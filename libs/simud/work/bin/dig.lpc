mapping legal_exits = ([
   'n': SMAKE_C(0,-1,0),
   'w': SMAKE_C(-1,0,0),
   's': SMAKE_C(0,1,0),
   'e': SMAKE_C(1,0,0) ]);

string query_action_name( mixed *param ) {
   if( !pointerp(param) || !stringp(param[4]) ) return "Dig";
   return "Dig " + param[4][..8] + (strlen(param[4])>9?"...":"");
}

string convert_path( string short_form ) {
   int ipath;
   int curr_count = 0;
   string long_form;

   long_form = "";
   for( ipath = 0; ipath < strlen(short_form); ipath++ ) {
      switch( short_form[ipath] ) {
      case 'n':
      case 'e':
      case 'w':
      case 's':
         long_form += tab( short_form[ipath..ipath], max(1,curr_count) );
         curr_count = 0;
         break;
      case '0'..'9':
         curr_count = curr_count * 10 + short_form[ipath] - '0';
         if( curr_count > 99 ) curr_count = 99;
         break;
      default:
         return 0;
      }
   }
   return long_form;
}

int main( string param ) {
   object ob;
   string path;

   if( !param ) {
      notify_fail("Where would you like to dig?\n");
      return 0;
   }

   if( strstr(param, " ") != -1 ) {// Syntax fallthrough for wizards
//      notify_fail("Where would you like to dig?\n"); // error for players
      return 0;
   }

   // There are two types of digging -- dig an object, or dig a direction.
   if( ob = single_present(param, environment(this_player())) ) {
      WALK_ACTION( 1000, ob );
      if( !this_player()->push_action(
         ({ 1000, this_object(), this_player(), ST_STANDING, convert_path(param) }) ) )
         msg("You get ready to dig.");
      return 1;
   }
   path = convert_path(param);
   if( !path ) {
      notify_fail("You need to either dig <something>, or dig <path>\n");
      return 0;
   }
   else if( !this_player()->push_action(
      ({ 1000, this_object(), this_player(), ST_STANDING, convert_path(param) }) ) )
      msg("You get ready to dig.");

   return 1;
}

void on_action( object target, string param ) {
   int delta, dig_flag;
   object ob, *oblist;

   if( !param ) {
      // practice geology
      this_player()->practice_skill("knowledge.science.geology");
      target->on_dig( 0 );
      return;
   }
   if( strlen(param) < 1 ) return;
   if( !member(legal_exits, param[0]) ) return 0;
   delta = legal_exits[param[0]];
   oblist = filter(all_inventory(environment(this_player())), (: $1->query_is_diggable() :) );
   if( !sizeof(oblist) ) {
      msg("Nothing to dig here!\n");
   }

   dig_flag = 0;
   foreach( ob : oblist )
      dig_flag |= ob->on_dig(delta);

   if( !dig_flag ) {
      msg( "You can't dig that way." );
      return; // If dig fails, quit trying
   }

   // practice geology
   this_player()->practice_skill("knowledge.science.geology");
   // practice mining ;)
   this_player()->practice_skill("craft.mining",2);

   // Continue on digging path
   // gpfault:  push at front of queue so that precise digs don't get
   // interrupted.
   if( strlen(param) > 1 )
   this_player()->set_action(-1,
         ({ 1000, this_object(), this_player(), ST_STANDING, param[1..] }) );
}
