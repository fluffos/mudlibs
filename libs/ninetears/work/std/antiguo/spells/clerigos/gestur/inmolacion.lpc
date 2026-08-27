#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Inmolacion"
#define	NIVEL   8		
#define	ESCUELA	({""})
#define	ESFERA	({"gestur"})
#define	CANCION	"'deus me ignis'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("none");
  set_range(0);
  set_help_desc("Este hechizo canaliza TODO el poder del clerigo en un brutal hechizo de destruccion. "
                "Su cuerpo se inmola, convirtiendolo en fuego que lo destruye todo, a amigos y enemigos, "
                "incluso tu propio cuerpo. Es un hechizo que hay que usar con cuidado..\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({ "round1","round2"}));
}

int query_gp_cost()
{
   return 20;
}

// NUEVO by Tyrael - Feb '02 - Si la persona no esta en tu room,
// como vas a saber a quien tienes que atacar?
void do_damage(object caster,int gps,object room,int adjust)
{
   object *persons, caster_env;
   int damage;
   int i;
  
  damage=gps*(100-(30*(adjust-1)))/100;  
  damage*=3/2;
  persons= filter_array(all_inventory(room),"filter_living");
	caster_env = ENV(caster);
  for(i=0;i<sizeof(persons);i++)
  {
      persons[i]->destruct_mirror_shadow();
      persons[i]->destruct_stoneskin_shadow();
      persons[i]->destruct_hokemjleaf_shadow();
      if(persons[i] != caster)
      {
	persons[i]->spell_damage(damage,"fuego",query_sphere(),100,caster);
	if (ENV(persons[i]) == caster_env)
		persons[i]->attack_by(caster);
      }
      else	// si no ponemos el caster peta el jarbit al hacer la
		// saving_throw, y ahora ya hay "soporte" para suicidio =)
	persons[i]->spell_damage(damage*2,"fuego",query_sphere(),100,caster);
  }
 }

object *calc_salidas(object *room)
{
   int i,j;
   object *room2;
   
   room2= ({ });
   for (i=0;i<sizeof(room);i++)
   {
      for(j=1;j<sizeof(room[i]->query_dest_dir());j+=2)
      {
        room2+=({ load_object((room[i]->query_dest_dir())[j]) });
      }
   }
   return room2;
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if(!quiet)
  {
  tell_object(caster,MSG_CAN_C);
  tell_room(ENV(caster),MSG_CAN_R,caster);
  }
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int gps;
  object *rooms;
  object *rooms2;
  int j;
  int i;
 
  int damage;
  tell_object(caster,"Elevas tus manos al cielo, inmolandote a tu dios.\n");
  tell_room(ENV(caster),caster->query_cap_name()+" eleva sus manos al cielo "
            "convirtiendo su cuerpo en fuego y las llamas surgen consumiendo "
	    "todo a su paso, incluso a TI!\n",caster);
  
  gps=caster->query_gp();
  caster->adjust_gp(-gps);

    //Eso es pa su propia room, ahora a ver las colindantes
  rooms= ({ ENV(caster) });

  do_damage(caster,gps,ENV(caster),1);
  for(i=1;i<3;i++)
  {
    rooms2=calc_salidas(rooms);
    //Miramos una por una las salidas de nivel 2;
    for(j=0;j<sizeof(rooms2);j++)
    {
      if(member_array(rooms2[j],rooms)==-1)
      {
         tell_room(rooms2[j],"Unas llamas divinas te envuelven, quemandolo todo a su paso, incluso a TI!\n");
         do_damage(caster,gps,rooms2[j],i+1);
         rooms+=({ rooms2[j] });
      }
    }
  } 
  return 0; 
}

int filter_living(object ob)
{
    return living(ob);
}
