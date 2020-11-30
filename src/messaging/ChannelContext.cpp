/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <messaging/Channel.h>
#include <messaging/ChannelContext.h>
#include <messaging/ExchangeMgr.h>

namespace chip {
namespace Messaging {

void ChannelContextDeletor::Release(ChannelContext * context)
{
    context->mExchangeManager->ReleaseChannelContext(context);
}

void ChannelContext::Start(const ChannelBuilder & builder)
{
    mState = ChannelState::kChanneState_Preparing;
    // TODO: start prepare the Channel using the builder
}

ExchangeContext * ChannelContext::NewExchange(ExchangeDelegate * delegate)
{
    if (GetState() != ChannelState::kChanneState_Ready) return nullptr;
    return mExchangeManager->NewContext(mReady.mSession, delegate);
}

bool ChannelContext::MatchesSession(SecureSessionHandle session, SecureSessionMgr * ssm)
{
    switch (mState)
    {
        case ChannelState::kChanneState_Closed:
        case ChannelState::kChanneState_None:
        case ChannelState::kChanneState_Failed:
            return false;
        case ChannelState::kChanneState_Preparing:
            {
                if (mPreparing.mState != kPrepareState_SessionEstablishing) return false;
                auto state = ssm->GetPeerConnectionState(session);
                return state->GetPeerNodeId() == mPreparing.mPeerNodeId && state->GetPeerKeyID() == mPreparing.mPeerKeyId;
            }
        case ChannelState::kChanneState_Ready:
            return mReady.mSession == session;
        default:
            assert(false);
            return false;
    }
}

void ChannelContext::OnNewConnection(SecureSessionHandle session)
{
    switch (mState)
    {
        case ChannelState::kChanneState_Preparing:
            mReady.mSession = session;
            mState = ChannelState::kChanneState_Ready;
            mExchangeManager->NotifyChannelEvent(this, [](ChannelDelegate * delegate) { delegate->OnEstablished(); });
            return;
        case ChannelState::kChanneState_None:
        case ChannelState::kChanneState_Ready:
        case ChannelState::kChanneState_Closed:
        case ChannelState::kChanneState_Failed:
            return;
    }
}

void ChannelContext::OnConnectionExpired(SecureSessionHandle session)
{
    switch (mState)
    {
        case ChannelState::kChanneState_Ready:
            mState = ChannelState::kChanneState_Closed;
            mExchangeManager->NotifyChannelEvent(this, [](ChannelDelegate * delegate) { delegate->OnClosed(); });
            return;
        case ChannelState::kChanneState_None:
        case ChannelState::kChanneState_Preparing:
        case ChannelState::kChanneState_Closed:
        case ChannelState::kChanneState_Failed:
            return;
    }
}

void ChannelContextHandleAssociation::Release()
{
    mExchangeManager->ReleaseChannelHandle(this);
}

} // namespace Messaging
} // namespace chip
