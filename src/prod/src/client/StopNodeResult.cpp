// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#include "stdafx.h"

using namespace std;
using namespace Common;
using namespace Api;
using namespace ServiceModel;
using namespace Management::FaultAnalysisService;
using namespace Client;

StopNodeResult::StopNodeResult(
    StopNodeStatus && nodeStatus)
    : nodeStatus_(move(nodeStatus))
{
}

shared_ptr<NodeResult> const & StopNodeResult::GetNodeResult()
{
    return nodeStatus_.GetNodeResult();
}
