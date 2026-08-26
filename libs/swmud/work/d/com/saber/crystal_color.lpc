inherit M_LIGHTSABER_COMPONENT;

#include <lightsaber.h>

varargs void setup(string color)
{
   if (!strlen(color))
   {
      color = "blue";
   }

   set_id(get_lightsaber_color_code(color) + "%^RESET%^ crystal", "crystal", "color crystal", color + " crystal", "lightsaber_color_crystal");
   set_long("A facetted crystal used in the construction of a lightsaber.  It glows faintly with an inner " + color + " light.");
   set_component_name(color);
   set_component_type("color");
   set_mass(50);
   set_value(5000);
}