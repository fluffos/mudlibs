inherit "/obj/food";

#include <room.h>

int do_chuck(object *obs);
int do_smear(object *obs);
int do_run_smear(object *obs, string dir);

void setup() {
   set_name("pie");
   set_short("banana cream pie");
   add_adjective( ({ "banana", "cream" }) );
   set_long(
"This is a banana cream pie.  It is simply covered in whipped cream.  Not "
"just covered, there's gobs and gobs of it on the thing.  You feel this "
"sudden urge to 'slap', 'smear' or 'chuck' it at someone.\n");
   add_read_mess("Inspired by Josie.\n", 0, "common", 1);
   set_weight(5);
   set_weight_per_bite(1);
   set_piece_description("This is a piece of a banana cream pie.  It is "
                         "simply covered in whipped cream.  You feel this "
                         "sudden urge to 'slap', 'smear' or 'chuck' it at someone.\n");
   set_medium_alias("Cream Pie");
} /* setup() */

void init() {
   ::init();
   add_command("chuck", "<direct:object> at <indirect:living>",
               (: do_chuck($1) :));
   add_command("smear", "<direct:object> into <indirect:living> [face]",
               (: do_smear($1) :));
   add_command("slap", "<direct:object> into <indirect:living> face then run <string>",
               (: do_run_smear($1, $4[2]) :));
} /* init() */

int do_chuck(object *obs) {
   object *fail;

   fail = this_player()->query_ignoring(obs[0..0]);
   if (sizeof(fail)) {
     add_failed_mess("You are ignoring $I and cannot chuck this pie at "
                     "them.\n", ({ obs[0] }));
     return 0;
   }

   fail = obs[0]->query_ignoring(({ this_player() }));
   if (sizeof(fail)) {
     add_failed_mess("You are being ignored by $I and cannot chuck this "
                     "pie at them.\n", ({ obs[0] }));
     return 0;
   }

   /* We only do the first one... */
   if (environment(obs[0]) == environment(this_player())) {
      add_succeeded_mess("$N hurl$s $D at $I.\n",
                         obs[0..0]);
   } else {
      add_succeeded_mess("$N hurl$s $D halfway around the Disc at $I!\n",
                         obs[0..0]);
      tell_object(obs[0], "SPLAAAAAAAAAT!!!!!\n"
                          "Where did that pie come from?  Did anyone get "
                          "it's license number?\n");
   }

   /* Add the covered in cream effect to them.  Add it for 5 minutes. */
   obs[0]->add_effect("/std/effects/other/covered_in_cream", 
                      query_weight() * 60);
   move("/room/rubbish");
   return 1;
} /* do_chuck() */

int do_smear(object *obs) {
   object *fail;

   fail = this_player()->query_ignoring(obs[0..0]);
   if (sizeof(fail)) {
     add_failed_mess("You are ignoring $I and cannot chuck this pie at "
                     "them.\n", ({ obs[0] }));
     return 0;
   }

   fail = obs[0]->query_ignoring(({ this_player() }));
   if (sizeof(fail)) {
     add_failed_mess("You are being ignored by $I and cannot chuck this "
                     "pie at them.\n", ({ obs[0] }));
     return 0;
   }

   add_succeeded_mess(({ "$N tap$s $I on the shoulder and then smear$s $D into " +
                      obs[0]->query_possessive() + " face.\n", "" }),
                      ({ obs[0] }));
   tell_object(obs[0], this_player()->the_short() + " taps you on the "
               "shoulder and then smears " + the_short() + " into your "
               "face.\n");
   tell_room(environment(obs[0]),
             this_player()->the_short() + " taps " + obs[0]->the_short() +
             " on the shoulder and then smears " + the_short() + " into " +
             obs[0]->query_possessive() + " face.\n", ({ this_player(), 
                                                           obs[0] }));
   obs[0]->add_effect("/std/effects/other/covered_in_cream", 
                      query_weight() * 60);
   move("/room/rubbish");
   return 1;
} /* do_smear() */

int do_run_smear(object *obs, string direc) {
   object *fail;
   string dest;

   fail = this_player()->query_ignoring(obs[0..0]);
   if (sizeof(fail)) {
     add_failed_mess("You are ignoring $I and cannot chuck this pie at "
                     "them.\n", ({ obs[0] }));
     return 0;
   }

   fail = obs[0]->query_ignoring(({ this_player() }));
   if (sizeof(fail)) {
     add_failed_mess("You are being ignored by $I and cannot chuck this "
                     "pie at them.\n", ({ obs[0] }));
     return 0;
   }

   /* Check the direction. */
   if (member_array(direc, environment(this_player())->query_direc()) == -1) {
     add_failed_mess("There is no " + direc + " exit.\n");
     return 0;
   } else {
     dest = environment(this_player())->query_destination(direc);
   }

   tell_object(this_player(),
               "You tap " + obs[0]->the_short() + " on the shoulder and "
               "then smear " + this_object()->the_short() + " into " +
               obs[0]->query_possessive() + " face, then run " +
               direc + ".\n");
   add_succeeded_mess("",
                      ({ obs[0] }));
   tell_object(obs[0], this_player()->the_short() + " taps you on the "
               "shoulder and then smears " + the_short() + " into your "
               "face, then runs " + direc + ".\n");
   tell_room(environment(obs[0]),
             this_player()->the_short() + " taps " + obs[0]->the_short() +
             " on the shoulder and then smears " + the_short() + " into " +
             obs[0]->query_possessive() + " face, then runs " + direc + 
             ".\n", ({ this_player(), 
                                                           obs[0] }));
   obs[0]->add_effect("/std/effects/other/covered_in_cream", 
                      query_weight() * 60);
   move("/room/rubbish");
   ROOM_HANDLER->exit_move(direc, 0, "$N head$s $T at a run.",
                           this_player());
   return 1;
} /* do_run_smear() */
