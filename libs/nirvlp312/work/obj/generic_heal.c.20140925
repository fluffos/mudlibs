/*
Generic Heal
Filename: generic_heal.c
Author: Feldegast @ Nirvana
Description:
	This heal should replace the dozen or so different heal objects currently being used
on the mud.  It would be much more memory efficient, as well as allowing some standard method
for handling heals, if everybody used this.
*/

/*  Modified by Cobain 17th June 2002
  i. Fixed 'verb what?' error when toxed and also added a negative heal charge check.
 ii. Added customization of stuffed, soaked and toxed msgs.
 iii.Added plural/singular definition of charges for improved readibility.
 iv. Added customize/colour option for charges padding. From *3* to [3], <3> or whatever.
 v.  Set default value codes to keep 100% compatibility with all code based on older generic_heal.
 vi. Added a function for condition checking. This allows further customization.

 minor alterations by verte, took out color_pad(), replaced with colour_pad()

Mod'd by Boltar, 17-Sep-2002, fixed saving functionality. Did not match
documentations and standard practice. Causing failures. 
*/

/* unnecessary
#include "/players/feldegast/std/color_pad.h"
*/
#define FILE "/obj/generic_heal.c"

int hp_heal;
int sp_heal;
int charges;
int value; /* This is value per charge */
int intox;
int soak;
int stuff;
int save_flag; /* user settable save flag */

string short_desc;
string long_desc;
string name;
string *alias; /* An array of id's for this object */
string msg; /* Ex: You chug a quart of beer!  You rip off a haunch of beef. etc. */
string msg2; /* "chugs a quart of beer!" "rips off a haunch of beef." */
string *cmds; /* An array of commands for using this heal */
string type; /* Ex: berries, sips, charges */

/* Added by Cobain */
string msg_precharges;  /* Pre charge message to allow colour customization for charges */
string msg_postcharges; /* Post charge message to allow colour return to normal for charges */

string type_single; /* Specifies the singlular charge type. ie. berry, sip , charge */

string msg_stuffed;  /* Ex. "You already ate way too goddamn much." */
string msg_soaked;   /* Ex. "You already need to piss like a racehorse!" */
string msg_intoxed;  /* Ex. "You are way too obliviated to attempt to kill yourself like that." */
/* End Addition */

/* added for donations at the green. Fred [7.28.06] */
static int donated_item;

string empty_msg;

/***************************************/

void reset(int arg)
{
  if(arg) return;
  cmds=({ });
  alias=({ });

  /* Initialize default values : Added by Cobain */
  msg_precharges ="*";
  msg_postcharges = "*";
  type_single = "";
  msg_stuffed = "You are too full!";
  msg_soaked = "You can't drink anything else!";
  msg_intoxed = "You cannot drink any more!";
  /* End Addition */

}

void init()
{
  int i,s;
  if(!present(this_object(),this_player()))
    return;
  s=sizeof(cmds);
  for(i=0; i < s; i++)
  add_action("cmd_imbibe",cmds[i]);
/*
  add_action("cmd_heals","heals");
  add_action("cmd_heals_all","heals+");
*/
}

/**************************************/
/* Functions for physical description */
/**************************************/

string short()
{
  return short_desc+ " " + msg_precharges + charges + msg_postcharges;
}

/* added by cobain */
void show_charges()
{
  int ch;

  if(charges == 1)
    ch = 1;

  write("There " + (ch ? "is" : "are") + 
        " " + msg_precharges + charges + msg_postcharges +
        " " + (ch ? type_single : type) +
        " remaining.\n");
}

void long()
{
  write(long_desc);
  if(donated_item) write("This heal has been donated.\n");

  /* Cobain: Added for compatibility with older heals */
  if (type_single == "")
  {
    type_single = type;
  }
  show_charges();
}

int id(string str)
{
  int i;
  if(name==str)
    return 1;
  for(i=0; i < sizeof(alias); i++)
    if(alias[i]==str)
      return 1;
  return 0;
}

int get() { return 1; }
int drop() { return 0; }
int is_heal() { return 1; }
int query_value() { return (donated_item ? 0 : charges*value); }

