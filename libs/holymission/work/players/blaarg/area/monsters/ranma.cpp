inherit "obj/monster";
#include "/players/blaarg/defs.h"
object cap,jacket;      

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Ranma");
    set_alias("ranma");
    set_short("Ranma");
    set_long("Ranma, the hero of this tale, is a young but brilliant\n"+
	     "warrior, son of Genma, with the curse of gender-change with\n"+
	     "just a splash of hot or cold water.\n");
    set_level(35);
    set_al(1000);
    set_hp(2500);
    set_gender(1);
    set_race("anime");
    add_money(2500);
    set_wc(25);
    set_ac(12);
    set_number_of_arms(4);
    cap=clone_object(ARMOUR+"ranmahat");
    move_object(cap, this_object());
    command("wear cap");
    jacket=clone_object(ARMOUR+"ranmajac");
    move_object(jacket, this_object());
    command("wear cloak");

}

