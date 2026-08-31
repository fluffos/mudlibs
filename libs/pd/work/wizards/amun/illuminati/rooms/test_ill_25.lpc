#include <std.h>
#include <guild.h>
#include <tirun.h>
#include <amun.h>
inherit HALL;
void create() {
    object ob;
    ::create();
    set_type("fighter");
    set("short", "The inner sanctum of the Hall of Fighters");
    set("long","%^BOLD%^%^WHITE%^This is the place where people of all races come to train, improve and level to become the best fighter God could ask for. There are many weapons hanging around for fighters to look at and train with. This is also a room for fighters to share thier wisdom with other fighters.%^RESET%^");
    set_exits( ([ "north" : ILLROOM "ill_24" ]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board" }) );
    ob->set_board_id("fighter_board");
    ob->set_max_posts(50);
    ob->set_location(ILLROOM "ill_25");
    ob->set("short", "%^BOLD%^%^RED%^Fighters Unite%^RESET%^");
    ob->set("long","%^BOLD%^%^RED%^The Fighters of our reality post tales of their glorious adventures here, as well as info on the dangers out there.%^RESET%^");
}
