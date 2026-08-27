// Traducido por Lummen 28-7-97
// Guldan Sep'98
 
#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE	= "Invocar muerto";
mixed	ESCUELA	= ({"necromancia"});
mixed	ESFERA	= ({"necromantica"});
int	NIVEL	= 9;
string	CANCION	= "''";
#define	DIR	"/obj/chars/"
#define	NPCS	({"skeleton","ghoul","zombie","wraith","spectre"})

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Esta es la base de un hechizo de invocaciones.\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Comienzas a formular el hechizo de invocacion.\n");
  tell_room(ENV(caster),caster->QCN+" comienza a formular unhechizo de invocacion.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i,j;
  object npc,*atts;

  tell_object(caster,"Pronuncias un cantico de palabras arcanas!.\n");
  tell_room(ENV(caster),caster->QCN+" pronuncia un cantico de palabras arcanas con los brazos en alto!.\n",caster);
  atts=caster->query_attacker_list()+caster->query_call_outed();
  atts-=({0});

  if (!sizeof(atts))
  {
    tell_object(caster,"Las palabras del cantico no tienen sentido aparente, el hechizo falla.\n");
    return -1;
  }	  

  for (i=0;i<(caster->query_cha()/10)+1;i++)
  {
    npc=clone_object(DIR+NPCS[random(sizeof(NPCS))]);
    if (!npc) continue;
    npc->set_aggressive(0);
    caster->set_protector(npc);
    npc->set_friend(caster);
    npc->move(ENV(caster));
    tell_room(ENV(caster),"Comienza a tomar forma solida un "+npc->query_short()+" que se dirige a "+caster->QCN+" ofreciendole su ayuda.\n",caster);
    tell_object(caster,"Un "+npc->query_short()+" toma forma para ayudarte.\n");
    for (j=0;j<sizeof(atts);j++) npc->attack_ob(atts[j]);
  }			
  return 0;
}
