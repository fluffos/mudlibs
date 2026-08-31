#include <std.h>
#include <daemons.h>
#include <flags.h>

#define tp this_player()

#define TIRUN_DIR "/d/nopk/tirun/"
#define DEFAULT_START TIRUN_DIR+"square"

#define HELP_CMD "/cmds/mortal/_help"

#define MIN_REMORT_LEVEL 50

#define PK_WAIT 60*60*24*2 // two full days

//not currently checking for stealing, leave that up to justice to catch them
#define STEAL_WAIT 60*60*24 // one full day

// remort_wait is in hours
#define REMORT_WAIT 30

#define DISABLE_REMORT 0

inherit DAEMON;


string *RACES_SAVED_ONCE = ({ "archangel", "demon" });
string col1 = "%^BOLD%^%^BLUE%^";
string col2 = "%^RESET%^";


int check_requirements();
varargs int check_sub(mapping data, string sub, string *allowedsubs, string race);
int check_race(mapping data, string sub);
int check_first(mapping data, string race);
int cmd_remort_list(mapping data);
int cmd_remort_show(mapping data, string sub);
int cmd_remort_clear(mapping data, string sub);
void ask_clearsub(string answer, mapping data, string sub);
int cmd_remort_into(mapping data, string *allowedsubs, string sub);
void ask_entersub(string answer, mapping data, string *allowedsubs);
void ask_confirm(string answer, mapping data, string *allowedsubs, string sub);
void ask_race(string answer, mapping data, string *allowedsubs, string sub);
void remort_player(mapping data, string sub);
void show_help(string what);


void help() {
  message("help",
   "Syntax: <remort>\n"
   "        <remort list>\n"
   "        <remort show [subclass]>\n"
   "        <remort clear [subclass]>\n"
   "        <remort into [subclass]>\n"
   "\n"
   "This command allows you to save your current character information "
   "and change to another subclass. Race, skills, stats, level, current exp, "
   "and alignment are saved for your current subclass. You keep your current "
   "inventory, though you may drop some if you are not strong enough to carry "
   "it all in your new form, and some items may no longer autoload.\n"
   "\n"
   "You must be at least level "+MIN_REMORT_LEVEL+
   " to use remort the first time.\n"
   "You may only remort once every "+REMORT_WAIT+" hours.\n"
   "It is only possible to remort while in Tirun.",
   tp );
}


int cmd_remort(string str) {
  mapping data;
  string cmd, sub;
  string *allowedcl;
  string *allowedsubs;
  string *dragonsubs;

  if (DISABLE_REMORT && !wizardp(tp))
    return notify_fail("This is being worked on.\n");

  data = tp->query_remort_data() || ([]);

  allowedcl = ({ "fighter", "rogue", "mage", "clergy", "wanderer" });
  allowedsubs = ({});
  foreach (string cl in allowedcl)
    allowedsubs += SKILLS_D->query_subclasses(cl) | ({});

  // intersection: dragonsubs contains array entries that are in BOTH arrays
  dragonsubs = SKILLS_D->query_subclasses("dragon") & keys(data);
  if (sizeof(dragonsubs)) {
    allowedcl += ({ "dragon" });
    allowedsubs += dragonsubs;
  }

  if (str && sscanf(str, "%s %s", cmd, sub) != 2) {
    if (member_array(str, allowedsubs) != -1) {
      cmd = "into";
      sub = str;
    }
    else {
      int space = strsrch(str, " ");
      if (space == -1) {
        cmd = str;
      }
      else {
        cmd = str[0..space-1];
        str = str[space+1..<1];
      }
    }
  }

  switch (cmd) {
    case "list":
      return cmd_remort_list(data);
    break;

    case "show":
      return cmd_remort_show(data, sub);
    break;

    default:
    case "into":
      return cmd_remort_into(data, allowedsubs, sub);
    break;

    case "clear":
      return cmd_remort_clear(data, sub);
    break;
  }

  return 1;
}

