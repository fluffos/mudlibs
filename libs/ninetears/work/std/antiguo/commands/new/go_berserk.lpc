
// Rabia , rabia 2 , rabia 3 y rabia enfocado por Yvendur Dec 99

/*  Adapted from the original Berserk command, coded by Timion.
 *  Marauder, 11/14/95/
 */
#include "tweaks.h"
#define LOCK_PROP "flipped"

int num_atacantes;

void attack_all(object ob);
int allow_attack(object who, object me);
int attack_one(string arg,object ob);
void end_berserk(object ob); 

int go_berserk(string str,object x)
{
   object me; 
   int BONUS, i;
   int ACBONUS;
   int COUNT;
   int TIME;
   if(x) me = x;
   else me = this_player();

   COUNT = me->query_property(LOCK_PROP);
   
   
   if(me->query_gp() <= 1)
   {
    tell_object(me,"Estas demasiado cansado para enrabiarte.\n");
    return 1;
   }
   switch(COUNT)
   {
   case 0:
       BONUS=((int)me->query_level()/3)+1;
    ACBONUS = (BONUS - ((me->query_dex())/3));
    me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
      me->adjust_tmp_damage_bon(BONUS);
      me->adjust_tmp_tohit_bon(BONUS*2);
      me->adjust_tmp_ac_bon(-ACBONUS);
if(me->query_gp() >= 25)
  {
   me->adjust_gp(-25);
   TIME = 25;
  }
else {
  TIME = me->query_gp();
   me->adjust_gp(-TIME);
 }
      me->add_timed_property(LOCK_PROP,1,TIME);
      if(!str)
        { attack_all(me); num_atacantes=2; }
      else
         if(me->query_level()>=35 && str!=me->query_name())
            { attack_one(str,me); num_atacantes=1; }
         else
            if(str!=me->query_name())
               { attack_all(me); num_atacantes=2; }
              else
               {  notify_fail("Estas loco?\n");
                  return 0;
               }
       if(num_atacantes==0)
          return 0;	       
	    	       
   break;
   case 1:
   if( ( (me->query_gp()) >= 50) && ((me->query_level())>=15) )
   {
       BONUS=((int)me->query_level()/2)+2;
    ACBONUS = (BONUS - ((me->query_dex())/2));
    me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
       me->adjust_gp(-50);
       me->adjust_tmp_damage_bon(BONUS);
       me->adjust_tmp_tohit_bon((int)BONUS*2);
       me->adjust_tmp_ac_bon(-ACBONUS);
       me->add_timed_property(LOCK_PROP,2,40);
    }
    else tell_object(me,"Estas demasiado cansado para conseguir enfadarte.\n");
    break;
    case 2:
    if( ((me->query_gp()) >= 100) && ((me->query_level()) >= 25 ) )
    {
        BONUS=((int)me->query_level()/1.75)+5;
     ACBONUS = (BONUS - (me->query_dex()) );
    me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
        me->adjust_gp(-100);
        me->adjust_tmp_damage_bon(BONUS);
        me->adjust_tmp_tohit_bon(BONUS*2);
        me->adjust_tmp_ac_bon(-ACBONUS);
        me->add_timed_property(LOCK_PROP,3,100);

     if(num_atacantes==2)	
     {  write("\n%^RED%^Pierdes el control por completo y atacas incluso a tus amigos.%^RESET%^"
      "\n\n");
       tell_room(environment(me),"\n"+me->query_cap_name()+" pierde "+
        "el control por completo.  %^BOLD%^%^RED%^Sera mejor que te vayas rapido !%^RESET%^"
        "\n\n",me);
     }
     else
      { write("\n%^RED%^Pierdes la cabeza por completo pero atacas controladamente a tu enemigo.%^RESET%^"
	      "\n\n");
	tell_room(environment(me),"\n"+me->query_cap_name()+" pierde "+
	"la cabeza por completo. %^BOLD%^%^RED%^Sus ataques estan controlados"
	" !!%^RESET%^\n\n",me);
      }
      	         	
    }
    else tell_object(me,"Te falta mas anedralina para enrabiarte mas.\n");
    break;
    default:
        tell_object(me,"Estas echando espuma por la boca ya y no puedes ser "
         "mas salvaje.\n");
    break;
    }
    return 1;
}
int allow_attack(object who, object me)
{
     if(who == me) return 0;
//     tell_object(me,"checking "+(string)who->query_cap_name()+" ");
     if(!who->query_alive() ) return 0;
//     tell_object(me,"alive ");
     if((int)me->query_property(LOCK_PROP) == 0 ) return 0;
//     tell_object(me,"I'm berserked ");
    if(who->query_property("no_guild")) return 1;
     if(who->query_pacify_spell()) return 0;
//     tell_object(me,"not pacified ");
     if(who->query_invis()) return 0;
//     tell_object(me,"not invis ");
     if( (int)who->query_hide_shadow() > ((int)me->query_level()/2 + (int)me->query_int()) ) return 0;
//     tell_object(me,"and not hidden, kill it ");
     if((int)me->query_property(LOCK_PROP) == 3 ) return 1;
// If you are frothing, even the people you protect get it.
     if(who->query_protector() == me) return 0;
//     tell_object(me,"not being protected ");
     return 1;
}

