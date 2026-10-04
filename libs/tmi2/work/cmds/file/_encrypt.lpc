/*
// File:	/cmds/file/_encrypt.c
// V1.0:	93-04-08
// Author:	Pallando (Douglas Reay)
// Mudlib:	TMI
*/
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: encrypt [-d ]<file> <key>\n"
#define LOW 33
#define HIGH 126
// Would use 0 - 255 but read_file() reads ctrl's as spaces. 8-(

protected void do_encrypt( mixed a );
protected void save_file( mixed a );

int cmd_encrypt( mixed a )
{
  string oldfile, filename, key, euid, del;
  object player;
  mixed tmp;
  int j, sj;

  player = this_player();
  euid = geteuid( previous_object() );
  seteuid( euid );
  if( a && sscanf( a, "-d %s", del ) ) a = del;
  if( !a || sscanf( a, "%s %s", filename, key ) < 2 )
  {
    notify_fail( SYNTAX );
    return 0;
  }
  filename = resolv_path( "cwd", filename );
  if( file_size( filename ) < 0 ) 
  {
    notify_fail( filename + " is not a file.\n" );
    return 0;
  }
  oldfile = read_file( filename );
  if( !oldfile )
  {
    notify_fail( filename + " is empty.\n" );
    return 0;
  }
  sj = strlen( key );
  tmp = ({ });
  for( j = 0 ; j < sj ; j++ )
    tmp += ({ key[j] - 97 });
  tmp += ({ 3, 4, 2, 17, 24, 15, 19 });
  a = ({ oldfile, "", tmp, 0, strlen( oldfile ), filename, euid, player, del });
//    ({ oldfile, newfile, key, i, s,            filename, euid, player, del })
  write( "Encryption started... ("+a[4]+" lines)\n" );
  do_encrypt( a );
  return 1;
}

protected void do_encrypt( mixed a )
{
  int i, s, k, *key;
  string newfile, oldfile;

  oldfile = a[0]; newfile = a[1]; key = a[2]; i = a[3];

  s = i + 1000;
  if( s > a[4] ) s = a[4];
  for( ; i < s ; i++ )
  {
    k = oldfile[i];
    if( ( k < LOW ) || ( k > HIGH ) )
    {
      newfile += oldfile[i..i];
    } else {
      k += key[(i - 3*(i/3) )];
      k += key[(i - 7*(i/7) )];
      if( k > HIGH ) k += (LOW - HIGH);
      newfile += sprintf( "%c", k );
    }
  }
  a[1] = newfile;
  a[3] = i;
  if( s == a[4] ) save_file( a );
  else {
    call_out( "do_encrypt", 1, a );
    if( a[7] ) tell_object( a[7], i + "...\n" );
  }
}

protected void save_file( mixed a )
{
  string newfile, filename, euid, del;
  object player;

  newfile = a[1]; filename = a[5]; euid = a[6]; player = a[7]; del = a[8];

  seteuid( euid );
  if( del ) rm( filename );
  filename += ".x";
  rm( filename );
  write_file( filename, newfile );
  if( player ) tell_object( player,
    "Encrypted version written to " + filename + "\n" );
}

string help()
{
  return( SYNTAX +
    "Effect: encrypts file <file> to <file>.x\n"+
    "        <key> is the password you must use to decrypt it.\n"+
    "        If -d is specified, <file> is deleted.\n"+
    "Characters are encrypted at a rate of 1000 per second.\n"+
  "" );
}
