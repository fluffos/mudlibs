#include <mailer.h>

// Some muds don't have this...if you already do, please
// uncomment or delete this function.  *Inspiral*

// mudlib: basis
// date:   1992/09/05
// author: Truilkan
 
void mkdirs(string path)
{
        string *parts, dir;
        int j;
 
        seteuid(geteuid(previous_object()));
        parts = explode(path, "/");
        dir = "";
        for (j = 0; j < sizeof(parts); j++) {
                dir += parts[j];
                mkdir(dir);
                dir += "/";
        }
}
 
 
/*
// Function: data_netmail_file( string mud )
// Author:   Inspiral@Tabor
// Date:     12/23/93
*/
 
// this simul_efun returns a savefile in the form:
// NETMAIL_DIR + mud[0..0] + "/" + mud ... "/data/mail/net/t/tabor"
// If the proper path does not exist, it creates directories along the way
string data_netmail_file( string mud ) {
  string path;
 
  if( !mud || mud == "" ) 
          return 0;
 
  mud = lower_case( mud );
  path = NETMAIL_DIR + mud[ 0..0 ];
 
  if( !directory_exists( path ) )
    mkdirs( path );
 
  return path + "/" + mud;
}
 
/*
//
// File:    strip_backspace, a simul_efun.
// Author:  Inspiral@Tabor
// Created: 94-01-10
// Purpose: Strip the backspace and previous character from an incoming
//          string message.
//
*/
 
string strip_backspace( string str ) {
  mixed str_arr;
  int i;
 
  if( !stringp( str ) || !(i = strlen( str )) )
      return str;
 
  str_arr = allocate( i );
 
  while( i-- ) {
    if( i < 0 ) break;
    if( str[i] == '\b' ) {
       i--;
       continue;
    }
    str_arr[i] = str[i..i];
  }
 
  str_arr -= ({ 0 });
  str = implode( str_arr, "" );
  return str;
}
 

string user_mbox_file( string name ) {
  string path;

  if( !name || name == "" ) return 0;
  name = lower_case( name );
  path = MBOXDIR + name[ 0..0 ];

  if( !directory_exists( path ) )
    mkdirs( path );

  return path + "/" + name;
}


string mail_mesg_file( mixed date_id ) {
  string path;
  if( !date_id ) return 0;
  if( !(date_id = to_int( date_id )) ) return 0;
  date_id = date_id + "";
  path = MESGDIR + date_id[ <2..<2 ] + "/" + date_id[ <1..<1 ];
  if( !directory_exists( path ) )
    mkdirs( path );
  return path + "/" + date_id;
}

int last_char( string arg1, mixed arg2 ) {
  int tst;

  if( !strlen( arg1 ) ) return 0;
  tst = strlen( arg1 ) - 1;

  if( intp( arg2 ) )
      return (arg1[tst] == arg2);

  return (arg1[tst..tst] == arg2);
}
/* EOF */
