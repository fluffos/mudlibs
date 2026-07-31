#define UPDIR_CMD "/cmds/bos/updir"

inherit F_CLEAN_UP;

string *get_dir = ({ 
		"/feature/",
		"/inherit/",
		"/cmds/",
		"/clone/",
		"/www/",
		"/adm/",
		"/kungfu/",
		"/quest/",
		"/shadow/",
		"/u/",
		"/d/",
		});

void get_version(object me, string dir, int place);

int main(object me, string arg)
{
	if ( !arrayp(get_dir) || !sizeof(get_dir) ) return 0;
	get_version(me, get_dir[0], 0);
	return 1;
}

void get_version(object me, string dir, int place)
{
	dir += " -debug";
	UPDIR_CMD->main(me, dir);
	remove_call_out("get_version");
	place++;
	if ( place < sizeof(get_dir)  )
		call_out("get_version", 0, me, get_dir[place], place);
}