// alias.c

#define MAX_REPEAT 50
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_time=time(), cmd_cnt=0, cmd_cnt1=0, cmd_cnt2=0;

int query_cmd_count() {return cmd_cnt2;}

string process_input(string str)
{
	string *args, cmd, argstr;
	int i, j, count, curr_time;

	if( userp(this_object()) && (this_object()->query_temp("block_msg/all")
	  || !living(this_object()) ) )
		return "";

	notify_fail("什么？\n"); 
	       
	reset_eval_cost();
	str = CONVERT_D->input(str,this_object());

       	cmd_cnt++;
	if(cmd_cnt>100) 
	{ 
        	curr_time=time();
	  	if(curr_time-last_time<5) 
	  	{
	    		if(cmd_cnt1==0)
	    		{
	      			cmd_cnt2=cmd_cnt/(curr_time-last_time+1);
	      			write("你一次输入太多命令了。\n");
            		}
	            	cmd_cnt1++;
		    	if(cmd_cnt1>30) 
	    			cmd_cnt1=0;
	            	last_time=curr_time; 
			return "";
          	} 
          	else 
          	{
	    		cmd_cnt2=cmd_cnt/(curr_time-last_time+1);
            		last_time=curr_time;
	    		cmd_cnt=0;
	    		cmd_cnt1=0;
	  	}
        }
	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) ) {
			        if(i<0) i=0;
			        else i=i%HISTORY_BUFFER_SIZE;
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			}  else
				str = history[last_cmd];
			if(!str) return "";
		} else
			return ""; 
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) ) 
	{
		if( !undefinedp(alias[str]) )
			return replace_string(alias[str], "$*", "" );
		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) 
		{
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}
	return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
	if( !replace ) {
		if( mapp(alias) ) map_delete(alias, verb);
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}
