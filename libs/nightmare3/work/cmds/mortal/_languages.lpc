//  /bin/user/_languages.c
//  written by Valodin, August 12, 1993


#include <std.h>
#define OLD_LANGUAGES ({ "elvish", "giantish", "orcish", "artrellian", "mischief", "sensuous", "hobbitish", "pseudo-speak", "gnomish" })


inherit DAEMON;

int cmd_languages(string str)
{
  string *langs;
  int i , lsz, prof, flag;

  flag = 0;
  langs = this_player()->query_all_languages();
  if((lsz = sizeof(langs)) == 0)
  {
    write("You need to visit the sage and ask him to fix you.");
    return 1;
  }
  write("Your primary language is " + 
	capitalize((string)this_player()->query_primary_lang()) + ".");

// This is to prevent a crasher in v20.21.  Remove when fixed
// - Beek
    
  write("The rest of the languages command is temporarily disabled.");
  return 1;

  for(i = 0; i < lsz; i++)
  {
    prof = this_player()->query_lang_prof(langs[i]);
    if(member_array(langs[i], OLD_LANGUAGES) != -1)
      flag = 1;
    switch(prof)
      {
      case 0:
	break;
      case 1:
      case 2:
      case 3:
      case 4:
	write("You are just beginning to learn " + capitalize(langs[i]) + ".");
	break;
      case 5:
      case 6:
      case 7:
	write("You are moderately skilled at " + capitalize(langs[i]) + ".");
	break;
      case 8:
      case 9:
	write("You are very skilled at " + capitalize(langs[i]) + ".");
	break;
      case 10:
	write("You are fluent in " + capitalize(langs[i]) + ".");
      }
  }
  if(flag)
    write("You need to go visit the sage and ask him to fix your "
	  "languages.");
  return 1;
}

int help()
{
  message("help", "Command: languages\n"
	  "Syntax: languages\n\n"
	  "This command tells you all the languages you can speak.  If you "
	  "have problems with languages, you should visit the sage and ask "
	  "him to fix you.  If you are skilled in one of these languages you "
	  "should also visit the sage and have him fix you:\n"
	  "  elvish, giantish, orcish, artellian, mischief, sensuous,\n"
	  "  hobbitish, pseudo-speak, or gnomish", this_player());
  message("help", "\nSee also: tongues, speak, shout", this_player());
  return 1;
}
