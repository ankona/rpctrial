#include "resize.h"
#include <stdio.h>

bool_t rpc_resize_54321_svc(data_in * input, data_out * output, struct svc_req * request)
{
    printf("rpc_resize_54321_svc\n");
    int result;

    printf("input->sz: %d\n", input->sz);

    printf("output->sz: %d\n", output->sz);

    output->sz = 345;

    // output = (data_out*)malloc(sizeof(data_out));
    // output->sz = 0;
    // output->data = "test";

    result = 1;
    return result;
}

int resize_prog_54321_freeresult (SVCXPRT * svcxprt, xdrproc_t xdrproc, caddr_t caddr)
{
    printf("resize_prog_54321_freeresult\n");
    static int result = 0;

    xdr_free(xdrproc, (void*)&result);
    result = 1;
    return result;
}
