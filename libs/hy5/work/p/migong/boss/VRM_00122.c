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
        set_maze_npcs(__DIR__"npc/0012/man3");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0012/zhuangzhu3");

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
	set_link_entry_room(__DIR__"vrm12out2");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm12out3");

	//入口房间短描述
	set_entry_short("十二连环坞");

	//入口房间描述
	set_entry_desc(@LONG
凤尾帮的老巢总舵，分十二连环坞分舵、分水关和内三堂。十二
连环坞巢穴极深，就是该帮的人众，不是直接在主舵效力的，也轻易
进不去。凤尾帮龙头帮主天南逸叟武维扬故意使他舵下的弟兄对十二
连环坞，始终存在着一种神秘感和向往，以免叛离心。凤尾帮以十二
连环坞，为巢穴，水旱两面，步步设防，以守为攻，以消灭天下武林
劲敌，称霸江湖。
LONG
);

	//BOSS房间短描述
	set_exit_short("凤尾帮总舵");

	//BOSS房间描述
	set_exit_desc(HIB"
凤尾帮的老巢总舵，分十二连环坞分舵、分水关和内三堂。十二
连环坞巢穴极深，就是该帮的人众，不是直接在主舵效力的，也轻易
进不去。凤尾帮龙头帮主天南逸叟武维扬故意使他舵下的弟兄对十二
连环坞，始终存在着一种神秘感和向往，以免叛离心。凤尾帮以十二
连环坞，为巢穴，水旱两面，步步设防，以守为攻，以消灭天下武林
劲敌，称霸江湖。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("十二连环坞");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
凤尾帮的老巢总舵，分十二连环坞分舵、分水关和内三堂。十二
连环坞巢穴极深，就是该帮的人众，不是直接在主舵效力的，也轻易
进不去。凤尾帮龙头帮主天南逸叟武维扬故意使他舵下的弟兄对十二
连环坞，始终存在着一种神秘感和向往，以免叛离心。凤尾帮以十二
连环坞，为巢穴，水旱两面，步步设防，以守为攻，以消灭天下武林
劲敌，称霸江湖。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
