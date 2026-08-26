/**
 * This handler deals will the options a player has.  It will return the
 * list of options, set options and control how the options can be
 * set.
 * @author Pinkfish
 * @started Thu Jun  8 17:13:47 PDT 2000
 */
#include <cmds/options.h>
#include <colour.h>
#include <clubs.h>
#include <obj_parser.h>
#include <player.h>

class option {
   mixed type;
   int cre_only;
   function set;
   function query;
}

private mapping _options;
private string* _colours;
private mapping _cache_input;

protected int add_option(string path, mixed type, int cre_only,
                function set_function,
                function query_function);

private int set_player_brief(object player, string variable, int value);
private int query_player_brief(object player, string variable);
private mapping get_inform_colours(object player);
private mapping get_club_colours(object player);
private int change_ambiguous(object player, int new_value);
private int change_earmuffs(object player, string ear, int new_value);
private int valid_birthday(string str);

void create() {
   string womble;

   _options = ([ ]);
   _cache_input = ([ ]);
   _colours = ({
    "BOLD",
    "FLASH",
    "BLACK",
    "RED",
    "BLUE",
    "CYAN",
    "MAGENTA",
    "ORANGE",
    "YELLOW",
    "GREEN",
    "WHITE",
    "B_RED",
    "B_ORANGE",
    "B_YELLOW",
    "B_BLACK",
    "B_CYAN",
    "B_WHITE",
    "B_GREEN",
    "B_MAGENTA" });

   //
   // Output brief/verbose.
   //
   add_option("output look", OPTIONS_TYPE_BRIEF, 0,
              (: $1->set_verbose($2[<1], $3), 1 :),
              (: $1->query_verbose($2[<1]) :));
   add_option("output combat", OPTIONS_TYPE_BRIEF, 0,
              (: $1->set_verbose($2[<1], $3), 1 :),
              (: $1->query_verbose($2[<1]) :));
   add_option("output score", OPTIONS_TYPE_BRIEF, 0,
              (: $1->set_verbose($2[<1], $3), 1 :),
              (: $1->query_verbose($2[<1]) :));
   add_option("output names", OPTIONS_TYPE_BRIEF, 0,
              (: $1->set_verbose($2[<1], $3), 1 :),
              (: $1->query_verbose($2[<1]) :));
   add_option("output htell", OPTIONS_TYPE_BRIEF, 0,
              (: $1->set_verbose($2[<1], $3), 1 :),
              (: $1->query_verbose($2[<1]) :));
   add_option("output finger", OPTIONS_TYPE_BRIEF, 0,
              (: $1->set_verbose($2[<1], $3), 1 :),
              (: $1->query_verbose($2[<1]) :));
   add_option("output msgout", OPTIONS_TYPE_STRING, 1,
              (: $1->set_msgout($3) :),
              (: $1->query_msgout() :));
   add_option("output msgin", OPTIONS_TYPE_STRING, 1,
              (: $1->set_msgin($3) :),
              (: $1->query_msgin() :));
   add_option("output mmsgout", OPTIONS_TYPE_STRING, 1,
              (: $1->set_mmsgout($3) :),
              (: $1->query_mmsgout() :));
   add_option("output mmsgin", OPTIONS_TYPE_STRING, 1,
              (: $1->set_mmsgin($3) :),
              (: $1->query_mmsgin() :));

   //
   // Colours.
   //
   foreach (womble in USER_COLOUR_LIST) {
      add_option("colour " + womble, OPTIONS_TYPE_COLOUR, 0,
                 (: $1->set_my_colours($2[<1], $3), 1 :),
                 (: $1->colour_event($2[<1], "default") :));
   }
   foreach (womble in CRE_COLOUR_LIST) {
      add_option("colour " + womble, OPTIONS_TYPE_COLOUR, 1,
                 (: $1->set_my_colours($2[<1], $3), 1 :),
                 (: $1->colour_event($2[<1], "default") :));
   }
   add_option("colour inform", OPTIONS_TYPE_DYNAMIC_GROUP, 0,
              0, (: get_inform_colours :));
   add_option("colour club", OPTIONS_TYPE_DYNAMIC_GROUP, 0,
              0, (: get_club_colours :));

   //
   // Terminal stuff.
   //
   add_option("terminal type", OPTIONS_TYPE_TERMINAL, 0,
              (: $1->set_term_type($3) :),
              (: $1->query_term_name() :));
   add_option("terminal rows", OPTIONS_TYPE_INTEGER, 0,
              (: $1->set_rows($3) :),
              (: $1->query_rows() :));
   add_option("terminal cols", OPTIONS_TYPE_INTEGER, 0,
              (: $1->set_cols($3) :),
              (: $1->query_cols() :));

   //
   // Combat stuff.  Wimpy etc.
   //
   add_option("combat wimpy", OPTIONS_TYPE_PERCENTAGE, 0,
              (: $1->set_wimpy($3) :),
              (: $1->query_wimpy() :));
   add_option("combat monitor", OPTIONS_TYPE_BOOLEAN, 0,
              (: $1->set_monitor($3), 1 :),
              (: $1->query_monitor() :));
   add_option("combat tactics attitude",
              ({ "offensive", "neutral", "defensive" }), 0,
              (: $1->set_combat_attitude($3), 1 :),
              (: $1->query_combat_attitude() :));
   add_option("combat tactics response",
              ({ "dodge", "neutral", "parry" }), 0,
              (: $1->set_combat_response($3), 1 :),
              (: $1->query_combat_response() :));
   add_option("combat tactics parry",
              ({ "left", "right", "both" }), 0,
              (: $1->set_combat_parry($3), 1 :),
              (: $1->query_combat_parry() :));
   add_option("combat tactics mercy",
              ({ "always", "ask", "never" }), 0,
              (: $1->set_combat_mercy($3), 1 :),
              (: $1->query_combat_mercy() :));
   add_option("combat tactics parry_unarmed",
              OPTIONS_TYPE_BOOLEAN, 0,
              (: $1->set_unarmed_parry($3), 1 :),
              (: $1->query_unarmed_parry() :));
   add_option("combat killer",
              OPTIONS_TYPE_BOOLEAN, 1,
              (: $3?$1->add_property(PKER, 1):$1->remove_property(PKER), 1 :),
              (: $1->query_property(PKER) :));

   //
   // Input options.
   //
   add_option("input ambiguous", OPTIONS_TYPE_BOOLEAN, 0,
              (: change_ambiguous($1, !$3) :),
              (: !$1->query_property(OBJ_PARSER_AMBIGUOUS_PROP) :));
   add_option("input editor", ({ "menu", "magic", "command", "ed" }), 0,
              (: $1->set_editor($3) :),
              (: $1->query_editor() :));

   //
   // Earmuffs.
   //
   foreach (womble in ({ "shout", "newbie", "cryer", "remote-soul",
         "multiple-soul", "multiple-tell",  "teach",
         "tell", "remote", "multiple-remote" })) {
      add_option("earmuff events "  + womble, OPTIONS_TYPE_BOOLEAN, 0,
             (: change_earmuffs($1, $2[<1], $3) :),
             (: member_array($2[<1], ($1->query_property("earmuffs")?$1->query_property("earmuffs"):({}))) != -1 :));
   }
   foreach (womble in ({ "cre", "lord", "intermud-all", "intercre",
         "intergossip", "remote-spam" })) {
      add_option("earmuff events "  + womble, OPTIONS_TYPE_BOOLEAN, 1,
             (: change_earmuffs($1, $2[<1], $3) :),
             (: member_array($2[<1], ($1->query_property("earmuffs")?$1->query_property("earmuffs"):({}))) != -1 :));
   }
   add_option("earmuff state", OPTIONS_TYPE_BOOLEAN, 0,
              (: $1->query_earmuffs() != $3 ? ($1->toggle_earmuffs(), 1) : 1 :),
              (: $1->query_earmuffs() :));

   //
   // Player options.
   //
   add_option("personal description", OPTIONS_TYPE_STRING, 0,
              (: strlen($3) > 30?0:($1->set_desc($3 == "none"?0:$3), 1) :),
              (: (($1->query_desc())?($1->query_desc()):"none") :));
   add_option("personal real_name", OPTIONS_TYPE_STRING, 0,
              (: strlen($3) > 30?0:($1->set_real_name($3 == "none"?0:$3), 1) :),
              (: (($1->query_real_name())?($1->query_real_name()):"none") :));
   add_option("personal location", OPTIONS_TYPE_STRING, 0,
              (: strlen($3) > 30?0:($1->set_where($3 == "none"?0:$3), 1) :),
              (: (($1->query_where())?($1->query_where()):"none") :));
   add_option("personal home_page", OPTIONS_TYPE_STRING, 0,
              (: strlen($3) > 30?0:($1->set_homepage($3 == "none"?0:$3), 1) :),
              (: (($1->query_homepage())?($1->query_homepage()):"none") :));
   add_option("personal email", OPTIONS_TYPE_STRING, 0,
              (: strlen($3) > 30?0:($1->set_email($3 == "none"?0:$3), 1) :),
              (: (($1->query_email())?($1->query_email()):"none") :));
   add_option("personal birthday", OPTIONS_TYPE_STRING, 0,
              (: (!valid_birthday($3) || !$1->query_birthday())? 0:($1->set_birthday($3 == "none"?0:$3), 1) :),
              (: (($1->query_birthday())?($1->query_birthday()):"none") :));
} /* create() */

