/*--------------------------------------------------------------------------
 * DAEMONPATH inetd.c -- The intermud protocol handler
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * Originally written by Nostradamus@Zebedee
 * Developed from an original concept by Alvin@Sushi
 *--------------------------------------------------------------------------
 */

#pragma no_range_check

#include <driver/driver_info.h>
#include <inetd.h>
#include <daemons.h>
#include <channel.h>
#include <properties.h>
#include <macros.h>

/* define this to log invalid packete
 * TODO:  find the reason why something constantly sends data to the udp
 * TODO:: port which is invalid, define LOG_INVALID to see if it still
 * TODO:: takes place.
 */
#define LOG_INVALID

/*--------------------------------------------------------------------------
 * Configuration defines
 *--------------------------------------------------------------------------
 */

/* Public commands which will be accessible to any unlisted muds.
 * I2R_PING, I2R_QUERY and I2R_REPLY are included by default.
 */

#define COMMANDS ({ I2R_CHANNEL, I2R_FINGER, I2R_TELL, I2R_WHO, I2R_MAIL, I2R_LOCATE })

/* The maximum number of characters we can send in one packet.
 * You may need to reduce this, but 512 should be safe.
 */

#define MAX_PACKET_LEN	1024

/* Defines the name of the wizard who should receive debug messages
 */

#define DEBUG(msg)	dtell("nostradamus", msg )

/* Do not alter any defines below!
 */

#define USE_OLD_DELIMITER
#define DELIMITER_COMPAT
#define USE_OLD_DATA_FORMAT

#ifndef DATE
#define DATE		ctime(time())[4..15]
#endif

#define UNKNOWN		0
#define UP		time()
#define DOWN		(-time())

#define NEW_DELIMITER	"\n"
#ifdef USE_OLD_DELIMITER
#define DELIMITER	"|"
#else
#define DELIMITER	"\n"
#endif
#define OLD_DELIMITER	"|"
#define HOSTFILE_DEL	":"
#define HOSTFILE_DEL2	","


/*--------------------------------------------------------------------------
 * Global variables
 *--------------------------------------------------------------------------
 */

private mapping hosts, pending_data, incoming_packets;
private string *received_ids;
private int packet_id;
nosave mapping intermud_channels;

/*--------------------------------------------------------------------------
 * Prototypes
 *--------------------------------------------------------------------------
 */

void set_host_list();
void startup();
varargs string send_packet(string mudname, mapping data, int expect_reply);

/* ------------------------------------------------------------------------
 * Channel moved here
 * ------------------------------------------------------------------------
 */

void udp_channel(mapping data)
{
  mapping reply;
  object *list;
  string msg;
  int i;

  /* Compatability with older systems. */
  if (!data[I2H_CHANNEL])
    data[I2H_CHANNEL] = data["CHANNEL"];
  if (!data[I2H_COMMAND])
    data[I2H_COMMAND] = data["CMD"];

  reply = ([
      I2H_REQUEST: I2R_REPLY,
      I2H_ID: data[I2H_ID]
  ]);
  switch(data[I2H_COMMAND])
  {
    case I2C_LIST:
      reply[I2H_RECIPIENT] = data[I2H_SENDER];

      if ( member( m_indices( intermud_channels ),
        lower_case(data[I2H_CHANNEL]||"") ) == -1)
      {
        msg = "[" + capitalize(data[I2H_CHANNEL]) + "@" +
          LOCAL_NAME + "] Unkown intermud channel.\n";
      }
      else
      {
      /* Request for a list of people listening to a certain channel. */
        list = ({object *})CHANNEL_D->
          ChannelListeners(lower_case(data[I2H_CHANNEL]||""));
        list -= ({ 0, this_object() });
        list = filter( list,
                       lambda( ({ SYM(a) }),
                               ({ SF_NEGATE,
                                 ({ SF( call_other ),
                                    SYM(a), "Query", P_INVIS })
                                }))
        );
        if (i = sizeof(list))
        {
          msg = "[" + capitalize(data[I2H_CHANNEL]) + "@" +
            LOCAL_NAME + "] Listening:\n";
          while(i--)
            msg += "    " + capitalize(({string})list[i]->Query(P_REALNAME)) +
                   "\n";
        }
        else
          msg = "[" + capitalize(data[I2H_CHANNEL]) + "@" +
            LOCAL_NAME + "] Nobody Listening.\n";
      }
      reply[I2H_DATA] = msg;
      break;
    default:
      CHANNEL_D->send_local_message(data);
      break;
  }
  INET_D->send_packet(data[I2H_NAME], reply);
}

