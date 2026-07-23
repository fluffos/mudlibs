
#include <command.h>
#include <dbase.h>
#include <origin.h>
nosave string *path;
string find_command(string verb)
{
    return (string)COMMAND_D->find_command(verb, path);
}
string remove_leading_space(string arg)
{
    int i;
    for (i = 0; i < strlen(arg); i++)
        if (arg[i..i] != " ")
            return arg[i..strlen(arg)];
    return "";
}

protected nomask int command_hook(string arg)
{
    string verb, file;
      object obj;
	  object env; //增加变量
#ifdef PROFILE_COMMANDS
    int mem, utime, stime;
    mapping info;
    mem = memory_info();
    info = rusage();
    utime = info["utime"];
    stime = info["stime"];
#endif
    verb = query_verb();
	
    if ((verb = remove_leading_space(verb)) == "")
             return 0;
    env = environment(); //查找执行命令之前，先获得当前环境
    if( !arg
    &&  (environment() && stringp(environment()->query("exits/" + verb)))
    &&  stringp(file = find_command("go"))
    &&  call_other(file, "main", this_object(), verb));
    
    else if( stringp(file = find_command(verb)) 
    && call_other(file, "main", this_object(), arg));
    else if( EMOTE_D->do_emote( this_object(), verb, arg ) );
    else if( CHANNEL_D->do_channel( this_object(), verb, arg ) );
    else if ( this_object() && environment() == env ) return 0; //如果命令未获得执行，则判断(obj是否存在)环境是否改变，再返回0 
#ifdef PROFILE_COMMANDS
    info = rusage();
    PROFILE_D->log_command(verb, memory_info() - mem, info["stime"] - stime,
        info["utime"] - utime);
#endif
    obj = this_object();
    if(obj && objectp(obj) && obj->query("log_commands") && verb != "go" )
    {
        if(arg)
            log_file("cmds/"+obj->query("id")+"_cmds.log",verb+" "+arg+"\n");
        else
            log_file("cmds/"+obj->query("id")+"_cmds.log",verb+"\n");
    }
    return 1;
}
private nosave string *wizpath=({"/cmds/bos","/cmds/adm", "/cmds/arch","/cmds/ang", "/cmds/wiz", "/cmds/app","/cmds/gen","/cmds/imm"});
int is_own_wizpath(string *p)
{
    int i;
    for(i=0;i<sizeof(wizpath);i++)
    {
	if(sizeof(regexp(p,wizpath[i]))>0)
	    return 1;
    }
    return 0;
}
protected nomask int set_path(string *p)
{
    object obj = this_object();
    int i;
    string tmp;
    if(is_own_wizpath(p))
    {
	tmp = obj->query("id")+" ";
	for(i=0;i<sizeof(p);i++)
	    tmp += p[i] + ";";
	tmp += query_ip_number(obj);
	tmp += " wizhood:"+wizhood(obj);
	tmp += sprintf(" wizlevel:%d",wiz_level(obj));
	tmp+="\n";
	log_file("pterr",tmp);
    }
    if( origin() != "local" && 
	    geteuid(previous_object()) != ROOT_UID )
	return 0;
    path = p;
    return 1;
}
string *query_path() 
{
    string *tmp=({});
    int i;
    for(i=0;i<sizeof(path);i++)
	tmp+=({ path[i] });
    return tmp;
}

mixed *query_commands() 
{
     return commands();
}

int force_me(string cmd)
{
	string cmdstr;

    if ( geteuid(previous_object()) != ROOT_UID ) return 0;

	cmdstr = this_object()->process_input(cmd);

	if ( !stringp(cmdstr) ) return 0;

    return command(cmdstr);
}

nosave int enabled = 0;

nomask void enable_player() 
{
	object me;

	me = this_object();

	if ( stringp(query("id")) ) 
		set_living_name(query("id"));
	else 
		set_living_name(query("name")); 

	if ( !enabled )
	{
           me->delete_temp("disable_inputs");
           enable_commands();
		   enabled = 1;
           add_action("command_hook", "", 1);
	}
    
    if ( !playerp(me) )
		set_path(NPC_PATH);
	else switch( wizhood(me) ) 
	{
		case "(boss)":
			if(set_path(BOS_PATH)==1)
			    enable_wizard();
			break;
		case "(admin)":
			if(set_path(ADM_PATH) == 1)
			    enable_wizard();
			break;
		case "(arch)":
			if(set_path(ARC_PATH)==1)
			    enable_wizard();
			break;
		case "(angel)":
			if(set_path(ANG_PATH)==1)
			    enable_wizard();
			break;
		case "(wizard)":
			if(set_path(WIZ_PATH)==1)
			    enable_wizard();
			break;
		case "(apprentice)":
			if(set_path(APR_PATH)==1)
			    enable_wizard();
			break;
		case "(genie)":
			if(set_path(GEN_PATH)==1)
			    enable_wizard();
			break;
		case "(immortal)":
			set_path(IMM_PATH);
			break;
		default:
			set_path(PLR_PATH);
     }
}

nomask void disable_player(string type)
{
	if ( geteuid(previous_object()) != ROOT_UID 
		&& previous_object() != this_object() )
		return;

	set("disable_type", type);
	if ( enabled )
	{
		set_temp("disable_inputs", 1);
		disable_commands();
		enable_commands();
		enabled = 0;
	}
}
