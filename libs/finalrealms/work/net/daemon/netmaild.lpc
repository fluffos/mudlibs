/*
//
//  File    :  /adm/daemons/network/netmail.c
//  Author  :  Inspiral@Tabor
//  Created :  93-12-22
//  Purpose :  To facilitate proper communication between the mailer daemon
//                     and the dns system.
//
//
//  REVISION HISTORY
//  93-12-23   - Added support to mailer daemon.
//  93-12-24   - Added support for data_netmail_file() simul_efun
//
//  16-1-95    - Changed to be used with our wonderous mudlib by Turrican.
//   5-4-95    - Added timeout checking.
//  14-6-95    - Changed the recipient handling a bit, added a bit of
//               security checking.
//
*/

#include <mail.h>
#include <udp.h>

#define init_queue()( out_queue = ({ }) )
#define SAVE_DIR "/net/save/"
#define SAVE_EXTENSION ".o"
#define TIMEOUT 604800

#undef DEBUG

#ifdef DEBUG
#define WHO find_player( "turrican" )
#define TELL( x ) if( WHO ) tell_object( WHO, "NETMAIL: " + x + "\n" )
#else
#define TELL( x )
#endif

mixed * out_queue;

create() {
  seteuid(getuid());
}

mapping check_for_mail(string mudname) {
  init_queue();
  if (file_size( SAVE_DIR + lower_case(mudname) + SAVE_EXTENSION) != -1) {  
    if ( !restore_object( SAVE_DIR + lower_case(mudname)) ) {
      rm( SAVE_DIR + lower_case(mudname) + SAVE_EXTENSION );
      return ([ ]);
    }
  }  
  if( !out_queue )
    init_queue();
  if( sizeof( out_queue ) ) {
    if ((time() - (int)out_queue[0]["TIME"]) >= TIMEOUT) {
      rm ( SAVE_DIR + lower_case(mudname) + SAVE_EXTENSION );
      out_queue[0]["MSG"] = implode(explode(out_queue[0]["MSG"], "\n"), "\n> ");
      MAILER->do_mail_message(out_queue[0]["WIZFROM"],
                "Mail-Server",
                "Returned mail: Failed to deliver.",
                "",
                "Couldn't deliver message for 1 week.\n"
                "Tip: Check if the mud supports mail by typing \"support "+
                mudname+" mail_q\".\n"
                "Unsent message follows: \n"
                "> To: "+out_queue[0]["WIZTO"]+
                "\n> From: "+out_queue[0]["WIZFROM"]+
                "\n> Cc: "+(out_queue[0]["CC"]?out_queue[0]["CC"]:"")+"\n>\n> "+
                out_queue[0]["MSG"]);
      return ([ ]);
    }
    return out_queue[0];
  }
  return ([ ]);
}

int pop_mud(string mudname) {
  init_queue(); 
  mudname = replace(mudname, " ", ".");
  if (file_size(SAVE_DIR + lower_case(mudname) + SAVE_EXTENSION) != -1) { 
    if (!restore_object(SAVE_DIR+lower_case(mudname))) {
      rm(SAVE_DIR+lower_case(mudname) + SAVE_EXTENSION);
      return 0;
    }
  }
  if (!out_queue)
    init_queue();
TELL( sizeof(out_queue) );
  out_queue = out_queue[1..sizeof(out_queue)];
TELL(sizeof(out_queue ) );
  if (!sizeof(out_queue))
    rm(SAVE_DIR+lower_case(mudname) + SAVE_EXTENSION);
  else
    save_object(SAVE_DIR + lower_case(mudname));
  return 1;
}

void bounce_message(mapping mesg, string mudname) {
  MAILER->do_mail_message(mesg["WIZFROM"], "Mail-Server",
                         "Delivery failed: lookup", "",
                         "Failed to lookup MUD: "+mudname+
                         "\nUnsent message follows:\n> To: "+mesg["WIZTO"]+
                         "\n> From: "+mesg["WIZFROM"]+
                         "\n> Cc: "+ (mesg["CC"]?mesg["CC"]:"")+
                         "\n> Subject: "+ mesg["SUBJECT"]+"\n>\n> "+
                         implode(explode(mesg["MSG"], "\n"), "\n> "),
                         1);
}

void push_mail(mapping outmsg) {
  mixed *list;
  int i;

  if (file_name(previous_object())[0..27] != "/obj/handlers/folder_handler") {
    write("NETMAILD: illegal access.\n");
    return;
  }
/* put our mudname behind the sender */
  outmsg["WIZFROM"] = outmsg["WIZFROM"] + "@" + replace(mud_name(), " ", ".");  
/* Used only for housekeeping on our end. */
  outmsg["TIME"] = time();
/* Put our mudname behind any local recipients. */
  i = sizeof(outmsg["WIZTO"]);
  while (i--) {
    if (strsrch(outmsg["WIZTO"][i], "@") < 0)
      outmsg["WIZTO"][i] += "@" + replace(mud_name(), " ", ".");
  }
  outmsg["WIZTO"] = implode(((string *)outmsg["WIZTO"] - ({""})), ",");
/* Put our mudname behind any local recipients. */
  i = sizeof(outmsg["CC"]);
  while (i--) {
    if (strsrch(outmsg["CC"][i], "@") < 0)
      outmsg["CC"][i] += "@" + replace(mud_name(), " ", ".");
  }
  outmsg["CC"] = implode(((string *)outmsg["CC"]-({""})), ",");
  list = outmsg["RECIPIENTS"];
  map_delete(outmsg, "RECIPIENTS");
/* Put our mudname behind any local recipients. */
  i = sizeof(list);
  while (i--) {
    if(!stringp(list[i]))
      list[i] = "";
    sscanf(list[i], "%*s@%s", list[i] );
  }
  list = uniq_array(list);
  list -= ({ replace(mud_name(), " ", ".") });
  list -= ({ replace(lower_case(mud_name()), " ", ".") });
  list -= ({ "" });
  i = sizeof( list );
  while (i--) {
    init_queue();
    list[i] = replace(list[i], " ", ".");
    if (file_size(SAVE_DIR + lower_case(list[i]) + SAVE_EXTENSION) != -1) { 
      if (!restore_object(SAVE_DIR + lower_case(list[i])))
        rm(SAVE_DIR + lower_case(list[i]) + SAVE_EXTENSION);
    }
    if (!out_queue) init_queue();
    if (!NAMESERVER_CD->query_mud_info(list[i])) {
      bounce_message(outmsg, list[i]);
      continue;
    }
    out_queue += ({ outmsg });
    save_object(SAVE_DIR + lower_case(list[i]));
    TELL("Saved to " + list[i] + ".o");
    (UDP_PATH+"mail_q")->check_for_mail(list[i], 3);
  }
}

int incoming_mail( mapping info ) {
  string name, mud;

  if (file_name(previous_object())[0..14] != "/net/udp/mail_q") {
    write("NETMAILD: illegal access.\n");
    return 0;
  }
/* Convert intermud format to our mailer's format. */
  if (info["CC"] && info["CC"] != ({ }))
    info["CC"] = replace(implode(info["CC"], ","), ".", " ");
  else
    info["CC"] = "";  
  if (!info["WIZTO"] || info["WIZTO"] == ({ }))
    return 0;
  info["WIZTO"] = replace(implode(info["WIZTO"], ","), ".", " ");
  MAILER-> do_mail_message((string)info["WIZTO"], 
                           (string)info["WIZFROM"],
                           (string)info["SUBJECT"], 
                           (string)info["CC"],
                           (string)info["MSG"]);
  return 1;
}

/* EOF */
