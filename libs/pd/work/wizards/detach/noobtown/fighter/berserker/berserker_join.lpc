#include <std.h>
#include <radyne.h>
#include <daemons.h>

#define CLASS     "fighter"
#define SUBCLASS  "berserker"
#define ALIGNMENT 500

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
    set("short", "Entrance to the Berserker hall");
    set("long", "This is the hall that berserkers come to hang out and "
                "train. The area is a total mess with empty bottles "
                "of alcohol. There are several holes in the wall like "
                "they were punched through. You may <preview> them if "
                "this way of life interests you.");
    set_items(
        (["door" : "The door is closed." ]) );
    set_exits( 
         (["west" : "/d/standard/outlands/brig_pub",
           "east" : "(: down :)"]) );
}
int preview() {
 if (this_player()->query_class() != "fighter" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn
about berserkers.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Berserkers specalize in hand to hand combat. They "
                    "are out of all the fighters the craziest. They drink "
                    "heavily before they fight.\n"
                    " You may become one by typing <become berserker>.",
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
    if((string)this_player()->query_class() != "fighter") {
        write("You must choose the path of Fighter first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");

    write("The Grand Drunkard initiates you into the life path of the
berserker.");
    say(this_player()->query_cap_name()+" becomes a berserker.",
this_player());
// CHAT_D->do_raw_chat("fighter", ""+this_player()->query_cap_name()+" has become a %^RED%^berserker.%^RESET%^");
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
if(wizardp(this_player())) {
write("Your wizardlyness has allowed you to enter.");
this_player()->move_player("/d/tirun/fighter/berserker/berserker_hall");
return 1;
}

        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "berserker hall, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the door");
    return 1;
}
