// alias.c
// From ES2
// Modified for XKX by Xiang (12/15/95)

#include <dbase.h>
#include <command.h>
#define MAX_REPEAT 20
#define MAX_ALIASES 30
#define HISTORY_BUFFER_SIZE 10
#define MAX_IN_A_ROW 30
#define SHELL_CHAR      '`'
#define SHELL_STR       "`"


mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_check, maxcom  = 0; 

string process_input(string str)
{
    string *args, cmd, argstr, *temp_cmds, temp1, temp2;
    int i, j;
    object ob;
	ob = this_object();
	if (!environment(ob))
	{
		tell_object(ob, "对不起，由于你没有环境，转移到void...\n");
		ob->move( VOID_OB );
	}


    if(maxcom == 0)	last_check = time();
    if(maxcom == (MAX_IN_A_ROW -1 ) && time() == last_check)
	return "";
    else
	maxcom++;
    maxcom = maxcom % MAX_IN_A_ROW ;
    if( str==last_input && str != "" ) {
/*
	repeat_cnt++;
	if( repeat_cnt > MAX_REPEAT && !wizardp(this_object()) ) {
	    tell_object( this_object(),
	      "\n\n达摩老祖突然在一阵烟雾中出现。\n\n"
	      "\n\n达摩老祖说道：你是机器人，连我也看不惯了，走吧！！！\n\n");
	    command("quit");
	}
*/
    } else {
	repeat_cnt = 0;
	if (str != "")
	    last_input = str;
    }

    if( str[0]=='!' ) {
	if( pointerp(history) && sizeof(history) ) {
	    if( sscanf(str, "!%d", i) )
		str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
	    else
		str = history[last_cmd];
	} else
	    return "";
    } else {
	if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
	last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
	history[last_cmd] = str;
    }

    if( mapp(alias) ) {

	if( !undefinedp(alias[str]) ) {
	    cmd = replace_string( alias[str], "$*", "" );
	    temp1 = str;
	    temp2 = alias[str];
	    temp_cmds = explode(cmd, ";");
	    if( (j = sizeof(temp_cmds)) > 1 ) {
		map_delete( alias, temp1 );
		for( i = 0; i < j-1; i++ )
		    command( process_input(temp_cmds[i]) );
		if( !mapp(alias) ) alias = ([ temp1 : temp2 ]);
		else alias[temp1] = temp2;
		cmd = process_input(temp_cmds[j-1]);
	    }
	    return cmd;
	}


	if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
	    temp1 = cmd;
	    temp2 = alias[cmd];
	    cmd = replace_string( alias[cmd], "$*", argstr );
	    args = explode(argstr, " ");
	    if( (j = sizeof(args)) )
		for(i=0; i<j; i++)
		    cmd = replace_string( cmd, "$" + (i+1), args[i] );
	    temp_cmds = explode(cmd, ";");
	    if( (j = sizeof(temp_cmds)) > 1 ) {
		map_delete( alias, temp1 );
		for( i = 0; i < j-1; i++ )
		    command( process_input(temp_cmds[i]) );
		if( !mapp(alias) ) alias = ([ temp1 : temp2 ]);
		else alias[temp1] = temp2;
		cmd = process_input(temp_cmds[j-1]);
	    }
	    return cmd;
	}
    }

    // poet added for shell on 2001.10.23
    if ( wizardp(this_object())
      && stringp(str) && (str != "")
      && query("env/use_shell") )
    {
	string afters, shells;
	int index1, index2;

	index1 = strsrch(str, SHELL_CHAR);
	while (index1 != -1)
	{
	    afters = str[(index1+1)..<1];
	    index2 = strsrch(afters, SHELL_CHAR);
	    if ( index2 == -1 )
		break;
	    afters = afters[0..(index2-1)];

	    // calls the shell-process function.
	    shells = process_shell_str(afters);
	    str = replace_string(str,
	      sprintf(SHELL_STR"%s"SHELL_STR, afters), shells);


	    // if failed in the previous process
	    index2 = strsrch(str, SHELL_CHAR);
	    if ( index1 == index2 )
		break;

	    index1 = index2;
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
	else {
	    replace = replace_string(replace, "\n", ";");
	    alias[verb] = replace;
	}
	return 1;
    }
}

mapping query_all_alias()
{
    return alias;
}

int delete_all_alias()
{
	alias = ([ "delete":"delete" ]);
	map_delete(alias, "delete");
    return 1;
}

