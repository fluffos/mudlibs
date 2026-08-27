//Paris. Nov '98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Maldecir Arma"
#define	NIVEL	5
#define	ESCUELA	({"wizwar"})
#define	ESFERA	({""})
#define	CANCION	""
#define	GP_COSTE	120
#define	MIN_LEVEL	30

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo permite maldecir un arma. Eso significa que las "
                "capacidades de la misma se ven reducidas. El efecto depende "
                "tanto del nivel del jugador como de los componentes que el "
                "hechicero emplee en el mismo. Se tira sobre el jugador "
                "objetivo, y afectara a alguna de las armas que empunye o lleve "
                "en el equipo (Ya se sabe que no hay nada seguro excepto la "
                "muerte). El componente esencial es el ojo del Conjurador de Almas, "
                "pudiendo mejorar la efectividad del hechizo con otros "
                "componentes.\n");
  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Levantas tus brazos al aire para permitir que la energia entre en tu cuerpo.\n");
  tell_room(ENV(caster),caster->QCN+" levanta sus brazos al aire al tiempo que empieza a cantar haciendole "
    "estremecer de placer al recorrer la energia su cuerpo.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"La energia acumulada en tu cuerpo es canalizada hacia tus manos que adquieren un brillo rojizo.\n");
  tell_room(ENV(caster),"La energia acumulada por "+caster->QCN+" es redireccionada a sus manos que adquieren un brillo rojizo.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Estas en el punto alguido del hechizo, tu cantico se torna grave y te contoneas al son de la musica que tu mismo pronuncias.\n");
  tell_room(ENV(caster),caster->QCN+" cambia el tono de su cante a otro mas grave y empieza a irradiar calor debido a la energia que atesora.\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i,j,resistencia,tiradas,dados=1;
  object *ob,*all,basico=present("ojo del conjurador",caster),*holder;
  string genero = "la";

  if (!basico)
  {
    tell_object(caster,"Despues de tanto trabajo y no tienes el componente "
      "esencial para el hechizo? Todo tu trabajo se va al garete por esta "
      "falta de conocimiento.\n");
    tell_room(ENV(caster),caster->QCN+" sufre una desconcentracion de ultima "
      "hora cuando se da cuanta que le falta el componente esencial para este "
      "hechizo y pierde el hechizo.\n",caster);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  tell_object(caster,"Finalizas tu hechizo y un aura de oscuridad rodea el arma.\n");
  
  ob=all_inventory(caster);
  for (j=0;j<sizeof(ob);j++)
  {
    if ( ob[j]->query_name()=="garra de dragon" ||
         ob[j]->query_name()=="cabeza de hydra" ||
         ob[j]->query_name()=="tentaculo de kraken" ||
         ob[j]->query_name()=="cuerno de minotauro" )
    { 
      ob[j]->dest_me();
      dados++;
    }
  }

  all = target->query_held_ob();
  
  for(i=0;i<sizeof(all);i++)
    if(all[i]->query_weapon())
    {
      if(!all[i]->query_property("maldita"))
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
          
          tiradas=(int)caster->QL/6*dados/2;
          target->add_property("maldita",tiradas);
          target->adjust_enchant(-tiradas);
          if (basico) basico->dest_me();
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
  }
  return 1;
}
