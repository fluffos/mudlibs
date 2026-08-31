// inventory command
// Nulvect 2012-06-09

#include <std.h>

#define tp this_player()

#define COLOR_RESET "%^RESET%^"
#define COLOR_HEADER "%^BOLD%^%^WHITE%^"
#define COLOR_BAR "%^BOLD%^%^BLUE%^"
#define COLOR_SHORT COLOR_RESET+"%^WHITE%^"
#define COLOR_WEIGHT COLOR_RESET+"%^CYAN%^"
#define COLOR_WEIGHT_HEAVY "%^BOLD%^%^RED%^"
#define COLOR_AUTOLOAD_YES COLOR_RESET+"%^CYAN%^"
#define COLOR_AUTOLOAD_SOME COLOR_RESET+"%^ORANGE%^"
#define COLOR_AUTOLOAD_NO "%^BOLD%^%^RED%^"
#define COLOR_TOTALWEIGHT "%^BOLD%^%^CYAN%^"
#define COLOR_NUMBER "%^YELLOW%^"

#define WEIGHT_HEAVY_PERC 12


inherit DAEMON;


class InvLine {
  string short;
  string type;
  int count;
  int autoyes;
  int autono;
  int weight;
}


int cmd_inventory_number(string str, object player);
int cmd_inventory_sort(string str);
string get_short(object ob, int len);
int get_width(object player);
string get_autotext(class InvLine line);
string get_type(object ob);
string get_color(string which, mixed arg);
void msg(string str);
int sort_type(class InvLine a, class InvLine b);
int sort_name(class InvLine a, class InvLine b);
int sort_autoload(class InvLine a, class InvLine b);
int sort_weight(class InvLine a, class InvLine b);


void help() {
  message("help",
    "Syntax: <inventory>\n"
    "        <inventory (weapons | armour | wielded | worn | short)>\n"
    "\n"
    "        <inventory [item name]>\n"
    "        <inventory number [item name]>\n"
    "\n"
    "        <inventory sort (name | type | weight | autoload | none)>\n"
    "\n"
    "The inventory command shows what your character is carrying.\n"
    "Also displayed are the weight of the items, if they autoload or not, "
    "and a summary of total weight. You can carry up to 200% weight, "
    "but carrying more than 100% increases stamina usage.\n"
    "\n"
    "Items that do not autoload will be lost when you quit or otherwise "
    "log off. See <help autoload> for more information.\n"
    "\n"
    "By default, all items are shown. The categories \"weapons\", "
    "\"armour\", \"wielded\", and \"worn\" show only those items. "
    "The \"short\" category shows all items that are neither worn nor "
    "wielded.\n"
    "\n"
    "Other command arguments are taken as an identifier to search for.\n"
    "Example: <inventory sword> will show you everything you are carrying "
    "that is identified as a sword.\n"
    "\n"
    "Specifying \"number\" in front of an identifier will show all items "
    "with that identifier in a non-consolidated format, with a number "
    "in front that can be used to reference each item.\n"
    "Example: <inventory number sword>\n"
    "Output: \"1\" | A steel sword\n"
    "        \"2\" | A steel sword\n"
    "        \"3\" | A curved longsword\n"
    "In this example, <drop sword 3> will drop the curved longsword.\n"
    "\n"
    "The last option sets the sorting method for all inventory displays.\n"
    "\n"
    +(tp && wizardp(tp) ?
      "Immortals can <inventory player [name] [inv options]>.\n"
      "Example: <inventory player bob weapons>\n"
      "Autoload info may be incorrect with this method.\n\n" : ""
    )+
    "See also: equipment, wield, wear, autoload",
    tp
  );
}

