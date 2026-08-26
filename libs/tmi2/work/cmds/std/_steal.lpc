// _steal.c
// Written by Mobydick, 11-5-92.
// Part of the TMI mudlib. Please leave this header here if you use it.
// This file was largely based on _get.c, originally written by Brian Leet
// and later extended by Sulam, Brian, and Mobydick.
// See _get.c for more comments.

#include <money.h>
#include <move.h>
#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_steal(string str) {

   object ob, victim ;
   int myskill, statmod, vskill, theft_chance, detect_chance ;
   int res ;
   string tmp, type, obname, victname ;
   
   if (!str) {
      return help();
   }
   //	Check to see if the user can see anything.
 
   if(!this_player()->query("vision")) {
   write("Steal what?  You can't see anything!\n");
   return 1; }
 
   if(this_player()->query_attackers()) {
   write("You are too busy with the battle to try to steal anything.\n");
   return 1; }
 
   if (sscanf(str,"%s from %s", obname, victname)!=2) {
      return help() ;
   }
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
   if (!ob) {
         if ((int)environment(this_player())->id(str)) {
            notify_fail("You can't take that!\n");
            return 0;
          }
         notify_fail("What " + str + "?\n");
         return 0;
         }
// If the victim can't drop it, then you can't steal it.
    if ((int)ob->query("prevent_drop")==1) {
	notify_fail ("You can't steal that!\n") ;
    	return 0 ;
    }
// If being wielded or worn, you can't steal it.
    if ((int)ob->query("wielded")==1){
        notify_fail ("You expect to get away with stealing a wielded item?\n");
        return 0;
    }
    if ((int)ob->query("equipped")==1){
        notify_fail("You expect to get away with stealing an equipped item?\n");
        return 0;
    }
   myskill = this_player()->query_skill("Theft") ;
   statmod = this_player()->query("stat/Dexterity") ;
   myskill += statmod ;
   vskill = (int)victim->query_skill("Theft") /2 ;
   statmod = victim->query("stat/Dexterity") ;
   vskill += statmod;

// This is the chance of success formula.

       theft_chance = 10 + myskill*2 - vskill ;

//Also do not want people stealing from wizards...
   if (wizardp(victim) || random(100)>theft_chance){
	write ("You try to steal the item, but you are not successful.\n") ;

// You can only gain skill by stealing from monsters, not players. This
// prevents players from boosting their skills by sitting around stealing
// from one another for hours.
	if (!userp(victim)) {
                this_player()->improve_skill("Theft",5);
	}

//We don't want wizards to get into combat, so we make it look like
//the attempt was not noticed.
        if(wizardp(victim)) return 1;
// This is the formula for detection if the theft is unsuccessful.

	detect_chance = 50 - myskill*2 + vskill ;

	if (random(100)>detect_chance) return 1 ; 
	write ("A fight begins!\n") ;
	tell_object(victim,this_player()->query("cap_name")+" tried to steal "+ob->query("short")+" from you!\n") ;
	victim->kill_ob(this_player()) ;
	say ("A fight begins!\n") ;
      return 1 ;
   }

// If we get here, he succeeded. Again, you only get skill improvement by
// stealing from monsters, not players.
	if (!userp(victim)) {
                this_player()->improve_skill("Theft",10);
	}
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

// This is the formula for detection if the theft is successful.

	detect_chance = 30 - myskill*2 ;

        if (random(100)>detect_chance) return 1 ;
        write ("A fight begins!\n") ;
	tell_object(victim,this_player()->query("cap_name")+" stole "+ob->query("short")+" from you!\n") ;
        victim->kill_ob(this_player()) ;
        say ("A fight begins!\n") ;
      return 1 ;
}

int
help() {
   write ("Command: steal\nSyntax: steal <item> from <victim>\n"+
        "This command will have your character try to steal the\n"+
	"item specified from your victim. You may or may not succeed,\n"+
	"and you may be detected in the attempt. If you are detected a\n"+
	"fight will begin, so be careful.\n") ;
  return 1;
}
/* EOF */
