int main( string param ) {
   string wizname, reason;
   int count;

   ADM_CHECK

   if( !param || sscanf(param, "%s %d %s", wizname, count, reason) != 3 )
      return notify_fail( "==> [Format] addpoint wizname points reason\n" );
   if( getuid() != "root" )
      raise_error( "The addpoint verb MUST be UID 'root', or it won't work" );

   wizname = lower_case( wizname );

   // checks that wizard exists
   if( !legal_filename(wizname) )
      return notify_fail( "That is not a legal name for a character.\n" );
   if( !sizeof(get_dir(PLAYER_DIR+wizname+".o")) &&
      !"/daemon/point"->query_points(wizname) )
      return notify_fail( "There is no one named " + capitalize(wizname) + ".\n" );

   "/daemon/point"->add_point( wizname, count, reason );
   msg( "Points added." );
   send_im( wizname, "You have been awarded " + count + " point" + (count==1?"":"s") + ". Reason: '" + capitalize(reason) +"'\n" );

   return 1;
}