int cmd_nulinv(string str) {
  object *ai;
  object player = tp;
  mapping lines = ([]);
  class InvLine *linearr;
  int totalweight, enc;
  int width, display_width = 25;
  string pname;
  string sort_type = "none";

  if (effective_light(tp) < -2) {
    return notify_fail("It is too dark.\n");
  }

  if (!str)
    str = "all";

  if (wizardp(tp)) {
    sscanf(str, "player %s %s", pname, str);
    if (!pname) {
      if (sscanf(str, "player %s", pname) == 1) {
	str = "all";
      }
    }
    if (pname) {
      player = find_player(pname);
      if (!player) {
	msg("No such player online.");
	return 1;
      }
    }
  }


  ai = all_inventory(player);

  switch (str) {
    case "all":
      // show everything
    break;

    case "weapon": 
    case "weapons":
    case "wep":
    case "weps":
      ai=filter(ai, (: $1->is_weapon() :) );
    break;

    case "armour": 
    case "armours": 
    case "armor":
    case "armors":
      ai=filter(ai, (: $1->is_armour() :) );
    break;

    case "worn":
    case "wear":
    case "wearing":
      ai=filter(ai, (: $1->query_worn() :) );
    break;

    case "wielded":
    case "wield":
    case "wielding":
      ai=filter(ai, (: $1->query_wielded() :) );
    break;

    case "short":
      ai=filter(ai, (:
	!( $1->query_worn() || $1->query_wielded() )
      :) );
    break;

    default: 
      if (sscanf(str, "number %s", str) == 1)
	return cmd_inventory_number(str, player);
      else if (sscanf(str, "sort %s", str) == 1)
	return cmd_inventory_sort(str);
      else
	ai=filter(ai, (: $1->id($2) :), str);
  }

  // subtract total width of display bars, autoload field, weight field,
  // everything except the short desc area
  width = get_width(tp) - display_width;

  msg( header_line("Inventory") );

  ai = filter(ai, (: strlen($1->query_short()) :) );

  foreach (object ob in ai) {
    string short;
    class InvLine line;

    short = get_short(ob, width);

    totalweight += ob->query_weight();

    if ((line = lines[short])) {
      line->count++;
      line->weight += ob->query_weight();
    }
    else {
      line = new(class InvLine);
      line->short = short;
      line->type = get_type(ob);
      line->count = 1;
      line->weight = ob->query_weight();
      line->autoyes = 0;
      line->autono = 0;
      lines[short] = line;
    }

    if (player->query_will_autoload(ob))
      line->autoyes++;
    else
      line->autono++;
  }

  if (!sizeof(lines))
    msg("You are not carrying anything.\n");
  else {
    msg(
      sprintf(
	"%s %15s %-*s %|10s %|8s %s\n"
	"%s+-" +
	repeat_string("-", width) +
	"-+----------+--------+%s",
	COLOR_HEADER, "", (width-14), "Name", "Autoload", "Weight", COLOR_RESET,
	COLOR_BAR, COLOR_RESET
      )
    );

    linearr = values(lines);

    sort_type = tp->getenv("INV_SORT");
    if (sort_type && sort_type != "none" &&
	function_exists("sort_" + sort_type, this_object())) {
	  linearr = sort_array(linearr, "sort_" + sort_type, this_object());
    }

    // we could just loop over 'lines' with foreach, but inventory command is used a lot,
    // so let's use efuns for speed when possible
    filter(linearr, function(class InvLine line, object player, int width) {
      string autotext = get_autotext(line);
      string col_auto, col_weight;

      col_auto = get_color("autoload", autotext);
      col_weight = get_color("weight", ({ player, line->weight }) );

      msg(
	sprintf("%s|%s %-*s %s|%s   %4s   %s|%s  %4d  %s|%s",
	  COLOR_BAR, COLOR_SHORT,
	  width, capitalize(consolidate(line->count, line->short)),
	  COLOR_BAR, col_auto,
	  autotext,
	  COLOR_BAR, col_weight,
	  line->weight,
	  COLOR_BAR, COLOR_RESET
	)
      );

      return 1;

    }, player, width );

    enc = player->query_max_internal_encumbrance()/2;

    msg(
      sprintf(
	"%s|-"
	"------------------------------------+"+
	repeat_string("-", width-37) +
	"-+----------+--------'%s\n"
	"%s|  %sTotal Weight: %s%-20s %s|%s\n"
	"%s'-------------------------------------'%s",
	COLOR_BAR, COLOR_RESET,
	COLOR_BAR, COLOR_TOTALWEIGHT, COLOR_SHORT,
	  sprintf("%d%% (%d/%d)", to_int(percent(totalweight, enc)), totalweight, enc),
	COLOR_BAR, COLOR_RESET,
	COLOR_BAR, COLOR_RESET
      )
    );
  }

  return 1;

}

