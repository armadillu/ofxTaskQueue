// =============================================================================
//
// Copyright (c) 2014 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofx/TaskQueueEvents.h"


namespace ofx {


BaseTaskEventArgs::BaseTaskEventArgs(const Poco::UUID& taskId,
                                     const std::string& taskName):
    _taskId(taskId),
    _taskName(taskName)
{
}


BaseTaskEventArgs::~BaseTaskEventArgs()
{
}


const Poco::UUID& BaseTaskEventArgs::getTaskId() const
{
    return _taskId;
}


const std::string& BaseTaskEventArgs::getTaskName() const
{
    return _taskName;
}


TaskFailedEventArgs::TaskFailedEventArgs(const Poco::UUID& taskId,
                                         const std::string& taskName,
                                         const Poco::Exception& exception):
    BaseTaskEventArgs(taskId, taskName),
    _exception(exception)
{
}


TaskFailedEventArgs::~TaskFailedEventArgs()
{
}


const Poco::Exception& TaskFailedEventArgs::getException() const
{
    return _exception;
}


TaskProgressEventArgs::TaskProgressEventArgs(const Poco::UUID& taskId,
                                             const std::string& taskName,
                                             float progress):
    BaseTaskEventArgs(taskId, taskName),
    _progress(progress)
{
}


TaskProgressEventArgs::~TaskProgressEventArgs()
{
}


float TaskProgressEventArgs::getProgress() const
{
    return _progress;
}


} // namespace ofx
