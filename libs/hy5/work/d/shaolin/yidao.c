// Room: /d/shaolin/yidao.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的
行商，赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。
不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。马上的人
个个身着劲装，衣甲鲜明，有的还随身佩带着刀剑。看来都是些
些习武的江湖人。道路两旁是整整齐齐的杨树林。看来扬州快到
了。
LONG );
	set("exits", ([
		"south" : "/d/city/beimen",
		"north" : __DIR__"yidao1",
            "east" : "/p/guangchang",
	]));
	set("outdoors", "shaolin");
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int sizeinv;

        if( dir=="east" && !userp(me) )
                return notify_fail("那里只有玩家才能进去。\n");
        if( dir=="east")
{
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character()&& userp(inv[sizeinv])  )  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
}		

        return ::valid_leave(me, dir);
}