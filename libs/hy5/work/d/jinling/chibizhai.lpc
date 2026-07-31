
inherit ROOM;

void create()
{
        set("short", "赤壁水寨");
        set("long", @LONG
朝廷的赤壁水师驻扎在隔江的乌林，一眼望去密密麻麻泊满了
大小各种战船，水营里刀枪林立，旗帜鲜明，无处不显示出中华大
国的军威。临江峭壁上刻有“赤壁”二个大字，传说是赤壁之战吴
军统帅周瑜的手笔。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"chibi",
	"south" : __DIR__"chibibing",
]));
        set("outdoors", "jinling");
 set("outdoors", "jinling"); 
        set("objects", ([
              __DIR__"npc/ye" : 1,
			]) );

        setup();
//        replace_program(ROOM);
}
