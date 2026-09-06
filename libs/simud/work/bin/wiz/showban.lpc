#include <const.h>

int main() {
   string *bans, buf;
   int n, i;

   bans = "/secure/banned_names"->query_banned_names();
   buf = "~CTITBanned names\n~CDRK------------\n~CDEF";
   for( i = 0; i < sizeof(bans); i++ ) {
      buf += "~CBRT" + (i + 1) + "~CDEF. " + bans[i] + "\n";
   }
   buf += "   ~CLAB" + sizeof(bans) + " total banned~CDEF\n";
   msg( buf );
   return 1;
}