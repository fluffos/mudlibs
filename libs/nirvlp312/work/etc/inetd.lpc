/*
 * UDP port handling code.
 * Written by Nostradamus for Zebedee.
 * Developed from an original concept by Alvin@Sushi.
 */

#pragma strict_types

#include <udp.h>
#include <kernel.h>
#include <libs.h>

/*
 * Public commands which will be accessible to any unlisted muds.
 * PING, QUERY and REPLY are included by default.
 */
#define COMMANDS ({ "channel", "finger", "locate", "man", \
                    "tell", "who", "www", "mail" })

/*
 * Define this to the object that receives incoming packets and passes
 * them to the inetd. Undefine for no receive_udp() security.
 * NOTE: The string must be of the format that object_name() returns.
 */
#define UDP_MASTER      MASTER

/*
 * The maximum number of characters we can send in one packet.
 * You may need to reduce this, but 512 should be safe.
 */
#define MAX_PACKET_LEN  1024

/*
 * The maximum number of muds we connect to. Protection against script
 * kiddies, as happened in Finalfrontier.
 */

#define MAX_MUD_AMOUNT  1000

#ifndef DATE
//#define DATE          ctime(time())[4..15]
#define DATE            ctime(time())
#endif

#define UNKNOWN         0
#define UP              time()
#define DOWN            (-time())

#define DELIMITER       "|"
#define RETRY           "_RETRY"

// Coogan, 08-Jun-2001
#if EVERMORE
#  define EVERMORE_TUBMUD_COMMAND "evermore_tubmud"
#else
#if TUBMUD
#  define EVERMORE_TUBMUD_COMMAND "evermore_tubmud"
#endif
#endif

#define SAVEFILE        "/save/inetd"

inherit ACCESS;
inherit "basic/create";
inherit "basic/encoding";

private        mapping hosts;
private nosave mapping pending_data, incoming_packets;
private nosave int     packet_id;
private nosave mixed  *last_packet;
private nosave int     debug;

varargs string do_send_udp(string mudname, mapping data, int expect_reply);

void set_debug(int d) {
  debug = !!d;
}

int query_debug() {
  return debug;
}

// next lfun for LIB_GRAMMAR support, Coogan, 19-Oct-2001
string get_mud_name(string str) {
  if (member(hosts, str))
    return hosts[str][0];
  return member(hosts, (str = implode(explode(lower_case(str), " "), "."))) &&
         hosts[str][0];
}

void set_host_list() {
  mapping old_hosts;
  mixed data;

  old_hosts = copy(hosts);
  if (data = read_file(HOST_FILE)) {
    int i, stat;
    string *local_cmds;
    string name;
    mixed tmp;

    for (i = sizeof(data = explode(data, "\n")); i--; ) {
      if (data[i] == "" || data[i][0] == '#')
        continue;
      if (sizeof(data[i] = explode(data[i], ":")) < 5) {
        log_file(INETD_LOG_FILE, "*Parse error in hosts file: line " +
                 (i + 1) + "\n");
        continue;
      }
      name = lower_case(data[i][HOST_NAME]);
      /* Don't discard existing host status. */
      if (tmp = old_hosts[name])
        stat = tmp[HOST_STATUS];
      else
        stat = UNKNOWN;
      if (member(local_cmds = explode(data[i][LOCAL_COMMANDS],","), "*") != -1)
        local_cmds = local_cmds - ({ "*" }) + COMMANDS;
      hosts[name] = ({ capitalize(data[i][HOST_NAME]),
                       data[i][HOST_IP],
                       to_int(data[i][HOST_UDP_PORT]),
                       local_cmds,
                       explode(data[i][HOST_COMMANDS], ","),
                       stat });
    }
  }
}

