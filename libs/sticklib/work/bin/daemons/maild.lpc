//************************************************************************
// maild.c -  mail daemon                                               //
// Version: 0.1h                                                        //
// Created by Germ 10-Jun-98                                            //
//                                                                      //
// Comments:                                                            //
//      This daemon is called by the postbox room/object and            //
//      handles all of the accessing of the mail savefiles.             //
//                                                                      //
// NEW:                                                                 //
//  18-Sep-96, Germ: The group aliases are now derived from the         //
//      defines in /secure/coders.h.                                    //
//  19-Sep-96, Germ: post_command(), query_mail(), and query_info()     //
//      now allow the input variable 'who' to be a string, but          //
//      only if previous_object() is /secure/login.c. This              //
//      allows mail to be accessed from the login menu.                 //
//  21-Sep-96, Waugh: case CMD_MAIL_SAVE in post_command() changed to   //
//      allow for the variable 'who' to be a string and a member of     //
//      the ADMIN_LIST, COADMIN_LIST, or CODER_LIST.                    //
//  26-Sep-96, Waugh: fixed bug in query_valid_name() which if passed   //
//      a string with a space in it, would bomb the object calling it   //
//      because it would create an error in master.c.                   //
//  16-Oct-96, Germ: Implemented read <next/previous>                   //
//  03-May-97, Germ: Fixed bug where players with no savefile could     //
//      read mail of the person who last accessed the mail daemon.      //
//  21-May-97, Germ: Fixed a bug when CC contained multiple aliases.    //
//  05-jun-97, Germ: save-files are now stored in multiple directories, //
//      sorted alphabetically.                                          //
// 19-Sep-98, Kieve: Modified it for StockMUD                           //
//                                                                      //
//************************************************************************

#include <player_defs.h>
#include <mail_defs.h>
#include <config.h>
#include <generic_items.h>
#include "/secure/coders.h"

#define _MAIL_PATH      "/data/d/maild/"
#define _SAVE_FILE      "mail.mbox"
#define _ILLEGAL_CHARS  ({ "/", "." })

#define DEBUG(xx) if(find_player("kieve")) \
                      find_player("kieve")->tell_me(xx);

// We only allow this daemon to be called by certain objects,
// Currently: /std/mailbox.c and /secure/login.c
//
#define _PREVIOUS_OBJ(obj) ( previous_object()\
        && (sscanf(object_name( previous_object()),obj,tmp)==1))

#define _GROUPS ([\
        "Admins"   : ADMIN_LIST,\
        "Coadmins" : COADMIN_LIST\
        ])


int    _new_mail;       // Flag if there is any new mail.
int    _last_read;      // The message # we last read.
string *_sender;
string *_subject;
string *_cc;
string *_message;
int    *_time;

// Function prototypes
//
nomask void load_player(mixed who);
nomask string query_valid_name(string s);

