/** @file
 * Copyright (c) 2019, Arm Limited or ps affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/
#ifndef _TEST_S002_PS_DATA_TESTS_H_
#define _TEST_S002_PS_DATA_TESTS_H_

#include "val_protected_storage.h"

#define SST_FUNCTION val->ps_function
#define PSA_SST_FLAG_WRITE_ONCE PSA_PS_FLAG_WRITE_ONCE
#define psa_sst_uid_t psa_ps_uid_t

typedef struct {
    char                   test_desc[100];
    enum ps_function_code  api;
    psa_ps_status_t        status;
} test_data;

static struct psa_ps_info_t orig_info;
static struct psa_ps_info_t new_info;
static test_data s002_data[] = {
{
 "This is dummy for index0", 0, 0
},
{
 "Create a valid storage with create flag value 0", VAL_PS_SET, PSA_PS_SUCCESS
},
{
 "Call the get_info api to validate the attributes", VAL_PS_GET_INFO, PSA_PS_SUCCESS
},
{
 "Index not used as check for get info size",0,0
},
{
 "Index not used as check for get info flag",0,0
},
{
 "validate the data using get api", VAL_PS_GET, PSA_PS_SUCCESS
},
{
 "Index not used",0,0
},
{
 "Change the flag to WRITE_ONCE using set api", VAL_PS_SET, PSA_PS_SUCCESS
},
{
 "Call the get_info api to validate the flag change", VAL_PS_GET_INFO, PSA_PS_SUCCESS
},
{
 "Index not used as check for get info size",0,0
},
{
 "Index not used as check for get info flag",0,0
},
{
 "validate the data using get api after flag change", VAL_PS_GET, PSA_PS_SUCCESS
},
{
 "Index not used",0,0
},
{
 " storage should not be removed after WRITE_ONCE flag", VAL_PS_REMOVE, PSA_PS_ERROR_WRITE_ONCE
},
{
 "Create a valid storage with different uid and flag value WRITE_ONCE ", VAL_PS_SET, PSA_PS_SUCCESS
},
{
 "storage should not be removed", VAL_PS_REMOVE, PSA_PS_ERROR_WRITE_ONCE
},
{
 "validate the data using get api after flag change", VAL_PS_GET, PSA_PS_SUCCESS
},
{
 "Index not used",0,0
},
{
 "Call the get_info api to validate the flag change", VAL_PS_GET_INFO, PSA_PS_SUCCESS
},
{
 "Index not used as check for get info size",0,0
},
{
 "Index not used as check for get info flag",0,0
},
{
 "try to set different size for same uid and flag value ", VAL_PS_SET, PSA_PS_ERROR_WRITE_ONCE
},
{
 "storage should not be removed", VAL_PS_REMOVE, PSA_PS_ERROR_WRITE_ONCE
},
{
 "Call the get_info api to validate the flag change", VAL_PS_GET_INFO, PSA_PS_SUCCESS
},
{
 "Index not used as check for get info size",0,0
},
{
 "Index not used as check for get info flag",0,0
},
{
 "validate the data using get api after flag change", VAL_PS_GET, PSA_PS_SUCCESS
},
{
 "Index not used",0,0
},
{
 "Setting flag to zero for uid should fail ", VAL_PS_SET, PSA_PS_ERROR_WRITE_ONCE
},
{
 "Check that the WRITE_ONCE flag is preserved", VAL_PS_GET_INFO, PSA_PS_SUCCESS
},
{
 "Index not used as check for get info size",0,0
},
{
 "Index not used as check for get info flag",0,0
},
};
#endif /* _TEST_S001_PS_DATA_TESTS_H_ */