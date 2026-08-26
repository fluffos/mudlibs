inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;

private string type = "healing";
private int potency = 20;

void mudlib_setup()
{
   m_valuable::mudlib_setup();
   add_save(({ "type", "potency" }));
}

varargs void setup(string set_type, int set_potency)
{
   if (strlen(set_type))
   {
      type = set_type;
   }

   if (set_potency)
   {
      potency = set_potency;
   }

   set_id(type + " seed", "seed", "horticulture_seed");
   set_long("A seed that may one day grow into a happy, healthy " + type + " plant.");
   set_mass(1);
   set_value(10);
}

string query_seed_type() { return type; }
int query_seed_potency() { return potency; }

void do_check_obj()
{
   if (this_body()->query_race() == "ithorian")
   {
      write("You check " + this_object()->the_short() + " and discover that it has " + potency + "% of its maximum potency.\n");

      return;
   }

   write("It looks like a normal " + type + " seed.\n");
}