/*
 * intermud.c - a server providing an interface for intermud communication
 * regardless of the intermud protocol of the particular target muds.
 * It is used by bin/intermud, bin/remote, bin/imud3.
 *
 * Coogan, Jan-May 2002
 *
 */

#pragma strong_types

#include <assert.h>
#include <udp.h>
#include <imud3.h>
#include <intermud.h>
#include <message.h>

#define MUDS_LINE "%-25.25s %|6s %-13s %-15s %4s\n"

private string last_mud_referenced;
private string last_mud_referenced_returned;
private int    last_mud_referenced_protocol;

varargs string get_mud_name(string mud, int i2_last) {
  string mud_name_2, mud_name_3;

  if (mud == last_mud_referenced ||
      mud == last_mud_referenced_returned)
    return last_mud_referenced_returned;

  // in normal cases, we prefer intermud2. For the soul, intermud3.
  last_mud_referenced = mud;
  last_mud_referenced_returned = 0;
  last_mud_referenced_protocol = 0;
  mud_name_2 = INETD->get_mud_name(mud);
  mud_name_3 = IMUD3->get_mud_name(mud);
  if (i2_last && mud_name_3) {
    last_mud_referenced_protocol = INTERMUD_3;
    return (last_mud_referenced_returned = mud_name_3);
  }
  if (mud_name_2) {
    last_mud_referenced_protocol = INTERMUD_2;
    return (last_mud_referenced_returned = mud_name_2);
  }
  if (mud_name_3) {
    last_mud_referenced_protocol = INTERMUD_3;
    return (last_mud_referenced_returned = mud_name_3);
  }
  return 0;
}

int get_mud_protocol(string mud) {
  if (mud != last_mud_referenced &&
      mud != last_mud_referenced_returned)
    get_mud_name(mud);
  return last_mud_referenced_protocol;
}

int* get_mud_status(string mud_name, string service, int protocol) {
  mixed *mud_status;
  mixed *mud_info;

  mud_status = ({ 0, 0, 0 });
  switch (protocol) {
  case INTERMUD_2:
    if (service == "emoteto")  // exception.
      service = "tell";
    if ((mud_name = INETD->get_mud_name(mud_name))) {
      mud_status[IM_MUD_KNOWN] = mud_name;
      mud_info = INETD->query_mud_info(mud_name);
      if ((mud_status[IM_MUD_UP] = (mud_info[HOST_STATUS] > 0)))
        if ((sizeof(mud_info[HOST_COMMANDS]) == 1 &&
             mud_info[HOST_COMMANDS][0] == "*") ||
            sizeof((mud_info[HOST_COMMANDS][HOST_COMMANDS] &
                    ({ service })) & mud_info[LOCAL_COMMANDS]) == 1)
          mud_status[IM_SERVICE_SUPPORTED] = 1;
    }
    break;
  case INTERMUD_3:
    if ((mud_name = IMUD3->get_mud_name(mud_name))) {
      mud_status[IM_MUD_KNOWN] = mud_name;
      mud_info = IMUD3->query_mud_info(mud_name);
      if ((mud_status[IM_MUD_UP] = (mud_info[I3_ML_STATE] == -1)))
        mud_status[IM_SERVICE_SUPPORTED] = mud_info[I3_ML_SERVICES][service];
    }
    break;
  }
  return mud_status;
}

string get_intermud_error_message(string mud, int *i2, int *i3, string service){
//  debug("coogan", ({ i2, i3 }));
  if (!i2[IM_MUD_KNOWN]) {
    if (!i3[IM_MUD_KNOWN])
      return "This mud is either unknown or doesn't support intermud3 at all.";
    if (!i3[IM_MUD_UP])
      return mud + " is currently marked as down.";
    if (!i3[IM_SERVICE_SUPPORTED])
      return mud + " doesn't support \"" + service + "\" requests.";
    return 0;
  }
  if (!i2[IM_MUD_UP]) {
    if (!i3[IM_MUD_KNOWN] || !i3[IM_MUD_UP])
      return mud + " is currently marked as down.";
    if (!i3[IM_SERVICE_SUPPORTED])
      return mud + " doesn't support \"" + service + "\" requests.";
    return 0;
  }
  if (!i2[IM_SERVICE_SUPPORTED]) {
    // Intermud2 was the most successful try (even not completely, too)
    return mud + " doesn't support \"" + service + "\" requests.";
  }
  return 0;  // Coogan, 26-Mar-2011
}

