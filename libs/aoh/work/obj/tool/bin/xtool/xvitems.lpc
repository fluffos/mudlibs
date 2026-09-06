#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICXCMD;

Query( string arg ) { if ( arg == "IsTool" ) return 1; else return 0; }

mapping plist;

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

void dump_vitems( string data, int indent, mapping vitems ) {
  mixed * index2;
  mixed index;
  mapping props;
  int i, n;

  index = sort_array( m_indices( vitems ), SF(>) );

  for( n = 0; n < sizeof( index ); n ++ ) {
    props = vitems[index[n]];
    index2 = sort_array( m_indices( props ), SF(>) );
    data += sprintf( "%-*' 'sVITEM ID \"%s\":\n",
                     indent, "", index[n] );

    for (i = 0; i < sizeof(index2); i++) {
      if ( index2[i] == P_VITEMS ) {
        data += 
          sprintf( "%-*' 's  %-25'.'s\n",
                  indent, "",
                  ( plist[index2[i]] ?
                    plist[index2[i]] :
                    index2[i] ) + " " ); 

        dump_vitems( & data, indent + 4, props[index2[i]] );
      }
      else
        data += 
          sprintf("%-*' 's  %-25'.'s ",
                  indent, "",
                  ( plist[index2[i]] ?
                    plist[index2[i]] :
                    index2[i] ) + " " ) + 
          ("/lib/string"->mixed_to_string(props[index2[i]], 6)) + 
          "\n";
    }
  }
}

int DumpVItems( string str ) {
  string data, * index2;
  object env, v_id;
  mapping dat;

  if ( ! env = environment( this_player() ) )
    return 0;
  
  plist = _get_props( PROPERTY_HEADER );
  plist += _get_props( "/sys/vitems.h" );
  data = "";

  if ( str ) {
    if ( ! v_id = env->GetVItem( str, 2 ) )
      return 0;
    if ( ! dat = env->GetVItemData( v_id ) )
      return 0;
    dump_vitems( & data, 0, ([ v_id : dat ]) );
  }
  else 
    dump_vitems( & data, 0, env->Query( P_VITEMS ) );
  
  msg_write( CMSG_GENERIC|MMSG_MORE, data );
  return 1;
}

int main(string str ) {
  int i, s;
  object obj;

  if ( str == "?" ) 
    return notify_fail( "xvitems\n" ), 0;

  if ( ! DumpVItems( str ) )
    return notify_fail( "No (matching) vitems found.\n" ), 0;
  
  return 1;
}




