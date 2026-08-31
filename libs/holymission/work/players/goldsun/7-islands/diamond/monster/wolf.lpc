inherit "/obj/monster";
#define COLOUR ({"gray","red","silver","black","white"})
#define LENGTH 5   

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name(COLOUR[random(LENGTH)]+" wolf");
set_alias("wolf");
set_race("wolf");
set_short(name);
set_gender(1);
set_long("A "+name+" wolf. He is very hungry but strong.\n");
set_level(40);
set_wc(35);
set_ac(10);
set_size(3);
set_aggressive(1);
set_spell_mess1("Wolf snatches your body.\n");
set_spell_mess2("");
set_chance(33);
set_spell_dam(58);
}

