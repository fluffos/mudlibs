// mudlib: Basis
// file:   emotion.c
// author: Truilkan
// Hacked to work by Shadowhawk
/*
  $Locker:  $

  $Source: /usr/local/mud/libs/basis/bin/maker/admin/RCS/edemote.c,v $
  $Revision: 1.5 $
  $Author: garnett $
  $Date: 92/09/30 08:21:55 $
  $State: Exp $

  $Log:   edemote.c,v $
 * Revision 1.5  92/09/30  08:21:55  garnett
 * lots
 * 
 * Revision 1.4  92/09/30  05:03:21  garnett
 * added back add_temote().  the e_target field is now optional for
 * targeted emotes (but you must use /t on the verb if you leave out
 * the target field.  the value of the others field is used for the
 * target field if target field is empty.  if you really want an empty
 * target field then give it a value of "*empty".
 * 
 * Revision 1.3  92/09/28  22:01:33  garnett
 * fixed the /t business yet again (made /t unnecessary if targeted
 * version is only one by that name).
 * 
 * Revision 1.2  92/09/28  21:27:55  garnett
 * fixed so that 'edemote verb/t' works correctly
 * 
 * Revision 1.1  92/09/27  23:20:38  garnett
 * Initial revision
 * 
 * Revision 1.2  92/09/27  21:43:45  garnett
 * corrected file to use this_player and not this_object
 * 
 * Revision 1.1  92/09/27  21:23:25  garnett
 * Initial revision
 * 
 * Revision 1.6  92/09/26  15:18:51  yorkjoe
 * Added check for EOF during processing.
 * Cleaned up some resiudual errors.
 * 
 * Revision 1.5  92/09/26  14:53:12  yorkjoe
 * Removed add_temote since it's not used any more.
 * 
 * Revision 1.4  92/09/26  14:40:07  yorkjoe
 * Fixed processing of entered file.
 * 
 * Revision 1.3  92/09/25  21:51:52  yorkjoe
 * Added prototype for file to prevent error.
 * 
 * Revision 1.2  92/09/25  21:50:18  yorkjoe
 * Added RCS header.
 * 
*/

#include <config.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON ;

string file();

int
cmd_edemote(string arg)
{
   string emotion;
   int temote, x;
   mixed val;
   string filename, verb, *fields;

   if (!arg) {
      notify_fail("usage: edemote emote_name\n");
      return 0;
   }
   if (sscanf(arg, "%*s %*s") > 1) {
      write("Verbs cannot have spaces in them.\n");
      return 1;
   }
   filename = file();
   if (temote = sscanf(arg, "%s/t", verb)) {
      emotion = (string)EMOTE_D->query_temote(verb);
   } else {
      verb = arg;
      emotion = (string)EMOTE_D->query_emote(verb);
   }
   if (emotion) {
      write("Editing existing entry.\n");
      write_file(filename, emotion);
   } else {
      write("Editing a new entry.\n");
   }
   this_player()->edit(filename, "get_soul", this_object(), ({verb, temote}));
   return 1;
}

string
file()
{
   return temp_file("emotion", this_player());
}

void
get_soul(mixed *info)
{
   string body;
   string filename;

   filename = file();
   body = read_file(filename);
   rm(filename);
   if (info[1]) {
      EMOTE_D->add_temote(info[0], body);
   } else {
      EMOTE_D->add_emote(info[0], body);
   }
}

int help() {
	write ("Usage: edemote <argument>\n"+
"The edemote command allows you to create new soul commands, or to alter\n"+
"existing ones. It will place you into a text editor which will permit\n"+
"you to change the text of the entry for the soul command <argument>.\n"+
"You can type \"help soul\" to learn about the format for soul command\n"+
"entries.\n"+
"\nSee also: semote, temote.\n") ;
	return 1 ;
}