#if 0  // obsolete, but too nice to delete it. Coogan, 08-Jun-2001
private string upper_case(string s) {
  mixed h;
  return catch(h=to_string(map(to_array(s),#'&,~32)))? s : h;
}
#endif

private mapping upper_case_mapping(mapping packet) {
#if 0  // some lowercase values must stay lowercase, according to the specs
       // Coogan, 15-Jul-2002
  return packet;
#else
  return mkmapping(map(m_indices(packet),#'upper_case),m_values(packet));
#endif
}

private mapping beautify_mapping(mapping packet) {
  string k, uk, lk;
  // Coogan, 29-May-2005: this function takes a packet and upper/lowercases
  // the keys according to the specs. The particular modules rely on that.
  // these must be uppercase:
#define UPPERCASE_KEYS  (({ "DATA", "RCPNT", "QUERY", "METHOD", "CHANNEL", "CMD", "EMOTE", "ID", "SND", "UDP", "REPLY", "REQ", "NAME" }))
  // and these lowercase:
#define LOWERCASE_KEYS  (({ "user", "vbs", "fnd", "udpm_status", "udpm_writer", "udpm_spool_name", "udpm_subject" }))
  foreach (k : LOWERCASE_KEYS) {
    uk = upper_case(k);
    if (member(packet, uk)) {
      if (!member(packet, k))
        packet[k] = packet[uk];
      m_delete(packet, uk);
    }
  }
  foreach (k : UPPERCASE_KEYS) {
    lk = lower_case(k);
    if (member(packet, lk)) {
      if (!member(packet, k))
        packet[k] = packet[lk];
      m_delete(packet, lk);
    }
  }
  if (debug)
    DEBUG_POINT("coogan", ({ packet }));
  return packet;
}

// Coogan, 11-Jul-2001
private varargs string strip_data(mixed d, status outgoing) {
  if (stringp(d)) {
#if 1  // Coogan, 19-Nov-2002
    d = regreplace(d, "^\n*(.*[^\n])\n*", outgoing? "\\1\n" : "\\1", 1);
#else
    while (strlen(d) && d[0] == '\n')
      d = d[1..];
    while (strlen(d) && d[<1] == '\n')
      d = d[0..<2];
    if (outgoing)
      d += "\n";
#endif
  }
  return d;
}
                        
void startup() {
  string *muds;
  int i;
  for (i = sizeof(muds = m_indices(hosts)); i--; )
    do_send_udp(muds[i], ([ REQUEST: PING ]), 1);
}

mixed decode(string arg) {
  if (arg[0] == '$')
    return arg[1..];
  if ((string)((int)arg) == arg)
    return (int)arg;
  return arg;
}

mixed decode_packet(string packet) {
  string *data;
  mapping ret;
  string info, tmp;
  mixed class;
  int i;

  data = explode(packet, DELIMITER);
  /* If this packet has been split, handle buffering. */
  if (data[0][0..strlen(PACKET)] == PACKET + ":") {
    int id, n;
    if (sscanf(data[0][strlen(PACKET)+1..],
               "%s:%d:%d/%d", class, id, i, n) != 4)
      return 0;
    class = lower_case(class) + ":" + id;
    if (pointerp(incoming_packets[class])) {
      incoming_packets[class][i-1] = packet[strlen(data[0])+1..];
      if (member(incoming_packets[class], 0) == -1) {
        ret = decode_packet(implode(incoming_packets[class], ""));
        incoming_packets = m_delete(incoming_packets, class);
        return ret;
      }
    }
    else {
      incoming_packets[class] = allocate(n);
      incoming_packets[class][i-1] = packet[strlen(data[0])+1..];
      /* If no timeout is running then start one. */
      if (!pending_data[class])
        efun::call_out("incoming_time_out", REPLY_TIME_OUT, class);
    }
    return 1;
  }
  ret = ([ ]);
  for (i = 0; i < sizeof(data); i++) {
    if (sscanf(data[i], "%s:%s", tmp, info) != 2)
      return 0;
    switch (class = decode(tmp)) {
    case DATA:
      return ret + ([ DATA: decode(implode(data[i..],DELIMITER)
                                   [strlen(DATA)+1..]) ]);
    default:
      ret[class] = decode(info);
      continue;
    }
  }
  return ret;
}

private int valid_request(mapping data) {
  mixed host_data,h;
  string req,s;
  
  if (!data[NAME] || !data[UDP_PORT] || !(req = data[REQUEST])) {
    log_file(INETD_LOG_FILE, DATE + ": Illegal packet.\n");
    return 0;
  }
  if (host_data = hosts[lower_case(data[NAME])]) {
    if (data[HOST] != host_data[HOST_IP]) {
      if (lower_case(data[NAME])==lower_case(LOCAL_NAME))
        return 0;
      log_file(INETD_LOG_FILE, DATE + ": Host change:\n" +
               host_data[HOST_NAME] + ": " + host_data[HOST_IP] + " -> " +
               data[HOST] + "\n\n");
      host_data[HOST_IP] = data[HOST];
    }
    if (data[UDP_PORT] != host_data[HOST_UDP_PORT]) {
      if (lower_case(data[NAME])==lower_case(LOCAL_NAME))
        return 0;
      log_file(INETD_LOG_FILE, DATE + ": Port change:\n" +
               host_data[HOST_NAME] + " (" + host_data[HOST_IP] + "): " +
               host_data[HOST_UDP_PORT] + " -> " + data[UDP_PORT] + "\n\n");
      host_data[HOST_UDP_PORT] = data[UDP_PORT];
    }
  }
  else {
    if (sizeof(hosts) >= MAX_MUD_AMOUNT) {
      log_file(INETD_LOG_FILE, DATE + ": Mud not accepted, too many muds: " +
                               data[NAME] + ":" + data[HOST] + ":" +
                               data[UDP_PORT] + "\n\n");
      return 0;
    }
      
    host_data = hosts[lower_case(data[NAME])] = ({ data[NAME],
                                                   data[HOST],
                                                   data[UDP_PORT],
                                                   COMMANDS,
                                                   ({ "*" }),
                                                   UP });
    log_file(INETD_LOG_FILE, DATE + ": New mud.\n" + data[NAME] + ":" +
             data[HOST] + ":" + data[UDP_PORT] + "\n\n");
  }
#if 1  // Alfe 00-May-23
  // find all muds with the same host/port combination and remove them.
  s = lower_case(data[NAME]);
  h = filter_indices(hosts,
                     (: ($2[$1][1] == $2[$3][1] &&
                         $2[$1][2] == $2[$3][2]) :), hosts, s) - ([ s ]);
  if (sizeof(h)) {
    hosts -= mkmapping(m_indices(h));
    log_file(INETD_LOG_FILE,DATE + ": Mud(s) ousted.\n" +
             data[NAME] + ":" + data[HOST] + ":" + data[UDP_PORT] + "\n" +
             implode(m_indices(h)," ") + "\n\n");
  }
#endif
  if (req != PING && req != QUERY && req != REPLY &&
      member(host_data[LOCAL_COMMANDS], data[REQUEST]) == -1
#ifdef EVERMORE_TUBMUD_COMMAND
      && lower_case(req) != EVERMORE_TUBMUD_COMMAND
#endif
      ) {

    /* This should probably send a system message too. */
    do_send_udp(host_data[HOST_NAME],
                ([ REQUEST: REPLY,
                   RECIPIENT: data[SENDER],
                   ID: data[ID],
                   DATA: "Invalid request @"+LOCAL_NAME+": " +
                         capitalize(data[REQUEST]) ]));
    log_file(INETD_LOG_FILE, DATE + ": Invalid request.\n");
    return 0;
  }
  return 1;
}


void receive_udp(string sender, string packet) {
  mapping data;
  string req, err;
//DEBUG_POINT("coogan",({ sender,strlen(packet)<2000? packet : ""+strlen(packet) }));
  if (!previous_object() || object_name(previous_object()) != UDP_MASTER) {
    log_file(INETD_LOG_FILE, DATE + ": Illegal call of receive_udp() by " +
             object_name(previous_object()) + "\n");
    return;
  }
  // drop duplicates, Coogan, 02-Mar-2002
  if (last_packet &&
      time() == last_packet[0] &&
      sender == last_packet[1] &&
      packet == last_packet[2])
    return;
  last_packet = ({ time(), sender, packet });

//if (strstr(packet, "vermore") > -1) DEBUG_POINT("coogan", ({ packet }));
  if (!mappingp(data = decode_packet(packet))) {
    if (!data)
      log_file(INETD_LOG_FILE,
               (DATE + ": Received invalid packet.\n"
                "Sender: " + sender + "\nPacket:\n" + packet + "\n"));
    return;
  }
// DEBUG_POINT("coogan",({ data }));
//  if (debug)
//    beautify_mapping(data);
  if (data[REQUEST] == "channel")       // uppercase the mapping only for some
    data = upper_case_mapping(data);    // cases, Coogan, 19-Nov-2002
  data[DATA] = strip_data(data[DATA]);
//DEBUG_POINT("coogan",({ data }));
  data[HOST] = sender;
  if (!valid_request(data)) {
    log_file(INETD_LOG_FILE, "Sender: " + sender + "\nPacket:\n" +
             packet + "\n\n");
    return;
  }
  hosts[lower_case(data[NAME])][HOST_STATUS] = UP;
#if 0
  if (//lower_case(data[NAME]) == "perlmud"
      //lower_case(data[NAME]) == "wunderland"
      lower_case(data[NAME]) == "morgengrauen"
      // lower_case(data[NAME]) == "avalon"
     ) DEBUG_POINT("coogan", ({ data }));
#endif
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
    pending_data = m_delete(pending_data,
                            lower_case(data[NAME]) + ":" + data[ID]);
  }
  if (err = catch(call_other(UDP_CMD_DIR + req, "udp_" + req,
                             copy(data)))) {
    do_send_udp(data[NAME],([ REQUEST: REPLY,
                              RECIPIENT: data[SENDER],
                              ID: data[ID],
                              DATA: (capitalize(req)+ " request failed @" +
                                    LOCAL_NAME + ".") ]));
    log_file(INETD_LOG_FILE, DATE + ": " + data[REQUEST] + " from " +
             data[NAME] + " failed.\n" + err + packet + "\n\n");
  }
}

int match_mud_name(string mudname, string match_str) {
  return mudname[0..strlen(match_str)-1] == match_str;
}

string encode(mixed arg) {
  if (objectp(arg))
    return object_name(arg);
  if (stringp(arg) && (arg[0] == '$' || (string)to_int(arg) == (string)arg))
    return "$" + arg;
  return to_string(arg);
}

// added argument mudname (not used yet, but offers the ability to encode
// differently for different muds)  Alfe 2003-May-22
varargs string encode_packet(mapping data, string mudname) {
  int i;
  mixed indices;
  string header, body, t1, t2, ret;
  status data_flag, dnews;

#define DNEWS  // Coogan, 24-May-2003
#ifdef DNEWS    // no mud2ascii() for d-news
  if (member(data, "CHANNEL") &&
      data["CHANNEL"] == "d-news")
    dnews = 1;
#endif
  for (i = sizeof(indices = m_indices(data)); i--; ) {
    if (indices[i] == DATA) {
      data_flag = 1;
      continue;
    }
#ifdef DNEWS
    if (dnews) {
      header = encode(indices[i]);
      body   = encode(data[indices[i]]);
    }
    else {
#endif
      // convert internal encoding (latin 1) to ascii:  Alfe 2003-May-22
      header = mud2ascii(encode(indices[i]), 0);
      body = mud2ascii(encode(data[indices[i]]), 0);
#ifdef DNEWS
    }
#endif
    if (sscanf(header, "%s" + DELIMITER + "%s", t1, t2) ||
        sscanf(body,   "%s" + DELIMITER + "%s", t1, t2))
      return 0;
    if (ret)
      ret += DELIMITER + header + ":" + body;
    else
      ret = header + ":" + body;
  }
  if (ret) {
    if (data_flag)
#ifdef DNEWS
      if (dnews)
        ret += DELIMITER + DATA + ":" + encode(data[DATA]);
      else
#endif
        ret += DELIMITER + DATA + ":" + mud2ascii(encode(data[DATA]), 2);
    return ret;
  }
}

string *explode_packet(string packet, int len) {
  if (strlen(packet) <= len)
    return ({ packet });
  return ({ packet[0..len-1] }) +
    explode_packet(packet[len..], len);
}

varargs string do_send_udp(string mudname, mapping data, int expect_reply) {
  mixed h;
  mixed host_data;
  string *packet_arr;
  string packet;
  int i;

  if (!mudname) {
    h = map(m_indices(hosts),#'do_send_udp,data,expect_reply);
    h -= regexp(h-({ 0 }),"^[Ww]arning");
    return implode(h,"\n");
  }
  mudname = lower_case(mudname);
  if (!(host_data=hosts[mudname])) {
    string *names;
    switch (sizeof(names=filter(m_indices(hosts),"match_mud_name",
                                      this_object(),mudname))) {
    case 0:
      return "Unknown mud: "+capitalize(mudname)+"\n";
    case 1:
      host_data = hosts[mudname=names[0]];
      break;
    default:
      return "Ambiguous mud name: " + make_list(names) + "\n";
    }
  }
  if (data[REQUEST] != PING &&
      data[REQUEST] != QUERY &&
      data[REQUEST] != REPLY &&
      member(host_data[HOST_COMMANDS], "*") < 0 &&
      member(host_data[HOST_COMMANDS], data[REQUEST])<0)
    return (capitalize(data[REQUEST])+": Command unavailable @"+
            host_data[HOST_NAME]+"\n");
  data += ([ NAME: LOCAL_NAME, UDP_PORT: LOCAL_UDP_PORT ]);
#if 0
  data[DATA] = strip_data(data[DATA], 1);  // Coogan, 11-Jul-2001
#endif
  if (expect_reply) {
    /* Don't use zero. */
    data[ID] = ++packet_id;
    /* Don't need copy() as we are changing the mapping size. */
    pending_data[mudname+":"+packet_id] =
      data + ([ NAME   : host_data[HOST_NAME],
#ifdef INETD_DIAGNOSTICS
                RESPONSE_TIME: time(),
#endif
             ]);
    efun::call_out("reply_time_out",REPLY_TIME_OUT,mudname+":"+packet_id);
  }
  if (!(packet=limited(lambda(0, ({ #'encode_packet,
#if 0  // Coogan, 19-Nov-2002
                                    upper_case_mapping(data),
#else
                                    data,
#endif
                                    mudname }))))) {
    if (expect_reply)
      pending_data = m_delete(pending_data, mudname+":"+packet_id);
    log_file(INETD_LOG_FILE,DATE+": Illegal packet sent by "+
             object_name(previous_object()) + "\n\n");
    return "inetd: Illegal packet.\n";
  }
  if (strlen(packet) <= MAX_PACKET_LEN)
    packet_arr = ({ packet });
  else {
    string header;
    int max;
    header = (PACKET+":"+lower_case(LOCAL_NAME)+":"+
              (expect_reply ? packet_id : ++packet_id) + ":");
    packet_arr = explode_packet(packet,
       /* Allow 8 extra chars: 3 digits + "/" + 3 digits + DELIMITER */
                                MAX_PACKET_LEN-(strlen(header)+8));
    for (i=max=sizeof(packet_arr); i--; )
      packet_arr[i] = header+(i+1) + "/" + max + DELIMITER + packet_arr[i];
  }
  for (i=sizeof(packet_arr); i--; ) {
//if (mudname=="tappmud") 
//if (mudname=="evermore") 
//if (mudname=="wunderland") 
//if (mudname=="finalfrontier") 
//if (mudname=="tubmud") 
//DEBUG_POINT("coogan", ({ packet_arr[i] }));
#if 0
    efun::call_out(#'send_udp, i / 4,
                   host_data[HOST_IP],host_data[HOST_UDP_PORT],packet_arr[i]);
#else
    if (!send_udp(host_data[HOST_IP],host_data[HOST_UDP_PORT],packet_arr[i]))
      // error message extended, Coogan, 13-Nov-2008
      return "inetd: Error in sending packet to " + host_data[HOST_NAME] +
             ", IP " + host_data[HOST_IP] + ", udp port " +
             host_data[HOST_UDP_PORT] + ".\n";
#endif
  }
  if (host_data[HOST_STATUS] < 0)  // mud is down?
    return "Warning: mud \""+host_data[HOST_NAME]+"\" is marked as down.\n";
  return 0;  // Commented out, Coogan, 12-Sep-2000
}

void incoming_time_out(string id) {
  incoming_packets = m_delete(incoming_packets, id);
}

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
      /*
       * We must use a copy so the NAME field in pending_data[id]
       * isn't corrupted by do_send_udp().
       */
      send = copy(data);
      send = m_delete(send, RETRY);
#ifdef INETD_DIAGNOSTICS
      send = m_delete(send, PACKET_LOSS);
      send = m_delete(send, RESPONSE_TIME);
#endif
      efun::call_out("reply_time_out", REPLY_TIME_OUT, id);
      do_send_udp(data[NAME], send);
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
}

varargs mixed query(string what) {
  switch (what) {
  case "commands":
    return COMMANDS;
  case "hosts":
    return copy(hosts);
  case "pending":
    return copy(pending_data);
  case "incoming":
    return copy(incoming_packets);
  }
  // NO_WARN_MISSING_RETURN would fit better, but I don't want to have
  // bugs caused by invalid queries of other muds (Coogan)
  return 0;  // Coogan, 26-Mar-2011
}

mixed* query_mud_info(string mud) {  // Coogan, 12-Feb-2002
  // the string 'mud' is expected to be a matching string to be successful
  // (only the case doesn't matter)
  return mud && member(hosts, lower_case(mud)) && copy(hosts[lower_case(mud)]);
}

private status restore_me() {  // Coogan, 07-May-2002
  if (file_size(SAVEFILE+".o") > 0 &&
      unguarded(1, #'restore_object, SAVEFILE))
    return 1;
  return 0;
}

private void save_me() {  // Coogan, 07-May-2002
  unguarded(1, #'save_object, SAVEFILE);
}

void create() {
  create::create();
  packet_id = 0;
  pending_data     = ([ ]);
  incoming_packets = ([ ]);
  if (!restore_me()) {
    hosts          = ([ ]);
    set_host_list();
    save_me();
  }
  efun::call_out("startup", 1);
}

void refresh() {
  create::refresh();
  save_me();
}

void notify_destruct() {  // Coogan, 07-May-2002
  save_me();
}

void dump_host_list() {  // Coogan, 13-May-2002
  string *hostnames, hostname, line;
  unguarded(1, #'rm, "/etc/INETD_HOSTS.DUMP");
  hostnames = sort_array(m_indices(hosts), #'>) - ({ "www" });
  foreach (hostname : hostnames) {
    if (!pointerp(hosts[hostname]) ||
        sizeof(hosts[hostname]) < 6)
      continue;
    line = hosts[hostname][0] + ":" + hosts[hostname][1] + ":" +
           hosts[hostname][2] + ":*:*\n";
    unguarded(1, #'write_file, ({ "/etc/INETD_HOSTS.DUMP", line }));
  }
}

