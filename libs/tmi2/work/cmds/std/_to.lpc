/*
// File:	_to.c
// Mudlib:	TMI-II
// Author:	Pallando
// Real Name:	Douglas Reay
// Date V1.0:	1992 December 20
*/

#define TMP_FILE "/tmp/" + name + ".to"

#include <mudlib.h>

inherit DAEMON;

mapping strs = ([]);

int cmd_to( string a )
{
  string name;

  name = geteuid( this_player() );
  a = ( a ? (a + " ") : "" );
  strs[name] = a;
  write( "Input rest of command: " + a + "...\n" );
  this_player()-> edit( TMP_FILE, "done", this_object() );
  return 1;
}

mixed done()
{
  string str, name, text;

  name = geteuid( this_player() );
  text = read_file( TMP_FILE );
  if( !text ) text = "";
  else text = text[0..(strlen(text)-2)]; // gets rid of a duplicate \n
  rm( TMP_FILE );
  str = strs[name];
  map_delete( strs, name );
  return this_player()-> force_me( str + text );
}

int help()
{
  write( ""+
    "Syntax: to <string>\n"+
    "Effect: Lets you input text lines then forces you to do \"<string> <text>\"\n"+
    "" );
  return 1;
}
