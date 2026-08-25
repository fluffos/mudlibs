/* save_object
 * simuled to make the define NO_SAVE work without too much hassle.
 * some files has to be saved, therefor the include of an array
 * Baldrick, dec '97
 */

#include <save_anyway.i>;

int save_object( string name, int flag )
  {
#ifdef NO_SAVE
 /* member_array costs but it's the best way to do it. 
  */
  if (member_array(name, save_anyway) != 1)
    return 1;
#endif 
  //return efun::save_object( name, flag );
  //function x = bind((:efun::save_object:), previous_object());
  function x = bind((:efun::save_object(name, flag):), previous_object());
  return apply(x, name, flag); 
} 
