#ifndef l_intermud_h
#define l_intermud_h

protected void create();
protected void Setup();
protected void eventRead(mixed *packet);
protected void eventSocketClose();
protected void eventConnectionFailure();
int SetDestructOnClose(int x);
int SetSocketType(int x);
string GetMudName(string mud);
mapping GetMudList();
string *GetMuds();
mapping GetChannelList();
string *GetMatch(string mud);
string GetNameserver();

#endif /* l_intermud_h */
