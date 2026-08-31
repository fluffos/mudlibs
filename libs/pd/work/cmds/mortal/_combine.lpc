
#include <std.h>
#include <daemons.h>
#include <recipe_cl.h>

void continue_recipe(object tp, class Recipe recipe, int step,
object *items, string *methods, string *temperatures);

void help() {
  message("help",
    "Syntax: <combine [item 1, item 2, etc] into [recipe]>\n\n"
    "This command lets you attempt to combine materials using "
    "a specific recipe as a guideline.",
    this_player() );
}

int cmd_combine(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *items;
  string itemlist, recipename;
  string *methods, *temperatures;
  int time;
  class Recipe recipe;

  if (tp->query_busy())
    return notify_fail("You are too busy.");

  if (tp->query_ghost())
    return notify_fail("You are not alive!");

  if (!str || sscanf(str, "%s into %s", itemlist, recipename) != 2)
    return notify_fail("Combine what into what?");

  if (!(recipe = RECIPE_D->query_recipe(recipename)) ||
      !RECIPE_D->check_user_requirements(recipe, tp) ||
      !sizeof(recipe->steps))
        return notify_fail("You do not know how to make that.");

  itemlist = replace_string(itemlist, " and ", "");
  itemlist = replace_string(itemlist, ", ", ",");
  itemlist = replace_string(itemlist, " ,", ",");
  
  items = ({});
  foreach (string s in explode(itemlist, ",")) {
    object ob = present(s, tp);
    if (ob) items |= ({ ob });
    else return notify_fail("You do not have "+indefinite_article(s)+".");
  }

  methods = ({ "mix" });
  temperatures = ({ "normal" });
  foreach (object ob in all_inventory(tp)) {
    string tmp = ob->query_property("alchemy tool");
    if (tmp) methods |= ({ tmp });
    tmp = ob->query_property("alchemy temperature");
    if (tmp) temperatures |= ({ tmp });
  }
  foreach (object ob in all_inventory(env)) {
    string tmp = ob->query_property("alchemy temperature");
    if (tmp) temperatures |= ({ tmp });
  }

  time = recipe->steps[0]->time;
  tp->set_paralyzed(time+2, "You are busy creating something.");

  call_out("continue_recipe", time, tp, recipe,
    0, items, methods, temperatures
  );

  message("info", "You begin working on the recipe.", tp);
  message("info", tp->query_cap_name()+" begins to work on a recipe.",
    env, tp);

  return 1;
}

void continue_recipe(object tp, class Recipe recipe, int step,
object *items, string *methods, string *temperatures) {

  string mymsg, theirmsg;
  string resultfile;
  object result, env;
  int time;

  if (!tp || !recipe) return;

  env = environment(tp);
  tp->set_paralyzed(0);

  if (!RECIPE_D->check_step_requirements(recipe, step,
     items, methods, temperatures)) {
       resultfile = recipe->steps[step]->failure_yield;
       if (!resultfile) {
         mymsg = "You fail to complete an important step in the recipe.";
         theirmsg = tp->query_cap_name()+" fails to complete a step "
           "in the recipe.";
       }
       // randomly lose half your ingredients on failure
       foreach (object a in items)
         if (random(100) < 50)
           items -= ({ a });
       items->remove();
  }
  else if (step == sizeof(recipe->steps)-1) {
    resultfile = recipe->yield_file;
    items->remove();
  }
  else {
    step++;
    time = recipe->steps[step]->time;
    tp->set_paralyzed(time+2, "You are busy creating something.");
    mymsg = "You complete a step of the recipe, and move on to the next.";
    theirmsg = tp->query_cap_name()+" completes one step of a recipe and "
      "moves on to the next.";
    call_out("continue_recipe", time, tp, recipe,
      step, items, methods, temperatures
    );
  }

  if (resultfile) {
    result = new(resultfile);
    if (!result) {
      mymsg = "You fail to create anything useful.";
      theirmsg = tp->query_cap_name()+" fails to create anything useful.";
    }
    else if (result->move(tp)) {
      result->move(env);
      mymsg = "You create "+indefinite_article(result->query_name())+
        ", but it is too heavy and you drop it.";
      theirmsg = tp->query_cap_name()+" creates "+
        indefinite_article(result->query_name())+", but drops it.";
    }
    else {
      mymsg = "You create "+indefinite_article(result->query_name())+".";
      theirmsg = tp->query_cap_name()+" creates "+
        indefinite_article(result->query_name())+".";
    }
  }

  if (mymsg)
    message("info", mymsg, tp);
  if (theirmsg)
    message("info", theirmsg, env, tp);
}
