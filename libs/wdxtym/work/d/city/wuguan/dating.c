//dating.c
inherit ROOM;

void create()
{
        set("short", "武馆大厅");
        set("long", @LONG
这里是武馆大厅，正中靠北摆着一张八仙桌，桌上供着关公的神位，旁边
放着两个青瓷花瓶，插着几支孔雀翎，墙上写着大大的一个“武”字，武馆主
人早些年在江湖上闯荡，现今洗手隐退，在襄阳开起了这间武馆，往北走有条
走廊，一直通向馆主的卧室。西面通向厨房，往东走就可以到后花园了。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"dayuan",
                "enter"     : __DIR__"zoulang4",
                "westdown"  : __DIR__"zoulang2",
                "eastdown"  : __DIR__"zoulang5",
		"southeast" : __DIR__"wupinfang",
        ]));
        set("no_fight", 1);

        set("objects", ([
               __DIR__"npc/dizi1" : 1,
        ]));         

        setup();
}
