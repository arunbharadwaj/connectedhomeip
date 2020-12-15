/**
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
 *      This file describes a AdditionalData Payload parser based on the
 *      CHIP specification.
 */

#include "AdditionalDataPayloadParser.h"
#include "Base41.h"

#include <math.h>
#include <memory>
#include <string.h>
#include <vector>
#include <sstream>
#include <iomanip>


#include <core/CHIPCore.h>
#include <core/CHIPError.h>
#include <core/CHIPTLVData.hpp>
#include <core/CHIPTLVUtilities.hpp>
#include <protocols/Protocols.h>
#include <support/CodeUtils.h>
#include <support/RandUtils.h>
#include <support/SafeInt.h>
#include <support/ScopedBuffer.h>
#include <core/CHIPTLVDebug.hpp>
#include <iomanip>
#include <cstdlib>
#include <iostream>

using namespace chip;
using namespace std;
using namespace chip::TLV;
using namespace chip::TLV::Utilities;

static CHIP_ERROR octetStringDecode(string octetString, vector<uint8_t> & result) {
    result.clear();
    size_t len = octetString.length();

    for(size_t i = 0; i < len; i += 2) {
        auto str = octetString.substr(i, 2);
        uint8_t x = (uint8_t)stoi(str, 0, 16);
        result.push_back(x);
    }
    return CHIP_NO_ERROR;
}

CHIP_ERROR AdditionalDataPayloadParser::populatePayload(AdditionalDataPayload & outPayload)
{
    CHIP_ERROR err          = CHIP_NO_ERROR;
    std::vector<uint8_t> payload;

    // Decoding input
    err = DecodeInput(&payload);
    SuccessOrExit(err);
    // Parse TLV fields
    err = parseTLVFields(outPayload, payload);
    SuccessOrExit(err);

exit:
    return err;
}

CHIP_ERROR AdditionalDataPayloadParser::DecodeInput(std::vector<uint8_t>* output)
{
    CHIP_ERROR err         = CHIP_NO_ERROR;
    vector<uint8_t> buf;

    VerifyOrExit(mPayload.length() != 0, err = CHIP_ERROR_INVALID_ARGUMENT);

    // convert the octet string to buf
    err = octetStringDecode(mPayload, buf);
    SuccessOrExit(err);

    for (size_t i = 0; i < mPayload.length(); i++)
    {
        uint64_t dest = buf[i];
        (*output).push_back(static_cast<uint8_t>(dest));
    }

exit:
    return err;
}

CHIP_ERROR AdditionalDataPayloadParser::parseTLVFields(chip::AdditionalDataPayload & outPayload, std::vector<uint8_t> tlvData)
{
    CHIP_ERROR err = CHIP_NO_ERROR;
    chip::TLV::TLVReader reader;
    chip::TLV::TLVReader innerReader;

    reader.Init(&tlvData[0], (uint32_t)tlvData.size());
    reader.ImplicitProfileId = chip::Protocols::kProtocol_ServiceProvisioning;
    err = reader.Next();
    SuccessOrExit(err);

    // Open the container
    err = reader.OpenContainer(innerReader);
    SuccessOrExit(err);

    err = innerReader.Next();
    SuccessOrExit(err);

    // Get the value of the rotating device id
    char rotatingDeviceId[256];
    err = innerReader.GetString(rotatingDeviceId, sizeof(rotatingDeviceId)+1);
    outPayload.rotatingDeviceId = std::string(rotatingDeviceId);
exit:
    return err;
}
