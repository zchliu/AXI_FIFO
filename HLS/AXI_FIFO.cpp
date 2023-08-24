#include "AXI_FIFO.h"

void example(hls::stream< trans_pkt > &A, hls::stream< trans_pkt > &B)
{
#pragma HLS TOP name=example
#pragma HLS INTERFACE mode=s_axilite port=return
#pragma HLS INTERFACE mode=axis port=A
#pragma HLS INTERFACE mode=axis port=B
	trans_pkt tmp;
	A.read(tmp);
	tmp.data += 5;
	tmp.last = 1;
    tmp.keep = 0xf;
    tmp.strb = 0xf;
	B.write(tmp);
}
