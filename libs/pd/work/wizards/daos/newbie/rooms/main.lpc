#include <std.h>
#include <newbiequest.h>
#include <common_fun.h>
#include <daemons.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1,
	"no bump" : 1, "no steal" : 1, "no teleport" : 1]));
    set_short("main room");
    set_long("Filler text");


}

void init() {
    object tp = this_player();
    object ob = new(MOB"parent");
    ::init();
    DELAY_D->add_delay(3, ob, "do_intro", tp, 0);
    if (!present("parent")) {
	if (QG == "male") { ob->set_gender("female"); }
	else ob->set_gender("male");
    }	
}

void do_intro() {
    object ob = new(MOB"parent");
    message("info", "Welcome to Primal Darkness! Please allow me to be your "
      "guide.  In a few moments, you are going to end up in a small house where a "
      "parent figure will appear and instruct you on the basic things you need to "
      "know in order to start your adventure.", TP);
    ob->move(this_object());
}

