inherit OBJ;
inherit M_GETTABLE;

string capability;
int level;

string *items =
    ({"scanner range", "hyperdrive stabilizer", "shield", "navigation AI", "engine overclock", "energy weapon refit"});

void internal_value()
{
   int cost;
   switch (capability)
   {
   case "scanner range":
      cost = level * 1000;
      break;
   case "hyperdrive stabilizer":
      cost = level * 2000;
      break;
   case "shield":
      cost = level * 500;
      break;
   case "navigation AI":
      cost = level * 1500;
      break;
   case "engine overclock":
      cost = level * 900;
      break;
   case "eneergy weapon refit":
      cost = level * 750;
      break;
   default:
      cost = level * 500;
      break;
   }
   set_value(cost);
}

void mudlib_setup(string c, int l)
{
   if (c)
      capability = c;
   if (l)
      level = l;
   set_id("module", "upgrade");
   internal_value();
}

string short()
{
   return capability+" module (L"+level+")";
}

string long()
{
   return "A terminal module for a ship computer. Insert it into a ship terminal for it to automatically "
          "upgrade when docked at a capable spacestation." +
          (capability ? " This one has a label on it saying '" + capitalize(capability) + " Level " + level + "'."
                      : " This module is empty, ready for a program to be installed.");
}

mixed *setup_args()
{
   return ({capability, level});
}

int is_terminal_module()
{
   return 1;
}

string query_module_name()
{
   return capability;
}

// Can be put into things.
mixed direct_put_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   return 1;
}

void internal_setup()
{
   add_save(({"capability", "level"}));
}