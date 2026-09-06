/* -------------------------------------------------------------------------
 * DAEMONPATH channel_d.c -- The channel daemon
 *
 * Copyright (C) 1997, 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * -------------------------------------------------------------------------
 * the channels mapping format:
 * name : ({
 *  object * listeners,
 *  int flags,
 *  int type,
 *  mixed extra,
 *  mixed history,
 *  object creator
 * })
 *
 * TODO:  Guild/Assoc/Domain channels at RegisterChannel, RegisterUser
 * TODO:: object used as sender for msg_xx is wrong
 * TODO:: There is a problem with the chan-mapping, because everything
 * TODO:: inside is returned by reference and could me manipulated
 * TODO:: The handling of permanent channels and the initialization on
 * TODO:: load of the daemon is buggy. It should be aware of handling
 * TODO:: changes in permchan-datalength and much more...
 *
 * CHANGES
 *  06/28/98 [Mica] implemented features.h
 *  07/02/98 [Mica] Added QueryUserChannels(), implemented mastered channels
 *  07/03/98 [Mica] Interface to AddChannel() improved
 */

#include <secure/wizlevels.h>
#include <driver/object_info.h>
#include <driver/regexp.h>
#include <msgclass.h>
#include <channel.h>
#include <properties.h>
#include <macros.h>
#include <daemons.h>
#include <inetd.h>
#include <features.h>
#include <i3.h>

inherit "/obj/lib/daemon_data";

#define CHANNELD_LOG         "CHANNEL"                  /* log file name */
#define MAX_CHANNEL_HISTORY   40       /* max. number of history entries */

/* ------------------------------------------------------------------------
 * Global vars
 * ------------------------------------------------------------------------
 */

nosave mapping chan;                                      /* the channels */
mapping permchan;           /* the permanent channels, used to store only */
mapping banned;                              /* banned users for channels */
mapping ops;                                         /* channel operators */

/* -------------------------------------------------------------------------
 * Prototypes
 * -------------------------------------------------------------------------
 */

private int _check_mastered_channel( string name, object ob );

/* -------------------------------------------------------------------------
 * Query functions
 * -------------------------------------------------------------------------
 */

mapping QueryChannels() { return copy( chan||([]) ); }
string * QueryChannelNames() { return m_indices( chan||([]) ); }
mapping QueryBanned() { return copy( banned||([]) ); }
mapping QueryOps() { return copy( ops||([]) ); }

/* get the listeners on a channel
 */

object * ChannelListeners( string name ) {
  if ( ( ! chan ) || ( ! chan[name] ) )
    return 0;

  return (chan[name][CHANNEL_LISTENERS]||({}))+({});
}

/* get the channel data
 */

mixed * ChannelData( string name ) {
  if ( ( ! chan ) || ( ! chan[name] ) )
    return 0;

  return (chan[name]||({}))+({});
}

/* get the channels available for the given user object,
 * this_player() is used if the object is omitted
 */

private void filter_user_channels( string key, mixed data, object ob ) {
  data[CHANNEL_HISTORY]=0; /* we do not need that in return */
}

public varargs mapping QueryUserChannels( object ob ) {
  mapping res;
  string *ks;
  int i;

  if ( ! ob ) {
    if ( ! ( ob = this_player()) ) {
      return ([]);
    }
  }

  /* we do that stuff manually becayse walk_mapping has that reference-prob
   * (we dump CHANNEL_HISTORY here, don't need it)
   */

  if ( ! sizeof ( ks = m_indices( chan ) ) )
    return ([]);

  res = ([]);
  for( i = 0; i < sizeof( ks ); i++ ) {
    if ( ( chan[ks[i]][CHANNEL_FLAGS] & CHANNEL_FLAG_WIZ ) &&
         ( ! IS_IMMORTAL( ob ) ) )
      continue;
    else if ( ( chan[ks[i]][CHANNEL_FLAGS] & CHANNEL_FLAG_ADMIN ) &&
              ( ! IS_WIZARD( ob ) ) )
      continue;
    else if ( ( chan[ks[i]][CHANNEL_FLAGS] & CHANNEL_FLAG_HLP ) &&
              ( ! IS_HLP( ob ) ) )
      continue;
    else if ( ( chan[ks[i]][CHANNEL_FLAGS] & CHANNEL_FLAG_MASTERED ) &&
              ( ! _check_mastered_channel( ks[i], ob ) ) )
      continue;

    /* sorta partial real copy of the mapping values */
    res[ks[i]] = allocate( CHANNEL_MAX + 1 );
    res[ks[i]][CHANNEL_LISTENERS] = (chan[ks[i]][CHANNEL_LISTENERS]||({}))+({});
    res[ks[i]][CHANNEL_FLAGS] = chan[ks[i]][CHANNEL_FLAGS];
    res[ks[i]][CHANNEL_TYPE] = chan[ks[i]][CHANNEL_TYPE];
    res[ks[i]][CHANNEL_EXTRA] = chan[ks[i]][CHANNEL_EXTRA]; /* ! NO COPY */
    res[ks[i]][CHANNEL_HISTORY] = 0;
    res[ks[i]][CHANNEL_CREATOR] = chan[ks[i]][CHANNEL_CREATOR];
  }

  return res;
}



