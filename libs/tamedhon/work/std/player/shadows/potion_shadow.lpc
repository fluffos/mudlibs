#include <defines.h>

object x;

create()
{
   x = shadow(previous_object(), 1);
   printf("%O\n", x);
}

FindPotion(string s)
{
   if (s)
      write(s);
   else
      write("Du findest einen Zaubertrank, den Du sofort trinkst.\n");
   SelectWhich();
   return 1;
}

SelectWhich()
{
   write("ZAUBERTRANK GEFUNDEN, STATS ERHÖHEN!\n");
   return 1;
}
