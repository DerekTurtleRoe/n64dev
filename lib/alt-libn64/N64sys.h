/*
   General R4300 stuff
*/

#ifndef _N64SYS_H
#define _N64SYS_H

#define UncachedAddr(_addr) ((void *)(((unsigned long)(_addr))|0x20000000))
#define UncachedShortAddr(_addr) ((short *)(((unsigned long)(_addr))|0x20000000))
#define UncachedUShortAddr(_addr) ((unsigned short *)(((unsigned long)(_addr))|0x20000000))
#define UncachedLongAddr(_addr) ((long *)(((unsigned long)(_addr))|0x20000000))
#define UncachedULongAddr(_addr) ((unsigned long *)(((unsigned long)(_addr))|0x20000000))

#define CachedAddr(_addr) (((void *)(((unsigned long)(_addr))&~0x20000000))

volatile unsigned long read_count(void);
volatile void data_cache_invalidate(volatile void *, unsigned long);
volatile void data_cache_writeback(volatile void *, unsigned long);
volatile void data_cache_writeback_invalidate(volatile void *, unsigned long);
volatile void inst_cache_invalidate(volatile void *, unsigned long);
volatile void inst_cache_writeback(volatile void *, unsigned long);
volatile void inst_cache_writeback_invalidate(volatile void *, unsigned long);
volatile void enable_interrupts();
volatile void disable_interrupts();

#endif // _N64SYS_H
