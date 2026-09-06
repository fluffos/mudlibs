#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICXCMD;

QueryAbrev() { return "xprop"; }

Query( string arg ) { if ( arg == "IsTool" ) return 1; else return 0; }

private mapping _get_props( string name ) {
  mixed raw;
  mapping pdata;
  int i;
  string alias, property;

  pdata = ([]);

  raw = read_file( name );
  if ( ! raw )
    return pdata;
  raw = explode( raw, "\n" );
  /* don't check for comments :-) */
  for (i = sizeof( raw) - 1; i >= 0; i--) {
    if (sscanf(raw[i],"#define %s %~s\"%s\"",alias,property) == 3) 
      pdata[property] = alias;
  }

  return pdata;
}

void DumpProperties(object obj) {
  string data;
  mapping props;
  mapping plist;
  string * index;
  int i;

  if(!obj) return;

  plist = _get_props( PROPERTY_HEADER );
  props = obj->QueryProperties();
  index = sort_array( m_indices( props ), SF(>) );
  data = "";

  for (i = 0; i < sizeof(index); i++)
    data += 
      sprintf("%-25'.'s ",
              ( plist[index[i]] ?
              plist[index[i]] :
              index[i] ) + " " ) + 
      ("/lib/string"->mixed_to_string(props[index[i]], 6)) + 
      "\n";
  
  msg_write( CMSG_GENERIC|MMSG_MORE, data );
}

int main(string str ) {
  int i, s;
  object obj;

  if ( ( ! str ) || ( str == "?" ) ) 
    return notify_fail( "xprop(s) <object>\n" ), 0;

  if ( obj = XFindObj(str) )
    DumpProperties(obj);
  return 1;
}




