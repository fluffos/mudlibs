#define HOME(x) "/d/gebirge/thor/plateau/"+x
#define HOMEDIR(x) "/players/thor/"+x
#define ROOM(x) HOME("room/")+x
#define OBJ(x) HOME("obj/")+x
#define NPC(x) HOME("npc/")+x
#define HOEHLE(x) "/d/gebirge/thor/hoehlenquest/"+x
#define ARMOUR(x) HOME("armour/")+x
#define WEAPON(x) HOME("weapon/")+x
#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define LOGFILE "/players/thor/thor.log"
#define LOGF LOGFILE
// #define WLOG(x) write_file(LOGF,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
// #define WLOG(x) write("");
// #define FLOG(y,x) write_file(y,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));

#define P_HOLZ "gestruepp"
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPronoun()
#define CLONEME(x) clone_object(x)->move(ME)
#define TK(x) if(find_player("thor"))tell_object(find_player("thor"),x)

#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
