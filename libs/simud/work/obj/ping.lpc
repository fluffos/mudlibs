/** This object is cloned into the inventory of a player who is the target
 * of the ping soul. Hey, I was bored.
 */

int t;		// time the ping happened
int seq;	// how many packets have been sent
object pinger;	// who is doing the pinging?

void begin(object who, object where) {
  t = time();
  move_object(this_object(),where);
  pinger = who;
  seq = 0;
  call_out("tick",6);
}

int is_ping_object() { return 1; }
int query_time() { return t; }
object query_pinger() { return pinger; }
int query_seq() { return seq; }

void tick() {
  msg_object(pinger,"~CEMO16 bytes. icmp_seq = "+seq+". No response.~CDEF");
  seq++;
  if (seq == 10)
    call_out("time_out",6);
  else {
    msg_object(environment(this_object()),"~CEMOPing.~CDEF");
    call_out("tick",6);
  }
}

void time_out() {
  msg_object(environment(this_object()),"~CEMORequest timed out.~CDEF");
  msg_object(pinger,"~CEMORequest timed out.~CDEF");
  destruct(this_object());
}
