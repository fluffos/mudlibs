/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CONTAINER;
inherit M_OPENABLE;
inherit M_WEARABLE;
inherit M_GETTABLE;

void setup()
{
   set_id("bag");
   add_adj("red","leather");
   set_long("A red leather bag with straps on the front..");
   add_relation("in");
   set_default_relation("in");
   set_objects(([]));
   set_max_capacity(3 * MEDIUM);
   set_slot("torso");
}

mixed ob_state()
{
   return (string)container::ob_state() + (string)m_wearable::ob_state();
}

void remove()
{
   m_wearable::remove();
   container::remove();
}
