// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Reliability
{
    class NodeDeactivateReplyMessageBody  : public Serialization::FabricSerializable
    {
    public:

        NodeDeactivateReplyMessageBody();

        NodeDeactivateReplyMessageBody(int64 sequenceNumber);

        __declspec(property(get=get_SequenceNumber)) int64 SequenceNumber;
        int64 get_SequenceNumber() const { return sequenceNumber_; }

        void WriteToEtw(uint16 contextSequenceId) const;
        void WriteTo(Common::TextWriter & w, Common::FormatOptions const &) const;

        FABRIC_FIELDS_01(sequenceNumber_);

    private:
        
        int64 sequenceNumber_;
    };
}

