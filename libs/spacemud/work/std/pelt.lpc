/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;
inherit M_SALVAGEABLE;

private
int pelt_size = 0;
private
string pelt_type;

void set_pelt_size(int s)
{
   pelt_size = s;
   set_mass(0.5 * s);
}

int query_pelt_size()
{
   return pelt_size;
}

void set_pelt_type(string t)
{
   pelt_type = t;
   set_id(pelt_type, "textile", "pelt");
}

string short()
{
   if (strlen(pelt_type))
      set_id(pelt_type, "textile", "pelt");
   return ::short();
}

string query_pelt_type()
{
   return pelt_type;
}

void mudlib_setup()
{
   ::mudlib_setup();
   set_salvageable((["textile":100]));
   set_id("textile", "pelt");
#ifdef USE_SIZE
   set_size(0);
#endif
#ifdef USE_MASS
   set_mass(0.5);
#endif
}

int is_pelt()
{
   return 1;
}

void internal_setup()
{
   this_object()->add_save(({"pelt_size", "pelt_type"}));
}
