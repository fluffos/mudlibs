#define HOME(x) "/players/dusty/"+x
#define DORF(x) HOME("dorf/")+x
#define CLONEOB(x) clone_object(x)                     
#define ROOM(x) HOME("room/")+x
#define WEG(x) ("/d/gebirge/dusty/weg/")+x
#define OBJ(x) HOME("obj/")+x
#define MON(x) HOME("mon/")+x
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

#define UPPER capitalize
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )
