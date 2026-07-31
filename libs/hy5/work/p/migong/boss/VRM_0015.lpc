#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// 迷宫进入要求最低等级。

        set_lonely_create(1);


	//迷宫房间里的怪物。
        set_maze_npcs(__DIR__"npc/0015/man");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0015/boss");

	//迷宫的单边长
        set_maze_long(6); 

        set_npcs_rate(66);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room("/d/city/wumiao");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm15out1");

	//入口房间短描述
	set_entry_short("玩偶山庄");

	//入口房间描述
	set_entry_desc(@LONG
武林侏儒逍遥侯因变态心理而建。逍遥侯仿照自己的庄园
，造了一座精致的玩偶房屋，先故意让人观看一遍，然后把人
迷倒，送到庄园上去。来人醒后便会不由自主产生种种错觉，
以为自己也被魔法缩小，变成了玩偶人，生活在玩偶房屋中，
因此而丧失生活的信心而自甘沉沦。逍遥侯借此来戏弄、折磨
天下武林高手。
LONG
);

	//BOSS房间短描述
	set_exit_short("玩偶山庄");

	//BOSS房间描述
	set_exit_desc(HIR"
武林侏儒逍遥侯因变态心理而建。逍遥侯仿照自己的庄园
，造了一座精致的玩偶房屋，先故意让人观看一遍，然后把人
迷倒，送到庄园上去。来人醒后便会不由自主产生种种错觉，
以为自己也被魔法缩小，变成了玩偶人，生活在玩偶房屋中，
因此而丧失生活的信心而自甘沉沦。逍遥侯借此来戏弄、折磨
天下武林高手。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("玩偶山庄");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
武林侏儒逍遥侯因变态心理而建。逍遥侯仿照自己的庄园
，造了一座精致的玩偶房屋，先故意让人观看一遍，然后把人
迷倒，送到庄园上去。来人醒后便会不由自主产生种种错觉，
以为自己也被魔法缩小，变成了玩偶人，生活在玩偶房屋中，
因此而丧失生活的信心而自甘沉沦。逍遥侯借此来戏弄、折磨
天下武林高手。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}