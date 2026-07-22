

inherit ROOM;




void create()
{
	set("short", "戒律院");
	set("long", @LONG
      整个大殿门户紧闭，密不透风。即便是在白昼，也犹如黑
夜一般，每隔几步的墙上，点燃着几枝牛油巨烛。殿上供奉着降魔韦陀
下方摆着一排排水牛皮鞭、穿孔竹板及狼牙棒等执法刑杖。四周站满了
怀抱戒刀的执法僧兵。他们正用威严的眼神打量着你，令你不
禁心生惧意。
LONG
	);

	set("exits", ([
		"west" : __DIR__ "songshu1",
       ]));
	
	setup();
	replace_program(ROOM);
}



