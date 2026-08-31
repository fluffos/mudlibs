#ifndef __patFiles__
#define __patFiles__

#include "/players/tatsuo/Includes/general.h"

#define IS_FOLDER    -2
#define NOT_READABLE -1


/* ------------------------------------------------------------------------------------ */
/*    new ls-function                                                                   */
/*    implemented by tatsuo: 20/10/92                                                 */
/*    THANX to klorathy for help                                                        */
/* ------------------------------------------------------------------------------------ */
pLs( path )
{
   string dirRet, fname, oBuf;
   int    i, newLine, noOfFiles, totalBytes;
   
   if ( !path ) {                                              /* path is empty         */
      path = "/" + this_player()->query_path();
      path += "/*";
   }
   else {                                                      /* check extensions      */
      if ( path[0..0] == "~" ) {
         if ( path[1..1] == "/" )
            path = "/players/" + this_player()->query_real_name() + path[1..-1];
         else
            path = "/players/" + this_player()->query_real_name() + "/" + path[1..-1];
      }
      if ( path[0..0] != "/" )                                 /* current directory     */
         path = "/" + this_player()->query_path() + "/" + path;
      
      if ( path[-1..-1] == "*" ) {;}
      else if ( path[-1..-1] == "/" )
         path = path + "*";
      else
         path = path + "/*";
   }
   
   if ( !CheckPath( path ) )
      write( "Error in path: " + path + "\nCan't proceed you command !!!\n" );
      
   write( "directory of path: " + extract( path, 0, strlen( path )-2 ) + "\n" );
   dirRet = get_dir( path );                                   /* gets the directory    */
   if ( !dirRet ) {                                            /* no such directory     */
      write( "No such directory\n" );
      return( 1 );
   }
  
   path = extract( path, 0, strlen( path )-2 );                /* shorten path for find */
      
   if ( sizeof( dirRet ) > 2 ) {                               /* . and ..              */
      i = 2;
      while ( i < sizeof( dirRet ) ) {
         oBuf = dirRet[i];
         if ( CheckPath( dirRet[i] ) ) {                       /* path is ok            */
            if ( file_size( path + dirRet[i] ) == IS_FOLDER )     /* a folder ?         */
               oBuf += "/";
            else if ( file_size( path + dirRet[i] ) == NOT_READABLE )  /* not readable  */
               oBuf += "!";
            else {                                                /* loaded ?           */
               totalBytes += file_size( path + dirRet[i] );       /* counting bytes     */
               fname = explode( dirRet[i], "." );                 /* fname without ext  */
               if ( fname && fname[0])
                  if ( find_object( path + fname[0] ) )
                     oBuf += "*";
            } 
         }
         else                                                  /* path is buggy         */
            oBuf += "???";
         
         write( LeftAlign( oBuf, 19 ) + " " );
         newLine++;
         noOfFiles++;
         
         if ( !(newLine % 4) )                                 /* line-wrapping ?       */
            write( "\n" );
         
         if ( !(newLine % (10*4)) )
            call_out( "dummy", 0 );
         
         if ( !(newLine % (40*4)) ) {                          /* list too long         */
            write( "***TRUNCATED***\n" );
            break;
         }   
         i++;
      }
      
      if ( newLine % 4 )                                       /* closing NL            */
         write( "\n" );
   }
  
   if ( (newLine % (40*4)) || (!newLine) ) {
    write( noOfFiles + " files/folders in this directory which need "
             + totalBytes + " bytes.\n" );
   }

   return( 1 );
}


/* ------------------------------------------------------------------------------------ */
/*     checks, it there are any spaces in the path                                      */
/* ------------------------------------------------------------------------------------ */
CheckPath( path )
{
   int i;
   
   while ( i < strlen( path ) ) {
      if ( path[i..i] == " " )
         return( 0 );
      i++;
   }
   return( 1 );
}

dummy() { return( 0 ); }

#endif /*__patFiles__*/