// check if player is allowed to remort
int check_requirements() {
  int *info;
  int tmp;

  info = (int *)tp->query_property("last remort") || ({ 0, 0 });

  if (file_name(environment(tp))[0..sizeof(TIRUN_DIR)-1] != TIRUN_DIR)
    return notify_fail("You may only remort while in Tirun.\n");

  if (tp->query_last_pk_time()+PK_WAIT > time())
    return notify_fail("You must wait longer to remort after you PK.\n");

  if (tp->query_recent_outlaw())
    return notify_fail("You cannot remort while you're an outlaw.\n");

  if (tp->query_poisoned() || tp->query_bleeding())
    return notify_fail("It would be too dangerous to change while you're losing health.");

  if (sizeof((string)tp->query_party()))
    return notify_fail("You must leave your party first.\n");

  if (tp->query_race() == "vampire" || tp->query_race() == "lich")
    return notify_fail("This command cannot handle the nuances of "+
     pluralize(tp->query_race())+" yet.\n");

  if (!(tp->query_subclass()) || tp->query_subclass() == "none")
    return notify_fail("You must pick a class and subclass first.\n");

  tmp = REMORT_WAIT*60*60 - (time() - info[0]);
  if (tmp > 0)
    return notify_fail("You may only remort once every "+REMORT_WAIT+" hours.\n"
                       "You have " + format_time(tmp) + " to wait.");

  if (!sizeof(info) && tp->query_level() < MIN_REMORT_LEVEL && !tp->query_property("can remort") &&
      !tp->query_remorted() && member_array(tp->query_race(), ({"archangel","demon"})) == -1)
        return notify_fail("You must reach level "+MIN_REMORT_LEVEL+" at least once before remorting.\n");

  return 1;
}

// check if player is allowed to remort into a certain subclass
varargs int check_sub(mapping data, string sub, string *allowedsubs, string race) {
  string *tmp = ({});

  if (!data || !sub) return 0;

  tmp |= keys(data);
  if (allowedsubs) tmp |= allowedsubs;

  if (race) {
    switch (race) {
      case "archangel":
        tmp -= ({ "kataan", "antipaladin", "necromancer" });
        // not sure if we want to do this
        // tmp -= ({ "thug", "thief", "assassin", "scout" });
      break;

      case "demon":
        tmp -= ({ "cleric", "druid", "paladin" });
      break;

      case "dragon":
        tmp &= SKILLS_D->query_subclasses("dragon");
      break;
    }
  }

  tmp -= ({ "illusionist", "conjurer", "shaman" });

  if (member_array(sub, tmp) != -1)
    return 1;

  return 0;
}

// check if a subclass has a race set already
// previously, you kept one race for all remorts
int check_race(mapping data, string sub) {
  if (data[sub] && data[sub]["race"] && data[sub]["race"] != "none") return 1;
  return 0;
}

// check for first remort using a special race
int check_first(mapping data, string race) {
  string cursub = tp->query_subclass();
  if (member_array(race, RACES_SAVED_ONCE) != -1 &&
      !(data[cursub] && data[cursub]["race"] && data[cursub]["race"] == race))
        return 1;
  return 0;
}

int cmd_remort_list(mapping data) {
  if (!sizeof(data)) {
    return notify_fail("You have no remort info saved.");
  }
  message("info",
    header_line("Remort") + "\n" +
    "You have saved information for the following subclasses:\n" +
    header_line() + "\n" +
    col1 +
    format_columns(
      map(keys(data), (:
        capitalize($1)+
        (SKILLS_D->query_class($1) == "dragon" ? " Dragon" : "")
      :) ),
      3, 80, "    ", "left"
    ) + 
    header_line() + "%^RESET%^\n",
    tp
  );
  return 1;
}

int cmd_remort_show(mapping data, string sub) {
  if (!sizeof(data) || !sizeof(data[sub])) {
    return notify_fail("You have not saved any remort information for that subclass.");
  }

  message("info",
    header_line("Remort") + "\n" +
    sprintf(
      "%s%9s : %s%-12s    %s%10s : %s%-10s\n"
      "%s%9s : %s%-12s    %s%10s : %s%-10s\n"
      "%s%9s : %s%-12d    %s%10s : %s%-d\n",
      col1, "Subclass", col2, capitalize(sub),
      col1, "Class", col2, capitalize(SKILLS_D->query_class(sub)),
      col1, "Race", col2, capitalize(data[sub]["race"] || "none"),
      col1, "Alignment", col2, capitalize(query_alignment_title(data[sub]["alignment"])),
      col1, "Level", col2, data[sub]["level"],
      col1, "Experience", col2, data[sub]["exp"],
    ) + header_line() + "\n" +
    sprintf(
      "%s%9s : %s%3d    %s%12s : %s%3d    %s%12s : %s%3d\n"
      "%s%9s : %s%3d    %s%12s : %s%3d    %s%12s : %s%3d\n",
      col1, "Strength", col2, data[sub]["stats"]["strength"],
      col1, "Constitution", col2, data[sub]["stats"]["constitution"],
      col1, "Dexterity", col2, data[sub]["stats"]["dexterity"],
      col1, "Charisma", col2, data[sub]["stats"]["charisma"],
      col1, "Intelligence", col2, data[sub]["stats"]["intelligence"],
      col1, "Wisdom", col2, data[sub]["stats"]["wisdom"]
    ) + header_line() + "%^RESET%^\n",
    tp
  );
  return 1;
}

