#ifndef WUESTEDEFH
#define WUESTEDEFH 1

// MAGIERNAME und GEBIET muessen eine Etage tiefer definiert werden

#define WUESTE "/d/WUESTE/"
#define NPC  WUESTE MAGIERNAME "/" GEBIET "/npc/"
#define OBJ  WUESTE MAGIERNAME "/" GEBIET "/obj/"
#define ROOM  WUESTE MAGIERNAME "/" GEBIET "/room/"
#define LOG  WUESTE MAGIERNAME "/" GEBIET "/log/"
#define SAVEDIR  WUESTE MAGIERNAME "/" GEBIET "/save/"
#define ARMOUR  WUESTE MAGIERNAME "/" GEBIET "/armour/"
#define WEAPON  WUESTE MAGIERNAME "/" GEBIET "/weapon/"

#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),(x))
#define HOME "/players/" MAGIERNAME "/"

#define TI this_interactive()

#define TP this_player()
#define TPN this_player()->name()
#define TPP this_player()->QueryPronoun
#define TPPP this_player()->QueryPossPronoun
#define PL this_player()
#define PLN this_player()->name()

#define PO previous_object()
#define TO this_object()
#define ME this_object()

#define BS(s) break_string(s,78)
#define bs(s) break_string(s,78)
#define IS_BLUE(s) (!is_clone(s))

#define CAP(x) capitalize(x)
#define UPPER capitalize
#define LOWER lower_case

#define ENV(x) environment(x)
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define CLONEME(x) clone_object(x)->move(ME)
#define CLONEOB(x) clone_object(x)
#define CLONE(x,y) clone_object(x)->move(y);

#endif
