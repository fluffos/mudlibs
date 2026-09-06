int main( string param ) {
   string key, text;

   BUILD_CHECK

   if( !param ) {
      notify_fail( "==> [Format] describe thing as description\n\tOR describe thing as !alias\n\tOR describe -thing (to delete)\n");
      return 0;
   }
   if( sscanf(param, "%s as %s", key, text) == 2 ) {
      string desc;
      environment(this_player())->set_extra_desc( key, text );
      desc = environment(this_player())->query_extra_desc( key );
      if( key && key[0] == '!' ) desc = environment(this_player())->query_extra_desc( key[1..] );
      msg( "Now, " + key + " is described as '" + desc + "'" );
      return 1;
   }
   if( sscanf(param, "-%s", key) == 1 && environment(this_player())->query_extra_desc(key) ) {
      environment(this_player())->remove_extra_desc( key );
      msg("Description deleted");
      return 1;
   }
   return 0;
}