int cmd_remort_clear(mapping data, string sub) {
  if (!cmd_remort_show(data, sub)) return 0;

  ask_clearsub(0, data, sub);

  return 1;
}

void ask_clearsub(string answer, mapping data, string sub) {

  if (answer == 0) {
    message("info",
      "%^BOLD%^%^RED%^"
      "Warning: This will delete the remort information for "+capitalize(sub)+".\n"
      "There is no way to get it back. This will NOT allow you to do special race quests again.\n"
      "If you delete one it is probably gone forever."
      "%^RESET%^",
      tp
    );
    message("no_wrap", "Are you sure you want to clear the save data for "+sub+"?  ", tp);
    input_to("ask_clearsub", I_NOESC, data, sub);
    return;
  }

  else if (answer == "yes" || answer == "y") {
    tp->clear_remort_sub_data(sub);
    message("info", "Cleared saved data for "+sub+".", tp);
    return;
  }

  message("info", "Aborting.", tp);
}

int cmd_remort_into(mapping data, string *allowedsubs, string sub) {
  if (!data || !allowedsubs) return;

  if (!check_requirements()) return 0;

  if (sub) {
    if (!cmd_remort_show(data, sub))
      message("info", header_line("Remort"), tp);

    ask_entersub(sub, data, allowedsubs);
  }

  else {
    ask_entersub(0, data, allowedsubs);
  }

  return 1;
}

void ask_entersub(string answer, mapping data, string *allowedsubs) {
  string what;

  // return from each block that should not input back into this func

  // entry point from cmd_remort_into with no subclass specified
  if (answer == 0) {
    if (!cmd_remort_list(data))
      message("info", header_line("Remort"), tp);

    message("info", "You can enter \"quit\" at any time to quit.", tp);
  }

  else if (answer == tp->query_subclass()) {
    message("info", "You are already in that form.", tp);
    return;
  }

  else if (answer == "quit" || answer == "q") {
    message("info", "Remort cancelled.", tp);
    return;
  }

  else if (sscanf(answer, "help %s", what) == 1 ||
           sscanf(answer, "h %s", what) == 1) {
             show_help(what);
  }

  else if (!check_sub(data, answer, allowedsubs)) {
    message("info", "You may not remort into that.", tp);
  }
  
  else {
    ask_confirm(0, data, allowedsubs, answer);
    return;
  }

  message("no_wrap", "What subclass would you like to remort into?  ", tp);
  input_to("ask_entersub", I_NOESC, data, allowedsubs);
}

void ask_confirm(string answer, mapping data, string *allowedsubs, string sub) {
  if (answer == 0) {
    message("no_wrap", "Are you sure you want to remort into "+
      indefinite_article(sub)+
      (SKILLS_D->query_class(sub) == "dragon" ? " dragon" : "" ) + "?  ", tp);
    input_to("ask_confirm", I_NOESC, data, allowedsubs, sub);
    return;
  }
  else if (answer == "y" || answer == "yes") {
    ask_race(0, data, allowedsubs, sub);
    return;
  }
  message("info", "Remort cancelled.", tp);
}