/**
 * This method adds in an option for the player to be able to set to
 * a mapping.  This method should be used by all the dynamic tree
 * methods to create leaves.
 * @param array the mapping to add the elements to
 * @param path the path to the option eg: ({ "output", "look" })
 * @param type the type of the option eg: OPTIONS_TYPE_BRIEF
 * @param set_function the function to call to set the option
 * @param query_function the function to call to query the option
 * @return 1 if successful, 0 if not
 */
protected void add_option_to_mapping(mapping array,
                         string name, mixed type, int cre_only,
                         function set_function,
                         function query_function) {
   class option fluff;

   //
   // Got to the end.
   //
   fluff = new(class option);
   fluff->type = type;
   fluff->set = set_function;
   fluff->query = query_function;
   fluff->cre_only = cre_only;
   array[name] = fluff;
} /* add_option() */

/**
 * This method adds in an option for the player to be able to set.
 * The set function will be called with two parameters, the value to
 * set it to and the variable being set.  The set function must return
 * 1 if the value was successfuly set.
 * <p>
 * int set_function(variable, value);
 * @param path the path to the option eg: ({ "output", "look" })
 * @param type the type of the option eg: OPTIONS_TYPE_BRIEF
 * @param set_function the function to call to set the option
 * @param query_function the function to call to query the option
 * @return 1 if successful, 0 if not
 */
