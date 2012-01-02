/*
 * Icon configuration file for Linux v2 on Athlon64, Solaris Studio compilers
 */

#define UNIX 1
#define LoadFunc
/* no SysOpt: Linux getopt() is POSIX-compatible only if an envmt var is set */

/* CPU architecture */
#define IntBits 32
#define WordBits 64
#define Double
#define StackAlign 16
#define NEED_UTIME
/* a non-default datatype for SQLBindCol's 6th parameter */
#define SQL_LENORIND SQLLEN

/*
 * Some Linuxen have -lcrypt, some dont.
 * If you have crypt, you can remove this.
 */
#define NoCrypt
#define Concurrent 1
#define PTHREAD_MUTEX_RECURSIVE PTHREAD_MUTEX_RECURSIVE_NP
