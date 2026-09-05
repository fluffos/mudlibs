/* DO NOT EDIT!
 *
 * This file is created automatically by configure from the template
 * in config.h.in.
 */

#ifndef CONFIG_H__
#define CONFIG_H__ 1

/* ----------- Commandline Argument Defaults ----------
 * These options provide default settings for those options which can
 * also be set on the commandline.
 */


/* Define COMPAT_MODE if you are using the 2.4.5 mudlib or one of its
 * derivatives.
 */
#undef COMPAT_MODE

/* The name of the master object.
 */
#define MASTER_NAME              "secure/master"

/* Define ALLOW_FILENAME_SPACES if the driver should accept space characters
 * in filenames. If it is not defined, a hardcoded test for space characters
 * is activated.
 */
#undef ALLOW_FILENAME_SPACES


/* --- Runtime limits --- */

/* This is the maximum array size allowed for one single array.
 * If 0, any size is allowed.
 */
#define MAX_ARRAY_SIZE            5000

/* This is the maximum number of entries allowed for a single mapping.
 * If 0, any size is allowed.
 */
#define MAX_MAPPING_KEYS          5000

/* This is the maximum number of values held in a single mapping.
 * If 0, any size is allowed.
 */
#define MAX_MAPPING_SIZE          15000

/* Max size of a file allowed to be read by 'read_file()'.
 */
#define READ_FILE_MAX_SIZE        50000

/* Define MAX_BYTE_TRANSFER to the number of bytes you allow to be read
 * and written with read_bytes and write_bytes
 */
#define MAX_BYTE_TRANSFER        50000

/* This is the maximum number of callouts allowed at one time.
 * If 0, any number is allowed.
 */
#define MAX_CALLOUTS              0

/* Define this to the maximum amount of data
 * to be held pending for writing per interactive.
 * A value of 0 means 'unlimited'.
 */
#define WRITE_BUFFER_MAX_SIZE     100000


/* --- Timing --- */

/* If an object is left alone for a certain time, then the
 * function clean_up will be called. This function can do anything,
 * like destructing the object. If the function isn't defined by the
 * object, then nothing will happen.
 *
 * This time should be substantially longer than the swapping time.
 */
#define TIME_TO_CLEAN_UP          3600

/* How long time until an unused object is swapped out.
 * Machine with too many players and too little memory: 900 (15 minutes)
 * Machine with few players and lot of memory: 10000
 * Machine with infinite memory: 0 (never swap).
 */
#define TIME_TO_SWAP              900
#define TIME_TO_SWAP_VARIABLES    1800

/* How many seconds until an object is reset again.
 * Set this value high if big system, otherwise low.
 */
#define TIME_TO_RESET             1800

/* The granularity of alarm() calls.
 * This is the granularity of the call_outs,
 * and base granularity of heart_beat, reset und clean_up calls.
 */
#define ALARM_TIME                2

/* The interval between heart beats.
 */
#define HEART_BEAT_INTERVAL       2

/* Shall all heart beats happen in the same time frame?
 * (i.e. only every HEART_BEAT_INTERVAL seconds.)
 */
#define SYNCHRONOUS_HEART_BEAT

/* --- Memory --- */

/* Reserve an extra memory area from malloc(), to free when we run out
 * of memory to get some warning and start Armageddon.
 * If this value is 0, no area will be reserved.
 */
#define RESERVED_USER_SIZE      700000
#define RESERVED_MASTER_SIZE    100000
#define RESERVED_SYSTEM_SIZE    200000

/* If MIN_MALLOCED is > 0, the gamedriver will reserve this amount of
 * memory on startup for large blocks, thus reducing the large block
 * fragmentation. The value therefore should be a significantly large
 * multiple of the large chunk size.
 * As a rule of thumb, reserve enough memory to cover the first couple
 * of days of uptime.
 */
#define MIN_MALLOCED  0

/* If MIN_SMALL_MALLOCED is > 0, the gamedriver will reserve this
 * amount of memory on startup for small blocks, thus reducing the small block
 * fragmentation. The value therefore should be a significantly large
 * multiple of the small chunk size.
 * As a rule of thumb, reserve enough memory to cover the first couple
 * of days of uptime.
 */
#define MIN_SMALL_MALLOCED  0

