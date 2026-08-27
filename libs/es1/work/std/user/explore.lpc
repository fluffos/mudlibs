// explore.c
// By Annihilator 09/26/94
#include <daemons.h>
#include <explore.h>

 mapping explored;

int query_explore(string explore)
{
	string area;
	int code;

	if( !mapp(explored) ) explored = ([]);
	if( sscanf(explore, "%s#%d", area, code)!=2 ) return 0;
	if( undefinedp(explored[area]) ) return 0;
	return test_bit( explored[area], code);
}

int set_explore(string explore)
{
	string area;
	int code;

	if( !OPEN_EXPLORE ) return 0;
	if( query_explore(explore) ) return 1;
	if( !EXPLORE_D->valid_explore(explore) ) return 0;
	if( sscanf(explore, "%s#%d", area, code)!=2 ) return 0;
	if( undefinedp(explored[area]) ) explored[area]="";
	explored[area] = set_bit( explored[area], code );
	return 1;
}

varargs int query_explore_points(string area)
{
	string *areas;
	int i, j, ex;

	if( !mapp(explored) ) return 0;
	if( area ) {
		if( undefinedp(explored[area]) ) return 0;
		ex = 0;
		for( i=strlen(explored[area])*6-1; i>=0; i-- )
			ex += test_bit(explored[area], i);
		return ex;
	}
	areas = keys(explored);
	ex = 0;
	for( i=sizeof(areas)-1; i>=0; i-- )
		for( j=strlen(explored[areas[i]])*6-1; j>=0; j-- )
			ex += test_bit(explored[areas[i]], j);
	return ex;
}
