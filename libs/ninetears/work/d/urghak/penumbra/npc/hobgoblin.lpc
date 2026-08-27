#include "../path.h"

inherit "/obj/guardian";

void setup() {
  set_name("hobgoblin");
  set_short("Guardia Hobgoblin");
  add_alias(({"guardia","hobgoblin"}));
  set_main_plural("Guardias Hobgoblin");
  add_plural(({"guardias","hobgoblins"}));
  set_long("Guardia Hobgoblin\n\n     "
  	"Los guardias hobgoblin son la guardia de la ciudad de la "
  	"ciudad de Penumbra. Su mision consiste en patrullar y defender "
  	"a los ciudadanos de Penumbra tanto de ellos mismos como de "
  	"invitados no deseados. Los hobgoblins destacan por su gran " 
  	"fuerza y su brutalidad con cualquier ser vivo, tanto amigo "
  	"como enemigo.\n");
  set_gender(1);
  set_level(20);
  set_str(28);
  set_con(18);
  set_dex(18);
  set_wis(10);
  set_int(10);
  set_cha(10);
  set_alineamiento(0,-1);
  set_max_hp(200);
  set_max_gp(300);
  add_clone(OBJ+"largagoblin",2);
  add_clone(OBJ+"mallagoblin",1);
  set_ciudadania("penumbra");
  add_move_zone("penumbra_tp");  
  init_equip();
  load_chat(50,
    ({
     1, "'No me hagas enfadar o te destrozare!",
     1, ":te mira de arriba a abajo enfurecido.",
     1, "'Manten el orden, idiota!!!",
     1, "'Que no te vea intentar robar a nadie!",
    }));  
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