/* Functions for dealing with storage */

/* Generic heals can only be saved if they are placed in a separate file. */
/*
int query_save_flag() { if(object_name(this_object())==FILE) return 1; }

This makes no sense, this file supports both locker and hotel systems.
this should always return 0, unless a coder set variable tells it not
to. -Bp
*/

int query_save_flag() { return save_flag; }

/* 
int generic_object() { return 1; }
CONFLICTING CONCEPTS. 1) These are not always generic items. 
2) When it's used as a generic item, the save flag is on, blocking saving
   making this irrelvant.
-Bp
*/

int generic_object() { if(object_name(this_object())==FILE) return 1; }
string locker_arg() { return ""+charges; }
void locker_init(string arg)
{
  if(sscanf(arg,"%d",charges)!=1) {
    write("Object failed to initialize properly.  Destructing.\n");
    destruct(this_object());
  }
}

int restore_thing(string str) { restore_object(str); return 1; }
int save_thing(string str) { save_object(str); return 1; }

int query_weight()
{
  if(charges > 2)
    return charges/2;
  else
    return 1;
}
/*************************************/

/* Cobain: Subroutine added
   It separates the monitor from the main code to allow option to override and customize.
   Must appear before cmd_imbibe
*/

void show_heal_mon()
{
  command("mon",this_player());
}

int conditions_check() {return 1; }

int cmd_imbibe(string str)
{
  object me;

  me = this_player();  /* bit better than tp */

/* Some of the messages tweaked by Verte */
  if(environment() != me)
  {
    notify_fail("You may only " + query_verb() + " from " +
      short() + " when you are carrying it.\n");
    return 0;
  }
  /* Added by Cobain */
  if(type_single == "")
    type_single = type;

  /* Cobain: Fix for the verb what ? problem. */
  /*if(!str || this_object()!=present(str),this_player()) )*/

  if(!str)
  {
    notify_fail(capitalize(query_verb())+" what?" + "\n");
    return 0;
  }
  if(!id(str))
  {
    notify_fail("You may only " + query_verb() + " from " + short() + ".\n");
    return 0;
  }
  /* End Fix */

  /* Allows user to configure their own customized conditions for heal use */
  if ( !conditions_check() ) { return 0; }


  /* Cobain: Modified these messages to depend on variables msg_stuffed, msg_soaked msg_intoxed */
  if(stuff > 0)
  if(stuff && (((int)me->query_stuffed() + stuff) > 
   ((int)this_player()->query_max_stuff()))
   )
    return (write(msg_stuffed + "\n"), 1);

  if(soak > 0)
  if(soak && (((int)this_player()->query_soaked() + soak) > 
   ((int)this_player()->query_max_soak()))
   )
    return (write(msg_soaked + "\n"), 1);

 if(intox > 0)
  if(intox && ((int)this_player()->query_intoxination() > 
            ((int)this_player()->query_max_intox()))
   )
    return (write(msg_intoxed + "\n"), 1);

  if(soak)
    this_player()->drink_soft(soak);

  if(stuff)
    this_player()->eat_food(stuff);

  if(intox)
    this_player()->drink_alcohol(intox);
  
  if(charges == 0) { 
    write("Nothing happens.\n");
    return 1;
  } /* Stamps out infinite heal use! -Bp */

  charges--;

  /* Prevents the negative heal charges bug.  */
  if (charges < 0)
    charges = 0;
  this_player()->add_hit_point(hp_heal);
  this_player()->add_spell_point(sp_heal);

  write(msg);
  if(msg2) say((string)this_player()->query_name()+msg2);
  if(charges)
  {
    show_charges();
    this_player()->recalc_carry();
    show_heal_mon();
  }
  else
  {
    /* Cobain : Updated to use the new type_single (charge) variable */
    /* write("You finish off the last "+type+".\n"); */
    if(!empty_msg)
    write("You finish off the last "+type_single+".\n");
    else
      write(empty_msg);
    show_heal_mon();
    this_player()->add_weight(-1);
    destruct(this_object());
  }
  return 1;
}


