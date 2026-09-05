#include "/players/boltar/things/esc.h"
#define EXLV "/room/exlv_guild"

status
cmd_xtitle(string str)
{
    int x, s;
    int xp22, xp50;
    string *words;
    x = (int) this_player()->query_extra_level();
    if( (int) this_player()->query_prestige_level() )
      x = 100;

    if(x  < 22) {
      xp22 = (int) EXLV->check_level( 22 );
      xp50 = (int) EXLV->check_level( 50 );
      if( this_player()->query_exp() >= xp50 )
        x = 50;
      else if( this_player()->query_exp() >= xp22 )
        x = 22;
      else
        return 0;
    }

    if(!str)
    {
      notify_fail("\
Set your title to what?\n\
Type 'help xtitle' for help.\n");
      return 0;
    }

    if(x >= 50)
    {
      words = explode(str, "$");
      s = sizeof(words);

      while(s --)
        if(this_player()->replace_ansi(words[s]))
          words[s] = (string)this_player()->replace_ansi(words[s]);

      str = (implode(words, "")) + esc + "[0m";
    }

    write("You set your title to " + str + ".\n");
    this_player()->set_title(str);

    return 1;
}
