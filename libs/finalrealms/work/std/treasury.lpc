/* source file -- Treasury, creator -- Vhaeraun, 2/20/93 */
/* Made /std/treasury.c, cleaned up alot, added and tweaked
   some functions - Radix, February 23, 1996

   Brief explaination of treasury.c
 
   This must be the first thing any group or guild purchaces
   before they can continue growing as guild/group.  Here they 
   will pool their money for future growth.   
   
   To the Patron or Thane creating this, all you have to do is 
   inherit this file just like you would /std/room.c and call
   one extra function in your setup(), that would set_admins().
   It should be an array of the very least the Patron of the
   vault and the group/guild's mortal administrator.  For example:
   set_admins( ({"radix","dorktheplayer"}) ); would grant Radix
   and Dorktheplayer admin access.
   Afterword, treasurers may be added by simple using the 
   "appoint" add_action in the room.  It is only available to
   administrators.  

   Admins - They can balance and look at logs
   Treasurer - They can WITHDRAW too

   Radix
*/
 
#include "money.h"
 
inherit "/std/room";
 
  /* global variables */
nosave string save_file;      /* path name of save file */
nosave string log_file;       /* path name of transactions log */
string *treasurers;    /* names of players with treasury access */
nosave string *admins;        /* admins of the guild/group */
int coppers;                 /* total amount of coppers in treasury */
 
  /* function declarations */
void load_it();
void save_it();
int add_treasurer(string name);
int remove_treasurer(string name);
int query_admin(string name);
int query_treasurer(string name);
 
void create()
{
  string *strs;
 
  save_file = file_name(this_object()) + "_save";
  log_file = file_name(this_object()) + "_log/";
  strs = explode(log_file, "/");
  log_file = "/d/aprior/logs/treasury/"+implode(strs, "_");
  treasurers = ({ });
  admins = ({ });
  coppers = 0;
  
  ::create();
  load_it();
}
// This is pissing me off - Radix
int clean_up(int i) { return 0; }
int clean_up_room(int i) { return 0; }
 
void init()
{
  ::init();
  add_action("do_deposit", "deposit");
  add_action("do_withdraw", "withdraw");
  add_action("do_balance", "balance");
  add_action("do_deposits", "deposits");
  add_action("do_treasurer", "treasurer");
  add_action("do_transactions", "transactions");
  add_action("do_appoint","appoint");
}
 
void set_admins(string *names) { admins = names; }
 
//Anirudh
int query_treasury() { return 1; }

int query_treasurer(string name)
{ 
   if(query_admin(name))
      return 1;
   if(!name || !stringp(name) || member_array(name,treasurers) == -1) 
      return 0;
   return 1;
}
 
int query_admin(string name)
{ 
   if(!name || !stringp(name) || member_array(name,admins) == -1) 
      return 0;
   return 1;
}
 
int do_balance() {
   if(!query_treasurer(this_player()->query_name())) {
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
 
  if(!this_player()->query_lord())
     if(!query_treasurer(this_player()->query_name())) {
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
  write_file(log_file, "WITHDRAWAL:  "+ this_player()->query_cap_name() +
    "  "+ ctime(time()) +"\n  "+amt+" "+type+" coins withdrawn.\n"
    "  Balance of "+ MONEY_HAND->money_value_string(coppers) +
    " forwarded.\n\n");
  write("You withdraw "+amt+" "+type+" coins from the treasury.\n");
  say(this_player()->query_cap_name()+" withdraws some money from "
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
  write_file(log_file, "DEPOSIT:  "+this_player()->query_cap_name()+
    "  "+ctime(time())+"\n  "+MONEY_HAND->money_value_string(total_amt)+
    " deposited.\n  Balance of "+MONEY_HAND->money_value_string(coppers)+
    " forwarded.\n\n");
  write_file(log_file+"_deposits",ctime(time())+" : "+this_player()->
     query_cap_name()+" deposited "+MONEY_HAND->money_value_string(total_amt)
     +".\n");
  write(capitalize((string)MONEY_HAND->money_value_string(total_amt))+
    " deposited to give a total amount of "+
    MONEY_HAND->money_value_string(coppers)+" in the treasury.\n");
  say(this_player()->query_cap_name()+" deposits some money into "
    "the treasury.\n");
  cont->dest_me();
  return 1;
}
 
int do_appoint(string name) {
  if(query_admin(this_player()->query_name())) {
    if (!name) {
      notify_fail("Syntax: appoint <name>\n\n"
         "Note: If <name> is already a treasurer, the "
         "name will be removed from the list instead.\n");
      return 0;
    }
    name = lower_case(name);
    if (member_array(name, treasurers) == -1) {
      add_treasurer(name);
      write_file(log_file, "TREASURER: "+ capitalize(name) +
        " appointed as a treasurer.\n\n");
      write(capitalize(name) +" has been added as a treasurer.\n");
    } else {
      remove_treasurer(name);
      write_file(log_file, "TREASURER: "+ capitalize(name) +
        " removed as a treasurer.\n\n");
      write(capitalize(name) +" has been removed as a treasurer.\n");
    }
    return 1;
  }
  write("Only an Administrator may appoint treasurers.\n");
  return 0;
}
 
int do_treasurer(string name) {
  int i, n;
  string tpname = this_player()->query_name();
 
   /*  removed cause Rathburn didn't like it - Radix
  if (!query_admin(tpname) || !query_treasurer(tpname)){
   notify_fail("Only treasurers and administrators can view the lists.\n");
    return 0;
  }
   */
  if (name)
    return (do_appoint(name));
  printf("Current Treasurers\n");
  for (i = 0, n = sizeof(treasurers); i < n; i++)
    printf("  %s\n", capitalize(treasurers[i]));
  return 1;
}
 
int do_transactions(string str) {
  string tpname = this_player()->query_name();
  if (!query_admin(tpname) || !query_treasurer(tpname)){
    notify_fail("Only treasurers and administrators can view the lists.\n");
    return 0;
  }
  
  this_player()->more_file(log_file);
  return 1;
}
 
// Radix : August 5, 1997
int do_deposits()
{
  string tpname = this_player()->query_name();
  if (!query_admin(tpname) || !query_treasurer(tpname)){
    notify_fail("Only treasurers and administrators can view the lists.\n");
    return 0;
  }
  
  this_player()->more_file(log_file+"_deposits");
  return 1;
}
 
string query_save_file() { return save_file; }
void set_save_file(string file_name) { save_file = file_name; }
string query_log_file() { return log_file; }
//void set_log_file(string file_name) { log_file = log_file; }
 
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
  if (save_file) {
    seteuid("Root");
    restore_object(save_file);
    seteuid("PLAYER");
  }
}
 
void save_it() {
  if (save_file) {
    seteuid("Root");
    save_object(save_file);
    seteuid("PLAYER");
  }
}
 