/* -------------------------------------------------------------------------
 * channel user handling
 * -------------------------------------------------------------------------
 */

/* add operator to channel
 */

int AddOp( string name, object ob ) {
  if ( ( ! chan ) || ( ! chan[name] ) )
    return 0;

  if ( ( ! this_player() ) || ( ! ({int})this_player()->QueryIsPlayer() ) )
    return 0; /* no ops without this_player being valid */

  if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_HLP ) &&
       ( ! IS_HLP( ob ) ) )
    return 0; /* no non-hlp ops on hlp-channels */

  /* the channel creator is allowed to do everything */
  if ( object_name(this_player()) != chan[name][CHANNEL_CREATOR] ) {
    if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_WIZ ) &&
	 ( ! IS_WIZARD( this_player() ) ) )
      return 0; /* only 'archs' can set an op for a wizard channel */
    else if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_ADMIN ) &&
	      ( !IS_WIZARD(this_player()) ) )
      return 0; /* only 'janitors' can set a op for an admin channel */
    else if ( ! IS_WIZARD( this_player() ) )
      return 0; /* only wizards may add ops */
  }

  if ( ! mappingp( ops ) )
    ops = ([ ]);

  if ( ! pointerp( ops[name] ) )
    ops[name] = ({ });

  ops[name] += ({ ({string})ob->Query( P_REALNAME ) });

  return 1;
}

/* add operator to channel
 */

int RemoveOp( string name, object ob ) {
  if ( ( ! chan ) || ( ! chan[name] ) )
    return 0;

  if ( ! IS_IMMORTAL( this_player() ))
    return 0; /* only wizards may add ops */

  if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_WIZ ) &&
       ( ! IS_WIZARD( this_player() ) ) )
    return 0; /* only 'archs' can set an op for a wizard channel */
  else if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_ADMIN ) &&
	    ( !IS_WIZARD(this_player()) ) )
    return 0; /* only 'janitors' can set a op for an admin channel */

  if ( ! mappingp( ops ) )
    return 0;

  if ( ! pointerp( ops[name] ) )
    return 0;

  if ( member( ops[name], ({string})ob->Query( P_REALNAME ) ) == -1 )
    return 0;

  ops[name] -= ({ ({string})ob->Query( P_REALNAME ) });
  if ( ! sizeof( ops[name] ) )
    m_delete( ops, name );
  if ( ! sizeof( ops ) )
    ops = 0;

  return 1;
}

/* check if object ob is op for channel name
 */

int IsOp( string name, object ob ) {
  if ( object_name( ob ) == chan[name][CHANNEL_CREATOR] )
    return 1; /* the creator is always op */

  if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_WIZ ) &&
	    ( IS_WIZARD( ob ) ) )
    return 1; /* 'archs' are always ops for wizard channels */
  else if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_ADMIN ) &&
	    ( IS_WIZARD(this_player())) )
    return 1; /* 'janitors' are always ops for admin channels */
  else if ( IS_WIZARD( ob ) )
    return 1; /* wizards are always ops for player/hlp channels */

  if ( ! mappingp( ops ) )
    return 0; /* no ops at all */

  if ( ! pointerp( ops[name] ) )
    return 0; /* no ops for that channel */

  if ( member( ops[name], ({string})ob->Query( P_REALNAME ) ) == -1 )
    return 0; /* ob is not op for that channel */

  return 1;
}

/* deny object ob to use the channel name till btime
 * if btime equals -1, the user is denied forever
 * if btime is omited, time()+3600 (i.e. one hour) is used
 */

varargs int DenyChannel( string name, object ob, int btime ) {
  if ( ( ! chan ) || ( ! chan[name] ) || ( ! objectp( ob ) ) )
    return 0; /* no such channel or invalid object */

  if ( ! IsOp( name, this_player() ) )
    return 0; /* illegal try */

  if ( ! query_once_interactive(ob) )
    return 0; /* no banning of npcs and daemons */

  if ( member( chan[name][CHANNEL_LISTENERS]||({}), ob ) == -1 )
    return 0;

  if ( ! btime )
    btime = time() + 3600; /* if no time given, ban for 60 minutes */

  if ( ! mappingp( banned ) )
    banned = ([]);

  if ( ! mappingp( banned[ob->Query(P_REALNAME)] ) )
    banned[ob->Query(P_REALNAME)] = ([ name : btime ]);
  else
    banned[ob->Query(P_REALNAME)][name] = btime;

  return 1;
}

