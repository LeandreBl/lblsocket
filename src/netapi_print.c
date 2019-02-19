#include <stdio.h>

#include "netapi.h"

void netapi_print(const netapi_t *iface)
{
  const uint8_t *ip = netapi_ip_addr(iface);

  fprintf(stderr, "[\"%s\"]\n"
          " -ip:\t%u.%u.%u.%u\n"
          " -mac:\t",
          iface->id.i, ip[0], ip[1], ip[2], ip[3]);
  for (size_t i = 0; i < iface->mac.len; ++i)
    fprintf(stderr, "%02X%s", iface->mac.arr[i], (i + 1 != iface->mac.len) ? ":" : "\n");
}