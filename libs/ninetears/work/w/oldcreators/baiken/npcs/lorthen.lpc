// Guldan Sep'98

#include "path.h"
inherit NPCS+"wizard";

void event_enter(object ob, string mess)
{
  string raza  = ob->query_race();
  string guild = ob->query_guild_name();
  
  if (raza == "Goblin" || raza == "Orco" || raza == "Duergar" ||
  raza == "Hombre-Lagarto" || raza == "Medio-Orco" || raza == "Drow" )
   {
     this_object()->attack_ob(ob);
   }
   else
   {
     if (ob->query_dead())
     {
     do_command("risa "+ob->query_name());
     }
   }
  ::event_enter(ob, mess);
}
setup()
{
  GRADO=5;
  ::setup();
  set_name("lorthen");
  set_short("Lorthen");
  add_alias("mago");
  set_long("Lorthen, el guardian de la torre de Wareth. Con cara de pocos amigos "
    "la cual expresa una fiereza inusual para los magos. Parece especialmente "
    "preparado para el combate y es quien se encarga de proteger la entrada de la torre. "
    "Muchos le han desafiado, pero pocos han vivido para contarlo.\n");
  set_gender(1);
  set_int(18);
  set_dex(18);
  set_str(18);
set_con(36);
  set_con(18);
  set_cha(20);
  set_wis(18);
  set_race("Medio-elfo");
  set_race_ob("/std/races/half-elf");
  set_guild_ob("/std/guilds/wizards/general_mage");
  set_al(-6000);
set_max_hp(1200);
  set_level(NIVEL);
  adjust_money(roll(4,query_level()/2),"platinum");

  load_chat(30,
  ({
    1, "@amablemente.",
    1, "'Wareth oculta numerosos secretos en su interior. Ve con cuidado.",
  }));

  load_a_chat(20,
  ({
    1, "'Ahora conoceras la furia de la magia de Wareth.",
  }));

  add_clone(WEAPONS+"ba_wareth",1);
  add_clone(ARMOURS+"tu_wareth",1);
  add_clone(ARMOURS+"ca_wareth",1);
  add_clone(ARMOURS+"cp_wareth",1);
  add_clone(ARMOURS+"am_wareth",1);
  add_clone(ARMOURS+"an_wareth",1);
  add_clone(ARMOURS+"br_wareth",1);
  init_equip();
}
