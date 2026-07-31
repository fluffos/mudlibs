// Room: /d/jinghai/zhuque11.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
这是一间温馨舒适的卧房，宽大的红木床罗帐深垂，床边是
一个小小妆台，妆台旁边的墙壁上却镶着一面一人多高的铜镜，
你走到镜前端祥了一下自己，抻手抚平了鬓角的乱发，[镜子]对
面是一张临窗书桌，打开窗户你似乎隐隐听到海浪拍岸的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"zhuque9",
]));
        
        set("sleep_room", 1);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
