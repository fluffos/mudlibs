#define MAGIERNAME "stahldorn"

#define DB(x) if (find_player(MAGIERNAME)) \
   tell_object(find_player(MAGIERNAME),("Debug sagt: "+x+"\n"))
#define HOME "/players/" MAGIERNAME "/"

#define TI this_interactive()

#define TP this_player()
#define TPN this_player()->name()
#define TPP this_player()->QueryPronoun
#define TPPP this_player()->QueryPossPronoun
#define PL this_player()
#define PLN this_player()->name()

#define TO this_object()
#define ME this_object()

#define BS(s) break_string(s,78)
#define bs(s) break_string(s)
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

#define KNARKHPATH "/d/wasser/stahldorn/knarkh/"
#define WEGPATH "/d/wasser/stahldorn/weg/"
#define QUESTPATH "/d/wasser/stahldorn/quest/"
#define OUTLAWPATH "/d/wasser/stahldorn/outlaw/"
