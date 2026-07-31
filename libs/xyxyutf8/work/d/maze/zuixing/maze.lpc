#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/zuixing/room" );
        set_unique_room( ({
		"/d/maze/zuixing/room2",
		"/d/maze/zuixing/room3",
		"/d/maze/zuixing/room4",
		"/d/maze/zuixing/room5",
        }) );
        set_npcs_rate(90);
	set_display_map(1);	
        //迷宫的单边长
        set_maze_long(5);

        //入口方向(出口在对面)
        set_entry_dir("east");

        //入口与区域的连接方向
        set_link_entry_dir("west");

        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"enter");

        //出口与区域的连接方向
        set_link_exit_dir("out");

        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"out");  
        set_maze_room_short("醉星楼");
        set_maze_room_desc(@LONG
高祖时，太子李建成和三子李元吉对高祖御旨起麒麟阁十分不满，
认为这是对太宗皇帝的偏爱。
    于是二人穷二府之资，在麒麟阁的对面造了一座及其华丽宏伟的彩
楼，名「醉星楼」。为了吸引百姓前来观看，二人甚至不惜发送食物钱
财。
    后二王薨，太宗仁慈，此楼依然保留。尚有二王死忠在此维护日常，
但是据说到了夜晚，楼内常常传来哭泣之声。

LONG); 
        //入口房间短描述 
        set_entry_short("醉星楼"); 
        //入口房间描述 
        set_entry_desc(@LONG
高祖时，太子李建成和三子李元吉对高祖御旨起麒麟阁十分不满，
认为这是对太宗皇帝的偏爱。
    于是二人穷二府之资，在麒麟阁的对面造了一座及其华丽宏伟的彩
楼，名「醉星楼」。为了吸引百姓前来观看，二人甚至不惜发送食物钱
财。
    后二王薨，太宗仁慈，此楼依然保留。尚有二王死忠在此维护日常，
但是据说到了夜晚，楼内常常传来哭泣之声。

LONG);
        //出口房间短描述 
        set_exit_short(HIR"醉星楼"NOR); 
        //出口房间描述 
        set_exit_desc(@LONG
高祖时，太子李建成和三子李元吉对高祖御旨起麒麟阁十分不满，
认为这是对太宗皇帝的偏爱。
    于是二人穷二府之资，在麒麟阁的对面造了一座及其华丽宏伟的彩
楼，名「醉星楼」。为了吸引百姓前来观看，二人甚至不惜发送食物钱
财。
    后二王薨，太宗仁慈，此楼依然保留。尚有二王死忠在此维护日常，
但是据说到了夜晚，楼内常常传来哭泣之声。
LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(0);
        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(0);
        //迷宫销毁时间
	set_remove_time(3600);
	set_maze_nodeath(1); 
	set_maze_map_color(WHT);       
}
