// _explored.c
// This command gives admin the power to maintance explore point management.
// by Annihilator 10/04/94, Rewrite by Kyoko 10/05/94

#include <mudlib.h>
#include <daemons.h>
#include <explore.h>

inherit DAEMON;

int help();

int cmd_explored(string arg)
{
	int i, code, level, number, x, y;
	string area;

// fixed to that archs can set explore points legal
   if( !member_group(getuid(this_player()), "admin") &&
      !member_group(getuid(this_player()), "arch") ) return 0;
	if( !arg ) {
		write(set_color("The explore points now set in ES are:\n", "HIY"));
		for( i=0; i<sizeof(AREAS); i++ ) {
			printf("Area: "+set_color("%15-s", "HIG")+"    Explores: "+
				set_color("%4d\n", "HIM"), AREAS[i],
				(int)EXPLORE_D->query_total_explore(AREAS[i]) );
			printf(iwrap(set_color("Used #: "+
				(string)EXPLORE_D->query_explore_number(AREAS[i]), "HIC"), 70));
		}
		write(set_color("Total: "+(int)EXPLORE_D->query_total_explore()+
			" points.\n", "HIM"));
		return 1;
	}
	if( arg == "-l" ) {
		write(set_color("The explore limit for each level:\n", "HIY"));
		for( i=1; i<21; i++ )
			printf("Level %2d: %4d Points.\n", i,
				(int)EXPLORE_D->query_explore_limit(i));
		return 1;
	}

	if( sscanf(arg, "-l %d %d", level, number ) == 2 ) {
		if( level < 1 || level > 20 || number < 0 ) return help();
		EXPLORE_D->set_explore_limit(level, number);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-a %s#%d-#%d", area, x, y) == 3 ) {
		if( member_array(area, AREAS) == -1 || x < 0 || x > y )
			return help();
		for( i=x; i<=y; i++ )
			EXPLORE_D->log_explore(area, i);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-d %s#%d-#%d", area, x, y) == 3 ) {
		if( member_array(area, AREAS) == -1 || x < 0 || x > y )
			return help();
		for( i=x; i<=y; i++ )
			EXPLORE_D->clear_explore(area, i);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-a %s#%d", area, code) == 2 ) {
		if( member_array(area, AREAS) == -1 || code < 0 || code > MAX_EXPLORE )
			return help();
		EXPLORE_D->log_explore(area, code);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-d %s#%d", area, code) == 2 ) {
		if( member_array(area, AREAS) == -1 || code > MAX_EXPLORE )
			return help();
		EXPLORE_D->clear_explore(area, code);
		write("Ok.\n");
		return 1;
	}

	return help();
}

int help()
{
	int i;

	write( @TEXT
Syntax: explored
        explored -l [lvl limit]
        explored -a <area>#<number>[-#<number>]
        explored -d <area>#<number>[-#<number>]

    This command lets admins manage the explore system.
Options are:
l                 - show the level <-> minimun explore points table.
l lvl limit       - set the minimun explore points of level lvl.
a <area>#<number> - make an explore point legal.
d <area>#<number> - clear a legal explore point.

If you give the number as #x-#y then it will do from #x to #y ( must x < y ).
Lvl must be 1 to 20, and please remember the limit can't be < 0.
Now defined areas are:
TEXT
	);
	for( i=0; i<sizeof(AREAS); i++ )
		write(" "+set_color(AREAS[i],"HIG")+" ");
	write("\nAnd the Max number now can set is: "+MAX_EXPLORE+".\n\n");
	return 1;
}
