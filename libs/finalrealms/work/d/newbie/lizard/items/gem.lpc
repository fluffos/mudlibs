inherit"std/object";
 
 
void setup()
{
set_name("gem");
add_alias("gemstone");
add_alias("crystal");

set_main_plural("gems");
	set_short("Gemstone");
   set_long("   This beautiful gemstone is made up of a perfect "
            "transparent crystal sphere with a number of small "
            "gems located within it.  The red, yellow, green, and "
            "blue gems are arranged in a pattern that seems to change "
            "as you look at the different sides.  "
            "\n\n");
set_value(0);
reset_drop();
}
void init()
{
   add_action("do_look","look");
   ::init();
}
int do_look(string str)
{
   if(str == "side" || str == "sides")
   {
   write("The sphere has four sides each dominated by "
       "one of the four colors in the sphere. \n");
   return 1;
   }
   if(str == "blue" || str == "blue side")
   {
   write("The blue side takes the shape "
       "of a large ship.  You can make out incredible detail of the "
       "entire scene.  This is incredible!  \n");
   return 1;
   }
   if(str == "red" || str == "red side")
   {
   write("As you turn the stone to the red "
       "side, an incredible vision begins to take shape.  You can see "
       "a dragon breathing fire upon a hapless victim.\n");
   return 1;
   }
   if(str == "green" || str == "green side")
   {
   write("This side shows a vivid "
       "representation of a cloaked wizard casting a spell.  He "
       "holds a bright green light in his hands.\n");
   return 1;
   }
   if(str == "yellow" || str == "yellow side")
   {
   write("Moving the gemstone around to the "
       "yellow side, you see a castle sitting upon a large hill.  It "
       "has four towers and a lowered drawbridge.\n");
   return 1;
   }
}