int cmd_inventory_number(string str, object player) {
  object *ai;
  mapping lines = ([]);
  int num;
  int width, display_width = 31;

  ai=filter(all_inventory(player), (: $1->id($2) && strlen($1->query_short()):), str);

  msg( header_line("Inventory: " + COLOR_NUMBER + str + COLOR_RESET) );

  // subtract width of display bars and non-shortdesc fields
  width = get_width(tp) - display_width;
  num = sizeof(ai);

  if (!num)
    msg("You are not carrying anything by that name.");
  else {
    msg(
      sprintf(
	"%s  %3s  %9s %-*s %|10s %|8s %s\n"
	"%s+-----+-"+
	repeat_string("-", width) +
	"-+----------+--------+%s",
	COLOR_HEADER, "#", "", (width-8), "Name", "Autoload", "Weight", COLOR_RESET,
	COLOR_BAR, COLOR_RESET
      )
    );

    for (int i = 1; i <= num; i++) {
      object ob = ai[i-1];
      string autotext = (player->query_will_autoload(ob) ? "Yes" : "No");
      string col_auto = get_color("autoload", autotext);
      string col_weight = get_color("weight", ({ player, ob->query_weight() }) );

      msg(
	sprintf("%s|%s %3d %s|%s %-*s %s|%s   %4s   %s|%s  %4d  %s|%s",
	  COLOR_BAR, COLOR_NUMBER,
	  i,
	  COLOR_BAR, COLOR_SHORT,
	  width, capitalize(get_short(ob, width)),
	  COLOR_BAR, col_auto,
	  autotext,
	  COLOR_BAR, col_weight,
	  ob->query_weight(),
	  COLOR_BAR, COLOR_RESET
	)
      );
    }

    msg(
      sprintf(
	"%s|-----+-"+
	repeat_string("-", width) +
	"-+----------+--------'%s",
	COLOR_BAR, COLOR_RESET,
      )
    );
  }

  return 1;
}

int cmd_inventory_sort(string str) {
  if (str && function_exists("sort_" + str, this_object())) {
    tp->setenv("INV_SORT", str);
    msg("Inventory will now sort by "+str+".");
  }
  else {
    msg("Invalid sort type.");
  }
  return 1;
}

string get_short(object ob, int len) {
  string short;
  string more;

  short = ob->query_short();
  more = ob->query_short_more();
  if (more) short += more;
  short = strip_color(short);

  len--;

  return short[0..len];
}

int get_width(object player) {
  string tmp = player->getenv("SCREEN");
  int width = to_int(tmp);
  width -= 2;
  if (width < 75) width = 75;
  return width;
}

string get_autotext(class InvLine line) {
  string autotext;
  if (line->count == 1) {
    if (line->autoyes == 1)
      autotext = "Yes";
    else
      autotext = "No";
  }
  else if (line->count == line->autoyes)
    autotext = "All";
  else if (line->count == line->autono)
    autotext = "None";
  else
    autotext = "Some";
  return autotext;
}

string get_type(object ob) {
  if (ob->is_weapon()) return "weapon";
  if (ob->is_armour()) return "armour";
  if (ob->is_bag()) return "bag";
  if (ob->query_property("light")) return "light";
  if (ob->is_supply()) return "supply";
  return "misc";
}

string get_color(string which, mixed arg) {
  switch (which) {
    case "autoload":
      if (!stringp(arg)) return "";
      switch (arg) {
	case "Yes":
	case "All":
	  return COLOR_AUTOLOAD_YES;
	case "Some":
	  return COLOR_AUTOLOAD_SOME;
	case "No":
	case "None":
	  return COLOR_AUTOLOAD_NO;
      }
    break;

    case "weight":
      if (!arrayp(arg)) return "";
      if ( (arg[1] * 100 / arg[0]->query_max_internal_encumbrance()) >= WEIGHT_HEAVY_PERC )
	return COLOR_WEIGHT_HEAVY;
      return COLOR_WEIGHT;
    break;
  }

  return "";
}

void msg(string str) {
  message("info", str, tp);
}

int sort_weight(class InvLine a, class InvLine b) {
  if (a->weight > b->weight) return 1;
  if (b->weight > a->weight) return -1;
  return 0;
}

int sort_autoload(class InvLine a, class InvLine b) {
  mapping autovals = ([
    "Yes"  : 1,
    "All"  : 1,
    "Some" : 0,
    "No"   : -1,
    "None" : -1,
  ]);
  int val_a = autovals[ get_autotext(a) ];
  int val_b = autovals[ get_autotext(b) ];
  if (val_a > val_b) return 1;
  if (val_b > val_a) return -1;
  return 0;
}

int sort_name(class InvLine a, class InvLine b) {
  if (a->short > b->short) return 1;
  if (b->short > a->short) return -1;
  return 0;
}

int sort_type(class InvLine a, class InvLine b) {
  string *types = ({ "weapon", "armour", "bag", "light", "supply", "misc", });
  int val_a = member_array(a->type, types);
  int val_b = member_array(b->type, types);
  if (val_a == -1 || val_b == -1) return 0;
  if (val_a > val_b) return 1;
  if (val_b > val_a) return -1;
  return 0;
}