attack_all(object ob)
{
  object *cows;
  object *guards;
  int y;
  int x;
  int COUNT;

   if(!ob) return;

   ob->set_wimpy(0);

   if((int)environment(ob)->query_property("noguild")) return;
   if((ob->query_dead())) return;
 
   cows=all_inventory(environment(ob));
 
   for(x=0; x <sizeof(cows); x++)
   {
        if(allow_attack(cows[x],ob)) ob->attack_ob(cows[x]);
   }
   COUNT = ob->query_property(LOCK_PROP);
   if(ob->query_attacker_list())
   {
       switch(COUNT)
       {
       default:
            end_berserk(ob);
            return;
       break;
       case 1:
            tell_room(environment(ob),ob->query_cap_name()+" corta y desgarra "
            "con una rabia increible.\n",ob);
            tell_object(ob,"Te enrabias, cortas y desgarras a cualquier cosa "
            "que se mueva.\n");
        break;
        case 2:
            tell_room(environment(ob),ob->query_cap_name()+" ataca "
            "a todo el mundo encolerizado, provocando danyos increibles.\n",ob);
            tell_object(ob,"Comienzas a ponerte rojo de colera, y danyas masivamente "
            "todo lo que esta a tu alrededor.\n");
        break;
        case 3:
            tell_room(environment(ob),ob->query_cap_name()+" esta expulsando "
            "espuma de la boca en un imparable ataque de rabia.\n",ob);
            tell_object(ob,"Tu poderosa colera asola todo a tu paso, y te "
            "enfureces en un ataque de venganza extremo.\n");
        break;
        }
    }
    call_out("attack_all",5,ob);
}

int attack_one(string arg, object ob)
{
  object *cows;
  object *guards;
  string atacado;
  object ob_atac;
  string *alias;
  
  int y,i,j;
  int x;
  int COUNT;

   if(!ob) return 0;

   ob->set_wimpy(0);

   if((int)environment(ob)->query_property("noguild")) 
   { tell_object(ob,"Imposible enrabiarse aqui.\n"); 
      return 0;
   }      
   if((ob->query_dead())) { notify_fail("Estas muerto. No puedes hacer esto.\n"); return 0; }


   
   cows=all_inventory(environment(ob));
   if(sizeof(cows))
     { for(i=0;i<sizeof(cows);i++)
         {
	  alias=cows[i]->query_alias();
	  if(sizeof(alias))
	     for(j=0;j<sizeof(alias);j++)
	        if(alias[j]==arg||arg==cows[i]->query_name())
		   {
		     ob_atac=cows[i];
		     atacado=arg;
         	   }
	 }
	 
     }	 
   
   if(!ob_atac)
       {  tell_object(ob,"Enfocar tu rabia contra quien?\n");
          end_berserk(ob);
          num_atacantes=0;
          return 0;
       }
            
   if(ob_atac->query_dead())
        {  tell_object(ob,"Tu objetivo se esfuma tras tus poderosos golpes.\n");
           end_berserk(ob);
        }

   if(allow_attack(ob_atac,ob)) ob->attack_ob(ob_atac);

   COUNT = ob->query_property(LOCK_PROP);
   if(ob->query_attacker_list())
   {
       switch(COUNT)
       {
       default:
            end_berserk(ob);
            return;
       break;
       case 1:
            tell_room(environment(ob),ob->query_cap_name()+" corta y desgarra "
            "con una rabia increible.\n",ob);
            tell_object(ob,"Te enrabias, cortas y desgarras enfocando tu rabia "
            "hacia "+capitalize(atacado)+".\n");
        break;
        case 2:
            tell_room(environment(ob),ob->query_cap_name()+" ataca "
            "a "+capitalize(atacado)+" encolerizado, provocandole danyos increibles.\n",ob);
            tell_object(ob,"Comienzas a ponerte rojo de colera, y danyas masivamente "
            "a "+capitalize(atacado)+" con varias rafagas sangrientas de golpes.\n");
        break;
        case 3:
            tell_room(environment(ob),ob->query_cap_name()+" esta expulsando "
            "espuma de la boca en un imparable ataque de rabia.\n",ob);
            tell_object(ob,"Tu poderosa colera asola todo a tu paso, y te "
            "enfureces en un ataque de venganza extremo enfocando todos tus golpes en "+capitalize(atacado)+"\n");
        break;
        }
    }
    call_out("attack_one",5,atacado,ob);
}


end_berserk(object ob)
{
    tell_object(ob,"Comienzas a estar exhausto y no alargas mas tu rabia.\n");

   ob->adjust_tmp_ac_bon(-(ob->query_tmp_ac_bon()));
   ob->adjust_tmp_damage_bon(-(ob->query_tmp_damage_bon()));
   ob->adjust_tmp_tohit_bon(-(ob->query_tmp_tohit_bon()));
    if((int)ob->query_tmp_con() >= 0) ob->adjust_tmp_con(-1);
   ob->remove_timed_property(LOCK_PROP);

    
}
 
