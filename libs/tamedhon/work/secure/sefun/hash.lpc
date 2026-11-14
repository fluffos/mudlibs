//
// Wunderland Mudlib
//
// secure/sefun/hash.c -- md5 and sha1 fuer ldmud 3.5
//
// $Log: hash.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

#if __EFUN_DEFINED__(hash)

#include "/sys/tls.h"

string md5(mixed arg, varargs mixed* iterations)
{
    if (extern_call())
         set_this_object(previous_object());

#if __EFUN_DEFINED__(to_bytes)
    if (stringp(arg))
        arg = to_bytes(arg, ENCODING);
#endif

    return hash(TLS_HASH_MD5, arg, iterations...);
}

string sha1(mixed arg, varargs mixed* iterations)
{
    if (extern_call())
         set_this_object(previous_object());

#if __EFUN_DEFINED__(to_bytes)
    if (stringp(arg))
        arg = to_bytes(arg, ENCODING);
#endif

    return hash(TLS_HASH_SHA1, arg, iterations...);
}

string sha512(mixed arg, varargs mixed* iterations)
{
    if (extern_call())
         set_this_object(previous_object());

#if __EFUN_DEFINED__(to_bytes)
    if (stringp(arg))
        arg = to_bytes(arg, ENCODING);
#endif

    return hash(TLS_HASH_SHA512, arg, iterations...);
}

#endif
