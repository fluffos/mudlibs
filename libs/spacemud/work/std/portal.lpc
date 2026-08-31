/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// A simple one way portal

inherit EXIT_OBJ;
inherit M_GETTABLE;

string look_in_desc;
string destination;

string enter_msg = "$N $vleave through the $o.";
string leave_msg = "$N $venter through the $o.";

string is_portal_open()
{
   // Override me
   return destination;
}

//: FUNCTION set_destination
// Set where you go when you enter the portal.  Valid arguments are a function
// pointer,  or a filename
void set_destination(mixed f)
{
   destination = f;
   set_method("enter", f, 0, ({sprintf(enter_msg)}), ({sprintf(leave_msg)}));
}

void set_portal_enter_msg(string s)
{
   enter_msg = s;
   set_destination(destination);
}

void set_portal_leave_msg(string s)
{
   leave_msg = s;
   set_destination(destination);
}

string get_destination()
{
   return query_method_destination("enter");
}

int direct_look_str_obj()
{
   return 1;
}

//: FUNCTION set_look_in_desc
// Set what you see when you look in the portal.
void set_look_in_desc(string s)
{
   look_in_desc = s;
}

string get_look_in_desc()
{
   return evaluate(look_in_desc);
}

string look_in(string prep)
{
   return evaluate(look_in_desc);
}

varargs void mudlib_setup(string d)
{
   ::mudlib_setup();
   set_id("portal");
   set_attached();
   set_gettable("#It's a portal not a portable.");
   if (d)
      set_destination(d);
}
