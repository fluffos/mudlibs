#include <cmd.h>
#include <tell_me.h>

#define	MIN_COL	20
#define	MIN_ROW	10

nomask int
screen_cmd(string str)
{
    int x, y;

    if (!CHECK) return 0;

    if (!str) {
	mixed a, b;

	a = (mixed) this_player() -> query_env("columns");
	b = (mixed) this_player() -> query_env("rows");
	if (stringp(a)) sscanf(a, "%d", a);
	if (stringp(b)) sscanf(b, "%d", b);
	if (intp(a)) x = a;
	if (intp(b)) y = b;
	this_player() -> tell_me((x || y) ?
	  ("Your current screen-dimensions are: "+x+" columns, and "+y+" rows.\n"
	    +"To re-define them, use command '"+query_verb()+" <columns> <rows>'.\n"
	    +"Values 'columns' and 'rows' will be used in line-wrapping.") :
	  "Your screen-dimensions haven't been defined yet. To define them, use"
	  +" command '"+query_verb()+" <columns> <rows>'.\n"
	  +"Values 'columns' and 'rows' will be used in line-wrapping.");
	return 1;
    }
    if (sscanf(str, "%d %d", x, y) < 2) return
	notify_fail("Usage: "+query_verb()+" <columns> <rows>.\n"), 0;
    if (x < MIN_COL) return
	notify_fail("Value for <columns> too small, mininum "
	  + MIN_COL + ".\n"), 0;
    if (y < MIN_ROW) return
	notify_fail("Value for rows too small, minimum "
	  +MIN_ROW+".\n"), 0;
    this_player() -> set_env("columns", x);
    this_player() -> set_env("rows", y);
    this_player()->tell_me("Ok.", TELL_UPDATE);
    return 1;
}
