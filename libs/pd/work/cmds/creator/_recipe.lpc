// command for immortals to manage recipes in the recipe daemon
// -Nulvect 10-Dec-2010
//
// Note: Many bits of code here rely on the fact that LPC passes complex
// types by reference by default. Any mappings, arrays, or class variables
// that don't seem to be getting saved should have been passed by reference,
// and so it should not be necessary to explicitly save them.

#include <std.h>
#include <daemons.h>
#include <recipe_cl.h>

#define FAILMSG return notify_fail("See <help recipe> for usage.")
#define RECIPE_PROP "recipe_manage_tmp"

inherit DAEMON;

int cmd_recipe_list(string str);
int cmd_recipe_filter(string str);
int cmd_recipe_new(string str);
int cmd_recipe_load(string str);
int cmd_recipe_clear(string str);
int cmd_recipe_set(string str);
int cmd_recipe_add(string str);
int cmd_recipe_remove(string str);
int cmd_recipe_set_step(string str);
int cmd_recipe_save(string str);
int cmd_recipe_delete(string str);
int cmd_recipe_rename(string str);
mapping set_mapping(mapping m, string key, mixed value);
class Recipe find_tmp_recipe(string name);
void remove_tmp_recipe(mixed recipe);
void add_tmp_recipe(class Recipe r);

void help() {
  message("help",
    "Syntax: <recipe list [name]/(all/unsaved)>\n"
    "        <recipe filter [property] [value]>\n"
    "        <recipe filter [requirement] [comparison] [value]>\n"
    "\n"
    "List will show you one recipe, all recipes, or all of your unsaved "
    "recipes. Filter will search for all recipes that contain the specified "
    "value and list them.\n"
    "Examples: <recipe filter skills nature >= 20>\n"
    "          <recipe filter type potion>\n"
    "          <recipe filter material leather>\n"
    "\n"
    "        <recipe new [name]>\n"
    "        <recipe load [name]>\n"
    "        <recipe clear [name]>\n"
    "        <recipe set [name] type [type]>\n"
    "        <recipe set [name] yield [file]>\n"
    "        <recipe set [name] reqs level [x]>\n"
    "        <recipe set [name] reqs (race/class/subclass) [item1,item2]>\n"
    "        <recipe set [name] reqs (skills/stats) [item1:x,item2:x]>\n"
    "        <recipe set [name] reqs clear>\n"
    "\n"
    "Commands for creating a new recipe and setting its properties. "
    "All recipes require a name, type, yield, and one step (see below). "
    "The recipe will not go into effect until you save it, or you can use "
    "the clear command to discard any work on an unsaved recipe. "
    "The load command will load up an existing recipe from the recipe daemon "
    "for you to work on. It must be saved again afterwards.\n"
    "\n"
    "        <recipe add step [name]>\n"
    "        <recipe remove step [n] [name]>\n"
    "        <recipe set step [n] [name] time [time]>\n"
    "        <recipe set step [n] [name] method [method]>\n"
    "        <recipe set step [n] [name] materials [item1,item2]>\n"
    "        <recipe set step [n] [name] prohibited [item1,item2]>\n"
    "        <recipe set step [n] [name] temperatures [temp1,temp2]>\n"
    "        <recipe set step [n] [name] failure [file]>\n"
    "\n"
    "Commands for adding steps to a recipe and setting their properties. "
    "All recipes require at least one step. Steps are numbered starting "
    "from 1. Every step requires a time, method, and at least one "
    "temperaure. Method and temperature can be \"any\". Most steps should "
    "have materials required as well.\n"
    "\n"
    "        <recipe save [name]>\n"
    "        <recipe delete [name]>\n"
    "        <recipe rename [oldname] [newname]>\n"
    "\n"
    "The save command saves your new recipe into the recipe daemon for "
    "use mudwide. The delete command will delete a recipe already saved.",
    this_player() );
}

int cmd_recipe(string str) {
  object tp = this_player();
  string cmd, args, tmp1, tmp2;

  if (!str || sscanf(str, "%s %s", cmd, args) != 2)
    FAILMSG;

  switch (cmd) {
    case "list":
    case "filter":
    case "new":
    case "clear":
    case "load":
    case "add":
    case "remove":
    case "save":
    case "delete":
    case "rename":
      return call_other(this_object(), "cmd_recipe_"+cmd, args);
    case "set":
      if (sscanf(args, "%s %s", tmp1, tmp2) == 2 && tmp1 == "step")
        return cmd_recipe_set_step(tmp2);
      else
        return cmd_recipe_set(args);
    default:
      FAILMSG;
  }
  
  return 1;
}

