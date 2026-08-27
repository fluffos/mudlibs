/* File upgrade by Grimbrand 2-11-96                                    */

inherit "/obj/monster";

void setup() {
    set_short("hombre-lagarto Cautivo");
    set_name("hombre-lagarto");
    add_alias("lagarto");
    add_alias("cautivo");
    set_main_plural("hombres-lagarto");
    add_plural("hombres-lagarto");
    set_long("   Es un lagarto con aspecto humanoide.  No parece muy "
             "inteligente dadas sus maneras primitivas, sin embargo "
             "dirias que se siente muy comodo con la lanza que porta "
             "como si fuera una extension de su brazo.\n"
             "\n");
    set_guild("fighter");
    set_level(5);
    set_al(50);
    set_random_stats(10,18);
    set_max_hp(20);
    set_kill_xp(155);
    clone_object("/baseobs/weapons/spear")->move(this_object());
    do_command("equip");
    adjust_money(2,"oro");
}
