// Note: May 29, 8:00 pm
// Hacked by Stormbringer
#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
   ::create();
   set_property("light", 1);
   set("short", "Grove of remembrance");
   set_long(
      "You are in an old, dark cemetary. Only in this small grove "
      "does the light of hope shine. It is here that adventurer and "
      "god alike come to remember the dearly lost. Those few good "
      "souls that leave into eternal bliss are remembered here in "
      "this place of rest. A weeping willow hangs over the monument "
      "which has been put up by Inferno. Surrounding the monument "
      "are many different blossoms, from roses to pink lady slippers. "
      "A beam of light shines down upon the monument.");
   set_items(([
        "cemetary" : "All about you stretch the silent graves. "
          "A sadness overcomes you.",
        "grave" : "The grave of a thousand good souls.",
        "blossoms" : "The flowers bloom eternally, a remembrace to hope.",
        "writing" : "Here rest the souls of a thousand good souls. "
                    "May they forever rest in peace and bliss.",
        ({ "weeping willow", "willow", "tree", "weeping willow tree" }) :
                    "It hangs down over the monument and the graves.",
        "flowers" : "The rarest of blossoms lay here.",
        ({ "beam", "light" }) : "A single beam of light shines upon the grave.",
        "plaque" : "The plaque is of platinum and writing has "
                   "been inscribed in gold."]) );
   set_exits(([
"west" : "/d/nopk/standard/cemetary/gravyar5",
"enter" : "/d/nopk/standard/cemetary/building"]));
}
void reset() {
  ::reset();
    if (!present("monument"))
new("/d/nopk/standard/cemetary/mon/monument")->move(this_object());
}
void init() {
  ::init();
    add_action("read","read");
}
int read(string str) {
  if(str == "writing" || str == "plaque") {
    write (::query_long("writing"));
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}
