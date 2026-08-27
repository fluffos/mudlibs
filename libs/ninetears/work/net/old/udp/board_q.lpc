#include "udp.h"
#include "board.h"
void send_message(mapping info);

/*
 * Intermud buliten boards....
 */

int call_in_progress;
mapping getting_board;

void create() {
  getting_board = ([ ]);
  seteuid(getuid());
} /* create() */

void incoming_message(mapping info) {
  mapping minfo;
  int i;
  string key;

  if (!info["NAME"] || !info["PORTUDP"]) return ;
  minfo = NAMESERVER_CD->query_mud_info(info["NAME"]);
  if (minfo["HOSTADDRESS"] != info["HOSTADDRESS"]) {
    /* Forged. */
      return ;
  }
  key = info["WIZNAME"]+"@"+info["NAME"];
  if (!getting_board[key]) {
    getting_board[key] = info;
      getting_board[key]["TIME"] = time();
    if (!call_in_progress)
      call_out("time_out", 5*60);
    call_in_progress = 1;
  } else
    getting_board[key]["NOTE"] += info["NOTE"];
  if (info["ENDHEADER"]) {
    if (info["ENDHEADER"] == getting_board[key]["HEADER"])
      send_message(getting_board[key]);
    map_delete(getting_board, key);
  }
} /* incoming_request() */

void time_out() {
  int i;
  string *the_keys;

  the_keys = keys(getting_board);
  for (i=0;i<sizeof(the_keys);i++)
    if (getting_board[the_keys[i]]["TIME"] + 5*60 < time())
      map_delete(getting_board, the_keys[i]);
  if (sizeof(getting_board))
   call_out("time_out", 5*60);
  else
    call_in_progress = 0;
} /* time_out() */

/*
 * This will add the message onto the correct board.
 */
void send_message(mapping info) {
  if (!info["BOARD"])
    info["BOARD"] = "intermud";
  BOARD_HAND->add_message(info["BOARD"], info["WIZNAME"]+"@"+info["NAME"],
                            info["HEADER"], info["NOTE"]);
} /* send_message() */
