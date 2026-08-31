#include <std.h>
inherit DAEMON;

int abil();
int fail_song();

int cmd_sing(string str) {
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!str) return notify_fail("Sing what?");
   if (!ob)
     return notify_fail("You do not see that here.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
     return notify_fail("You cannot sing here.\n");
   if (present("a_bard_song", tp))
     return notify_fail("You are already singing a song!\n");
   switch (str) {
      case "song of rain":
      default:
        fail_song();
   }
}

int fail_song() {
   return notify_fail("You do not know that song.\n");
}

int abil() {
  object o;
  o = this_player();
   if (wizardp(o) && o->query_subclass() == "bard") return 1;
}
