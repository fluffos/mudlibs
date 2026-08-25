/* Hamlet threw me together, August 1996.
   I bind to a port of choice and give a who list whenever someone telnets
     there.
   Bits of it are scavenged from the ftpd by Bannor, Pinkfish, Pinkfish,
     Turrican and Turrican.
*/

#include <socket.h>
#include <socket_errors.h>

#include <network.h>

#define LOGFILE "who.server"
#define WHOPORT 4090

/* If it's to act as a sort of web page, we want a head and a tail file.
   If WWW is undefined, the rest is ignored.
*/
#define WWW
#define WWW_TEMPLATE  "/net/config/template.html"
#define WWW_HEADING   "</pre><H3><B>"
#define WWW_UNHEADING "</b></h3><PRE>"

#define SORTED_ORDER ({ "G", "D", "H", "T", "P", "C", " " })
#define TRANS ([ "G" : "God"    , "D" : "Demigod" , "H" : "Alchemist" \
                ,"T" : "Thane"  , "P" : "Patron"  , "C" : "Creator"   \
                ," " : "Player"                                       \
              ])
#define SHOW_PLAYERS

/* Next one waits for a newline before closing connection if defined. */
#undef PAUSE

#define NL "\r\n"

string build_wholist(int web);
mapping sort_players();

void create() {
  call_out("start_whoserver",2, WHOPORT);
}

int our_socket;

void start_whoserver(int port)
{
  our_socket = socket_create(STREAM, "in_read_callback", "in_close_callback");
  if (our_socket < 0)
  {
    log_file(LOGFILE,ctime(time())+": Failed to create socket.\n");
    return;
  }
  if (socket_bind(our_socket, port) < 0)
  {
    log_file(LOGFILE,ctime(time())+": Failed to bind socket.\n");
    socket_close(our_socket);
    return;
  }
  if (socket_listen(our_socket, "in_listen_callback") < 0)
  {
    log_file(LOGFILE,ctime(time())+": Failed to listen to socket.\n");
    return;
  }
}      /* start_whoserver */

void  in_listen_callback(int fd)
{
  int new_fd;
  string response;

  if ((new_fd = socket_accept(fd, "in_read_callback",
                                  "in_write_callback")) < 0)  {
    return;
  }


#ifdef WWW
  response = read_file(WWW_TEMPLATE);
  response = replace_string(response, "[TEXT]", build_wholist(1));
#else
  response = build_wholist(0);
#endif

  if(NL != "\n")
    response = replace_string(response, "\n", NL);

#ifdef PAUSE
  response += "               <Press return to exit this display>";
#endif

  socket_write(new_fd, response);

#ifndef PAUSE
  socket_close(new_fd);
#endif
}      /* in_listen_callback() */


void  in_read_callback(int fd, string str)
{
  socket_close(fd);
}      /* in_read_callback() */

void  in_close_callback(int fd)
{
  socket_close(fd);
}      /* in_close_callback() */

string build_wholist(int web) {
  string output = "\n";
  mapping mapdata;
  int i;

  mapdata = sort_players();

  for(i=0;i<sizeof(SORTED_ORDER);i++)
    if(mapdata[SORTED_ORDER[i]]) {
      if(web)
        output += WWW_HEADING;
      output += TRANS[SORTED_ORDER[i]] + "s:";
      if(web)
        output += WWW_UNHEADING;
      output += "\n" + sprintf("%s%-=*s","    ", 80,
                         sprintf("%-*#s\n", 74, mapdata[SORTED_ORDER[i]]));
    }

  output += "\n";

  return output;
}

mapping sort_players() {
  object *ppl;
  mapping pos = ([ ]);
  mapping pos2 = ([ ]);
  int i;
  int idle;
  string obtype;
  string *thekeys;
  int players;

  ppl = users();

  if(!sizeof(ppl))
    return ([ ]);

  for(i=0;i<sizeof(ppl);i++) {
    if(ppl[i]->query_invis())
      continue;

#ifndef SHOW_PLAYERS
    if(!ppl[i]->query_creator()) {
      players++;
      continue;
    }
#endif

    idle = query_idle(ppl[i]);
    obtype = ppl[i]->query_object_type();

    if(!pos[obtype])
      pos[obtype] = ({ });

    pos[obtype] += ({ ppl[i]->query_cap_name() +
          ((idle > 120) ? " (Idle " + (idle / 60) + ")" : "") });
  }

  thekeys = keys(pos);

  for(i=0;i<sizeof(thekeys);i++)
    pos2[thekeys[i]] = implode(sort_array(pos[thekeys[i]], 1), "\n");

#ifndef SHOW_PLAYERS
  pos2[" "] = "" + players;
#endif

  return pos2;
}

