// Copyright 2006-2009 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_LOGGING_LOG_INL_H_
#define V8_LOGGING_LOG_INL_H_

#include "src/execution/isolate.h"
#include "src/logging/log.h"
#include "src/objects/objects-inl.h"
#include "src/tracing/trace-event.h"

namespace v8 {
namespace internal {

CodeEventListener::LogEventsAndTags Logger::ToNativeByScript(
    CodeEventListener::LogEventsAndTags tag, Script script) {
  if (script.type() != Script::TYPE_NATIVE) return tag;
  switch (tag) {
    case CodeEventListener::FUNCTION_TAG:
      return CodeEventListener::NATIVE_FUNCTION_TAG;
    case CodeEventListener::LAZY_COMPILE_TAG:
      return CodeEventListener::NATIVE_LAZY_COMPILE_TAG;
    case CodeEventListener::SCRIPT_TAG:
      return CodeEventListener::NATIVE_SCRIPT_TAG;
    default:
      return tag;
  }
}

template <class TimerEvent>
void TimerEventScope<TimerEvent>::LogTimerEvent(v8::LogEventStatus se) {
  Logger::CallEventLogger(isolate_, TimerEvent::name(), se,
                          TimerEvent::expose_to_api());
}

}  // namespace internal
}  // namespace v8

#endif  // V8_LOGGING_LOG_INL_H_
