/*
 * Ok, we connect to the nntp port on the remote site.  We issue a 
 * group command to get some useful info on the group.
 * Then we fetch the articles one by one.  From the oldest one we
 * have.
 */
#include "inet.h"
#include "socket.h"
#include "board.h"


#ifdef DEBUG
#define TP(RABBIT) tell_object(find_player("pinkfish"), RABBIT)
#else
#define TP(RABBIT)
#endif
#define SAVE_DIR "/net/save/nntp_"

nosave string group_name, in_message, *pending;
int cur_article;
nosave int last_article;

void load_me();
void save_me();

void create() {
  pending = ({ });
  seteuid(getuid());
} /* create() */

void do_connect(string g_n) {
  if (group_name) {
    pending += ({ g_n });
    return ;
  }
  group_name = g_n;
  load_me();
  INETD->open_to_service("nntp", STREAM, "nntp_server");
} /* do_connect() */

void do_fetch(int article) {
} /* do_fetch() */

void read_callback(int fd, string mess) {
  int tmp, number, start, finish;
  string str, from, header, body, s1, s2, subject;

  TP("Got "+mess[0..2]+"("+strlen(mess)+") - "+
     replace_string(mess[strlen(mess)-5..1000000], "\n", "\\n")+
     "\n");
  if (in_message) {
    in_message += mess;
    if (in_message[strlen(in_message)-5..1000000] != "\r\n.\r\n") {
      TP("Collecting message.\n");
      return ;
    } else {
      mess = in_message;
      in_message = 0;
      TP("New mess "+mess[0..2]+"\n");
    }
  }
  switch (mess[0..2]) {
    case "200" :
    case "201" :
      previous_object()->write_fd(fd, "group "+group_name+"\n");
      return ;
    case "211" :
      sscanf(mess, "%d %d %d %d %s", tmp, number, start, finish, str);
      TP("Got news group info, "+start+".."+finish+".\n");
/*
 * Ok, excelent...
 */
/* Find the new articles and grab them one by one... */
      last_article = finish;
      if (cur_article < start)
        cur_article = start;
      if (cur_article <= finish)
        previous_object()->write_fd(fd, "article "+(cur_article++)+"\n");
      else {
        previous_object()->close_fd(fd);
        group_name = 0;
        if (sizeof(pending)) {
          do_connect(pending[0]);
          pending = pending[1..10000];
        }
      }
      return ;
    case "220" :
/* Article retrived. */
/* Ok, now get the info we want out of it... */
      if (mess[strlen(mess)-5..10000000] != "\r\n.\r\n") {
        in_message = mess;
        break;
      }
      mess = replace_string(mess, "\r", "");
      sscanf(mess, "%s\n\n%s", header, body);
      sscanf(header, "%s\nFrom: %s\n%s", s1, from, subject, s2);
      sscanf(from, "%s %s", from, s1);
      sscanf(header, "%s\nSubject: %s\n%s", s1, subject, s2);
      TP("From "+from+" with a subject of "+subject+" and a body of ");
      BOARD_HAND->add_message(group_name, from, subject, body);
      save_me();
      if (cur_article <= last_article)
        previous_object()->write_fd(fd, "article "+(cur_article++)+"\n");
      else {
        previous_object()->close_fd(fd);
        group_name = 0;
        save_me();
        if (sizeof(pending)) {
          do_connect(pending[0]);
          pending = pending[1..10000];
        }
      }
      return ;
    case "423" :
      if (cur_article <= last_article)
        previous_object()->write_fd(fd, "article "+(cur_article++)+"\n");
      else {
        previous_object()->close_fd(fd);
        group_name = 0;
        save_me();
        if (sizeof(pending)) {
          do_connect(pending[0]);
          pending = pending[1..10000];
        }
      }
      break;
    default :
      TP("Error "+mess);
      break;
  }
} /* read_callback() */

void connected(int fd) {
  TP("We are connected.\n");
} /* connected() */

void dest_me() {
  if (group_name)
    save_me();
  destruct(this_object());
} /* dest_me() */

void save_me() {
  save_object(SAVE_DIR+group_name);
} /* save_me() */

void load_me() {
  restore_object(SAVE_DIR+group_name);
} /* load_me() */