int cmd_recipe_list(string str) {
  object tp = this_player();
  class Recipe *show;
  string out = "";

  if (!str) FAILMSG;

  if (str == "all") {
    show = RECIPE_D->query_all_recipes();
    if (!show || !sizeof(show))
      return notify_fail("There are no recipes.");
  }
  else if (str == "unsaved") {
    show = tp->query(RECIPE_PROP);
    if (!show || !sizeof(show))
      return notify_fail("You have no unsaved recipes.");
  }
  else {
    show = ({ RECIPE_D->query_recipe(str) });
    if (!show[0]) {
      // check if we have an unsaved recipe with this name
      show = tp->query(RECIPE_PROP);
      if (sizeof(show))
        show = filter(show, (: $1->name == $2 :), str);
      if (!sizeof(show))
        return notify_fail("There is no recipe by that name.");
    }
  }

  foreach (class Recipe r in show) {
    out += RECIPE_D->query_recipe_string(r) + "\n";
  }

  if (strlen(out))
    tp->more(explode(out, "\n"));

  return 1;
}

int filter_type(class Recipe r, string value) { return (r->type == value); }
int filter_yield(class Recipe r, string value) { return (r->yield_file == value); }

int filter_requirements(class Recipe r, string value, string which) {
  mapping reqs = r->user_requirements;
  mixed reqvalue;
  int low, high;
  string check;

  if (!sizeof(reqs) || !(reqvalue = reqs[which]))
    return 0;

  switch (which) {
    case "level":
    default:
      // allow default entries to be either a mapping or an int
      // if a mapping, the first word of value is the key to check
      if (mapp(reqvalue)) {
        if (sscanf(value, "%s %s", check, value) != 2) return 0;
        if (!(reqvalue = reqs[which][check])) return 0;
      }
      else if (!intp(reqvalue)) return 0;

      if (sscanf(value, "%d %d", low, high) == 2)
        return (reqvalue >= low && reqvalue <= high);
      else if (sscanf(value, "%s %d", check, low) == 2) {
        switch (check) {
          case ">": return (reqvalue > low);
          case ">=": return (reqvalue >= low);
          case "<": return (reqvalue < low);
          case "<=": return (reqvalue <= low);
          case "==":
          case "=": return (reqvalue == low);
          default: return 0;
        }
      }
      return 0;

    case "race":
    case "class":
    case "subclass":
      if (!arrayp(reqvalue) || !sizeof(reqvalue)) return 0;
      return (member_array(value, reqvalue) != -1);
  }

  return 0;
}
int filter_method(class Recipe r, string value) {
  foreach (class RecipeStep s in r->steps)
    if (s->combine_method == value)
      return 1;
  return 0;
}
int filter_failure(class Recipe r, string value) {
  foreach (class RecipeStep s in r->steps)
    if (s->failure_yield == value)
      return 1;
  return 0;
}
int filter_materials(class Recipe r, string value) {
  foreach (class RecipeStep s in r->steps)
    if (member_array(value, s->required_materials) != -1)
      return 1;
  return 0;
}
int filter_prohibited(class Recipe r, string value) {
  foreach (class RecipeStep s in r->steps)
    if (member_array(value, s->prohibited_materials) != -1)
      return 1;
  return 0;
}
int filter_temperatures(class Recipe r, string value) {
  foreach (class RecipeStep s in r->steps)
    if (member_array(value, s->allowed_temperatures) != -1)
      return 1;
  return 0;
}


int cmd_recipe_filter(string str) {
  object tp = this_player();
  class Recipe *show, *all;
  string prop, which;
  mixed value;
  function f;
  string out = "";

  if (!str || sscanf(str, "%s %s", prop, value) != 2)
    FAILMSG;

  all = RECIPE_D->query_all_recipes();

  switch (prop) {
    case "type":
      f = (: filter_type :);
    break;
    case "yield":
      f = (: filter_yield :);
    break;
    case "level":
    case "race":
    case "class":
    case "subclass":
      f = (: filter_requirements :);
      which = prop;
    break;
    case "skill":
    case "stat":
      prop += "s";
    case "skills":
    case "stats":
      f = (: filter_requirements :);
      which = prop;
    break;
    case "method":
      f = (: filter_method :);
    break;
    case "material":
    case "materials":
      f = (: filter_materials :);
    break;
    case "prohibited":
      f = (: filter_prohibited :);
    break;
    case "temperature":
    case "temperatures":
      f = (: filter_temperatures :);
    break;
    case "failure":
      f = (: filter_failure :);
    break;
    default:
      return notify_fail(
        "Valid properties are as follows:\n"
        "type, yield, level, race, class, subclass, skill, stat,\n"
        "method, material, prohibited, temperature, and failure"
      );
  }

  if (which)
    show = filter(all, f, value, which);
  else
    show = filter(all, f, value);
    

  if (!show || !sizeof(show)) {
    message("info", "No recipes found with that filter.", tp);
  }
  else {
    foreach (class Recipe r in show) {
      out += RECIPE_D->query_recipe_string(r->name) + "\n";
    }
  }

  if (strlen(out))
    tp->more(explode(out, "\n"));

  return 1;  
}

