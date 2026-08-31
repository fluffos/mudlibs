inherit OBJ;
inherit M_GETTABLE;

string guild;
string letter;

void mudlib_setup(string g)
{
   if (g)
      guild = g;
   set_id("vdu module", "module");
   set_adj(guild);
   set_value(50);
}

string long()
{
   return "A small VDU module. Insert it into a VDU for it to work." +
          (guild ? " This one has a label on it saying '" + capitalize(guild) + "'."
                 : " This module is empty, ready for a program to be installed.");
}

int is_vdu_module()
{
   return 1;
}

void set_module_name(string n)
{
   guild = n;
   set_adj(guild);
}

void set_letter(string l)
{
   letter = l;
}

string query_letter()
{
   return letter || guild[0..0];
}

string query_module_name()
{
   return guild;
}

// Can be put into things.
mixed direct_put_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   return 1;
}

void internal_setup()
{
   this_object()->add_save(({"guild", "letter"}));
}