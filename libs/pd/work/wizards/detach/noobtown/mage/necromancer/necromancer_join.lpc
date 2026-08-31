#include <std.h>
#include <radyne.h>
#include <daemons.h>

#define CLASS     "mage"
#define SUBCLASS  "necromancer"
#define ALIGNMENT 0

inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_down","east");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no bump", 1);
    set("short", "The fire of the Pyromancers");
    set("long",
     "Down the stairs into the depths of the fetid, moist soil of "
     "the cemetary. It is a fairly large chamber with bones and skulls "
     "placed carefully into the fallow walls. There are a few dim "
     "torches and roots projecting from the earthen walls.\n"
     "There is a %^BLUE%^blue%^RESET%^ light protecting the path to the east. "
     "This is a place where the necromancers come to "
     "hone thier vile arts.\nYou can <preview> the powers of the necromancers here."
   );
   set_smell("default","The smell of rotting flesh lingers in the air.");
    set_items(
        ([
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads north into the necromancer's inner sanctum."]) );
    set_exits( 
     ([
     "up" : "/d/standard/cemetary/gravyar8",
           "east" : "(: down :)"]) );
}
int preview() {
 if (this_player()->query_class() != "mage" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the talent to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about necromancers.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Necromancers are an evil brethren of mages that traffick in death "
        "and evil.  Choosing to ply their magic to raise creatures from the dead "
        "necromancers are shunned by other mages.  Mastering the dark arts of "
        "magic means a necromancer is a unnafraid of death and wields many powers "
        "of destruction.  Type <become necromancer> to become a necromancer.", this_player());
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
    if((string)this_player()->query_class() != "mage") {
        write("You must choose the path of Mage first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");

    write("The wicked pyromancer initiates you into the path of the
necromancer.");
    say(this_player()->query_cap_name()+" becomes a necromancer.",
this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start",
"/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_down() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "necromancer's inner sanctum, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS,
                          "through the light in the passage");
    return 1;
}
