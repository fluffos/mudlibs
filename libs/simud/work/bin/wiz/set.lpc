#include <const.h>
#include <wizard.h>

void disp_set_var(string key, mixed val) {
   string buf, a, b;
   int i;

   buf = as_lpc(val, 1);
   if( pointerp(val) ) buf = key + "[]=" + buf;
   else if( mappingp(val) ) buf = key + "([])=" + buf;
   else buf = key + "=" + buf;

   /*
   if( !pointerp(val) && !mappingp(val) )
      buf = key + "=" + efun::to_string(val);
   else {
      if( pointerp(val) ) {
         buf = key + "[]=";
         if( sizeof(val) > 0 ) buf += efun::to_string(val[0]);
         for( i = 1; i < sizeof(val); i++ ) {
            buf += "\n" + tab( " ", strlen(key) + 3 ) + efun::to_string(val[i]);
         }
      }
      else {
         buf = reversible_to_string(val);
         buf = implode(explode(buf, "\n"), " ");
         buf = key + "([])=" + buf;
      }
   }
   */
   write(buf+"\n");
}

int main(string comm) {
   mapping v;
   string who;
   object p;

   WIZ_CHECK

   if(!comm) p = this_player(); else {
      if(sscanf(comm, "%s@%s", comm, who) == 2) {
         p = find_player(who);
         if(!p) {
            msg("==> [Error] Could not find that player.");
            return 1;
         }
         if( this_player()->query_level() < ADMLEVEL && p->query_level() >= WIZLEVEL ) {
            notify_fail("==> [Error] Access denied\n");
            return 0;
         }
      }
      else p = this_player();
   }
   if(!comm || comm == "") {
      v = p->query_env_vars();
      walk_mapping(v, "disp_set_var");
   }

   else {
      string var;
      mixed val;
      int success;

      success = 0;
      // Try to decipher what type of expression it is, then
      // perform the appropriate action.
      if( sscanf(comm, "%s+=%s", var, val) == 2 ) {
         success = 1;
         p->add_env_var( trim(var), trim(val) );
      }
      else
      if( sscanf(comm, "%s-=#%d", var, val) == 2 )
         success = p->remove_env_var_item( trim(var), val );
      else
      if( sscanf(comm, "%s-=%s", var, val) == 2 )
         success = p->remove_env_var_item( trim(var), trim(val) );
      else
      if( sscanf(comm, "%s=%d", var, val) == 2 )
         success = p->set_env_var( trim(var), val );
      else
      if( sscanf(comm, "%s=%s", var, val) == 2 )
         success = p->set_env_var( trim(var), trim(val) );

      if( success )
         msg( "==> [Notice] Variable set" );
      else
         msg( "==> [Format] set [expression][@player]\nSee the help file 'help set' for more information." );
   }

   return 1;
}
