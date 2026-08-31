inherit ARMOUR;

int is_up;

void setup()
{
   set_id("hoodie", "hood");
   set_adj("hyperspace");
   set_armour_class(4);
   set_slot("torso");
   set_salvageable((["textile":80, "plastic":20]));
   set_also_covers("left arm", "right arm");
   set_worn_under(1);
   set_long("The hoodie's sleek, dark fabric is adorned with luminescent, pulsating patterns that mimic the "
            "mesmerizing trails left by ships entering hyperspace.");
}

string get_extra_long()
{
   return "\nIt has a hood that can be pulled up or down - it is currently " + (is_up ? "up" : "down") + ".";
}

void do_pull_str(string str)
{
   if (!ob_state())
   {
      write("First wear the hoodie to pull up the hood.");
      return;
   }
   if (is_up && str == "up")
   {
      write("The hood is already up?");
      return;
   }
   if (!is_up && str == "down")
   {
      write("The hood is already down?");
      return;
   }
   switch (str)
   {
   case "up":
      this_body()->simple_action("$N $vpull up the hood of $p $o.", this_object());
      set_also_covers("left arm", "right arm", "head");
      environment()->update_cover(this_object());
      is_up = 1;
      break;
   case "down":
      this_body()->simple_action("$N $vpull down the hood of $p $o.", this_object());
      set_also_covers("left arm", "right arm");
      environment()->update_cover(this_object());
      is_up = 0;
      break;
   }
}

void do_remove()
{
   if (is_up)
      do_pull_str("down");
   // Must set the max limbs we would cover before removing it, so they all get removed correctly.
   set_also_covers("left arm", "right arm", "head");
   ::do_remove();
}

mixed direct_pull_obj()
{
   return "#Pull the hood up or down?";
}

mixed direct_pull_str_obj(string str)
{
   if (str == "up" || str == "down")
      return 1;
   return "#Pull the hood how?";
}