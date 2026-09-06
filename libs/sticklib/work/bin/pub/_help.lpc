#include <cmd.h>

#define BAR \
"============================================================================"

int query_access_file(string file) { return (file == ".ACCESS") ? 0 : 1; }

nomask int
help_cmd(string arg)
{
    string s;
    object me;

    if  (!(me = this_player())) return 0;

    if (arg == ".ACCESS") arg = "NO_SUCH_TOPIC";
    if (arg && sscanf(arg, "%s/../%s", s, s)) arg = "NO_SUCH_TOPIC";
    else if (arg && member(arg, ' ') >= 0) arg = "NO_SUCH_TOPIC";
    else if(!arg || arg == "all")
	s = sprintf("Commands: %-=65s\nGeneral:  %-=65s\nMiscellaneous: %-=60s\n",
	  implode(filter(get_dir("/doc/help/commands/"), #'query_access_file), ", "),
	  implode(filter(get_dir("/doc/help/topics/"), #'query_access_file), ", "),
	  implode(filter(get_dir("/doc/help/bonus/"), #'query_access_file), ", ") );

    if (!s) s = read_file ("/doc/help/commands/"+arg);
    if (!s) s = read_file ("/doc/help/topics/"+arg);
    if (!s) s = read_file ("/doc/help/bonus/"+arg);

    /* K l u d g e ! ! ! */
    if (!s && (int)me->query_coder_level() > 0) {
	s = read_file ("/doc/man/man1/"+arg);
	if (!s) s = read_file ("/doc/man/man2/"+arg);
	if (!s) s = read_file ("/doc/man/man3/"+arg);
	if (!s) s = read_file ("/doc/man/man4/"+arg);
	if (!s) s = read_file ("/doc/man/man5/"+arg);
	if (!s) s = read_file ("/doc/man/man6/"+arg);
	if (!s) s = read_file ("/doc/man/man7/"+arg);
	if (!s) s = read_file ("/doc/man/man8/"+arg);
	if (!s) s = read_file ("/doc/man/man9/"+arg);
    }

    if (!s) {
	me -> tell_me("No help under that topic.");
	return 1;
    }
    me->more( ({ BAR }) + explode (s, "\n") + ({ BAR }) );
    return 1;
}
