// Room: dating.c 
 
inherit ROOM; 
 
void create() 
{
	set("short", "凤府大厅");
	set("long", @LONG
这里便是凤府的大厅，气派非凡，装饰奢华，居中一张太师椅，上铺一张
黄章黑纹的虎皮，凤天南看来不在，几个打手和师爷在旁嘀咕着。虎皮椅旁边
有两座大理石屏风，都有三四尺高，石上山水木石，便如是画出来的一般。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"dayuan",
		"south" : __DIR__"shufang",
	]));

        set("objects", ([
		__DIR__"npc/dashou" : 2,
		__DIR__"npc/he" : 1,
	]));
	setup();
}
