#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Curar"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"curadora"})
#define	CANCION	""
#define	NIVEL	6
#define	TIPO	"heal"
#define	SALV	100

void setup()
{ 
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este es el conjuro de curacion mas poderoso conocido. Es "
    "capaz de curar completamente al objetivo, incluso restituyendole "
    "miembros perdidos y enfermedades. Es un gran privilegio para el clerigo "
    "que su dios le conceda este hechizo.\n");

  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster,"Elevas tus rezos para obtener el poder curativo necesario.\n");
  tell_room(ENV(caster),caster->QCN+" mira a su alrededor buscando a alguien para bendecirle.\n",caster);
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster,"Tu deidad sonrie piadosamente mientras responde a tus rezos y "
     "te concede el poder necesario. Eres envuelto en un aura blanca.\n");
  tell_room(ENV(caster),caster->QCN+" sonrie mientras un aura blanca le invade y le ilumina.\n",caster);
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet )
{
  int hp,damage;
  // this goes, wf. mixed *curses;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!living(target)) 
  {
    tell_object(caster,target->QCN+" no crees poder curar a un espiritu, tal vez "
       "le puedas dar guia espiritual.\n");
    return -1;
  }

  if (target==caster) 
  {
    tell_object(caster,"Terminas de formular el hechizo y un cosquilleo recorre tus "
       "manos. Sientes como el cosquilleo se transmite por todo tu cuerpo y una gran "
       "sensacion de tranquilidad te invade.\n");
    tell_room(ENV(caster),caster->QCN+" suspira descansado y parece que sus heridas "
    "han desaparecido completamente.\n");
  }
  else 
  {
    tell_object(caster,"Tocas a "+target->QCN+" a la vez que sientes como el "
    "cosquilleo te abandona y se transmite al cuerpo de "+target->QCN+" y un aura blanca "
    "le ilumina.\n");
    tell_room(ENV(caster),caster->QCN+" se ilumina debilmente y toca a "+target->QCN+" que "
    "tambien se ilumina. Al instante sus heridas desaparecen.\n");
    tell_object(target,caster->QCN+" te toca mientras te transmite un extranyo "
    "cosquilleo. Este se extiende por tu cuerpo y sientes una gran sensacion de "
    "tranquilidad y sosiego. Tus heridas han desaparecido!.\n");
  }

  damage=fix_damage(caster,target,target->query_max_hp()-target->query_hp());
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
 
/**********

  if ((int)target->query_tmp_int() < 0) {
    target->adjust_tmp_int(-((int)target->query_tmp_int()));
    tell_object(target, "Your intelligence returns to normal.\n");
    }
  if ((int)target->query_tmp_dex() < 0) {
    target->adjust_tmp_dex(-((int)target->query_tmp_dex()));
    tell_object(target, "Your dexterity returns to normal.\n");
	 }
  if ((int)target->query_tmp_wis() < 0) {
    target->adjust_tmp_wis(-((int)target->query_tmp_wis()));
    tell_object(target, "Your wisdom returns to normal.\n");
    }
  if ((int)target->query_tmp_str() < 0) {
    target->adjust_tmp_str(-((int)target->query_tmp_str()));
    tell_object(target, "Your strength returns to normal.\n");
    }
  if ((int)target->query_tmp_con() < 0) {
	 target->adjust_tmp_con(-((int)target->query_tmp_con()));
    tell_object(target, "Your constitution returns to normal.\n");
    }
  target->reset_all();

********/

  /* cure all curses */
/*
  if (sizeof((curses = (mixed *)target->query_curses())))
    for (i=0; i<sizeof(curses); i+=2)
      if (target->query_remove(curses[i])->query_remove(skill)) {
        target->remove_curse(curses[i]);
	  tell_object(target, "The curse of " + curses[i] + " is lifted.\n");
      }
*/

  /* cure all diseases */
/*
  if (sizeof((curses = (mixed *)target->query_diseases())))
    for (i=0; i<sizeof(curses); i+=2)
      if (target->query_remove(curses[i])->query_remove(skill)) {
        target->remove_disease(curses[i]);
        tell_object(target, "The " + curses[i] + " disease is cured.\n");
      }
 */
  return NIVEL*100;
}
