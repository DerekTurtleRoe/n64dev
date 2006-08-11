#include "N64sys.h"

volatile unsigned long read_count(void) {
    unsigned long count;
    // reg $9 on COP0 is count
    asm("\tmfc0 %0,$9\n\tnop":"=r"(count));

    return count;
}

#define cache_op(op) \
    addr=(void*)(((unsigned long)addr)&(~3));\
    for (;length>0;length-=4,addr+=4) \
	asm ("\tcache %0,(%1)\n"::"i" (op), "r" (addr))

volatile void data_cache_writeback(volatile void * addr, unsigned long length) {
    cache_op(0x19);
}
volatile void data_cache_invalidate(volatile void * addr, unsigned long length) {
    cache_op(0x11);
}
volatile void data_cache_writeback_invalidate(volatile void * addr, unsigned long length) {
    cache_op(0x15);
}
volatile void inst_cache_writeback(volatile void * addr, unsigned long length) {
    cache_op(0x18);
}
volatile void inst_cache_invalidate(volatile void * addr, unsigned long length) {
    cache_op(0x10);
}
volatile void inst_cache_writeback_invalidate(volatile void * addr, unsigned long length) {
    cache_op(0x14);
}

volatile void disable_interrupts() {
	asm("\tmfc0 $8,$12\n\tla $9,~1\n\tand $8,$9\n\tmtc0 $8,$12\n\tnop":::"$8","$9");
}

volatile void enable_interrupts() {
	asm("\tmfc0 $8,$12\n\tori $8,1\n\tmtc0 $8,$12\n\tnop":::"$8");
}