/* This value gives the upper limit for the total allocated memory
 * (useful for systems with no functioning process limit).
 * A value of 0 means 'unlimited'.
 */
#define HARD_MALLOC_LIMIT_DEFAULT    0x4000000

/* This value gives a soft limit of the allocated memory (kind of low
 * watermark). If this value is exceeded, the driver will call low_memory() in
 * the master to inform the mudlib about the (potenntially) developing low
 * memory situation.
 * A value of 0 means 'unlimited'.
 */
#define SOFT_MALLOC_LIMIT_DEFAULT    0

/* --- Random Number Generator (SFMT) --- */
/* Set the period length of the SFMT.
 * Default is a period length of 2^19937 - 1
 */
#define RANDOM_PERIOD_LENGTH 19937

/* --- Interpreter --- */

/* Define STRICT_EUIDS if the driver is to enforce the use of euids,
 * ie. load_object() and clone_object() require the current object to
 * have a non-zero euid.
 */
#undef STRICT_EUIDS

/* Maximum number of evaluated nodes/loop.
 * If this is exceeded, the current function is halted.
 */
#define MAX_COST             1000000

/* Define SHARE_VARIABLES if a clone's variables are to be assigned
 * from the current blueprint's variables. Undefine it if clones
 * should be initialized by __INIT().
 */
#undef SHARE_VARIABLES


/* --- Communication --- */

/* The input escape character.
 */
#define INPUT_ESCAPE             "!"

/* Define what port number the game is to use.
 */
#define PORTNO               2010

/* Define this to the port on which the driver can receive UDP message.
 * If set to -1, the port will not be opened unless the mud is given a valid
 * port number on startup with the -u commandline option.
 */
#define UDP_PORT             4246

/* Maximum numbers of ports the GD accepts connections to.
 */
#define MAXNUMPORTS          20

/* Should code for the external request demon be included?
 */
#define ERQ_DEMON

/* Maximum sizes for an erq send or reply.
 */
#define ERQ_MAX_REPLY 1024
#define ERQ_MAX_SEND  1024

/* Define this if you want IPv6 support (assuming that your host
 * actually offers this.
 */
#undef USE_IPV6

/* maximum number of concurrent outgoing connection attempts by net_connect()
 * (that is connections that are in progress but not fully established yet).
 */
#define MAX_OUTCONN 10


/* ----------- Compilation Options ----------
 * To change these options, the config.h must be recreated and the
 * driver recompiled.
 */

/* Trace the most recently executed bytecode instructions?
 */
#define TRACE_CODE

/* If using TRACE_CODE , how many instructions should be kept?
 */
#define TOTAL_TRACE_LENGTH      4096

/* Runtime statistics:
 *  COMM_STAT: count number and size of outgoing packets.
 *  APPLY_CACHE_STAT: count number of hits and misses in the apply cache.
 */
#define COMM_STAT
#define APPLY_CACHE_STAT

/* The name of the swapfile used by the driver to swap out objects (if
 * enabled), relative to the mudlib directory. The driver will append
 * '.<hostname>' to the file.
 */
#define SWAP_FILE                 "LP_SWAP"


/* --- Memory --- */

/* Which memory manager to use. Possible defines are
 *   MALLOC_smalloc:   Satoria's malloc. Fastest, uses the least memory,
 *                     supports garbage collection.
 *   MALLOC_slaballoc: Slab allocator. Fastest, reduces fragmentation,
 *                     supports garbage collection, not threadsafe.
 *   MALLOC_sysmalloc: the normal system malloc()
 *   MALLOC_ptmalloc:  ptmalloc from www.malloc.de - threadsafe.
 */

#define MALLOC_slaballoc

/* Define this to let the memory allocator request memory from the system
 * directly using sbrk() (assuming the system supports it).
 * If not defined, the memory allocator will use malloc().
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 */
#define MALLOC_SBRK

/* Define this to annotate all allocations with a magic word to find
 * simple misuses of memory (like multiple frees).
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 */
#define MALLOC_CHECK

/* Define this to annotate all allocations with file:line of the driver
 * source responsible for it.
 */
#undef MALLOC_TRACE

/* Define this to annotate all allocations with file:line of the lpc program
 * responsible for it.
 */