/* permit object ob to use channel name again
 */

varargs int PermitChannel( string name, object ob ) {
  if ( ( ! chan ) || ( ! chan[name] ) || ( ! objectp( ob ) ) )
    return 0; /* no such channel or invalid object */

  if ( ! IsOp( name, this_player() ) )
    return 0; /* illegal try */

  if ( ! query_once_interactive(ob) )
    return 0; /* no unbanning of npcs and daemons */

  if ( ! mappingp( banned ) )
    return 0; /* nobody is banned currently */

  if ( ! mappingp( banned[ob->Query(P_REALNAME)] ) )
    return 0; /* user is not banned anywhere */

  if ( ! banned[ob->Query(P_REALNAME)][name] )
    return 0; /* user is not banned from that channel */

  m_delete( banned[ob->Query(P_REALNAME)], name );
  if ( ! sizeof( banned[ob->Query(P_REALNAME)] ))
    m_delete( banned, ({string})ob->Query(P_REALNAME) );
  if ( ! sizeof( banned ) )
    banned = 0;

  /* we do not connect the user to the channel, he/she might do that */

  return 1;
}

/* check if object ob is banned from channel name
 */

int IsBanned( string name, object ob ) {
  int btime;

  if ( ( ! chan ) || ( ! chan[name] ) || ( ! objectp( ob ) ) )
    return 0; /* no such channel or invalid object */

  if ( ! query_once_interactive(ob) )
    return 0; /* npcs and daemons are never banned */

  if ( ! mappingp( banned ) )
    return 0; /* nobody is banned currently */

  if ( ! mappingp( banned[ob->Query(P_REALNAME)] ) )
    return 0; /* user is not banned anywhere */

  if ( ! ( btime = banned[ob->Query(P_REALNAME)][name] ) )
    return 0; /* user is not banned from that channel */

  if ( ( btime > 0 ) && ( btime < time() ) ) {
    PermitChannel( name, ob ); /* ban time is over */
    return 0;
  }

  return 1;
}

/* unregister user/object ob from channel name
 */

void UnregisterChannel( string name, object ob ) {
  if ( ( ! chan ) || ( ! chan[name] ) )
    return;

  if ( ! chan[name][CHANNEL_LISTENERS] )
    return;

  if ( member( chan[name][CHANNEL_LISTENERS], ob ) == -1 )
    return;

  chan[name][CHANNEL_LISTENERS] -= ({ ob });
  chan[name][CHANNEL_LISTENERS] -= ({ 0 });

  if ( ! sizeof( chan[name][CHANNEL_LISTENERS] ) )
    chan[name][CHANNEL_LISTENERS] = 0;

#ifdef FEATURES_INTERMUD3
  /* the intermud-3 daemons needs to be notified about changes */
  if ( ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD3 ) &&
       ( object_name( ob ) != I3_TOOL("channel") ) )
    I3_TOOL("channel")->NotifyChannelChange( name, chan[name][CHANNEL_LISTENERS] );
#endif
}

/* unregister user/object from all channels
 */

void UnregisterUser( object ob ) {
  string * names;

  if ( ! chan )
    return;

  if ( ! objectp( ob ) )
    return;

  /* check if the objects provides a channel array, if not, use all */
  if ( ! call_resolved( & names, ob, "Query", P_CHANNELS ) )
    names = m_indices( chan );

  /* nothing to do */
  if ( ! names )
    return;

  filter( names, SF( UnregisterChannel ), ob );
}

/* register user/object ob on channel name
 * use testflag to test if the user might use the channel
 */

private int _check_mastered_channel( string name, object ob ) {
  object masterob;

  if ( ! stringp( chan[name][CHANNEL_CREATOR] ) )
    return 0; /* no master */

  if ( catch( masterob = load_object( chan[name][CHANNEL_CREATOR] ) ) )
    return 0; /* error loading master */

  /* for objects all clones of a certain blueprint are allowed */
  if ( ! ({int})masterob->QueryChannelPermission( name, ob ) )
    return 0; /* user/object not allowed */

  return 1;
}

