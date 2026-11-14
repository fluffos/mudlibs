#include "local.h"

#define T_NUMBER	0x2
#define T_STRING	0x4
#define T_POINTER	0x8
#define T_OBJECT	0x10
#define T_STATUS	0x10000
#define T_MIXED         0x1ffff
#define WIZFLAG 0x20000000
#define NEEDEDFLAG 0x40000000
#define TRUE 1
#define FALSE 0

#if mappings
#define T_MAPPING	0x20
#define EMPTY_MAP ([])
#define MYMAP mapping
#else
#define T_MAPPING	0x00
#define EMPTY_MAP ({ ({}),({}) })
#define MYMAP mixed 
#endif

#define PR(X) write(X)
#define NAME(X) (string)X->query_name()
#define ENV(X) environment(X)
#define BEARERS_ENV() ENV(the_bearer())
#define iswizard() (wizard)
#define this_name() capitalize(bearer)
#define my_write(str) (flagval("notify")?write(str):0)
#define my_tell_room(a,str) (flagval("muffle")?0:tell_room(a,str,({the_bearer()})))
#define my_say(str) my_tell_room(BEARERS_ENV(),str)
#define my_tell_object(a,str) (flagval("notify")?0:tell_object(a,str))
#define book(X) obj_history[((++current_obj) % HISTORY_SIZE)]=X
#define last_news (iswizard()?last_wiznews:last_mortalnews)
#define endwrite(X) return write(X),1;
#define OK() endwrite("Ok.\n")
#define record_history(X) (history_list[(++current) % HISTORY_SIZE]=(X))
#define onoroff(X) ((X)?"on":"off")
#define share(X,Y) (basepatch("enjoy",X,Y)) 

#define DUMFUNC void move(object x) { move_object(this_object
#if KINGDOMS
#define find_player(X) ((object)find_player(X))
#endif

#ifdef INHERIT
inherit INHERIT;
#endif

#if REMOVE_FUNC
REMOVE_FUNC() { destruct(this_object()); }
#endif

#if NATIVE
#ifdef MYMOVE
MYMOVE
#else
void move(object x) { move_object(this_object(),x); }
#endif

/* no security for mortals  :) */
#define SAFECHECK() (iswizard() && previous_object() && previous_object()!=this_object() && (geteuid(previous_object())!=bearer))

#define move_object(X,Y) ((X)->move(Y))
#define my_file_name(X) ("/"+file_name(X))
#else
/* no security for mortals  :) */
#define SAFECHECK() (iswizard() && (this_interactive()!=the_bearer() || (previous_object() && previous_object()!=this_object() && my_creator(previous_object())!=bearer)))
#define my_file_name(X) ("/"+file_name(X))
#endif

#if PROF
#define PROFILE(X) basepatch("profile",(X));
#else
#define PROFILE(X)
#endif
