#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("Daos plushie");
  set_short("Daos plushie");
  set_long("Daos plushie beams brightly at you."
           " He carries a laptop under one arm"
           " and hoists aloft a PD banner in his right hand."
           " There is a button on his right sleeve cuff,"
	   " maybe you should <use> it.");
  set_id(({ "plushie", "daos plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("use", "use");

}

int use(string str) {
  int numb;

  if(!str)
    return 0;
  if(str != "plushie" && str != "daos plushie")
    return 0;

  write("You use the button on Daos plushie's sleeve.");
  say(this_player()->query_cap_name()+" presses a button on "+possessive(this_player())+" 
Daos plushie.");

  str = "%^CYAN%^Daos plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "That is not a toy.";
  else if(numb == 1)

    str += "I could beat you at paintball any day.";
  else

    str = "%^BOLD%^YELLOW%^Daos plushie waves his PD banner proudly.%^RESET%^";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("%^BOLD%^YELLOW%^Daos plushie wave his brightly colored PD banner above "+this_player()->query_cap_name()+".%^RESET%^");

  return 1;
}

int query_auto_load() { return 1; }
