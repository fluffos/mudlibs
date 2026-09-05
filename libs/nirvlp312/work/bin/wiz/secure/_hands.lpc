#include <security.h>

int cmd_hands(string x)
{
 int wc, num;

 if(!x || !sscanf(x, "%d", num))
 {
  write("Usage: 'hands <weapon_class>'\n");
  return 1;
 }

 wc = num;

 if((num > 10 + (int)this_player()->query_level()/2) && ((int)this_player()->query_level() < ALL_POWER))
 {
  wc = (10 + (int)this_player()->query_level()/2);
  write("Weapon class "+num+" too high.\n"+
        "Setting weapon class to: "+wc+"\n");
 }
 this_player()->wield(this_player(),1,({"physical",wc,0}));
 write("Ok.\n");
 return 1;
}
