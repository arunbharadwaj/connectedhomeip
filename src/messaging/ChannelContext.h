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

/**
 *    @file
 *      This file defines the internal classes used by CHIP Channel.
 */

#pragma once

#include <lib/core/ReferenceCounted.h>
#include <lib/mdns/platform/Mdns.h>
#include <messaging/Channel.h>
#include <transport/PeerConnectionState.h>
#include <transport/SecureSessionMgr.h>

namespace chip {
namespace Messaging {

class ExchangeManager;
class ChannelContext;

class ChannelContextDeletor
{
public:
    static void Release(ChannelContext * context);
};

class ChannelContext : public ReferenceCounted<ChannelContext, ChannelContextDeletor>
{
public:
    ChannelContext(ExchangeManager * exchangeManager) : mState(ChannelState::kChanneState_Closed), mExchangeManager(exchangeManager)
    {}

    void Start(const ChannelBuilder & builder);
    ExchangeContext * NewExchange(ExchangeDelegate * delegate);

    ChannelState GetState() const { return mState; }

    bool MatchesSession(SecureSessionHandle session, SecureSessionMgr * ssm);
    bool MatchesBuilder(const ChannelBuilder & builder, SecureSessionMgr * ssm);

    // events of ResolveDelegate, propagated from ExchangeManager
    void HandleNodeIdResolve(CHIP_ERROR error, uint64_t nodeId, const Mdns::MdnsService & address);

    // events of SecureSessionManager, propagated from ExchangeManager
    void OnNewConnection(SecureSessionHandle session);
    void OnConnectionExpired(SecureSessionHandle session);

private:
    friend class ChannelContextDeletor;
    ChannelState mState = ChannelState::kChanneState_Closed;
    ExchangeManager * mExchangeManager;

    enum PrepareState
    {
        kPrepareState_WaitingForInterface,
        kPrepareState_AddressResolving,
        kPrepareState_SessionEstablishing,
    };

    union
    {
        struct
        {
            PrepareState mState;
            NodeId mPeerNodeId;
            uint16_t mPeerKeyId;
        } mPreparing;
        struct
        {
            SecureSessionHandle mSession;
        } mReady;
    };
};

struct ChannelContextHandleAssociation
{
    ChannelContextHandleAssociation(ExchangeManager * exchangeManager, ChannelContext * channelContext,
                                    ChannelDelegate * channelDelegate) :
        mExchangeManager(exchangeManager),
        mChannelContext(channelContext), mChannelDelegate(channelDelegate)
    {
        mChannelContext->Retain();
    }
    ~ChannelContextHandleAssociation() { mChannelContext->Release(); }

    void Release();

    ExchangeManager * mExchangeManager;
    ChannelContext * mChannelContext;
    ChannelDelegate * mChannelDelegate;
};

} // namespace Messaging
} // namespace chip
