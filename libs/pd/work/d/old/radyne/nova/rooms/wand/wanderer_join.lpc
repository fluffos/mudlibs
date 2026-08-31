#include <std.h>
#include <radyne.h>
inherit ROOM;
int go_north();
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_up","up");
    add_action("preview","preview");
}
void create() {
  ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Entrance of the Wanderer Hall");
    set("long", 
        "The Hall of Wanderers is decorated with ornate objects form all over "
        "the world.  The hall is mostly deserted, since wanderers like to be "
        "out having fun.  Young people visit here hoping to hear stories of "
        "the adventurous members.  Children may <preview> what it is like to be "
        "a wanderer.");
    set_items(([
        "hall" : "This is the single wanderer class hall.",
            ]));
   set_exits(
          (["south" : ROOMS"nwganthus1",
            "up" : "(: go_up :)" ]));
}
int preview() {
    if((string)this_player()->query_class() != "child") {
        write("This is not for you.");
        return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about wanderers.", this_player());
    write("Welcome, child!\n");
    write("Wanderers are those people who have chosen to spend the rest "
      "of their lives traveling and moving about. All wanderers have at least two "
      "things in common: their love of fun and pranks and their overwhelming "
      "wanderlust. Some wanderers choose to spend their time with others "
      "who wander about in groups, while others will travel alone from town "
      "to town telling jokes and entertaining peasants for a few coins. "
      "Wanderers are sometimes looked down upon because they have a "
"tendancy towards theft.  To become a wanderer, type <become wanderer> "
      "and strike out now and find your path in life, go and find the hall "
      "of the Bard, the hall of the Gypsy, the hall of the Jester, "
      "or the hall of the Swashbuckler.");
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
    if(str != "wanderer") {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
    if((string)this_player()->query_class() != "child") {
        write("You do not possess proper desire to do that.");
        return 1;
    }
    write("%^YELLOW%^You have now dedicated your life to wandering and fun.");
    say("%^YELLOW%^"+this_player()->query_cap_name()+" becomes a wanderer.", this_player());
    this_player()->set_class("wanderer");
    this_player()->setenv("TITLE", "$N the novice traveler");
    this_player()->init_skills("wanderer");
   this_player()->register_channels();
    return 1;
}
int go_up() {
    if(wizardp(this_player())){
      write("Mighty immortals are always welcome into the hall.");
    } else
    if((string)this_player()->query_class() != "wanderer") {
        write("You are no wanderer!");
        say(this_player()->query_cap_name()+" twitches.", this_player());
        return 1;
    }
this_player()->move_player(ROOMS"wanderer_hall", "through a passage of light.");
    return 1;
}
