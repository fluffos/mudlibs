#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("azire plushie");
  set_short("a cute Azire plushie");
  set_long("This plushie of Azire smiles at you with her big blue"
           " eyes.  The plushie is white and fuzzy, and incredibly"
           " soft and huggable.  It's almost impossible to resist"
           " giving it a <hug>.");
  set_id(({ "plushie", "azire plushie" }));
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
  if(str != "plushie" && str != "azire plushie")
    return 0;

  write("You give the Azire plushie an affectionate squeeze.");
  say(this_player()->query_cap_name()+" gives "+possessive(this_player())+"
Azire plushie an affectionate squeeze.");

  str = "%^CYAN%^Azire plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "Awww..  thanks for the hug!";
  else if(numb == 1)
    str += "^_^";
  else

    str = "Azire plushy licks you.";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("Azire plushy licks "+this_player()->query_cap_name()+".");

  return 1;
}

int query_auto_load() { return 1; }
