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

#include <stdint.h>

#include "af-structs.h"
#include "call-command-handler.h"
#include "callback.h"
#include "cluster-id.h"
#include "command-id.h"
#include "util.h"

using namespace chip;

EmberAfStatus emberAfLevelControlClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfOnOffClusterServerCommandParse(EmberAfClusterCommand * cmd);


static EmberAfStatus status(bool wasHandled, bool clusterExists, bool mfgSpecific)
{
    if (wasHandled)
    {
        return EMBER_ZCL_STATUS_SUCCESS;
    }
    else if (mfgSpecific)
    {
        return EMBER_ZCL_STATUS_UNSUP_MANUF_CLUSTER_COMMAND;
    }
    else if (clusterExists)
    {
        return EMBER_ZCL_STATUS_UNSUP_COMMAND;
    }
    else
    {
        return EMBER_ZCL_STATUS_UNSUPPORTED_CLUSTER;
    }
}


// Main command parsing controller.
EmberAfStatus emberAfClusterSpecificCommandParse(EmberAfClusterCommand * cmd)
{
    EmberAfStatus result = status(false, false, cmd->mfgSpecific);
    if (cmd->direction == (uint8_t) ZCL_DIRECTION_SERVER_TO_CLIENT &&
        emberAfContainsClientWithMfgCode(cmd->apsFrame->destinationEndpoint, cmd->apsFrame->clusterId, cmd->mfgCode))
    {
        switch (cmd->apsFrame->clusterId)
        {
        default:
            // Unrecognized cluster ID, error status will apply.
            break;
        }
    }
    else if (cmd->direction == (uint8_t) ZCL_DIRECTION_CLIENT_TO_SERVER &&
             emberAfContainsServerWithMfgCode(cmd->apsFrame->destinationEndpoint, cmd->apsFrame->clusterId, cmd->mfgCode))
    {
        switch (cmd->apsFrame->clusterId)
        {
        case ZCL_LEVEL_CONTROL_CLUSTER_ID :
            result = emberAfLevelControlClusterServerCommandParse(cmd);
            break;
        case ZCL_ON_OFF_CLUSTER_ID :
            result = emberAfOnOffClusterServerCommandParse(cmd);
            break;
        default:
            // Unrecognized cluster ID, error status will apply.
            break;
        }
    }
    return result;
}

// Cluster specific command parsing

EmberAfStatus emberAfLevelControlClusterServerCommandParse(EmberAfClusterCommand * cmd)
{
    bool wasHandled = false;

    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        {
        case ZCL_MOVE_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t moveMode;
uint8_t rate;
uint8_t optionMask;
uint8_t optionOverride;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  rate = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterMoveCallback(moveMode, rate, optionMask, optionOverride);
            break;
        }
        case ZCL_MOVE_TO_LEVEL_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t level;
uint16_t transitionTime;
uint8_t optionMask;
uint8_t optionOverride;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  level = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 2)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 2;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterMoveToLevelCallback(level, transitionTime, optionMask, optionOverride);
            break;
        }
        case ZCL_MOVE_TO_LEVEL_WITH_ON_OFF_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t level;
uint16_t transitionTime;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  level = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 2)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterMoveToLevelWithOnOffCallback(level, transitionTime);
            break;
        }
        case ZCL_MOVE_WITH_ON_OFF_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t moveMode;
uint8_t rate;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  rate = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterMoveWithOnOffCallback(moveMode, rate);
            break;
        }
        case ZCL_STEP_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t stepMode;
uint8_t stepSize;
uint16_t transitionTime;
uint8_t optionMask;
uint8_t optionOverride;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  stepSize = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 2)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 2;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterStepCallback(stepMode, stepSize, transitionTime, optionMask, optionOverride);
            break;
        }
        case ZCL_STEP_WITH_ON_OFF_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t stepMode;
uint8_t stepSize;
uint16_t transitionTime;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  stepSize = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 2)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterStepWithOnOffCallback(stepMode, stepSize, transitionTime);
            break;
        }
        case ZCL_STOP_COMMAND_ID: {
        uint32_t payloadOffset = cmd->payloadStartIndex;
uint8_t optionMask;
uint8_t optionOverride;

  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
  payloadOffset += 1;
  if (cmd->bufLen < payloadOffset + 1)
  {
    return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
  }
  optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);

wasHandled = emberAfLevelControlClusterStopCallback(optionMask, optionOverride);
            break;
        }
        case ZCL_STOP_WITH_ON_OFF_COMMAND_ID: {
        wasHandled = emberAfLevelControlClusterStopWithOnOffCallback();
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            break;
        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}
EmberAfStatus emberAfOnOffClusterServerCommandParse(EmberAfClusterCommand * cmd)
{
    bool wasHandled = false;

    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        {
        case ZCL_OFF_COMMAND_ID: {
        wasHandled = emberAfOnOffClusterOffCallback();
            break;
        }
        case ZCL_ON_COMMAND_ID: {
        wasHandled = emberAfOnOffClusterOnCallback();
            break;
        }
        case ZCL_TOGGLE_COMMAND_ID: {
        wasHandled = emberAfOnOffClusterToggleCallback();
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            break;
        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}
