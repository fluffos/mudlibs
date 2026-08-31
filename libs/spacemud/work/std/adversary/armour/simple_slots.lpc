/* Do not remove the headers from this file! see /USAGE for more info. */

private
mapping slots = allocate_mapping(({"torso", "head", "arms", "legs", "hands", "feet"}), 0);
private
mapping non_armours = allocate_mapping(({"left hand", "right hand", "neck"}), 0);

private
int wear_non_armour(object what, string sname)
{
   if (undefinedp(non_armours[sname]) || non_armours[sname])
      return 0;

   non_armours[sname] = what;
   return 1;
}

//: FUNCTION wear_item
// nomask int wear_item(object what, string sname);
// Wear item 'what' on armour slot 'sname'.
nomask int wear_item(object what, string sname)
{
   if (wear_non_armour(what, sname) == 1)
      return 1;

   if (undefinedp(slots[sname]) || slots[sname])
      return 0;

   slots[sname] = what;
   return 1;
}

//: FUNCTION remove_item
// nomask int remove_item(object what, string sname);
// Remove armour 'what' from armour slot 'sname'.
nomask int remove_item(object what, string sname)
{
   if (slots[sname])
   {
      slots[sname] = 0;
      return 1;
   }
   if (non_armours[sname])
   {
      non_armours[sname] = 0;
      return 1;
   }
}

nomask mixed get_random_clothing()
{
   return choice(values(slots));
}

//: FUNCTION has_body_slot
// nomask int has_body_slot(string what);
// Returns 1 if 'what' is a valid armour slot.
nomask int has_body_slot(string what)
{
   return (!undefinedp(slots[what]) || !undefinedp(non_armours[what]));
}

//: FUNCTION query_armour_slots
// string *query_armour_slots();
// Returns an array of all valid armour slots.
string *query_armour_slots()
{
   return keys(slots);
}

string query_random_armour_slot()
{
   string tmp;

   tmp = choice(keys(slots));

   return tmp;
}

object *event_get_armours()
{
   object *tmp = ({get_random_clothing()}) - ({0});
   if (!sizeof(tmp))
      return 0;
   else
      return tmp;
}
