/*
** File: timestop_ob2.c
** Purpose: The OTHER spell object for the timestop spell.
** Credits:
**   24 Nov 97  Cyanide created the file.
*/

inherit OBJECT;

object *attackers = ({}), player;

void create() {
  set("prevent_get", 1);
  set("prevent_clean", 1);
  set("dest_at_die", 1);
  set("id", ({ "#TIME_STOP2#" }) );
}

void init() {
   add_action("time_stop", "");
}

int time_stop() {
   if (wizardp(TP)) return 0;

   write("Time has stopped - you can do nothing.\n");
   return 1;
}

void check_attackers( object ob ) {
   attackers = ob->query_current_attackers();
   ob->cease_all_attacks();

   player = ob;
}

void remove() {
   if (player) player->set_attackers(attackers);

   ::remove();
}

/* EOF */
