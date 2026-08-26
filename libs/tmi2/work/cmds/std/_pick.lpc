// _pick.c
// Written by Deathknight,  12-10-92.
// Mobydick added support for picking door locks, 1-21-92.
// Part of the TMI mudlib. Please leave this header here if you use it.
// This file was largely based on _steal.c, written by Mobydick
// See _steal.c for more comments.
// Moby appreciates the credit :)
// Watcher updated the door check code a bit, 03-28-93.

#include <mudlib.h>
inherit DAEMON ;

// Number of seconds to wait after failure until they can try the lock again.
#define NEXT_PICK  120

string help();

int cmd_pick(string str) {

   mixed *locks ;
   object env ;
   mapping exits, doors ;
   mixed ob ;
   int myskill, vskill, pick_chance, i, *lock_time;
   int doordum ;   // 1 if picking a door lock, 0 if a container lock.
   string dir ;
   
   if (!str) {
      return notify_fail(help());
   }

   //	Check to see if the user can see what they are doing.
 
   if(!this_player()->query("vision")) {
   write("Pick what?  You can't see anything!\n");
   return 1; }
 
   env = environment(this_player());
 
   if (!env) {
      notify_fail("There aren't any doors in the void to pick!\n");
      return 0;
   } 
   if(str == "lock" && sizeof(env->query("doors")))
	str = "door";
 
   ob = present(str, environment(this_player())) ;
   if (!ob) {
       ob = present (str, this_player());
   }
   if(ob && (int)ob->query("prevent_get")) {
   notify_fail("You can't get that object.\n");
   return 0; }
 
   if (!ob || living(ob)) {
// We didn't find a container, must be a door we're trying to pick.
 
      if(str != "door" && sscanf(str, "%s door", dir) != 1) {
         notify_fail ("There's nothing here by that name.\n") ;
         return 0 ;
      }
      env = environment(this_player()) ;
      exits = env->query("exits") ;
 
      doors = env->query("doors") ;
 
      if(!dir) {
        if(sizeof(doors) > 1) {
        notify_fail("Which door do you wish to pick?\n");
        return 0; }

        dir = keys(doors)[0];
      }
 
      if (member_array(dir,keys(doors))==-1) {
	 notify_fail ("There is no door in that direction.\n") ;
	 return 0 ;
      }
      if (doors[dir]["status"] != "locked") {
	 notify_fail("The door is not locked.\n") ;
	 return 0 ;
      }
// All door locks have skill of 5.
      vskill = 5 ;
      doordum = 1 ;

      ob = dir+env->query("short") ;
   } else {
      vskill = ob->query("lock");
      doordum = 0 ;
   }
   this_player()->block_attack(2) ;
   myskill = this_player()->query_skill("Theft") ;
   if (!vskill) {
       write ("No lock to pick on that object!!!\n");
       return 1;
   }
   if (vskill == -1) {
       write ("Already unlocked!\n");
       return 1;
   }

// Make sure they haven't tried recently...

   locks = (mixed *)this_player()->query("locks_failed");
   if (!locks)  locks = ({ });
   lock_time = (int *)this_player()->query("locks_timed");
   if (!lock_time)  lock_time = ({ });
   for(i=0; i<sizeof(locks); i++) {
       if (locks[i] == ob && lock_time[i] > time()) {
           write ("You can't pick that particular lock again so soon!\n");
           return 1;
       }
   }
   
// This is the chance of success formula.

    pick_chance = 20 +myskill*3 - vskill*2 ;

   if (random(100)>pick_chance) {
	this_player()->improve_skill("Theft", 5) ;
	write ("You attempt to pick the lock, but are unsuccessful.\n") ;

       for(i=0; i<sizeof(locks); i++) {
           if (lock_time[i] <= time()) {
               locks[i] = ob;
               lock_time[i] = time() + NEXT_PICK;
               this_player()->set("locks_failed", locks);
               this_player()->set("locks_timed", lock_time);
               return 1;
           }
       }
       locks += ({ ob });
       lock_time += ({ time() + NEXT_PICK });
       this_player()->set("locks_failed", locks);
       this_player()->set("locks_timed", lock_time);
       return 1;
	}

// Success!
   this_player()->improve_skill("Theft", 10);
   if (doordum) {
      write ("You hear an audible \"Click!\" as the lock opens.\n") ;
      say (this_player()->query("cap_name")+" unlocks the "+dir+" door.\n") ;
      env->set_status(dir,"closed") ;
      env->update_link(dir) ;
      return 1 ;
   } else {
      ob->pick_lock(-1);
      if (ob->query("lock") > 0) {
          write ("The lock clicks, but it still doesn't look open to you...\n");
          return 1;
      }
      write ("You hear an audible 'click' as the lock opens!\n");
      return 1;
   }
}

string help() {
   return("Syntax: pick [lock on|in] <object>\n\n"+
   "This command will have your character try to pick the lock on\n"+
   "the object specified. You may or may not succeed. If you fail,\n"+
   "you won't be able to pick that particular lock again until\n"+
   "two minutes have passed.\n"+
  "\nSee also: lock, unlock, open, close\n");
}
/* EOF */
