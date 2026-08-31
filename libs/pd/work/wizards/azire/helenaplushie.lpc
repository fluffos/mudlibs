#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("helena plushie");
  set_short("a cute Helena plushie");
  set_long("This gorgeous plushie looks at you with her luminous"
           " eyes.  She has a long white robe and golden sash - she"
           " even has a pair of snow white wings! Her halo hangs in"
           " the air glowing softly. You can't help it, you want to <snuggle>
her.");
  set_id(({ "plushie", "helena plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("snuggle", "snuggle");

}

int snuggle(string str) {
  int numb;

  if(!str)
    return 0;
  if(str != "plushie" && str != "helena plushie")
    return 0;

  write("You snuggle the Helena plushie fondly.");
  say(this_player()->query_cap_name()+" gives "+possessive(this_player())+"
Helena plushie an adorable snuggle.");

  str = "%^CYAN%^Helena plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "You're such a NOOB.";
  else if(numb == 1)
    str += "Muah!";

  else

    str = "Helena plushie flits around your head!";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("Helena plushie flits around "+this_player()->query_cap_name()+".");

  return 1;
}

int query_auto_load() { return 1; }
