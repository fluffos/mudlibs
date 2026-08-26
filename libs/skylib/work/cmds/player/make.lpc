/* make command for making snowballs and snowmen. Moved from /global/pweath.c
 * by Ceres 24/3/96
 */
inherit  COMMAND_BASE;
#include <config.h>
#include <weather.h>
#include <move_failures.h>

int is_snowing(object player, string str) {
  object env;
  int *co_ords;

  env = environment(player);
  if ((string)env->query_property("location") == "inside") {
    add_failed_mess("You must be outside to make a " + str + ".\n");
    return 0;
  }

  co_ords = (mixed *)env->query_co_ord();

  if (!WEATHER->query_snowing(env)) {
     add_failed_mess("You need snow to make a " + str + ".\n");
     return 0;
  }

  return 1;
} /* is_snowing() */

mixed cmd(string str) {
  object ob;
  object env;
 
  env = environment(TP);
  switch (str) {
  case "snowball" :
    if (is_snowing(TP, str)) {
      ob = clone_object("/std/environ/snowball");
      if (ob->move(TP) != MOVE_OK) {
        add_succeeded_mess(({ "$N try to make a snowball, but you cannot "
                              "pick it up so it disintergrates in "
                              "disinterest.\n",
                              "$N tries to make a snowball, but they cannot "
                                "pick it up.\n" }));
      } else {
        add_succeeded_mess(({
          "$N $V a lovely big snowball. Have fun with it ;)\n",
            "$N $V a lovely big snowball.\n" }));
      }
      return 1;
    }
    break;
  case "snowman" :
    if (is_snowing(TP, str)) {
      ob = clone_object("/std/environ/snowman");
      ob->move(env);
      add_succeeded_mess("$N $V a beautiful snowman.\n");
      return 1;
    }
    break;
  case "snowwoman" :
    if (is_snowing(TP, str)) {
      ob = clone_object("/std/environ/snowwoman");
      ob->move(env);
      add_succeeded_mess("$N $V a beautiful snowwoman.\n");
      return 1;
    }
    break;
  }
  return 0;
} /* cmd() */

mixed *query_patterns() {
   return ({ "{snowwoman|snowman|snowball}", (: cmd($4[0]) :) });
} /* query_patterns() */
