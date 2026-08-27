#include "../path.h"

inherit "/obj/monster";

void setup() {
  set_name("nihil");
  set_short("Nihil, Espiritu protector de la Tumba");
  add_alias("espiritu");
  set_habilidad("doble arma",100);
  set_habilidad("filo",100);
  add_alias("protector");
  set_main_plural("Nihil, Espiritus protectores de la Tumba");
  add_plural("espiritus");
  add_plural("protectores");
  set_long("Nihil, Espiritu protector de la Tumba\n\n     "
  	"Un triste y translucido espiritu blanquecino, con unas "
  	"sobrias vestimentas, se encuentra delante de ti. Se trata "
  	"del espiritu que antao fue el amante de Penumbra, la joven "
  	"elfa que vivio en extraa armona con los enanos, invitada "
  	"en su gran ciudad dentro de las entraas de la montaa. "
  	"\n\n     Parece enormemente triste, a juzgar por su aspecto. "
  	"Su cabizbaja cabeza ni siquiera se levanta para mirarte, "
  	"y la expresion de su boca es un gesto de dolor y sufrimiento. "
	"Puede que tenga muchas penas que contar.\n\n");
  set_level(24);
  set_str(28);
  set_con(16);
  set_dex(16);
  set_wis(10);
  set_int(10);
  set_cha(10);
  set_alineamiento(1,1);
  set_max_hp(1200);
  set_max_gp(1000);
  adjust_tmp_damage_bon(5+random(3));
  add_clone(OBJ+"inmaterial",2);
  init_equip();
}

void event_enter(object yo, string mensaje, object donde) {
}