#undef MALLOC_LPC_TRACE

/* Define this to log all calls to esbrk() (the system memory allocator).
 * Works best if MALLOC_TRACE is defined.
 * This define is useful if your mud keeps growing in total memory size
 * instead of re-using the memory already allocated.
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 */
#undef MALLOC_SBRK_TRACE

/* --- Wizlist --- */

/* Where to save the WIZLIST information.
 * If not defined, and neither given on the commandline, the driver will
 * not read the WIZLIST file.
 */
#define WIZLIST_FILE  "WIZLIST"


/* --- Access Control --- */
/* file for access permissions data.
 * Don't define this if you don't want the driver to do any access control.
 */
#define ACCESS_FILE "ACCESS.ALLOW"

/* logfile to show valid and rejected connections
 * simple not define this for NO logs
 */
#undef ACCESS_LOG      


/* --- Language --- */

/* Define USE_PARSE_COMMAND if you want the efun parse_command().
 */
#define USE_PARSE_COMMAND

/* Define USE_SET_LIGHT if you want the efun set_light() and the
 * simple 2.4.5 light system.
 */
#define USE_SET_LIGHT

/* Define USE_SET_IS_WIZARD if you want the efun set_is_wizard().
 */
#define USE_SET_IS_WIZARD

/* Define USE_PROCESS_STRING if you want the efun process_string().
 */
#define USE_PROCESS_STRING

/* Define this if you want MCCP (Mud Control Compression Protocol).
 */
#undef USE_MCCP

/* Define this if you want TLS (Transport Layer Security) over Telnet.
 */
#undef USE_TLS

/* Default paths for TLS.
 */
#define        TLS_DEFAULT_KEYFILE        "key.pem"
#define       TLS_DEFAULT_CERTFILE       "cert.pem"
#undef      TLS_DEFAULT_TRUSTFILE      
#undef TLS_DEFAULT_TRUSTDIRECTORY 
#undef        TLS_DEFAULT_CRLFILE        
#undef   TLS_DEFAULT_CRLDIRECTORY   

/* Define this if you want to use libgcrypt (and not OpenSSL).
 */
#define USE_GCRYPT

/* Define this if you want mySQL support (assuming that your host
 * actually offers this.
 */
#undef USE_MYSQL

/* Define this if you want PostgreSQL support (assuming that your host
 * actually offers this.
 */
#undef USE_PGSQL

/* Define this if you want SQLite support (assuming that your host
 * actually offers this.
 */
#undef USE_SQLITE

/* Define this if you want alist support.
 */
#define USE_ALISTS

/* Define this if you want to allow call_other()s on arrays of objects.
 */
#define USE_ARRAY_CALLS

/* Define this if you want PCRE instead of traditional regexps.
 */
#define USE_PCRE

/* Define this if you want to use builtin PCRE (ignored when PCRE
 * is disabled as a whole).
 */
#undef USE_BUILTIN_PCRE

/* Define this if you want iksemel library support.
 */
#undef USE_XML

/* Define this if you want the obsolete and deprecated efuns.
 */
#undef USE_DEPRECATED


/* --- Runtime limits --- */

/* Maximum size of a socket send buffer.
 */
#define SET_BUFFER_SIZE_MAX      65536

/* CATCH_RESERVED_COST is the default value added to the eval cost for the
 * time executing code guarded by a catch() statement, so that an
 * eval_cost-too-big error can still be caught and handled.
 *
 * To catch an eval_cost too big error in an object that called recursive
 * master functions, CATCH_RESERVED_COST should be greater than
 * MASTER_RESERVED_COST.
 */
#define CATCH_RESERVED_COST       2000

/* MASTER_RESERVED_COST is the total reserve available for master applies.
 * It is halved for every recursion into another master apply.
 */
#define MASTER_RESERVED_COST    512 /* must be power of 2 */
/* TODO: Check that at runtime */

/* If this is defined, expensive operations like string additions
 * receive additional evalcosts depending on the amount of data handled.
 */
#undef DYNAMIC_COSTS

/* Show the evaluation costs in the stacktrace.
 */
#undef EVAL_COST_TRACE

/* Define the maximum stack size of the stack machine. This stack will also
 * contain all local variables and arguments.
 */
