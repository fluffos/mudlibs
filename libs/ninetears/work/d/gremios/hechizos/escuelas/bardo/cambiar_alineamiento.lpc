/***  Cambio de Aliniamiento  ***/
/*** Editado por Osucaru ***/ 

#include <spells.h>
inherit BASE_SPELL;
string CANCION=	"   I've talked to the Gods, I've walked on the stars,\n"
		"   Our fathers were Druids, masters of earth.\n"
		"   Call me a liar, call me a thief,\n"
		"   But from this chant you'll find little relief.\n";
#define	NOMBRE	"Cambiar alineamiento"
#define	NIVEL	4
#define	ESCUELA	"bardo"
#define	ESFERA	"bardo"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(1);

  set_help_desc("Este hechizo cambia el aliniamiento del objetivo.  "
    "Los efectos pueden ser devastadores para algunos gremios, "
    "aunque puede favorecer en algunos momentos.\n");
 
  set_gp_cost(NIVEL);  // 50 es una burrada
  set_casting_time(1);
  set_rounds(({"round1"}));
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
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
  if (random(target->query_res("magical"))<10)
  {	
     if (target==caster)
     {
        tell_object(target,"Formulas "+NOMBRE+" sobre tu persona.\n");
    	tell_room(ENV(caster),caster->QCN+" formula un hechizo sobre si mismo.\n",target);
     } 	
     else
     {
        tell_object(target,"Te sientes diferente, como si a tu espiritu le hubieran dado completamente la vuelta!\n");
        tell_object(caster,"Formulas "+NOMBRE+" sobre "+target->QCN+".\n");
        tell_room(ENV(caster),target->QCN+" repentinamente cambia de humor.\n",({target,caster}));
     }	
     target->reverse_align();
     target->set_ethics(-(int)target->query_ethics());
  }
  else
  {
     tell_object(target,"Notas repentinamente un viento pasa atraves "
        "de tu alma, tiemblas, aunque, no has cambiado en nada.\n");
     tell_object(caster,"Tu hechizo ha fallado.\n");
  }   

  if (!interactive(target))
  {
    tell_room(ENV(caster),target->QCN+" no parece estas muy agradecido con "
      "la hazanya de "+caster->QCN+".\n", caster);
    tell_object(caster,target->QCN+" no parece estar muy contento con tu hazanya.\n");
    target->attack_by(caster);
  }

  return 0;
}
