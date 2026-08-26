#ifndef __INTERMUD_H__
#define __INTERMUD_H__

class list {
    int ID;
    mapping List;
}

nosave void create();
nosave void Setup();
nosave void eventRead(mixed *packet);
nosave void eventRequestMudList();
nosave void eventRequestChannelList();
nosave void eventSocketClose();
nosave void eventConnectionFailure();
int SetDestructOnClose(int x);
int SetSocketType(int x);
string GetMudName(string mud);
mapping GetMudList();
string *GetMuds();
mapping GetChannelList();
string *GetMatch(string mud);
string GetNameserver();

#endif /* __INTERMUD_H__ */
