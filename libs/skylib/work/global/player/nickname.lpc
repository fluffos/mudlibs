/*
 * The great and wonderful alias driver by me ;)
 * pinkfish.
 */
mapping map_nicknames;

void nickname_commands() {
}

mapping query_nicknames() { return map_nicknames; }
void set_nicknames(mapping map) { map_nicknames = map; }
     
string expand_nickname( string phrase ) {
   int i;
   string new_n, *words;
   if ( stringp( phrase ) )
      words = explode( phrase, " " );
   else
      return phrase;
   if ( !map_nicknames )
      map_nicknames = ([ ]);
   for ( i = 0; i < sizeof( words ); i++ ) {
      new_n = map_nicknames[ lower_case( words[ i ] ) ];
      if ( new_n )
         words[ i ] = new_n;
   }
   return implode( words, " " );
} /* expand_nickname() */
 
