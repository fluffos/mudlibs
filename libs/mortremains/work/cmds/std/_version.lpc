// #include <disclaimer.h>
// The Version command.
// Brought to you by Buddha@TMI
// Updated for mudlib version by Watcher@TMI
// 4-19-92

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_version(string str) {
	if (str) return help();
 
	write(capitalize(mud_name()) + " is running the " + MUDLIB_VERSION +
	      " mudlib on " + version() + "\n");
	write("The game has been up since ");
  printf( "%s.\n", ctime( time() - uptime() ) );
	return 1;
}

int help() {
	write("Usage:\tversion\n" +
	"Tells you what version of MudOS the world is running and how long" +
		"\nthe world has been up.\n");
	return 1;
}
