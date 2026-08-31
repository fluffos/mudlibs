#include <daemons.h>
#include <std.h>
inherit ROOM;

int cmd_start(string str);

object ob;
void init()
{
    ::init();
    add_action("cmd_start", "start");
}

void create() {
room::create();
set_properties( ([ "light" : 2, "indoors" : 1]) );
set_short("Shinkoro's Work Area");
set_long(
      "%^BOLD%^%^RED%^This is the small workplace of Shinkoro.  All around "
      "you are little crumpled papers laying on the floor. "
      "In the far corner sits a small oak desk with a vial of ink and a few quills. "
      "Although this room looks new, the person who works here isn't new to rooms like"
       " this.%^RESET%^"
);
set_items(([
        "desk" : "A very small oak desk with fresh laquor shining anew",
        "vial" : " Just a plain vial of writing ink that's full to the brim",
        "quills" : "Writing quills pulled from a pheasant's tail",

]));
set_smell("default", "The slight smell of new ideas can be sensed");
set_listen("default", "The sound of a frustrated wiz beating his " 
"code is here");
set_exits( ([ 
     "down" : "/d/nopk/tirun/square",
    "hall" : "/d/nopk/standard/adv_inner",
    "testroom" : "/wizards/shinkoro/testroom",
    "cave" : "/wizards/shinkoro/pkcave/rooms/cave[]"
    ]) );
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_location("/wizards/shinkoro/workroom");
    ob->set_id( ({ "board", "shinkoro", "shinkoro board" }) );
    ob->set_board_id("Shinkoro_idea");
    ob->set_max_posts(99);
    ob->set_short("Shinkoro's Board");
    ob->set_long("Shinkoro's Idea Board");
}
void reset() {
 ::reset();
   if (!present("box"))
      new("/wizards/seeker/box")->move(this_object());
}
  
int cmd_start(string str)
{
    if (!str || str=="") 
    {
        notify_fail("Start where?\n");
        return 0;
    }
    if (str!="here")
    {
        notify_fail("You cannot start there.\n");
        return 0;

    }
    this_player()->set_primary_start("/wizards/shinkoro/workroom");
    write("You are now set to start here.");
    return 1;
}
