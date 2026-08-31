/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// This module keeps track of charge and charge expenditure for batteries and other
// things that may hold a charge. In your setup() function call:
//
//  |   void setup()
//  |   {
//  |      ...
//  |      set_max_mah(3000);
//  |      set_random_mah();
//  |   }
//
// To set the maximum mah and set it randomly within the interval from 0 to max.
//
// .. TAGS: RST

private
int max_mAh;
private
int mAh_capacity;

private
int rechargable = 0;

//: FUNCTION is_power_source
// Always returns 1 if this module is inherited.
int is_power_source()
{
   return 1;
}

//: FUNCTION set_rechargable
// Set if power source can be recharged or not.
void set_rechargable(int r)
{
   rechargable = r;
}

//: FUNCTION use_charge
// Spend an amount of charge in the power source.
// Returns 1 if successful, otherwise 0 - we're out of power.
int use_charge(int ma)
{
   mAh_capacity -= ma;
   if (mAh_capacity > 0)
      return 1;
   return 0;
}

//: FUNCTION query_rechargable
// Returns 1 if rechargable, otherwise 0.
int query_rechargable()
{
   return rechargable;
}

//: FUNCTION set_max_mah
// Set the maximum charge the power source will hold. Remember to call
// either set_random_mah() or set_mah(number) after this.
void set_max_mah(int c)
{
   max_mAh = c;
}

//: FUNCTION query_max_mah
// Returns the max mah of the power source.
int query_max_mah()
{
   return max_mAh;
}

//: FUNCTION set_mah
// Set a specific charge for the power source. Number will be clamped
// between 0-max mah always.
void set_mah(int c)
{
   mAh_capacity = clamp(c, 0, max_mAh);
}

//: FUNCTION set_random_mah
// Sets the power source to a random mah betwen 25%-100%.
// The chance to be 100% is >25%.
void set_random_mah()
{
   set_mah((max_mAh / 4) + random(max_mAh));
}

//: FUNCTION query_mah
// Returns the current charge of the power source.
int query_mah()
{
   return mAh_capacity;
}
