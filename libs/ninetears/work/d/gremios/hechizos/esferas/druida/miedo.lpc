// Translated by Osucaru
// Paris. Jun'98. No afecta a los No-Muertos.

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Miedo"
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({""})
#define	NIVEL	5
#define	CANCION	""
#define	TIPO	"psionic"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo hara que todos los que estan en la zona "
     "que no tengan defensas contra el hechizo del miedo estaran afectados "
     "por los efectos de este hechizo tantos turnos como niveles tenga el "
     "que lo formule.\n"
     "La cantidad de miedo que provocas en los personajes dependen del nivel "
     "el carisma y la resistencia a ataques psiquicos que el objetivo tenga.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i;
  string str;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),"Una ola de luz plateada fluye de "+caster->QCN+
       ", creando una oscuridad fantasmal en el resto de la zona.\n",caster);
    tell_object(caster,"Llamas a los dioses ante los dioses y una ola de luz plateada fluye de ti.\n");
  }

  for (i=sizeof(target)-1;i>=0;i--)
  {
    if (target[i]->query_race_name()!="No-muerto")
    {
      if(target[i]->query_property("no_fear"))
        tell_object(caster,"Tu hechizo parce no afectar a "+target[i]->query_short()+".\n");
      else  
      {
        damage=-MAX(-90,fix_damage(caster,target[i],-roll(3,caster->query_cha())));
        target[i]->ATP("fear",damage,caster->QL*(POWER+1));	
        
        tell_room(ENV(caster),caster->QCN+" envuelve a "+target[i]->query_short()+" en el seno de un aura de oscuro terror.\n",({caster,target}));
        tell_object(caster,"Envuelves a "+target[i]->query_short()+" en un aura del mas puro terror!\n");
        tell_object(target[i],"La oscuridad fantasmal invocada por "+caster->QCN+ 
              " te recubre mientras el horror invocado de tiempos inmemorables "
              "profundiza en lo mas hondo de tu alma.\n");
        target[i]->set_wimpy(damage);	
        target[i]->attack_by(caster);
       }
    }
    else tell_room(ENV(target[i]),target[i]->query_name()+" no se ve afectado por el hechizo porque es un No Muerto!!\n");
  }
  return 0;
}