#define EVALUATOR_STACK_SIZE      2000

/* Define the maximum call depth for functions.
 * MAX_USER_TRACE is used for for normal program execution, the full
 * MAX_TRACE is only available in error handling.
 *
 * MAX_TRACE must be larger than MAX_USER_TRACE (check at compile time).
 */
#define MAX_USER_TRACE              60
#define MAX_TRACE                   65

/* Maximum number of bits in a bit field. They are stored in printable
 * strings, 6 bits per byte.
 * The limit is more based on considerations of speed than memory
 * consumption.
 */
#define MAX_BITS                  6144

/* Maximum number of players in the game.
 */
#define MAX_PLAYERS                50

/* When uploading files, we want fast response; however, normal players
 * shouldn't be able to hog the system in this way.  Define ALLOWED_ED_CMDS
 * to be the ratio of the no of ed cmds executed per player cmd.
 */
#define ALLOWED_ED_CMDS           20
/* TODO: ALLOWED_ED_CMDS: make this a runtime option */

/* Limit the amount of recursion in the PCRE code. Setting it to low will
 * prevent certain regexps to be executed properly, setting it too high can
 * cause that regexps to crash the driver. Set it according to the
 * available maximum stack size for the driver process. (Rule of thumb:
 * The memory used for a recursion on the stack seems to be within 466 and
 * 1008 bytes. If you have 8M of stack size, reserve half of it for LPC 
 * recursions and choose about 3000 - 4000.) In doubt, increase the stack
 * size limit for the driver process with ulimit & Co.)
 * Defaults to 3000
 */
#define LD_PCRE_RECURSION_LIMIT    3000

/* The maximum length of the buffer for commands. The maximum length of a
 * command will be MAX_COMMAND_LENGTH - 1.
 */
#define MAX_COMMAND_LENGTH       1000

/* --- Compiler --- */

/* Define the size of the compiler stack. This defines how complex
 * expressions the compiler can parse. The value should be big enough.
 */
#define COMPILER_STACK_SIZE        400

/* Max number of local variables in a function.
 */
#define MAX_LOCAL                   50

/* Maximum size of an expanded preprocessor definition.
 */
#define DEFMAX                   65000


/* --- Internal Tables --- */

/* Define the size of the shared string hash table.  This number needn't
 * be prime, probably between 1000 and 30000; if you set it to about 1/5
 * of the number of distinct strings you have, you will get a hit ratio
 * (number of comparisons to find a string) very close to 1, as found strings
 * are automatically moved to the head of a hash chain.  You will never
 * need more, and you will still get good results with a smaller table.
 * If the size is a power of two, hashing will be faster.
 */
#define HTABLE_SIZE               4096

/* Object hash table size.
 * Define this like you did with the strings; probably set to about 1/4 of
 * the number of objects in a game, as the distribution of accesses to
 * objects is somewhat more uniform than that of strings.
 */
#define OTABLE_SIZE               1024

/* Define the size of the ident_table. It contains all global identifiers
 * (efuns and permanent defines) as well as the identifiers of a compiled
 * program which are removed from the ident_table after compilation.
 * Must be within 256 and the maximum of a short (SHRT_MAX, usually 32768).
 */
#define ITABLE_SIZE               256

/* the number of apply_low cache entries will be 2^APPLY_CACHE_BITS.
 */
#define APPLY_CACHE_BITS            12

/* The parameters of the regular expression/result cache.
 * The expression cache uses a hashtable of RXCACHE_TABLE entries.
 * Undefine RXCACHE_TABLE to disable the all regexp caching.
 */
#define RXCACHE_TABLE            8192

/* --- Current Developments ---
 * These options can be used to disable developments-in-progress if their
 * code turns out to be interrrupting.
 */

/* Define this if you want structs supported.
 */
#define USE_STRUCTS

/* Define this if you want the new inline closure syntax supported.
 * (f-020528).
 */
#define USE_NEW_INLINES


/* --- Profiling ---
 * For profiling of the VM instruction implementations, refer to the Makefile
 */

/* Enable usage statistics of VM instructions.
 * For profiling of the VM instructions themselves, see the Profiling
 * Options in the Makefile.
 */
#undef OPCPROF

