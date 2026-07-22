inherit ROOM;
void create()
{
	set("short", "荒草路");
	set("long", @LONG
你走一条荒芜的小路上，两旁荒草齐膝，荆棘遍地，似乎罕有人至。山石
壁立，遮天蔽日，鸟兽全无，四周笼罩在一片阴暗之中，使这里看起来格
外深隧幽静。
LONG
	);

	set("exits", ([
"southdown" : __DIR__"hclu-4",
"northwest" : __DIR__"hclu-6",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-350);
  set("coor/y",-150);
   set("coor/z",60);
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
