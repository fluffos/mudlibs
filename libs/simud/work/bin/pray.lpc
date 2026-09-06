string query_action_name( mixed * action ) {
   return "Pray";
}

int main(string args) {
   WALK_ACTION_PARAM(1000, this_player(), args);
   debug(this_player()->query_name() + " is praying " + args, "gp");
   return 1;
}

void on_action(object TP, string args) {
   string deity, subject, *elements = ({});
   int t, f, x;

   debug("Prayed " + args, "gp");
   if (args)
      elements = explode(args," ");
   t = member(elements,"to");
   f = member(elements,"for");

   // they have specified who they are praying to
   if (t != -1) {
      if (t == sizeof(elements)) {
         msg("Bad prayer syntax.");
         return;
      }
      if (t < f)
         deity = implode(elements[t+1..f-1]," ");
      else
         deity = implode(elements[t+1..]," ");
   }

   if (!deity)
      deity = "Everyone";
   else {
      deity = "/faith/prayer_daemon"->query_god_name(deity);
      if (!deity) {
         msg("There is no god by that name in this world.");
         return;
      }
      if ( deity == "The Great Pumpkin" ) {
         if ( gmtime()[4] + 1 != 10 ) {
            msg("The Great Pumpkin slumbers...");
            return;
         }
      }
   }

   // they have specified what they are praying for
   if (f != -1) {
     if (f == sizeof(elements)) {
       msg("Bad prayer syntax.");
       return;
     }
     if (f < t)
       subject = implode(elements[f+1..t-1]," ");
     else
       subject = implode(elements[f+1..]," ");
   }

   // prayers without subjects == thanks ;)
   if (!subject || subject == "thanks" ) {
     if (this_player()->query_mana() < 25) {
       msg("You are too spiritually drained to offer thanks right now.");
       return;
     }
     if (deity == "Everyone") {
       msg("You must select a specific god to pray to if you want to offer thanks.");
       return;
     }
     this_player()->add_favor(deity, min(this_player()->query_mana() / 25, 5));
     this_player()->set_mana(0);
     set_actor(this_player());
     this_player()->msg_local("~CACT~Name ~verboffer up a prayer of gratitude to "+capitalize(deity)+".");
     "/bin/hp"->main();
     this_player()->practice_skill("magic.faith.repentance");
     return;
   }

   "/faith/prayer_daemon"->on_prayer(deity,subject);

   this_player()->msg_local("~CACT~Name ~verbpray to ~CBRT"+deity+"~CACT for ~CBRT"+subject+"~CACT.~CDEF");
   this_player()->add_readiness( -500 );
   this_player()->practice_skill("magic.faith.devotion");
   this_player()->practice_skill("knowledge.religion."+deity);
}
