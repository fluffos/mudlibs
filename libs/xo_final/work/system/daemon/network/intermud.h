#ifndef l_intermud_h
#define l_intermud_h

class list {
    int ID;
    mapping List;
}

private void create();
private void remove();
void eventSend( string type, string mud, string target, mixed * packet );
void SendToRouter(string type, mixed * data);
void SendToMud(string type, string mud, mixed * data );
void SendToUser(string type, string mud, string user, mixed * data);
void SendToAll(string type, mixed * data);

private void Setup();
private void eventReceiveStartupReply(string mud,string from, string to, mixed * packet);
private void eventReceiveMudList(string mud, string from, string to, mixed* packet);
private void eventReceiveTell(string mud, string from, string to, mixed* packet);
private void eventReceiveEmoteTo(string mud, string from, string to, mixed* packet);

private void eventReceiveWhoRequest(string mud, string from, string to, mixed* packet);
private void eventReceiveWhoReply(string mud, string from, string to, mixed* packet);

private void eventReceiveFingerRequest(string mud, string from, string to, mixed* packet);
private void eventReceiveFingerReply(string mud, string from, string to, mixed* packet);

private void eventReceiveChannelMessage(string mud, string from, string to, mixed* packet);
private void eventReceiveChannelEmote(string mud, string from, string to, mixed* packet);
private void eventReceiveChannelTargetEmote(string mud, string from, string to, mixed* packet);

private void eventReceiveStartupReply(string mud, string from, string to, mixed* packet);
private void eventReceiveMudlist(string mud, string from, string to, mixed* packet);
private void eventReceiveError(string mud, string from, string to, mixed* packet);

private void eventRead(mixed *packet);
private void eventSocketClose();
private void eventConnectionFailure();
int SetDestructOnClose(int x);
int SetSocketType(int x);
string GetMudName(string mud);
mapping GetMudList();
string *GetMuds();
mapping GetChannelList();
mapping GetServices();
string *GetMatch(string mud);

#endif /* l_intermud_h */
