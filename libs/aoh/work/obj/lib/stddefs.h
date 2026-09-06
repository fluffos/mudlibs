/* Some Defs...*/

#define Master "/secure/master"

#define PL        this_player()
#define PL_WLEVEL query_user_level(this_player())
#define PL_SHORT  this_player()->QueryShort()
#define PL_NAME   this_player()->QueryName()
#define PL_RNAME  this_player()->QueryRealName()

#define IPL        this_interactive() /*this_player(1)*/
#define IPL_WLEVEL query_user_level(this_interactive() /*this_player(1)*/)
#define IPL_SHORT  this_interactive()->QueryShort()
#define IPL_NAME   this_interactive()->QueryName()
#define IPL_RNAME  this_interactive()->QueryRealName()

#define ME  this_object()
#define PO  previous_object()

#define TRUE  (1)
#define FALSE (0)
#define NULL  (0)
