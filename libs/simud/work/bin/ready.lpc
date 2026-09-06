#include <const.h>

/** Displays the ready meter for this living object to this_object().
 */
void force( object who, string spamlevel ) {
   int i,
       x = this_player()->query_readiness();
   string buf = "~[100Readiness: ~[150[~[140";

   /* quick hack to make sure the victim isn't being spammed to death by
    * the meter because they have zero will and speed.
    * should probably think this over some time...
    */
   if (this_player()->query_will() == 0)
     this_player()->set_will(1);
   if (this_player()->query_speed() == 0)
     this_player()->set_speed(1);

   // minimal meter
   if (spamlevel == "1") {
     if (x > 1000)
       buf = tab("#",20);
     else if (x > 0)
       buf = tab("=",x/50) + tab("-",20-(x/50));
     else if (x > -1000)
       buf = tab("-",(x+1000)/50) + tab(" ",20-(x+1000)/50);
     else
       buf = tab(" ",20);

     if (this_player()->query_held())
       buf = "~[090" + buf;
     else if (this_player()->query_busy())
       buf = "~[030" + buf;
     else
       buf = "~[110" + buf;

     buf = "~[150[" + buf + "~[150]";
     if (this_player()->query_level() >= WIZLEVEL)
       buf += " ~[070(" + (string)x + ")";
   }

   // normal meter
   if (spamlevel == "2") {
     if (x > 2000)
       buf += tab("#", 25);
     if (x > 1000)
       buf += tab("#", (x-1000)/40) + "~[150" + tab("=", 25 - ((x-1000)/40));
     else if (x > 0)
       buf += tab("=", x/40) + "~[150" + tab("-", 25 - (x/40));
     else if (x > -1000)
       buf += tab("-", (x+1000)/40) + "~[150" + tab(" ", 25 - ((x+1000)/40));
     else
       buf += tab(" ", 25);
     buf += "~[150] ";

     if (this_player()->query_held())
       buf += "~[090H ";
     else if (this_player()->query_busy())
       buf += "~[030B ";

     if (this_player()->query_level() >= WIZLEVEL)
       buf += "~[070(" + (string)x + ") ";
   }

   // high spam meter
   if (spamlevel == "3" || !spamlevel) {
     if (x > 2000)
       buf += tab("#", 50);
     if (x > 1000)
       buf += tab("#", (x-1000)/20) + "~[150" + tab("=", 50 - ((x-1000)/20));
     else if (x > 0)
       buf += tab("=", x/20) + "~[150" + tab("-", 50 - (x/20));
     else if (x > -1000)
       buf += tab("-", (x+1000)/20) + "~[150" + tab(" ", 50 - ((x+1000)/20));
     else
       buf += tab(" ", 50);
     buf += "~[150] ";

     if (this_player()->query_held())
       buf += "~[090HELD";
     else if (this_player()->query_busy())
       buf += "~[030BUSY";
     else if (x >= this_player()->readiness_required())
       buf += "~[140READY";

     if (this_player()->query_level() >= WIZLEVEL)
       buf += " ~[070(" + (string)x + ")";
     buf += "\n";
   }

   // Put next action to be performed at end of meter
   if (spamlevel != "1") {
     buf += "~[100Action: ~[070";
     if(sizeof(this_player()->query_actions())) {
       buf += this_player()->query_action_name(0);
       for (i = 1; i < sizeof(this_player()->query_actions()) && i < 5; i++)
         buf += ", " + this_player()->query_action_name(i);
       if (sizeof(this_player()->query_actions()) > 5)
         buf += ", ...";
     } else if (this_player()->query_target()) {
       buf += "*fight*";
     } else
       buf += "<none>";
   }

   // spam poor fool with meter
   msg_object( who, buf+"~CDEF" );
}

int main( string param ) {
   string level;

   force( this_player(), param );

   switch(this_player()->query_env_var("Tautoready")) {
      case 0: level = "off"; break;
      case 1: level = "low"; break;
      case 2: level = "normal"; break;
      case 3: level = "high"; break;
      default:level = "messed up";
   }
   msg("Autoready display level is " + level + ".");

   return 1;
}
