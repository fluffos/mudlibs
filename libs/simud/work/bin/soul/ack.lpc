#include <emote.h>

string ping_results(object ob) {
  string buf = EMOTE_COLOR;
  buf += "16 bytes. icmp_seq = "+(ob->query_seq());
  buf += ". time = "+(time()-(ob->query_time()));
  buf += " sec.~CDEF";
  destruct(ob);
  return buf;
}

string query_cself() { return "~Name ~verbgo `Ack'."; }
string query_ctarget() { return "~Name ~verbgo `Ack' at ~targ."; }

main(param) {
  object t, ob = present_clone("/obj/ping",this_player());

  if(param) {
    if( t = present(param,environment(this_player()))) {
      set_target(t);
      this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ack' at ~targ.~CDEF");
      if (ob && t == ob->query_pinger())
        this_player()->msg_local(ping_results(ob));
    } else
      msg ("~[010No one by that name here~[070.");
  } else if (ob && t = present(ob->query_pinger(),environment(this_player()))) {
    set_target(t);
    this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ack' at ~targ.~CDEF");
    this_player()->msg_local(ping_results(ob));
  } else
    this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ack'.~CDEF");
  return 1;
}
