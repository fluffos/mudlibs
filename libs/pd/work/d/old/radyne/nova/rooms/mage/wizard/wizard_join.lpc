#include <std.h>
#include <radyne.h>
#include <daemons.h>

#define CLASS     "mage"
#define SUBCLASS  "wizard"
#define ALIGNMENT 2000

inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_down","west");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no bump", 1);
    set("short", "The Wizard hall");
    set("long",
        "Dull blue, red and yellow fabrics compose this room.  They represent "
        "the many paths that a Wizard follows. "  
        "<preview> will tell you about becoming a wizard.");
    set_items(
        (["fabrics" : "The fabrics are hung all over the room like banners and walls alike.",
          "colours" : "The colours represent the different paths of the wizard."]) );
    set_exits( 
         (["south" : ROOMS"ewayward5",
           "west" : "(: west :)"]) );
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
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about wizards.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Wizards are skilled in all the paths of magic, attempting to attain "
          "more of a balance between types than an edge in just one. Type <become wizard> "
          "to become a wizard.",
this_player());
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

    write("The elder wizard initiates you into the path of the wizard.");
    say(this_player()->query_cap_name()+" becomes a wizard.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start","/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_down() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "sorceror's inner sanctum, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the light in the passage");
    return 1;
}
