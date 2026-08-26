/* The resolver, most likely made by Inspiral@Tmi-2
 * Leto added check to see if addr_server is running 12/7/95
 */

#include <mudlib.h>
inherit DAEMON;

#define USAGE "Syntax: resolve <address>\n"

mapping pending;

void create() { pending = ([ ]); }

int cmd_resolve( string address ) {
  int key;

  if( !address || address == "" )
	return notify_fail( "RESOLVE: " + USAGE );

  key = resolve( address, "resolve_callback" );

  if(!key) 
  message("error","Addr_server is not running, resolve failed.\n",this_player() );
else {
  pending += ([ key : this_player() ]);
 message("network", "Resolve: " + key + "\t"+ identify(this_player()) +
 "\n", this_player() );
}
  return 1;
}

void resolve_callback( string address, string resolved, int key ) {
  if(!key) return;
  message( "network", 
   sprintf( "Address: %s, Resolved: %s, Key: %d\n", address,
	resolved, key ), pending[key] );
}

string help() {

return @HelpText
Usage:   resolve <address>

This command will allow for name/address resolution.  Good luck.
HelpText;
}
