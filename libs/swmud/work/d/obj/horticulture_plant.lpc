inherit OBJ;

private string type = "healing";
private int potency = 20;
private int planted_time = 0;
private int growth_state = 0;

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

   planted_time = time();

   set_id("seed in the ground", "horticulture_plant");
   set_long("A seed that has been planted in the ground.  If you're looking at it then you must have x-ray vision.");

   set_attached(1);
   set_heart_beat(1);
}

void heart_beat()
{
   set_heart_beat(1);

   if (((time() - planted_time) >= 120) && (growth_state == 2))
   {
      set_heart_beat(0);

      clear_id();
      set_id("grown " + type + " plant", type + " plant", "plant", "horticulture_plant");
      set_long("A plant that is ready to be harvested by an Ithorian for its " + type + " properties.");

      growth_state++;
   }
   else if (((time() - planted_time) >= 60) && (growth_state == 1))
   {
      clear_id();
      set_id("small " + type + " plant", type + " plant", "plant", "horticulture_plant");
      set_long("A small " + type + " plant that is still growing.");

      growth_state++;
   }
   else if (((time() - planted_time) >= 30) && (growth_state == 0))
   {
      tell_from_outside(environment(), "A small sprout emerges from the soil.\n");

      clear_id();
      set_id("small " + type + " plant sprout", type + " plant sprout", type + " sprout", "sprout", "horticulture_plant");
      set_long("A small sprout that will grow into a " + type + " plant.");

      set_attached(0);

      growth_state++;
   }
}

string query_plant_type() { return type; }
int query_plant_potency() { return potency; }

int ready_for_harvest()
{
   if ((time() - planted_time) >= 120)
   {
      return 1;
   }

   return 0;
}

void do_check_obj()
{
   if (this_body()->query_race() == "ithorian")
   {
      write("You check " + this_object()->the_short() + " and discover that it has " + potency + "% of its maximum potency.\n");

      return;
   }

   write("It looks like a normal " + type + " plant.\n");
}