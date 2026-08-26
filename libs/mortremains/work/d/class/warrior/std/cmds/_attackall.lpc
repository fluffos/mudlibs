// DOne by Ilzarion

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>


int cmd_attackall() {
   object ob, *targets, weapon;
   int dmj, dmin, dmax, damage, i;
   int multiplier;
   int level;   //Forgot this, too.
   string type;

  
  if ((this_player()->query_skill("All Around Attack"))<1){
    write("You must have the proficiency first!\n");
      return 1;
   }

  targets = this_player()->query_attackers();

   if (!targets) {
     write("There is no one around you!\n");
      return 1;
   }

   if (TP->query("stop_attack")) {
	   write("You are too busy to make use of that!\n");
      return 1;
   }

   weapon = (object)this_player()->query("weapon"+(this_player()->query("handedness")));

   if (!weapon) {
      write("You can't do that with your bare hands!\n");
      return 1;
   }

   type = (string)weapon->query("damage_type");

  // dmj = weapon->query("damage");
   
	TP->block_attack(2);
   level = TP->query_level("warrior");
	dmj = ((level - 14)/3);
	if (dmj == 0) dmj = 1;
   dmin = dmj;
   dmax = (8*dmj);

   damage = random(1 + dmax - dmin) + dmin;
  // write("Rolled: "+damage+"\n");
  if (random(20) == 0) damage *= 2;
//write("after crit: "+damage+"\n");
  damage+=PROPERTY_D->query_str_dam(this_player());

 
         ob = (TP->query_current_attacker());                                             
 if (ob && this_player()->query_hit(ob)){       
	 for(i=(sizeof(targets)-1);i>0;i--){

	 dmin = targets[i]->query("weap_resist");
	 dmax = (weapon->query("enchantment")+1);
	 
	 if (dmax > dmin){

  if (damage <= targets[i]->query("hit_points")) {
   tell_object(targets[i], TPN+" Spins around in a flurry of attacks!.\n"
);
   write("You feel your weapon bite into an opponent.\n");
   say(TPN+" All around attacks!", ({ targets[i], this_player() }) );
   } else {
      write("You slay "+targets[i]->query("cap_name")+" in your flurry of attacks!\n");
     tell_object(targets[i],wrap("You are pummeled and killed by multiple blows."));
      say(wrap(TPN+" Rends "+targets[i]->query("cap_name")+" into chunks."), ({ TP, targets[i] }) );

   }
   
   targets[i]->receive_damage(damage, type, this_player());
  // ob->kill_ob(this_player());
   }else{
 write("You weapon is useless against "+targets[i]->query("cap_name")+"!\n");
    }
	}

   return 1;
}else{

  write("You miss!\n");
     tell_object(targets[0],wrap("Your opponent flails about wildly!"));
      say(wrap(TPN+" Attempts to kill "+targets[0]->query("cap_name")+" in one blow!, and misses."), ({ TP, targets[0] }) );                 
   return 1;
   }
   }