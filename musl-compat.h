#ifndef MUSL_COMPAT_H
#define MUSL_COMPAT_H

/* _Atomic is a C11 keyword in C, but not exposed as a keyword in C++ here.
   Map it to std::atomic for the bionic headers. */
#ifdef __cplusplus
#include <atomic>
#ifndef _Atomic
#define _Atomic(T) std::atomic<T>
#endif
#include <libgen.h>
#include <cstdlib>
#endif

/* glibc/bionic extensions not provided by musl */
#ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_MUTEX_INITIALIZER
#endif

#ifndef TEMP_FAILURE_RETRY
#define TEMP_FAILURE_RETRY(expression) \
    (__extension__ ({ \
        long int __result; \
        do __result = (long int)(expression); \
        while (__result == -1L && errno == EINTR); \
        __result; \
    }))
#endif

#ifndef strtouq
#define strtouq strtoull
#endif
#ifndef strtoq
#define strtoq strtoll
#endif

/* glibc has these natively; musl does not. libc-shim (SrDicov fork) provides
   the real definitions, but every TU needs the declarations. */
#include <sys/socket.h>
#include <locale.h>
#include <time.h>
#include <errno.h>
#ifdef __cplusplus
extern "C" {
#endif
char *strptime_l(const char *buf, const char *fmt, struct tm *tm);
unsigned long strtoul_l(const char *nptr, char **endptr, int base, locale_t loc);
long strtoll_l(const char *nptr, char **endptr, int base, locale_t loc);
unsigned long long strtoull_l(const char *nptr, char **endptr, int base, locale_t loc);
float strtof_l(const char *nptr, char **endptr, locale_t loc);
long double strtold_l(const char *nptr, char **endptr, locale_t loc);
struct cmsghdr *__cmsg_nxthdr(struct msghdr *m, struct cmsghdr *c);
#ifdef __cplusplus
}
#endif

/* getprogname is BSD/glibc; provide it inline everywhere (musl has the var). */
static inline const char *getprogname(void) {
    return program_invocation_short_name;
}

#endif
