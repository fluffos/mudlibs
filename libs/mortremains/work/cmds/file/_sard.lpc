// Sar (Search And Replace) by Inspiral@Tmi-2

#include <mudlib.h>
inherit DAEMON;
 
int cmd_sard (mixed str) {
  int i, siz;
  string *files;
  string s1, s2, s3, s4, work, work2, blah;
             
  notify_fail("SAD: sad <search string> yes <file[s]>\n") ;
  
  if( !str || str == "" ) return 0;
 
  s4 = str[0..0];
  if( sscanf( str, s4 + "%s" + s4 + " " + s4 + "%s" + s4 + " %s", 
              s1, s2, s3) != 3 )
     if( sscanf( str, "%s %s %s", s1, s2, s3 ) != 3 )
        return 0;
 
/* ..
  if( s1 == s2 )
     return notify_fail( "SAD:  <search_string> should not match <replace_string>.\n" );
  */
  files = (string *) this_player() -> wild_card( s3 );
 
  if( !(siz = sizeof( files )) ) {
     notify_fail( sprintf( "SAD:  File(s) %O not found.\n", s3 ) );
     return 0;
  }                 
 
  message("developer", "SAD:  Beginning file sweep.\n",this_player() );
  for( i = 0; i < siz; i++ )  {
     if( !file_exists( files[i] ) ) continue;
     s4 = read_file( files[i] );                                  
 
     if( s4 && ( strsrch( s4, s1 ) > -1 ) ) {
        message("developer",sprintf( "SAD:  Opening %O ... ", files[i],
   ), this_player() );
  i =1 ;
  blah = s4 ;
  while (i) {
  i = sscanf(blah, "%s^M%s", work, work2 ) ;
    blah = work + work2;
  }
        rm( files[i] );
        write_file( files[i], s4 + "\n" );
         message("developer", "deleted.\n", TP ) ;
     }
  }
                         
  message("developer", "SAD: Done.\n",this_player() );
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

