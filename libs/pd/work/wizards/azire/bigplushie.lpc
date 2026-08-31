#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("Large Azire Plushie");
  set("id",({"plushie","plush doll"}));
  set("short","Azire Plushie");
  set("long","The Azire plushie is cute and cuddly. It has wide blue eyes that sparkle, and soft white furred wings.  It looks like it wants a  <hug>.");
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

  write("You squeeze the Azire plushie. It is amazingly soft, and you feel comforted by its presence.");

  say(this_player()->query_cap_name()+" squeezes their Azire plushie.");
  
  write("Azire plushie says: Rawr!");

  say("Azire plushie says: Rawr!");

  return 1;
}
