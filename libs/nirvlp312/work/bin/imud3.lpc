/*
 * Intermud 3 commands daemon written by Fafnir 1998
 * (C) Evermore 1998
 */

#include <grammar.h>
#include <is_wizard.h>
#include <imud3.h>
#include <kernel.h>
#include <server.h>
#include <intermud.h>

inherit "basic/create";
inherit "basic/parser";
inherit "basic/daemon";

inherit ACCESS;

void create() {
#ifdef INTERMUD3
  add_rule("iremote who "G_MUD_NAME,            "who");
  add_rule("iremote finger "G_REMOTE_RESOURCE,  "finger");
  add_rule("iremote mudlist",                   "mudlist");
  add_rule("iremote mudinfo "G_MUD_NAME,        "mudinfo");
  add_rule("iremote locate "G_WORD,             "locate");

  if (is_wizard(this_player()) ||
      is_wizard(this_player(), IW_TOOLUSER)) {
    add_rule("iremote chanlist",                        "chanlist");
    add_rule("iremote ls "G_REMOTE_RESOURCE,            "ls");
    add_rule("iremote cp "G_REMOTE_RESOURCE" "G_TEXT,   "cpfrom");
    add_rule("iremote cp "G_TEXT" "G_REMOTE_RESOURCE,   "cpto");
    add_rule("iremote addchannel "G_WORD" "G_NUMBER,    "addchannel");
    add_rule("iremote remchannel "G_WORD,               "remchannel");
    add_rule("iremote addmud "G_WORD" "G_MUD_NAME,      "addmud");
    add_rule("iremote remmud "G_WORD" "G_MUD_NAME,      "remmud");
    add_rule("iremote mudservice "G_WORD,               "mudservice");
    add_rule("iremote won "G_WORD,                      "won");
    add_rule("iremote woff "G_WORD,                     "woff");
    add_rule("iremote "G_TEXT,                          "wiz_shout");
  }

  add_rule("iremote",   "ir_help");

  filter(query_rule_verbs(),
    lambda(({ 'v }), ({ #'add_command, "parse_cmd", 'v })));
  
  set_privilege(1);
#endif
}

int parse_cmd(string arg,string verb) {
  return parse_sentence(arg ? verb + " " + arg : verb);
}

status do_action(string v,mapping a) {
  closure cl;

  if (!check_previous_privilege(1)) {
    switch (v) {
      case "addchannel":
      case "remchannel":
      case "addmud":
      case "remmud":
        return 0;
      default:
    }
  }
   
  if (!is_wizard(this_player())) {
    switch (v) {
      case "chanlist":
      case "ls":
      case "cpfrom":
      case "cpto":
        return 0;
      default:
    }
  }

  if (!(cl = symbol_function("act_"+v, this_object())))
    return 0;
  return funcall(cl, a);
}

status check(int r,string s) {
  switch(r) {
    case 0:
      write("Request '"+s+"' doesn't seem to be supported.\n");
      return 1;
    case 1:
      return 1;
    case -1:
      write("Unknown MUD.\n");
      return 1;
   }
  return 0;
}

int act_won(mapping args) {
  this_player()->switch_on_protocol_for_channel(args[G_WORD], INTERMUD_3);
  return 1;
}

int act_woff(mapping args) {
  this_player()->switch_off_protocol_for_channel(args[G_WORD], INTERMUD_3);
  return 1;
}

int act_wiz_shout(mapping args) {
  mixed h;
  string chan, mud;
  int emote;

  if (strlen(args[G_TEXT]) < 4 ||
      args[G_TEXT][0..2] != "wiz")
    return 0;
  switch (args[G_TEXT][3]) {
  case '?':
    if (strlen(args[G_TEXT]) < 5)
      return notify_fail("Give a channel.\n"), 0;
    chan = args[G_TEXT][4..];
    h = explode(chan, "@");
    chan = h[0];
    if (sizeof(h) == 2) {
      mud = h[1];
      mud = IMUD3->get_mud_name(mud);
      if (!mud)
        return notify_fail("No mud of such name.\n"), 0;
    }
    else
      mud = 0;
    // regarding to the specs, 'mud==0' is not supported. Indeed, the router
    // supports such a query, making a broadcast query to all muds
    if ((IMUD3->query_channels())[chan])
      IMUD3"/channel"->send_channel_who_request(chan, mud);
    else
      return notify_fail("No such intermud3 channel.\n"), 0;
    break;
  case ':':
    emote = 1;  // fall through
  case '!':
    if (strlen(args[G_TEXT]) < 5)
      return notify_fail("Give a channel.\n"), 0;
    chan = args[G_TEXT][4..];
    h = explode(chan, " ");
    if (sizeof(h) < 2 || h[0] == "")
      if (chan[0] == ' ')
        return notify_fail("Give a channel.\n"), 0;
      else
        return notify_fail("Give a message.\n"), 0;
    chan = h[0];
    h = implode(h[1..], " ");
    if (strlen(h) < 1)
      return notify_fail("Give a message.\n"), 0;
    if (!(IMUD3->query_channels())[chan])
      return notify_fail("No such intermud3 channel.\n"), 0;
    if (emote) {
      if (strlen(h) > 3 && h[0..2] == "'s ")
        IMUD3"/channel"->send_channel_emote(chan, "$N" + h);
      else
        IMUD3"/channel"->send_channel_emote(chan, "$N " + h);
    } else {
      return "bin/soul"->wizline(h, chan, INTERMUD_3);
    }
    break;
  default:
    if (strlen(args[G_TEXT]) < 4)
      return notify_fail("Give a channel.\n"), 0;
    chan = args[G_TEXT][3..];
    h = explode(chan, " ");
    if (sizeof(h) < 2)
      return notify_fail("Give a message.\n"), 0;
    chan = h[0];
    h = implode(h[1..], " ");
    if (strlen(h) < 1)
      return notify_fail("Give a message.\n"), 0;
    IMUD3"/channel"->send_channel_message(chan, h);
    return 1;
  }
  return 1;
}

status act_who(mapping args) {
#if 0  // Coogan, 20-Feb-2002
  return check(IMUD3->send_who_request(args[G_MUD_NAME]),"who");
#else
  SE_INTERMUD->send_request("who", args[G_MUD_NAME], 0, INTERMUD_3);
  return 1;
#endif
}

status act_finger(mapping args) {
#if 0  // Coogan, 20-Feb-2002
  return check(IMUD3->send_finger_request(
    args[G_REMOTE_RESOURCE,1],
    args[G_REMOTE_RESOURCE]),"finger");
#else
  SE_INTERMUD->send_request("finger", args[G_REMOTE_RESOURCE],
                            args[G_REMOTE_RESOURCE,1], INTERMUD_3);
  return 1;
#endif
}

status act_mudlist(mapping a)
{
  mapping h;

  this_player()->view_text(
  implode(map(sort_array(m_indices(h = IMUD3->query_muds()),#'>),
    lambda(({'x}),({#'sprintf,"%-25s %16s %5d %s\n",'x,
	  ({#'[,({#'[,h,'x}),I3_ML_IPADDR}),({#'[,({#'[,h,'x}),I3_ML_PPORT}),
	  ({#'?,({#'<,({#'=,'st,({#'[,({#'[,h,'x}),I3_ML_STATE})}),0 }),
	    "UP",({#'+,"DOWN ",({#'?,'st,({#'+,"for further ",({#'+,
          ({#'to_string,'st})," seconds"})}),"(unknown)"})})})}))),""),
    "Mud list");
  this_player()->start_view();
  return 1;
}

status act_mudservice(mapping a)
{
  string *h;

  h = sort_array(m_indices(IMUD3->query_muds_per_service(a[G_WORD])),#'>);
  this_player()->view_text(implode(h,"\n"),"Mud list per service");
  this_player()->start_view();
  return 1;
}

status act_mudinfo(mapping a)
{
  mixed *h;
  string s;
  
  h = IMUD3->query_mud_info(a[G_MUD_NAME]);

  s  = sprintf("MUD name    : %s\n",a[G_MUD_NAME])
      +sprintf("IP Address  : %s\n",h[I3_ML_IPADDR])
      +sprintf("Player Port : %d\n",h[I3_ML_PPORT])
      +sprintf("MUDLib      : %s\n",h[I3_ML_MUDLIB])
      +sprintf("Driver      : %s\n",h[I3_ML_DRIVER])
      +sprintf("State       : %s\n",h[I3_ML_OPENSTATE])
      +sprintf("Admin EMail : %s\n",h[I3_ML_ADMINEMAIL])
      +sprintf("Services    : %s\n",break_string(make_list(m_indices(h[I3_ML_SERVICES]))+".",0,14,1));
  this_player()->view_text(s,"Mud info");
  this_player()->start_view();
  return 1;
}

status act_ls(mapping a)
{
  string name;

  name = a[G_REMOTE_RESOURCE,1];
  if(!name || name == "")
    name = "/";
  return check(IMUD3"/file"->send_file_list_request(a[G_REMOTE_RESOURCE],name),"file list");
}

int act_cpfrom(mapping a) {
  return check(IMUD3"/file"->send_file_get_request(a[G_REMOTE_RESOURCE],
                                            a[G_REMOTE_RESOURCE,1],a[G_TEXT]),
               "file get");
}

status act_cpto(mapping a) {
  string contents;
  string lfname;
  
  contents = read_file(lfname = __MASTER_OBJECT__->normalize_path(a[G_TEXT],
                                                               this_player()));
  if(!contents)
    return notify_fail("File not found.\n"), 0;
  return check(IMUD3"/file"->send_file_put_request(a[G_REMOTE_RESOURCE,1],
                                            a[G_REMOTE_RESOURCE],
                                            contents, lfname),
               "file put");
}

status act_chanlist() {
  mixed h;
  string s;
  
  h = IMUD3->query_channels();
#if 1  // Alfe 2007-Sep-27
  h = filter_indices(h, #'stringp);  // ignore entries with non-string keys
  h = map(sort_array(m_indices(h), #'>),
          (:
           if (!pointerp($2[$1])) return "";
           return sprintf("%'.'-25s %'.'-30s %s\n",
                          $1,
                          $2[$1][0][0..29],
                          ([ 0: "selectively banned",
                             1: "selectively admitted",
                             2: "administered" ])[$2[$1][1]]); :), h);
  s = implode(h, "");
#else
  s = implode(map(sort_array(m_indices(h),#'>),
    lambda(({'x}),({
      #'sprintf,
      "%'.'-15s %'.'-20s %s\n",
      'x,
      ({#'[..],
        ({#'[,
          ({#'[,h,'x}),
          0
        }),
        0, 19
      }),
      ({#'?,
        ({#'==,
          ({#'=,'st,
            ({#'[,
              ({#'[,h,'x}),
              1
            })
          }),
          0
        }),
	"selectively banned",
	({#'==,'st,1}),
	"selectively admitted",
	({#'==,'st,2}),
	"administered"
      })
    }))),"");
#endif
  this_player()->view_text(s,"Channel list");
  this_player()->start_view();
  return 1;
}

status act_locate(mapping a) {
  IMUD3"/locate"->send_locate_request(a[G_WORD]);
  return 1;
}

status act_ir_help() {
  string s;

  s =
"\n"
"iremote mudlist\n"
"    - shows you a list of all remote MUDs and their state.\n\n"
"iremote mudinfo <mud>\n"
"    - shows you information about a given MUD.\n\n"
"iremote who <mud>\n"
"    - lists visible players in a given MUD.\n\n"
"iremote finger <name>@<mud>\n"
"    - gives back some information about a particular user in that MUD.\n\n"
"iremote locate <name>\n"
"    - searches all connected MUDs for a user having that name.\n\n";

  if(is_wizard(this_player())) s+=

"\nAs a wizard you have some more commands:\n\n"
"iremote chanlist\n"
"    - shows you a list of the InterMUD channels.\n\n"
"iremote ls <path>@<mud>\n"
"    - gives you a file list of the directory in that MUD.\n\n"
"iremote cp <local_file> <remote_file>@<mud>\n"
"    - copies a local file to a remote MUD.\n\n"
"iremote cp <remote_file>@<mud> <local_file>\n"
"    - copies a file from a remote MUD to a local file.\n"
"      Overwriting is disallowed, use rm if needed.\n\n"
"iremote addchannel <name> <mode>\n"
"    - adds an intermud channel with the given mode number.\n\n"
"iremote remchannel <name>\n"
"    - remotes a previously added intermud channel.\n\n"
"iremote addmud <channel> <mudname>\n"
"    - adds a mud to the banned/admitted list.\n\n"
"iremote remmud <channel> <mudname>\n"
"    - removes a mud from the banned/admitted list.\n\n"
"iremote wiz?<channel>[@<mudname>]\n"
"    - queries for all listeners of a channel resp. the listeners\n"
"      of a channel on a particular mud\n\n"
"iremote wiz:<channel> <emote>\n"
"    - sends a channel emote\n\n"
"iremote wiz!<channel> <feeling>\n"
"    - sends a channel feeling, even a targetted one to a person \n"
"      on another mud (e.g. iremote wiz!german nod coogan@tubmud)\n\n"
"iremote wiz<channel> <message>\n"
"    - sends a channel message\n\n"
"iremote won|woff <channel>\n"
"    - lets one un/listen to a channel (the listening may be restricted\n"
"      by the mud who created the channel)\n\n";

  this_player()->view_text(s,"iremote help");
  this_player()->start_view();
  return 1;
}

string check_channel(string channel)
{
  mixed h;

  if(!(h = (IMUD3->query_channels())[channel]))
    return "Channel not found.";
  if(h[0] != MUDNAME)
    return "Channel not created by " + MUDNAME + ".";
  return 0;
}

void act_addchannel(mapping a)
{
  if(check_channel(a[G_WORD]) != "Channel not found.")
   {
    write("Channel already exists.\n");
    return;
   }
  if(a[G_NUMBER] < 0 || a[G_NUMBER] > 1)
   {
    write("Use 0 (selectively banned) or 1 (selectively admitted).\n");
    return;
   }
   
  IMUD3"/channel"->send_channel_add(a[G_WORD],a[G_NUMBER]);
  return;
}

void act_remchannel(mapping a)
{
  string s;

  if(s = check_channel(a[G_WORD]))
   {
    write(s+"\n");
    return;
   }
  IMUD3"/channel"->send_channel_remove(a[G_WORD]);
  return;
}

status act_addmud(mapping a)
{
  string s;

  if(a[G_MUD_NAME] == MUDNAME) return 0;
  if(s = check_channel(a[G_WORD]))
   {
    write(s+"\n");
    return 1;
   }
  IMUD3"/channel"->send_channel_administer(a[G_WORD],({a[G_MUD_NAME]}),({}));
  return 1;
}

status act_remmud(mapping a)
{
  string s;

  if(a[G_MUD_NAME] == MUDNAME) return 0;
  if(s = check_channel(a[G_WORD]))
   {
    write(s+"\n");
    return 1;
   }
  IMUD3"/channel"->send_channel_administer(a[G_WORD],({}),({a[G_MUD_NAME]}));
  return 1;
}

