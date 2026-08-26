inherit "/std/races/base";

void create() {
   do_setup++;
   ::create();
   do_setup--;

   set_desc( "your standard fish.  This should not be used since it is a "
      "base race" );

   bits = ({
      "head", "head", ({ 0, 200, 0,
         "left eye", "right eye", "left gill", "right gill" }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "left gill", "gill", ({ "head", 50, 0 }),
      "right gill", "gill", ({ "head", 50, 0 }),
      "torso", "guts", ({ 0, 800, 0,
         "heart", "liver", "left kidney", "right kidney", "spleen" }),
      "heart", "heart", ({ "guts", 50, 0 }),
      "liver", "liver", ({ "guts", 50, 0 }),
      "left kidney", "kidney", ({ "guts", 25, 0 }),
      "right kidney", "kidney", ({ "guts", 25, 0 }),
      "spleen", "spleen", ({ "guts", 25, 0 }),
      "genitals", "genitals", ({ 0, 10, 0 }),
      "left petral fin", "fin", ({ 0, 100, 0, }),
      "right petral fin", "fin", ({ 0, 100, 0, }),
      "dorsal petral fin", "fin", ({ 0, 100, 0 }),
      "tail", "tail", ({ 0, 150, 0 })
   });

   inedible = ({ "left petral fin", "right petral fin", "dorsal petral fin",
      "tail" });
   unrottable = ({  });
   set_skin( "scales" );

   if( !do_setup )
      this_object()->setup();
} /* create() */

