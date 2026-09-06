#include <const.h>
#include <wizard.h>

int main( string param ) {
  string from, to;
  object ob, inv, env;
  int nok = 0, nfail = 0;

  WIZ_CHECK

  if( !param ) {
     notify_fail("==> [Format] wempty object [[in]to object]\n");
     return 0;
  }
  if ( (sscanf( param, "%s into %s", from, to ) < 2) &&
       (sscanf( param, "%s to %s", from, to) < 2) ) {
    from = param;
  }
  if( !from ) {
     notify_fail("==> [Format] wempty object [[in]to object]\n");
     return 0;
  }
  ob = find_thing( from );
  if( !ob ) {
     notify_fail("I don't understand what you are trying to empty.\n");
     return 0;
  }

  env = find_thing( to );
  if (!env) {
    if ( !ob || !(env = environment(ob))) {
      env = find_thing("/obj/void");
    }
  }

  foreach( inv : all_inventory(ob) ) {
    inv->move( env );
    if( !inv || environment(inv) == env )
      nok++;
    else
      nfail++;
    if( !inv ) continue;
    inv->set_x( this_player()->query_x() );
    inv->set_y( this_player()->query_y() );
  }
  if( nfail )

    msg( "" + nok + " object(s) moved successfully to  " + as_string(env) + ", " + nfail + " did not move.\n");
  else
    msg( "" + nok + " object(s) moved successfully to " + as_string(env) );
  return 1;
}