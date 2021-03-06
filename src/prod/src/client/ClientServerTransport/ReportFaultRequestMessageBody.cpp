// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#include "stdafx.h"

using namespace std;
using namespace Common;
using namespace Reliability;
using namespace ServiceModel;

ReportFaultRequestMessageBody::ReportFaultRequestMessageBody()
: nodeName_(),
  faultType_(FaultType::Invalid),
  replicaId_(0),
  partitionId_(Guid::Empty()),
  isForce_(false)
{
}

ReportFaultRequestMessageBody::ReportFaultRequestMessageBody(
    wstring nodeName,
    FaultType::Enum faultType,
    int64 replicaId,
    Guid partitionId,
    bool isForce)
: nodeName_(move(nodeName)),
  faultType_(faultType),
  replicaId_(replicaId),
  partitionId_(partitionId),
  isForce_(isForce)
{
}

ReportFaultRequestMessageBody::ReportFaultRequestMessageBody(ReportFaultRequestMessageBody && other)
: nodeName_(move(other.nodeName_)),
  faultType_(move(other.faultType_)),
  replicaId_(move(other.replicaId_)),
  partitionId_(move(other.partitionId_)),
  isForce_(move(other.isForce_))
{
}

ReportFaultRequestMessageBody & ReportFaultRequestMessageBody::operator=(ReportFaultRequestMessageBody && other)
{
    if (this != &other)
    {
        nodeName_ = move(other.nodeName_);
        faultType_ = move(other.faultType_);
        replicaId_ = move(other.replicaId_);
        partitionId_ = move(other.partitionId_);
        isForce_ = move(other.isForce_);
    }

    return *this;
}


string ReportFaultRequestMessageBody::AddField(Common::TraceEvent & traceEvent, string const & name)
{
    string format = "Node = {0} Partition = {1} Replica = {2} FaultType = {3} IsForce = {4}";
    size_t index = 0;

    traceEvent.AddEventField<wstring>(format, name + ".node", index);
    traceEvent.AddEventField<Guid>(format, name + ".guid", index);
    traceEvent.AddEventField<int64>(format, name + ".replica", index);
    traceEvent.AddEventField<FaultType::Trace>(format, name + ".faultType", index);
    traceEvent.AddEventField<bool>(format, name + ".isForce", index);

    return format;
}

void ReportFaultRequestMessageBody::FillEventData(TraceEventContext & context) const
{
    context.Write(nodeName_);
    context.Write(partitionId_);
    context.Write(replicaId_);
    context.WriteCopy<uint>(static_cast<uint>(faultType_));
    context.Write(isForce_);
}

void ReportFaultRequestMessageBody::WriteTo(TextWriter& w, FormatOptions const &) const
{
    w.Write("Node = {0} Partition = {1} Replica = {2} FaultType = {3} IsForce = {4}", nodeName_, partitionId_, replicaId_, faultType_, isForce_);
}
