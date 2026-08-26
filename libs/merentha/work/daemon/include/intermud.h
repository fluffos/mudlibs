#ifndef l_intermud_h
#define l_intermud_h

class list {
    int ID;
    mapping List;
}

nosave void create();
nosave void Setup();
nosave void eventRead(mixed *packet);
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

#endif /* l_intermud_h */
