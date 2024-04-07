#ifndef __HEAD__H__
#define __HEAD__H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#ifndef DEBUG
#define __DEBUG(Msg, ...)
#define __WARNING(Msg, ...)
#define __ERROR(Msg, ...)
#define __PRINT
#else
/* Debug Print. Msg send to stderr*/
#define __DEBUG(Msg, ...) fprintf(stderr, "\033[36m[DEBUG]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
/* Warning message send to stderr*/
#define __WARNING(Msg, ...) fprintf(stderr, "\033[43m[WARNI]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
/* Error message send to stderr*/
#define __ERROR(Msg, ...) fprintf(stderr, "\033[41m[ERROR]\033[0m %s: (%d):" #Msg "\n", __FILE__, __LINE__,  ##__VA_ARGS__);
#define __PRINT printf
#endif

// malloc 函数的宏写法，仍然需要 free 函数回收
#define qmalloc(T) (struct T *) malloc(sizeof(struct T))

typedef char* String;
typedef int* Pint;
typedef __int8_t i8;
typedef __int16_t i16;
typedef __int32_t i32;
typedef __int64_t i64;
typedef __int128_t i128;

#endif
