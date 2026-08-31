#ifndef __EXT_MESSAGING_H__
#define __EXT_MESSAGING_H__

#include "/std/living/include/env.h"
#include "/std/living/include/player.h"

void receive_message(string type, string msg);
int set_contents_can_hear(int i);
int set_environment_can_hear(int i);
int query_contents_can_hear();
int query_environment_can_hear();
varargs void receive_up(string msg, object *exclude, int msg_type);
varargs void receive_down(string msg, object *exclude, int msg_type);
varargs void receive_all(string msg, object *exclude, int msg_type);
varargs receive_direct(string msg, int message_type);
void do_receive(string message, int message_type);
void send_ga();

#endif // __EXT_MESSAGING_H__