#ifdef OPCPROF
/* With OPCPROF, the dump of the statistics include the names
 * of the instructions.
 */
#undef VERBOSE_OPCPROF
#endif


/* --- Standard Debugging --- */

/* Enable basic run time sanity checks. This will use more time
 * and space, but nevertheless you are strongly encouraged to keep
 * it defined.
 */
#define DEBUG

/* Enable debug output from the LPC compiler.
 */
#undef YYDEBUG

/* Disable inlining.
 */
#undef NO_INLINES

/* Activate debug prints in the telnet machine.
 */
#undef DEBUG_TELNET

/* Activate allocation debug prints in the malloc module.
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 */
#undef DEBUG_MALLOC_ALLOCS

/* The DEBUG level for the ERQ daemon:
 *  0 : no debug output
 *  1 : standard debug output
 *  2 : verbose debug output
 */
#define ERQ_DEBUG 0


/* --- Specific Debugging ---
 * These options have been introduced to debug specific problems and will
 * be removed again later.
 */

/* Enable the automatic data cleanup from the backend.
 * TODO: Remove this macro once it is proven stable.
 */
#define NEW_CLEANUP

/* Log the details of the automatic data cleanup for each individual object.
 * This is useful if the cleanup is suspected to hog the CPU.
 * TODO: Remove this macro once it is proven stable.
 */
#undef LOG_NEW_CLEANUP

/* Log the details of the automatic data cleanup of all objects. This is
 * useful if the cleanup is suspected to hog the CPU.
 * TODO: Remove this macro once it is proven stable.
 */
#define LOG_NEW_CLEANUP_ALL

/* Enable the use of freelists in the malloc AVL nodes.
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 * TODO: Remove this macro once it is proven stable or if the change
 * TODO:: didn't bring any advantages..
 */
#define USE_AVL_FREELIST

/* Order malloc large block freelists by address.
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 * TODO: Remove if it doesn't help with the fragmentation, as it uses up
 * TODO:: a small, but measurable amount of time in the allocator.
 */
#define MALLOC_ORDER_LARGE_FREELISTS

/* Order slaballoc partial-slab freelists by number of free blocks.
 * Supported by: MALLOC_slaballoc.
 * TODO: Remove if it doesn't help with the fragmentation, as it uses up
 * TODO:: a small, but measurable amount of time in the allocator.
 */
#define MALLOC_ORDER_SLAB_FREELISTS

/* Allow slaballoc to use multiples of DESIRED_SLAB_SIZE when creating
 * new slabs.
 */
#define SLABALLOC_DYNAMIC_SLABS

/* Collect extended malloc statistics.
 * Supported by: MALLOC_smalloc, MALLOC_slaballoc.
 * TODO: Remove this macro or make it configurable.
 */
#define MALLOC_EXT_STATISTICS

/* Collected statistics about string comparisons.
 * TODO: Remove this macro after we got our  data.
 */
#define EXT_STRING_STATS

/* Trace changes to the tot_alloc_object and tot_alloc_object_size
 * statistics, in order to find the status bugs (enables commandline
 * option --check-object-stat). Will produce a decent amount of
 * output on stderr.
 */
#undef CHECK_OBJECT_STAT

/* Activate total mapping size consistency check code. It has a small
 * impact on the execution speed. This define was used to find
 * the inaccuracy in the mapping statistic.
 */
#undef CHECK_MAPPING_TOTAL

/* Activate object refcount check code. It will produce a decent
 * amount of log output. It will also fatal() the driver as soon
 * as it detects an inconsistency in the list of destructed objects.
 */
#undef CHECK_OBJECT_REF

/* Activate object referencing checking code during the GC. It will
 * print error messages to gcout when an object or program is
 * referenced as something else. No penalty for using.
 * Requires MALLOC_TRACE to work. Incompatible with DUMP_GC_REFS.
 */
#ifdef MALLOC_TRACE
#define CHECK_OBJECT_GC_REF
#endif

/* Sometimes the GC stumbles over invalid references to memory
 * blocks (namely 'Program referenced as something else'). Define
 * this macro to get a detailed dump of all found references
 * (Warning: LOTS of output!). Incompatible with CHECK_OBJECT_GC_REF.
 */
#undef DUMP_GC_REFS

#endif /* CONFIG_H__ */