varargs int RegisterChannel( string name, object ob, int testflag ) {
  string tmp;

  if ( ( ! chan ) || ( ! chan[name] ) )
    return 0;

  /* handling of mastered channels, same for all kinds of objects */
  if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_MASTERED ) &&
       ( ! _check_mastered_channel( name, ob ) ) )
    return 0;

  if ( query_once_interactive(ob) ) {
    /* do some checks for interactives */
    if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_RESTRICTED ) &&
	 ( ! IsOp( name, this_player() ) ) )
      return 0; /* for restricted channels only ops can add someone */

    if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_HLP ) &&
	 ( ! IS_HLP( ob ) ) )
      return 0;

    if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_WIZ ) &&
	 ( ! IS_IMMORTAL( ob ) ) )
      return 0;

    if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_ADMIN ) &&
	 ( ! IS_WIZARD( ob ) ) )
      return 0;
  }
  else {
    /* do some checks for intermud */
    tmp = object_name( ob );

    /* no intermud daemons on local channels */
    if ( ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_LOCAL ) &&
	 ( ( tmp == INET_D )
#ifdef FEATURES_INTERMUD3
           || ( tmp == I3_TOOL("channel") )
#endif
         ) )
      return 0;

#ifdef FEATURES_INTERMUD3
    /* no intermud-3 daemon on old intermud channels */
    if ( ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD ) &&
	 ( tmp = I3_TOOL("channel") ) )
      return 0;
#endif

    /* no old intermud daemon on intermud-3 channels */
    if ( ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD3 ) &&
	 ( tmp == INET_D ) )
      return 0;
  }

  if ( testflag )
    return 1;

  if ( ! chan[name][CHANNEL_LISTENERS] )
    chan[name][CHANNEL_LISTENERS] = ({ });

  if ( member( chan[name][CHANNEL_LISTENERS], ob ) == -1 )
    chan[name][CHANNEL_LISTENERS] += ({ ob });

#ifdef FEATURES_INTERMUD3
  /* the intermud-3 daemons needs to be notified about changes */
  if ( ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD3 ) &&
       ( object_name( ob ) != I3_TOOL("channel") ) )
    I3_TOOL("channel")->NotifyChannelChange( name, chan[name][CHANNEL_LISTENERS] );
#endif

  return 1;
}

/* register user/object on given channels
 * for interactive users names can be omited, P_CHANNELS is used then
 */

varargs void RegisterUser( object ob, mixed * names ) {
  if ( ! chan )
    return;

  /* don't register the login, it is interactive too .) */
  if ( blueprint( ob ) == "/secure/login" )
    return;

  if ( query_once_interactive(ob) && ! names )
    names = ({mixed *})ob->Query( P_CHANNELS );

  if ( ! names || ! sizeof( names ) )
    return;

  filter( names, SF( RegisterChannel ), ob );
}

/* ------------------------------------------------------------------------
 * Channel initialization
 * ------------------------------------------------------------------------
 */

/* initialize the channel from the permanent channels and add our users
 */

private void filter_add_permchan( string k, mixed * v ) {
  /* need to check for invalid mastered channels */
  if ( ( v[PERMCHANNEL_FLAGS] & CHANNEL_FLAG_MASTERED ) &&
       ( ! stringp( v[PERMCHANNEL_CREATOR] ) ) )
    return;

  chan[k] = allocate( CHANNEL_MAX + 1 );
  chan[k][CHANNEL_FLAGS] = v[PERMCHANNEL_FLAGS];
  chan[k][CHANNEL_TYPE]  = v[PERMCHANNEL_TYPE];
  chan[k][CHANNEL_EXTRA] = v[PERMCHANNEL_EXTRA];
  chan[k][CHANNEL_CREATOR] = v[PERMCHANNEL_CREATOR];
}

private varargs void initialize_chan( int flag ) {
  if ( chan && ( ! flag ) )
    return;

  chan = ([]);

  if( permchan ) {
    walk_mapping( permchan, SF( filter_add_permchan ) );
    permchan = 0; /* free mem */
  }

  /* load intermud daemons to ensure that they are there */
  INET_D->chan_startup();

#ifdef FEATURES_INTERMUD3
  if ( ({int})I3->query_state() == I3_CHANLIST_OK )
    //I3->chan_startup();
#endif

  filter( users(), SF( RegisterUser ) );
}

/* -------------------------------------------------------------------------
 * channel add/removal handling
 * -------------------------------------------------------------------------
 */

/* add a single channel
 */

private void filter_add_channel( object ob, string name ) {
  if ( member( ({string *})ob->Query(P_CHANNELS)||({}), name ) != -1 )
    RegisterChannel( name, ob );
}

