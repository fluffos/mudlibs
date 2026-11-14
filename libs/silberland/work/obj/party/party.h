#define PARTY(x) "/obj/party/"+x
#define HOME(x) PARTY(x)
#define ROOM(x) PARTY("room/")+x
#define OBJ(x) PARTY("obj/")+x
#define MON(x) PARTY("mon/")+x

#define P_PARTY_ID "party_id"
#define MAX_PARTY_DAUER 2700

#define LOGFILE "game/PARTYMONSTER"
#define LOGF LOGFILE
// #define TRANK_LOG HOME("log/trank.log")
// #define WLOG(x) write_file(LOGF,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
#define WLOG(x) write("");
#define FLOG(y,x) write_file(y,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));

#define TP this_player()
#define TPN this_player()->name()
#define TO this_object()
#ifndef ME
#define ME TO
#endif
#define TW(x) if (find_player("woody")) tell_object(find_player("woody"), x)
#define ADD_OBJECT(str) clone_object(str)->move(TP);
#define ENV            environment

#define UPPER capitalize
#define LOWER lower_case

