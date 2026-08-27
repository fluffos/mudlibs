//Paris. Nov '98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Herrumbe"
#define	NIVEL	7
#define	ESCUELA	({"wizwar"})
#define	ESFERA	({""})
#define	CANCION	""
#define	MIN_LEVEL	21

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(1);
  set_help_desc("Este hechizo afecta de forma permanente al estado general de "
                "un arma en el objetivo del hechizo. Todas las armas tiene una "
                ",mayor o menor, capacidad para resitirse al hechizo, pero si no "
                "lo hacen esta quedara en muy mal estado.\n");
  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object *all,arma;
  int i,efecto,resistencia;
  
  if (!living(target))
  {
    tell_room(ENV(caster),caster->QCN+" parece momentaneamente aturdido y "
      "deja de recitar su cantico.\n");
    tell_object(caster,"Intentando tirar el hechizo sobre algo que no puede "
      "llevar armas ?. Incomprensible.\n");
    return -1;
  }
  
  all = target->query_held_ob();
  for(i=0;i<sizeof(all);i++)
    if(all[i]->query_weapon())
    {
      if(!all[i]->query_timed_property("herrumbe"))
      {
        resistencia = all[i]->query_enchant();
        resistencia *= random(caster->query_level());
        if(resistencia < 28)
        {
          tell_object(target,caster->query_cap_name()+" pronuncia unas palabras "
                      "en un lenguaje arcano y tu "+all[i]->query_short()+
                      "vibra bajo el influjo de tan poderoso lenguaje.\n");
          tell_object(caster,"Pronuncia unas palabras en un lenguaje arcano y "
                             +all[i]->query_short()+" de "+target->QCN+" vibra "
                             "bajo el influjo de tan poderoso lenguaje.\n");
          tell_room(ENV(target),caster->QCN+"pronuncia unas palabras en un "
                                "lenguaje arcano y "+all[i]->query_short()+" de "+
                                target->QCN+" vibra bajo el influjo de tan "
                                "poderoso lenguaje.\n",({target,caster}));
          
          efecto = (int)(caster->QL*POWER*(random(2)+1));
          all[i]->adjust_cond(efecto);
          efecto =(int)(efecto*caster->QL)/100;
          all[i]->add_timed_property("herrumbe",1,efecto);
          break;
        }
        else
        {
          tell_object(target,caster->query_cap_name()+" pronuncia unas palabras "
                      "en un lenguaje arcano y tu "+all[i]->query_short()+
                      "se sacude fuertemente al rechazarlas.\n");
          tell_object(caster,"Pronuncia unas palabras en un lenguaje arcano y "
                             +all[i]->query_short()+" de "+target->QCN+" se "
                             "sacude fuertemente al rechazarlas.\n");
          tell_room(ENV(target),caster->QCN+"pronuncia unas palabras en un "
                                "lenguaje arcano y "+all[i]->query_short()+" de "+
                                target->QCN+" se sacude violentamente al "
                                "rechazarlas.\n",({target,caster}));
          return -1;
       }
     }
     else
       tell_object(caster,"Las armas de "+target->QCN+" ya han sido "
                   "afectadas por un hechizo de herrumbre.\n");
  } 
  return 1;
}
