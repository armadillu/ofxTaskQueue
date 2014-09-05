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


#pragma once


#include "ofMain.h"
#include "ofxTaskQueue.h"
#include "SimpleCountingTask.h"
#include "SimpleTaskProgress.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);

    void onTaskQueued(const ofx::TaskQueuedEventArgs& args);
    void onTaskStarted(const ofx::TaskStartedEventArgs& args);
    void onTaskCancelled(const ofx::TaskCancelledEventArgs& args);
    void onTaskFinished(const ofx::TaskFinishedEventArgs& args);
    void onTaskFailed(const ofx::TaskFailedEventArgs& args);
    void onTaskProgress(const ofx::TaskProgressEventArgs& args);
    void onTaskData(const ofx::TaskStringEventArgs& args);

    void onTaskCustomNotification(const ofx::TaskCustomNotificationEventArgs& args);

    // Use the default std::string data queue.
    ofx::TaskQueue queue;

    // Make a typedef for the map to make it shorter.
    typedef std::map<Poco::UUID, SimpleTaskProgress> TaskProgress;

    // We keep a simple task progress queue.
    TaskProgress taskProgress;

};
