/* Modified and added by Galvin 95-06-18 */
/* Created by Mist - Fall 1994 */
#include "pub.h"
#include "path.h"
inherit "/std/pub";
mixed top_list, top_deaths;
void add_to_list(object ob);

object orgg, globe, hider, *lizard;

void setup()
{
  add_menu_item("Water", SOFTDRINK, 1, 0, 0, 0,
    "drink a glass of water", "drinks a glass of water");
  add_menu_item("Milk", SOFTDRINK, 6, 1, 5, 5,
    "drink your glass of milk", "drinks a glass of milk");
  add_menu_item("Swamp beer", ALCOHOL, 20, 2, 10, 10,
    "drink your swamp beer", "drinks a pint of swamp beer");
  add_menu_item("Root ale", ALCOHOL, 40, 3, 20, 20,
    "gulp down a pint of tasty root ale", "gulps down a pint of root ale");
  add_menu_item("Orggs special", ALCOHOL, 500, 8, 200, 200,
    "hurl down Orggs special", "hurls down Orggs special and burps");
  add_menu_item("Boiled lizard", FOOD, 200, 4, 150, 0,
    "eat a tasty lizard", "eats a boiled lizard");
  add_menu_item("Alligator soup", FOOD, 200, 4, 150, 0,
    "eat a meal of alligator soup", "eats some alligator soup");
  add_menu_item("Roasted dog", FOOD, 1000, 7, 500, 0,
    "eat a whole roasted dog", "eats a whole roasted dog");
  add_menu_alias("water", "Water");
  add_menu_alias("milk", "Milk");
  add_menu_alias("swamp beer", "Swamp beer");
  add_menu_alias("beer", "Swamp beer");
  add_menu_alias("root ale", "Root ale");
  add_menu_alias("ale", "Root ale");
  add_menu_alias("orggs special", "Orggs special");
  add_menu_alias("special", "Orggs special");
  add_menu_alias("boiled lizard", "Boiled lizard");
  add_menu_alias("lizard", "Boiled lizard");
  add_menu_alias("alligator soup", "Alligator soup");
  add_menu_alias("soup", "Alligator soup");
  add_menu_alias("roasted dog", "Roasted dog");
  add_menu_alias("dog", "Roasted dog");
set_short("realm of the Lizard:  Long Tail Tavern");
  set_zone("pub");
  set_light(50);
set_long("\nRealm of the Lizard:  Long Tail Tavern\n\n"
	 "     This is the Long Tail Tavern, a very popular hangout "
           "among the local lizard-men. Several sturdy wooden tables "
           "are neatly arranged around the room and a large fireplace "
           "is placed in the south wall, right next to the long bar. "
           "The dusky room is crowded with noisy lizard-men sitting "
           "around the tables or standing at the bar. Next to the bar "
           "a big menu shows what this establishment has to offer. \n\n");
add_property("no_undead",1);
  add_item("tables", "These sturdy tables are covered with notches and "
           "cuts, clearly indicating that more than a few pub-brawls "
           "have taken place here. \n\n");
  add_item("fireplace", "A large cosy fireplace that makes a brave "
           "attempt to lighten up the room but fails miserably. \n\n");
  add_item("wall", "These walls are made of boring grey stone and "
           "are totally unadorned. \n\n");
  add_item("bar", "The bar stretches along the eastern wall and is "
           "almost hidden from sight behind a living wall of "
           "customers. A lot of empty mugs and remains of food are all "
           "over the bar but nobody seems to care. \n\n");
  add_item("lizard-men", "The lizard-men are enjoying themselves with "
           "food and drinks. They may look friendly but you've heard "
           "stories about the many pub-brawls in this place so "
           "don't be deceived. \n\n");
  add_exit("east", SWAMP +"lizard26", "door");
  lizard = allocate(3);
}
void reset()
{
  int i;
  if(!orgg)
    {
      orgg = clone_object(MONSTER+"orgg");
      orgg->move(this_object());
    }
  if(!globe)
    {
      globe = clone_object("/obj/misc/globe");
      globe->move(this_object());
    }
  if (!lizard)
    lizard = allocate(3);
  if (!hider)
    {
      hider = clone_object("/std/container");
      hider->reset_get();
    }
  for (i=0;i<sizeof(lizard);i++)
    if (!lizard[i])
    {
      lizard[i] = clone_object(MONSTER+"lizardmn");
      lizard[i]->move(hider);
    }
}
void init()
{
  int i;
  ::init();
  if (orgg && !sizeof((object *)orgg->query_attacker_list()))
    for (i=0;i<sizeof(lizard);i++)
      if (lizard[i] && !sizeof((object *)lizard[i]->query_attacker_list()))
        lizard[i]->move(hider);
}
/*
void event_fight_in_progress(object ob1, object ob2)
{
  int i;
  for (i=0;i<sizeof(lizard);i++)
    if (lizard[i] && environment(lizard[i]) == hider)
    {
      lizard[i]->move(this_object());
      if (ob1 != orgg)
        lizard[i]->attack_ob(ob1);
      if (ob2 != orgg)
        lizard[i]->attack_ob(ob2);
    }
}
*/
void dest_me()
{
  int i;
  if(orgg)
    orgg->dest_me();
  if(globe)
    globe->dest_me();
  if (hider)
    hider->dest_me();
  for (i=0;i<sizeof(lizard);i++)
    if (lizard[i])
      lizard[i]->dest_me();
  ::dest_me();
}
