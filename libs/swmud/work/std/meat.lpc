inherit JUNK;
inherit M_DECAY;
inherit M_EDIBLE;

string meat_type = "unknown";
int meat_level = 1;

void setup_meat()
{
   set_id("piece of " + meat_type);
   add_id(meat_type);
   set_long("This is a piece of " + meat_type + ".");
   set_num_decays(3);
   set_decay_action("The " + meat_type + " decays a little.\n");
   set_last_decay_action("The " + meat_type + " rots away.\n");
   set_decay_time(5);
   set_num_eats(1 + random(meat_level));
   set_decay_auto_remove(1);
   set_eat_action("$N $veat a piece of raw " + meat_type + ".");
   set_last_eat_action("$N $vfinish the raw " + meat_type + ". A bit chewy.");
}

void mudlib_setup(string type, int level)
{
   ::mudlib_setup(type);
   m_decay::mudlib_setup();
   set_id("meat");

   if (type)
   {
      meat_type = type;
      meat_level = level;
   }

   call_out("setup_meat", 0);
}

void internal_setup()
{
   this_object()->add_save(({"meat_type", "meat_level"}));
}