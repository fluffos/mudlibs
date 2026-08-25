/* A "new" armoury.
 * Changed to fit the new armour / weapon thingies we use here.
 * instead of the clone from .wep & .arm we have all basic stuff in
 * /items/armour & /items/weapon
 * Baldrick, apr '94
 * It has to be completely rewritten to function as is shall
 * But I haven't time for it now.
 * 
 * Hmm, is it request_armour or request_armoury ??
 */

#include "armory.h"
inherit "/std/room";
#define FILE_NAME "/save/armoury"

mixed weaps, armourys;

#define TEST_CALLER \
  if (sscanf(file_name(previous_object()), "/obj/misc/add_armouryy#%d", tmp) != 1) { \
    write("No No you tried to add from an invalid object.\n"); \
    return 0; \
  }

void setup() {
  set_light(100);
  weaps = ({ });
  armourys = ({ });
  set_short("The Armory");
  set_long("You are in the armoury.  People cannot normally get "+
           "here.  Commands available are: weapons, armourys and request.\n");
}

void reset() {
  restore_object(FILE_NAME,1);
}

int armourys(string str) 
  {
  int i;
  string bit;

  bit = "";
  for (i=0;i<sizeof(armourys);i+=2)
    bit += armourys[i]+"\n";

  printf("Available armourys are:\n%-*#s\n", this_player()->query_cols(), bit);
  return 1;
}

int weapons(string str) 
  {
  int i;
  string bit;

  bit = "";
  for (i=0;i<sizeof(weaps);i+=2)
    bit += weaps[i]+"\n";

  printf("Available weapons are:\n%-*#s\n", this_player()->query_cols(), bit);
  return 1;
}
 
void init() {
  ::init();
  add_action("weapons", "weapons");
  add_action("armourys", "armourys");
  add_action("request", "request");
}

object request_armour(string name, int per);
object request_weapon(string name, int per);

/* Hmm, I don't have to change this part.. Good. */
int request(string str) 
  {
  string s1, s2;
  object ob;
  int per;

  notify_fail("Usage: request <armoury|weapon> <percentage> <name>\n");
  if (!str)
    return 0;
  str = lower_case(str);
  if (sscanf(str, "%s %d %s", s1, per, s2) != 3)
    return 0;
  if (s1 != "armoury" && s1 != "weapon")
    return 0;
  if (s1 == "armoury")
    ob = request_armour(s2,per);
  else
    ob = request_weapon(s2,per);
  if (!ob)
    write("Sorry but the "+s1+", "+s2+" does not exist.\n");
  else {
    if (ob->move(this_player())) {
      ob->move(this_object());
      write("You cant carry it so it has been put here.\n");
    } else
      write("Ok created and put in you.\n");
  }
  return 1;
}

object request_weapon(string name, int per) 
 {
  object ob;

  if (ob = clone_object("/baseobs/weapons/" + name))
    ob->set_percent(per);
  return ob;
}

object request_armour(string name, int per) 
  {
  object ob;

  /* we have a new armour system, with basic weapons in /item/armour
   */
   if (ob = clone_object("/baseobs/armours/" + name))
     ob->set_percentage(per);
   return ob;
}

int add_weapon(string name, mixed *arr) {
  int i, tmp;
  if ((i=member_array(name, weaps)) != -1)
    return 0;
  TEST_CALLER
  log_file("ARMORY", this_player()->query_name()+" added weapon "+name+"\n");
  weaps += ({ name, arr });
  save_object(FILE_NAME,1);
  return 1;
}

int remove_weapon(string name) {
  int i, tmp;

  if ((i=member_array(name, weaps)) == -1)
    return 0;
  TEST_CALLER
  log_file("ARMORY", this_player()->query_name()+" deleted weapon "+name+"\n");
  weaps = delete(weaps, i, 2);
  save_object(FILE_NAME,1);
  return 1;
}

int add_armoury(string name, mixed *arr) {
  int i, tmp;
  if ((i=member_array(name, armourys)) != -1)
    return 0;
  TEST_CALLER
  log_file("ARMORY", this_player()->query_name()+" added armoury "+name+"\n");
  armourys += ({ name, arr });
  save_object(FILE_NAME,1);
  return 1;
}

int remove_armoury(string name) {
  int i, tmp;

  if ((i=member_array(name, armourys)) == -1)
    return 0;
  TEST_CALLER
  log_file("ARMORY", this_player()->query_name()+" deleted armoury "+name+"\n");
  armourys = delete(armourys, i, 2);
  save_object(FILE_NAME,1);
  return 1;
}

mixed query_armourys() { return armourys + ({ }); }
mixed query_weapons() { return weaps + ({ }); }

void dest_me() {
  save_object(FILE_NAME,1);
  ::dest_me();
}

mixed query_armoury(string name) {
  int i;

  if ((i=member_array(name,armourys)) == -1)
    return 0;
  return armourys[i+1];
}

mixed query_weapon(string name) {
  int i;

  if ((i=member_array(name, weaps)) == -1)
    return 0;
  return weaps[i+1];
}
