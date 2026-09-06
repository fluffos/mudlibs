#include <time.h>

struct nolife_struct {
	string	name;
	int		today, week;
};

string format_time(int total) {
	int d,h,m,s;
	d = total / 86400;
	total -= d * 86400;
	h = total / 3600;
	total -= h * 3600;
	m = total / 60;
	s = total % 60;

	if( d )
		return sprintf("%2dd %2d:%02d:%02d",d,h,m,s);
	else if( h )
		return sprintf("    %2d:%02d:%02d",h,m,s);
	else if( m )
		return sprintf("       %2d:%02d",m,s);
	else if( s )
		return sprintf("          %2d",s);
	else
		return "          --";
}

int sort_by_today(struct nolife_struct a, struct nolife_struct b) {
	return a->today < b->today;
}
int sort_by_week(struct nolife_struct a, struct nolife_struct b) {
	return a->week < b->week;
}

string print_data(struct nolife_struct who) {
	return (pad(who->name,14,0)+" ~CDEF"+
			format_time(who->week)+"  "+
			format_time(who->today));
}

int get_data_index(struct nolife_struct *data, string name) {
	int x;
	for(x = 0; x < sizeof(data); x++)
		if( data[x]->name == name )
			return x;
	return -1;
}

string month(int x) {
	return ({ "Jan", "Feb", "Mar", "Apr", "May", "Jun",
			  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" })[x % 12];
}

string week_date() {
	int *then = localtime(time() - 604800);
	int *now = localtime();
	return  month(then[TM_MON]) + " " + then[TM_MDAY] + " - " +
			month(now[TM_MON]) + " " + now[TM_MDAY];
}

int main( string args ) {
	string curr, *names, player;
	struct nolife_struct *data = ({});
	int x, start = 0, stop, index = -1;
	int today_total, week_total, today_players = 0;

	// get data from daemon
	names = "/daemon/nolife"->query_all_players();
	foreach( curr : names ) {
		int today = "/daemon/nolife"->query_time_today(curr);
		int week = "/daemon/nolife"->query_time_week(curr);
		struct nolife_struct new = (<nolife_struct> curr, today, week);
		if( args == "today" ) {
			if( today ) {
				data += ({ new });
				today_total += today;
				today_players++;
			}
		} else if( week ) {
			data += ({ new });
			today_total += today;
			week_total += week;
			today_players++;
		}
	}

	// allow for sorting by day
	if( args == "today" ) {
		msg("~CDEF+--\n| ~CLABToday~CDEF");
		data = sort_array( data, #'sort_by_today );
		args = 0;
	} else {
		msg("~CDEF+--\n| ~CLAB"+week_date()+"~CDEF");
		data = sort_array( data, #'sort_by_week );
	}
		
	// parse index targetting
	if( args )
		sscanf(args,"%d",x);
	if( x <= sizeof(data) && x > 0 ) {
		index = x-1;
		start = index-5;
		args = 0;
	}
	if( args ) {
		index = get_data_index(data, args);
		if( index > -1 )
			start = index-5;
		else {
			msg("~CDEFNobody by that name has logged in this week.");
			return 1;
		}
	}

	// make sure start is within range
	if( start > sizeof(data) - 10 )
		start = sizeof(data) - 10;
	if( start < 0 )
		start = 0;
	stop = start + 10;
	if( stop > sizeof(data) )
		stop = sizeof(data);
	
	// print thingy
	msg("~CTIT   Player          Week          Today~CDEF");
	for( x = start; x < stop; x++ ) {
		string color = "~CBRT";
		if( x == 0 )
			color = "~CWRN";
		else if( x == index )
			color = "~CLAB";
		msg( sprintf("%2d ",x+1) + color + print_data( data[x] ) );
	}
	msg( "  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" );
	msg( "~CBRT" + sprintf("%2d ",sizeof(data)) + "~CTIT" + pad("Total",15,0) + "~CBRT" + format_time(week_total) + "  " +format_time(today_total) + "~CDEF");
	msg( "   ~CTIT" + pad("Average",15,0) + "~CDEF" + format_time(week_total / sizeof(data)) + "  " + format_time(today_total / today_players) );
	
	return 1;
}
