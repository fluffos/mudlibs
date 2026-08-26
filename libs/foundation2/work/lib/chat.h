#ifndef __CHAT_H__
#define __CHAT_H__

nosave void create();
nosave string cache_commands(string str);
nosave void net_dead();
void restart_heart();

int eventDestruct();

string *AddChannel(mixed val);
string *RemoveChannel(mixed val);
string *GetChannels();
string *RestrictChannel(string str);
string *GetRestrictedChannels();

#endif /* __CHAT_H__ */
