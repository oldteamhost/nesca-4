/*
 * LIBNCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "include/http.h"
#include <string.h>

void add_http_basicauth(struct http_request *h, const char* user,
    const char* pass)
{
  char combined[strlen(user) + 1 + strlen(pass) + 1];
  char resencode[65535];

  sprintf(combined, "%s:%s", user, pass);
  base64encode((u8*)combined, strlen(combined), resencode);
  add_http_header(h, "Authorization", resencode);
}
