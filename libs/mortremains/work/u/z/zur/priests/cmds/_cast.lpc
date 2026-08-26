#include "../pr.h"
int cmd_cast(string str) {
  string spell, arg1, arg2, file;
  int rev;
  int lv;
  seteuid( getuid() );
  load_object(PRIEST_SPELL);
  load_object(REL_D);
  if (!str)
     return (int) notify_fail("Cast what?\n");
  
  if(sscanf(str,"reverse %s", str)) rev = 1;
  
  if (sscanf(str, "%s at %s", spell, arg1) != 2 )
  
  if (sscanf(str, "%s at", spell) == 1)
  {
    write("Cast "+spell+" at who?\n");
    return 1;
    }
  else
  {
   if (sscanf(str, "%s %s", spell, arg1)!=2) spell = str;
   }
  file = SPELLS + spell;

  if(!find_object(file))
  {
    write("Failed to find_object(): "+file+".\n");
    return (int) notify_fail("You know of no such spell you could cast.\n");
  }
  if(call_other(file, "start_spell", rev, arg1, arg2) == 0)
    {
      return (int) notify_fail("*Error loading priest spell. Notify administration imediately.\n");
    }
  return 1;
}
