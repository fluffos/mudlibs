#include <std.h>
inherit ROOM;
void create() {
    ::create();
   new("/wizards/whit/house/house")->move(this_object());
    set_name("TEST");
    set_long("This is a test building that Whit keeps all of his pets in.  It looks a "
      "little crowded in here and im sure Whit wouldnt mind you clearing this out "
      "a little bit.");
    set_properties(([
	"light":2, "night light":2, "indoors":1,
      ]));
}
void reset() {
    ::reset();
    if(!present("monster")) {
	new("/wizards/whit/test/mon1")->move(this_object());
	new("/wizards/whit/test/mon1")->move(this_object());
	new("/wizards/whit/test/mon1")->move(this_object());
	new("/wizards/whit/test/mon1")->move(this_object());
	new("/wizards/whit/test/mon1")->move(this_object());
	new("/wizards/whit/test/mon1")->move(this_object());
    }
}
