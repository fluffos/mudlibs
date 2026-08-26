inherit OBJ;
inherit M_WEARABLE;
inherit M_GETTABLE;

void setup()
{
   set_id("dancer's outfit", "outfit", "dancer_outfit");
   set_long("This dancer's outfit leaves little to the imagination.");

   set_slots("torso", "head");
   set_wear_message("$N $vslide on $p $o.");
   set_remove_message("$N $vslide off $p $o.");

   set_attribute_modifiers((["cha" : 10]));

   set_mass(2000);
}

int valid_wear()
{
   if (environment(this_object())->query_gender() == 2) { return 1; }

   write("You decide that you couldn't get away with wearing something like that.\n");

   return 0;
}