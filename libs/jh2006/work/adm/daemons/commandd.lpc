//
// cmd_d.c
//
// By Annihilator (11/07/94)
// Modified by snowman@SJ 22/03/2000

mapping search = ([]);
mapping user_cmds = ([]);

mapping query_user_cmds() { return user_cmds; }

void rehash(string dir)
{
	int i;
	string *cmds;

	if( dir[<1]!='/' ) dir += "/";
	cmds = get_dir(dir);
	i = sizeof(cmds);
	while(i--)
		if( !sscanf(cmds[i]+"$", "%s.c$", cmds[i]) )
			cmds = cmds[0..i-1] + cmds[i+1..<1];
	if( sizeof(cmds) ){
		search[dir] = cmds;
		switch(dir){
			case "/cmds/std/":
			case "/cmds/skill/":
			case "/cmds/usr/":
				user_cmds[dir] = cmds;
		}
	}		
}

string find_command(string verb, string *path)
{
	int i;

	if( !pointerp(path) ) return 0;

	i = sizeof(path);
	while(i--) {
		if( undefinedp(search[path[i]]) ) rehash(path[i]);
		if( undefinedp(search[path[i]]) ) continue;
		if( member_array(verb, search[path[i]])!=-1 && load_object(verb = path[i] + verb))
			return verb;
	}
	return 0;
}
