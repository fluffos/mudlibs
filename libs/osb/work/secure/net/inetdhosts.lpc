/*
 *	inetdhosts.c			Pepel <pepel@ibr.cs.tu-bs.de> Nov 94
 *
 * create the transitive hull of all known and reachable muds theat emply
 * the inetd protocol.
 */

#include <secure/udp.h>

#define UNKNOWN		0
#define UP		time()
#define DOWN		(-time())

#define DELIMITER	"|"

#define LOGFILE "/log/inetdhosts"

mapping hosts;
string *donehosts = ({});
int sent, received, timeouts;

#define TELL_CHEF(m) \
  do { tell_room(find_object("/players/pepel/workroom"), \
                 object_name()+": "+m+"\n"); } \
  while (0)

#ifdef COMPAT_FLAG
reset(i) { if (!i) create(); }
#endif
create() {
#ifndef COMPAT_FLAG
  seteuid(getuid());
#endif
  rm(LOGFILE);
  hosts = INETD->query("hosts");
  //TELL_CHEF(sprintf("created with hosts: %O", hosts));
  call_out("query_next_host", 0);
}

restart() { donehosts = ({}); call_out("query_next_host", 0); }

/* the encoding functions are copied from inetd.c - sigh */

private string encode(mixed arg) {
    if (objectp(arg))
	return object_name(arg);
    if (stringp(arg) &&
    (arg[0] == '$' || (string)to_int(arg) == (string)arg))
	return "$" + arg;
    return to_string(arg);
}

private string encode_packet(mapping data) {
    int i;
    mixed indices;
    string header, body, t1, t2, ret;
    int data_flag;

    data_flag = 0;
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
	    ret += DELIMITER + header + ":" + body;
	else
	    ret = header + ":" + body;
    }
    if (ret) {
	if (data_flag)
	    ret += DELIMITER + DATA + ":" + encode(data[DATA]);
	return ret;
    }
}

void query_next_host() {
  string *hostnames;
  string h, err;
  string packet;

  hostnames = m_indices(hosts) - donehosts;
  //TELL_CHEF(sprintf("hostnames: %O", hostnames));
  if (sizeof(hostnames)) {
    h = hostnames[0];
    hostnames = 0;
    donehosts += ({ h });
    if (find_call_out("query_next_host") < 0) call_out("query_next_host", 0);
    /* now send out the query */
    TELL_CHEF("sending query to "+h);
    if (stringp(err = INETD->send_udp(h,
				    ([ REQUEST:QUERY,
				     SENDER:object_name(),
				     DATA:"hosts" ]),
				    1))) {
      TELL_CHEF("send_udp() got "+err);
      /* the packet will always be small enough */
      packet = encode_packet(([ REQUEST:QUERY,
			      SENDER:object_name(),
			      DATA:"hosts",
			      NAME:LOCAL_NAME,
			      UDP_PORT:LOCAL_UDP_PORT,
			      ID:42 ]));
	if (!send_udp(hosts[h][HOST_IP], hosts[h][HOST_UDP_PORT], packet))
	  TELL_CHEF("Error in sending packet.");
    } else
      sent++;
  } else
    TELL_CHEF("not sending request, sent "+sent+" received "+received
              +" timeouts "+timeouts);
}

