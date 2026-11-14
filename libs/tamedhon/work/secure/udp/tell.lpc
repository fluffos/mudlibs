/* Tamedhon MUDlib
 *
 * /secure/udp/tell.c -- UDP tell handling
 *
 * $Date: 2003/07/05 14:20:00 $
 * $Revision: 1.5 $
 * $Log: tell.c,v $
 * Revision 1.5  2003/07/05 14:20:00  Querolin
 * nirgendwofinden -> nirgendwo finden 
 *
 * Revision 1.4  1997/11/05 20:10:23  Feyaria
 * silberland -> mudname
 *
 * Revision 1.2  1997/06/25 10:57:36  Woody
 * Message() updated, AddToTellHist() raus
 *
 * Revision 1.1  1997/03/16 00:26:36  Woody
 * prepared for revision control
 *
 * Revision 1.0a  1997/01/06  Woody
 * AWAY richtig handlen, AddToTellHist Aufruf angepasst
 *
 * Revision 1.0   1996/11/17  Woody
 * Teilemit-History bei teile-mits erweitern
 *
 */

#include <udp.h>
#include <properties.h>
#include <config.h>

#ifdef ZEBEDEE
#include <system.h>
inherit "/sys/format";
#elif !defined(INETD)
#define INETD	"/secure/inetd"
#endif


void udp_tell(mapping data) {
  object ob;
  string message_string, message_prefix;
  int i,re;
  string *message_array;

  if (data[RECIPIENT] && (ob = find_player(lower_case(data[RECIPIENT]))) &&
      interactive(ob)) {
    data[SENDER]=
      implode(filter(efun::explode(data[SENDER], ""), #'>=, " "), "");//'))
    data[DATA]=
      implode(filter(efun::explode(data[DATA], ""), #'>=, " "), "");//'))
    message_prefix=capitalize(data[SENDER])+"@"+data[NAME]+" teilt Dir mit: ";
    message_array=explode(
        break_string(data[DATA],79-sizeof(message_prefix)),"\n");
    message_string="";
    for (i=0;i<sizeof(message_array);i++)
    {
      if (!message_array[i]) 
	message_array[i]="";
      message_string += message_prefix + message_array[i] + "\n";
    }
    re = ob->Message("\n"+message_string, MSGFLAG_RTELL);

    if (!ob->QueryProp(P_INVIS))
    {
      message_prefix="Du teilst "+capitalize(data[RECIPIENT]) + "@" + 
	LOCAL_NAME + " mit: ";
      message_array=explode(break_string(data[DATA],79-sizeof(message_prefix)),"\n");
      message_string="";
      for (i=0;i<sizeof(message_array);i++)
      {
	if (!message_array[i])
	  message_array[i]="";
	message_string=message_string+message_prefix+message_array[i]+"\n";
      }
      if(ob->QueryProp(P_AWAY))
	message_string=sprintf("%s%s@"+MUDNAME+" ist gerade nicht da: %s\n",
            message_string,ob->name(WER),ob->QueryProp(P_AWAY));
      else switch(re) {
        case MESSAGE_CACHE:
          message_string +=
            sprintf("%s@"+MUDNAME+" möchte gerade nicht gestört werden.\n"
                "Die Mitteilung wurde von einem kleinen Kobold in Empfang "
                "genommen.\nEr wird sie später weiterleiten.\n",
                capitalize(getuid(ob)));
          break;
        case MESSAGE_CACHE_FULL:
          message_string +=
            sprintf("%s@"+MUDNAME+" möchte gerade nicht gestört werden.\n"
                "Die Mittelung ging verloren, denn der Kobold kann sich "
                "nichts mehr merken.\n", capitalize(getuid(ob)));
          break;
        case MESSAGE_DEAF:
          message_string +=
            sprintf("%s@"+MUDNAME+" ist momentan leider taub.\n",
                    capitalize(getuid(ob)));
          break;
        case MESSAGE_IGNORE_YOU:
          message_string +=
            sprintf("%s@"+MUDNAME+" ignoriert Dich.\n",
                    capitalize(getuid(ob)));
          break;
        case MESSAGE_IGNORE_MUD:
          message_string +=
            sprintf("%s@"+MUDNAME+" ignoriert das Mud '%s'.\n",
                    capitalize(getuid(ob)), data[NAME]);
          break;
      }
    } else
      message_string="Merlin@"+MUDNAME+" teilt Dir mit: Spieler "+
        capitalize(data[RECIPIENT])+" kann ich leider nirgendwo finden!\n";
    INETD->send_udp(data[NAME], ([
				  REQUEST: REPLY,
				  RECIPIENT: data[SENDER],
				  ID: data[ID],
				  DATA: "\n"+message_string
				  ]) );   
  }
  else
    INETD->send_udp(data[NAME], ([
				  REQUEST: REPLY,
				  RECIPIENT: data[SENDER],
				  ID: data[ID],
				  DATA:
      sprintf("\nMerlin@"+MUDNAME+": Spieler %s kann ich leider nirgendwo "
              "finden!\n",capitalize(data[RECIPIENT]))
				  ]) );
}
