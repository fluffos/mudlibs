#ifndef __CHAT_H__
#define __CHAT_H__

protected void create();
protected string cache_commands(string str);
protected void net_dead();
void restart_heart();

int eventDestruct();

string *AddChannel(mixed val);
string *RemoveChannel(mixed val);
string *GetChannels();
string *RestrictChannel(string str);
string *GetRestrictedChannels();

#endif /* __CHAT_H__ */
