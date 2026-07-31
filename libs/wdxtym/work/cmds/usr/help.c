// help.c
#define DEFAULT_LINE 15

#define DEFAULT_HELP_PATHS ({"/help/", })

#define DEFAULT_TIT_PATHS ({"/help/tit/",})

inherit F_CLEAN_UP;

string *tit_search = DEFAULT_TIT_PATHS;
string *help_search = DEFAULT_HELP_PATHS;

int main(object me, string arg)
{
	int i,page;
	string file, *search,str;

	if( !arg )
	{
		if (file_size(HELP_DIR + "/tit/topics") > 0)
		{
			str = replace_string(color_filter(read_file(HELP_DIR+"/tit/topics")),"\n","");
			str = replace_string(str,"$sp#","\n");
			write(ZJOBLONG+str+"\n");
		} else
		{
			write("没能找到帮助主题。\n");
		}
		return 1;
	}

	seteuid(getuid());

	if(sscanf(arg,"%s %d",arg,page)!=2)
		page = 1;
	if( pointerp(tit_search) ) {
		i = sizeof(tit_search);
		while(i--) if( file_size(tit_search[i] + arg)>0 ) {
			str = replace_string(color_filter(read_file(tit_search[i] + arg)),"\n","");
			str = replace_string(str,"$sp#","\n");
			write(ZJOBLONG+str+"\n");
			return 1;
		}
	}
	if( pointerp(help_search) ) {
		i = sizeof(help_search);
		while(i--) if( file_size(help_search[i] + arg)>0 ) {
			write(ZJOBLONG+replace_string(color_filter(read_file(help_search[i] + arg)),"\n",ZJBR)+"\n");
			//me->zj_more(ZJOBLONG,arg,explode(color_filter(read_file(help_search[i] + arg)),"\n"),DEFAULT_LINE,page);
			return 1;
		}
	}

	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}

	return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
	write(@HELP
指令格式：help <主题>	      例如：> help cmds
	  help <函数名称>()	例如：> help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
	);
	return 1;
}

