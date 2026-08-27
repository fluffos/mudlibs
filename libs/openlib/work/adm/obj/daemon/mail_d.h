/*  -*- LPC -*-  */
// maild.h: header file for maild.c, mudlib mail daemon.
//          The mail daemon works in conjunction with a mail command and a
//          mailbox object.  The interface to both of these was designed
//          so you may easily write your own versions if you wish.  It
//          also uses a global editor to get text from the player.
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
//
// Written 12.10.95 by Tim (astasia@iastate.edu)
//
// 04.10.96  Tim@Dysfunctional Mud
//         o Bumped version to 1.3 in light of Intermud3 integration (almost)
// 08.30.96  Tim@Dysfunctional Mud
//         o Implemented I3 support; bumped version to 2.0 to reflect this.
// 09.03.96  Tim@Dysfunctional Mud
//         o Changed print_headers() and deletion strategy to reflect changes
//           to mailbox object.
//         o Changed to use more() when displaying things
//         o Added 'save' command, changed behavior of pressing <enter>
//         o Bumped version to 3.0 to reflect these changes.
// 09.20.96  Tim@Dysfunctional Mud
//         o Changed to use unguarded() when loading/saving mailboxes
//           to implement security.
//         o Bumped version to 3.1 to reflect changes.
//          

#include <mudlib.h>
#include <daemons.h>

// Major version number changes when new features are added; minor version
// number changes with bug fixes and implementation changes.
#define VERSION "3.1"

// Path to your mailbox object (UltraLib defines this in mudlib.h)
// #define MAILBOX "/adm/obj/clone/mailbox"

// This should be a string representing the home directory of object x
// with no trailing slash.  i.e. "/u/t/tim"
#define HOME_DIR(x) user_cwd(x->query_name())

// Define this if your mudlib doesn't already define RESOLVE_PATH()
// It should resolve a path with respect to this_player()'s cwd.
// #define RESOLVE_PATH(x) some_function(x)

// Define this to be the filename of the editor daemon to use when entering
// a message.  (UltraLib defines this in daemons.h)
// It should define a function as follows:
//
// varargs void edit(function call_back, string* input_buffer);
//
// where 'call_func' is the function which will be called after the text has
// been entered, with an array (the lines of entered text) as the last argument
// and any extra arguments should be included in the function pointer itself.
// If the edit failed, the buffer will be 0.
// #define EDITOR_D "/obj/clone/editor_d"

// Turn on/off debugging info
#undef DEBUG

/*
 * Function Prototypes
 * This returns the number of messages in user's mailbox.  If check_new==1
 * it returns the number of new messages in the box.
 */
varargs int check_mail(string user, int check_new);

/*
 * This starts the interactive mail reading loop
 */
void cmd_mail_loop(object mbox);

/*
 * This starts the interactive send-message dialog
 */
void cmd_send_mesg(string tolist, function call_func);

/*
 * This function distributes mail locally
 *
 * 'bcclist' is an array of usernames to send the message to blindly.
 *
 * 'tolist'  They should be mappings
 * 'cclist'  of the following format:
 *           ([ Mudname : ({ user-1, ... }), ... ])
 * 'time'    send time; an integer as returned by time()
 *
 * The rest is self explanatory.
 */
void send_mail(mapping to_list, mapping cc_list, string* bcc_list, string from,
	       int time, string subject, string content);

/*
 * Private Functions
 */

void print_message(object mbox, int curr, int count);
void print_headers(object mbox, int curr, int count);
void print_help(object mbox, int curr, int count);
void delete_message(object mbox, int count, int curr, string* args);
void save_message(object mbox, int curr, string* args);
void reenter_mail_loop(object mbox, int curr, int count);
void cmd_mail_loop2(string input, object mbox, int curr, int count);
void cmd_send_mesg2(string input, string tolist, function cf);
void cmd_send_mesg3(string* lines, string subject, string tolist, function cf);
void cmd_send_mesg4(string cclist, string tolist, string subject,
			    string content, function cf);
private mapping filter_remote_users(string* arr);
