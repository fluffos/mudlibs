#define MAGIERNAME "andyl"
#define CLOSURE(x) #'x

#define TT(x) if(find_player("turrican"))tell_object(find_player("turrican"),x)
#define TA(x) if(find_player("andyl"))tell_object(find_player("andyl"),x)

#define LOGFILE "/players/andyl/log/andyl.log"
#define LOGF LOGFILE

#define CLONETP(x,ob) if ((ob=clone_object(x))->move(TP, M_GET) != 1) \
                         ob->move(TPENV, M_NOCHECK);
#define CLONETPNOCHK(x) clone_object(x)->move(TP, M_NOCHECK);
#define TPENV environment(this_player())
#define MENV environment(this_object())
