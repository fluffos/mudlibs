 
//	File	:  /std/body/track.c
//	Creator	:  Watcher@TMI  (03/28/93)
//
//	This file is inherited by /std/body, and allows living
//	objects to track other living objects.

int follow_other(object target, object where, string dir) {
   int prop, skill, tskill;

   if((object)this_object()->query_temp("track") != target || !dir) return 0;
 
   //  If this object can't see ... they can't very well track someone.
 
   if(!this_object()->query("vision"))  return 0;
 
   skill = (int)this_object()->query_skill("Wilderness");
   tskill = (int)target->query_skill("Wilderness");

   //	This is the probability formula to see if the track
   //	attempt succeeds.  I have not really tested it fully
   //	to see if it is accurate, so you may want to tweak
   //	it a bit, after you see tracking in a true setting.
 
   prop = 20 + skill*3 - tskill*2;

   if(random(100) > prop) {
   tell_object(this_object(), "You lose sight of " +
	(string)target->query("cap_name") + ".\n");
   if(!random(4))  this_object()->improve_skill("Wilderness", 1);
   this_object()->delete_temp("track");
   return 0; }
 
   this_object()->improve_skill("Wilderness", 1);   //  A little reward
 
   tell_object(this_object(),
	"You follow " + (string)target->query("cap_name") + " " + dir + ".\n");
 
   command( dir );
 
return 1; }

