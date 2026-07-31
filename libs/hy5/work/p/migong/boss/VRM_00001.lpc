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
        set_maze_npcs(__DIR__"npc/0000/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0000/zhuangzhu2");

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
	set_link_entry_room(__DIR__"vrm00out1");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm00out2");

	//入口房间短描述
	set_entry_short("狼山");

	//入口房间描述
	set_entry_desc(@LONG
这是一个非常恐怖的地方。据说天下大大小小、公公母母
，各式各样的狼，都是从山来的，等到它们将死的时候，也都
要回山去死，这当然是传说，但狼山上曾有很多的狼却千真万
确，而现在上面几乎连一只狼都没有了，因为那些狼都被狼山
上的人杀光了，他们不但杀狼，还杀人，甚至杀的人比杀的狼
还多，所以，人们觉得狼山上的人比世上所有的毒蛇猛兽都可
怕得多。江湖中还替那些人取了个可怕的名字--狼人。
LONG
);

	//BOSS房间短描述
	set_exit_short("狼山");

	//BOSS房间描述
	set_exit_desc(HIB"
这是一个非常恐怖的地方。据说天下大大小小、公公母母
，各式各样的狼，都是从山来的，等到它们将死的时候，也都
要回山去死，这当然是传说，但狼山上曾有很多的狼却千真万
确，而现在上面几乎连一只狼都没有了，因为那些狼都被狼山
上的人杀光了，他们不但杀狼，还杀人，甚至杀的人比杀的狼
还多，所以，人们觉得狼山上的人比世上所有的毒蛇猛兽都可
怕得多。江湖中还替那些人取了个可怕的名字--狼人。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("狼山");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一个非常恐怖的地方。据说天下大大小小、公公母母
，各式各样的狼，都是从山来的，等到它们将死的时候，也都
要回山去死，这当然是传说，但狼山上曾有很多的狼却千真万
确，而现在上面几乎连一只狼都没有了，因为那些狼都被狼山
上的人杀光了，他们不但杀狼，还杀人，甚至杀的人比杀的狼
还多，所以，人们觉得狼山上的人比世上所有的毒蛇猛兽都可
怕得多。江湖中还替那些人取了个可怕的名字--狼人。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