/* -------------------------------------------------------------------------
 * Initialize us
 * -------------------------------------------------------------------------
 */


void chan_startup()
{
  CHANNEL_D->AddChannels( intermud_channels, this_object() );
}

void create() {
  seteuid(getuid());
  packet_id = 0;
  pending_data = ([ ]);
  incoming_packets = ([ ]);
  hosts = ([ ]);
  received_ids = ({ });
  set_host_list();
  intermud_channels =
  ([
    /* intermud player channels (not intermud 3) */
    "d-chat" : ({ ({ this_object() }),
        0,
        CHANNEL_TYPE_IMUD,
        0 }),
    "intermud" : ({ ({ this_object() }),
        0,
        CHANNEL_TYPE_IMUD,
        0 }),
    /* intermud wizard channels (not intermud 3) */
    "d-code" : ({ ({ this_object() }),
        CHANNEL_FLAG_WIZ,
        CHANNEL_TYPE_IMUD,
        0 }),
    /* intermud wizard channels (not intermud 3) */
    "d-adm" : ({ ({ this_object() }),
        CHANNEL_FLAG_WIZ,
        CHANNEL_TYPE_IMUD,
        0 }),
    "intercode" : ({ ({ this_object() }),
        CHANNEL_FLAG_WIZ,
        CHANNEL_TYPE_IMUD,
        0 }),
    /* intermud admin channels (not intermud 3) */
    "interadmin" : ({ ({ this_object() }),
        CHANNEL_FLAG_ADMIN,
        CHANNEL_TYPE_IMUD,
        0 }),
    /* intermud readonly channels (not intermud 3) */
    "d-news" : ({ ({ this_object() }),
        CHANNEL_FLAG_ADMIN,
        CHANNEL_TYPE_IMUD,
        0 }),
  ]);
  call_out(#'startup /*'*/, 1);
  chan_startup();
}

/* --------------------------------------------------------------------------
 * remove
 * --------------------------------------------------------------------------
 */

int remove() {
  CHANNEL_D->RemoveChannels( m_indices( intermud_channels ) );
  destruct( this_object() );
  return this_object() && 1;
}

/* --------------------------------------------------------------------------
 * clean_up
 * --------------------------------------------------------------------------
 */

int clean_up( int refcount ) {
  /* don't wanna cleanup */
  return this_object() && 1;
}

/*---------------------------------------------------------------------------
 * adds a host to the internal host list
 *  this _must_ be only used by the hostlist builder
 *---------------------------------------------------------------------------
 */

void add_host( string name, mixed data ) {
  hosts[name] = data;
}

/*---------------------------------------------------------------------------
 * check_system_field: check the received hostdata for a specific entry in
 *                     the I2H_SYSTEM data
 *---------------------------------------------------------------------------
 */

status check_system_field(mapping data, string field) {
  return data[I2H_SYSTEM] && member(data[I2H_SYSTEM], field) != -1;
}

/*---------------------------------------------------------------------------
 * add_system_field: adds the field to the I2H_SYSTEM entry of data
 *---------------------------------------------------------------------------
 */

mapping add_system_field(mapping data, string field) {
  if (data[I2H_SYSTEM])
  {
    if (!check_system_field(data, field))
      data[I2H_SYSTEM] += ({ field });
  }
  else
    data[I2H_SYSTEM] = ({ field });

  return data;
}

/*---------------------------------------------------------------------------
 * set_host_list: read the INETD_HOSTS file and set the "hosts" mapping from
 * it. Retain existing I2D_HOST_STATUS fields.
 *---------------------------------------------------------------------------
 */

void set_host_list() {
  mixed data;

  if (data = read_file( INETD_HOST_FILE ) )
  {
    mapping old_hosts;
    int i;
    string *local_cmds;
    string name;

    old_hosts = hosts;
    hosts = ([ ]);
    for(i = sizeof(data = explode(data, "\n")); i--; )
    {
      if (data[i] == "" || data[i][0] == '#')
        continue;
      if (sizeof(data[i] = explode(data[i], HOSTFILE_DEL)) < 5)
      {
        log_file(INETD_LOG_FILE, "*Parse error in hosts file: line " +
          (i + 1) + "\n\n");
        continue;
      }
      name = lower_case(data[i][I2D_HOST_NAME]);
      if (member(local_cmds =
        explode(data[i][I2D_LOCAL_COMMANDS], HOSTFILE_DEL2), "*") != -1)
        local_cmds = local_cmds - ({ "*" }) + COMMANDS;
      hosts[name] =
      ({
        capitalize(data[i][I2D_HOST_NAME]),
        data[i][I2D_HOST_IP],
        to_int(data[i][I2D_HOST_UDP_PORT]),
        local_cmds,
        explode(data[i][I2D_HOST_COMMANDS], HOSTFILE_DEL2),
        UNKNOWN
      });
  /*
   * Retain existing host status as long as the IP and
   * UDP ports are the same.
   */
      if (old_hosts[name] &&
        old_hosts[name][I2D_HOST_IP] == hosts[name][I2D_HOST_IP] &&
        old_hosts[name][I2D_HOST_UDP_PORT] == hosts[name][I2D_HOST_UDP_PORT])
        hosts[name][I2D_HOST_STATUS] = old_hosts[name][I2D_HOST_STATUS];
    }
  }
  else
    log_file(INETD_LOG_FILE, "*Error in reading host file.\n\n");
}

/*---------------------------------------------------------------------------
 * startup: send a I2R_PING request to all muds in the "hosts" mapping to query
 *          I2D_HOST_STATUS information.
 *---------------------------------------------------------------------------
 */

void startup() {
  string *muds;
  int i;

  while(remove_call_out(#'startup /*'*/) != -1);
  for(i = sizeof(muds = m_indices(hosts)); i--; )
    send_packet(muds[i], ([ I2H_REQUEST: I2R_PING ]), 1);
}

/*---------------------------------------------------------------------------
 * Remove a buffered packet from the "incoming_packets" mapping.
 *---------------------------------------------------------------------------
 */

void remove_incoming(string id) {
  incoming_packets = m_delete(incoming_packets, id);
}

/*---------------------------------------------------------------------------
 * Decode a string from a UDP packet.
 * Returns:   The actual value of the argument (either int or string)
 *---------------------------------------------------------------------------
 */

string|int decode(string arg) {
  if (sizeof(arg) && arg[0] == '$')
    return arg[1..];
  else if ((arg & "0123456789") == arg)
    return to_int(arg);
  return arg;
}

/*---------------------------------------------------------------------------
 * Decode a UDP packet.
 * Arguments: UDP packet as a string.
 * Returns:   The decoded information as a mapping, 1 for succes but no
 *            output (buffered packet), or 0 on error.
 *---------------------------------------------------------------------------
 */

mixed decode_packet(string packet, string delimiter) {
  string *data;
  mapping ret;
  string info, tmp;
  mixed class;
  int i, id, n;

  /* If this packet has been split, handle buffering. */
  if (packet[0..sizeof(I2H_PACKET)] == I2H_PACKET + ":")
  {
    if (sscanf(packet, I2H_PACKET + ":%s:%d:%d/%d" + delimiter + "%s",
         class, id, i, n, tmp) != 5)
      return 0;
    class = lower_case(class) + ":" + id;
    if (pointerp(incoming_packets[class]))
    {
      incoming_packets[class][i-1] = tmp;
      if (member(incoming_packets[class], 0) == -1)
      {
        ret = decode_packet(implode(incoming_packets[class], ""), delimiter);
        remove_incoming(class);
        return ret;
      }
    }
    else
    {
      incoming_packets[class] = allocate(n);
      incoming_packets[class][i-1] = tmp;
      /* Is it possible to already have a timeout running here ?!? */
      /* If no timeout is running then start one. */
      if (!pending_data[class])
      {
        call_out("remove_incoming",
          INETD_REPLY_TIME_OUT + INETD_REPLY_TIME_OUT * INETD_RETRIES, class);
      }
      else
      {
        DEBUG("INET_D: Buffered packet Timeout already running!\n");
      }
    }
    return 1;
  }
  ret = ([ ]);
  for(i = 0, n = sizeof(data = explode(packet, delimiter)); i < n; i++)
  {
    /* I2H_DATA fields can be denoted by a preceeding blank field. */
    if (data[i] == "")
    {
      tmp = I2H_DATA;
      /* Test for illegal packet length (no I2H_DATA) */
      if (++i >= n)
        return 0;
      info = data[i];
    }
    else if (sscanf(data[i], "%s:%s", tmp, info) != 2)
      return 0;
    switch((string)(class = decode(tmp)))
    {
      case I2H_DATA:
        return ret + ([ I2H_DATA: decode(implode( ({ info }) +
          data[i+1..], delimiter)) ]);
      case I2H_SYSTEM:
        ret[class] = explode(info, ":");
        continue;
      default:
        ret[class] = decode(info);
        continue;
    }
  }
  return ret;
}

/*---------------------------------------------------------------------------
 * Check wether a UDP packet was valid.
 * Logs are made and "host" information is updated as appropriate.
 * Arguments: Decoded UDP packet (mapping)
 * Returns:   0 for valid packets, an error string otherwise.
 *---------------------------------------------------------------------------
 */

string valid_request(mapping data)
{
  mixed host_data;
  string *muds;
  string req;
  int i;

  if (!data[I2H_NAME] || !data[I2H_UDP_PORT])
    return DATE + ": Illegal packet.\n";
  if (host_data = hosts[lower_case(data[I2H_NAME])])
  {
    if (data[I2H_HOST] != host_data[I2D_HOST_IP])
    {
      if (data[I2H_NAME] == LOCAL_NAME)
        return DATE + ": *** FAKE MUD ***\n";
      log_file(INETD_LOG_FILE, DATE + ": Host change:\n" +
         host_data[I2D_HOST_NAME] + ": " + host_data[I2D_HOST_IP] + " -> " +
         data[I2H_HOST] + "\n\n");
      host_data[I2D_HOST_IP] = data[I2H_HOST];
    }
    if (data[I2H_UDP_PORT] != host_data[I2D_HOST_UDP_PORT])
    {
      if (data[I2H_NAME] == LOCAL_NAME)
        return DATE + ": *** FAKE MUD ***\n";
      log_file(INETD_LOG_FILE, DATE + ": Port change:\n" +
         host_data[I2D_HOST_NAME] + " (" + host_data[I2D_HOST_IP] + "): " +
         host_data[I2D_HOST_UDP_PORT] + " -> " + data[I2H_UDP_PORT] + "\n\n");
      host_data[I2D_HOST_UDP_PORT] = data[I2H_UDP_PORT];
    }
  }
  else
  {
    if (lower_case(data[I2H_NAME]) == lower_case(LOCAL_NAME))
      return DATE + ": *** FAKE MUD ***\n";
    for(i = sizeof(muds = m_indices(hosts)); i--; )
    {
      host_data = hosts[muds[i]];
      if (data[I2H_HOST] == host_data[I2D_HOST_IP] &&
        data[I2H_UDP_PORT] == host_data[I2D_HOST_UDP_PORT])
      {
        log_file(INETD_LOG_FILE, DATE + ": Name change:\n" +
          host_data[I2D_HOST_NAME] + " (" + host_data[I2D_HOST_IP] +
          ") -> " + data[I2H_NAME] + "\n\n");
        host_data[I2D_HOST_NAME] = data[I2H_NAME];
        hosts[lower_case(data[I2H_NAME])] = host_data;
        hosts = m_delete(hosts, muds[i]);
        i = -2;
        break;
      }
    }
    if (i != -2)
    {
      host_data = hosts[lower_case(data[I2H_NAME])] =
      ({
        data[I2H_NAME],
        data[I2H_HOST],
        data[I2H_UDP_PORT],
        COMMANDS,
        ({ "*" }),
        UP
      });
      log_file(INETD_LOG_FILE, DATE + ": New mud.\n" + data[I2H_NAME] + ":" +
         data[I2H_HOST] + ":" + data[I2H_UDP_PORT] + "\n\n");
    }
  }
  if (!(req = data[I2H_REQUEST]))
    return DATE + ": System message.\n";
  if (req != I2R_PING &&
      req != I2R_QUERY &&
      req != I2R_REPLY &&
      member(host_data[I2D_LOCAL_COMMANDS], req) == -1)
  {
    /* This should probably send a system message too. */
    send_packet(host_data[I2D_HOST_NAME],
    ([
      I2H_REQUEST: I2R_REPLY,
      I2H_RECIPIENT: data[I2H_SENDER],
      I2H_ID: data[I2H_ID],
      I2H_DATA: "Invalid request @" + LOCAL_NAME + ": " +
      capitalize(data[I2H_REQUEST]) + "\n"
    ]));
    return DATE + ": Invalid request.\n";
  }
  return 0;
}

/*---------------------------------------------------------------------------
 * Incoming UDP packets are sent to this function to be interpretted.
 * The packet is decoded, checked for validity, I2D_HOST_STATUS is updated
 * and the appropriate udp module called.
 * Arguments: Senders IP address (string)
 *            UDP packet (string)
 *---------------------------------------------------------------------------
 */

void receive_udp(string sender, string packet) {
  mixed data;
  string req, err, id;

//  dtell("nostradamus", sprintf("%O\n", packet));
  if (!previous_object() ||
      object_name(previous_object()) != __MASTER_OBJECT__ )
  {
    log_file(INETD_LOG_FILE, DATE + ": Illegal call of receive_udp() by " +
       object_name(previous_object()) + "\n\n");
    return;
  }

  if (
#ifdef DELIMITER_COMPAT
      (!mappingp(data = decode_packet(packet, NEW_DELIMITER))
       || (data[I2H_HOST] = sender) && (err = valid_request(data))) &&
      (!mappingp(data = decode_packet(packet, OLD_DELIMITER)) ||
       (data[I2H_HOST] = sender) && (err = valid_request(data)))
#else
      !mappingp(data = decode_packet(packet, DELIMITER))
#endif
      )
  {
    if (!data)
#ifdef LOG_INVALID
      log_file(INETD_LOG_FILE, DATE + ": Received invalid packet.\nSender: " +
         sender + "\nPacket:\n" + packet + "\n\n");
#endif
    return;
  }
#ifdef DELIMITER_COMPAT
  if (!mappingp(data))
    return;
  if (err)
#else
    data[I2H_HOST] = sender;
  if (err = valid_request(data))
#endif
  {
    log_file(INETD_LOG_FILE, err + "Sender: " + sender + "\nPacket:\n" +
      packet + "\n\n");
    return;
  }

  hosts[lower_case(data[I2H_NAME])][I2D_HOST_STATUS] = UP;
  if ((req = data[I2H_REQUEST]) == I2R_REPLY)
  {
    mapping pending;

    /* If we can't find the reply in the pending list then bin it. */
    if (!(pending = pending_data[lower_case(data[I2H_NAME]) + ":" + data[I2H_ID]]))
      return;
    /* Set data[I2H_REQUEST] correctly, but still send to (req = I2R_REPLY) */
    data[I2H_REQUEST] = pending[I2H_REQUEST];
#ifdef INETD_DIAGNOSTICS
    data[I2H_PACKET_LOSS] = pending[I2H_PACKET_LOSS];
    data[I2H_RESPONSE_TIME] = time() - pending[I2H_RESPONSE_TIME] + 1;
#endif

#if 0
    /* channel replies may not include a recipient, and shouldn't have */
    /* Restore I2H_RECIPIENT in replies if none given and it is known. */
    if (!data[I2H_RECIPIENT] && pending[I2H_SENDER])
      data[I2H_RECIPIENT] = pending[I2H_SENDER];
#endif

    pending_data =
      m_delete(pending_data, lower_case(data[I2H_NAME]) + ":" + data[I2H_ID]);
  }
  else if (data[I2H_ID])
  {
    if (member(received_ids, id = (lower_case(data[I2H_NAME]) + ":" + data[I2H_ID])) == -1)
    {
      received_ids += ({ id });
      call_out("remove_received_id", INETD_REPLY_TIME_OUT +
        INETD_REPLY_TIME_OUT * (INETD_RETRIES + 1), id);
    }
    else
      add_system_field(data, I2S_REPEAT);
  }

  if ( function_exists( "udp_"+req, this_object() ) )
    call_other( this_object(), "udp_"+req, copy( data ) );
  else if (err = catch( call_other( INETD_CMD_DIR + req, "udp_" + req, copy(data))))
  {
    send_packet(data[I2H_NAME],
      ([
         I2H_REQUEST: I2R_REPLY,
         I2H_RECIPIENT: data[I2H_SENDER],
         I2H_ID: data[I2H_ID],
         I2H_DATA: capitalize(req)+ " request failed @" + LOCAL_NAME + ".\n"
      ]));
    log_file(INETD_LOG_FILE, DATE + ": " + data[I2H_REQUEST] + " from " +
       data[I2H_NAME] + " failed.\n" + err + packet + "\n\n");
  }
}

/*---------------------------------------------------------------------------
 * expand_mud_name : find a mudname that matches abbreviated given name
 *---------------------------------------------------------------------------
 */

int do_match(string mudname, string match_str)
{
  return mudname[0..sizeof(match_str)-1] == match_str;
}

string *expand_mud_name(string name)
{
  return sort_array( filter(m_indices(hosts), #'do_match /*'*/, name), #'> /*'*/ );
}

string encode(mixed arg) {
  if (objectp(arg))
    return object_name(arg);
  if (stringp(arg) && (arg[0] == '$' || to_int(arg) == arg))
    return "$" + arg;
  return to_string(arg);
}

/*---------------------------------------------------------------------------
 * encode_packet: encode the mapping data to a string packet
 *---------------------------------------------------------------------------
 */

string encode_packet(mapping data) {
  int i, data_flag;
  mixed indices;
  string header, body;
  string *ret;

  for(ret = ({ }), i = sizeof(indices = m_indices(data)); i--; )
  {
    if (indices[i] == I2H_DATA)
    {
      data_flag = 1;
      continue;
    }
    header = encode(indices[i]);
    body = encode(data[indices[i]]);
    if (sscanf(header, "%~s:%~s") ||
      sscanf(header + body, "%~s" + DELIMITER + "%~s"))
      return 0;
    ret += ({ header + ":" + body });
  }
  if (data_flag)
#ifdef USE_OLD_DATA_FORMAT
    ret += ({ I2H_DATA + ":" + encode(data[I2H_DATA]) });
#else
  ret += ({ "", encode(data[I2H_DATA]) });
#endif
  return implode(ret, DELIMITER);
}

/*---------------------------------------------------------------------------
 * explode_packet: split string-packet into chunks of len
 *---------------------------------------------------------------------------
 */

string *explode_packet(string packet, int len) {
  if (sizeof(packet) <= len)
    return ({ packet });
  return ({ packet[0..len-1] }) + explode_packet( packet[len..], len);
}

/*---------------------------------------------------------------------------
 * send_packet: send data to mudname, optinal parameter to specify if an reply
 *           is expected (i.e. start reply_time_out call_out)
 *---------------------------------------------------------------------------
 */

varargs string send_packet(string mudname, mapping data, int expect_reply)
{
  mixed host_data;
  string *packet_arr;
  string packet;
  int i;

  mudname = lower_case(mudname);
  if (!(host_data = hosts[mudname]))
  {
    string *names;

    if (sizeof(names = expand_mud_name(mudname)) == 1)
      host_data = hosts[mudname = names[0]];
    else
      return "Unknown or ambiguous mudname: " + capitalize(mudname) + "\n";
  }
  if (data[I2H_REQUEST] != I2R_PING &&
      data[I2H_REQUEST] != I2R_QUERY &&
      data[I2H_REQUEST] != I2R_REPLY &&
      member(host_data[I2D_HOST_COMMANDS], "*") == -1 &&
      member(host_data[I2D_HOST_COMMANDS], data[I2H_REQUEST]) == -1)
    return capitalize(data[I2H_REQUEST]) + ": Command unavailable @" +
      host_data[I2D_HOST_NAME] + "\n";
  data[I2H_NAME] = LOCAL_NAME;
  data[I2H_UDP_PORT] = LOCAL_UDP_PORT;
  if (expect_reply)
  {
    /* Don't use zero. */
    data[I2H_ID] = ++packet_id;
    /* Don't need copy() as we are changing the mapping size. */
    pending_data[mudname + ":" + packet_id] =
#ifdef INETD_DIAGNOSTICS
    data + ([ I2H_NAME: host_data[I2D_HOST_NAME], I2H_RESPONSE_TIME: time() ]);
#else
    data + ([ I2H_NAME: host_data[I2D_HOST_NAME] ]);
#endif
  }
  if (!(packet = encode_packet(data)))
  {
    if (expect_reply)
      pending_data = m_delete(pending_data, mudname + ":" + packet_id);
    log_file(INETD_LOG_FILE, DATE + ": Illegal packet sent by " +
       object_name(previous_object()) + "\n\n");
    return "inetd: Illegal packet.\n";
  }
  if (expect_reply)
    call_out("reply_time_out", INETD_REPLY_TIME_OUT, mudname + ":" + packet_id);
  if (sizeof(packet) <= MAX_PACKET_LEN)
    packet_arr = ({ packet });
  else
  {
    string header;
    int max;

    /* Be careful with the I2H_ID.  data[I2H_ID] could have been set up by I2H_RETRY */
    header =
      I2H_PACKET + ":" + lower_case(LOCAL_NAME) + ":" +
      ((expect_reply || data[I2H_REQUEST] != I2R_REPLY)&& data[I2H_ID] ?
       data[I2H_ID] : ++packet_id) + ":";
    /* Allow 8 extra chars: 3 digits + "/" + 3 digits + DELIMITER */
    packet_arr = explode_packet(packet,
      MAX_PACKET_LEN - (sizeof(header) + 8));
    for(i = max = sizeof(packet_arr); i--; )
      packet_arr[i] = header + (i+1) + "/" + max + DELIMITER + packet_arr[i];
  }
  for(i = sizeof(packet_arr); i--; )
  {
    if (!efun::send_udp(
#if __VERSION__ > "3.5.2"
      host_data[I2D_HOST_IP], host_data[I2D_HOST_UDP_PORT],
      to_bytes(packet_arr[i], "UTF-8")))
#else
      host_data[I2D_HOST_IP], host_data[I2D_HOST_UDP_PORT], packet_arr[i]))
#endif
      return "inetd: Error in sending packet.\n";
  }
  return 0;
}

/*--------------------------------------------------------------------------
 * reply_time_out: handler for timed out replies, started by call_out
 *--------------------------------------------------------------------------
 */

void reply_time_out(string id)
{
  mapping data;

  if (data = pending_data[id])
  {
#ifdef INETD_DIAGNOSTICS
    data[I2H_PACKET_LOSS]++;
#endif
    if (data[I2H_RETRY] < INETD_RETRIES)
    {
      mapping send;

      data[I2H_RETRY]++;
      /* We must use a copy so the I2H_NAME field in pending_data[id]
       * isn't corrupted by send_packet(). */
      send = copy(data);
      send = m_delete(send, I2H_RETRY);
#ifdef INETD_DIAGNOSTICS
      send = m_delete(send, I2H_PACKET_LOSS);
      send = m_delete(send, I2H_RESPONSE_TIME);
#endif
      call_out("reply_time_out", INETD_REPLY_TIME_OUT, id);
      send_packet(data[I2H_NAME], send);
      return;
    }
    data = m_delete(data, I2H_RETRY);
#ifdef INETD_DIAGNOSTICS
    data = m_delete(data, I2H_RESPONSE_TIME);
#endif
    catch(call_other( INETD_CMD_DIR + I2R_REPLY, "udp_" + I2R_REPLY,
        add_system_field(data, I2S_TIME_OUT)));
    /* It's just possible this was removed from the host list. */
    if (hosts[lower_case(data[I2H_NAME])])
      hosts[lower_case(data[I2H_NAME])][I2D_HOST_STATUS] = DOWN;
    remove_incoming(lower_case(data[I2H_NAME]) + ":" + id);
  }
  pending_data = m_delete(pending_data, id);
}

/*---------------------------------------------------------------------------
 * remove_received_id: remove the id from the interlist list of received ids
 *---------------------------------------------------------------------------
 */

void remove_received_id(string id)
{
  received_ids -= ({ id });
}

/*---------------------------------------------------------------------------
 * query: returns internal data
 *---------------------------------------------------------------------------
 */

varargs mixed query(string what, mixed extra1, mixed extra2)
{
  mixed data;

  switch(what)
  {
    case I2RQ_COMMANDS:
      return COMMANDS;
    case I2RQ_HOSTS:
      return copy(hosts);
    case I2RQ_PENDING:
      return copy(pending_data);
    case I2RQ_INCOMING:
      return copy(incoming_packets);
    case I2RQ_RECEIVED:
      return ({ }) + received_ids;
    case I2RQ_VALID_REQUEST:
    /* args: "valid_request", request, mudname */
      if (data = hosts[extra2])
        return member(data[I2D_HOST_COMMANDS], "*") != -1
          || member(data[I2D_HOST_COMMANDS], extra1) != -1;
      return 0;
  }
  return 0;
}

void get_remote_hosts(string mudname)
{
  send_packet(mudname, ([
    I2H_REQUEST: I2R_QUERY,
    I2H_SENDER: this_player(),
    I2H_DATA: I2RQ_HOSTS
  ]), 1);
}

void get_remote_cmds(string mudname)
{
  send_packet(mudname, ([
    I2H_REQUEST: I2R_QUERY,
    I2H_SENDER: this_player(),
    I2H_DATA: I2RQ_COMMANDS
  ]), 1);
}
