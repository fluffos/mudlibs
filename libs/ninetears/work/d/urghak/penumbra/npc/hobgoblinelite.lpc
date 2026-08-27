#include "../path.h"

inherit "/obj/civil";

void setup() {
  set_name("hobgoblin");
  set_short("Guerrero Hobgoblin de Elite");
  add_alias(({"guerrero","hobgoblin","elite"}));
  set_main_plural("Guerreros Hobgoblin de Elite");
  add_plural(({"guerreros","hobgoblins","elites"}));
  set_long("Guerrero Hobgoblin de Elite\n\n     "
  	"Se trata de uno de los Guerreros Hobgoblins mas poderosos "
  	"de toda Penumbra. Ha accedido al rango de Guardian de las "
  	"Puertas despues de muchos, muchos anyos demostrando su valia "
  	"y su crueldad como guerrero. Para el es un honor guardar " 
  	"las puertas de su bienamada ciudad, y sin duda dara su vida "
  	"para evitar cualquier intrusion.\n");
  set_gender(1);
  set_race("goblin");
  set_level(28);
  set_str(28);
  set_con(16);
  set_dex(18);
  set_wis(10);
  set_int(10);
  set_cha(14);
  set_alineamiento(0,-1);
  set_max_hp(400);
  set_max_gp(300);
  this_object()->init_command("proteger ogro");  
  this_object()->init_command("proteger guerreros");  
  add_clone(OBJ+"mayal",1);
  add_clone(OBJ+"corazaguardian",1);
  init_equip();
  set_ciudadania("penumbra");
  add_property("NO_BUDGE", 1);
}

void event_enter(object enterer, string message)
{
  if (!enterer)
    return;
  if (enterer->query_dead())
    return;
  if (enterer->query_alineamiento()[1] == 1)
    this_object()->attack_ob(enterer);
  ::event_enter(enterer,message);
}
