// Last edited by deforce on 03-03-2010
// attributes.c -- provide attributes to an object's description
// Used internally to map flag values into attributes to display at the
// end of a description. For example: (open) or (providing light) (wielded)

#include <flags.h>

/*
** The key is a flag value (see /include/flags.h) and the values are a
** string or an array of three strings.  For the first case, the string will
** be used if the flag is set. For the latter case: if the object responds
** TRUE to the function specified in the third string, then the first
** string (at index 0) will be used if the flag is off, and the second
** string will be used if the flag is on.
**
** This information is kept ONLY in the M_OBJ_ATTRIBUTES object.  It will
** be initialized by the various modules that need to have attributes
** displayed.  Each object will then use this information to display that
** data.
*/
private nosave mapping attribute_info = 0;

int test_flag(int);

//:FUNCTION get_attributes
// Get the attributes (a string) for the given object.  This will be
// built from the object's flag states and the registered attributes.
string get_attributes()
{
   string attr = "";

   if (!attribute_info)
   {
      attribute_info = ATTRIBUTES_D->get_global_attributes();
   }

   foreach (int flag, mixed info in attribute_info)
   {
      if (test_flag(flag))
      {
         attr += call_other(this_object(), info);
      }
   }

   return attr;
}

string adjusted_attributes()
{
   return "";
}

string altered_attributes()
{
   return "";
}

string broken_attributes()
{
   return " (broken)";
}

string concealed_attributes() { return ""; }

string damaged_attributes()
{
   if (!test_flag(F_BROKEN)) { return " (damaged)"; }

   return "";
}

string holstered_attributes()
{
   if (this_object()->is_lightsaber()) { return " (attached)"; }

   return " (holstered)";
}

string lighted_attributes()
{
   if (this_object()->is_lightsaber()) { return ""; }
   else if (this_object()->is_flashlight()) { return " (on)"; }

   return " (lit)";
}