// Traducido por Spp ENE'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Conocer alineamiento"
#define	ESCUELA	({"adivinacion"})
#define	ESFERA	({"adivinacion","paladin"})
#define	NIVEL	2
#define	CANCION	"'ethos deus beleah'"

void setup()
{
  set_spell_name(NOMBRE);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo detecta el alineamiento de tu objetivo. "
    "La cantidad de informacion obtenida depende del nivel del que "
    "formula el hechizo.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  string retv,deity,mydeity;
  int i;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  tell_object(caster,"Clamas a los Dioses para conocer el alineamiento de "+target->QCN+".\n");
  tell_object(target, caster->QCN+" te mira fijamente y formula unas palabras "
    "sobre ti, sientes tu alma desnuda ante "+caster->query_pronoun()+".\n");
  tell_room(ENV(caster),caster->QCN+" mira fijamente a "+target->QCN+
    " formulando un hechizo sobre el.\n",({caster, target}));

  i=target->query_align();
  retv="Notas que "+target->QCN+" es moralmente "+target->query_align_name(i)+".\n";
  deity=target->query_deity();
  mydeity=caster->query_deity();

  switch (caster->QL)
  {
    case 21..1000:
      i = target->query_deity_status(mydeity);
      retv += "Es"+target->query_deity_string(i)+mydeity+".\n";
    case 16..20:
      i = target->query_deity_status(deity);
      retv += "Es"+target->query_deity_string(i)+deity+".\n";
    case 11..15:
      retv += "Es un devoto de "+deity+".\n";
    case 6..10:
      i = target->query_ethics();
      retv += "Y es eticamente "+target->query_ethical_name(i)+".\n";
  }

  tell_object(caster,retv);
  return NIVEL*100;
}
