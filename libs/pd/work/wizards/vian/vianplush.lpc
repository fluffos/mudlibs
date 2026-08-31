#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_name("Vian plushie");
  set_short("a %^MAGENTA%^%^BOLD%^velvet %^RESET%^plushie of Vian");
  set_long("This Vian plushie is made of a very nice %^BOLD%^%^MAGENTA%^purple%^RESET%^ velvet.  It resembles a tall human holding an apple.  Perhaps you should <smack> it.");
  set_id(({ "plushie", "vian plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("smack", "smack");

}

int smack(string str) {
  object tp = this_player();
  string mymsg, roommsg, allmsg;
  int x;

  if (!str || present(str, tp) != this_object())
    return notify_fail("Smack what?\n");

  mymsg = "You smack the small Vian plushie.\n";
  roommsg = tp->query_cap_name()+" smacks "+tp->query_possessive()+
            " small Vian plushie.\n";
allmsg = "%^BOLD%^%^BLUE%^Vian plushie says: %^RESET%^";

  switch (random(3)) {

    case 0:
      allmsg += "I'm not Cenn, I promise...";
    break;

    case 1:
      allmsg += "I'm sorry that you died in my area.";
    break;

    case 2:
      allmsg = "The plushie starts to vibrate and a disgusting odor "
               "escapes from it!";
      // or:
      // allmsg = "";
      // mymsg += "The plushie starts to vibrate and sprays a disgusting odor on you!";
      // roommsg += "The plushie starts to vibrate and sprays a disgusting odor on "+
      //            tp->query_cap_name()+"!";
    break;

  }

  message("my_action", mymsg, tp);
  message("other_action", roommsg, environment(tp), tp);
  if (sizeof(allmsg))
    message("action", allmsg, environment(tp));

  return 1;
}

/*
int smack(string str) {
  int numb;

  if(!str)
    return 0;
  if(str != "plushie" && str != "vian plushie")
    return 0;

  write("You smack the small Vian plushie.");
  say(this_player()->query_cap_name()+" smacks their
"+possessive(this_player())+" 
Vian plushie.");

  str = "%^BOLD%^%^BLUE%^Vian plushie says: %^RESET%^";
  numb = random(3);
  if(numb == 0)
    str += "I'm not Cenn, I promise...";
  else if(numb == 1)

    str += "I'm sorry that you died in my area.";
  else

    str = "The Vian plushie starts to vibrate, and a disgusting odor escapes from it.";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("The Vian plushie seems to vibrate and sprays an odor on 
"+this_player()->query_cap_name()+"!");

  return 1;
}
*/

int query_auto_load() { return 1; }
