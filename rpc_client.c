#include "resize.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argv, char * argc[])
{
    data_in in;
    // in.data = "foo";
    in.sz = 111;
    data_out out;
    // out.data = "bar";
    out.sz = 222;
    
    
    printf("clnt_create\n");
    char * host = "0.0.0.0";
    CLIENT * client = clnt_create(host, RESIZE_PROG, RESIZE_V1, "tcp");
    if (client == NULL) {
        clnt_pcreateerror(host);
        
        // https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_72/apis/clnt_create.htm
        if(rpc_createerr.cf_stat==RPC_SYSTEMERROR) printf("RPC_SYSTEMERROR\n");
        if(rpc_createerr.cf_stat==RPC_UNKNOWNHOST) printf("RPC_UNKNOWNHOST\n");
        if(rpc_createerr.cf_stat==RPC_PROGNOTREGISTERED) printf("RPC_PROGNOTREGISTERED\n");
        
        exit(-1);
    }

    printf("rpc_resize_54321\n");
    enum clnt_stat result = rpc_resize_54321(&in, &out, client);
    if (result != RPC_SUCCESS) {
        clnt_perror(client, "resize rpc failed.");
    }
    printf("result: %d\n", result);

    printf("clnt_destroy\n");
    clnt_destroy(client);
}