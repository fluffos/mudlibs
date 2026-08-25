/* Do not remove the headers from this file! see /USAGE for more info. */

int do_wield(object);

//: FUNCTION set_wielding
// int set_wielding(string wep)
//  A quick and easy way to give monsters weapons. Pass the filename of a
//  weapon object from within the setup() function of your monster.
int set_wielding(string wep)
{
   object ob = new (evaluate_path(wep, 0, 1));

   if (!ob)
      return 0;
   ob->move(this_object());
   return do_wield(ob);
}

//: FUNCTION add_item
// void add_equipment(string file, int num)
// This function adds equipments given by the filename to adversaries.
// The 'num' parameter is optional, and defaults to 1. But more can
// be specified.
varargs void add_equipment(string file, int num)
{
   if (!num)
      num = 1;
   for (int i = 0; i < num; i++)
   {
      object ob = new (file);
      ob->move(this_object());
   }
}
