// Quick hack by Rust 12-10-93
int cmd_spew(string arg){
	string buf;
	string* lines;
	int loop;
	int i;
	int startln, numlines;
	string pipe;

	seteuid(getuid(previous_object()));
	if(!arg){
		notify_fail("Couldn't find your file.\n");
		return 0;
	}
	sscanf (arg, "%s | %s", arg, pipe);
	sscanf(arg, "%s %d %d", arg, startln, numlines);
	arg = resolv_path(this_player()->query("cwd"), arg);
	if(!buf = (numlines ? read_file(arg, startln, numlines) :
	read_file(arg, startln))){
		notify_fail("Couldn't find your file.\n");
		return 0;
	}
	if(!pipe) pipe = "say";
	lines = explode(buf, "\n");
	i = sizeof(lines);
	for(loop = 0; loop<i; loop++)
this_player()->force_me(pipe+" "+lines[loop]);
	return 1;
	this_player()->force_me(pipe+" "+lines[loop]);
}

void help(){

	write("Usage: spew <file> [startline] [# lines] [| command]\n"
"dumps contents of the file to the screen as a say from the user.\n"
"if pipe is used, dumps to the command specified.  Ie, \n"
"spew /cmds/xtra/_spew | wiz\n"
"would send the contents of this file over the wiz line.\n"
"\n");
}
