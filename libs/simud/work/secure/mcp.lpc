/*
 * Mud Control Protocol Stuff
 * http://www.moo.mud.org/mcp/mcp2.html
 */

// map of user objects -> mcp auth id's
mapping users = ([]);
// map of auth id's -> map of mcp state
mapping user_state = ([]);

int handle_mcp( string authkey, string *args );

void mcp_write( string authkey, string cmd, string msg) {
  string buf =
  buf = "#$#mcp-"+cmd+" "+authkey;
  if( strlen(msg) )
    buf += " "+msg;
  write( buf+"\n" );
  debug( ">> "+buf, "mcp" );
}

int on_mcp( string msg ) {
  string *args = explode(msg, " ");
  debug( "<< #$#mcp-"+msg, "mcp" );

  if( this_player() && !users[this_player()] ) {
   	debug( as_lpc(this_player()), "mcp" );
    if( args[0] == "authentication-key:" ) {
        string authkey = args[1];
		debug( "got auth key "+authkey, "mcp" );
    	users[this_player()] = authkey;
        user_state[authkey] = ([ "obj": this_player() ]);
        mcp_write( authkey, "negotiate-can", "mcp-negotiate min-version: 1.0 max-version: 2.0" );
		mcp_write( authkey, "negotiate-can", "dns-org-mud-moo-simpleedit min-version: 1.0 max_version: 1.0" );
	} else {
		debug( "got unexpected mcp message "+args[0]+", bad handshake", "mcp" );
		return 0;
	}
  } else {
    return handle_mcp( users[this_player()], args );
  }
}

int handle_mcp( string authkey, string *args ) {
  mapping user_map = user_state[authkey];
  // validate authkey
  if( authkey != args[1] ) {
    debug( "got invalid authkey "+args[1]+", expected "+authkey, "mcp" );
    return 0;
  }
  // handle command
  switch( args[0] ) {
    case "negotiate-can":
      if( user_state[authkey]["negotiate-end"] ) {
        debug( "already negotiated!", "mcp" );
        return 0;
      }
      debug( "got negotiate-can: "+args[3], "mcp" );
      break;
    case "negotiate-end":
      if( user_state[authkey]["negotiate-end"] ) {
        debug( "already negotiated!", "mcp" );
        return 0;
      }
      debug( "got end to mcp negotiation", "mcp" );
      user_state[authkey]["negotiate-end"] = 1;
      mcp_write( authkey, "negotiate-end", "" );
      break;
    default:
      debug( "got unrecognized mcp message "+args[0]+", ignoring", "mcp" );
      return 0;
  }
  return 1;
}

// switches a user's expected mcp object
void switch_user( object old, object new ) {
  debug( "switching "+as_lpc(old)+" -> "+as_lpc(new), "mcp" );
  string authkey = users[old];
  m_delete( users, old );
  users[new] = authkey;
  user_state[authkey]["obj"] = new;
  user_state[authkey]["switched"] = 1;
  debug( as_lpc(user_state[authkey]) );
}

// invalidate a user session and discard their settings
void invalidate_user( object obj ) {
  debug( "invalidating "+as_lpc(obj), "mcp" );
  string authkey = users[obj];
  debug( as_lpc(user_state[authkey]) );
  m_delete( user_state, authkey );
  m_delete( users, obj );
}
