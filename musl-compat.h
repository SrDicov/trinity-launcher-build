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

#ifndef strtouq
#define strtouq strtoull
#endif
#ifndef strtoq
#define strtoq strtoll
#endif
#ifndef strtoul_l
#define strtoul_l(a, b, c, d) strtoul((a), (b), (c))
#endif
#ifndef strtoull_l
#define strtoull_l(a, b, c, d) strtoull((a), (b), (c))
#endif
#ifndef strtoll_l
#define strtoll_l(a, b, c, d) strtoll((a), (b), (c))
#endif
#ifndef strptime_l
#define strptime_l(b, f, t, l) strptime((b), (f), (t))
#endif
#ifndef __cmsg_nxthdr
#define __cmsg_nxthdr(m, c) CMSG_NXTHDR((m), (c))
#endif

#endif
