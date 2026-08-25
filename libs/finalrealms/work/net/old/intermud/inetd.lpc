/*
 * UDP port handling code. Version 0.61
 * Written by Nostradamus for Zebedee.
 * Developed from an original concept by Alvin@Sushi.
 */

#pragma strict_types
#include <newudp.h>
#include <socket.h>

/* --- Configurable definitions. --- */

/* CD muds will probably need these include file. */
/* #include <std.h> */
/* #include "/config/sys/local.h" */

/* Public commands which will be accessible to any unlisted muds.
 * PING, QUERY and REPLY are included by default. */
#define COMMANDS \
({ "channel", "finger", "ftp", "locate", "man", "tell", "who" })

/* Define this to the object that receives incoming packets and passes
 * them to the inetd. Undefine for no receive_udp() security.
 * NOTE: The string must be of the format that file_name() returns. */
/* #define UDP_MASTER	__MASTER_OBJECT__ */
/* #define UDP_MASTER	SECURITY	// CD */
#define UDP_MASTER	"/single/master"
/* #define UDP_MASTER	"obj/master" */

/* How to set the euid for this object if using native mode.
 * Ensure that it can read the INETD_HOSTS file. */
/* #define SET_EUID		seteuid("root") */
#define SET_EUID		seteuid(getuid())

/* Define these as appropriate if you do not have the relevant efuns. */
/* #define to_int(x)		atoi(x)			// MudOS & CD */
#define to_string(x)		("" + x)		// CD 
/* #define copy_mapping(x)	copy(x)			// MudOS  */
#define copy_mapping(x)	(x + ([ ]))		// CD 
/* #define send_imp(host, port, data) \
		SECURITY->send_udp_message(host, port, data)	// CD

/* Define if casts can only be used on unknown or mixed types. (CD) */
#define RESTRICTED_CASTS

/* Define if your system does not support the a[n..] indexing notation. (CD) */
#undef USE_EXTRACT

/* Define this if you are running another intermud package concurrently. */
/* #define RECEIVE_UDP_COMPAT(sender, packet) \
		UDP_MANAGER->incoming_udp(sender, packet)	// CD */

/* Define this if you are running another intermud package concurrently and
 * have a compatability module for it. */
/* #define SEND_UDP_COMPAT(mudname, data, expect_reply) \
		"/secure/udp_compat"->send_udp(mudname, data, expect_reply) */

/* The maximum number of characters we can send in one packet.
 * You may need to reduce this, but 512 should be safe. */
#define MAX_PACKET_LEN	1024

/* You shouldn't need to change anything below. */

#ifdef ZEBEDEE
#include <defs.h>
#endif

#ifndef DATE
#define DATE		ctime(time())[4..15]
#endif

/* --- End of Config. Do not alter anything below. --- */

#define UNKNOWN		0
#define UP		time()
#define DOWN		(-time())

#define DELIMITER	"|"
#define RETRY		"_RETRY"

#define DEBUG(msg)	if (find_player("pinkfish"))\
			tell_object(find_player("pinkfish"), msg)

private mapping hosts, pending_data, incoming_packets;
private int packet_id;
private int socket;

void set_host_list();
varargs int send_udp(string mudname, mapping data, int expect_reply);
void receive_udp(string sender, string message);

int atoi(string str) {
  int bing;

  sscanf(str, bing);
  return bing;
} /* atoi() */

mapping m_delete(mapping map, mixed key) {
  map = map + ([ ]);
  map_delete(map, key);
  return map;
} /* m_delete() */

int send_imp(string host, string port, mixed data) {
  int blue;

  blue = socket_create(DATAGRAM, "out_read_callback", "out_close_callback");
  if (blue >= 0) {
    socket_write(blue, data, host+" "+port);
  } else {
    printf("Failure into the night.\n");
  }
  socket_close(blue);
  return 1;
} /* send_imp() */

void setup_server() {
  socket = socket_create(DATAGRAM, "in_read_callback", "in_close_callback");
  if (socket >= 0) {
    if (socket_bind(socket, LOCAL_UDP_PORT) < 0) {
      printf("Failed to bind socket.\n");
      socket_close(socket);
    }
  } else {
    printf("Failed to create socket.\n");
  }
} /* setup_server() */

