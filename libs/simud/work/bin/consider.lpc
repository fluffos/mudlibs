string query_action_name() {
   return "Consider";
}

string compare_health(object player, object victim) {
   int php, pend, vhp, vend;
   int score;
   php = player->query_hp();
   vhp = victim->query_hp();
   pend = player->query_endurance();
   vend = victim->query_endurance();
   score = (vend - pend) + (vhp - php) * 2;
   if (score > 50)
      return "~Targ ~vertis way healthier than ~name.\n";
   if (score > 10)
      return "~Targ ~vertappear to be slightly healthier than ~name.\n";
   if (score > -10)
      return "~Targ ~vertseem about as healthy as ~name.\n";
   if (score > -50)
      return "~Name ~verbappear to be slightly healthier than ~targ.\n";
   return "~Name ~verbis way healthier than ~targ.\n";
}

string compare_stats(object player, object victim) {
   int pstr, pdex, pspd, vstr, vdex, vspd;
   int strength, speed;
   string buf;

   pstr = player->query_stat("str");
   pdex = player->query_stat("dex");
   pspd = player->query_stat("spd");
   vstr = victim->query_stat("str");
   vdex = victim->query_stat("dex");
   vspd = victim->query_stat("spd");

   strength = vstr - pstr;
   speed = ((vdex + vspd) - (pdex + pspd)) / 2;

   if (strength > 3) {
      if (speed > 3)
         buf = "~Targ ~vertis both stronger and faster than ~name.";
      else if (speed > -3)
         buf = "~Targ ~vertlook stronger than ~name.";
      else
         buf = "~Targ ~vertis stronger but slower than ~name.";
   } else if (strength > -3) {
      if (speed > 3)
         buf = "~Targ ~vertlook faster than ~name.";
      else if (speed > -3)
         buf = "~Targ ~verthave about the same build as ~name.";
      else
         buf = "~Targ ~vertlook slower than ~name.";
   } else {
      if (speed > 3)
         buf = "~Name ~verbis stronger but slower than ~targ.";
      else if (speed > -3)
         buf = "~Name ~verblook stronger than ~targ.";
      else
         buf = "~Name ~verbis both stronger and faster than ~targ.";
   }
   return buf + "\n";
}

string compare_wc(object player, object victim) {
   return "Sorry, you can't compare offensive potentials just yet...\n";
}

string analyze_armour(object victim) {
   return "Sorry, you can't analyze your enemy's armour just yet...\n";
}

string analyze_spellcasting(object victim) {
   return "Sorry, you can't analyze your enemy's magical powers quite yet...\n";
}

int main(string arg) {
   object ob = single_present(arg, environment(this_player()));
   if (!ob) {
      if( !arg )
         return notify_fail("What do you want to consider?\n");
      else
         return notify_fail("Nothing here matches \""+arg+"\".\n");
   }
   if (!ob->query_is_living())
      return notify_fail("This is an ex-parrot!\n");
   if (ob == this_player()) {
      msg("Yeah, you're you. You could probably beat yourself up, but only if you let yourself.");
      return 1;
   }
   this_player()->push_action( ({ 1000, this_object(), ob, ST_STANDING, 0 }) );
   return 1;
}

void on_action(object ob, string param) {
   int check;
   string buf = "~CDEF";

   check = this_player()->cached_skill_check(300, ob->query_name(), "combat.intuition",10,25,50,75,90);
   // Case fallthrough is intentional!
   switch (check) {
      case 5:
         buf = analyze_spellcasting(ob) + buf;
      case 4:
         buf = analyze_armour(ob) + buf;
      case 3:
         buf = compare_wc(this_player(),ob) + buf;
      case 2:
         buf = compare_stats(this_player(),ob) + buf;
      case 1:
         buf = compare_health(this_player(),ob) + buf;
         break;
      default: buf = "You are unable to determine anything about ~targ.\n";
   }

   set_target(ob);
   this_player()->msg_local("~CACT~Name ~verbfocus intently on ~targ.~CDEF");
   set_actor(this_player());
   set_listener(this_player());

   msg("~CDEF"+buf);

   // more detailed consideration takes a bit more time
   // (Note: being more skilled at consideration makes it
   // take longer? Bizarre. Dropping, since players
   // cannot control this. -- Acius)
   this_player()->add_readiness(-700);
}
