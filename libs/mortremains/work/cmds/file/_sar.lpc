// Sar (Search And Replace) by Inspiral@Tmi-2

#include <mudlib.h>
inherit DAEMON;
 
int cmd_sar( mixed str ) {
  int i, siz;
  string *files;
  string s1, s2, s3, s4;
             
  notify_fail("SAR:  sar <search_string> <replace_string> <file(s)>\n");
  
  if( !str || str == "" ) return 0;
 
  s4 = str[0..0];
  if( sscanf( str, s4 + "%s" + s4 + " " + s4 + "%s" + s4 + " %s", 
              s1, s2, s3) != 3 )
     if( sscanf( str, "%s %s %s", s1, s2, s3 ) != 3 )
        return 0;
 
  if( s1 == s2 )
     return notify_fail( "SAR:  <search_string> should not match <replace_string>.\n" );
  files = (string *) this_player() -> wild_card( s3 );
 
  if( !(siz = sizeof( files )) ) {
     notify_fail( sprintf( "SAR:  File(s) %O not found.\n", s3 ) );
     return 0;
  }                 
 
  message("developer", "SAR:  Beginning file sweep.\n",this_player() );
  for( i = 0; i < siz; i++ )  {
     if( !file_exists( files[i] ) ) continue;
     s4 = read_file( files[i] );                                  
 
     if( s4 && ( strsrch( s4, s1 ) > -1 ) ) {
        message("developer",sprintf( "SAR:  Opening %O ... ", files[i],
   ), this_player() );
        s4 = replace_string( s4, s1, s2 );
        rm( files[i] );
        write_file( files[i], s4 + "\n" );
        message("developer","replaced.\n",this_player() );
     }
  }
                         
  message("developer", "SAR: Done.\n",this_player() );
  return 1;
}  

string help() {

return @HelpText      

Usage:   sar <search_string> <replace_string> <file(s)>

This command searches all specified files for the occurance of the
search string, and replaces it with the replace string.

Cave at: You can't have spaces in the search or replace strings
HelpText;
}
