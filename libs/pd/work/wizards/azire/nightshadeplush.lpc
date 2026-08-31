#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("Large Nightshade Plushie");
  set("id",({"plushie","plush doll"}));
  set("short","Nightshade Plushie");
  set("long","The Nightshade plushie sparkles slightly. Intelligent eyes regard you with a life of their own.. But surely this is only a replica of him.. You feel compelled to gaze more closely. His charisma oozes towards you - maybe you should give him a <hug>.");
  set_weight(1);
  set_value(0);
}

void init() {
  ::init();
  add_action("hug","hug");
}

int hug(string str) {
  object ob;

  if(str != "plushie")
    return 0;

  write("You squeeze the Nightshade plushie. A tingle of immortal energy thrills through you as the plushie leaps to life for an instant.");

  say(this_player()->query_cap_name()+" is zapped with immortal power as they squeeze their Nightshade plushie!");
  
  write("%^CYAN%^Nightshade doll says:%^RESET%^ I'm going to downgrade "+this_player()->query_class()+"s next!");

  say("%^CYAN%^Nightshade doll says:%^RESET%^ I'm going to downgrade "+this_player()->query_class()+"s next!");

  return 1;
}

int query_auto_load() { return 1; }
