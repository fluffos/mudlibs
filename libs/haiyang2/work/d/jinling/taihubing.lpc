
inherit ROOM;

void create()
{
        set("short", "太湖兵工场");
        set("long", @LONG
这是一个庞大的兵工场，是国家设立的专门制造大型武器装备
的地方。到处可见钢铁和熔炉，所有工人都在忙碌地工作着，有的
打铁，有的锻造，有的装配，好一番热火朝天的景象。不远处放着
一排刚制好的成品。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"taihuzhai",
]));
        set("outdoors", "jinling");
        set("objects", 
        ([ //sizeof() == 1
              "/d/hainan/npc/man1" : 2,
        ]));
	set("no_fight",1);
	set("no_study",1);
	set("no_magic",1);
	set("hell",1);
	set("NONPC",1);
        setup();
//        replace_program(ROOM);
}