//
// Miscelaneous command handler
// Handles:  headers, read, delete, save.
//
// Note: Return codes are used to specify the various errors
//      that can occur, and return_text provides an error
//      message.  The return code allows the calling object
//      to use it's own custom error messages.
//
nomask int
post_command(int func, string str, string return_text, mixed who )
{
    string tmp,line, *tmp1, *tmp2, *tmp3, *tmp4;
    int *tmp5, num, size, i, j;

    if (!who || !_PREVIOUS_OBJ((GENERIC_MAILBOX)[1..<1]+"#%s")
      && ( stringp(who) && !_PREVIOUS_OBJ((PLAYER_FILE)[1..<1]+"#%s")))
	return RET_ERROR;

    load_player(who);

    if ( !size = sizeof(_sender) )
    {
	return_text = "You have no mail in your box.";
	return RET_NO_MAIL;
    }
    //
    // Non-indexed commands:
    //      - headers
    //
    switch ( func )
    {
    case CMD_MAIL_HEADERS :
	line = "Your box contains the following messages:\n";
	for (i=0; i<size; i++)
	    line = sprintf("%s\n%3d. (%-6.6s) %-10s Subj: %s",
	      line, i+1, ctime(_time[i])[4..9],
	      _sender[i], _subject[i] );
	return_text = line;
	return RET_SUCCESS;
    }
    //
    // Indexed commands:
    //      - delete, save
    //

    if ( !str || sscanf(str,"%d", num)!=1) return 0;
    if ( num>size || num < 1)
    {
	return_text = sprintf("Illegal message number: %d", num);
	return RET_BAD_NUM;
    }
    num--;
    switch ( func )
    {
    case CMD_MAIL_DELETE :
	tmp1 = ({ });
	tmp2 = ({ });
	tmp3 = ({ });
	tmp4 = ({ });
	tmp5 = ({ });
	for ( i=0; i<size-1; i++ )
	{
	    if ( j==num ) j++;
	    tmp1 += ({ _sender[j] });
	    tmp2 += ({ _subject[j] });
	    tmp3 += ({ _cc[j] });
	    tmp4 += ({ _message[j] });
	    tmp5 += ({ _time[j] });
	    j++;
	}
	_sender = tmp1;
	_subject = tmp2;
	_cc = tmp3;
	_message = tmp4;
	_time = tmp5;
	_new_mail = 0;
	if (objectp(who)) tmp=(string)who->query_real_name();
	else if ( stringp(who) ) tmp = who;
	save_object(sprintf("%s%s/%s",_MAIL_PATH, tmp[0..0], tmp ));
	return_text = sprintf("Message %d deleted.",num+1);
	return RET_SUCCESS;

    case CMD_MAIL_SAVE  :
	if ( objectp(who) && (who->query_coder_level() > 0) ||
	  stringp(who) && (member(ADMIN_LIST, who) != -1
	    || member(COADMIN_LIST, who) != -1
	    || member(CODER_LIST, who) != -1) )
	{
	    if (objectp(who))
		tmp = lower_case((string)who->query_real_name());
	    else if (stringp(who)) tmp = lower_case(who);
	    line = sprintf("/u/%s/%s", tmp, _SAVE_FILE);
	    if ( write_file(line,sprintf(
		  "From:\t\t%s\nSubject:\t%s\nDate:\t\t%s\nCC:\t\t%s\n\n%s\n",
		  capitalize(_sender[num]), _subject[num],
		  ctime(_time[num])[4..9],
		  _cc[num], _message[num])))
	    {
		return_text = sprintf("Message saved in %s", line);
		return RET_SUCCESS;
	    }
	    else
	    {
		return_text = sprintf("Failed to save to %s",line);
		return RET_FAILED_SAVE;
	    }
	    return RET_SUCCESS;
	}
	return_text = "Only coders can save mail.";
	return RET_CODERS_ONLY;
    }
    return RET_ERROR;
}

//
// Loads the player's mail file into memory. If the file
// contains new mail, reset the new_mail flag and re-save.
//
nomask void
load_player(mixed who)
{
    string n;

    // Clear all the global vars...
    _new_mail = 0;
    _last_read = 0;
    _sender = 0;
    _subject = 0;
    _cc = 0;
    _message = 0;
    _time = 0;

    if ( !who ) return;
    if ( objectp(who) ) n=(string)who->query_real_name();
    else
    if ( stringp(who) ) n = who;

    if ( !n || !restore_object(sprintf("%s%s/%s",_MAIL_PATH,n[0..0],n)))
	return;
    if (!_new_mail) return;
    _new_mail = 0;
    save_object(sprintf("%s%s/%s",_MAIL_PATH,n[0..0],n));
}


//
// Sends the mail provided in the input args to the
// dest and cc recipients.
//
nomask void
send_mail(mixed who, string dest, string subj, string cc, string mess )
{
    int i,j;
    string tmp, *list, *cc_tmp, *new, name;
    object ob;
    mapping groups;
    groups = _GROUPS;

    if (( !_PREVIOUS_OBJ((GENERIC_MAILBOX)[1..<1]+"#%s") &&
	!_PREVIOUS_OBJ((PLAYER_FILE)[1..<1]+"#%s")) || 
      !who || !dest || !mess ) return;

    if ( member(groups,dest ))
    {
	list = groups[dest];
	name = dest;
    }
    else
    {
	list = ({ dest });
	name = "";
    }


    if (cc && cc != "")          // Get the valid cc recipients
    {
	cc_tmp = explode(cc, ",");
	for (i=0; i<sizeof(cc_tmp); i++)
	    // Check if the names are valid...
	    if (( member(list, cc_tmp[i]=capitalize(cc_tmp[i]))==-1 )
	      && cc_tmp[i]=query_valid_name( cc_tmp[i] ))
	    {
		new = (member(groups,cc_tmp[i])) ?
		new=groups[cc_tmp[i]] : ({ cc_tmp[i] });
		for ( j=0; j<sizeof(new); j++ )
		    // Don't add the same name twice...
		    if ( member(list,new[j])==-1) list+= ({ new[j] });
		if (name=="") name = cc_tmp[i];
		else name = sprintf("%s,%s",name,cc_tmp[i]);
	    }
    }

    cc = name;
    if(objectp(who))
	name = (string)who->query_real_name();
    else if(stringp(who))
	name = who;
    for ( i=0; i<sizeof(list); i++ )     // Send the mail to the recipients
    {
	if(objectp(who))
	    who->tell_me(sprintf("Sending mail to %s.", list[i]));
	if (ob = find_player(lower_case(list[i])))
	    ob->tell_me(sprintf("You have new mail from %s, Subject: %s",capitalize(name),subj));

	if ( !restore_object(sprintf("%s%s/%s",_MAIL_PATH,
	      lower_case(list[i])[0..0], lower_case(list[i])) )) {
	    _sender = ({ });
	    _subject = ({ });
	    _cc = ({ });
	    _message = ({ });
	    _time = ({ });
	}

	_sender += ({ capitalize(name) });
	_subject += ({ subj });
	_cc += ({ cc });
	_message += ({ mess });
	_time += ({ time() });
	_new_mail = 1;
	save_object(sprintf("%s%s/%s",_MAIL_PATH,
	    lower_case(list[i])[0..0], lower_case(list[i])));
    }
}

