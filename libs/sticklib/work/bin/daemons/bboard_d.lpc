/****************************************************************
*								*
* Module:							*
*	/bin/daemons/bboard_d.c					*
* Description:							*
*	Central daemon that the bulletin boards use for storing	*
*	and retrieving data (notes). Originally written for	*
*	MurderMud; not used in StickMud. Converted and added	*
*	to StickLib by Doomdark.				*
* Version:							*
*	1.0a (for StickLib), Aug-98				*
* Last update:							*
*	28-Aug-98 by Doomdark					*
*								'
* Modifications:						*
*								*
****************************************************************/

#include <config.h>
#include <coder_levels.h>
#include <bboard_defs.h>



#define _SAVEDIR	"/data/d/bboard_d/"
#define	_SAVEFILE	"/data/d/bboard_d/last_notes"
#define	DO_SAVE	save_object(_SAVEFILE);
#define	DO_LOAD	restore_object(_SAVEFILE);

// Prevent access from other objects than those that are _clones_ of
// /std/obj/bboard.c!

#define _SECURE_CHECK_FAILURE ( previous_object()\
	&& strstr(object_name( previous_object()),"std/obj/bboard#"))


mapping _last_notes;

nomask void
create()
{
    DO_LOAD
    if (!mappingp(_last_notes))
	_last_notes = ([ ]);
}

// Don't allow shadowing of this object.
status query_prevent_shadow() { return 1; }

// Query information about the specified board, including
// a header list, a specifed message, or the general help
// information for bulletin boards.
//
mixed
query_board(int func, mixed num, string boardname, object who )
{
    string *dir,*headers, mess,tmp, tmp_name,tmp_title,tmp_date;
    int i;
    mixed x;

    if ( _SECURE_CHECK_FAILURE ) {
	//raise_error("\nSECURITY ERROR ON BBOARDD!\n");
	return 0;
    }

    switch( func )
    {

	// Read all files in the bboard dir, and return an array of formatted
	// text headers.
    case BB_INFO_HEADERS :
    case BB_INFO_ALL:	// Or perhaps return even more data...

	// Get all of the note filenames for this board
	if ( !(dir = get_dir(sprintf("%s%s/@*",_SAVEDIR, boardname))))
	    return 0;

	headers = allocate(sizeof(dir));
	for ( i=0; i<sizeof(dir); i++ )
	{
	    if ( !mess = read_file(sprintf("%s%s/%s",	// Read the file
		  _SAVEDIR,boardname,dir[i]),1,3)) return 0;	
	    if ( sscanf(mess, "%sTitle: %s\n%sName: %s\n%sDate: %s\n",
		tmp, tmp_title, tmp, tmp_name , tmp, tmp_date) !=6 )
	    {
		tmp_title = "-error";
		tmp_name = "-error-";
		tmp_date = "-error-";
	    }
	    headers[i] = sprintf("(%-6.6s) %-10s: %s", tmp_date, tmp_name, tmp_title);
	}
	if (func != BB_INFO_ALL) {
	    return headers;
	}

	return ({ dir, headers });

    case BB_INFO_ALL2:

	// Get all of the note filenames for this board
	if ( !(dir = get_dir(x=sprintf("%s%s/*.note",_SAVEDIR, boardname)))) {
	    //raise_error(sprintf("\nCan't read %s!\n", x));
	    return 0;
	}

	headers = allocate(sizeof(dir));
	for ( i=0; i<sizeof(dir); i++ )
	{
	    if ( !mess = read_file(sprintf("%s%s/%s",
		  _SAVEDIR,boardname,dir[i]),1,3)) return 0;	
	    if ( sscanf(mess, "%sTitle:%t%s\n%sName:%t%s\n%sDate:%t%s\n",
		tmp, tmp_title, tmp, tmp_name , tmp, tmp_date) !=6 )
	    {
		tmp_title = "-error";
		tmp_name = "-error-";
		tmp_date = "-error-";
	    }
	    headers[i] = sprintf("(%-s) %-10s %s", tmp_date, tmp_name,
	      tmp_title);
	}
	return ({ dir, headers });

	// Read the file and return the entire file text.
    case BB_INFO_MESSAGE :

	/* If we are given the filename things go even better... */
	if (stringp(num))
	    return read_file(sprintf("%s%s/%s",_SAVEDIR, boardname, num));
	if (!intp(num))
	    return 0;

	// Get all of the note filenames for this board
	if ( !(dir = get_dir(sprintf("%s%s/@*",_SAVEDIR, boardname))))
	    return 0;
	if (num-- > sizeof(dir) || num < 0 )
	    return 0;
	return read_file(sprintf("%s%s/%s",_SAVEDIR, boardname,dir[num]));

    }
}

