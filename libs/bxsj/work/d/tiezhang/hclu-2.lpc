//hclu-2.c 荒草路

inherit ROOM;


void create()
{
	set("short", "荒草路");
	set("long", @LONG
你走一条荒芜的小路上，两旁荒草齐膝，荆棘遍地，似乎罕有人至。山石壁立，
遮天蔽日，鸟兽全无，四周笼罩在一片阴暗之中，使这里看起来格外深隧幽静。
LONG
	);

	set("exits", ([
"southdown" : __DIR__"hclu",
"northwest" : __DIR__"hclu-3",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-340);
  set("coor/y",-180);
   set("coor/z",40);
   setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "northwest") && (dir != "southdown"));
        if (dir == "northwest"){
            me->receive_damage("qi", 100);       
            write("你的双腿被荆棘刺破，鲜血流了出来。\n");
        }

        if (dir == "southdown"){
            me->receive_damage("qi", 100);       
            write("你的双腿被荆棘刺破，鲜血流了出来。\n");
        }
        return 1;
}