//
// This is to be called by player.c at login to determine if
// the player has any mail.  Returns the number of messages.
//
mixed
query_mail(mixed who, status silent)
{
    string tmp;
    int num;
    if (!who || ( stringp(who) && !_PREVIOUS_OBJ((PLAYER_FILE)[1..<1]+"#%s") ))
	return 0;

    if ( objectp(who)) tmp = (string)who->query_real_name();
    if ( stringp(who)) tmp = who;

    if (!restore_object(sprintf("%s%s/%s",_MAIL_PATH, tmp[0..0], tmp))
      || !num=sizeof(_sender)) return 0;
    if (silent) return num;
    return sprintf( "\nThere is%s mail for you in your mailbox.\n",
      (_new_mail) ? " NEW" : "" );
}

//
// Return a mapping containing message <num>, or 0 if
// message <num> does not exist.
//
mixed
query_info( mixed num, mixed who )
{
    string tmp;
    mapping temp;
    if ( !who || !_PREVIOUS_OBJ((GENERIC_MAILBOX)[1..<1]+"#%s")
      && ( stringp(who) && !_PREVIOUS_OBJ((LOGIN_OB)[1..<1]+"#%s") ))
	return RET_ERROR;
    load_player(who);
    if ( !sizeof(_sender)) return "There is no mail in your box.";
    if ( stringp(num) ) switch(num)
    {
    case "next" : num = _last_read + 1; break;
    case "prev" :
    case "previous" : num = _last_read - 1; break;
    default: num = 0;
    }
    if ( !intp(num) ) return 0;
    if ( num>sizeof(_sender) || num < 1)
	return sprintf("Illegal message number: %d", num);
    _last_read = num;
    tmp=(objectp(who)) ? (string)who->query_real_name() : who;
    save_object(sprintf("%s%s/%s",_MAIL_PATH,tmp[0..0],tmp));
    num--;
    temp = ([   INFO_MAIL_SENDER  : _sender[num],
      INFO_MAIL_SUBJECT : _subject[num],
      INFO_MAIL_CC      : _cc[num],
      INFO_MAIL_MESSAGE : _message[num],
      INFO_MAIL_TIME    :  _time[num] ]);
return temp;
}



//
// Check that we are allowed to send mail to this name.
// Apparently, without this it might be possible to modify
// other files.
// Returns a "clean" name, or 0.
//
nomask string
query_valid_name(string str)
{
    int i,j;
    if (!str || str == "") return 0;
    sscanf(str, "%t%s", str);       // Let's remove leading white spaces,
    // -+ Doomdark 22-jul-96 +-
    if (str == "" || sizeof(explode(str," ")) != 1) return 0;

    j = i = sizeof(str)-1;
    while ( str[j] == ' ' ) j--;    // find last non-space char
    if (j != i)
	str = capitalize(str[0..j]);
    else
	str = capitalize(str);

    if ( str == "Guest" ) return 0;
    for ( i=0; i<sizeof(_ILLEGAL_CHARS); i++ )
	if ( strstr(str,_ILLEGAL_CHARS[i]) != -1 ) return 0;
    if ( !member( _GROUPS,str ) && !MASTER_OB->exists_player(str)) return 0;
    return str;
}
