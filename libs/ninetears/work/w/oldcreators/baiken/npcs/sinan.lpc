#include "path.h" 
inherit NPCS+"asesinos";

void setup()
{ 
  set_name("sinan");
  set_short("Sinan");
  set_long("Mas conocido por su sobrenombre "
     "\"el %^RED%^Despiadado%^RESET%^\", Sinan es el Lugarteniente de "
     "Armadin y segundo en la escala de poder en el Gremio de los Asesinos. "
     "Fue durante anyos su mejor alumno y ahora, todavia en la juventud, es "
     "lo mas parecido al maestro. Dada su condicion de lider del Gremio, se "
     "encarga de impedir a toda costa que ningun intruso consiga entrar en "
     "la Gruta y ponga en peligro la vida y pertenencias de los "
     "aprendices.\n");
  set_gender(1);
  set_al(1000);
  set_con(19);
  set_str(18);
  set_dex(19);
  set_int(16);
  set_wis(18);
  set_cha(18);
  set_level(60);
  set_race("Goblin");
  set_race_ob("/std/races/goblin");
  set_guild_ob("/std/guilds/rogues/assassin");
  load_chat(20,
  ({
    1, "'Nadie entra aqui sin el permiso de Armadin.",
    1, "'Lealtad, sangre y dolor. Solo eso quiere Armadin.",
    1, ":bosteza aburrido. Hoy no hay aventureros que se atrevan a entrar "
       "aqui.",
    1, "'Si entras ahi dentro y no le gustas a Armadin, REZA lo que sepas.",
  }));
  
  add_clone("/baseobs/weapons/bastard_sword",2);
  add_clone("/baseobs/armours/chainmail",1);
  add_clone("/baseobs/armours/helm",1);
  add_clone("/baseobs/armours/bracers",1);
//  add_clone("/baseobs/armours/gloves",1);
  add_clone(ITEMS+"gloves",1);
  add_clone("/baseobs/armours/cloak",1);
  init_equip();
}
