// Mobydick added an ANSI reset to this, 12-17-94.
// The idea is to prevent people from screwing up the color schemes of
// others with their text. I'm not sure if this is going to work. Feel
// free to remove it if it doesn't, as long as you install something
// else that works Better.

#include <ansi.h>
varargs void say(string msg, mixed exclude) {
   object me;

   if (this_player()) me = this_player();
   else me = previous_object();

  // msg+= NOR;  // This gave lots of ansi chars,
  // for people with no ansi handling.
 
   if(objectp(exclude))
      exclude = ({ me, exclude });
   else if(pointerp(exclude))
     exclude += ({ me });
   else if (!exclude)
     exclude = ({ me });
   message("say", msg, environment(me), exclude);
}
