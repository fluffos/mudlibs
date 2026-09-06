int main( string param ) {
   string name1, name2;

   if( !param || sscanf(param, "%s %s", name1, name2) != 2 ) {
      notify_fail("==> [Format] objrename source_name dest_name\n");
      return 0;
   }

   name1 = this_player()->make_path_absolute( name1 );
   name2 = this_player()->make_path_absolute( name2 );
   "/daemon/uptodate"->add_file_rename( name1, name2 );

   msg( "OK, " + name1 + " will switch to " + name2 + " next time the uptodate daemon reloads it." );
   return 1;
}