int do_introduction(object a, object b) {

   if (b->query_recognize(a->query_name()))
        return 0;

   set_actor( a );
   set_target( b );
   set_listener( a );
   msg( "~CACTYou introduce yourself to ~targ.~CDEF" );
   a->msg_observers( "~CACT~Name ~verbintroduce ~refl to ~targ.~CDEF" );
   set_actor( a );
   set_target( b );
   set_listener( b );
   msg_object(b, "~CACT~Npos name is \"" + a->query_cap_name() + "\".~CDEF");
   b->add_recognize( a->query_name() );
   return 1;
}

int main( string who ) {
   object *oblist, unk, ob;

   if(stringp(who) && strstr(who, "to ", 0) < 0) {
      who="to "+ who;
   }

   if( !who || (sscanf(who, "to %s", who) != 1 && sscanf(who, "myself to %s", who) != 1 && sscanf(who, "me to %s", who) != 1) ) {
      notify_fail("To whom are you introducing yourself? Use 'introduce to <whomever>'\n");
      return 0;
   }

   unk = this_player();
   who = lower_case(who);

   if (who == "all") {
      int x;
      oblist = all_inventory(environment(this_player()));
      foreach (ob : oblist)
      if (ob->query_is_player() && ob != unk)
         x += do_introduction(unk, ob);

           if (!x)
            msg("There is nobody here to introduce yourself to!");
         return 1;
   } else if( !(ob = single_present(who, environment(this_player()), ({ this_player() }))) ) {
      notify_fail("I'm not sure who you mean by \"" + who + "\"\n");
      return 0;
   }

   if (unk == ob) {
      msg("If you're needing to introduce yourself to yourself, you should remember Sammy Jankis.");
      return 1;
   }

   if (!do_introduction(unk, ob)) {
      set_target(ob);
      msg("~Prot already knows who you are.");
   }

   return 1;
}
