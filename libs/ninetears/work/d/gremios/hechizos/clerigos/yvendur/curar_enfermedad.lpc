#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Curar enfermedad"
#define	NIVEL	5
#define	ESFERA	({"curadora"})
#define	ESCUELA	({"yvendur"})
#define	CANCION	"'illar camu enufus'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("   Este hechizo cura muchas enfermedades."
     "Sintomas extranyos pueden aparecer luego d formulado este hechizo.\n"
     "  Los clerigos con "
     "esferas sanadoras mas poderosas tendran mas exito con este hechizo.\n");
  
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i,j;
  object *stuff;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  // added to kill parasites (shifter guild)
  if (target->query_property("infecting")==1||sizeof(target->query_enfermedades())>1)
  {
    tell_room(ENV(caster),caster->QCN+" concentra todo su poder curador sobre "+target->QCN+"!\n");
    target->do_cure(caster);
    return 1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target==caster)
  {
    tell_object(target,"Te curas las enfermedades que tenias.\n");
    tell_room(ENV(caster),caster->QCN+" se cura a si mismo alguna enfermedad.\n",caster);
  }
  else
  {
    tell_object(target,caster->QCN+" te toca curandote alguna enfermedad.\n");
    tell_object(caster,"Formulas "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo y cura las enfermedades de "+target->QCN+".\n",({target,caster}));
  }
  stuff=all_inventory(target);
  for (j=0;j<sizeof(stuff);j++) if((stuff[j]->query_name())=="disease") stuff[j]->dest_me();
  target->RTP("diseased");
  target->RSP("diseased");
  target->ROP("diseased");
  if(sizeof(target->dame_enfermedades())>1)
     target->limpia_enfermedades();
  return 10;
}
