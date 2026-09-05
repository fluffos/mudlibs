//沼泽随机迷宫的设置文件
inherit VIRTUAL_MAZE;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( __DIR__"zhaoze" );

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("west");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"jshanlu");

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"shidi");

	//入口房间短描述
	set_entry_short("大沼泽入口");

	//入口房间描述
	set_entry_desc(@LONG
往东就是一片沼泽，这里地势低洼，常年积水。空气中散发着一种腐臭的气味，泥塘里
时隐时现的是动物的尸骸。看来没有绝顶的轻功，是很难过去的。
LONG
);

	//出口房间短描述
	set_exit_short("沼泽");

	//出口房间描述
	set_exit_desc(@LONG
往西就是一片沼泽，这里地势低洼，常年积水。空气中散发者一种腐臭的气味，泥塘里
时隐时现的是动物的尸骸。看来没有绝顶的轻功，是很难过去的。东面地势渐渐高起来
了。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("大沼泽");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(({"这是一片一望无际的大沼泽。多年不曾见过阳光的谷底里，生长着无数不知名的植物。\n脚下的土地不停的冒着气泡，随时可能陷下去。偶尔可以看到一些动物的尸骸。\n",
"脚下的土地似乎干旱了一点，但是沼泽还是毫无看到边际的意思。	\n",
"令人绝望的绝境，秃鹫在你的头顶上盘旋。	\n"
}));
    



	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}
