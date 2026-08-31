inherit ARMOUR;

void worn()
{
   environment()->add_skill_bonus("combat/defense/stance",50);
   write("You feel your stance improve immediately.");
}

void removed()
{
   environment()->remove_skill_bonus("combat/defense/stance",50);
   write("You feel your stance go back to normal after removing the sneakers.");
}

void setup()
{
   set_adj("pair of levitating");
   set_armour_class(5);
   set_id("sneakers");
   set_long(
       "These sleek shoes boast a low-profile design with a streamlined silhouette, giving off an appearance of "
       "aerodynamic elegance. The defining feature, of course, is the anti-gravity sole. Composed of advanced magnetic "
       "levitation technology, the sole allows the wearer to literally hover a few millimeters above the ground.");
   set_slot("left foot");
   set_also_covers("right foot");
   set_extra_mod("[stance]");
}
