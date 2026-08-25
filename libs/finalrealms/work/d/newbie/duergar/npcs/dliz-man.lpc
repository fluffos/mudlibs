/* File upgrade by Grimbrand 2-11-96                                    */

inherit "/obj/monster";

void setup() {
    set_short("lizard-Man Captive");
    set_name("lizard-man");
    add_alias("lizardman");
    add_alias("captive");
    set_main_plural("lizard-men");
    add_plural("lizardmen");
    set_long("   This is a lizard that has a humanoid appearance.  It "
             "doesn't look too intelligent due to its primitive manner, "
             "yet you can tell he is fairly familiar with the spear "
             "that he carries.\n"
             "\n");
    set_guild("fighter");
    set_level(5);
    set_al(50);
    set_random_stats(10,18);
    set_max_hp(20);
    set_kill_xp(155);
    clone_object("/baseobs/weapons/spear")->move(this_object());
    do_command("equip");
    adjust_money(2,"gold");
}
