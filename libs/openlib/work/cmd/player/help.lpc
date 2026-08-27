// help.c: help command. 'k' flag is search by keyword, 'w' forces to search
//         for wiz commands only
// Written by Tim McIntosh late at night on 1/22/96
//
#include <cmdline.h>
#include <daemons.h>

#define USAGE "usage: help [-k] [-w] <command or keyword>\n" \
              "       help -t [-w] <topic>\n"

#define WIZARD_HELP_DIR "/doc/help/wizard"
#define PLAYER_HELP_DIR "/doc/help/player"

#define FMT \
"--------------------------------------------------------------------------\n"\
"%-10.10s - %-42.42s   %16.16s\n"\
"--------------------------------------------------------------------------\n"\
"\n%%s\n"\
"--------------------------------------------------------------------------\n"

#define FMT2 \
"--------------------------------------------------------------------------\n"\
"%-55.55s   %16.16s\n"\
"--------------------------------------------------------------------------\n"\
"\n%%s\n"\
"--------------------------------------------------------------------------\n"

int
main(string* argv, string* argv2)
{
  int optw = flag("w"), optk = flag("k"), optt = flag("t");
  string header, helptext, str;
  object ob;

// Can't use both these options at same time
  if(optt && optk)
    return notify_fail(USAGE);

// Topic (if given)
  if(sizeof(argv2))
    str = argv2[0];

  // wizard check
  if(optw && !wizardp(this_player()))
    optw = 0;

  if(!str) {
    if(optw) {
      str = "Wizard Help";
      helptext = read_file(WIZARD_HELP_DIR "/General");
    } else {
      str = "Player Help";
      helptext = read_file(PLAYER_HELP_DIR "/General");
    }

    header = sprintf(FMT2, str, "(General Help)");

  } else if(optt) {               /* get help on topic */
    if(optw) {
      if(file_exists(WIZARD_HELP_DIR "/" + str))
	helptext = read_file(WIZARD_HELP_DIR "/" + str);
    } else {
      if(file_exists(PLAYER_HELP_DIR "/" + str))
	helptext = read_file(PLAYER_HELP_DIR "/" + str);
    }

    header = sprintf(FMT2, capitalize(str), "(Topic Help)");
    
  } else if(!optk) {              /* get help for command using CMD_D */
    ob = (object) CMD_D->find_cmd(str);

    if(ob) {
      header = sprintf(FMT, str, (string) ob->help_desc(), "(Command Help)");
      helptext = (string) ob->help();
    }

  } else {                        /* Keyword Search using CMD_D */

    /* MORE TO DO HERE */

  }

  if(helptext) {
    helptext = sprintf(header, helptext);
    this_player()->more(explode(helptext, "\n"));
  } else {
    write("No help found.\n");
  }

  return 1;
}

string help_desc() { return "gives help on commands and topics"; }

string
help()
{
  return @ENDHELP
To get help on a command type 'help <commandname>'.  To get help on a
topic, type 'help -t <topic name>'.  To do a keyword search of commands
type 'help -k <keyword>'.  If you are a wizard and need wizard help files
use the -w flag.  The -t and -k flags cannot be used simultaneously.

See also: man
ENDHELP;
}