#define m_indices(map) keys(map)

void in_read_callback(int socket, string message, string addr) {
  string port;

  sscanf(addr, "%s %s", addr, port);
  receive_udp(addr, message);
} /* in_read_callback() */

#if !defined(COMPAT_FLAG) || defined(ZEBEDEE)
void create() {
#ifndef COMPAT_FLAG
    SET_EUID;
#endif
#else
void reset(mixed arg) {
    if (arg)
	return;
#endif
    packet_id = 0;
    pending_data = ([ ]);
    incoming_packets = ([ ]);
    hosts = ([ ]);
    set_host_list();
    if (!this_player())
	call_out("startup", 1);
} /* create() */

void set_host_list() {
    mapping old_hosts;
    mixed data;

    old_hosts = copy_mapping(hosts);
    if (data = read_file(HOST_FILE)) {
	int i, stat;
	string *local_cmds;
	string name;
	mixed tmp;

	for(i = sizeof(data = explode(data, "\n")); i--; ) {
	    if (data[i] == "" || data[i][0] == '#')
		continue;
	    if (sizeof(data[i] = explode(data[i], ":")) < 5) {
		log_file(INETD_LOG_FILE, "*Parse error in hosts file: line " +
		(i + 1) + "\n");
		continue;
	    }
	    name = lower_case(data[i][HOST_NAME]);
	    /* Don't discard existing host int. */
	    if (tmp = old_hosts[name])
		stat = tmp[HOST_STATUS];
	    else
		stat = UNKNOWN;
	    if (member_array("*",
	    local_cmds = explode(data[i][LOCAL_COMMANDS], ",")) != -1)
		local_cmds = local_cmds - ({ "*" }) + COMMANDS;
	    hosts[name] = ({
		capitalize(data[i][HOST_NAME]),
		data[i][HOST_IP],
		to_int(data[i][HOST_UDP_PORT]),
		local_cmds,
		explode(data[i][HOST_COMMANDS], ","),
		stat
	    });
	}
    }
} /* set_host_list() */

void startup() {
    string *muds;
    int i;

    setup_server();
    for(i = sizeof(muds = m_indices(hosts)); i--; )
	send_udp(muds[i], ([ REQUEST: PING ]), 1);
} /* startup() */

mixed decode(string arg) {
    if (arg[0] == '$')
#ifdef USE_EXTRACT
	return extract(arg, 1);
#else
	return arg[1..10000];
#endif
#ifdef RESTRICTED_CASTS
    if (to_string(to_int(arg)) == arg)
	return to_int(arg);
#else
    if ((arg) == arg)
	return arg;
#endif
    return arg;
} /* decode() */

mixed decode_packet(string packet) {
    string *data;
    mapping ret;
    string info, tmp;
    mixed class_i;
    int i;

    data = explode(packet, DELIMITER);
    /* If this packet has been split, handle buffering. */
    if (data[0][0..strlen(PACKET)] == PACKET + ":") {
	int id, n;

	if (sscanf(
#ifdef USE_EXTRACT
	extract(data[0], strlen(PACKET)+1)
#else
	data[0][strlen(PACKET)+1..10000]
#endif
	, "%s:%d:%d/%d", class_i, id, i, n) != 4)
	    return 0;
	class_i = lower_case(class_i) + ":" + id;
	if (pointerp(incoming_packets[class_i])) {
	    incoming_packets[class_i][i-1] =
#ifdef USE_EXTRACT
	    extract(packet, strlen(data[0])+1);
#else
	    packet[strlen(data[0])+1..10000];
#endif
	    if (member_array(0, incoming_packets[class_i]) == -1) {
		ret = decode_packet(implode(incoming_packets[class_i], ""));
		incoming_packets = m_delete(incoming_packets, class_i);
		return ret;
	    }
	} else {
	    incoming_packets[class_i] = allocate(n);
	    incoming_packets[class_i][i-1] =
#ifdef USE_EXTRACT
	    extract(packet, strlen(data[0])+1);
#else
	    packet[strlen(data[0])+1..10000];
#endif
	    /* If no timeout is running then start one. */
	    if (!pending_data[class_i])
		call_out("incoming_time_out", REPLY_TIME_OUT, class_i);
	}
	return 1;
    }
    ret = ([ ]);
    for(i = 0; i < sizeof(data); i++) {
	if (sscanf(data[i], "%s:%s", tmp, info) != 2)
	    return 0;
	switch((string)(class_i = decode(tmp))) {
	    case DATA:
		return ret + ([ DATA: decode(
#ifdef USE_EXTRACT
		    extract(implode(data[i..sizeof(data)-1], DELIMITER)
		    , strlen(DATA)+1)
#else
		    implode(data[i..10000], DELIMITER)[strlen(DATA)+1..10000]
#endif
		    )
		]);
	    default:
		ret[class_i] = decode(info);
		continue;
	}
    }
    return ret;
} /* decode_packet() */

private int valid_request(mapping data) {
    mixed host_data;
    string req;
    
    if (!data[NAME] || !data[UDP_PORT] || !(req = data[REQUEST])) {
	log_file(INETD_LOG_FILE, DATE + ": Illegal packet.\n");
	return 0;
    }
    if (host_data = hosts[lower_case(data[NAME])]) {
#if 0
	if (data[HOST] != host_data[HOST_IP]) {
	    log_file(INETD_LOG_FILE, DATE + ": Host mismatch.\n");
	    return 0;
	}
	if (data[UDP_PORT] != host_data[HOST_UDP_PORT]) {
	    log_file(INETD_LOG_FILE, DATE + ": Port mismatch.\n");
	    return 0;
#else
	if (data[HOST] != host_data[HOST_IP]) {
	    log_file(INETD_LOG_FILE, DATE + ": Host change:\n" +
	    host_data[HOST_NAME] + ": " + host_data[HOST_IP] + " -> " +
	    data[HOST] + "\n\n");
	    host_data[HOST_IP] = data[HOST];
	}
	if (data[UDP_PORT] != host_data[HOST_UDP_PORT]) {
	    log_file(INETD_LOG_FILE, DATE + ": Port change:\n" +
	    host_data[HOST_NAME] + " (" + host_data[HOST_IP] + "): " +
	    host_data[HOST_UDP_PORT] + " -> " + data[UDP_PORT] + "\n\n");
	    host_data[HOST_UDP_PORT] = data[UDP_PORT];
	}
#endif
    } else {
	host_data = hosts[lower_case(data[NAME])] = ({
	    data[NAME],
	    data[HOST],
	    data[UDP_PORT],
	    COMMANDS,
	    ({ "*" }),
	    UP
	});
	log_file(INETD_LOG_FILE, DATE + ": New mud.\n" + data[NAME] + ":" +
	data[HOST] + ":" + data[UDP_PORT] + "\n\n");
    }
    if (req != PING && req != QUERY && req != REPLY &&
    member_array(data[REQUEST], host_data[LOCAL_COMMANDS]) == -1) {
	/* This should probably send a system message too. */
	send_udp(host_data[HOST_NAME], ([
	    REQUEST: REPLY,
	    RECIPIENT: data[SENDER],
	    ID: data[ID],
	    DATA: "Invalid request @" + LOCAL_NAME + ": " +
		capitalize(data[REQUEST]) + "\n"
	]) );
	log_file(INETD_LOG_FILE, DATE + ": Invalid request.\n");
	return 0;
    }
    return 1;
} /* valid_request() */

void receive_udp(string sender, string packet) {
    mapping data;
    string req, err;

/*
#ifdef UDP_MASTER
    if (!previous_object() ||
    file_name(previous_object()) != UDP_MASTER) {
	log_file(INETD_LOG_FILE, DATE + ": Illegal call of receive_udp() by " +
	file_name(previous_object()) + "\n\n");
	return;
    }
#endif
 */
    if (!mapp(data = decode_packet(packet))) {
	if (!data)
#ifdef RECEIVE_UDP_COMPAT
	    RECEIVE_UDP_COMPAT(sender, packet);
#else
	    log_file(INETD_LOG_FILE, DATE + ": Received invalid packet.\nSender: " +
	    sender + "\nPacket:\n" + packet + "\n\n");
#endif
	return;
    }
    data[HOST] = sender;
    if (!valid_request(data)) {
	log_file(INETD_LOG_FILE, "Sender: " + sender + "\nPacket:\n" +
	packet + "\n\n");
	return;
    }
    hosts[lower_case(data[NAME])][HOST_STATUS] = UP;
    req = data[REQUEST];
    if (req == REPLY) {
    	mapping pending;

	/* If we can't find the reply in the pending list then bin it. */
	if (!(pending = pending_data[lower_case(data[NAME]) + ":" + data[ID]]))
	    return;
	data[REQUEST] = pending[REQUEST];
#ifdef INETD_DIAGNOSTICS
	data[PACKET_LOSS] = pending[PACKET_LOSS];
	data[RESPONSE_TIME] = time() - pending[RESPONSE_TIME];
#endif
	pending_data =
	m_delete(pending_data, lower_case(data[NAME]) + ":" + data[ID]);
    }
    if (err = catch(
    call_other(UDP_CMD_DIR + req, "udp_" + req, copy_mapping(data)))) {
	send_udp(data[NAME], ([
	    REQUEST: REPLY,
	    RECIPIENT: data[SENDER],
	    ID: data[ID],
	    DATA: capitalize(req)+ " request failed @" + LOCAL_NAME + ".\n"
	]) );
	log_file(INETD_LOG_FILE, DATE + ": " + data[REQUEST] + " from " +
	data[NAME] + " failed.\n" + err + packet + "\n\n");
    }
} /* recieve_udp() */

int match_mud_name(string mudname, string match_str) {
    return mudname[0..strlen(match_str)-1] == match_str;
} /* match_mud_name() */

string encode(mixed arg) {
    if (objectp(arg))
	return file_name(arg);
    if (stringp(arg) && (arg[0] == '$' ||
#ifdef RESTRICTED_CASTS
    to_string(to_int(arg)) == (string)arg))
#else
    (string)to_int(arg) == (string)arg))
#endif
	return "$" + arg;
    return to_string(arg);
} /* encode() */

