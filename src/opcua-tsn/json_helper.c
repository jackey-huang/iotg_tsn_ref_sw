/******************************************************************************
 *
 * Copyright (c) 2020, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
#include <json-c/json.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "json_helper.h"
#include "opcua_utils.h"

typedef struct json_object JsObj;

void ensureType(JsObj *toCheck, json_type type, JsObj *parent, char *key)
{
    json_type objType = json_object_get_type(toCheck);

    if (objType != type) {
        log_error("Key '%s' in object '%s' has invalid type. Exiting.",
                key, json_object_to_json_string(parent));
        exit(EXIT_FAILURE);
    }

    return;
}

char *getOptionalStr(struct json_object *parent,
        char *key, char *defaultVal)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_string, parent, key);
        return strdup(json_object_get_string(val));
    }

    return defaultVal;
}

int getOptionalInt(struct json_object *parent, char *key, int defaultVal)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_int, parent, key);
        return json_object_get_int(val);
    }

    return defaultVal;
}

bool getOptionalBool(struct json_object *parent, char *key, bool defaultVal)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_boolean, parent, key);
        return json_object_get_boolean(val);
    }

    return defaultVal;
}

int64_t getOptionalInt64(struct json_object *parent, char *key, int64_t defaultVal)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_int, parent, key);
        return json_object_get_int64(val);
    }

    return defaultVal;
}

char *getString(struct json_object *parent, char *key)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_string, parent, key);
        return strndup(json_object_get_string(val), json_object_get_string_len(val));
    }

    log_error("Key '%s' not found in object '%s'. Exiting.", key,
            json_object_to_json_string(parent));
    exit(EXIT_FAILURE);
}

int getInt(struct json_object *parent, char *key)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_int, parent, key);
        return json_object_get_int(val);
    }

    log_error("Key '%s' not found in object '%s'. Exiting.", key,
            json_object_to_json_string(parent));
    exit(EXIT_FAILURE);
}

bool getBool(struct json_object *parent, char *key)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_boolean, parent, key);
        return json_object_get_boolean(val);
    }

    log_error("Key '%s' not found in object '%s'. Exiting.", key,
            json_object_to_json_string(parent));
    exit(EXIT_FAILURE);
}

int64_t getInt64(struct json_object *parent, char *key)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found) {
        ensureType(val, json_type_int, parent, key);
        return json_object_get_int64(val);
    }

    log_error("Key '%s' not found in object '%s'. Exiting.", key,
            json_object_to_json_string(parent));
    exit(EXIT_FAILURE);
}

int countChildrenEntries(struct json_object *json)
{
    return json_object_object_length(json);
}

struct json_object *getValue(struct json_object *parent, char *key)
{
    JsObj *val;
    json_bool found = json_object_object_get_ex(parent, key, &val);

    if (found)
        return val;

    log_error("Key '%s' not found in object '%s'. Exiting.", key,
            json_object_to_json_string(parent));
    exit(EXIT_FAILURE);
}
