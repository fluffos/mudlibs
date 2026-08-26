/**
 * Nothing in this shadow should be modified directly.  The shadow
 * should do it all for us.
 */

#include <move_failures.h>

inherit "/std/effect_shadow";

int _keep;
string _identifier;
object _owner;

int query_keep() { return _keep; }

void set_keep_value(int keep) { _keep = keep; }

void set_keep() { _keep = 1; }

void reset_keep() { _keep = 0; }

string query_identifier() { return _identifier; }

void set_identifier( string word ) { _identifier = word; }

void set_identity_hold_owner(object ob) {
   _owner = ob;
} /* set_identity_hold_owner() */

object query_identity_hold_owner() {
   return _owner;
} /* query_identity_hold_owner() */

string *parse_command_id_list() {
   string *words;

   words = (string *)player->parse_command_id_list();
   if( TP == _owner && stringp( _identifier ) &&
       !sizeof( filter( previous_object( -1 ),
       (: $1->ignore_identifier() :) ) ) ) {
       words += ({ _identifier });
   }

   return words;

} /* parse_command_id_list() */

varargs int move( mixed dest, string messin, string messout ) {
   int flag;
   object ob;

   if( !ENV(player) )
       return player->move( dest, messin, messout );

   flag = player->move( dest, messin, messout );

   if( flag == MOVE_OK && objectp( dest ) ) {
      ob = ENV(player);
      while( ob && ob != _owner )
          ob = ENV(ob);
      if( ob != _owner )
          remove_this_effect();
   }

   return flag;

} /* move() */
