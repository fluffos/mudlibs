/* This sefun is meant to replace the deprecated efun tail().
 * Feel free to add it to your mudlibs, if you have much code using tail() or
 * want to use tail().
 */

#include "/sys/files.h"

#define TAIL_MAX_BYTES 1000

varargs int
tail(string file)
{
    //if (extern_call())
	//set_this_object(previous_object());
#if __VERSION__ >= "3.5.99"
    if (!stringp(file) || !efun::this_player()) {
	return 0;
    }

    bytes txt = read_bytes(file, -(TAIL_MAX_BYTES + 80), (TAIL_MAX_BYTES + 80));

    if (!bytesp(txt)) {
	return 0;
    }

    // cut off first (incomplete) line
    int index = strstr(txt, b"\n");

    if (index > -1) {
	if (index + 1 < sizeof(txt)) {
	    txt = txt[index+1..];
	} else {
	    txt = b"";
	}
    }

    tell_object(efun::this_player(), to_text(txt, "UTF-8"));
#else
    if (!stringp(file) || !this_player()) {
	return 0;
    }

    string txt = read_bytes(file, -(TAIL_MAX_BYTES + 80), (TAIL_MAX_BYTES + 80));

    if (!stringp(txt)) {
	return 0;
    }

    // cut off first (incomplete) line
    int index = strstr(txt, "\n");

    if (index > -1) {
	if (index + 1 < sizeof(txt)) {
	    txt = txt[index+1..];
	} else {
	    txt = "";
	}
    }

    tell_object(efun::this_player(), txt);
#endif
    return 1;
}