// Perform an action that modifies the specified bulletin board.
// Valid actions include removing a message, and adding a message
// from either the specified string or a filename. 
//
status
board_command(int func, int num, string message, string boardname,
  object me, int b_flags)
{
    int i;
    string *dir, nfile, mess, tmp, name, subj;

    if ( _SECURE_CHECK_FAILURE )
	return 0;

    // Get the filenames of the board messages.
    if ( !dir = get_dir(sprintf("%s%s/%s",_SAVEDIR,boardname,"@*")))
	return 0;

    // Guest cannot modify the bboard.
    if ((string)me->query_real_name() == "guest")
	return 0;

    switch ( func ) {

	// Remove the specified message from the specified board.
	// Non-admins can only remove their own messages.

    case CMD_BB_REMOVE :

	if (stringp(num)) {
	    if ((num = member(dir, num)) < 0)
		return 0;
	} else if ( num-- > sizeof(dir) || num < 0 )
	    return 0;
	nfile = sprintf("%s%s/%s",_SAVEDIR,boardname,dir[num]);
	if ( !mess = read_file(nfile,2,1)) return 0; 
	if ( sscanf(mess, "%sName: %s\n",tmp,name) != 2) return 0;
	if ( lower_case(name) != (string)me->query_real_name()
	  && me->query_coder_level() < LVL_COADMIN)
	    return 0;
	if (rm(nfile)) {
	    if (i == (sizeof(dir) - 1))
		_last_notes[boardname] = sizeof(dir) ? dir[<1] : 0;
	    DO_SAVE
	    return 1;
	}
	return 0;

	// Post a file to the bboard.
	// Only coders can do this, and the specified file must be in the 
	// coder's home directory tree.

    case CMD_BB_POST :

	if ( sscanf(message, PATH_USER_FNAME "%s/%s %s", name,tmp,subj )<3 )
	    if ( sscanf(message, PATH_USER_FNAME "%s/%s",name,tmp ) < 2 )
		return 0;
	if ( lower_case(name) != (string)me->query_real_name())
	    return 0;
	if ( !stringp(mess = read_file(message))) return 0;
	message = sprintf("Title: %s\nName: %s\nDate: %s\n\n%s",
	  ( !subj || subj == "" ) ? "none" : subj,
	  capitalize((string)me->query_real_name()),
	  ctime(time())[4..9], mess);
	// Fall thru to CMD_BB_WRITE

	// Determine the filename of the new message, and copy it to the
	// bboard directory.

	/* Also, mark it as the last note so that we can check if the coders
	 * have unread messages.
	 */

    case CMD_BB_WRITE :

	if (sizeof(dir))
	    sscanf( dir[sizeof(dir)-1], "@%d", i );
	else i=0;
	nfile = sprintf("@%06d", i+1);
	if (write_file(name=sprintf("%s%s/%s", _SAVEDIR, boardname, nfile),
	    message)) {
	    if (b_flags & F_BBOARD_NO_NOTIFY)
		m_delete(_last_notes, boardname);
	    else
		_last_notes[boardname] = nfile;
	    DO_SAVE
	    return 1;
	} else {
	    printf("ERROR: Failed to write to file %s.\n", name);
	}
	return 0;

    }
    return 0;
}

string *
check_last_notes(object plr, mapping ln)
{
    string *boards, *notes, x, y;
    int i, n;
    if (!mappingp(ln))
	ln = ([ ]);
    boards = m_indices(_last_notes);
    notes = m_values(_last_notes);
    for (i = n = 0; i < sizeof(boards); i++) {
	if (!(y = notes[i]) || (
	    (x = ln[boards[i]]) && (x >= y))) {
	    n++;
	    boards[i] = 0;
	}
    }
    if (n) {
	if (n == sizeof(boards))
	    return 0;
	return boards - ({ 0 });
    }
    return boards;
}

mapping
query_last_notes()
{
    return _last_notes;
}
