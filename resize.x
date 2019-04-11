struct data_in {
    int sz;
};

struct data_out {
    int sz;
};

program RESIZE_PROG {
    version RESIZE_V1 {
        data_out RPC_RESIZE(data_in) = 12345;
    } = 54321;
} = 0x20010101;
