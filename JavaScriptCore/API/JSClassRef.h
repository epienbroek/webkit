// -*- mode: c++; c-basic-offset: 4 -*-
/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef JSClassRef_h
#define JSClassRef_h

#include "JSObjectRef.h"
#include "HashMap.h"
#include "ustring.h"

struct StaticValueEntry {
    StaticValueEntry(JSGetPropertyCallback _getProperty, JSSetPropertyCallback _setProperty, JSPropertyAttributes _attributes)
        : getProperty(_getProperty), setProperty(_setProperty), attributes(_attributes)
    {
    }
    
    JSGetPropertyCallback getProperty;
    JSSetPropertyCallback setProperty;
    JSPropertyAttributes attributes;
};

struct StaticFunctionEntry {
    StaticFunctionEntry(JSCallAsFunctionCallback _callAsFunction, JSPropertyAttributes _attributes)
    : callAsFunction(_callAsFunction), attributes(_attributes)
    {
    }

    JSCallAsFunctionCallback callAsFunction;
    JSPropertyAttributes attributes;
};

struct __JSClass {
    __JSClass() : refCount(0), staticValues(0), staticFunctions(0)
    {
    }
    
    unsigned refCount;
    
    typedef HashMap<RefPtr<KJS::UString::Rep>, StaticValueEntry*> StaticValuesTable;
    StaticValuesTable* staticValues;

    typedef HashMap<RefPtr<KJS::UString::Rep>, StaticFunctionEntry*> StaticFunctionsTable;
    StaticFunctionsTable* staticFunctions;

    KJS::UString name; // FIXME: Not used yet
    JSObjectCallbacks callbacks;
    __JSClass* parent;
};

#endif // JSClassRef_h
