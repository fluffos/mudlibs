int main(string arg) {
   object who = find_player(arg), obj;
   if (!who) {
      msg("You can't find anyone with that name :)");
      return 1;
   }
   foreach (obj : all_inventory(who)) {
      int x = obj->query_max_condition();
      if (x)
         obj->set_condition(x);
   }
   set_actor(this_player());
   set_target(who);
   msg_object(who,"~CBRT~Name has repaired all of your equipment.~CDEF");
   msg("~CBRTYou have repaired all of ~post equipment.~CDEF");
   return 1;
}