string encode_packet(mapping data) {
    int i;
    mixed indices;
    string header, body, t1, t2, ret;
    int data_flag;

    for(i = sizeof(indices = m_indices(data)); i--; ) {
	if (indices[i] == DATA) {
	    data_flag = 1;
	    continue;
	}
	header = encode(indices[i]);
	body = encode(data[indices[i]]);
	if (sscanf(header, "%s" + DELIMITER + "%s", t1, t2) ||
	sscanf(body, "%s" + DELIMITER + "%s", t1, t2))
	    return 0;
	if (ret)
	    ret +=
	    DELIMITER + header + ":" + body;
	else
	    ret = header + ":" + body;
    }
    if (ret) {
	if (data_flag)
	    ret += DELIMITER + DATA + ":" + encode(data[DATA]);
	return ret;
    }
} /* encode_packet() */

string *explode_packet(string packet, int len) {
    if (strlen(packet) <= len)
	return ({ packet });
    return ({ packet[0..len-1] }) +
    explode_packet(
#ifdef USE_EXTRACT
    extract(packet, len)
#else
    packet[len..10000]
#endif
    , len);
} /* explode_packet() */

varargs string send_udp(string mudname, mapping data, int expect_reply) {
    mixed host_data;
    string *packet_arr;
    string packet;
    int i;

    mudname = lower_case(mudname);
    if (!(host_data = hosts[mudname])) {
	string *names;

	if (sizeof(names = filter_array(
	m_indices(hosts), "match_mud_name", this_object(), mudname)) == 1)
	    host_data = hosts[mudname = names[0]];
	else
#ifdef SEND_UDP_COMPAT
	    return (string)SEND_UDP_COMPAT(mudname, data, expect_reply);
#else
	    return "Unknown mud: " + capitalize(mudname) + "\n";
#endif
    }
    if (data[REQUEST] != PING &&
    data[REQUEST] != QUERY &&
    data[REQUEST] != REPLY &&
    member_array("*", host_data[HOST_COMMANDS]) == -1 &&
    member_array(data[REQUEST], host_data[HOST_COMMANDS]) == -1)
	return capitalize(data[REQUEST]) + ": Command unavailable @" +
	host_data[HOST_NAME] + "\n";
    data += ([ NAME: LOCAL_NAME, UDP_PORT: LOCAL_UDP_PORT ]);
    if (expect_reply) {
	/* Don't use zero. */
	data[ID] = ++packet_id;
	/* Don't need copy_mapping() as we are changing the mapping size. */
	pending_data[mudname + ":" + packet_id] =
#ifdef INETD_DIAGNOSTICS
	data + ([ NAME: host_data[HOST_NAME], RESPONSE_TIME: time() ]);
#else
	data + ([ NAME: host_data[HOST_NAME] ]);
#endif
	call_out("reply_time_out", REPLY_TIME_OUT, mudname + ":" + packet_id);
    }
    if (!(packet = encode_packet(data))) {
	if (expect_reply)
	    pending_data = m_delete(pending_data, mudname + ":" + packet_id);
	log_file(INETD_LOG_FILE, DATE + ": Illegal packet sent by " +
	file_name(previous_object()) + "\n\n");
	return "inetd: Illegal packet.\n";
    }
    if (strlen(packet) <= MAX_PACKET_LEN)
	packet_arr = ({ packet });
    else {
	string header;
	int max;

	header = PACKET + ":" + lower_case(LOCAL_NAME) + ":" +
	(expect_reply ? packet_id : ++packet_id) + ":";
	packet_arr = explode_packet(packet,
	/* Allow 8 extra chars: 3 digits + "/" + 3 digits + DELIMITER */
	MAX_PACKET_LEN - (strlen(header) + 8));
	for(i = max = sizeof(packet_arr); i--; )
	    packet_arr[i] =
	    header + (i+1) + "/" + max + DELIMITER + packet_arr[i];
    }
    for(i = sizeof(packet_arr); i--; ) {
	if (!send_imp(
	host_data[HOST_IP], host_data[HOST_UDP_PORT], packet_arr[i]))
	    return "inetd: Error in sending packet.\n";
    }
    return 0;
} /* send_udp() */

