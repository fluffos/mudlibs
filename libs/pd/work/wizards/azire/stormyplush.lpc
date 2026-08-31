#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("Stormbringer plushie");
  set_short("Stormbringer plushie");
  set_long("This Stormbringer plushie is all powerful."
           " He appears to be an impressive combination"
           " of dragon and immortal. He holds a shimmering"
           " bolt of lightning aloft in his claw. Maybe"
	   " you should <poke> it.");
  set_id(({ "plushie", "stormbringer plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("poke", "poke");

}

int poke(string str) {
  int numb;

  if(!str)
    return 0;
  if(str != "plushie" && str != "stormbringer plushie")
    return 0;

  write("You poke the shimmering lightning bolt.");
  say(this_player()->query_cap_name()+" pokes the lightning bolt on "+possessive(this_player())+" 
Stormbringer plushie.");

  str = "%^CYAN%^Stormbringer plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "Hrm...";
  else if(numb == 1)

    str += "Dont touch what you dont understand.";
  else

    str = "%^BOLD%^RED%^Stormbringer plushie frowns and the skies darken overhead!%^RESET%^";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("%^BOLD%^RED%^Stormbringer plushie frowns and the skies darken over "+this_player()->query_cap_name()+"!%^RESET%^");

  return 1;
}

int query_auto_load() { return 1; }
