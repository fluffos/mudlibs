#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE  "Desintegrar"
#define ESCUELA ({"invocacion","wizwar"})
#define ESFERA  ({})
#define NIVEL   5
#define CANCION "'bellum destruct corpore'"
#define TIPO    "magical"
#define SALV    100
#define MAX_D   15
#define SIZE_D  4
#define BONUS   2

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(10);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Ninguna");
  set_help_desc("Este hechizo lanza una onda magica que explota sobre el "
     "enemigo que le supone una disgragacion de sus atomos. El "
     "danyo aumenta segun el nivel del hechizero.\n");
  
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,NO_D=MIN((caster->QL+1)/2,MAX_D);

  if (caster->query_property("no_desintegrar"))
  {
    tell_object(caster,"No puedes juntar la energia necesaria para formular "
       "este hechizo.\n");
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
    tell_object(caster,MSG_SUIC_C);
    tell_room(ENV(caster),MSG_SUIC_R,caster);
    return -1;
  }


  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(target,"Un golpe magico impacta fuertemente en tu pecho disgregando "
    "tus atomos esparciendolos en la atmosfera.\n");
  tell_object(caster, "Formulas el hechizo y un fuerte impacto magico golpea "
    "a "+target->QCN+" disgregando sus atomos esparciendolos en el aire.\n");
  tell_room(ENV(caster),caster->QCN+" formula un hechizo y "+target->QCN+
    " es golpeado por un ataque magico que le arranca trozos de piel y carne "
    "que son vaporizados.\n",({target,caster}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D)-NO_D*BONUS);
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  caster->ATP("no_desintegrar",1,20);
  return NIVEL*100-damage;
}