void ask_race(string answer, mapping data, string *allowedsubs, string sub) {
  string cur_race = tp->query_race();
  string cur_sub = tp->query_subclass();
  int first;
  
  if (!data[sub]) data[sub] = ([]);
  if (!data[cur_sub]) data[cur_sub] = ([]);

  first = check_first(data, cur_race);

  // entry point from ask_confirm
  if (answer == 0) {
    // if race already set, use it
    // races were never set before this update,
    // so first time users will not hit this
    if (check_race(data, sub)) {
      remort_player(data, sub);
      return;
    }
    else if (SKILLS_D->query_class(sub) == "dragon") {
      data[sub]["race"] = "dragon";
      remort_player(data, sub);
      return;
    }
    // some races can only be used for one sub, first remort with that race
    // decides which sub it will be saved in
    else if (first) {
      message("info",
        "%^BOLD%^%^CYAN%^"
        "The fate of your quest race rests in your decision here.\n"
        "\n"
        "If you choose "+cur_race+" here, you will become "+
        indefinite_article(cur_race)+" "+sub+". You will not be able "
        "to use "+cur_race+" for any future remorts, not even your "
        "current subclass.\n"
        "\n"
        "If you choose a different race, your current subclass "
        "will be "+indefinite_article(cur_race)+". You will not be able "
        "to use it for other subclasses.\n"
        "\n"
        "In essence: use "+cur_race+" for your new subclass, or use "
        "it for the current one.\n"
        "\n"
        "If you are unsure what this means, enter \"quit\" now."
        "%^RESET%^",
        tp
      );
    }

  }
  else if (sizeof(answer) && (answer == "quit" || answer == "q")) {
    message("info", "Remort cancelled.", tp);
    return;
  }
  else if (
    (!check_sub(data, sub, allowedsubs, answer)) ||
    (!(first && answer == tp->query_race()) &&
    member_array(answer, RACE_D->query_new_player_races()) == -1)) {
      message("info", "That is not an appropriate race.", tp);
  }
  else {
    data[sub]["race"] = answer;
    // first time remort for some races:
    // if you choose the quest race you currently are, transfer it to the new
    // subclass and leave the old one with no race set yet
    // otherwise, save it with the old subclass like everyone else will always do
    // note that the remort code IGNORES the race setting if one is already set
    if (first && answer == cur_race)
      data[cur_sub]["race"] = "none";
    else
      data[cur_sub]["race"] = cur_race;
    remort_player(data, sub);
    return;
  }

  message("no_wrap",
    "Please choose a race for the "+sub+" subclass:  ", tp);
  input_to("ask_race", I_NOESC, data, allowedsubs, sub);
}

void remort_player(mapping data, string sub) {
  string tmp;
  string startroom;
  string cls;
  int newtitle;
  int intox, quenched, stuffed, hp, sp, mp;
  object *obs;

  cls = SKILLS_D->query_class(sub);
  if (cls == "dragon") tmp=sub+" dragon";
  else tmp = sub;

  message("info", "%^GREEN%^%^BOLD%^"
    "Your mind begins to cloud as you change into "+
    indefinite_article(tmp)+".%^RESET%^", tp);

  // move it all out to avoid bugs relating to carrying capacity
  // being changed drastically
  obs = all_inventory(tp);
  obs->silent_unequip();
  obs->move(environment(tp));

  if (tp->query_invis()) tp->set_invis(0);

  hp = tp->query_hp() * 100 / tp->query_max_hp();
  sp = tp->query_sp() * 100 / tp->query_max_sp();
  mp = tp->query_mp() * 100 / tp->query_max_mp();
  intox = tp->query_intox() * 100 / tp->query_max_intox();
  quenched = tp->query_quenched() * 100 / tp->query_max_quenched();
  stuffed = tp->query_stuffed() * 100 / tp->query_max_stuffed();

  // the races are ignored by remort if one is set already
  tp->do_remort(sub, data[sub]["race"], data[tp->query_subclass()]["race"]);

  // set the player to have the same percentage of max
  tp->set_hp(tp->query_max_hp() * hp / 100);
  tp->set_sp(tp->query_max_sp() * sp / 100);
  tp->set_mp(tp->query_max_mp() * mp / 100);
  tp->set_intox(tp->query_max_intox() * intox / 100);
  tp->set_quenched(tp->query_max_quenched() * quenched / 100);
  tp->set_stuffed(tp->query_max_stuffed() * stuffed / 100);

  // this was previously used to track remorts per reboot
  // we just limit it by number of hours now
  // keeping the structure for backwards compatibility
  tp->remove_property("last remort");
  tp->set_property("last remort", ({ time(), 0 }) );

  tp->update_channels();
  tp->init_path();

  if (tp->query_level() < 20) {
    tp->setenv("TITLE", ADVANCE_D->get_new_title(tp));
    message("info", "Your title has been reset.", tp);
  }

  startroom = tp->query_env("start");
  if (regexp(startroom, implode(keys(SKILLS_D->query_all_classes()), "|") )) {
    tp->set_primary_start(DEFAULT_START);
    message("info", "Your start room has been reset.", tp);
  }

  foreach (object ob in obs) {
    if (ob->move(tp)) {
      message("info", "You drop "+ ob->query_short()+".", tp);
      message("info", tp->query_cap_name()+" drops "+ob->query_short()+".",
        environment(tp), tp);
    }
  }

  tp->force_me("save");

  message("info", "%^BOLD%^%^GREEN%^Remort complete.%^RESET%^\n"+
    header_line()+"\n", tp);
}

void show_help(string what) {
  load_object(HELP_CMD)->show_help(what);
}

