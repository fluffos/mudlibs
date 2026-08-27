// Modificado por: Osucaru   Dic'97
 
#include <spells.h>
inherit BASE_SPELL;
 
#define ALCOHOL 0
#define VOLUME 200
#define LVL_FACTOR 10 
#define MAX_DRUNK 1000

string CANCION=	"    Cerveza! Quien te invento?\n"
		"    A ese lo quiero ver yo,\n"
		"    bebiendo y por ti brindando,\n"
		"    del vivir eres la reina, CERVEZA.\n";
// CANCION ANTIGUA
/*	"   Twenty-four kegs of the King's finest ale,\n"
	"   If we drank even one, we'd wind up in jail.\n"
	"   Though we'd be merry, our heads in a sail,\n"
	"   At the last we would find our good lunch in a"
	" pail.\n";
*/

#define	NOMBRE	"Intoxicar"
#define	NIVEL	2
#define	ESCUELA	"bardo"
#define	ESFERA	"bardo"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);

  set_help_desc("Este hechizo provoca en el afectado a una razonable " 
     "intoxicacion. La cantidad de embriaguez aumenta con el nivel del bardo.");
 
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int ajuste;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if ( target == caster )
  {
    tell_object(target,"Formulas el hechizo "+NOMBRE+" sobre ti mismo.\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre si mismo.\n",target);
  }
  else
  {
    tell_object(target,"Te sientes un tanto embriagado. Que alegria!\n");
    tell_object(caster,"Formulas Intoxicacion sobre "+(string)target->QCN+".\n");
    tell_room(ENV(caster),"Repentinamente "+target->QCN+" parte muy alegre.\n",({target,caster}));
  }
  ajuste=fix_damage(caster,target,-VOLUME-caster->QL*LVL_FACTOR*POWER);
  if (target->query_volume(ALCOHOL)<MAX_DRUNK) target->adjust_volume(ALCOHOL,-ajuste);

  if (!interactive(target))
  {
    tell_room(ENV(caster), target->QCN+" no prece estar muy satisfecho con las travesuras de "+caster->QCN+".\n",caster);
    tell_object(caster,target->QCN+" no parece estar muy satisfecho con tus travesuras.\n");
    target->attack_by(caster);
  }

  return 0;
}
