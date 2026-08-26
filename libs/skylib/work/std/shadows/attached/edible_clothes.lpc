/**
 *
 * event trickle shadow
 * @author Terano
 *
 */
inherit "/std/effect_shadow";
#include <move_failures.h>

int query_event() {
  return 1; 
} /* query_event() */

private int do_eat_clothes(object *obs);

void event_enter( object objecty, string mess, object from ) {
   if (living(objecty)) {
      objecty->add_command("eat", player,
                           "<indirect:object:direct-obs> {from|off} "
                           "<direct:living:here>", (: do_eat_clothes($1) :));
   }
   player->event_enter( objecty,  mess,  from );
} /* event_enter() */

private int do_eat_clothes(object *obs) {
   object *clothes;

   clothes = arg();
   obs = obs & clothes;
   if (!sizeof(obs)) {
      write("Argh in space!\n");
      return 0;
   }
   return sizeof(filter(obs->do_clothing_eat(), (: $1 :)));
} /* do_eat_clothes() */

void init_eat_clothes_command() {
   object ob;

   foreach (ob in all_inventory(environment(player))) {
      if (living(ob) && ob != player) {
            tell_creator("pinkfish", "Init %O (%O)\n", ob, player);
            ob->add_command("eat", player,  
                            "<indirect:object:direct-obs> {from|off} "
                            "<direct:living:here>", (: do_eat_clothes($1) :));
      }
   }
} /* init_eat_clothes_command() */

/**
 * Shadow move so that we can keep track of when we move somewhere more
 * interesting.
 */
int move(mixed dest, string msgin, string msgout) {
   int ret;

   ret = player->move(dest, msgin, msgout);
   if (ret == MOVE_OK) {
      init_eat_clothes_command();
   }
   return ret;
} /* move() */