void incoming_time_out(string id) {
    incoming_packets = m_delete(incoming_packets, id);
} /* incoming_time_out() */

void reply_time_out(mixed id) {
    mapping data;

    if (data = pending_data[id]) {
	object ob;

#ifdef INETD_DIAGNOSTICS
	data[PACKET_LOSS]++;
#endif
	if (data[RETRY] < RETRIES) {
	    mapping send;

	    data[RETRY]++;
	    /* We must use a copy so the NAME field in pending_data[id]
	     * isn't corrupted by send_udp(). */
	    send = copy_mapping(data);
	    send = m_delete(send, RETRY);
#ifdef INETD_DIAGNOSTICS
	    send = m_delete(send, PACKET_LOSS);
	    send = m_delete(send, RESPONSE_TIME);
#endif
	    call_out("reply_time_out", REPLY_TIME_OUT, id);
	    send_udp(data[NAME], send);
	    return;
	}
	data = m_delete(data, RETRY);
#ifdef INETD_DIAGNOSTICS
	data = m_delete(data, RESPONSE_TIME);
#endif
	catch(call_other(UDP_CMD_DIR + REPLY, "udp_" + REPLY,
	data + ([ SYSTEM: TIME_OUT ])));
	/* It's just possible this was removed from the host list. */
	if (hosts[lower_case(data[NAME])])
	    hosts[lower_case(data[NAME])][HOST_STATUS] = DOWN;
	incoming_time_out(lower_case(data[NAME]) + ":" + id);
    }
    pending_data = m_delete(pending_data, id);
} /* reply_time_out() */

varargs mixed query(string what) {
    switch(what) {
	case "commands":
	    return COMMANDS;
	case "hosts":
	    return copy_mapping(hosts);
	case "pending":
	    return copy_mapping(pending_data);
	case "incoming":
	    return copy_mapping(incoming_packets);
    }
} /* query() */

int query_host(string str) {
  if (hosts[str]) return 1;
} /* query_host() */

mixed query_host_info(string str) {
  return hosts[str];
} /* query_host_info() */

void dest_me() {
  socket_close(socket);
  destruct(this_object());
} /* dest_me() */

void remove() {
  dest_me();
} /* remove() */
