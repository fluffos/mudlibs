/* Origial Design: Mobydick
// Recoded By: Nightmask@Nightfalls Keep
// Date: August somthing 1997
// Purpose: Just another thief ability to piss off Ilzarion.
// Side Note: Lick my ball sack. :)
*/
#include <money.h>
#include <move.h>
#include <rogues.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_steal(string str) {

   object ob, victim, invis_ob ;
   int theft_chance, detect_chance, stat_mod;
   int targ_lvl_mod = 0;
   int res ;
   string tmp, type, obname, victname ;
   
   if (TP->query_level("thief") < 10) {
     write("You are not yet skilled enough.\n");
   return 1;
  }

   if (!str) {
     write ("Steal what from who?\n");
   }
/*
ilz saiz you dont need to be invis!
   if (TP->query("invisible") == 0) {
     write("You must be hidden to attempt this ability.\n");
   return 1;
  }
*/

 if(this_player()->query("stop_attack")) {
   write("You are too busy to do that!\n");
   return 1; }

   if(!this_player()->query("vision")) {
   write("Steal what?  You can't see anything!\n");
   return 1; }
 
   if(this_player()->query_attackers()) {
   write("You are too busy with the battle to try to steal anything.\n");
   return 1; }
 
   if (sscanf(str,"%s from %s", obname, victname)!=2) {
     write ("Do what to who for how many cookies?\n");
   return 1; }

   ob = environment(this_player());
   if (!ob) {
      notify_fail("There's nothing to steal in the void!\n");
      return 0;
   }

   victim = present(victname, ob);
   if (!victim || !living(victim)) {
	notify_fail ("There's no one here by that name.\n") ;
	return 0 ;
   }

    if (victim==this_player())  {
	notify_fail ("You can't steal from yourself!\n") ;
	return 0 ;
    }

   this_player()->block_attack(2) ;
      
   ob = present(obname,victim) ;
   if (!ob && !(obname == "coins")) {
         if ((int)environment(this_player())->id(str)) {
            notify_fail("You can't take that!\n");
            return 0;
          }
         notify_fail("What " + str + "?\n");
         return 0;
         }
if (!(obname == "coins")){
    if ((int)ob->query("prevent_drop")==1) {
	notify_fail ("You can't steal that!\n") ;
    	return 0 ;
    }
    if ((int)ob->query("wielded")==1){
        notify_fail ("You expect to get away with stealing a wielded item?\n");
        return 0;
    }
    if ((int)ob->query("equipped")==1){
        notify_fail("You expect to get away with stealing an equipped item?\n");
        return 0;
    }
   }
   theft_chance = TP->query_level("rogue") * 3;
   targ_lvl_mod = victim->query_level();
   switch(TP->query("stat/dexterity")) {
     case 0..8 : stat_mod = -20; break;
     case 9 : stat_mod = -15; break;
     case 10 : stat_mod = -10; break;
     case 11 : stat_mod = -5; break;
     case 12..16 : stat_mod = 0; break;
     case 17 : stat_mod = 5; break;
     case 18 : stat_mod = 10; break;
     case 19 : stat_mod = 15; break;
     default : stat_mod = 20; break;
   }


   theft_chance = theft_chance + stat_mod - targ_lvl_mod;

   if (wizardp(victim) || random(100)>theft_chance){
	write ("You try to steal the item, but you are not successful.\n") ;

        if(wizardp(victim)) return 1;

       detect_chance =  ((3 * victim->query_level() ) -  TP->query_level("rogue"));

       if (random(100)<detect_chance) return 1;
	
	if (this_player()->query("invisible")) this_player()->set("invisible", 0);
	this_player()->do_new();
   	invis_ob = (present("#HIDE_OB#", this_player()));
	if(invis_ob) invis_ob->remove();

	write ("A fight begins!\n") ;
	tell_object( victim , (this_player()->query("cap_name")+" tried to steal from you!\n") ) ;
	victim->kill_ob(this_player()) ;
	TP->block_attack(2);
	TP->set("no_move", 2);
write("A fight begins!\n");
      return 1 ;
   }
if (obname == "coins"){
	theft_chance = (TP->query_level() * (random(100)+101));
	if (victim->query("wealth") < theft_chance)	theft_chance = (victim->query("wealth"));
	write ("You steal "+theft_chance+" coins from "+victim->query("cap_name")+"!\n");
	TP->credit(theft_chance);
	victim->debit(theft_chance);
	}else{
    
      res = (int)ob->move(this_player());
      if (res == MOVE_OK) {
	write ("You steal "+ob->query("short")+"!\n") ;
         }
      if (res == MOVE_NOT_ALLOWED)
         write("You can't do that.\n");
      else if (res == MOVE_NO_ROOM)
	 write("You don't have enough room to carry that.\n") ;
      else if (res == MOVE_TOO_HEAVY)
	write("It is so heavy you cannot pick it up!\n") ;
}
// This is the formula for detection if the theft is successful.


        if (random(100)>detect_chance) return 1 ;
        	if (this_player()->query("invisible")) this_player()->set("invisible", 0);
	this_player()->do_new();
   	invis_ob = (present("#HIDE_OB#", this_player()));
	if(invis_ob) invis_ob->remove();

        write ("A fight begins!\n") ;
	tell_object(victim,this_player()->query("cap_name")+" stole "+ob->query("short")+" from you!\n") ;
        victim->kill_ob(this_player()) ;
        TP->block_attack(2);
	TP->set("no_move", 2);
        say ("A fight begins!\n") ;
      return 1 ;
}
