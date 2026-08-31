/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CONTAINER;
inherit M_OPENABLE;
inherit M_GETTABLE;

void setup()
{
   set_id("bag");
   add_adj("plastic","white");
   set_long("A white plastic bag");
   add_relation("in");
   set_default_relation("in");
   set_objects(([]));
   set_max_capacity(2 * MEDIUM);
}

mixed ob_state()
{
   return (string)container::ob_state();
}

void remove()
{
   container::remove();
}
