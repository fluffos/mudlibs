inherit ROOM;

void create ()
{
        set ("short", "武器铺");
        set ("long", @LONG
刚一进门就看到兵器架上摆着各种兵器，从上百近重的大刀到轻如芥
子的飞磺石，是应有尽有。女老板巾帼不让须眉。
LONG);
        set("exits", ([
                "east" : __DIR__"south1",
        ]));
        set("objects", ([
                __DIR__"npc/wuqi" : 1,
        ]));
	set("no_clean_up", 0);
        setup();
}

