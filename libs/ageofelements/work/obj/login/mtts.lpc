/*
** /obj/login/mtts.c
**
**  Author: Tamarindo
**
**    Date: December 2019
**
** Purpose: The MUD Terminal Type Standard (MTTS) provides a
**          standard for mud clients to communicate their
**          terminal capabilities.
**
** References:
**
**	https://tintin.sourceforge.io/protocols/mtts/
**
** Notes:
**
**	TinTin++, MUSH Client and Mud Portal are the only
**	known clients supporting this today.
**
** See Also:
**
**	/obj/login/telopt.c
*/

#ifndef OBJ_LOGIN_MTTS_C
#define OBJ_LOGIN_MTTS_C

#ifndef LPC_LPCTYPES_H
#include <sys/lpctypes.h>
#endif // LPC_LPCTYPES_H

#ifndef TELNET_H__
#include <sys/telnet.h>
#endif // TELNET_H__

#ifndef MTTS_H
#include <mtts.h>
#endif // MTTS_H

nosave string term_client;
nosave string term_type;
nosave int term_standard;
nosave mapping term_env;

// Prototypes
public nomask string query_term_client();
public nomask string query_term_type();
public nomask int query_term_standard(int arg);
public nomask string query_term_env(string arg);
private void mtts_input(int *optdata);
private void newenv_input(int *optdata);

/*
** Function: query_term_client
**
**  Purpose: Query the client name.
**
**  Returns: string, name of the client.
*/
public nomask string
query_term_client() {
    return term_client;
}

/*
** Function: query_term_type
**
**  Purpose: Query the client terminal type.
**
**  Returns: string, type of the client.
**
**    Notes: Console clients should report the name of the terminal emulator,
**           other clients should report one of the four most generic terminal
**           types:
**
**           "DUMB"  Terminal has no ANSI color or VT100 support.
**           "ANSI"  Terminal supports the common ANSI color codes. Supporting
**                   blink and underline is optional.
**           "VT100" Terminal supports most VT100 codes and ANSI color codes.
**           "XTERM" Terminal supports all VT100 and ANSI color codes,
**                   256 colors, mouse tracking, and all commonly used xterm
**                   console codes.
**
**           LDMud provides guidance to store these as lower case.
*/
public nomask string
query_term_type() {
    return term_type;
}

/*
**   Function: query_term_standard
**
**    Purpose: Query the bitvector of the client supported terminal
**             capabilities.
**
** Parameters: int arg, value to & (AND) with the bitvector.
**
**    Returns: int, a value of 0 (false) or 1 (true).
**
**      Notes: A bitvector. The bit values and their names are defined below:
**
**               1 "ANSI"              Client supports all common ANSI
**                                     color codes.
**               2 "VT100"             Client supports all common VT100 codes.
**               4 "UTF-8"             Client is using UTF-8 character encoding.
**               8 "256 COLORS"        Client supports all 256 color codes.
**              16 "MOUSE TRACKING"    Client supports xterm mouse tracking.
**              32 "OSC COLOR PALETTE" Client supports the OSC color palette.
**              64 "SCREEN READER"     Client is using a screen reader.
**             128 "PROXY"             Client is a proxy allowing different
**                                     users to connect from the same IP address.
**             256 "TRUECOLOR"         Client supports truecolor codes using
**                                     semicolon notation.
**
**             The client adds up the numbers of all supported terminal
**             capabilities and prints it as ASCII in decimal notation. In the
**             case that a client supports ANSI, UTF-8, as well as 256 COLORS,
**             it should respond with "MTTS 13", which is the sum of 1, 4, and
**             8. The reporting of UTF-8 should be implemented as a user setting,
**             unless the client is certain that a Unicode font is being used.
*/
public nomask int
query_term_standard(int arg) {
    return (term_standard & arg);
}

/*
** Function: query_term_env
**
**  Purpose: Query the terminal environment variables.
**
**  Returns: string, value of environment variable
*/
public nomask string
query_term_env(string arg) {
    if (!term_env || !mappingp(term_env) || !arg || !stringp(arg)) {
	return 0;
    }

    return term_env[arg];
}

/*
**   Function: mtts_input
**
**    Purpose: The telopt_negotiate function routes inbound MTTS messages from
**             the player's client here for handling.
**
** Parameters: int *optdata, option data
*/
private void
mtts_input(int *optdata) {
    string data;
    int i, tmp;

    // Parse the data
    for (i = 0; i < sizeof(optdata); i++) {
	if (!i && optdata[i] != MTTS_IS) {
	    return;
	} else if (i > 0) {
	    data = sprintf("%s%c", data ? data : "", optdata[i]);
	}
    }

    if (!term_client) {
	term_client = data;
        binary_message(({IAC, SB, TELOPT_TTYPE, MTTS_SEND, IAC, SE}));
    } else if (!term_type) {
	term_type = data;
        binary_message(({IAC, SB, TELOPT_TTYPE, MTTS_SEND, IAC, SE}));
    } else if (!term_standard) {
	if (sscanf(data, "MTTS %d", term_standard) == 1) {
            binary_message(({IAC, SB, TELOPT_TTYPE, MTTS_SEND, IAC, SE}));
	}
    } else {
	if (sscanf(data, "MTTS %d", tmp) == 1 && tmp == term_standard) {
	    // The end of the list of available terminal types has been reached

	    // If the client is using a proxy, we'll see if the client WILL share
	    // environmental variables through telopt.c and send the user's IPADDRESS
	    // through the newenv_input below to save in the term_env mapping.
	    if (query_term_standard(MTTS_STD_PROXY)) {
		binary_message(({IAC, DO, TELOPT_NEWENV}));
	    }
	}
    }
}

/*
**   Function: newenv_input
**
**    Purpose: The telopt_negotiate function routes inbound NEW-ENVIRO messages from
**             the player's client here for handling.
**
** Parameters: int *optdata, option data
*/
private void
newenv_input(int *optdata) {
    string data, var, val;
    int i, is_val;

    // Parse the data
    for (i = 0; i < sizeof(optdata); i++) {
	if (!i) {
	    if (optdata[i] != MTTS_IS) {
		return; // Invalid
	    } else {
		continue;
	    }
	}

	switch (optdata[i]) {
	case MTTS_VAR:
	    // If we have a value on the stack, save it now.
	    if (sizeof(val)) {
		if (!term_env || !mappingp(term_env)) {
		    term_env = ([ var: val ]);
		} else {
		    term_env[var] = val;
		}
	    }

	    is_val = 0;
	    var = 0;
	    break;
	case MTTS_VALUE:
	    is_val = 1;
	    val = 0;
	    break;
	default:
	    if (!is_val) {
		var = sprintf("%s%c", var ? var : "", optdata[i]);
	    } else {
		val = sprintf("%s%c", val ? val : "", optdata[i]);
	    }
	    break;
	}
    }

    // If we have a value on the stack, save it now.
    if (sizeof(val)) {
	if (!term_env || !mappingp(term_env)) {
	    term_env = ([ var: val ]);
	} else {
	    term_env[var] = val;
	}
    }
}
#endif // OBJ_LOGIN_MTTS_C
