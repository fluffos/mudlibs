#define P_MAX_KILL_LEV "maxkilllevel"
#define P_NOKILL_MSG "nokillmsg"

#define HOME(x) "/players/dusty/"+x
#define CLONEME(x) clone_object(x)->move(ME)
#define XX(x) if (!is_clone(this_object())) return   
#define CLONEOB(x) clone_object(x)
#define ROOM(x) ("/d/gebirge/dusty/hoch/room/")+x
#define OBJ(x) ("/d/gebirge/dusty/hoch/obj/")+x
#define NPC(x) ("/d/gebirge/dusty/hoch/mon/")+x
#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define LOGFILE "/players/dusty/log/dusty.log"
#define LOGF LOGFILE
// #define WLOG(x) write_file(LOGF,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
// #define WLOG(x) write("");
// #define FLOG(y,x) write_file(y,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));

#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TPP TP->QueryPossPronoun()
#define TK(x) if(find_player("dusty"))tell_object(find_player("dusty"),x)

#define CAP capitalize
#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
