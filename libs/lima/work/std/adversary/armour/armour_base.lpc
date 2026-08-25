/* Do not remove the headers from this file! see /USAGE for more info. */

//: FUNCTION set_wearing
// void set_wearing(string);
// A quick and easy way to give monsters armour. Pass the filename of an
// armour object from within the setup() function of your monster.
void set_wearing(string s)
{
   object ob = new (evaluate_path(s, 0, 1));
   if (!ob)
      return;

   ob->move(this_object());
   ob->do_wear();
}
