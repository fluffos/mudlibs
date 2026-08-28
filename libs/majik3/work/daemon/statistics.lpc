/*
 * /daemon/statistics.c                 statistics daemon
 * 
 *                coder                 dazzt
 * */

inherit ITEM;

#define INTERVAL    20 * 60
#define ARRAY_SIZE  70

#define SAVEFILE    "/data/misc/statistics"

/* --- -- - variables - -- --- */

int *s_user;                         // number of users online
int *s_wiz;                          // number of wizards online
int *s_cmd;                          // commands per second
int *s_cpu;                          // current cpu usage
int *s_mem;                          // amount of memory used

int last_measure_time;

/* --- function prototypes --- */

int showStatistics(string);
void updateStatistics();
string generateGraph(int *, string);

/* --- -- - code - -- --- */

create_item()
{
	restore_object(SAVEFILE);
	
	set_name(({ "whirling ball", "ball"	}));
	set_short("a whirling ball is levitating in the air");
	set_long("A whirling ball levitates in the air in front of you." +
			 "Many kinds of gadgets stick out from the ball making you feel " +
			 "sick when trying to follow their movement. Apparently it's actively " +
			 "measuring something. You can 'inspect' the statistics it has gathered.\n");

	set_no_get(1);
	set_dimensions(30, 30, 30);
	set_weight(1000);
        set_hp(1);
        set_max_hp(1);
	
	if (!s_user)
		s_user = s_wiz = s_cpu = s_mem = s_cmd = ({ });
	
	call_out("updateStatistics", INTERVAL);
}

init()
{
	add_action("showStatistics", "inspect");
}




int showStatistics(string args)
{
	string str; 
	
	if (!args)
	{
		notify_fail("What kind of statistics you want to inspect?\n" +
					"(users, wizards, commands, cpu and memory).\n");
		return 0;
	}

	str = "^cW^bb [MAJIK STATISTICS]:  ";
	
	switch(lower_case(args))
	{
		case "users" : 
		    str += sprintf("%56s^c0\n", "Number of users online");
			str += generateGraph(s_user, "Users");
    		break;
		
		case "wizards" :
		    str += sprintf("%56s^c0\n", "Number of wizards online");
	        str += generateGraph(s_wiz, "Wizards");
		    break;
		
		case "cpu" :
		    str += sprintf("%56s^c0\n", "CPU load");
		    str += generateGraph(s_cpu, "      %");
		    break;
		
		case "memory" :
		    str += sprintf("%56s^c0\n", "Memory usage");
		    str += generateGraph(s_mem, "      kb");
		    break;
		
		case "commands" :
		    str += sprintf("%56s^c0\n", "Commands per second");
		    str += generateGraph(s_cmd, "  cmds / s");
		    break;
		
		default :
		    str = "No statistics found on such subject.\n";
	}
	
	message("standard", str, THIS);
		
	return 1;
}


void updateStatistics()
{
	object *ob;
	int i, sz, wiz;
	float f;
	mapping usage = rusage();
	
	remove_call_out("updateStatistics");

/* Count users */
	
	ob = users();
	
	for (i = 0, sz = sizeof(ob); i < sz; i++)
	{
		if (ob[i]->query_security())
			wiz++;
	}
	
	sscanf(query_load_average(), "%f %*s", f);

	s_user += ({ sizeof(ob) });
	s_wiz  += ({ wiz }); 
	s_cpu  += ({ to_float(usage["stime"] + usage["utime"]) / (uptime() * 10) });
	s_mem  += ({ memory_info() / 1000.0 });
	s_cmd  += ({ f });
	
	if (sizeof(s_user) > ARRAY_SIZE)   s_user = s_user[1..<1];
	if (sizeof(s_wiz) > ARRAY_SIZE)    s_wiz = s_wiz[1..<1];
	if (sizeof(s_mem) > ARRAY_SIZE)    s_mem = s_mem[1..<1];
	if (sizeof(s_cpu) > ARRAY_SIZE)    s_cpu = s_cpu[1..<1];
	if (sizeof(s_cmd) > ARRAY_SIZE)    s_cmd = s_cmd[1..<1];
	
	last_measure_time = time();
	
	save_object(SAVEFILE);
	
	call_out("updateStatistics", INTERVAL);
}


string generateGraph(int *measured, string yaxis)
{
	int *stats;
	string str;
	int x, y, i;
	float max;
	
	if (measured == ({ }))
		return "No statistics have been generated on this subject.\n";
	
	stats = measured;
	
	while (sizeof(stats) < ARRAY_SIZE)
		stats = ({ 0 }) + stats;
	
	max = 0;
	for (i = 0; i < sizeof(stats); i++)
		if (stats[i] > max)
			max = stats[i];
	
	if (max == 0 || max == 0.0)
		return "No statistics other than zero have been measured.\n";

	if (INTERVAL > 60)
		str = sprintf("%79s", "Each vertical line corresponds " + INTERVAL/60 + " minutes of time.\n");
	else
		str = sprintf("%79s", "Each vertical line corresponds " + INTERVAL + " seconds of time.\n");
	
	str += yaxis + "\n";
	
	for (y = 10; y >= 0; y--)
	{
		if ((y == 10) || (y == 0))
		{
			str += sprintf("%7.2f ", y * max / 10);
		}
		else
			str += "        ";
		
		for (x = 0; x < ARRAY_SIZE; x++)
		{
			if (( (10 * stats[x] / max) >= y) && 
				( (10 * stats[x] / max) != 0))
				str += "|";
			else
				str += " ";
		}
		str += "\n";
	}
	str += sprintf("          %-55s %10s\n", ctime(last_measure_time - INTERVAL * sizeof(measured))[4..15],
				   ctime(last_measure_time)[4..15]);
	
	return str;
}
		
		
	
