
inherit ROOM;

void create()
{
        set("short", "太湖水寨");
        set("long", @LONG
太湖水寨是朝廷最大的水师----太湖水师的驻扎之地，濒临充
山半岛。整个水营布满大小各种战船，装备各种重型火炮，刀枪林
立，旗帜招展，煞是威风。登了望台观万顷太湖，帆影点点，气象
轩豁。近眺三山如神龟静伏，远眺马山如骏马奔驰，好一幅山横马
迹尽纳湖光开绿野的风光。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"taihu",
	"south" : __DIR__"taihubing",
]));
        set("outdoors", "jinling");
        set("objects", ([
              __DIR__"npc/xiao" : 1,
			]) );

        setup();
//        replace_program(ROOM);
}