/******************************/
/* Functions for modification */
/******************************/

void set_empty_msg(string x) { empty_msg=x; }
void set_heal(int hp,int sp) { hp_heal=hp; sp_heal=sp; }

void set_charges(int x) { charges=x; }

void set_intox(int x) { intox=x; }

void set_stuff(int x) { stuff=x; }

void set_soak(int x) { soak=x; }

void set_value(int x) { value=x; }

void set_short(string str) { short_desc=str; }

void set_long(string str) { long_desc=str; }

void set_name(string str) { name=str; }

void add_alias(string str) { alias+=({ str }); }

void set_msg(string str) { msg=str; }

void set_msg2(string str) { msg2=str; }

void set_type(string str) {  type=str; }

void add_cmd(string str) { cmds+=({ str }); }

/* Added by Cobain */
void set_type_single(string str) { type_single = str ; }

void set_msg_stuffed(string str){ msg_stuffed = str; }
void set_msg_soaked(string str){ msg_soaked = str; }
void set_msg_intoxed(string str) { msg_intoxed = str; }

void set_msg_precharges(string str) { msg_precharges = str; }
void set_msg_postcharges(string str) { msg_postcharges = str; }
/* End Additon */
/* Added by boltar */
void set_save_flag(int arg) { save_flag = 1; if(arg) save_flag = arg; }
/*end Bp */


/*********************************/
/* Functions for querying status */
/*********************************/

int query_hp_heal() { return hp_heal; }

int query_sp_heal() { return sp_heal; }

int query_charges() { return charges; }

int query_intox() { return intox; }

int query_stuff() { return stuff; }

int query_soak() { return soak; }

int query_val() { return value; }

string query_short() { return short_desc; }

string query_long() { return long_desc; }

string query_name() { return name; }

string *query_alias() { return alias; }

string query_msg() { return msg; }

string query_msg2() { return msg2; }

string query_type() { return type; }

string *query_cmds() { return cmds; }

/**********************************/
/* Commands                       */
/**********************************/


/* List heals and show their charges. */
int cmd_heals(string str)
{
  mapping heals;
  object ob;
  string *indices;
  int total;
  int i;

  heals=([ ]);
  ob=first_inventory(this_player());
  while(ob)
  {
    if((int)ob->is_heal())
    {
      heals[(string)ob->query_short()]+=(int)ob->query_charges();
      total++;
    }
    ob=next_inventory(ob);
  }

  indices=keys(heals);

  write("Heals                         Charges\n");
  write("-------------------------------------\n");
  for(i=0; i < sizeof(indices); i++)
  {
    write(colour_pad(indices[i],30));
    write(heals[indices[i]]+"\n");
  }
  /* Cobain: Modified to correct grammar anomalies */
  /* write("You have "+total+" heals.\n"); */
  write("\nYou have "+(total == 1 ? "1 heal": total+" heals")+".\n");
  return 1;
}

/* A deep_inventory version of cmd_heals */
int cmd_heals_all(string str)
{
  mapping heals;
  object *inv;
  string *indices;
  int size;
  int i;
  int total;

  heals=([ ]);

  inv=deep_inventory(this_player());
  size=sizeof(inv);

  for(i=0; i < size; i++)
  {
    if(inv[i]->is_heal())
    {
      heals[(string)inv[i]->query_short()]+=(int)inv[i]->query_charges();
      total++;
    }
  }

  indices=keys(heals);

  write("Heals                         Charges\n");
  write("-------------------------------------\n");
  size=sizeof(indices);
  for(i=0; i < size; i++)
  {
    write(colour_pad(indices[i],30));
    write(heals[indices[i]]+"\n");
  }

  /* Cobain : Modified to Correct grammar anomalies.*/
  /* write("You have "+total+" heals.\n"); */
  write("\nYou have "+((total == 1) ? "1 heal": total+" heals")+".\n");
  return 1;
}

set_donated_item(int arg){ donated_item = arg; }
query_donated_item(){ return donated_item; }
