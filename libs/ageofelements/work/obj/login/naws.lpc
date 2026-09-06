/*
** /obj/login/naws.c
**
**  Author: Tamarindo
**
**    Date: December 2019
**
** Purpose: The Negotiate About Window Size (NAWS) allow a client to
**	convey window size to the game.
**
** References:
**
**	https://tools.ietf.org/html/rfc1073
**
** See Also:
**
**	/obj/login/telopt.c
*/

#ifndef OBJ_LOGIN_NAWS_C
#define OBJ_LOGIN_NAWS_C

#ifndef LPC_LPCTYPES_H
#include <sys/lpctypes.h>
#endif // LPC_LPCTYPES_H

#ifndef TELNET_H__
#include <sys/telnet.h>
#endif // TELNET_H__

nosave int term_columns = 80;
nosave int term_rows = 24;

// Prototypes
public nomask int get_term_columns();
public nomask int get_term_rows();
private void naws_input(int *optdata);

/*
** Function: get_term_columns
**
**  Purpose: Query the number of columns the client displays.
**
**  Returns: int, number of columns.
*/
public nomask int
get_term_columns() {
    return term_columns;
}

/*
** Function: get_term_rows
**
**  Purpose: Query the number of rows the client displays.
**
**  Returns: int, number of rows.
*/
public nomask int
get_term_rows() {
    return term_rows;
}

/*
** Function: naws_input
**
**  Purpose: The telopt_negotiate function routes inbound NAWS messages from
**               the player's client here for handling.
*/
private void
naws_input(int *optdata) {
    // Parse the data
    for (int i = 0; i < sizeof(optdata); i++) {
	if (i == 1) {
	    term_columns = optdata[i];
	} else if (i == 3) {
	    term_rows = optdata[i];
	}
    }
}
#endif // OBJ_LOGIN_NAWS_C
