#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("Large Wiz Plushie");
  set("id",({"plushie","plush doll"}));
  set("short","Wiz Plushie");
  set("long","The Wiz plushie looks remarkably like Harry Potter.. complete with a Primal Darkness house scarf and cape. there is a small pullstring on his back, maybe you should <pull> it.");
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("pull","pull");
}

int pull(string str) {
  object ob;

  if(str != "plushie")
    return 0;

  write("You pull the string on your Wiz plushie.. a strange whirring sound emits.%^BOLD%^%^BLUE%^ The plushie flies around the room in a superhero pose!!%^RESET%^ ");

  say(this_player()->query_cap_name()+" pulls a string on their Wiz plushie...a whirring sound fills the room.%^BOLD%^%^BLUE%^The plushie suddenly leaps into the air and flies around the room in a superhero pose!! %^RESET%^");
  
  write("%^CYAN%^Wiz plushie says:%^RESET%^That was so leetice!!!");

  say("%^CYAN%^Wiz plushie says:%^RESET%^That was so leetice!!!");

  return 1;
}

int query_auto_load() { return 1; }
