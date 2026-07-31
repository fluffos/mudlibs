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
        set_maze_npcs(__DIR__"npc/0005/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0005/zhuangzhu2");

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
	set_link_exit_room(__DIR__"vrm05out1");

	//入口房间短描述
	set_entry_short("铁花堡");

	//入口房间描述
	set_entry_desc(@LONG
河岳五怪中张子清和黄少堂的城堡，江湖中名噪一时的河岳五怪曾
参加谋害武林大侠李清尘，掠夺了他收藏的所有珍宝、古玩。五怪中老
大张子清与老五黄少堂，深知李氏后代会有一天上门复仇，内心极为恐
惧，于是，在一荒山谷中，修筑了一座遍布险关、埋伏的铁花堡，在堡
中藏身并秘藏宝物。
LONG
);

	//BOSS房间短描述
	set_exit_short("铁花堡");

	//BOSS房间描述
	set_exit_desc(HIB"
河岳五怪中张子清和黄少堂的城堡，江湖中名噪一时的河岳五怪曾
参加谋害武林大侠李清尘，掠夺了他收藏的所有珍宝、古玩。五怪中老
大张子清与老五黄少堂，深知李氏后代会有一天上门复仇，内心极为恐
惧，于是，在一荒山谷中，修筑了一座遍布险关、埋伏的铁花堡，在堡
中藏身并秘藏宝物。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("铁花堡");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
河岳五怪中张子清和黄少堂的城堡，江湖中名噪一时的河岳五怪曾
参加谋害武林大侠李清尘，掠夺了他收藏的所有珍宝、古玩。五怪中老
大张子清与老五黄少堂，深知李氏后代会有一天上门复仇，内心极为恐
惧，于是，在一荒山谷中，修筑了一座遍布险关、埋伏的铁花堡，在堡
中藏身并秘藏宝物。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
