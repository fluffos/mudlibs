/* source file -- Treasury */
/* creator -- Vhaeraun, 2/20/93 */
#include "money.h"
#include "path.h"
#define GUILDMASTER "fengarance"
#define MORE_FILE "/global/more_file"

  /* inheritance */
inherit "/std/room";

  /* global variables */
string save_file;            /* path name of save file */
string log_file;             /* path name of transactions log */
string *treasurers;          /* names of players with treasury access */
int coppers;                 /* total amount of coppers in treasury */

  /* function declarations */
void load_it();
void save_it();
int add_treasurer(string name);
int remove_treasurer(string name);

  /* function definitions */
void create()
{
  string *strs;

  save_file = file_name(this_object()) + "_save";
  log_file = file_name(this_object()) + "_log/";
  strs = explode(log_file, "/");
  log_file = implode(strs, "_");
  treasurers = ({ });
  coppers = 0;
  ::create();
  load_it();
}

void setup()
{
  set_short("Treasury");
  set_long("The walls of this room are smooth, shiny, slightly "+
    "reflective and clearly transparent.  In the wall opposite "+
    "from the entrance, a glowing hemisphere is embedded "+
    "into the wall and provides light for the whole "+
    "room.  Stacks of gold, platinum, and silver coins "+
    "line the walls.  Gems and jewels are scattered "+
    "like marbles all over the floor.  Unfortunately, "+
    "it's all locked in a glasssteel vault.\n");
  set_light(70);
  set_zone("private");
    /* items */
  add_item( ({ "hemisphere", "globe" }), "The globe furnishes "+
    "reflective light for the entire chamber.  That appears "+
    "to be its only purpose.\n");
  add_item( ({ "vault", "treasury", "safe" }), "The vault is "+
    "like no other safe you have ever seen.  You are standing "+
    "inside the room, but the vault lies on the other side of "+
    "the walls.  There is no apparent access to the treasure "+
    "that appears in the vault without.\n");
    /* exits */
  add_exit("out", ROOM + "office", "door");
}

void init()
{
  ::init();
  add_action("do_deposit", "deposit");
  add_action("do_withdraw", "withdraw");
  add_action("do_balance", "balance");
  add_action("do_treasurer", "treasurer");
  add_action("do_transactions", "transactions");
}

int do_balance() {
  if (member_array(this_player()->query_name(), treasurers) == -1) {
    notify_fail("Only treasurers can estimate the balance.\n");
    return 0;
  }
  if (!coppers) {
    write("The vaults are empty.\n");
    return 1;
  }
  write("There is "+MONEY_HAND->money_value_string(coppers)+
    " in the treasury.\n");
  return 1;
}

int do_withdraw(string str) {
  int amt, i, val;
  string s1, type;
  mixed *values;

  if (member_array(this_player()->query_name(), treasurers) == -1) {
    notify_fail("Only treasurers can withdraw money from the vault.\n");
    return 0;
  }
  notify_fail("Syntax: "+query_verb()+" <amount> <type> coin[s]\n");
  if (!str)
    return 0;
  if (sscanf(str, "%d %s coin%s", amt, type, s1) != 3 &&
      sscanf(str, "%d %s", amt, type) != 2)
    return 0;
  if (amt <= 0) {
    notify_fail("You must withdraw something.\n");
    return 0;
  }
  values = (mixed *)MONEY_HAND->query_values();
  if ((i=member_array(type, values)) == -1) {
    notify_fail("I do not know of any "+type+" coins.\n");
    return 0;
  }
  val = amt*values[i+1];
  if (val > coppers) {
    write("There is not enough money in the treasury.\n");
    return 1;
  }
  this_player()->adjust_money(amt, type);
  coppers -= val;
  save_it();
  log_file(log_file, "WITHDRAWAL:  "+ this_player()->query_cap_name() +
    "  "+ ctime(time()) +"\n  "+amt+" "+type+" coins withdrawn.\n"+
    "  Balance of "+ MONEY_HAND->money_value_string(coppers) +
    " forwarded.\n\n");
  write("You withdraw "+amt+" "+type+" coins from the treasury.\n");
  say(this_player()->query_cap_name()+" withdraws some money from "+
    "the treasury.\n");
  return 1;
}

