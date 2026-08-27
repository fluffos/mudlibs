// Modificado por: Osucaru  dic'97 

#include <spells.h>
inherit BASE_SPELL;
 
#define ALCOHOL 0
#define VOLUME 200
#define LVL_FACTOR 10 
#define MIN_DRUNK 0
string CANCION=	"    Si resisto, si resisto y sobrevivo es por tu luz.\n"
		"    Me llevaste a tu casa\n"
		"    yo enseguida a sobar\n"
		"    tu ya imaginarias que no iba a funcionar\n"
		"    y ahora en la cabeza que resaca de verdad.\n"
		"    Tu mosqueo de la noche no para de retumbar...\n"
		"    \"Deja de beber tanta cerveza y lucha\"...\n"
		"    te pasas todo el dia en la barra del bar\n"
		"    aunque este todo perdido siempre queda molestar\n"
		"    Si resisto, si resisto y sobrevivo es por tu luz...\n";
                  /*      Equilibrio ( Kortatu )        */ 
/* ANTIGUA CANCION
	"   Adventure has waited, we've been in a slump,\n"
	"   No treasure we've plundered, nor goods not a lump.\n"
	"   How can we overcome this inebriated hump?\n"
	"   Mind to your manners and stop being drunk.\n";
*/
#define	NOMBRE	"Sobriedad"
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
  set_help_desc("Este hechizo hace que el objetivo quede sobrio si estaba "  
    "intoxicado. La cantidad de alcohol en sangre perdida esta relacionada "
    "con el nivel del bardo.");
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

  if (target==caster)
  {
    tell_object(target, "Formulas el hechizo "+NOMBRE+" sobre ti mismo.\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo sobre si mismo.\n",target);
  }
  else
  {
    tell_object(target, "Te sientes menos embriagado. Menuda borrachera!\n");
    tell_object(caster, "Formulas "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),target->QCN+" parece que se siente un poco mas sobrio.\n",({target,caster}));
  }

  ajuste=fix_damage(caster,target,VOLUME+caster->QL*LVL_FACTOR*POWER);
  if (target->query_volume(ALCOHOL)>MIN_DRUNK) target->adjust_volume(ALCOHOL,-ajuste);
  
  return 0;
}
