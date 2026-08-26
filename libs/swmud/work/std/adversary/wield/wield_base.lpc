int do_wield(object);

int set_wielding(string wep)
{
   object ob = new(wep);

   if (!ob) { return 0; }

   ob->move(this_object());

   return do_wield(ob);
}