int do_deposit(string str) {
  object *obs, cont;
  int i, total_amt;

  if (!str) {
    notify_fail("Syntax: "+query_verb()+" <money>\n");
    return 0;
  }
  cont = clone_object("/std/container");
  obs = find_match(str, this_player());
  for (i=0;i<sizeof(obs);i++)
    if (obs[i]->query_property("money"))
      obs[i]->move(cont);
  if (!sizeof(all_inventory(cont))) {
    cont->dest_me();
    notify_fail("You might want to deposit some money.\n");
    return 0;
  }
  obs = all_inventory(cont);
  for (i=0;i<sizeof(obs);i++)
    total_amt += (int)obs[i]->query_value();
  if (!total_amt) {
    notify_fail("Your money is not worth anything.\n");
    return 0;
  }
  coppers += total_amt;
  save_it();
  log_file(log_file, "DEPOSIT:  "+this_player()->query_cap_name()+
    "  "+ctime(time())+"\n  "+MONEY_HAND->money_value_string(total_amt)+
    " deposited.\n  Balance of "+MONEY_HAND->money_value_string(coppers)+
    " forwarded.\n\n");
  write(capitalize((string)MONEY_HAND->money_value_string(total_amt))+
    " deposited to give a total amount of "+
    MONEY_HAND->money_value_string(coppers)+" in the treasury.\n");
  say(this_player()->query_cap_name()+" deposits some money into "+
    "the treasury.\n");
  cont->dest_me();
  return 1;
}

int do_appoint(string name) {
  if ((string)this_player()->query_name() == GUILDMASTER) {
    if (!name) {
      notify_fail("Syntax: appoint <player's name>\n");
      return 0;
    }
    name = lower_case(name);
    if (member_array(name, treasurers) == -1) {
      add_treasurer(name);
      log_file(log_file, "TREASURER: "+ capitalize(name) +
        " appointed as a treasurer.\n\n");
      write(capitalize(name) +" has been added as a treasurer.\n");
    } else {
      remove_treasurer(name);
      log_file(log_file, "TREASURER: "+ capitalize(name) +
        " removed as a treasurer.\n\n");
      write(capitalize(name) +" has been removed as a treasurer.\n");
    }
    return 1;
  }
  write("Only the Guildmaster may appoint treasurers.\n");
  return 0;
}

int do_treasurer(string name) {
  int i, n;

  if (member_array(this_player()->query_name(), treasurers) == -1)
    return 0;
  if (name)
    return (do_appoint(name));
  printf("Current Treasurers\n");
  for (i = 0, n = sizeof(treasurers); i < n; i++)
    printf("  %s\n", capitalize(treasurers[i]));
  return 1;
}

int do_transactions(string str) {
  if (member_array(this_player()->query_name(), treasurers) == -1)
    return 0;
  MORE_FILE->more_file("/log/"+ log_file);
  return 1;
}

string query_save_file() { return save_file; }
void set_save_file(string file_name) { save_file = file_name; }
string query_log_file() { return log_file; }
void set_log_file(string file_name) { log_file = log_file; }

string *query_treasurers() { return treasurers; }

int add_treasurer(string name) {
  if (member_array(name, treasurers) < 0) {
    treasurers += ({ name });
    save_it();
    return 1;
  }
  return 0;
}

int remove_treasurer(string name) {
  if (member_array(name, treasurers) >= 0) {
    treasurers  -= ({ name });
    save_it();
    return 1;
  }
  return 0;
}

void load_it() {
  if (save_file)
    restore_object(save_file);
}

void save_it() {
  if (save_file)
    save_object(save_file);
}