int cmd_recipe_new(string str) {
  object tp = this_player();
  class Recipe r;

  if (RECIPE_D->query_recipe(str))
    return notify_fail("There is already a recipe by that name.");

  if (find_tmp_recipe(str))
    return notify_fail("You are already working on a recipe by that name.");

  r = new(class Recipe);
  r->name = str;

  add_tmp_recipe(r);

  message("info", "Created new recipe: "+str+".\n"
                  "It will not be useable until it is saved.", tp);

  return 1;
}

int cmd_recipe_load(string str) {
  object tp = this_player();
  class Recipe r = RECIPE_D->query_recipe(str);

  if (!r)
    return notify_fail("There is no recipe by that name.");

  add_tmp_recipe(r);
  RECIPE_D->remove_recipe(r);

  message("info", "Loaded existing recipe: "+str+".\n"
                  "It must be saved after modifications are complete.", tp);

  return 1;
}

int cmd_recipe_clear(string str) {
  object tp = this_player();
  class Recipe r = find_tmp_recipe(str);

  if (!r)
    return notify_fail("You are not working on a recipe by that name.");

  remove_tmp_recipe(r);

  message("info", "Cleared unsaved recipe: "+str+".", tp);

  return 1;
}

int cmd_recipe_set(string str) {
  object tp = this_player();
  class Recipe r;
  string name, cmd, arg;
  string req;
  string *list;
  mapping check;
  
  if (!str || sscanf(str, "%s %s %s", name, cmd, arg) != 3)
    FAILMSG;

  r = find_tmp_recipe(name);
  if (!r)
    return notify_fail("You are not working on a recipe by that name.");

  switch (cmd) {
    case "type":
      r->type = arg;
    break;
    case "yield":
      r->yield_file = arg;
    break;
    case "reqs":
      if (arg == "clear") {
        r->user_requirements = 0;
      }
      else if (sscanf(arg, "%s %s", req, arg) != 2)
        FAILMSG;
      switch (req) {
        case "level":
          r->user_requirements = set_mapping(r->user_requirements, "level", to_int(arg));
        break;
        case "class": case "subclass": case "race":
          arg = replace_string(arg, ", ", ",");
          list = explode(arg, ",");
          r->user_requirements = set_mapping(r->user_requirements, req, list);
        break;
        case "skills": case "stats":
          arg = replace_string(arg, ", ", ",");
          list = explode(arg, ",");
          foreach (string pair in list) {
            string *exp = explode(pair, ":");
            check = set_mapping(check, exp[0], to_int(exp[1]) );
          }
          r->user_requirements = set_mapping(r->user_requirements, req, check);
      }
    break;
    default:
      FAILMSG;
  }

  message("info", "Set "+cmd+" for "+name+": "+arg+".", tp);

  return 1;
}

int cmd_recipe_add(string str) {
  object tp = this_player();
  class Recipe r;
  class RecipeStep s;
  string name;
  int num;

  if (!str || sscanf(str, "step %s", name) != 1) FAILMSG;

  r = find_tmp_recipe(name);
  if (!r)
    return notify_fail("You are not working on a recipe by that name.");

  s = new(class RecipeStep);

  num = sizeof(r->steps);
  if (!num)
    r->steps = ({});
  r->steps += ({ s });

  message("info", "Added a new step ("+(num+1)+") to recipe "+name+".", tp);

  return 1;
}

int cmd_recipe_remove(string str) {
  object tp = this_player();
  class Recipe r;
  string name;
  int num;

  if (!str || sscanf(str, "step %d %s", num, name) != 2) FAILMSG;

  r = find_tmp_recipe(name);
  if (!r)
    return notify_fail("You are not working on a recipe by that name.");

  if (num > sizeof(r->steps) || num < 1)
    return notify_fail("That recipe does not have that many steps.");

  r->steps = r->steps[0..num-2] + r->steps[num..];

  message("info", "Removed step #"+num+" from recipe "+name+".", tp);

  return 1;
}

