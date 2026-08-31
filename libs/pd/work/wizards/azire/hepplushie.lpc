#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("Hepualahaole plushie");
  set_short("Hepualahaole plushie");
  set_long("This plushie of Hepualahaole is blacker than night. "
           " Her electric blue eyes pierce you to your core as you"
           " look at her. Each detail is perfectly shown, down to the"
           " smallest scale. Her tail coils posessively around your wrist."
	   " One scale on her back seems a bit out of place. Maybe you"
	   " should <press> it.");
  set_id(({ "plushie", "hepualahaole plushie" }));
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("press", "press");

}

int press(string str) {
  int numb;

  if(!str)
    return 0;
  if(str != "plushie" && str != "hepualahaole plushie")
    return 0;

  write("You press the scale between Hepualahaole's wings.");
  say(this_player()->query_cap_name()+" presses a button on "+possessive(this_player())+" 
Hepualahaole plushie.");

  str = "%^CYAN%^Hepualahaole plushie says:%^RESET%^ ";
  numb = random(3);
  if(numb == 0)
    str += "Touch me again and I'll bite off your finger.";
  else if(numb == 1)

    str += "Dont tick off a black dragoness...";
  else

    str = "Hepualahaole plushie crackles with %^BOLD%^YELLOW%^electricity%^RESET%^ and zaps you with her lightning breath!";

  write(str);
  if(numb != 2)
    say(str);
  else
    say("Hepualahaole plushie%^BOLD%^YELLOW%^ ZAPS%^RESET%^ "+this_player()->query_cap_name()+" with a bolt of lightning from her maw!");

  return 1;
}

int query_auto_load() { return 1; }
