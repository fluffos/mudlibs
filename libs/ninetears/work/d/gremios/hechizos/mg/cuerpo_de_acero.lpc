//Paris. Nov'98

#include <spells.h>
inherit BASE_SPELL;

#define STEEL_BODY_PROP "Cuerpo de Acero"
#define NOMBRE	"Cuerpo de Acero"
#define	ESCUELA	({"alteracion","wizwar"})
#define	ESFERA	({""})
#define	NIVEL	6
#define	CANCION	"'fere hilis tzbem ocsa'"
#define COSTE   21

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Un poderoso hechizo que permite al hechicero convertir todo "
    "su cuerpo en acero. Esto reporta grandes beneficos pues, "
    "aunque no se pueden blandir armas ni armaduras, el danyo "
    "producido por ataque desarmado es aumentado "
    "brutalmente asi como la categoria de armadura.\n");
                
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shadow;
  int tiempo = caster->QL*10*3;

  if (caster->query_steel_skin_spell())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }     

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(caster, "Tu cuerpo se retuerce por el dolor cuando toda tu piel y organos "
    "se transforman en hierro.\n");
  tell_room(ENV(caster),caster->QCN+" formula un hechizo y su cuerpo se transforma en hierro.\n",caster);
  
  shadow=clone_object(SHADOWS+"cuerpo_acero_sh");
  caster->ATP(STEEL_BODY_PROP,1,tiempo);
  shadow->setshadow(caster); 
  return 1;
}
