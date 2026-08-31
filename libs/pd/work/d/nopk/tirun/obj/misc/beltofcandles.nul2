
#include <std.h>
#include <move.h>

#define BLANK_SEAL "/d/nopk/tirun/obj/misc/seal_blank"

inherit ARMOUR;
inherit BAG;

void init() {
  armour::init();
}

void create() {
    armour::create();
    bag_logic::create();
    set_id( ({ "belt", "belt of candles", "candles" }) );
    set_name("belt of candles");
    set_short("%^BOLD%^%^BLUE%^Belt of %^YELLOW%^C%^BLACK%^a%^YELLOW%^ndles%^RESET%^");
    set_long(
      "%^BOLD%^The %^BLUE%^Belt of %^YELLOW%^C%^BLACK%^a%^YELLOW%^ndles%^RESET%^"
      " %^BOLD%^is made from a soft wax that is abnormally strong "
      "but somehow flexible. There are many "
      "%^YELLOW%^golden stars%^WHITE%^ placed around the belt that "
      "are used to magically hold waxes.%^RESET%^");
    // making the value a bit more random. Should be
    // 9,500-10,500 now, instead of the 10,000-10,024 that it was
    set_curr_value("gold", 9500+random(1001));
    // added by Nulvect
    set_weight(6);
    // armour calls
    set_type("belt");
    set_limbs( ({ "torso" }) );
    set_ac(1);
    // bag calls
    set_max_internal_encumbrance(40); // should allow 10 waxes; they weigh 4 each
    set_can_close(0);
    set_can_lock(0);
}

// added by Nulvect
varargs int receive_objects(object ob) {
  if (ob && base_name(ob) == BLANK_SEAL && ::receive_objects(ob))
    return 1;
  return 0;
}

// Renamed create_waxes() to void init_arg(mixed *stuff)
// To simplify things, basically this function is called when a player
// returns to the game... It passes whatever query_auto_load() returns to it.
// cleaned up by Nulvect
void init_arg(mixed *stuff) {

    if (!arrayp(stuff)) return;

    foreach (mixed *arg in stuff) {
      object tmp=new(BLANK_SEAL);

      if (!tmp) return;

      if (!arrayp(arg) || sizeof(arg) < 2) {
        tmp->remove();
        continue;
      }

      tmp->init_arg(arg[1]);

      if (tmp->move(this_object()) != MOVE_OK)
        tmp->remove();

    }
}

mixed query_auto_load() {
  object *ai;
  if (this_player()->query_level() >= 20) {
    if (!sizeof(ai=all_inventory(this_object())))
      return 1;
    else
      return ({ base_name(this_object()), ai->query_auto_load() });
  }
  return 0;
}


string query_long_more() {
  string l = "";
  string tmp;
  string *worn;
  
  if (sizeof(worn=this_object()->query_actual_limbs()))
    l += "Worn on: "+implode(worn, ", ")+".\n";

  l += bag_logic::query_long_more();

  return l;
}


