//
// Wunderland Mudlib
//
// secure/sefun/tail.c -- tail fuer ldmud 3.5
//
// $Log: tail.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is meant to replace the deprecated efun tail().
 * Feel free to add it to your mudlibs, if you have much code using tail() or
 * want to use tail().
 */

#if ! __EFUN_DEFINED__(tail)

#include <files.h>

#define TAIL_MAX_BYTES 1000

varargs int tail(string file)
{
    // if (extern_call())
    //     set_this_object(previous_object());

    if (!stringp(file) || !this_player())
        return 0;
    string txt = read_bytes(file, -(TAIL_MAX_BYTES + 80), (TAIL_MAX_BYTES + 80));
    if (!stringp(txt))
        return 0;

    // cut off first (incomplete) line
    int index = strstr(txt, "\n");
    if (index > -1) {
        if (index + 1 < sizeof(txt))
            txt = txt[index+1..];
        else
            txt = "";
    }

    tell_object(this_player(), txt);

    return 1;
}

#endif
