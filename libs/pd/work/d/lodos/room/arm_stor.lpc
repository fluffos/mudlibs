#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
  ::create();
    set("short", "Anathar's Storage Room");
    set("long", "Storage room for the Lodos armoury.");
    set_exits( 
	      (["south" : "/d/standard/frealmz/armoury"]) );
    new(ARM"chainvest")->move(this_object());
    new(ARM"chainsleeves")->move(this_object());
    new(ARM"chainleggings")->move(this_object());
    new(ARM"chainhood")->move(this_object());
    new(ARM"chaingloves")->move(this_object());
    new(ARM"chainboots")->move(this_object());
}
