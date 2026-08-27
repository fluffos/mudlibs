// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

#define DISPELL(s) if (ob->QTP(s)) {ob->RTP(s);return;}
#define	NOMBRE	"Disipar magia"
#define	ESCUELA	({"adivinacion"})
#define	ESFERA	({"proteccion","paladin"})
#define	CANCION	"'nullo magius'"
#define	NIVEL	3

void do_dispell(object);

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo interumpe cualquier encantamiento "
    "que este afectando a un objetivo. Objetivos de alto nivel (pueden "
    "ser buenos o malvados) pueden tener encantamientos mas poderosos, "
    "por lo que seran mas dificiles de disipar. Este hechizo disipara "
    "un unico hechizo sobre un objetivo, y solo afectara a un objetivo.\n");
  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int OK=random(20);

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (OK!=19 && OK)
  {
    OK+=caster->QL-target->QL+POWER;
    OK=OK>10;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  if (target==caster)
  {
    tell_object(caster,"Acabas el hechizo y sientes que la magia se va de ti.\n");
    tell_room(ENV(caster),caster->QCN+" acaba en hechizo y se ve aparentemente normal.\n", caster);
    do_dispell(caster);
    caster->ATP("nocast",1,caster->QL/MAX(POWER,1));
    return 0;
  }
  else if (!OK)
  {
    tell_room(ENV(caster),caster->QCN+" acaba el hechizo con unos gestos "
      "sobre "+target->QCN+", pero no parece pasar nada.\n",({caster,target}));
    tell_object(caster,"Completas tu hechizo, pero te das cuenta que los "
      "encantamientos sobre "+target->QCN+" son demasiado poderosos para tus "
      "habilidades.\n");
    tell_object(target,caster->QCN+" acaba el hechizo con unos gestos sobre "
      "ti, pero no parece muy contento.\n");
    return 0;
  }

  tell_room(ENV(caster),(string)caster->QCN+" acaba el hechizo con unas florituras.\n",({caster,target}));
  tell_object(target,caster->QCN+" acaba el hechizo con unos gestos sobre ti.\n");
  tell_object(caster,"Acabas el hechizo y destruyes los encantamientos que pudieran afectar a "+target->QCN+".\n");
  do_dispell(target);
  return NIVEL*3;
}

void do_dispell(object ob)
{
  ob->dispell_me();
  DISPELL("veneno");
  DISPELL("electrico");
  DISPELL("fuego");
  DISPELL("frio");
  DISPELL("acido");
  DISPELL("magico");
  DISPELL("tierra");
  DISPELL("aire");
}
