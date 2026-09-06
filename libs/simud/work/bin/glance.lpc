#include <const.h>

int main( string param ) {
   object env;
   string buf, tmp, *inv;

//   msg("Begin look:" + utime()[0] + ":" + utime()[1]);
   env = environment(this_player());
   set_listener(this_player());

   if(!env) {
      this_player()->move( "/obj/void" );
      env = environment(this_player());
   }
   if(!env) {
      msg("Glance command fails; I couldn't even get the void to work.\n");
      return 1;
   }

   buf = "~CTIT" + env->query_short();
   tmp = env->query_exit_list();
   if( tmp )
      buf += " ~CREF(Exits: " + comma_list( tmp ) + ")~CDEF";
   else
      buf += "~CDEF";
   msg( buf + "\n" );

   inv = env->query_inventory_list();
   if( inv ) {
      mapping actions = ([ ]);
      mixed *mobs;
      string curr_phrase, *curr_actors;
      int i;

      buf = "";

      inv -= ({ this_player() });
      mobs = filter( inv, (: $1->query_is_living() :) );
      if( sizeof(mobs) ) {
         for( i = sizeof(mobs); i--; ) {
            string doing;

            doing = mobs[i]->query_doing();
            if( !doing ) doing = "standing here";
            if( !actions[doing] ) actions[doing] = ({ });
            actions[doing] += ({ mobs[i] });
         }

         tmp = "";
         mobs = ({ });
         i = 0;
         foreach( curr_phrase, curr_actors : actions ) {
            mobs = curr_actors;
            if( sizeof(curr_actors) == 1 ) {
               switch( i ) {
                  case 0: tmp += "You see " + inventory_string(curr_actors) + ", " + curr_phrase + ". "; break;
                  case 1: tmp += capitalize(inventory_string(curr_actors)) + " is " + curr_phrase + ". "; break;
                  case 2: tmp += "You also see " + inventory_string(curr_actors) + ", " + curr_phrase + ". "; i = -1; break;
               }
               i++;
            }
            else
               tmp += capitalize( inventory_string(curr_actors) + " are " + curr_phrase + ". " );
         }
         buf += eval_exp(tmp, this_player());
      }

      inv = filter( inv, (: !$1->query_is_living() :) );
      tmp = inventory_string(inv);
      if( tmp != "" ) {
         if( buf == "" )
            buf += "You see " + tmp + ". ";
         else
            buf += "You also see " + tmp + ". ";
      }
      msg(buf);
   }
   return 1;
}
