/* Do not remove the headers from this file! see /USAGE for more info. */

#include <combat_modules.h>

class event_info
{
   object target;
   string target_extra;
   object weapon;
   mixed data;
}

int
event_damage(class event_info evt)
{
   return evt->data[sizeof(evt.data) - 1];
}

//: FUNCTION event_to_str
// string event_to_str(class event_info evt)
// Shows an event on the combat event queue as a string.
// Only used for debug purposes, but oh so very useful.
string event_to_str(class event_info evt)
{
   string data = "";
   string out = "Event:\n"
                " target=" +
                evt.target +
                "\n"
                " target_extra=" +
                evt.target_extra +
                "\n"
                " weapon=" +
                evt.weapon + "\n";

   if (arrayp(evt.data))
   {
      int count = 0;
      foreach (mixed ele in evt.data)
      {
         if (arrayp(ele))
         {
            string ar = "[";
            foreach (mixed e in ele)
               ar += e + ", ";
            data += " evt.data[" + count + "]=" + ar + "]\n";
         }
         else
            data += " evt.data[" + count + "]=" + ele + "\n";
         count++;
      }
   }
   else if (stringp(evt.data))
      data += " " + evt.data;

   return out + data;
}