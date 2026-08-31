#include <std.h>
#include <daemons.h>

inherit DAEMON;

int my_cmd_say(string);

string* mixColors = ({ "%^RED%^", "%^BOLD%^%^BLACK%^" });

int cmd_colorsay(string str) {
  string line;
  line = "%^RESET%^%^RED%^<%^BOLD%^<%^RESET%^ ";
  for(int i = 0; i < sizeof(str); i++) {
    if(random(1000) < 350 || i == 0)
      line += "%^RESET%^"+  mixColors[random(sizeof(mixColors))];
    line += str[i..i]; //because str[i] doesn't work
  }
  line += " %^BOLD%^%^RED%^>%^RESET%^%^RED%^>";
  my_cmd_say(line);
  return 1;
}

int my_cmd_say(string str) {
  object *ob, *ignoring;
  string type;
  int i;

    if(!str || str == "") {
        notify_fail("You mutter to yourself.\n");
        return 0;
    }
    if(str[sizeof(str)-1] == '!')
        type = "exclaims";
    else if(str[sizeof(str)-1] == '?')
        type = "asks";
    else
        type = "says";
    str = CENSOR_D->censor(this_player(), "say", str);

    LAST_D->add_say(this_player()->query_name(),  "%^CYAN%^You "+type[0..(sizeof(type)-2)]+":%^RESET%^ "+str);

    ob = all_inventory(environment(this_player()));
    i = sizeof(ob);
    ignoring = ({});
    while(i--)
     {
     if (ob[i]!= this_player() ) {
      if(ob[i]->query_ignoring(this_player()->query_name()))
        ignoring += ({ob[i]});
      else
        LAST_D->add_say(ob[i]->query_name(), ""+ (string)previous_object()->query_cap_name()+""+type+": "+str);
       }
     }

    ignoring += ({ this_player() });

    message("say", "%^CYAN%^You "+type[0..(sizeof(type)-2)]+":%^RESET%^ "+str+"", this_player());

    message("say", "%^CYAN%^" + (string)previous_object()->query_cap_name()+" "+type+":%^RESET%^ "+str+"", environment(this_player()), ignoring);

    return 1;
}
