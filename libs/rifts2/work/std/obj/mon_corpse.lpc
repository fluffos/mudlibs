// level hacking put in by Valodin to enable necromancy

#include <std.h>
#include <move.h>

inherit BAG;

#define DECAY_TIME 150

string name;
int decay;
int level;
int old_hp;
int fingers;  /* indication of body type for the time being */
mapping body;
string *wielding_limbs;
string race;
string gender;
int player;


void init() {
  ::init();
  add_action("transfer_inv", "get");
  return;
}

varargs void preserve_me(int time) {
  remove_call_out("decay");
  if(time) call_out("decay", time);
  return;
}
int transfer_inv(string str) {
  object *inv;
  string what, me;
  int i;

  if(sscanf(str,"%s from %s", what, me) != 2) return 0;
  if(present(me, this_player()) != this_object() &&
     present(me, environment(this_player())) != this_object()) return 0;
  if(this_player()->query_ghost()) {
    write("You cannot do that in your immaterial state.");
    return 1;
  }
  if(lower_case(what) == "all") inv = all_inventory(this_object());
  else inv = ({ present(what, this_object()) });
  if(!inv || !sizeof(inv)) {
    write("There is nothing in the corpse.");
    return 1;
  }
  if(!inv[0]) {
    write("There is no '"+what+"' in the corpse.");
    return 1;
  }
  i = sizeof(inv);
  while(i--) {
    if((int)inv[i]->move(this_player()) == MOVE_OK) {
      write("You take "+(string)inv[i]->query_short()+".");
      message("info", (string)this_player()->query_cap_name() +
        " takes "+(string)inv[i]->query_short()+" from a corpse.",
        environment(this_player()) , ({ this_player() }));
    }
    else
      write((string)inv[i]->query_short()+": too heavy.");
  }
  write("Ok.");
  return 1;
}


int is_player() { return player; }

int copy_body(object ob)
{
  string *limb_names;
  int i, lnsz;

  wielding_limbs = (string *)ob->query_wielding_limbs();
  body = ([]);
  limb_names = (string *)ob->query_limbs();
  for(i = 0, lnsz = sizeof(limb_names); i < lnsz; i++)
    {
      body[limb_names[i]] = ([ "limb_ref": ob->query_reference(limb_names[i]),
			      "max_dam": ob->query_max_dam(limb_names[i]),
			      "damage": ob->query_dam(limb_names[i]) ]);
    }
  fingers = ob->query_fingers();
  old_hp = ob->query_max_hp();
  level = ob->query_level();
  player = ob->is_player();
  gender = ob->query_gender();
  race = ob->query("race");
}

int make_new_body(object ob)
{
  int i, lnsz;
  string *limb_names;

  ob->set_level(level);
  ob->set_max_hp(old_hp);
  ob->set_fingers(fingers);
  limb_names = keys(body);
  for(i = 0, lnsz = sizeof(limb_names); i < lnsz; i++)
    {
      ob->add_limb(limb_names[i], body[limb_names[i]]["limb_ref"],
		   body[limb_names[i]]["max_dam"],
		   body[limb_names[i]]["damage"], body[limb_names[i]]["ac"]);
    }
  ob->set_wielding_limbs(wielding_limbs);
  ob->set_zombie_name(name, decay);
  ob->set("race", race);
  ob->set_gender(gender);
}

int is_corpse() { return 1; }

int query_level()
{
   return level;
}

void set_level(int lev)
{
   level = lev;
}

int query_old_hp()
{
   return old_hp;
}

void set_old_hp(int num)
{
   old_hp = num;
}

int query_decay()
{
   return decay;
}

void set_fingers(int num)
{
   fingers = num;
}

int query_fingers()
{
   return fingers;
}

int prevent_insert() {
   write("The corpse is too big.");
   return 1;
}

void create() {
   set_name("noone");
   name = "noone";
    set_weight(100);
   decay = 2;
   set_id(({"corpse", "corpse of " + name, "remains"}));
   set_max_internal_encumbrance(0);
   level = 0;
   old_hp = 0;
   fingers = 0;
}

void set_name(string str) {
  ::set_name(str);
   name = str;
   set("long", "This is the dead body of " + name + ".");
   set_id( ({"corpse", "corpse of " + lower_case(name), "remains" }));
   call_out("decay", DECAY_TIME);
}

void decay() {
  decay -= 1;
  if(decay > 0) {
    call_out("decay", 20);
    return;
  }
  catch(map_array(all_inventory(this_object()), (: call_other :),
		  "remove"));
  remove();
}

int can_put_and_get() { return 1; }

string query_short() {
  if(decay == 2)
    return "the corpse of " + name;
  else
    return "The somewhat decayed remains of " + name;
}

void remove() {
if(environment())
  if(living(environment()) && this_object()->query("prepared")!=1) {
    message("info", "%^GREEN%^The corpse of "+name+" decays.",
      environment());
    map_array(
      filter_array(all_inventory(this_object()),
        (: (!call_other($1, $2)) :), "drop"),
      (: call_other :), "move", environment());
    ::remove();
    return;
  }
  map_array(deep_inventory(this_object()),
    (: (objectp($1))?(call_other($1, $2)):0 :), "remove");
  ::remove();
  return;
}




