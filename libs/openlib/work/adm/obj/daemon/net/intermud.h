#ifndef __INTERMUD_H__
#define __INTERMUD_H__

class list {
    int ID;
    mapping List;
}

protected void create();
int remove();
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

#endif /* __INTERMUD_H__ */
