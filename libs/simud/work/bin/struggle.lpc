string query_action_name() { return "Struggle"; }

object get_first_obj(object ob) {
   object *obs;
   obs = all_present("grapple_ob", ob);
   if (!sizeof(obs))
      obs = all_present("entangle_ob", ob);
   if (sizeof(obs))
      return obs[0];

   return 0;
}

int main() {
   object obj = get_first_obj(this_player());
   if (!obj)
      return notify_fail("Nothing is restraining you that you can struggle against.\n");

   this_player()->push_action( ({ 500, this_object(), obj, ST_STANDING, 0 }) );
   return 1;
}

void on_action(object target, mixed param) {
   target = get_first_obj(this_player());
   object holder = target->query_holder();
   this_player()->add_endurance(target->query_dex_bonus());
   this_player()->add_readiness(-500 - target->query_strength() * 2);
   set_target(holder);
   if ( !holder || environment(holder) != environment(this_player()) ) {
      msg("~CBRTYou begin to struggle briefly before realizing that your assailant is no longer present.");
      target->do_release();
   } else if ( this_player()->stat_check("str", holder->stat_check("str")) ) {
      this_player()->msg_local("~CACT~Name ~verbbreak free from ~npot "+target->query_limb_name()+"!~CDEF");
      target->do_release();
   } else {
      this_player()->msg_local("~CACT~Name ~verbstruggle against ~npot hold!~CDEF");
      this_player()->set_action( -1, ({ 500, this_object(), target, ST_STANDING, 0 }) );
   }
}
