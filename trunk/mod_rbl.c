/*
 * Copyright (c) 2009 Igor Popov <iPopovi@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */
              
#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

#ifndef __unused
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
#define __unused	__attribute__((unused))
#else	/* __GNUC__ */
#if defined(__INTEL_COMPILER)
#define __unused	__attribute__((__unused__))
#else	/* __INTEL_COMPILER */
#define __unused
#endif	/* __INTEL_COMPILER */
#endif	/* __GNUC__ */
#endif	/* __unused */


static const char __unused cvsid[] = "$Id$";

/* The content handler */
static int rbl_handler(request_rec *r)
{
    if (strcmp(r->handler, "rbl")) {
        return DECLINED;
    }
    return OK;
}

static void rbl_register_hooks(apr_pool_t *p)
{
    ap_hook_handler(rbl_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA rbl_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    rbl_register_hooks  /* register hooks                      */
};
