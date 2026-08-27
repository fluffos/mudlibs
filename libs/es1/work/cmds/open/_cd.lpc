//#pragma save_binary

/*
*  Author and date unknown ??
*  help() added 1/27/92   Brian@TMI
*  revised for greater speed by Buddha (8/23/92)
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int
cmd_cd(string str)
{
	int size;
	string name, path, hdir;
 
	path = this_player()->query("cwd");
	name = geteuid(this_player());
	seteuid(getuid());
 
	if(!str) {
		str = user_path(name);
 
		hdir = (string)this_player()->query("home_dir");
		if(hdir)  str = hdir;

		if(str[strlen(str)-1] == '/')  str = str[0..strlen(str)-2];
		if(!str || !directory_exists(str))  str = "/doc";
		this_player()->set("cwd", str);
		write( this_player()->query("cwd")+"\n");
		return 1;
	}
	str = resolv_path(path, str);
	substr("//", "/", str);
	if ((int)master()->valid_read(str, this_player()) == 0) {
		notify_fail(str+": permission denied\n");
		return 0;
	}
	size = file_size(str);
	if (size > -1) {
		notify_fail(str+": not a directory\n");
		return 0;
	}
	if (size == -1) {
		notify_fail(str+": no such file or directory\n");
		return 0;
	}
	this_player()->set("cwd", str);
	write( this_player()->query("cwd")+"\n");
	return 1;
}

int
help() {
	write("Command: cd\nSyntax: cd <directory>\n"+
		"This command changes your current directory to the\n"+
		"one you specify.  If directory begins with a / then\n"+
		"the command will look from the root, otherwise it\n"+
		"will look in the child directories of your current\n"+
		"directory.  .. will back up to the parent of your\n"+
		"current directory.  Thus cd ../obj will attempt to\n"+
		"move to the directory obj which is a child of your\n"+
		"current parent directory.\n"+
		"cd with no arguments will move you to your home dir-\n"+
		"ectory if you are a student, or the /doc directory if\n"+
		"not.\n");
	return 1;
}
