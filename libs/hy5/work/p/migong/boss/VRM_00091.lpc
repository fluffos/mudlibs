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
        set_maze_npcs(__DIR__"npc/0009/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0009/zhuangzhu2");

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
	set_link_exit_room(__DIR__"vrm09out1");

	//入口房间短描述
	set_entry_short("宝俶塔");

	//入口房间描述
	set_entry_desc(@LONG
西湖北岸有宝石山，宝俶塔就建于此山巅峰。史载“钱王俶入朝
，久留京师，百姓思念，建塔祈福”，这就是宝俶塔的来历。它虽然是
实心的，无路登临，但由于周围空旷无物，只有宝俶塔娟娟独立，更显
得秀丽天成，别有风韵。但这样一座宝塔的下面却变成了秘密恐怖组织
“天宗”的一个巢穴。
LONG
);

	//BOSS房间短描述
	set_exit_short("宝俶塔");

	//BOSS房间描述
	set_exit_desc(HIB"
西湖北岸有宝石山，宝俶塔就建于此山巅峰。史载“钱王俶入朝
，久留京师，百姓思念，建塔祈福”，这就是宝俶塔的来历。它虽然是
实心的，无路登临，但由于周围空旷无物，只有宝俶塔娟娟独立，更显
得秀丽天成，别有风韵。但这样一座宝塔的下面却变成了秘密恐怖组织
“天宗”的一个巢穴。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("宝俶塔");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
西湖北岸有宝石山，宝俶塔就建于此山巅峰。史载“钱王俶入朝
，久留京师，百姓思念，建塔祈福”，这就是宝俶塔的来历。它虽然是
实心的，无路登临，但由于周围空旷无物，只有宝俶塔娟娟独立，更显
得秀丽天成，别有风韵。但这样一座宝塔的下面却变成了秘密恐怖组织
“天宗”的一个巢穴。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
