/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** M_HEALING
**
** Module that handles healing limbs of living things.
**
** Tsath 2019-11-16
*/

private
int heal_value = 0;

int is_healing()
{
   return 1;
}

private
object find_whom_to_heal()
{
   return environment()->is_living() ? environment() : this_body();
}

//: FUNCTION set_heal_value
// Sets the number of HP returned by one hit from this
// thing.
void set_heal_value(int val)
{
   heal_value = val;
}

//: FUNCTION query_heal_value
// Query the number of HP returned by one hit from this
// thing.
int query_heal_value()
{
   return heal_value;
}

void heal_limb(string limb)
{
   if (find_whom_to_heal())
      find_whom_to_heal()->heal_us(heal_value, limb);
}

void heal_from_food()
{
   if (find_whom_to_heal())
      find_whom_to_heal()->heal_us(heal_value);
}

void heal_from_slowheal()
{
   if (find_whom_to_heal())
      find_whom_to_heal()->heal_us(heal_value);
}

void heal_from_drink()
{
   if (find_whom_to_heal())
      find_whom_to_heal()->heal_us(heal_value);
}

void heal_from_bandage(string limb)
{
   if (find_whom_to_heal())
      find_whom_to_heal()->heal_us(heal_value, limb);
}