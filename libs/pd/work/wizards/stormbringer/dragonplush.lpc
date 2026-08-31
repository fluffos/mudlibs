#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("dragon plushie");
  set_short("dragon plushie");
  set_long("This dragon plushie keeps changing color."
           " He appears to be an impressive combination"
           " of red, blue, white, and black. Maybe you"
           " should <poke> him.");
  set_id(({ "plushie", "dragon plushie", "dragon" }));
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
  if(str != "plushie" && str != "dragon plushie" && str != "dragon")
    return 0;

  write("You poke the dragon plushie.");
  say(this_player()->query_cap_name()+" pokes the dragon plushie.");

  str = "%^CYAN%^The dragon plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "I want to be a black dragon!!!!";
  else if(numb == 1)

    str += "Look I am a Red Dragon!";
  else

    str = "%^BOLD%^BLUE%^The dragon plushie turns blue!%^RESET%^";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("%^BOLD%^BLUE%^The dragon plushie turns blue and grins at "+this_player()->query_cap_name()+"!%^RESET%^");

  return 1;
}

int query_auto_load() { return 1; }