int cmd_recipe_set_step(string str) {
  object tp = this_player();
  class Recipe r;
  class RecipeStep s;
  string name, cmd, arg;
  string *list;
  int num;
  
  if (!str || sscanf(str, "%d %s %s %s", num, name, cmd, arg) != 4)
    FAILMSG;

  r = find_tmp_recipe(name);
  if (!r)
    return notify_fail("You are not working on a recipe by that name.");

  if (num > sizeof(r->steps) || num < 1)
    return notify_fail("That recipe does not have that many steps.");

  s = r->steps[num-1];

  switch (cmd) {
    case "time":
      s->time = to_int(arg);
    break;
    case "method":
      s->combine_method = arg;
    break;

    case "failure":
      s->failure_yield = arg;
    break;
    case "materials":
      arg = replace_string(arg, ", ", ",");
      list = explode(arg, ",");
      s->required_materials = list;
    break;
    case "prohibited":
      arg = replace_string(arg, ", ", ",");
      list = explode(arg, ",");
      s->prohibited_materials = list;
    break;
    case "temperatures":
      arg = replace_string(arg, ", ", ",");
      list = explode(arg, ",");
      s->allowed_temperatures = list;
    break;
    default:
      FAILMSG;
  }

  message("info", "Set "+cmd+" for step #"+num+" of "+name+": "+arg, tp);

  return 1;
}

int cmd_recipe_save(string str) {
  object tp = this_player();
  class Recipe r = find_tmp_recipe(str);

  if (!r)
    return notify_fail("You are not working on a recipe by that name.");

  // check recipe requirements
  if (!r->type || !strlen(r->type))
    return notify_fail("Recipe "+str+" has no type set.");
  if (!r->yield_file || !strlen(r->yield_file))
    return notify_fail("Recipe "+str+" has no yield set.");
  if (!sizeof(r->steps))
    return notify_fail("Recipe "+str+" has no steps added.");
  // check each step for time, method, temperature
  for (int i = 0; i < sizeof(r->steps); i++) {
    int step = i+1;
    if (!r->steps[i]->time)
      return notify_fail(
        "Step #"+step+" of recipe "+str+" has no time set."
      );
    if (!r->steps[i]->combine_method || !strlen(r->steps[i]->combine_method))
      return notify_fail(
        "Step #"+step+" of recipe "+str+" has no method set."
      );
    if (!sizeof(r->steps[i]->allowed_temperatures))
      return notify_fail(
        "Step #"+step+" of recipe "+str+" has no temperature set."
      );
    if (!sizeof(r->steps[i]->required_materials))
      message("info",
        "Warning: step #"+step+" of recipe "+str+
        " has no requried materials, saving anyway...", tp
      );
  }

  RECIPE_D->add_recipe(r);

  remove_tmp_recipe(r);

  message("info", "Saved new recipe: "+str+". "
                  "It is now available for use.", tp);

  return 1;
}

int cmd_recipe_delete(string str) {
  object tp = this_player();
  
  if (!RECIPE_D->query_recipe(str))
    return notify_fail("There is no recipe by that name.");

  RECIPE_D->remove_recipe(str);

  message("info", "Deleted recipe: "+str+".", tp);

  return 1;
}

int cmd_recipe_rename(string str) {
  object tp = this_player();
  string oldname, newname;
  class Recipe r;

  if (sscanf(str, "%s %s", oldname, newname) != 2)
    FAILMSG;
  
  if (!(r = RECIPE_D->query_recipe(oldname)))
    return notify_fail("There is no recipe by that name.");

  // shouldn't have to do this, but it's been acting weird
  RECIPE_D->remove_recipe(r);

  r->name = newname;

  RECIPE_D->add_recipe(r);

  message("info", "Renamed recipe \""+oldname+"\" to: "+newname+".", tp);

  return 1;
}


mapping set_mapping(mapping m, string key, mixed value) {
  if (!m) m = ([]);
  m[key] = value;
  return m;
}

class Recipe find_tmp_recipe(string name) {
  object tp = this_player();
  class Recipe *find;
  find = tp->query(RECIPE_PROP) || ({});
  find = filter(find, (: $1->name == $2 :), name);
  if (sizeof(find))
    return find[0];
  return 0;
}

void remove_tmp_recipe(mixed recipe) {
  object tp = this_player();
  class Recipe *tmp = tp->query(RECIPE_PROP) || ({});
  class Recipe r;

  if (stringp(recipe)) r = find_tmp_recipe(recipe);
  else if (classp(recipe)) r = recipe;

  if (r) {
    tmp -= ({ r });
    tp->set(RECIPE_PROP, tmp);
  }
}

void add_tmp_recipe(class Recipe r) {
  object tp = this_player();
  class Recipe *tmp = tp->query(RECIPE_PROP) || ({});

  if (r && r->name) {
    tmp += ({ r });
    tp->set(RECIPE_PROP, tmp);
  }
}
