#include "animals.h"
inherit "/std/object";
int summon(string str, object me)
{
   int cost, min_level;
   int animal_hp, animal_gp;
   int wis_bonus;
   string ANIMAL;
   object animal, shadow, ob;
   if(!me) me=this_player();
   if(me->query_timed_property("KILLED_OWN_ANIMAL"))
   {
      notify_fail("Ningun animal escucho tu llamada. Vieron "
         "tu lado oculto y pensando que no eras una persona normal.\n");
      return 0;
   }
   if(me->query_alignment()>1000)
   {
      notify_fail("Yvendur no concede este poder a personas demoniacas.\n");
      return 0;
   }
   switch(str)
   {
      case "comadreja":
         min_level=3;
         cost=5;
         ANIMAL=WEASEL;
         animal_hp=4;
         animal_hp=4;
         break;
      case "halcon":
         min_level=6;
         cost=10;
         ANIMAL=HAWK;
         animal_hp=4;
         animal_gp=4;
         break;
      case "lobo":
         min_level=9;
         cost=15;
         ANIMAL=WOLF;
         animal_hp=6;
         animal_gp=6;
         break;
     case "jabali":
         min_level=12;
         cost=20;
         ANIMAL=BOAR;
         animal_hp=6;
         animal_gp=6;
         break;
      case "tigre":
         min_level=15;
         cost=25;
         ANIMAL=TIGER;
         animal_hp=8;
         animal_gp=8;
         break;
      case "oso":
         min_level=18;
         cost=30;
         ANIMAL=BEAR;
         animal_hp=10;
         animal_gp=10;
         break;
      default:
         cost=-1;
         break;
   }
   if(me->query_level()<min_level)
   {
      notify_fail("No puedes invocar este tipo de animal.\n");
      return 0;
   }
   if(cost==-1)
   {
      notify_fail("No puedes invocar este tipo de animal.\n");
      return 0;
   }
   if(me->query_gp()<cost)
   {
      notify_fail("Estas un poco cansado para invocar este "
         "animal ahora.\n");
      return 0;
   }
   if(sizeof(me->query_attacker_list()))
   {
      notify_fail("Las cosas estan algo calientes ahora para invocar animales.\n");
      return 0;
   }
   if(!environment(me)->query_outside())
   {
      notify_fail("No tienes animales a tu alrededor para poder invocarlos.\n");
      return 0;
   }
   if(me->query_static_property("animal_summoned"))
   {
      notify_fail("Solo puedes controlar un animal a la vez.\n");
      return 0;
   }
   wis_bonus=(me->query_wis()-15)*me->query_level();
   if(wis_bonus<0)
      wis_bonus=-(me->query_level());
   me->adjust_gp(-cost);
   if(!file_exists(ANIMAL))
   {
      notify_fail("Invocar que ????\n");
      return 0;
   }
   me->add_static_property("animal_summoned",1);
   animal=clone_object(ANIMAL);
   animal->move(environment(me));
   animal->set_my_player(me);
   animal->set_max_hp(roll(me->query_level(),animal_hp)+wis_bonus);
   animal->set_max_gp(roll(me->query_level(),animal_hp)+wis_bonus);
   animal->set_thac0(me->query_thac0());
   ob=clone_object(OBJECT);
   ob->move(me);
   ob->animal_setup(me,animal,animal_hp,animal_gp);
   animal->set_hp(animal->query_max_hp());
   animal->set_gp(animal->query_max_gp());
   tell_room(environment(me),me->query_cap_name()+" invoca a "+
      animal->query_short()+" a su lado.\n",
      me);
   write("Invocas a "+animal->query_short()+" a tu lado.\n");
   return 1;
}
string help()
{
   return
      "Animal      Nivel  PG  Ataque  Defensa   PV   Especial\n"
      "Comadreja     3    5   *        ***      *     No (no puede proteger)\n"
      "Halcon        6    10  **       ***      *     Ciego (No puede proteger)\n"
      "Lobo          9    15  **       *        **    No\n"
      "Jabali        12   20  ***      *        **    No\n"
      "Tigre         15   25  ***      **       ***   Dificil de sorprender\n"
      "Oso           18   30  ****     **       ****  Abrazo del oso\n"
      "\n"
      "Ordenes validas:  sintaxis:  ordenar <animal> a <comando> <objetivo>\n"
      "abrazo (Solo osos)\n"
      "seguir/perder\n"
      "matar\n"
      "proteger/desproteger (Comadrejas y halcones son poca proteccion)\n"
      "parar\n"
      "\n";
}
