inherit ARMOUR;

void setup()
{
   set_id("gravity gloves", "gloves");
   set_adj("pair of");
   set_armour_class(2);
   set_salvageable((["textile":80, "plastic":20]));
   set_slot("left hand");
   set_also_covers("right hand");
   set_long(
       "The GravityGrip gloves from Galactic Gadgets are a game-changer for spacefarers. Designed to counter the "
       "challenges of zero gravity, these gloves have a specialized grip surface that adheres to surfaces with subtle "
       "yet effective magnetism. Whether you're wielding slippery items, navigating the narrow corridors of a space "
       "station or attempting a moonwalk, these gloves provide stability and control, minimizing the awkwardness of "
       "accidental floating. The sleek, form-fitting design ensures comfort and ease of movement, making the "
       "GravityGrip gloves an essential accessory for those who want to stay grounded in the weightless expanse of the "
       "cosmos.");
   set_extra_mod("[disarm]");
}

void worn()
{
   environment()->add_skill_bonus("combat/defense/disarm", 50);
   write("Small sticky spikes extend from the gloves.");
}

void removed()
{
   environment()->remove_skill_bonus("combat/defense/disarm", 50);
   write("The sticky spikes from your gloves retract.");
}
