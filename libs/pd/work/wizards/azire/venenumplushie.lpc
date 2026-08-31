#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("venenum plushie");
  set_short("a darling Venenum plushie");
  set_long("This plushie of Venenum is rather large. "
           " His tail wraps around your wrist as you hold him, and"
           " little red wings flap in the air. His eyes twinkle with merriment."
           " You find it impossible to resist giving him a <hug>.");
  set_id(({ "plushie", "venenum plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("hug", "hug");

}

int hug(string str) {
  int numb;

  if(!str)
    return 0;
  if(str != "plushie" && str != "venenum plushie")
    return 0;

  write("You give the Venenum plushie a bear hug.");
  say(this_player()->query_cap_name()+" gives "+possessive(this_player())+"
Venenum plushie a bear hug.");

  str = "%^CYAN%^Venenum plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "Rrt? mrrrrrrrrrr...";
  else if(numb == 1)

    str += "hehehe! That tickles!";
  else

    str = "Venenum plushie licks you.";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("Venenum plushie  licks "+this_player()->query_cap_name()+".");

  return 1;
}

int query_auto_load() { return 1; }
