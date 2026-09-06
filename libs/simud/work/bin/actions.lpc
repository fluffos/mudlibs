#include <const/battconst.h>

int main( string param ) {
   mixed *actions;
   string buf, tmp;
   object action_ob;
   int i;

   actions = this_player()->query_actions();
   if( !pointerp(actions) || sizeof(actions) == 0 ) {
      msg("You haven't got any actions waiting.");
      return 1;
   }
   buf = "~CMA5Actions waiting:~CMA3 ( ~CMA4";
   for( i = 0; i < sizeof(actions); i++ ) {
      if( actions[i][B_FNAME] == "me" ) action_ob = this_player();
      else action_ob = actions[i][B_FNAME];

      if( !objectp(action_ob) || !stringp(tmp = action_ob->query_action_name(actions[i])) ) {
         tmp = "Unnamed action";
		 debug( as_lpc(action_ob), "combat" );
      }

      if( i != 0 ) buf += " ~CMA2| ~CMA4";
      buf += tmp;
   }
   buf += " ~CMA3)~CDEF";

   msg( buf );

   return 1;
}
