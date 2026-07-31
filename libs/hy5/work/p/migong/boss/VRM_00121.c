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
        set_maze_npcs(__DIR__"npc/0012/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0012/zhuangzhu2");

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
	set_link_entry_room(__DIR__"vrm12out1");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm12out2");

	//入口房间短描述
	set_entry_short("二十四桥");

	//入口房间描述
	set_entry_desc(@LONG
二十四桥明月夜，玉人何处教吹箫？ 有茶园桥、大明桥、九曲桥
下马桥、作坊桥、洗马桥、南桥、阿师桥、周家桥、小市桥、广济桥
新桥、开明桥、顾家桥、通泗桥、太平桥、利园桥、万岁桥、青园桥
参佐桥、山光桥等二十四座桥，“二十四桥仍在，波心荡，冷月无声。
念桥边红药，年年知为谁生？竹西巷谷啸风家就在此桥附近。
LONG
);

	//BOSS房间短描述
	set_exit_short("谷啸风家");

	//BOSS房间描述
	set_exit_desc(HIB"
二十四桥明月夜，玉人何处教吹箫？ 有茶园桥、大明桥、九曲桥
下马桥、作坊桥、洗马桥、南桥、阿师桥、周家桥、小市桥、广济桥
新桥、开明桥、顾家桥、通泗桥、太平桥、利园桥、万岁桥、青园桥
参佐桥、山光桥等二十四座桥，“二十四桥仍在，波心荡，冷月无声。
念桥边红药，年年知为谁生？竹西巷谷啸风家就在此桥附近。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("二十四桥");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
二十四桥明月夜，玉人何处教吹箫？ 有茶园桥、大明桥、九曲桥
下马桥、作坊桥、洗马桥、南桥、阿师桥、周家桥、小市桥、广济桥
新桥、开明桥、顾家桥、通泗桥、太平桥、利园桥、万岁桥、青园桥
参佐桥、山光桥等二十四座桥，“二十四桥仍在，波心荡，冷月无声。
念桥边红药，年年知为谁生？竹西巷谷啸风家就在此桥附近。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