protected int add_option(string name, mixed type, int cre_only,
                         function set_function,
                         function query_function) {
   string option;
   mapping stuff;
   string *path;

   path = explode(name, " ");
   stuff = _options;
   foreach (option in path[0..<2]) {
      if (!stuff[option]) {
         stuff[option] = ([ ]);
      } else if (!mapp(stuff[option])) {
         return 0;
      }
      stuff = stuff[option];
   }

   add_option_to_mapping(stuff, path[<1], type, cre_only, set_function,
                         query_function);
   return 1;
} /* add_option() */

private mixed query_sub_option(object player, string name, mapping tree) {
   mixed tmp;

   if (mapp(tree[name])) {
      return tree[name];
   }

   if (classp(tree[name])) {
      if (tree[name]->type == OPTIONS_TYPE_DYNAMIC_GROUP) {
         if (tree[name]->cre_only && !creatorp(player)) {
            return 0;
         } else {
            tmp = evaluate(tree[name]->query, player, name);
            return tmp;
         }
      }
      return tree[name];
   }
   return 0;
} /* query_sub_option() */

private mixed query_bottom_sub_option(object player, string* path) {
   string option;
   mixed stuff;

   if (!sizeof(path)) {
      return _options;
   }
   stuff = _options;
   foreach (option in path[0..<2]) {
      stuff = query_sub_option(player, option, stuff);
      if (!mapp(stuff)) {
         return 0;
      }
   }
   stuff = query_sub_option(player, path[<1], stuff);
   if (classp(stuff)) {
      if (stuff->cre_only && !creatorp(player)) {
         return 0;
      }
   }
   return stuff;
} /* query_bottom_sub_option() */

/**
 * This method checks to see if the specified option path exists.  This
 * will only return true if it is an actual option, not an option group.
 * @param player the player this is relative to
 * @param name the option path to check
 * @return 1 if it is an option, 0 if not
 */
