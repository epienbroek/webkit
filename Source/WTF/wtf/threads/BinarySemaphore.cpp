/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "BinarySemaphore.h"

#if 1 //!OS(WINDOWS)

namespace WTF {

BinarySemaphore::BinarySemaphore()
#if 0
    : m_isSet(false)
#endif
{
}
    
BinarySemaphore::~BinarySemaphore()
{
}

void BinarySemaphore::signal()
{
#if 0
    MutexLocker locker(m_mutex);

    m_isSet = true;
    m_condition.signal();
#endif
}

bool BinarySemaphore::wait(double absoluteTime)
{
#if 0
    MutexLocker locker(m_mutex);

    bool timedOut = false;
    while (!m_isSet) {
        timedOut = !m_condition.timedWait(m_mutex, absoluteTime);
        if (timedOut)
            return false;
    }

    // Reset the semaphore.
    m_isSet = false;
#endif
    return true;
}

} // namespace WTF

#endif // !PLATFORM(WIN)
