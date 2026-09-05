// help.c
#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;

void query_wiki(string arg,object me)
{
	if (!me) return;
	if (me->query_temp("wiking") && ((time() - me->query_temp("wiki_start_time")< 65)))
	  		tell_object(me,"你上次的wiki查询还未结束，暂时无法进行wiki查询。\n");
	else if (!me->query("env/nowiki"))
	  		tell_object(me,load_object("/adm/daemons/webd")->query_web(me,arg,"WIKI"));
	me->set_temp("wiking",arg);
	me->set_temp("wiki_start_time",time());
}
int main(object me, string arg)
{
	int i;
	string file, *search;

tell_object(this_player(),HIY"因游戏内不能贴图，且巫师更新帮助速度较慢，请查看北侠百科寻求帮助。\n访问地址："+HIR"http://wiki.pkuxkx.com/"+HIY"中获得。\n"NOR);
	// If no topic specified, give the topics.
	if( !arg ) {
                cat("doc/help/topics");
		return 1;
	}

	//call_out("query_wiki",1,arg,this_player());
	// Else, try if a command name is specified.
	seteuid(getuid());
        if (arg == "newbie")
                this_player()->set("seen_help",1);
	arg = ALIAS_D->process_global_alias(arg);
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}
	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);
	//arg最后如果有\，则会死循环出错，所以去掉arg中的\和空格
	arg = replace_string(arg," ","");
	arg = replace_string(arg,"\\","");
	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( F_NAME->replace_color(read_file(default_search[i] + arg) ));
			return 1;
		}
	}

	return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
	write(@HELP
指令格式：help <主题>              例如：> help cmds
          help <函数名称>()        例如：> help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
	);
	return 1;
}

