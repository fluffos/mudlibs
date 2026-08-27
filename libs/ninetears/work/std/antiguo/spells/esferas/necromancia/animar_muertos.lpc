#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Animar muertos"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	NIVEL	3
#define	CANCION	"'morti elai aradi'"

#define SKEL	"/obj/chars/skeleton"
#define ZOMB	"/obj/chars/zombie"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_help_desc("Este hechizo da al hechicero el poder de invocar las fuerzas del mal "
     " para animar los muertos de una habitacion. El numero y tipo "
     "depende del nivel del hechicero y su providencia con la necromancia.  "
     "Formular este hechizo produce un efecto negativo en el alineamiento bueno "
     "de los clerigos.");
  set_target_type("none");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
   int level=caster->QL*POWER/2;

   if (caster->QTP("animate_dead_on"))
   {
      tell_object(caster,"No puedes animar otro muerto otra vez.\n");
      return -1;
   }

   target=find_match("cuerpos",ENV(caster));

   if (!sizeof(target))
   {
      tell_object(caster,"No hay ningun muerto para animar.\n");
      return -1;
   }
   
   if (!quiet)
   {
      tell_room(ENV(caster),MSG_CAN_R,caster);
      tell_object(caster,MSG_CAN_C);
   }

   tell_room(ENV(caster),caster->QCN+" susurra una plegaria arcana, y el muerto se levanta de su sepultura.\n",caster);

   for (int count=0;count<sizeof(target);count++)
   {
     target[count]->dest_me();
     if (count<level)
     {
       if(level>20)
       {
         target[count]=clone_object(ZOMB);
         target[count]->move(ENV(caster));
         level-=4;
       }
       else
       {
         target[count]=clone_object(SKEL);
         target[count]->move(ENV(caster));
         level-=2;
       }
       target[count]->set_aggressive(0);
       target[count]->do_command("follow "+caster->QN);
       target[count]->do_command("protect "+caster->QN);
       target[count]->set_join_fights(0);
     }
   }
   caster->adjust_align(1000);
   caster->ATP("animate_dead_on",1,100+level*10*POWER);
   call_out("wear_off",100+level*10*POWER,target);
   return NIVEL*100;
}

int wear_off(mixed target)
{
  for(int i=0;i<sizeof(target);i++)
    if(target[i]) target[i]->do_death();
}
