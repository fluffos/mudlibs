#include <const.h>

int main() {
   string buf, tmp;
   object env;
   mapping res;
   int width, val;

   WIZ_CHECK

   width = this_player()->query_term_width() - 2;

   buf = "~CDRK--- ~CTITResources in this room ~CDRK" + tab( "-", width - 28 ) + "\n";
   res = environment(this_player())->query_resources();
   if( !mappingp(res) ) res = ([ ]);
   foreach( tmp, val : res )
     buf += "   ~CLAB"+tmp+"~CDEF: "+val+"\n";

   tmp = sizeof(res) + " total resource" + (sizeof(res)==1?"":"s");
   buf += "~CDRK" + tab( "-", width - (strlen(tmp) + 6) ) + " ~CTIT" + tmp + " ~CDRK---~CDEF";

   msg( buf );
   return 1;
}