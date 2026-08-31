/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Moved from M_VALUABLE into OBJ. We want players to clean the MUD, so everything potentially has value. Besides, this
** is one integer and 3 functions. We will be okay.
*/

nosave float object_value = 0;
nosave float value_factor = 1;

//: FUNCTION set_value_factor
// This factor is multiplied unto the value of the
// item. It's an easy way to modify the avlue of something
// being able to turn up back to normal again.
void set_value_factor(float f)
{
   value_factor = f;
   ;
}

//: FUNCTION query_value_factor
// Returns the value factor, see also set_value_factor(float f).
float query_value_factor()
{
   return value_factor;
}

//: FUNCTION set_value
// Sets the value of the item to a float.
void set_value(float value)
{
   object_value = value;
}

//: FUNCTION reduce_value_by
// Divide the value of the item by this number
void reduce_value_by(int times)
{
   object_value = object_value / times;
}

//: FUNCTION increase_value_by
// Multiply the value of the item by this number
void increase_value_by(int times)
{
   object_value = object_value * times;
}

//: FUNCTION query_value
// Returns the value of the item which is normally
// calculated as:
//   object value * value factor
float query_value()
{
   return object_value * value_factor;
}