int is_option(object player, string name) {
   mixed stuff;
   string *path;

   path = explode(name, " ");
   stuff = query_bottom_sub_option(player, path);
   if (!classp(stuff)) {
      return 0;
   }
   return 1;
} /* is_option() */

/**
 * This method checks to see if the specified option group path exists.  This
 * will only return true if it is an option group, not an actual option.
 * @param player the player this is relative to
 * @param name the option path to check
 * @return 1 if it is an option group, 0 if not
 */
int is_option_group(object player, string name) {
   mixed stuff;
   string *path;

   path = explode(name, " ");
   stuff = query_bottom_sub_option(player, path);
   if (!mapp(stuff)) {
      return 0;
   }
   return 1;
} /* is_option() */

/**
 * This method returns all the sub options and option groups at this
 * level.
 * @param player the player this is relative to
 * @param name the path to return the suboptions of
 * @return the sub options of the path
 */
string *query_sub_options(object player, string name) {
   mapping stuff;
   string *path;

   path = explode(name, " ");
   stuff = query_bottom_sub_option(player, path);
   if (mapp(stuff)) {
      return filter(keys(stuff),
                    (: query_bottom_sub_option($2, $3 + ({ $1 })) :),
                    player, path);
   }
   return ({ });
} /* query_sub_options() */

/**
 * This method returns the different values this option can be
 * set to.
 * @param player the player this is relative to
 * @param name the name of the option
 * @return the allowed parameters
 */
string* query_option_values(object player, string name) {
   mixed stuff;
   string *path;

   path = explode(name, " ");
   stuff = query_bottom_sub_option(player, path);
   if (classp(stuff)) {
      if (intp(stuff->type)) {
         switch (stuff->type) {
         case OPTIONS_TYPE_BOOLEAN :
            return ({ "on", "off" });
         case OPTIONS_TYPE_BRIEF :
            return ({ "brief", "verbose" });
         case OPTIONS_TYPE_INTEGER :
            return ({ "integer" });
         case OPTIONS_TYPE_STRING :
            return ({ "string" });
         case OPTIONS_TYPE_PERCENTAGE :
            return ({ "0..100" });
         case OPTIONS_TYPE_COLOUR :
            return ({ "none", "default", "colour" });
         }
      } else {
         return stuff->type;
      }
   }
   return ({ });
} /* query_option_values() */

/**
 * This method returns the value of the specified option.
 * @param player the player to find the value on
 * @param path the path to the option
 */
string query_option_value(object player, string path) {
   string* bits;
   mixed value;
   mixed stuff;

   bits = explode(path, " ");
   stuff = query_bottom_sub_option(player, bits);
   if (classp(stuff)) {
      value = evaluate(stuff->query, player, bits);
      if (intp(stuff->type)) {
         switch (stuff->type) {
         case OPTIONS_TYPE_BRIEF:
            if (value) {
               value = "verbose";
            } else {
               value = "brief";
            }
            break;
         case OPTIONS_TYPE_BOOLEAN :
            if (value) {
               value = "on";
            } else {
               value = "off";
            }
            break;
         case OPTIONS_TYPE_COLOUR :
            if (value == "") {
               value = "[none]";
            } else if (value == "default") {
               value = "[default]";
            } else {
               value = "[" + value + "" +
                       lower_case(replace(value, ({ "%^%^", " ", "%^", "" }))) +
                       "%^RESET%^]";
            }
            break;
         default :
         }
      }
      return value + "";
   }
} /* query_option_value() */

/**
 * This method sets an option value on the player.
 * @param player the player to find the value on
 * @param path the path to the option
 * @param value the value directly from the command line
 */
