//      Starting room for new characters choosing races
//      and classes
//      idea from nightmare
//      rewritten entirely by Gravity

#include <std.h>
#include <ansi.h>

#define CLS ESC + "[H" + ESC + "[2J"

#include <lib.h>
inherit LIB_ROOM;

void do_rolls();
void assign_point(string str, int *points, int pts_left);
void set_ansi();

string * _occs = ({"Coalition Grunt"});

void create()
{
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no attack", 1);
  set_property("no scry", 1);
  set_property("no teleport", 1);
  set_property("no summon", 1);
  set_property("no cast", 1);
  set("long",
      "This is the Character generator\n\n"
      " type \"help races\" to see a list of race selections.\n"
      " type \"pick <race>\" to select your race and begin\n");
  //skip_obvious();
}

void init()
{
  ::init();
  this_player()->setenv("SCORE", "off");
  this_player()->set("in creation", 1);
  this_player()->set_catch("off");
  //add_action("read", "read");
  //add_action("set_ansi", "ready");
  add_action("pick_race", "pick");
  add_action("choose_occ","choose");
}

mapping s1_rolling_attributes() {
  mapping attrib = (["iq":0, "me":0, "ma":0, "ps":0, "pp":0, "pe":0, "pb":0, "spd":0]);
  string *keys = keys(attrib);
  int extra;
  for(int x =0; x < sizeof(keys);x++) {
      attrib[keys[x]] = roll("3d6");
      if(attrib[keys[x]] >= 16) {
        extra = roll("1d6");
        if(extra == 6)
          extra += roll("1d6");
        attrib[keys[x]] += extra;
      }
  }
  return attrib;
}

void show_attrib(mapping attrib) {
  write(sprintf("IQ:  %2d", attrib["iq"]));
  write(sprintf("ME:  %2d", attrib["me"]));
  write(sprintf("MA:  %2d", attrib["ma"]));
  write(sprintf("PS:  %2d", attrib["ps"]));
  write(sprintf("PP:  %2d", attrib["pp"]));
  write(sprintf("PE:  %2d", attrib["pe"]));
  write(sprintf("PB:  %2d", attrib["pb"]));
  write(sprintf("Spd: %2d", attrib["spd"]));
}

void prompt_keep_attributes(mapping attrib, string race) {
  write("\nKeep these attributes? (y/n)?\n");
  input_to("keep_attrib", 0, attrib, race);
}
int number_low(mapping attrib) {
  string *keys;
  int count = 0;
  keys=keys(attrib);
  for(int x=0;x<sizeof(keys);x++) {
    if(attrib[keys[x]] < 7) {
      count++;
    }
  }
  return count;
}

void prompt_low_values(int low_values, mapping attrib, string race) {
  write(sprintf("\n  Stats that are low: %d!", low_values));
  write(sprintf("  Choose a stat to add 1d4+%d to: iq,ma,me,ps,pp,pe,pb,spd", low_values == 1 ? 3: 5 ));
  input_to("add_low_val", 0, low_values, attrib, race);
}

int pick_race(string race) {
  mapping attrib, racial_props;
  string *racial_keys;
  object who = this_player();
  int low_values=0, i;
  if(!race) {
    return notify_fail("pick [race] (see help races)\n");
  }
  who->set_race(race);
  who->new_body();
  who->add_sight_bonus((int)RACE_D->query_sight_bonus(race) -
                       (int)who->query_sight_bonus());
  racial_props = (mapping)RACE_D->query_racial_properties(race);
  if (mapp(racial_props))
  {
    racial_keys = keys(racial_props);
    i = sizeof(racial_keys);
    while (i--)
    {
      who->set_property(racial_keys[i],
                        racial_props[racial_keys[i]]);
    }
  }
  who->setenv("TITLE", "Novice $N the " + capitalize(race));
  //DEFAULT COMBAT COLOR
  who->set_property("combat color", "%^BOLD%^");
  //DEFAULT COMBAT COLOR
  switch(race) {
    case "human" :
      attrib = s1_rolling_attributes();
    break;
    default:
      return notify_fail("invalid race. see help races.\n");
  }
  show_attrib(attrib);
  low_values = number_low(attrib);
  if(low_values > 0) {
    prompt_low_values(low_values, attrib, race);
  }
  else
    prompt_keep_attributes(attrib, race);
  return 1;
}