int AddChannel( string name, mixed * data, object ob ) {
  string tmp;

  if ( ( ! objectp(ob) ) || ( ! stringp( name ) ) )
    return -1;

  if ( chan && chan[name] && ( chan[name][CHANNEL_CREATOR] != blueprint(ob) ) )
    return -1; /* invalid call */

  if ( ! chan[name] )
    chan[name] = allocate( CHANNEL_MAX + 1 );

  if ( data && pointerp( data ) && sizeof( data ) ) {
    if ( sizeof( data) >= ( CHANNEL_LISTENERS + 1 ) ) {
      if ( objectp( data[CHANNEL_LISTENERS] ) )
	chan[name][CHANNEL_LISTENERS] = ({ data[CHANNEL_LISTENERS] });
      else if ( pointerp( data[CHANNEL_LISTENERS] ) )
	chan[name][CHANNEL_LISTENERS] = data[CHANNEL_LISTENERS];
    }
    if ( sizeof( data) >= ( CHANNEL_FLAGS + 1 ) )
      chan[name][CHANNEL_FLAGS] = data[CHANNEL_FLAGS];
    if ( sizeof( data) >= ( CHANNEL_TYPE + 1 ) )
      chan[name][CHANNEL_TYPE] = data[CHANNEL_TYPE];
    if ( sizeof( data) >= ( CHANNEL_EXTRA + 1 ) )
      chan[name][CHANNEL_EXTRA] = data[CHANNEL_EXTRA];
  } else if ( ( data ) && ( intp( data ) ) ) {
    chan[name][CHANNEL_FLAGS] = data;
  } else if ( ( data ) && ( mappingp( data ) ) ) {
    if ( objectp( data[CHANNEL_LISTENERS] ) )
      chan[name][CHANNEL_LISTENERS] = ({ data[CHANNEL_LISTENERS] });
    else if ( pointerp( data[CHANNEL_LISTENERS] ) )
      chan[name][CHANNEL_LISTENERS] = data[CHANNEL_LISTENERS];
    if ( data[CHANNEL_FLAGS] )
      chan[name][CHANNEL_FLAGS] = data[CHANNEL_FLAGS];
    if ( data[CHANNEL_TYPE] )
      chan[name][CHANNEL_TYPE] = data[CHANNEL_TYPE];
    if ( data[CHANNEL_EXTRA] )
      chan[name][CHANNEL_EXTRA] = data[CHANNEL_EXTRA];
  }

  tmp = object_name( ob );
  if ( tmp == INET_D )
    chan[name][CHANNEL_TYPE] = CHANNEL_TYPE_IMUD;
#ifdef FEATURES_INTERMUD3
  else if ( tmp == I3_TOOL("channel") )
    chan[name][CHANNEL_TYPE] = CHANNEL_TYPE_IMUD3;
#endif
  else
    chan[name][CHANNEL_TYPE] = CHANNEL_TYPE_LOCAL;

  /* mastered channels are always permanent, permission checks are next
   */
  if ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_MASTERED )
    chan[name][CHANNEL_FLAGS] |= CHANNEL_FLAG_PERMANENT;

  /* it is impossible to create permanent channels with AddChannel for
   * interactive object, because they'd gain permanent control. Standard
   * channels must not be added by AddChannel() permanent, that's what
   * the permchan-list later in the file is for. This is just for guild,
   * assoc or clan channels. In addition no clone is allowed to create those.
   */
  if ( ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_PERMANENT ) &&
       ( interactive( ob ) || is_clone( ob ) ) )
    return -1;

  /* we store the creators filename to allow player creators to quit
   * and relogin without loosing creator access */
  chan[name][CHANNEL_CREATOR] = blueprint( ob );

  /* add users to channel */
  filter( users(), SF( filter_add_channel ), name );

  if ( ! pointerp( chan[name][CHANNEL_LISTENERS] ) )
    return 0; /* nobody on yet */

  return sizeof( chan[name][CHANNEL_LISTENERS] ); /* listeners incl. ob */
}

/* add a bunch of channel names
 * names can be either an array of names or a mapping with name : data
 */

void AddChannels( mixed names, object ob ) {
  if ( ( ! names ) || ( ! sizeof( names ) ) )
    return;

  if ( pointerp( names ) )
    filter( names, SF( AddChannel ), 0, ob );
  else
    walk_mapping( names, SF(AddChannel), ob );
}

/* remove a single channel
 */

void RemoveChannel( string name, object ob ) {
  string tmp;

  if ( ( ! chan ) || ( ! chan[name] )  )
    return;

  tmp = object_name( ob );

  if ( chan[name][CHANNEL_CREATOR] != tmp )
    return;  /* invalid call */

  if ( chan[name][CHANNEL_FLAGS] & CHANNEL_FLAG_PERMANENT )
    return; /* impossible to remove permanent channels */

  if ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_LOCAL ) {
    if ( ( tmp == INET_D )
#ifdef FEATURES_INTERMUD3
         || ( tmp == I3_TOOL("channel") )
#endif
       )
      return;
  }
  else if ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD ) {
    if ( tmp != INET_D )
      return;
  }
  else if ( chan[name][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD3 ) {
    if ( tmp != I3_TOOL("channel") )
      return;
  }

  m_delete( chan, name );
}

