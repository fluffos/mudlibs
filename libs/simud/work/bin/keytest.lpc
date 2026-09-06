#include <keys.h>

mapping pkeys;

create() {
   pkeys = ([ ]);
}

void keytest( string c ) {
   string key;
   mapping m;
   int n;

   key = this_player()->query_name();
   m = KEY_NAMES;

   if( !pkeys[key] ) pkeys[key] = "";
   if( pkeys[key] != "" || c[0] < 32 || c[0] > 126 )
      pkeys[key] += c;

   if( c[0] < 32 || c[0] > 126 )
      write("The code for that key is "+c[0]+".\n");
   else
      write("The code for that key is "+c[0]+" ("+c+")\n");

   if( (n = this_player()->translate_code(pkeys[key])) != KEY_NONE ) {
      pkeys[key] = "";
      write("Code translated: "+n+" ("+KEY_NAMES[n]+")\n");
   }

   if( c == "q" ) drop_interface();
}

int main() {
   msg("This command lets you test out keys. Type 'q' to exit.");
   add_interface("@keytest", 0);
   return 1;
}
