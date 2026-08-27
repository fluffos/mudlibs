// Traducido por Lummen 3-7-97

#include <spells.h>
inherit BASE_SPELL;
#define BEAST		"/baseobs/monsters/displacer"
#define BLINKROOM	"/room/blinkroom"
#define	NOMBRE	"Parpadeo"
#define	ESCUELA	"alteracion"
#define	ESFERA	""
#define	NIVEL	3
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("none");
  set_range(100000);
  set_line_of_sight_needed(0);
  set_help_extras("Este hechizo hace que el hechicero viaje entre esta "
    "dimension y otra durante 20 rounds.\n"
    "Nota: El viaje interdimensional es arriesgado.\n");
  add_property_to_check("blinked");
  set_casting_time(24);
  set_gp_cost(NIVEL);
  set_rounds( ({ "round0","round1","round2","round1","round2","round2","round1","round2",
                 "round1","round2","round1","round2","round2","round1","round1","round2",
                 "round1","round2","round1","round2","round2","round1","round1","round3"
                }) );
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet);

int round0(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (caster->QP("blink"))
  {
    tell_object(caster,"Oops, realmente no estas nervioso?\n");
    round2(caster,caster,out_range,time,quiet);
    return 0;
  }
  
  tell_room(ENV(caster),caster->QCN+" formula un hechizo y desaparece para marcharse a algun lugar.\n",caster);
  caster->ATP("blinked",1,200);
  return 1;
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int j;
  string room;
  object *atts_list;

  //  check to see if we move them
  if (find_object(BLINKROOM) == ENV(caster)) return 1;
  tell_object(caster, "Te desvaneces...\n");
  atts_list = caster->query_attacker_list();

  caster->AP("blink",file_name(ENV(caster)));
  caster->move(BLINKROOM);
  caster->look_me();

  for (j=0;j<sizeof(atts_list);j++)
    if(atts_list[j])
    {
      caster->stop_fight(atts_list[j]);
      atts_list[j]->stop_fight(caster);
    }

  atts_list = caster->query_call_outed();
  for (j=0;j<sizeof(atts_list);j++)
    if(atts_list[j])
    {
      caster->stop_fight(atts_list[j]);
      atts_list[j]->stop_fight(caster);
    }
  return 1;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  string room=caster->QP("blink");
  
  if (!room)
  {
//    caster->move("/room/raceroom");
    return 0;
  }
  
  tell_object(caster, "Reapareces...\n");
  caster->move(room);
  tell_room(ENV(caster),"Chasss!\n");
  caster->look_me();
  return 1;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object beast,victim;
  object *olist;
  string room=caster->QP("blink");

  if (!room)
  {
//    caster->move("/room/raceroom");
    return 0;
  }

  if (find_object(room) == ENV(caster)) return 1;
  tell_object(caster, "Reapareces...\n");
  caster->move(room);
  tell_room(ENV(caster),caster->QCN+" parece que se estabiliza finalmente.\n");
  if (interactive(caster) && !random(caster->query_cha()+POWER))
  {
    if (stringp(BEAST))
    {
      beast = clone_object(BEAST);
      if (beast)
      {
        olist = all_inventory(ENV(caster));
        victim = olist[random(sizeof(olist))];
        beast->move(room);
        if(victim->query_alive())
        {
          if(random((int)victim->query_cha()) > 10)
          {
            victim->add_follower(beast);
            beast->do_protect(victim->QN);
          }
          else victim->attack_by(beast);
        }
        tell_object(caster,"Oops, algo parece haberte seguido a tu casa.!\n");
        tell_room(ENV(caster),"Oops, algo parece haberte seguido a "+
        caster->QCN+" a su casa!.\n",caster);
      }
    }
  }
  caster->look_me();
  caster->RP("blink");
  return 1;
}
