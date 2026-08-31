#include <std.h>
#include <tirun.h>

inherit ROOM;


void create()
{

 ::create();
 set_short("The holy place of the Clergy");
 set_long("This temple was created as the holy place of the Clergy. Clergy all "
   "come here until they choose their path in life. Within this hall, Clergy "
   "of all beliefs are able to put aside their battles and train together, "
   "though this unity does not last once they leave the temple. Those newbie "
   "adventurerers who have not chosen a class can <become clergy> here, though "
   "you are recommended to <preview> first.");
 set_exits ( ([ "north" : ROOMS "ehonin4",
		"east": ROOMS "clergy_hall" ]) );

}

int become(string str) {
   if (!str || str != "clergy") return notify_fail("Become what?\n");
   if (this_player()->query_class() != "child") return notify_fail(
     "You already have a class.\n");
   write("You choose your faith and follow the path of the Clergy.");
   say(this_player()->query_cap_name()+" finds "
     +this_player()->query_title_gender()+" faith in the path of the Clergy.",
     this_player());
   this_player()->set_class("clergy");
   this_player()->setenv("TITLE", "$N the believer");
   this_player()->init_skills("clergy");
   this_player()->register_channels();
   return 1;
}

int preview() {
    if((string)this_player()->query_class() != "child") {
        write("This is not for you.\n");
        return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about fighter.",
        this_player());
    write("Welcome, child!");
write("Clergy are those people that believe in dedication of their "
     "lives to religion and to their holy, or unholy, beliefs.  The"
     "only uniting factor between all Clergy is that they are completely "
     "dedicated to their faith.  To become a clergy, type <become clergy> "
     "and strike out now and find your path in life, go and find the hall "
     "of the Cleric, the hall of the Druid, the hall of the Monk, or the "
     "hall of the Kataan.");
    return 1;
}

int go_east() {
   if (this_player()->query_class() != "clergy" && !wizardp(this_player()))
     { write("You cannot enter this palce."); return 1; }
   return 0;
}

void init() {
 ::init();
   add_action("become", "become");
   add_action("preview", "preview");
   add_action("go_east", "east");
}
