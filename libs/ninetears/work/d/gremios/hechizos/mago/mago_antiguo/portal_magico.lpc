/*** Traducido por Lummen 4-9-97 ***/

#include <spells.h>
inherit BASE_SPELL;
#define	NOMBRE	"Portal magico"
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({""})
#define	NIVEL	9
#define	CANCION	"'magius portius'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo es capaz de abrir un Portal Magico en una "
  "de las torres de hechiceria. De esta forma podras viajar de un Portal "
  "a otro, apareciendo asi en otra torre de hechiceria.");

  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({({
    "Comienzas a formular el hechizo, todo tu ser se estremece al concentrar una grancantidad de poder en un solo punto, el Portal.\n",
    "De pronto el aire comienza a levantarse acariciando tu cara, un cumulo de poder se concentra.\n",
  }),"round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!ENV(caster)->query_portal())
  {
    tell_object(caster,"El hechizo solo puede ser formulado delante de un Portal Magico.\n");
    return -1;
  }
  
  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  tell_object(caster,"De pronto el Portal Magico se abre frente a ti.\n"
    "Un gran estruendo golpea tus oidos, y una luz intensa surge del Portal invitandote a entrar en el.\n"
    "Sin vacilar te diriges hacia el Portal y lo cruzas, apareciendo en otro lugar.\n");
  tell_room(ENV(caster), caster->QCN+" abre el Portal "
  "Magico y entra dentro de el, para cerrarse tras sus pasos.\n",caster);
  caster->ATP("stillcasting",1,3-POWER);
  caster->move(ENV(caster)->query_donde());
  return NIVEL*100;
}
