/* Some Defs...*/

#define M    "/players/mateese/"
#define MLOG "/players/mateese/log/"
#define LM   "/log/mateese/"
#define MR   "/players/mateese/room/"
#define MO   "/players/mateese/obj/"
#define ML   "/players/mateese/lib/"

#define PL        this_player()
#define PL_EUID   geteuid(this_player())
#define PL_WLEVEL query_user_level(this_player())
#define PL_SHORT  this_player()->QueryShort()
#define PL_NAME   this_player()->QueryName()
#define PL_RNAME  this_player()->QueryRealName()

#define IPL        this_interactive()
#define IPL_EUID   geteuid(this_interactive())
#define IPL_WLEVEL query_user_level(this_interactive())
#define IPL_SHORT  this_interactive()->QueryShort()
#define IPL_NAME   this_interactive()->QueryName()
#define IPL_RNAME  this_interactive()->QueryRealName()

#define ME  this_object()
#define PO  previous_object()
