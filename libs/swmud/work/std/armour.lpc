/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_SALVAGEABLE;
inherit M_DAMAGE_SINK;

inherit M_DURABILITY;

#define ARMOUR_LVL_PRICE 50

//: MODULE
// This is the base for creating a piece of armour.  It uses M_WEARABLE to
// allow it to be worn, and M_DAMAGE_SINK to allow it to absorb damage.

void mudlib_setup()
{
   object::mudlib_setup();
   m_wearable::mudlib_setup();
   set_salvageable((["textile":50, "metal":50]));
   add_id("armour", "armor");
   set_mass(1);
}

int query_value()
{
   int value = ::query_value();
   int level = query_armour_class() + array_sum(values(query_stat_mods()));
   if (!value)
      value = ARMOUR_LVL_PRICE * level - random(ARMOUR_LVL_PRICE);
   set_value(value);
   return value;
}

//: FUNCTION set_worn
// set_worn(1) causes this object to be worn by whatever is holding it.
// set_worn(0) takes it back off again.
void set_worn(int g)
{
   if (g)
      environment()->add_armour(this_object());
   else
      environment()->remove_armour(this_object());
   ::set_worn(g);
}

void remove()
{
   m_wearable::remove();
   object::remove();
}

mixed ob_state()
{
   return m_wearable::ob_state();
}
