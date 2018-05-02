#include<string.h>

void* memcpy(void* restrict dst, const void* restrict src, size_t size){
    unsigned char * dstptr = (unsigned char*) dst;
    const unsigned char* srcptr = (const unsigned char*)src;
    for(size_t i=0; i<size; ++i){
        dstptr[i] = srcptr[i];
    }
    return dstptr;
}
