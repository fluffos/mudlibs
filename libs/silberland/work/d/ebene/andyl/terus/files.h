#define NPC(x) "/d/ebene/andyl/terus/npc"+x
#define ROOM(x) "/d/ebene/andyl/terus/room/"+x
#define OBJ(x) "/d/ebene/andyl/terus/obj/"+x
#define ARMOUR(x) "/d/ebene/andyl/terus/armour/"+x
#define WEAPON(x) "/d/ebene/andyl/terus/weapon/"+x
#define MAGIERNAME "andyl"

#define TI this_interactive()
#define TP this_player()
#define TPP TP->QueryPronoun
#define TPPP TP->QueryPossPronoun
#define PL this_player()
#define TPN this_player()->name()
#define CAP_TPN capitalize(this_player()->name())
#define TO this_object()
#define PO previous_object()
#define TT(x) if(find_player("turrican"))tell_object(find_player("turrican"),x)
#define TA(x) if(find_player("andyl"))tell_object(find_player("andyl"),x)

#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define TPENV environment(this_player())
#define SUID seteuid(getuid(this_object()));
#define CLONEME(x) clone_object(x)->move(this_object());
#define CLONEOB(x) clone_object(x)
#define CLONETPNOCHK(x) clone_object(x)->move(TP, M_NOCHECK);
#define CLONETP(x,ob) if ((ob=clone_object(x))->move(TP, M_GET) != 1) \
                         ob->move(TPENV, M_NOCHECK);
#define CLONE(x,y) clone_object(x)->move(y);

#define LOGFILE "/players/andyl/log/andyl.log"
#define LOGF LOGFILE

#define UPPER capitalize
#ifndef CAP
#define CAP capitalize
#endif
#define LOWER lower_case
#define bs( x ) break_string( x, 78 )
#define BS( x ) break_string( x, 78 )







