varargs void say(string msg, mixed exclude) {
   object me, *list;

   if (this_player()) me = this_player();
   else me = previous_object();
 
   if(objectp(exclude))
      exclude = ({ me, exclude });
   else if(pointerp(exclude))
     exclude += ({ me });
   else if (!exclude)
     exclude = ({ me });

   list = all_inventory(me);
   list += ({ environment(me) });

   message("say", msg, list, exclude);
}
