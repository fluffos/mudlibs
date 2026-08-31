#include <std.h>
#include <tirun.h>
#include <daemons.h>
#define CLASS     "wanderer"
#define SUBCLASS  "gypsy"
#define ALIGNMENT 0
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A gypsy's wagon");
    set("long",
      "All about is a mixture of color and the glimmer of metals.  On the floor are " 
      "trunks and crates stacked randomly, some belching out colorful "
      "scarves and feathery bits of garment. From every bit of rafter space hangs "
      "baubles and trinkets of various sizes, most offer a tinkle or rattle to the "
      "sway of the wagon. A small doorway leads east. "
      "<preview> to find out more about becoming a gypsy.");
    set_items(
      ([
	"light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
	"passage" : "It leads down into the gypsy's inner sanctum."]) );
    set_exits( 
      (["out" : "/d/nopk/forest/tiruneastforest/rooms/tiruneastforest3",
	"east" : ROOMS+"wand/"+SUBCLASS+"/"+SUBCLASS+"_hall"]) );
    add_pre_exit_function("east", "go_enter");
}
int preview() {
    if (this_player()->query_class() != "wanderer" ||
      this_player()->query_subclass() != "none")  {
	message("info", "You have not the training to join.", this_player());
	return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
	message("info", "You are already one of the singers.", this_player());
	return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about gypsies.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Gypsies are people of lore, song, and free spirit. Travelling the realms "
      "spreading their lore as they go. Using fortune, they give help "
      "where needed and get donations for their pay. "
      "Type <become gypsy> to become a gypsy.", this_player());
    return 1;
}
int become(string str) {
    if(!str) {
	notify_fail("Become what?\n");
	return 0;
    }
    if(str != SUBCLASS) {
	notify_fail("You cannot become that here.\n");
	return 0;
    }
    if((string)this_player()->query_class() != "wanderer") {
	write("You must choose the path of Wanderer first.");
	return 1;
    }
    if (this_player()->query_subclass()!="none")
	return notify_fail("You have already chosen your path in life!");
    write("The Grand Gypsy initiates you into the life path of the gypsy.");
    say(this_player()->query_cap_name()+" becomes a gypsy.", this_player());
    // CHAT_D->do_raw_chat("fighter", "%^WHITE%^"+this_player()->query_cap_name()+" has become a %^RED%^bard.%^RESET%^");
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
    this_player()->register_channels();
    return 1;
}
int go_enter() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != SUBCLASS) {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "gypsy's inner sanctum, but fails.", this_player());
	return 0;
    }
    return 1;
}
