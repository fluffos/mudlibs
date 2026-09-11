// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit MONSTER;
inherit M_BLOCKEXITS;

void setup() {
    object sword;

    set_name("bill", "比尔");
    set_id("troll");
    set_gender(1);
    set_proper_name("龙族比尔");
    set_in_room_desc("龙族比尔");
    set_long("人们通常都避免凑得很近去观察龙族的人。");
    set_max_hp(10);

    add_block("north");
    set_block_action("$N1向朝$o走，却被$N挡住了$p1路。\n");

    sword = new("/domains/std/objects/sword");
    sword->move(this_object());
    do_wield(sword);
}
