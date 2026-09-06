#include <const.h>

int main() {
   object *targets;
   string name, buf;
   int i, has_target;

   targets = this_player()->query_targets();
   buf = "~CTITYou are currently fighting:~CDEF";
   has_target = 0;
   for( i = 0; i < sizeof(targets); i++ )
   if( objectp(targets[i]) ) {
      name = capitalize(targets[i]->query_distant());
      buf += "\n  " + name;
      has_target = 1;
   }
   if( !has_target ) buf += "\n  Nothing.";
   msg( buf, 4 );

   return 1;
}