void udp_reply(mapping data) {
  mixed *new, *mud;
  int i, added;
  string mudname;

  TELL_CHEF(sprintf("got reply, request %O from host %O port %O name %O",
		    data[REQUEST], data[HOST], data["port"], data[NAME]));
  //write_file(LOGFILE, sprintf("got reply: %O\n", data));

  mudname = lower_case(data[NAME]);
  if (data[SYSTEM]) {
    TELL_CHEF(sprintf("got administrational reply %O", data));
    if (TIME_OUT == data[SYSTEM]) {
      timeouts++;
      if (mudname && hosts[mudname]) hosts[mudname][HOST_STATUS] = DOWN;
    }
    return;
  }
  if (mudname && hosts[mudname]) {
    hosts[mudname][HOST_STATUS] = UP;
    if (hosts[mudname][HOST_UDP_PORT] != to_int(data["port"])) {
      TELL_CHEF("got msg from wrong udp port: "+mudname+": old "
		+hosts[mudname][HOST_UDP_PORT]+", new: "+to_int(data["port"]));
    }
  }

  if (QUERY /* ! */ != data[REQUEST]) {
    TELL_CHEF(sprintf("ignoring unknown request type %O", data[REQUEST]));
    return;
  }
  /* add newly received muds to list.
   * TODOwatch careful for truncated lists due to packet size restrictions :-(,
   * check for inconsistencies,
   * eliminate duplicates
   */
  new = map(explode(data[DATA], "\n"),
		  lambda(({'x}), ({ #'explode, 'x, ":" })));
  received++;
  //write_file(LOGFILE, sprintf("new %O\n", new));
  for (i = added = 0; i < sizeof(new); i++) {
    mud = new[i];
    if (sizeof(mud) < 5) {
      TELL_CHEF(sprintf("bad mud entry %O from %O", mud, data[HOST]));
      continue;
    }
    mud[HOST_UDP_PORT] = to_int(mud[HOST_UDP_PORT]);
    mud[LOCAL_COMMANDS] = explode(mud[LOCAL_COMMANDS], ",");
    mud[HOST_COMMANDS] = explode(mud[HOST_COMMANDS], ",");
    /* some sites do not send the mud status */
    if (sizeof(mud) == 5) mud += ({ UNKNOWN });
    else mud[HOST_STATUS] = UNKNOWN;
    mudname = lower_case(mud[HOST_NAME]);
    if (hosts[mudname]) {
      /* consistency checks */
      //write_file(LOGFILE, "mud "+mudname+" already in list\n");
      if (mud[HOST_IP] != hosts[mudname][HOST_IP]) {
        TELL_CHEF("ip number inconsistency for mudname "+mudname+": old "
                  +hosts[mudname][HOST_IP]+"/"+hosts[mudname][HOST_STATUS]
                  +", new: "+mud[HOST_IP]+"/"+mud[HOST_STATUS]);
        if (hosts[mudname][HOST_STATUS] <= 0 && mud[HOST_STATUS] > 0
            && mud[HOST_IP] != "127.0.0.1" /* sigh */) {
	  TELL_CHEF("...updating");
          hosts[mudname][HOST_IP] = mud[HOST_IP];
          hosts[mudname][HOST_STATUS] = mud[HOST_STATUS];
          donehosts -= ({ mudname });
        }
      }
      if (mud[HOST_UDP_PORT] != hosts[mudname][HOST_UDP_PORT]) {
        TELL_CHEF("udp port inconsistency for mudname "+mudname+": old "
                  +hosts[mudname][HOST_UDP_PORT]+", new: "+mud[HOST_UDP_PORT]);
        if (hosts[mudname][HOST_STATUS] <= 0 && mud[HOST_STATUS] > 0
            && mud[HOST_IP] != "127.0.0.1" /* sigh */) {
	  TELL_CHEF("...updating");
          hosts[mudname][HOST_UDP_PORT] = mud[HOST_UDP_PORT];
          hosts[mudname][HOST_STATUS] = mud[HOST_STATUS];
          donehosts -= ({ mudname });
        }
      }
#if 0
      if (implode(mud[LOCAL_COMMANDS], ",")
          != implode(hosts[mudname][LOCAL_COMMANDS], ",")) {
        TELL_CHEF(sprintf("localcmd inconsistency for mudname %O: old %O, new: %O",
                  mudname, hosts[mudname][LOCAL_COMMANDS], mud[LOCAL_COMMANDS]));
      }
#endif
    } else {
      TELL_CHEF("adding mud: "+mudname);
      //write_file(LOGFILE, "adding mud "+mudname+"\n");
      hosts[mudname] = mud;
      added++;
      /* send out a friendly piinnnnggg */
      INETD->send_udp(mudname, ([ REQUEST:PING, SENDER:this_object() ]), 1);
    }
  }
  //walk_mapping(hosts, lambda(({'x}), ({ #'write_file, LOGFILE,
  //                                      ({ #'sprintf, "%O\n",
  //					  ({ #'[, hosts, 'x }) }) }) ));
  //write_file(LOGFILE, sprintf("hosts now: %O\n", hosts));

  if (added) {
    if (find_call_out("query_next_host") < 0) call_out("query_next_host", 0);
  } else
    TELL_CHEF("none added, sent "+sent+" received "+received
              +" timeouts "+timeouts);
}

mapping QueryHosts() { return hosts; }

void dump() {
  string *muds, localcmds;
  int i, t, now;
  
  rm(LOGFILE);
  now = time();
  write_file(LOGFILE, "#\n# Intermud Hosts on "+ctime(now)+".\n#\n");
  write_file(LOGFILE, "# Produced by Pepel's ``inetdhosts'' tool\n#\n");
  write_file(LOGFILE,
             "# queried "+sent+" sites, got "+received+" replies, "
             +timeouts+" timeouts, in all "+sizeof(hosts)+" entries\n#\n");
  for (i = sizeof(muds = sort_array(m_indices(hosts), #'<)); i--;) {
     localcmds = implode(hosts[muds[i]][LOCAL_COMMANDS], ",");
     if ("channel,finger,locate,man,tell,who" == localcmds
         || "channel,finger,ftp,locate,man,tell,who" == localcmds)
       localcmds = "*";
     t = hosts[muds[i]][HOST_STATUS];
     if (t > 0) t = now - t; else if (t < 0) t = now + t;
     write_file(LOGFILE,
		hosts[muds[i]][HOST_NAME]+":"+hosts[muds[i]][HOST_IP]+":"
		+hosts[muds[i]][HOST_UDP_PORT]+":"
		+localcmds+":"
		+"*" ":"
		+t+"\n");
  }
}