/* remove a bunch of channels
 */

void RemoveChannels( mixed names, object ob ) {
  if ( ( ! names ) || ( ! sizeof( names ) ) )
    return;

  if ( pointerp( names ) )
    filter( names, SF( RemoveChannel ), ob );
  else
    filter( m_indices( names ), SF( AddChannel ), ob );
}

/* -------------------------------------------------------------------------
 * channel history
 * -------------------------------------------------------------------------
 */

varargs int SendChannelHistory( string name, object ob, int num ) {
  if ( ( ! name ) || ( ! ob ) )
    return 0; /* invalid call */

  if ( ( ! chan ) || ( ! chan[name] ))
    return 0; /* invalid channel */

  if ( ! pointerp( chan[name][CHANNEL_HISTORY] ) ) {
    msg_object( ob, CMSG_GENERIC, "No messages in history buffer for channel \""+name+"\".\n" );
    return 1;
  }

  if ( ( num >= sizeof( chan[name][CHANNEL_HISTORY] ) ) || ( num <= 0 ) )
    num = 0;
  else
    num = sizeof( chan[name][CHANNEL_HISTORY] ) - num;

  msg_object( ob, CMSG_GENERIC|MMSG_MORE,
	      "--- History for channel \""+name+"\".\n" );

  for( ;num < sizeof( chan[name][CHANNEL_HISTORY] ); num++ ) {
    msg_object( ob, CMSG_CHANNEL|MMSG_MORE,
		({ name }) + chan[name][CHANNEL_HISTORY][num] );
  }

  msg_object( ob, CMSG_GENERIC|MMSG_MORE,
	      "--- End of history.\n" );

  return 1;
}

/* -------------------------------------------------------------------------
 * channel usage
 * -------------------------------------------------------------------------
 */

private void SendChannelOldInet(string ch, string msg, string wh,
                                int is_emote) {
  mapping data, hosts;
  string *muds;
  int i;

  data = ([
	   I2H_REQUEST: "channel",
	   I2H_SENDER: wh,
	   I2H_CHANNEL: ch,
	   "CHANNEL": ch, /* argl, backward compat hack - Pepel */
	   I2H_DATA: msg
    ]);

  if (is_emote)
    data[I2H_COMMAND] = "emote";

  for(i = sizeof(muds = m_indices(hosts = ({mapping})INET_D->query(I2RQ_HOSTS))); i--; ) {
    /*
     * Don't send it to ourselves and check that the receiver
     * recognizes "channel" requests. Normally this checking is done
     * by the inetd, but we don't want it throwing out
     * 'invalid command' messages for muds that don't use channels
     * every time we send an intermud message.
     */

    if ( ( lower_case(muds[i]) != lower_case(LOCAL_NAME) ) &&
	 ( ( member(hosts[muds[i]][I2D_HOST_COMMANDS], "*") != -1 ) ||
	   ( member(hosts[muds[i]][I2D_HOST_COMMANDS], "channel") != -1)))
      INET_D->send_udp(muds[i], data);
  }
}