int set_option_value(object player, string path, string value) {
   string* bits;
   string* bad;
   mixed set_value;
   mixed stuff;

   bits = explode(path, " ");
   stuff = query_bottom_sub_option(player, bits);
   if (classp(stuff)) {
      if (pointerp(stuff->type)) {
         if (member_array(value, stuff->type) == -1) {
            add_failed_mess("You must set your type to one of " +
                            query_multiple_short(stuff->type) + ".\n");
            return 0;
         }
         set_value = value;
      } else switch (stuff->type) {
      case OPTIONS_TYPE_BRIEF:
         if (value == "verbose") {
            set_value = 1;
         } else if (value == "brief") {
            set_value = 0;
         } else {
            return 0;
         }
         break;
      case OPTIONS_TYPE_BOOLEAN :
         if (value == "on" || value == "true") {
            set_value = 1;
         } else if (value == "off" || value == "false") {
            set_value = 0;
         } else {
            return 0;
         }
         break;
      case OPTIONS_TYPE_PERCENTAGE :
      case OPTIONS_TYPE_INTEGER :
         if (sscanf(value, "%d", set_value) != 1) {
            return 0;
         }
         if (stuff->type == OPTIONS_TYPE_PERCENTAGE &&
             (set_value < 0 || set_value > 100)) {
            add_failed_mess("Value must be between 0 and 100.\n");
            return 0;
         }
         break;
      case OPTIONS_TYPE_COLOUR :
         if (value == "none" || value == "default") {
            set_value = value;
         } else {
            set_value = map(explode(value, " "),
                         (: upper_case($1) :));
            bad = filter(set_value, (: member_array($1, _colours) == -1 :));
            if (sizeof(bad)) {
               add_failed_mess("Bad colours " + implode(bad, " ") + ".\n");
               return 0;
            }
            set_value = "%^" + implode(set_value, (: $1 + "%^ %^" + $2 :)) + "%^";

         }
         break;
      default :
         set_value = value;
         break;
      }
      return evaluate(stuff->set, player, bits, set_value);
   }
   return 0;
} /* set_option_value() */

private mapping get_inform_colours(object player) {
   string* colours;
   string womble;
   mapping ret;
   string index;

   if (creatorp(player)) {
      index = "colour 1";
   } else if (lordp(player)) {
      index = "colour 2";
   } else {
      index = "colour 0";
   }

   if (_cache_input[index]) {
      return _cache_input[index];
   }

   colours = player->query_inform_types();
   ret = ([ ]);
   foreach (womble in colours) {
      add_option_to_mapping(ret, womble, OPTIONS_TYPE_COLOUR, 0,
                 (: $1->set_my_colours($2[<1], $3), 1 :),
                 (: $1->colour_event($2[<1], "default") :));
   }
   _cache_input[index] = ret;
   return ret;
} /* get_inform_colours() */

private mapping get_club_colours(object player) {
   string* colours;
   string womble;
   mapping ret;
   string index;

   index = "colour " + player->query_name();
   if (_cache_input[index]) {
      return _cache_input[index];
   }

   colours = map(this_player()->query_player_clubs(),
                 (: CLUB_HANDLER->normalise_name($1) :) );
   ret = ([ ]);
   foreach (womble in colours) {
      add_option_to_mapping(ret, womble, OPTIONS_TYPE_COLOUR, 0,
                 (: $1->set_my_colours("club_" + $2[<1], $3), 1 :),
                 (: $1->colour_event("club_" + $2[<1], "default") :));
   }
   _cache_input[index] = ret;
   call_out((: map_delete(_cache_input, $1) :), 5 * 60, index);
   return ret;
} /* get_inform_colours() */

private int change_ambiguous(object player, int new_value) {
   if (new_value) {
      player->add_property(OBJ_PARSER_AMBIGUOUS_PROP, 1);
   } else {
      player->remove_property(OBJ_PARSER_AMBIGUOUS_PROP);
   }
   return 1;
} /* change_ambiguous() */

private int change_earmuffs(object player, string ear, int new_value) {
   string *on;

   on = player->query_property("earmuffs");
   if (!on) {
      on = ({ });
   }
   if (new_value) {
      if (member_array(ear, on) == -1) {
         on += ({ ear });
         player->add_property("earmuffs", on);
      }
   } else {
      on -= ({ ear });
      player->add_property("earmuffs", on);
   }
   return 1;
} /* change_earmuffs() */

private int valid_birthday(string str) {
#define LENGTHS ({ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 })

  int tot, month, day;

  if(strlen(str) != 4) {
    return 0;
  }
  if(!sscanf(str, "%d", tot)) {
    return 0;
  }
  month = tot % 100;
  day = tot / 100;
  if(month > 12 || month < 1) {
    return 0;
  }
  if(day < 1) {
    return 0;
  }
  return day <= LENGTHS[month];
} /* valid_birthday() */

