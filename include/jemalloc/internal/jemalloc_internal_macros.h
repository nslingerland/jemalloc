#ifndef JEMALLOC_INTERNAL_MACROS_H
#define JEMALLOC_INTERNAL_MACROS_H

#if defined(JEMALLOC_DEBUG) || defined(JEMALLOC_CODE_COVERAGE)
#  define JEMALLOC_ALWAYS_INLINE static inline
#else
#  define JEMALLOC_ALWAYS_INLINE JEMALLOC_ATTR(always_inline) static inline
#endif
#ifdef _MSC_VER
#  define inline _inline
#endif

#define UNUSED JEMALLOC_ATTR(unused)

#define ZU(z)	((size_t)z)
#define ZD(z)	((ssize_t)z)
#define QU(q)	((uint64_t)q)
#define QD(q)	((int64_t)q)

#define KZU(z)	ZU(z##ULL)
#define KZD(z)	ZD(z##LL)
#define KQU(q)	QU(q##ULL)
#define KQD(q)	QI(q##LL)

#ifndef __DECONST
#  define	__DECONST(type, var)	((type)(uintptr_t)(const void *)(var))
#endif

#if !defined(JEMALLOC_HAS_RESTRICT) || defined(__cplusplus)
#  define restrict
#endif

#endif /* JEMALLOC_INTERNAL_MACROS_H */