void prompt_add_three(mapping attrib, string race, string expended) {
  write("You had 2 or more low stats.");
  write("choose a stat to add 3 to: iq,ma,me,ps,pp,pe,pb,spd");
  input_to("add_three", 0, attrib, race, expended);
}

int add_low_val(string stat, int low_values, mapping attrib, string race) {
  if(!attrib[stat]) {
    write("invalid stat try iq,ma,me,ps,pp,pe,pb,spd");
    prompt_low_values(low_values,attrib, race);
    return 1;
  }
  if(low_values == 1) {
    attrib[stat] += roll("1d4+3");
    show_attrib(attrib);
    prompt_keep_attributes(attrib, race);
  }
  else if(low_values >1) {
    attrib[stat] += roll("1d4+5");
    show_attrib(attrib);
    prompt_add_three(attrib, race, stat);//send the stat we just added to exclude it
  }
  return 1;
}

int add_three(string stat, mapping attrib, string race, string expended) {
  if(!attrib[stat]) {
    write("invalid stat try iq,ma,me,ps,pp,pe,pb,spd");
    prompt_add_three(attrib,race, expended);
    return 1;
  }
  if(expended == stat) {
    write("try another stat. you already added to "+stat);
    prompt_add_three(attrib,race,expended);
    return 1;
  }
  attrib[stat] += 3;
  show_attrib(attrib);
  prompt_keep_attributes(attrib, race);
  return 1;
}



int keep_attrib(string yn, mapping attrib, string race) {
  string *keys;
  int base_hp;
  if(yn != "y" && yn != "n")
    return notify_fail("y or n");
  if(yn =="y") {
    write("Keeping\n");
    keys = keys(attrib);
    for(int x=0;x < sizeof(keys);x++) {
      this_player()->set_stats(keys[x],attrib[keys[x]]);
    }
    base_hp = roll("1d6") + attrib["pe"];
    write(sprintf("Base HP is %d",base_hp));
    this_player()->set_max_hp(base_hp);
    this_player()->set_hp(base_hp);
    //IF not rcc
  }
  else if(yn == "n") {
    pick_race(race);
  }
  return 1;
}

void set_ansi()
{
  this_player()->setenv("TERM", "ansi");
  this_player()->reset_terminal();
  this_player()->reset_max_exp();
  write("\nOne more thing...\n%^RED%^Is this line red (y or n)?%^RESET%^");
  input_to("set_ansi_two");
}

void set_ansi_two(string str)
{

  str = arrange_string(lower_case(str), 1);
  if (str == "n")
  {
    write("Ok.  Terminal set to \"unknown.\"  See 'help setenv' for more info.");
    this_player()->setenv("TERM", "unknown");
    this_player()->reset_terminal();
    this_player()->move(ROOM_NEWBIE);
    if (wizardp(this_player()) || this_player()->query_property("reincarnate"))
    {
      write("You are done.");
      return;
    }

    return;
  }
  else if (str == "y")
  {
    write("Terminal set to ansi.");
    this_player()->move(ROOM_NEWBIE);
    if (wizardp(this_player()) || this_player()->query_property("reincarnate"))
    {
      write("You are done.");
      return;
    }

    return;
  }
  else
  {
    write("Answer y or n");
    input_to("set_ansi_two");
    return;
  }
}

int read(string str)
{
  if (!str)
  {
    notify_fail("What do you want to read? A list?\n");
    return 0;
  }
  if (str != "list")
  {
    notify_fail("That is not here to be read.\n");
    return 0;
  }
  write("These are the following races available in our reality:");
  write("-----------------------------------------------------------");
  message("Ninfo", format_page((string *)RACE_D->query_races(), 4),
          this_player());
  write("----------------------------------------------------------");
  write("pick <race> will forever make you one of these races");
  write("Type help <race> for more information.");
  return 1;
}

int choose_occ(string str) {
  object occ_obj;
  object *inv = filter_array(all_inventory(this_player()),
    (: call_other :), "query_is_occ_obj");
  if(inv)
    for(int x = 0;x<sizeof(inv);x++) {
      inv[x]->remove();
    }
  occ_obj = new ("/std/occ_picker");
  occ_obj->move(this_player());
  occ_obj->begin_selection();
  return 1;
}