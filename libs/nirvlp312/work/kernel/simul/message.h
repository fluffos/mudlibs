#ifndef _kernel_simul_message_h
#define _kernel_simul_message_h

varargs string describe_object(mixed o,string id,mixed article,int full,
                               mixed subject,status possessive_s,
                               object perceiver);
public varargs mixed *simplify_message_pass1(mixed m,mapping arguments);
public varargs string message2string(mixed *m,object o,mapping args);
public varargs void send_message(mixed m,mapping arguments,mixed active);
varargs int query_message_busy(object o);
varargs void message(mixed m,object player);
varargs void map_messages(mapping m,mapping args,mixed targets);
varargs void say(mixed msg, mixed exclude);
void write(mixed msg);
void tell_object(object ob, string msg);

#endif

