#define PLANT_SKILL "other.woodland"

int birth, leaves, fruit;
#define PLANT_HANDLER "/obj/handlers/plant"

create()
{
   if (file_name(this_object()) != MY_NAME) {
      birth = time();
      PLANT_HANDLER->note_birth(MY_NAME);
      leaves = 0;
      fruit = 0;
      call_out("growth", GROWTH_TIME,GROWTH_TIME);
   } else {
      birth = leaves = fruit = 0;
   }
}

disperse_fruit()
{
   int bing;
   object *dd, *dests;

   dd = environment()->query_dest_dir();
   dests = ({ environment() });
   for (bing = 1; bing <= sizeof(dd) / 2; bing++) {
      if (dd[bing * 2 - 1]->query_property("location") != "inside")
         dests += ({ find_object(dd[bing * 2 - 1]) });
   }

   while (fruit--) {
      bing = random(sizeof(dests));
      dd = clone_object("/obj/seed");
      dd->set_plant(MY_NAME);
      dd->set_germ(GROWTH_TIME);
      dd->set_name(FRUIT_NAME);
      dd->set_plural(FRUIT_PLURAL);
      dd->add_alias("seed");
      dd->move(dests[bing]);
   }
   fruit = 0;
}

growth()
{
   int age;

   age = time() - birth;

   if (age < OLD) leaves += random(LEAF_INDEX);
   else if (age < DEAD) leaves += random(LEAF_INDEX / 2);
   else leaves -= random(LEAF_INDEX);
   if (leaves < 0) leaves = 0;
   if (fruit) disperse_fruit();
   if (age > MATURE && age < OLD) {
      fruit = random(FRUIT_INDEX);
   }
   if (age > DEST) this_object()->dest_me();

   call_out("growth", GROWTH_TIME / 2 + random(GROWTH_TIME));
}

#define UP_BOUND 25
#define LOW_BOUND 10
string query_name() {
  return "plant";
}

string query_plural() {
   int i;

   i = (int)this_player()->query_skill(PLANT_SKILL);
   if (i > UP_BOUND) return SPECIES_PLURAL;
   if (i > LOW_BOUND) return TYPE_PLURAL;
   return VAGUE_PLURAL;
}

string pretty_plural() {
   return query_plural();
}

int id(string str) {
  return (str == "plant") || (str == VAGUE) || (str == TYPE) || (str == SPECIES);
}

/* need to change the below to also query_skill() on the player ... 
   but later [als] */
string *parse_command_id_list() { return ({ "plant", VAGUE, TYPE, SPECIES }); }
string *parse_command_plural_id_list() { return ({ "plants", VAGUE_PLURAL, TYPE_PLURAL, SPECIES_PLURAL }); }
string *parse_command_adjective_id_list() { return ADJECTIVE_LIST; }

object query_parse_id(mixed *arr) {
  if (arr[0] == 0)
    return this_object();
  if (arr[0] < 0) {
    arr[0]++;
    if (arr[0] != 0)
      return 0;
    arr[0] = -10321;
    return this_object();
  }
  arr[0]--;
  if (arr[0] != 0)
    return this_object();
  arr[0] = -10101;
  return this_object();
}

void attack_by(object ob) {
  ob->stop_fight(this_object());
}

string short() {
   int i;

   i = (int)this_player()->query_skill(PLANT_SKILL);
   if (i > UP_BOUND) return SPECIES;
   if (i > LOW_BOUND) return TYPE;
   return VAGUE;
}

string long() {
   string s;
   int i, age;

   i = (int)this_player()->query_skill(PLANT_SKILL);
   age = time() - birth;

   s = "This is a";
   if (age < YOUNG) s += " sprouting ";
   else if (age < MATURE) s += "n immature ";
   else if (age < OLD) s += " mature ";
   else if (age < DEAD) s += "n old ";
   else if (age < DRY) s += " newly dead ";
   else s += " long dead ";
   if (i > (UP_BOUND + LOW_BOUND) / 2) s += SPECIES;
   else if (i > LOW_BOUND / 2) s += TYPE;
   else s += VAGUE;
   s += ".\n";
   return s;
}

query_short()
{
   return short();
}

query_long()
{
   return long();
}

string pretty_short() {
   return short();
}

#include "move_failures.h"
varargs int move(mixed dest, mixed messin, mixed messout) {
  if (!dest)
    return MOVE_EMPTY_DEST;
  if (environment() && !environment()->test_remove(this_object(), 1))
    return MOVE_NO_DROP;
  if (!dest->test_add(this_object(), 1))
    return MOVE_NO_GET;
  if (environment() && stringp(messout))
    say(messout);
  move_object(this_object(), dest);
  if (stringp(messin))
    say(messin);
  return MOVE_OK;
}

void dest_me() {
   if (file_name(this_object()) != MY_NAME) {
      PLANT_HANDLER->note_death(MY_NAME);
   }
  destruct(this_object());
}

void dwep() {
  destruct(this_object());
}

query_age()
{
   return time() - birth;
}

query_max()
{
   return MAX_PLANTS;
}

query_birth()
{
   return birth;
}

set_birth(n)
{
   birth = n;
}

note_birth()
{
   birth++;
}

note_death()
{
   birth--;
}

query_leaves()
{
   return leaves;
}

query_fruit()
{
   return fruit;
}

mixed *stats() {
   return ({
      ({ "vague", VAGUE, }),
      ({ "type", TYPE, }),
      ({ "species", SPECIES, }),
      ({ "birth", birth }),
      ({ "leaves", leaves }),
      ({ "fruit", fruit }),
      ({ "age", time() - birth }) });
}
