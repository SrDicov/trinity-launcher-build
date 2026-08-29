/* musl compatibility shim providing glibc-style <sys/cdefs.h> macros.
 * Bionic's sys/cdefs.h wrapper does `#include_next <sys/cdefs.h>` expecting
 * glibc's header, which does not exist on musl. This file supplies the
 * commonly used macros. Every macro is guarded so it can be included after
 * bionic's own sys/cdefs.h without redefinition errors. */
#ifndef _MUSL_COMPAT_SYS_CDEFS_H
#define _MUSL_COMPAT_SYS_CDEFS_H

#include <features.h>

#ifndef __BEGIN_DECLS
# define __BEGIN_DECLS
#endif
#ifndef __END_DECLS
# define __END_DECLS
#endif

#ifndef __THROW
# define __THROW
#endif
#ifndef __NTH
# define __NTH(fct) fct
#endif
#ifndef __NTHNL
# define __NTHNL(fct) fct
#endif
#ifndef __THROWNL
# define __THROWNL
#endif
#ifndef __P
# define __P(args) args
#endif
#ifndef __PMT
# define __PMT(args) args
#endif

#ifndef __attribute_malloc__
# define __attribute_malloc__
#endif
#ifndef __attribute_pure__
# define __attribute_pure__
#endif
#ifndef __attribute_const__
# define __attribute_const__
#endif
#ifndef __attribute_used__
# define __attribute_used__
#endif
#ifndef __attribute_noinline__
# define __attribute_noinline__
#endif
#ifndef __attribute_deprecated__
# define __attribute_deprecated__
#endif
#ifndef __attribute_deprecated_msg__
# define __attribute_deprecated_msg__(msg)
#endif
#ifndef __attribute_warn_unused_result__
# define __attribute_warn_unused_result__
#endif
#ifndef __attribute_alloc_size__
# define __attribute_alloc_size__(x)
#endif
#ifndef __attribute_alloc_size2__
# define __attribute_alloc_size2__(x,y)
#endif
#ifndef __attribute_format_strfmon__
# define __attribute_format_strfmon__(x,y)
#endif
#ifndef __attribute_nonnull__
# define __attribute_nonnull__(x)
#endif
#ifndef __attribute_nonnull_all__
# define __attribute_nonnull_all__
#endif
#ifndef __attribute_returns_twice__
# define __attribute_returns_twice__
#endif
#ifndef __attribute_hidden__
# define __attribute_hidden__
#endif

#ifndef __wur
# define __wur __attribute_warn_unused_result__
#endif
#ifndef __malloc_like
# define __malloc_like __attribute_malloc__
#endif
#ifndef __format
# define __format(archetype, format, first)
#endif
#ifndef __printflike
# define __printflike(x,y)
#endif
#ifndef __scanflike
# define __scanflike(x,y)
#endif
#ifndef __fortify_function
# define __fortify_function
#endif

#ifndef __REDIRECT
# define __REDIRECT(name, proto, alias) name proto
#endif
#ifndef __REDIRECT_NTH
# define __REDIRECT_NTH(name, proto, alias) name proto
#endif
#ifndef __ASMNAME
# define __ASMNAME(cname)
#endif
#ifndef __ASMNAME2
# define __ASMNAME2(prefix, cname)
#endif

#ifndef __BEGIN_NAMESPACE_STD
# define __BEGIN_NAMESPACE_STD
#endif
#ifndef __END_NAMESPACE_STD
# define __END_NAMESPACE_STD
#endif
#ifndef __BEGIN_NAMESPACE_C99
# define __BEGIN_NAMESPACE_C99
#endif
#ifndef __END_NAMESPACE_C99
# define __END_NAMESPACE_C99
#endif
#ifndef __USING_NAMESPACE_STD
# define __USING_NAMESPACE_STD(name)
#endif
#ifndef __BEGIN_NAMESPACE_LDBL
# define __BEGIN_NAMESPACE_LDBL
#endif
#ifndef __END_NAMESPACE_LDBL
# define __END_NAMESPACE_LDBL
#endif
#ifndef __LDBL_NAMESPACE
# define __LDBL_NAMESPACE
#endif

#ifndef __flexarr
# define __flexarr []
#endif

#ifndef __glibc_likely
# define __glibc_likely(x) (x)
#endif
#ifndef __glibc_unlikely
# define __glibc_unlikely(x) (x)
#endif
#ifndef __nonnull
# define __nonnull(x)
#endif

#endif /* _MUSL_COMPAT_SYS_CDEFS_H */
