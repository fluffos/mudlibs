/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CONTAINER;
inherit M_GETTABLE;
inherit M_WEARABLE;

void setup()
{
   set_id("belt");
   add_adj("worn","leather");
   set_long("A worn leather belt made for holding tools. You can put items on it.");
   add_relation("on");
   set_default_relation("on");
   set_objects(([]));
   set_max_capacity(3 * MEDIUM);
   set_slot("torso");
   set_worn_under(1);
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
