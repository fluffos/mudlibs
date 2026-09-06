#include <armour.h>

void
init_armour()
{
add_action("destr","waste");
}

status
destr(string str) {

 if(id(str)) {
   /* we can do this cuz ac 0 and weight 0 */
   destruct(this_object());
   return 1;
  }
return 0;
}
