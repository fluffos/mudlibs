inherit SLOWHEAL;

void setup()
{
   set_id("cigarette", "cig");
   set_in_room_desc("A perfectly good cigarette lies here.");
   set_long("You can try to light it.");
   set_fuel(10);
   set_heal_value(2);
   set_consume_message("$N $vlight $p cigarette.");
   set_heal_message("You smoke your cigarette and feel more relaxed.");
   set_expire_message("A last puff on $p cigarette and $n $vflick it away.\n");
}

int direct_light_obj()
{
   return 1;
}

int direct_smoke_obj()
{
   return 1;
}

void do_light()
{
   do_consume();
}

void do_smoke()
{
   do_consume();
}

mixed direct_consume_obj()
{
   return "#Don't eat cigarettes, light them!";
}

mixed direct_use_obj()
{
   return "#Tobacco like this needs to be lit first.";
}
