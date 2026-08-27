#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Palabra sagrada"
#define	NIVEL	7
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	({"combate"})
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("all");
  set_range(0);
  set_help_desc("Este hechizo canaliza parte de la fuerza de Yvendur al clerigo atraves\n"
    "de un grito mistico.  Todo lo que se encuentre a tu alrededor se paralizara y estara\n"
    "incapacitado durante algun tiempo.\n");
  set_gp_cost(NIVEL);	// 38
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level, i;
  object shadow;

  if(caster->query_timed_property("Holy_word_property"))
  {
    tell_object(caster,"Aun no puedes invocar la energia necesaria para poder "
                       "ejecutar este hechizo nuevamente.\n");
    return -1;
  } 
  if (sizeof(target)<2)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,"Coges aire profundamente ...\n"
      "Levantando tu simbolo sagrado exclamas con todas tus fuerzas el nombre de %^BOLD%^Yvendur%^RESET%^\n"
      "Durante un instante te quedas sin sentido, notando un cosquilleo en tus labios\n"
      "El tiempo cambia de repente y todo lo que se encuentra a tu alrededor se paraliza.\n"
      "El poder de Gestur se canaliza a traves de ti dejando atontado a todo el mundo.\n");
    
    tell_room(ENV(caster),caster->QCN+
      " levanta su simbolo sagrado, inhalando aire profundamente\n"
      +caster->query_pronoun()+" exclama el nombre de %^BOLD%^Gestur%^RESET%^\n"
      "y un inmenso poder llega desde el cielo canalizandose atraves del cuerpo de "+caster->query_cap_name()+
      "Notas como el tiempo cambia y todo se vuelve mas lento de lo normal !\n");     
  }

  for (i=0;i<sizeof(target);i++)
  {
    level=target[i]->QL;
    target[i]->clear_attackers();
    if (!target[i]->query_creator())
    {
      shadow=clone_object(SHADOWS+"h_word_sh1");
      shadow->setshadow(target[i],caster);
      if (target[i]==caster) call_out("hw1_wear_off", 12, target[i]);
      else call_out("hw1_wear_off", 20, target[i]);
    }
  }
  caster->add_timed_property("Holy_word_property",1,40);
  return NIVEL*100;
}

void hw1_wear_off(object target)
{
  if (target) target->destruct_hw1_shadow();
}
