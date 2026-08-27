/* Editado por Lummen 25-8-97 */
// Modificado por Guldan Jun'98

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
  GRADO=3;
  ::setup();
  set_name("fistandantilus");
  set_short("Fistandantilus El Gran Maestre");
  add_alias("mago");
  set_long("Fistandantilus es el Gran Maestre de la torre de Wareth. Es el encargado "
    "de orientar a los novivios y de hacer respetar las leyes del gremio. Su reputacion "
    "y experiencia es admirada en todo el reino. Es un elfo de apariencia noble y peligrosa "
    "pero de baja estatura. Sus ojos carecen de pupilas, segun se dice por un accidente "
    "mientras investigaba un hechizo, y en su mano izquierda puedes ver que lleva un dedal "
  "de plata.\n");
  set_gender(1);
  set_race("Elfo");
  set_race_ob("/std/races/elf");
  set_guild_ob("/std/guilds/wizards/general_mage");
  set_int(19);
  set_dex(19);
  set_str(17);
set_con(36);
  set_cha(18);
  set_wis(18);
  set_al(-4000);
set_max_hp(1200);
  set_level(NIVEL);
  adjust_money(roll(3,query_level()/2),"platinum");

  load_chat(30,
  ({
    1, "'Si quieres informacion sobre el guild, pon 'info'.",
    1, "'Los Magos son el mas antiguo y poderoso Gremio de Reinos de Leyenda.",
    1, "@amablemente.",
    1, "'Wareth oculta numerosos secretos en su interior. Ve con cuidado.",
    1, "'En el cartel tienes toda la informacion necesaria para el guild."
  }));
  load_a_chat(20,
  ({
    1, "'Ahora conoceras la furia de la magia de Wareth.",
    1, "@prepara uno de los componentes necesarios para formular el siguente hechizo."
  }));

  add_clone(WEAPONS+"ba_wareth",1);
  add_clone(ARMOURS+"tu_wareth",1);
  add_clone(ARMOURS+"ca_wareth",1);
  add_clone(ARMOURS+"cp_wareth",1);
  add_clone(ARMOURS+"am_wareth",1);
  add_clone(ARMOURS+"br_wareth",1);
  add_clone(ARMOURS+"an_wareth",1);
  init_equip();
}
