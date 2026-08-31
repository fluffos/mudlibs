/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Tsath March 2020.
** Completely rewritten and extended.
**
*/

inherit OBJ;
inherit M_DAMAGE_SOURCE;
inherit M_GETTABLE;
inherit M_MESSAGES;
inherit M_READY;

private
int charges = -1;
private
string ammo_type = "unknown ammo";
private
int destruct_on_spent = 0;
private
int max_charges = 0;
private
nosave object weapon;

void set_destruct_on_spent()
{
   destruct_on_spent = 1;
}

string query_ammo_type()
{
   return ammo_type;
}

void set_ammo_type(string at)
{
   ammo_type = at;
}

int query_charges()
{
   if (charges == -1)
      return 1;
   return charges;
}

int query_max_charges()
{
   return max_charges;
}

void set_charges(int c)
{
   charges = c;
   max_charges = c;
}

void ammo_for(object w)
{
   weapon = w;
}

void ammo_spent()
{
   if (!charges)
      this_object()->remove();
}

varargs string short(int base)
{
   string short = ::short();
   if (base)
      return short;
   return "clip of " + short;
}

string get_extra_long()
{
   return "The clips seems to have " + charges + " bullets out of " + max_charges + " left.";
}

// Called out when the ammunition has been fired, and has hit/missed
// Overload as necessary, but should typically either remove the item
// or move it to target's environment().
void finish_discharge(object target)
{
   if (charges > 0)
      charges--;
   // TBUG("Charges: " + charges + "/" + max_charges);
   if (destruct_on_spent && !charges)
   {
      object player = environment(this_object())->is_body() ? environment(this_object()) : 0;
      tell(player, "Your " + this_object()->short() + " is empty.\n");
      this_object()->remove();
   }
   else if ((!charges || charges == -1) && !destruct_on_spent)
   {
      this_object()->move(environment(target));
      weapon = 0;
   }
}

// Called when the ammunition is discharged.
// Overload as needed, but normally calls out finish_discharge(),
// which will thus occur after the ammunition has hit/missed the target
void discharge(object target)
{
   call_out(( : finish_discharge:), 0, target);
}

string alt_weapon()
{
   return ::short();
}

object secondary_weapon_part()
{
   return weapon;
}

int is_ammo()
{
   return 1;
}

mixed indirect_load_obj_with_obj(object ob1, object ob2)
{
   // TBUG("ob1: " + ob1 + " ob2: " + ob2);
   if (query_ammo_type() == ob2->query_ammo_type())
      return 1;
   return capitalize(ob2->the_short()) + " requires " + ob2->query_ammo_type() + " and not " + query_ammo_type() + ".";
}