varargs mixed send_request(string service, string mud_name, mixed args,
                           int protocol, object agent) {
  string mud;
  mixed *mud_status_2, *mud_status_3;
  int gemote;

  agent = agent || this_player();
  assert(agent);

// DEBUG_POINT("coogan", ({ service, mud_name, args, protocol }));  
  mud_status_2 = allocate(3);
  mud_status_3 = allocate(3);

  switch (service) {
  case "who":
  case "finger":
  case "emoteto":
  case "tell":
    break;
  default:
    tell_object(agent, "This service is not supported by SE_INTERMUD yet.\n");
    return;
  }

  mud = INETD->get_mud_name(mud_name);
  if (mud)
    mud_status_2 = get_mud_status(mud, service, INTERMUD_2);
  mud_status_3 = get_mud_status(mud_name, service, INTERMUD_3);

// DEBUG_POINT_TP("coogan", ({ mud, protocol, mud_status_2, mud_status_3 }));

  // test for exceptions
  if (service == "emoteto"       &&     // for emoteto,
      !protocol                  &&     // when no protocol is specified,
      mud_status_2[IM_MUD_KNOWN] &&     // and mud supports both I2
      mud_status_3[IM_MUD_KNOWN] &&     // and I3,
      mud_status_3[IM_MUD_UP]    &&     // and I3 is up,
      mud_status_3[IM_SERVICE_SUPPORTED]  // and supports I3-emoteto
      && lower_case(mud) != "finalfrontier"
    )
    protocol = INTERMUD_3;      // set this fix to prevent i2-emotetos, where
                                // the cleaner i3 is possible.
  if (!protocol || protocol == INTERMUD_2) {
    mud = INETD->get_mud_name(mud_name);
    if (mud)
      mud_status_2  = get_mud_status(mud, service, INTERMUD_2);
    if (mud_status_2[IM_MUD_KNOWN] &&
        mud_status_2[IM_MUD_UP] &&
        mud_status_2[IM_SERVICE_SUPPORTED]) {
      switch (service) {
      case "who":
        send_message(({ M_TARGETS, agent,
                        "Who request sent to mud \""+
                        mud_status_2[IM_MUD_KNOWN] +"\"." }));
        INETD->do_send_udp(mud,
                           ([ REQUEST: service, 
                              SENDER : agent->query_vis_name(),
                              DATA   : args && lower_case(args),
                           ]), 1);
        return;
      case "finger":
        send_message(({ M_TARGETS, agent, 
                        "Finger request for \"" + args + "\" sent to mud \"" +
                        mud_status_2[IM_MUD_KNOWN] +"\"." }));
        INETD->do_send_udp(mud,
                           ([ REQUEST: service,
                              SENDER : agent->query_vis_name(),
                              DATA   : lower_case(args),
                           ]), 1);
        return;
      case "emoteto":
        // args == ({ name, emote-string })
        assert(pointerp(args) && sizeof(args) == 2);
        send_message(({ M_TARGETS, agent,
                        "Emote sent to " + args[0] + "@" +
                        mud_status_2[IM_MUD_KNOWN] + "." }));
        gemote = 0;
        if (strlen(args[1]) > 3 && args[1][0..2] == "'s ") {
          gemote = 1;
          args[1] = args[1][3..];
        }
        args[1] = "*" + args[1] + "* ";
        INETD->do_send_udp(mud,
                           ([ REQUEST: "tell",
                              SENDER : agent->query_vis_name(),
                              RECIPIENT: lower_case(args[0]),
                              METHOD : (gemote ? "gemote" : "emote"),
                              DATA   : args[1],
                           ]), 1);
        return;
      case "tell":
        // args == ({ name, tell-string, adverbs })
        assert(pointerp(args) && sizeof(args) > 1);
        send_message(({ M_TARGETS, agent,
                        "Tell sent to " + args[0] + "@" +
                        mud_status_2[IM_MUD_KNOWN] + "." }));
        if (sizeof(args) == 3 && args[2])
          args[1] = "*" + args[2] + "* " + args[1];
        INETD->do_send_udp(mud,
                           ([ REQUEST: "tell",
                              SENDER : agent->query_vis_name(),
                              RECIPIENT: lower_case(args[0]),
                              METHOD : (sizeof(args) == 3 && args[2])
                                       ? "adverb" : "tell",
                              DATA   : args[1],
                           ]), 1);
        return;
      }
    }
  }

  if (!protocol || protocol == INTERMUD_3) {
    mud_status_3 = get_mud_status(mud_name, service, INTERMUD_3);
    if (mud_status_3[IM_MUD_KNOWN] &&
        mud_status_3[IM_MUD_UP] &&
        mud_status_3[IM_SERVICE_SUPPORTED]) {
      switch (service) {
      case "who":
        send_message(({ M_TARGETS, agent,
                        "Who request sent to mud \"" +
                        mud_status_3[IM_MUD_KNOWN] + "\"." }));
        IMUD3"/who"->send_who_request(mud_name);
        return;
      case "finger":
        send_message(({ M_TARGETS, agent,  
                        "Finger request for \"" + args + "\" sent to mud \"" + 
                        mud_status_3[IM_MUD_KNOWN] +"\"." }));
        IMUD3"/finger"->send_finger_request(args, mud_name);
        return;
      case "emoteto":
        // args == ({ name, emote-string })
        assert(pointerp(args) && sizeof(args) == 2);
        send_message(({ M_TARGETS, agent,
                        "Emote sent to " + args[0] + "@" +
                        mud_status_3[IM_MUD_KNOWN] + "." }));
        IMUD3"/emoteto"->send_emoteto(args[0], mud_name, args[1]);
        return 1;
      case "tell":
        // args == ({ name, tell-string, adverbs })
        assert(pointerp(args) && sizeof(args) > 1);
        send_message(({ M_TARGETS, agent,
                        "Tell sent to " + args[0] + "@" +
                        mud_status_3[IM_MUD_KNOWN] + "." }));
        if (sizeof(args) == 3 && args[2])
          args[1] = "*" + args[2] + "* " + args[1];
        IMUD3"/tell"->send_tell(args[0], mud_name, args[1]);
        return 1;
      }
    }
  }
  send_message(({ M_TARGETS, agent,
                  get_intermud_error_message(mud_name, mud_status_2,
                                             mud_status_3, service) }));
  return 0;  // Coogan, 26-Mar-2011
}   

