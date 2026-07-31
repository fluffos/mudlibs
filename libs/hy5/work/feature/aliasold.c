#include <ansi.h>
// alias.c
#pragma save_binary
#include <command.h>
#define MAX_REPEAT 50
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
mapping alias;
static string *history, last_input;
static int last_cmd, repeat_cnt = 0;
static int last_cmd_time,cmd_time=0,kill_time=0;
string process_input(string str)
{
    string *args, command, argstr,verb,arg,file,cmd;
    int i, j;
    object ob,dest;
    object me = this_player();
    if (!query_heart_beat(me))
    {
    write("由于你没有心跳，请重新登陆!!\n");
    "/cmds/usr/quithy"->main(me);
    }

    if( me->query_temp("disable_inputs") )   return HIR"什么？\n"NOR;
    if( me->query_temp("block_msg/all") )   return HIR"你看不见什么,什么都不能做!\n"NOR;
    cmd_time++;
    if (time()-last_cmd_time<1){
            if (kill_time>4){
                tell_object( this_object(),HIR "\n由于你滥用指令,你的指令被暂时封闭了!!!。\n二分钟后自动恢复\n" NOR);
                    seteuid(getuid());
                    dest = this_player();
                    this_player()->start_busy(50);
//	            this_player()->set_temp("block_msg/all", 1);
                    this_player()->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
                    cmd_time=0;
                    kill_time=0;
            }
                        if (cmd_time>14){
                tell_object( this_object(), "\n你的指令输入过快了。\n这个指令被取消了!\n"  );
                cmd_time=0;
                kill_time++;
            }
    }else   {
        cmd_time=0;
        if (time()-last_cmd_time>1)
                kill_time>0?kill_time--:0;
          else
                kill_time=0;
    }
    last_cmd_time=time();
 
    if( str==last_input ) {
        repeat_cnt++;
        if( repeat_cnt > MAX_REPEAT && !wizardp(this_object())) {
            tell_object( this_object(),
                HIR "\n你输入了过多的重复指令。\n"
                "\n你的指令被暂时封闭了!!二分钟后自动恢复!!\n" NOR);
        this_object()->start_busy(50);
//	this_object()->set_temp("block_msg/all", 1);
        this_object()->set_temp("disable_inputs",1);
	call_out("recoveralias", 120);
          return "";
        }
    } else {
        repeat_cnt = 0;
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
        if( !undefinedp(alias[str]) )
            return replace_string( alias[str], "$*", "" );
        if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
            cmd = replace_string( alias[cmd], "$*", argstr );
            args = explode(argstr, " ");
            if( (j = sizeof(args)) )
                for(i=0; i<j; i++)
                    cmd = replace_string( cmd, "$" + (i+1), args[i] );
            return cmd;
        }
    }
    command=(string)ALIAS_D->process_global_alias(str);

        if( this_object()->query_encoding() )
                str = LANGUAGE_D->toGB(str);

    if (!living(this_object())){
        if (sscanf(command,"%s %s",verb,arg)!=2) verb=command;
        file="/cmds/usr/"+verb+".c";
      if (file_size(file)>0){
         file->main(this_object(),arg);
         return "";
      }
        else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
            return "";
        else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
            return "";
    }
    return command;
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

void recoveralias()
{
//	this_object()->set_temp("block_msg/all", 0);
        this_object()->set_temp("disable_inputs",0);
//	this_player()->set_temp("block_msg/all", 0);
        this_player()->set_temp("disable_inputs",0);
     message("system", HIG "\n慢慢地系统恢复了你的指令....\n\n" NOR,
		this_object());
}
