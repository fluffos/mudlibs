string query_action_name() {
   return "Label";
}

int main(string arg) {
   string what, as;
   object ob;

   if (!arg || sscanf(arg,"%s as %s",what,as) != 2) {
      notify_fail("Usage: label <object> as <label>\n");
      return 0;
   }
   if (!ob=single_present(what,this_player())) {
      if (single_present(what,environment(this_player())))
         return notify_fail("You must be holding the "+what+" in order to label it.\n");
      else
         return notify_fail("I can't find any such item here.\n");
   }

   WALK_ACTION_PARAM(1000, ob, as);

   return 1;
}

void on_action(object ob, string as) {
   if ( environment( ob ) != this_player() ) {
      msg( "You must be holding the " + ob->query_name() + " to label it.\n" );
      return;
   }

   if (!ob->on_label(as)) {
      msg("You can't label "+ob->query_specific()+".\n");
      return;
   }

   set_target(ob);
   this_player()->msg_local("~CACT~Name ~verbmark a label on ~targ.~CDEF");
}
