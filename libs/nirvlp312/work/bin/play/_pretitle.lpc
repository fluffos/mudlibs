#include "/players/boltar/things/esc.h"
#define EXLV "/room/exlv_guild"

status
cmd_pretitle(string str)
{
    int x, s;
    int xp50;
    string *words;

   if ((string)this_player()->query_real_name() == "guest")
   {
      write("Guest cannot have a pretitle.\n"+
          "We're bastards about this.\n");
      return 1;
   }
   else if (str == "|")
   {
     this_player()->set_pretitle(0);
     write("O.K., cleared your pretitle.\n");
     return 1;
   }


   if( str ) 
     str = str[0..60];

    x = (int) this_player()->query_extra_level();
    if( (int) this_player()->query_prestige_level() )
      x = 100;

    if(x  < 50) {
      xp50 = (int) EXLV->check_level( 50 );
      if( this_player()->query_exp() >= xp50 )
        x = 50;
      else
        x = 0;
    }

  if(!str) {
    notify_fail("\
Set your pretitle to what?\n\
"+(x ? "Type 'help xtitle' for help.\n" : "\n"));
     return 0;
   }

    words = explode(str, "$");
    s = sizeof(words);

    while(s --)
      if(this_player()->replace_ansi(words[s]))
        words[s] = (string)this_player()->replace_ansi(words[s]);

    str = (implode(words, "")) + esc + "[0m";

    if( x < 50 )
      str = remove_color( str );

    this_player()->set_pretitle(str);
    write("O.K., you are now:\n\n"+
      (string)this_player()->short()+"\n");

    return 1;
}
