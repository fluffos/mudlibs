#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Palabra poderosa matar"
#define	ESCUELA	"conjuracion"
#define	ESFERA	"necromantica"
#define	NIVEL	9
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo mata a la persona sobre la que es formulado. Si la victima es suficientemente poderosa, el hechizo puede fallar");

  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Empiezas a recitar una morbida salmodia.\n");
  tell_room(ENV(caster),caster->QCN+" comienza a recitar una morbida salmodia.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Tu cantico se convierte en un malevolo y perverso grito.\n");
  tell_room(ENV(caster),caster->QCN+" aumenta la intensidad de su cantico, degenerando en un malevolo grito.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Detienes bruscamente tu cantico y un apabullador silencio inunda el lugar.\n");

  tell_room(ENV(caster),caster->QCN+" detiene bruscamente su cantico, y un ominoso silencio inunda el lugar.\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int skill;
  int check;
  int cost;
  int c_roll, t_roll;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    tell_room(ENV(caster),caster->QCN+" parece confundido y maldice!.\n",caster);
    return -1;
  }

  if (target->query_creator())
  {
    tell_object(caster,"Matar un inmortal no seria muy inteligente por tu parte.\n");
    tell_room(ENV(caster), caster->QCN+" parece confundido y maldice!.\n", caster);
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster,(string)target->QCN+" ya esta muerto.\n");
    tell_room(ENV(caster), caster->QCN+" parece confundido y maldice!.\n", caster);
    return -1;
  }

  if (target->query_pacify_spell())
  {
    tell_object(caster,"No te encuentras con ganas de atacar a "+target->QCN+" al ver el tan paficico estado en el que se encuentra.\n");
    return -1;
  }

  /* here is the "saving throw" I'm trying out */

  c_roll = random( (int)caster->query_level() * (int)caster->query_wis() + 5 );
  t_roll = (int)target->query_level() * (int)target->query_wis();
  if ( c_roll*((100-(int)target->query_property("magical")) / 100 ) < t_roll )
  {
    tell_object(target, "Oyes a "+(string)caster->QCN+" susurrarte la Muerte a traves del silencio.\n");
    tell_object(caster,"Tu palabra queda exhalada como un mero susurro...\n");
    tell_room(ENV(caster),caster->QCN+" susurra algo a "+target->QCN+" acabando con el silencio que inunda la zona.\n",caster);
    caster->attack_ob(target);
    return 0;
  }

  if(target->query_property("pacify_on"))
  {
    tell_room(ENV(caster),"Los Dioses interfieren para salvar la vida de "+target->QCN+".\n");
    return 0;
  }

  tell_object(caster,"Rompes el siniestro silencio con el grito: MUERE "+target->QCN+"!!!\nInvocas a los Dioses para que traigan la muerte a "+target->QCN+".\n");
  tell_room(ENV(caster),caster->QCN+" rompe el siniestro silencio con el grito: MUERE "+target->QCN+"!!!\n",caster);
  tell_object(target,"Sientes como la morbida palabra de "+caster->QCN+" destroza la esencia de tu ser.\nLa Palabra de Poder te ha matado.\n");
  target->do_death(caster);
  return 0;
}
