#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
   ::create();
   set_property("light", 1);
   set("short", "Forlock's grave");
   set("long",
      "You are in an old, dark cemetary. The eerie silence gets on your "
      "nerves.  At your feet is a new grave, dug in haste.  A few faded "
      "blossoms give mute, sad testimony to affections from the past. A "
      "small marble plaque lies to one side, not having been installed "
      "at the head of the grave yet.");
   set_items(
      (["cemetary" : "All about you stretch the silent graves. "
	  "You feel like you are being watched.",
	"grave" : "The grave is new and mounded with fresh dirt.",
	"blossoms" : "The flowers are wilted and faded. They look sad.",
	"writing" : "Here lies poor old Forlock. His last words were: "
	  "Help!! I'm getting line noiss..fjjjdk..%$fffs..*squawk*.."
	  "0w0w0w0w0w!!",
	"plaque" : "The plaque is of grey marble.  You might be able "
	  "to read the writing on it."]) );
   set_exits( 
             (["northwest" : ROOMS"cemetary/gravyar6",
               "west" : ROOMS+"cemetary/gravyar2",
               "east" : ROOMS+"cemetary/gravyar9",
               "southwest" : ROOMS+"cemetary/gravyar4"]) );
}
void reset() {
  ::reset();
    if (!present("ghost"))
      new(ROOMS+"cemetary/mon/ghost5")->move(this_object());
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

