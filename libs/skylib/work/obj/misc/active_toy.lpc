inherit OBJECT_OBJ;
inherit "/std/basic/item_chat";

string hug, pet, cuddle, fondle, snuggle, squeeze;

void set_hug( string words ) { hug = words; }

void set_pet( string words ) { pet = words; }

void set_cuddle( string words ) { cuddle = words; }

void set_fondle( string words ) { fondle = words; }

void set_snuggle( string words ) { snuggle = words; }

void set_squeeze( string words ) { squeeze = words; }

void init() {
   item_chat::init();
   this_player()->add_command( "hug", this_object() );
   this_player()->add_command( "pet", this_object() );
   this_player()->add_command( "cuddle", this_object() );
   this_player()->add_command( "fondle", this_object() );
   this_player()->add_command( "snuggle", this_object() );
   this_player()->add_command( "squeeze", this_object() );
} /* init() */

int do_hug() {
   this_player()->add_succeeded_mess( this_object(), replace( hug,
         "$poss_short$", poss_short() ), ({ }) );
   return 1;
} /* do_hug() */

int do_pet() {
   this_player()->add_succeeded_mess( this_object(), replace( pet,
         "$poss_short$", poss_short() ), ({ }) );
   return 1;
} /* do_pet() */

int do_cuddle() {
   this_player()->add_succeeded_mess( this_object(), replace( cuddle,
         "$poss_short$", poss_short() ), ({ }) );
   return 1;
} /* do_cuddle() */

int do_fondle() {
   this_player()->add_succeeded_mess( this_object(), replace( fondle,
         "$poss_short$", poss_short() ), ({ }) );
   return 1;
} /* do_fondle() */

int do_snuggle() {
   this_player()->add_succeeded_mess( this_object(), replace( snuggle,
         "$poss_short$", poss_short() ), ({ }) );
   return 1;
} /* do_snuggle() */

int do_squeeze() {
   this_player()->add_succeeded_mess( this_object(), replace( squeeze,
         "$poss_short$", poss_short() ), ({ }) );
   return 1;
} /* do_squeeze() */

mapping query_static_auto_load() {
   if ( explode( file_name( this_object() ), "#" )[ 0 ] !=
         "/obj/misc/active_toy" )
      return 0;
   return ([
      "::" : int_query_static_auto_load(),
      "hug" : hug,
      "pet" : pet,
      "cuddle" : cuddle,
      "fondle" : fondle,
      "snuggle" : snuggle,
      "squeeze" : squeeze
   ]);
} /* query_static_auto_load() */

mapping query_dynamic_auto_load() {
   mapping tmp;

   tmp = ([ "::" : object::query_dynamic_auto_load(),
            "chat" : item_chat::query_dynamic_auto_load(),
          ]);
   return tmp;
} /* query_dynamic_auto_load() */

void init_dynamic_arg(mapping map) {
   if ( !map )
      return;
   if (map["::"])
      object::init_dynamic_arg(map["::"]);
   if (map["chat"])
      item_chat::init_dynamic_arg(map["chat"]);
} /* init_dynamic_arg() */

void init_static_arg( mapping map ) {
   if ( !map )
      return;
   if ( map[ "::" ] )
      ::init_static_arg( map[ "::" ] );
   hug = map[ "hug" ];
   pet = map[ "pet" ];
   cuddle = map[ "cuddle" ];
   fondle = map[ "fondle" ];
   snuggle = map[ "snuggle" ];
   squeeze = map[ "squeeze" ];
} /* init_static_arg() */
