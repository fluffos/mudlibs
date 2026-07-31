// by tiantian(www.wangcf.com) 2001.4
// 查看帮派信息

#include <ansi.h>
#include <mudlib.h>
#include <group.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object group;
    string group_file, *str, msg;
    int i, chinese_name;  
	string dir, group_id;
    
    seteuid(getuid());

	// for group
    if( !arg ) {
		str = get_dir( GROUP_DIR );

		// 去掉公用的总舵文件group.c
		str = str - ({ "group.c" });

		msg = HIW+CHINESE_MUD_NAME+NOR"目前的帮派有：\n"NOR;
		msg += "帮派名称                          现任帮主        是否开放     简  介 \n"; 
		msg += "─────────────────────────────────────\n"NOR;
    
		for( i=0; i<sizeof(str); i++ ) {
			group_file = GROUP_DIR + str[i] + "/group.c";
			group = load_object( group_file );
			if( !group )
				continue;
			msg += sprintf("%-34s%-14s%-15s%-10s\n",
				group->query("group_name")+"("+capitalize(str[i])+")",
				capitalize( group -> query( "master" ) ),
				group->query( "time_gate" ) ?" 开　放":"",
				group->query( "story" ) ? "有":"",
				);
		}
		
		msg += "─────────────────────────────────────\n"NOR;
		msg += "目前江湖中共有 "+sizeof(str)+" 个帮派。\n";
		me->start_more(msg);
		return 1;
	}
	// for group <group_name>
	else {
		i = strlen( arg );
		chinese_name = 1;
		while(i--) {
			if( i%2==0 && !is_chinese(arg[i..<0]) ) {
				chinese_name = 0;
				break;
			}
		}

		if( chinese_name == 1 ) {
			// 输入的是中文名称
			str = get_dir( GROUP_DIR );
			
			// 去掉公用的总舵文件group.c
			str = str - ({ "group.c" });

			// 查找对应给定中文名的帮派
			for( i=0; i<sizeof(str); i++ ) {
				group_file = GROUP_DIR + str[i] + "/group.c";
				group = load_object( group_file );
				if( !group )
					continue;
				if( group->query( "group_name" ) == arg )
					break;
			}

			if( i == sizeof( str ) )
				group_id = 0;
			else 
				group_id = str[i];
		}
		else {
			// 输入的参数是英文名称
			group_id = arg;
		}

		if( !group_id )
	        return notify_fail("没有这个帮派。\n");
	    dir = GROUP_DIR + group_id + "/";
		if( file_size( dir + "group.c" ) < 0 )
	        return notify_fail("没有这个帮派。\n");
        if( file_size( dir + "story" ) < 0 )
	        return notify_fail("这个帮派没有简介。\n");
        me->start_more(HIW + CHINESE_MUD_NAME + NOR"－"
	        + load_object (dir + "group.c") -> query("group_name") + "\n" NOR
            + read_file( dir + "story") );
            return 1;
	}

}

int help(object me)
{
        write(@HELP
----------------------------------------
指令格式：group

显示当前江湖中的所有帮派和摘要信息。


指令格式：group <帮派名称>

查看帮派简介。

相关命令：gstate gstory

----------------------------------------
HELP
        );
        return 1;
}

