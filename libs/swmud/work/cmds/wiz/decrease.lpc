// Last edited by deforce on 04-05-2010
inherit VERB_OB;

void do_decrease_obj(object thing)
{
   if (thing->is_armor() || thing->is_weapon())
   {
      thing->decrease_durability(1);

      this_body()->simple_action("$N $vdecrease the durability of $o by 1.", thing);
   }
}

void do_decrease_obj_by_str(object thing, string value)
{
   int amount = to_int(value);

   if (thing->is_armor() || thing->is_weapon())
   {
      thing->decrease_durability(amount);

      this_body()->simple_action("$N $vdecrease the durability of $o by " + value + ".", thing);
   }
}

void do_decrease()
{
   write("Decrease the durability of what?\n");
}

mixed can_decrease_obj() { return wizardp(this_body()); }
mixed can_decrease_obj_by_str() { return wizardp(this_body()); }
mixed can_decrease() { return wizardp(this_body()); }

void create()
{
   add_rules( ({ "", "OBJ", "OBJ by STR" }) );
}