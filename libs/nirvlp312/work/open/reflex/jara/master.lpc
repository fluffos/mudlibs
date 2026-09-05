inherit "/players/reflex/lib/std/work/monster";

void create() {
    object weapon;
    
    ::create();
    Hands = ([ "first hand":0, "second hand":0 ]);
    set_name("master");
    set_short("The Sand Master");
    set_gender("male");
    set_hp(600);
    set_sp(600);
    set_wc(20);
    set_ac(15);
    set_level(18);
    set_long("This is the Sand Master\n");
    weapon = (object) "players/reflex/snd_swrd"->load();
    transfer(weapon, this_object());
    command("wield sword");
}
