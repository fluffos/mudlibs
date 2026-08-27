class channel_info {
  string desc;             /* description of channel */
  int min_lvl;             /* minimum level to chat, -1 == no-one 0 == unltd */
  string guild;            /* required guild to chat here */
  object *userlist;        /* list of subscribed users */
}

// someone finish these !
int chat(string msg);
int channel_exists(string name);
void add_member(string chan, object member);
string map_to_local(string ch);
string map_to_remote(string ch);
varargs void broadcast_local(string ch, string who, string msg, int emote,
			     string target, string targetmsg);
