// filename : /adm/daemons/natured.c

#define TIME_TICK (time() * 60)

static int current_day_phase;
mapping *day_phase;

string *weather_msg =
({
	"天空中万里无云",
	"几朵淡淡的云彩妆点著清朗的天空",
	"白云在天空中飘来飘去",
	"厚厚的云层堆积在天边",
	"天空中乌云密布",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table(SYSTEM_CONFIG_DIR + "day_phase");
	init_day_phase();
}

// read a regular type of data table for day_phase and etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for ( i = 0; i < sizeof(line); i++ )
	{
		if ( line[i] == "" || line[i][0] == '#' ) continue;
		if ( !pointerp(field) )
		{
			field = explode( line[i], ":" );
			continue;
		}
		if ( !pointerp(format) )
		{
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for ( rn = 0, fn = 0; i < sizeof(line); i++ )
	{
		if ( line[i] == "" || line[i][0] == '#' ) continue;
		if ( !fn )
			data += ({ allocate_mapping( sizeof(field) ) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if ( !fn ) ++rn;
	}
	return data;
}

void init_day_phase()
{
	mixed *local;
	int i, t, phase_index;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	// Find the day phase for now.
	for ( i = 0; i < sizeof(day_phase); i++ )
		if ( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = ( i == 0 ? sizeof(day_phase) - 1 : i - 1 );

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	phase_index = ( current_day_phase + 1 ) % sizeof( day_phase );
	call_out( "update_day_phase",
		(int)day_phase[ phase_index ][ "length" ] - t );
}

mapping *query_day_phase()
{
	return day_phase;
}

void update_day_phase()
{
	mapping cur_phase;

	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	cur_phase = day_phase[ current_day_phase ];
	message( "outdoor:vision", cur_phase["time_msg"] + "\n", users() );
	if ( !undefinedp( cur_phase["event_fun"] ) )
		call_other( this_object(), cur_phase["event_fun"] );

	call_out( "update_day_phase", cur_phase["length"] );
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
void event_noon()
{
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
}

varargs mixed game_time(int flag)
{
	if( flag ) return localtime(TIME_TICK);
	else return CHINESE_D->chinese_date(TIME_TICK);
}