private varargs void SendChannel( object sender, string channel, string name,
				  string msg, int override, int emote ) {
  object * u;
  int i;
  string *reg_chan = ({});

  if ( ( ( ! chan ) || ( ! chan[channel] ) )
      && sizeof(reg_chan = regexp(m_indices(chan), "(?i)^"+channel+"$", RE_PCRE) ) < 1 ) {
    if ( interactive( sender ) )
      msg_object( sender, CMSG_GENERIC, "Unknown channel \""+channel+"\".\n" );
    else
      log_file( CHANNELD_LOG, ctime()+" ["+object_name(sender)+"] attemped to use not existing channel \""+channel+"\".\n" );

    return;
  }

  if (sizeof(reg_chan))
    channel = reg_chan[0];
  u = (chan[channel][CHANNEL_LISTENERS]||({})) - ({ 0 });

  /* override flag for access checking
   * TODO: override might be secured somehow
   */
  if ( ! override ) {
    /* this does the access check, who is not able to register, is not
     * allowed to send.
     */

    if ( member( u, sender ) == -1 ) {
      if ( interactive( sender ) ) {
	/* test if sender might use it */
	if ( RegisterChannel( channel, sender, 1 ) )
	  msg_object( sender, CMSG_GENERIC, "You are not active on channel \""+channel+"\".\n" );
	else
	  msg_object( sender, CMSG_GENERIC, "Unknown channel \""+channel+"\".\n" );
      }
      else
	log_file( CHANNELD_LOG, ctime()+" ["+object_name(sender)+"] attemped to use channel \""+channel+"\" without beeing member or override-flag set.\n" );

      return;
    }

    /* read-only channels
     */

    if ( chan[channel][CHANNEL_FLAGS] & CHANNEL_FLAG_READONLY ) {
      if ( interactive( sender ) )
	msg_object( sender, CMSG_GENERIC, "Channel \""+channel+"\" is read-only.\n" );
      else
	log_file( CHANNELD_LOG, ctime()+" ["+object_name(sender)+"] attemped to use read-only channel \""+channel+"\" without override-flag set.\n" );

      return;
    }

    if ( IsBanned( channel, sender ) ) {
      msg_object( sender, CMSG_GENERIC, "You are banned from channel \""+channel+"\".\n" );
      return;
    }
  }

  if ( ! sizeof( u ) )
    return; /* all checking is done, now we can return if there are no lis. */

  /* anononymous channels */
  if ( chan[channel][CHANNEL_FLAGS] & CHANNEL_FLAG_ANONYMOUS ) {
    if ( emote )
      name = "Someone";
    else
      name = "";
  }

  /* init channel history if not already done */
  if ( ! pointerp( chan[channel][CHANNEL_HISTORY]) )
    chan[channel][CHANNEL_HISTORY] = ({});

  /* remove first entry if max. reached */
  if ( sizeof( chan[channel][CHANNEL_HISTORY] ) >= MAX_CHANNEL_HISTORY )
    chan[channel][CHANNEL_HISTORY] = chan[channel][CHANNEL_HISTORY][1..];

  /* add current message at the end */
  chan[channel][CHANNEL_HISTORY] += ({ ({ name, msg, emote }) });

  /* actual delivery */
  for( i = 0; i < sizeof( u ); i ++ ) {
    if ( ! objectp( u[i] ) )
      continue; /* might happen */

    if ( interactive( u[i] ) ) {
      /* ignore checking for interactives */
      if ( ( interactive( sender ) ) &&
	   ( ({int})u[i]->check_ignore( "channel", sender ) <= 0 ) )
      continue;

      /* check for global channel off */
      if ( ({int})u[i]->Query(P_CHANNELS_ON) )
	msg_object( u[i], CMSG_CHANNEL,
		    ({ channel, name, msg, emote }) );
    }
    else if ( object_name( u[i] ) == INET_D ) {
      if ( chan[channel][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD ) {
	/* old intermud daemon */

	if ( sender == u[i] )
	  continue; /* don't send them back */

	SendChannelOldInet( channel, msg, name, emote );
      }
    }
#ifdef FEATURES_INTERMUD3
    else if ( object_name( u[i] ) == I3_TOOL("channel") ) {
      if ( chan[channel][CHANNEL_TYPE] == CHANNEL_TYPE_IMUD3 ) {
	/* intermud-3 daemon */

	if ( sender == u[i] )
	  continue; /* don't send them back */

	I3_TOOL("channel")->channel_rcv_data( channel, name, emote?"emote":"tell", msg );
      }
    }
#endif
    else { /* npcs and stuff */
      msg_object( u[i], CMSG_CHANNEL,
		  ({ channel, name, msg, emote }) );
    }
  }
}

varargs void SendEmote( string channel, string name,
			string msg, int override ) {
  if ( channel && name && ( ! msg ) ) {
    SendChannel( this_object(), "error", object_name( previous_object() ),
		 "used outdated call to CHANNEL_D->SendEmote() (paramter missing)", 1, 1 );
    log_file( CHANNELD_LOG, ctime()+" ["+object_name(previous_object())+"] used outdated call to SendEmote() for channel \""+channel+"\".\n" );
  }
  else {
    if ( ( ! channel ) || ( ! name ) || ( ! msg ) )
      return;

    SendChannel( this_player()||previous_object(),
		 channel, name, msg, override, 1 );
  }
}

varargs void SendStr( string channel, string msg, int override ) {
  if ( ( ! channel ) || ( ! msg ) )
    return;

  SendChannel( this_player()||previous_object(),
               channel, "", msg, override, 0 );
}

varargs void SendTell( string channel, string name,
		       string msg, int override ) {
  if ( ( ! channel ) || ( ! name ) || ( ! msg ) )
    return;

  SendChannel( this_player()||previous_object(),
	       channel, name, msg, override, 0 );
}

void SendMsg( string channel, string msg ) {
  SendChannel( this_object(), "error", object_name( previous_object() ),
	       "used CHANNEL_D->SendMsg()", 1, 1 );
  log_file( CHANNELD_LOG, ctime()+" ["+object_name(previous_object())+"] used outdated call SendMsg() for channel \""+channel+"\".\n" );
}

/* called by inetd/udp/channel upon reception of a intermud msg */
void send_local_message( mapping data ) {
  SendChannel( previous_object(), data[I2H_CHANNEL],
	       capitalize(data[I2H_SENDER])+"@"+data[I2H_NAME],
	       data[I2H_DATA], 0, (data[I2H_COMMAND]=="emote")?1:0 );
}

/* -------------------------------------------------------------------------
 * permanent channel handling
 * -------------------------------------------------------------------------
 */

/* initialize the permanent channels
 */

private void initialize_permchan() {
  permchan =
    ([
      /* the player channels */
      "players" : ({ CHANNEL_FLAG_PERMANENT,
		     CHANNEL_TYPE_LOCAL,
		     0, object_name( this_object() ) }),
      "hlp" : ({ CHANNEL_FLAG_HLP|CHANNEL_FLAG_PERMANENT,
		 CHANNEL_TYPE_LOCAL,
		 0, object_name( this_object() ) }),
      "sex" : ({ CHANNEL_FLAG_PERMANENT|CHANNEL_FLAG_ANONYMOUS,
		 CHANNEL_TYPE_LOCAL,
		 0, object_name( this_object() ) }),
      "newbie" : ({ CHANNEL_FLAG_PERMANENT,
		    CHANNEL_TYPE_LOCAL,
		    0, object_name( this_object() ) }),
      "help" : ({ CHANNEL_FLAG_PERMANENT,
		  CHANNEL_TYPE_LOCAL,
		  0, object_name( this_object() ) }),
      /* the wizard channels */
      "general" : ({ CHANNEL_FLAG_WIZ|CHANNEL_FLAG_PERMANENT,
		     CHANNEL_TYPE_LOCAL,
		     0, object_name( this_object() ) }),
      "lpc" : ({ CHANNEL_FLAG_WIZ|CHANNEL_FLAG_PERMANENT,
		 CHANNEL_TYPE_LOCAL,
		 0, object_name( this_object() ) }),
      /* system channels */
      "news" : ({ CHANNEL_FLAG_READONLY|CHANNEL_FLAG_PERMANENT,
		  CHANNEL_TYPE_LOCAL,
		  0, object_name( this_object() ) }),
      "title" : ({ CHANNEL_FLAG_READONLY|CHANNEL_FLAG_PERMANENT,
		   CHANNEL_TYPE_LOCAL,
		   0, object_name( this_object() ) }),
      "error" : ({ CHANNEL_FLAG_READONLY|CHANNEL_FLAG_PERMANENT|CHANNEL_FLAG_WIZ,
		   CHANNEL_TYPE_LOCAL,
		   0, object_name( this_object() ) }),
      "info" : ({ CHANNEL_FLAG_READONLY|CHANNEL_FLAG_PERMANENT|CHANNEL_FLAG_WIZ,
		   CHANNEL_TYPE_LOCAL,
		   0, object_name( this_object() ) }),
      ]);
}

/* update the permanent channels
 */

private void filter_update_permchan( string k, mixed * v ) {
  if ( v[CHANNEL_FLAGS] & CHANNEL_FLAG_PERMANENT ) {
    permchan[k] = allocate( PERMCHANNEL_MAX + 1 );
    permchan[k][PERMCHANNEL_FLAGS] = v[CHANNEL_FLAGS];
    permchan[k][PERMCHANNEL_TYPE] = v[CHANNEL_TYPE];
    permchan[k][PERMCHANNEL_EXTRA] = v[CHANNEL_EXTRA];
    permchan[k][PERMCHANNEL_CREATOR] = v[CHANNEL_CREATOR];
  }
}

varargs void update_permchan( int flag ) {
  if ( ! sizeof( chan ) || flag ) {
    initialize_permchan();
    initialize_chan( 1 );
  }

  permchan = ([]);
  walk_mapping( chan, SF( filter_update_permchan ) );
  save_me();
}

/* -------------------------------------------------------------------------
 * create/remove/clean_up
 * -------------------------------------------------------------------------
 */

void create() {
  if ( clonep() ) {
    destruct( this_object() );
    return;
  }

  seteuid( getuid() );

  /* load our permanent channels */
  daemon_data::create();

  /* if needed, init our permanent channels */
  if ( ! sizeof( permchan ) )
    initialize_permchan();

  initialize_chan();
}

int remove( int flag ) {
  update_permchan();
  destruct( this_object() );
  return this_object() && 1;
}

int clean_up( int refcount ) {
  return 1; /* we never cleanup */
}

/* ********************************************************************** */