varargs string get_mud_list(int protocol) {
  mapping i2m, i3m;
  string *muds, result, mud_lc;
  int i, sm;

  if (!protocol || protocol == INTERMUD_2) {
    i2m = INETD->query("hosts");
  } else
    i2m = ([ ]);

  if (!protocol || protocol == INTERMUD_3) {
    i3m = IMUD3->query_muds();
  } else
    i3m = ([ ]);

  muds = sort_array(map(m_indices(i2m), #'capitalize) + m_indices(i3m), #'>);

  result = sprintf(MUDS_LINE,
                   "Mudname", "Status", "Last access", "Host", "Port");
  result += sprintf("%'-'*s\n",strlen(result)-1,"");

  if (!sizeof(muds)) {
    result += "There are no known muds.\n";
    return result;
  }

  sm = sizeof(muds);

  for (i = 0; i < sm; i++) {
    mud_lc = lower_case(muds[i]);          // i2m has no capitalised keys
    if (i < sm-1 && muds[i] == muds[i+1])  // for muds supporting both,
      mud_lc = muds[i];                    // choose i3 first.
    if (i2m[mud_lc]) {
      if (i2m[mud_lc][HOST_STATUS] > 0)
        result += sprintf(MUDS_LINE,
                          i2m[mud_lc][HOST_NAME],  // name
                          "UP",  // status
                          ctime(i2m[mud_lc][HOST_STATUS])[4..15],  // time
                          i2m[mud_lc][HOST_IP],  // host
                          to_string(i2m[mud_lc][HOST_UDP_PORT]));  // port
      else if (i2m[mud_lc][HOST_STATUS] < 0)
        result += sprintf(MUDS_LINE,
                          i2m[mud_lc][HOST_NAME],  // name
                          "DOWN",  // status
                          ctime(-i2m[mud_lc][HOST_STATUS])[4..15],  // time
                          i2m[mud_lc][HOST_IP],  // host
                          to_string(i2m[mud_lc][HOST_UDP_PORT]));  // port
      else
        result += sprintf(MUDS_LINE,
                          i2m[mud_lc][HOST_NAME],  // name
                          "UNKNOWN",  // status
                          "Never accessed.",  // time
                          i2m[mud_lc][HOST_IP],  // host
                          to_string(i2m[mud_lc][HOST_UDP_PORT]));  // port
    } else if (i3m[muds[i]]) {
      result += sprintf(MUDS_LINE,
                        muds[i],  // name
                        (i3m[muds[i]][I3_ML_STATE] < 0
                         ? "UP" : "DOWN"),  // status
                        "intermud3",  // time
                        i3m[muds[i]][I3_ML_IPADDR],  // host
                        to_string(i3m[muds[i]][I3_ML_PPORT]));  // port
    }
    else
      result += muds[i] + "\n";
  }
  return result;
}

