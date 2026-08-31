#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle36");
     set_short("The Purgatory Castle");
     set_long("%^CYAN%^Crawling through the hole, a large cavernous space suddenly "
"%^CYAN%^opens up from the hole. Inside all there is to be seen is a "
"%^CYAN%^small chest that appears to be open.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
        "no lockpick" : 1,
]));
 set_exits( (["out" : ROOMS"castle13"]) );

    set_items( ([
        "chest" : "A strange looking thing, glittering can be seen inside..."]) );


}
void reset() {
 ::reset();
  if (!present("chest", this_object()))
    new(ITEMS"chest" )->move(this_object());
}
