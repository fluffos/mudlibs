#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xse"; }

int main( string str ) {
  int i;
  mixed obj;
  string name, tmp, * keys;

  notify_fail( "xse(t) [$<name>=[<object>]]\n");
  if ( str == "?" )
    return 0;

  if ( str ) {
    if(sscanf(str, "$%s=%s", name, tmp)) {
      if ( member( ({ "m", "me", "h", "here" }), name ) != -1 ) {
	tell_object( cloner, "Sorry, this is a reserved variable [$"+name+"].\n");
	return 1;
      }
      if ( ( ! tmp ) || ( tmp == "" ) ) { 
	RemoveXVariable( name, 0 );
	tell_object( cloner, " $"+name+" has been removed.\n" );
      }
      else if(obj=XFindObj(tmp)) {
	AddXVariable( name, obj, 0 );
	tell_object( cloner, " $"+name+"="+ObjFile(obj)+"\n");
      }
    } 
    else 
      return 0;
  } else {
    CheckXVariables( 0, 0 );
    tell_object( cloner, "Current settings:\n" );
    if ( mappingp( xvariables ) && ( sizeof( xvariables ) ) ) {
      keys = m_indices( xvariables );
      for( i=0; i < sizeof( keys ); i++ ) {
	if ( xvariables[keys[i]] ) /*paranoia check, as this is done by Check*/
	  tell_object(cloner," $"+keys[i]+"="+ObjFile(xvariables[keys[i]])+"\n" );
      }
    }
    tell_object( cloner, " $me="+ObjFile(cloner)+"\n");
    tell_object( cloner, " $here="+ObjFile(environment(cloner))+"\n");
  }
  return 1;
}




