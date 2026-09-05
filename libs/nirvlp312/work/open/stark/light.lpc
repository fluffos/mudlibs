#include "/players/stark/defs.h"
int light_time;

string short() { return "Softly glowing orb"; }

mixed id(string str) { return str == "druid_orb"; }

void long()
{
    return write("A collection of light which glows softly.\n");
}

void reset(int arg)
{
    if(arg) return;  
    set_light(1);
    light_time=100;
    set_heart_beat(1);
}

status drop() { return 1; }

void heart_beat()
{
    light_time --;
    if(!light_time)
    {
      set_light(-1);
      tell_object(environment(), "The light twinkles and fades away.\n");
      destruct(TO);
    }
} 
