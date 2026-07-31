// shijie2.c 石阶2
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你正走在一条用坚实石板铺成的宽大石阶，两边建有石栏，凭栏观赏，抬头隐
约可见笼罩在云雾中的莲花峰，循石阶而上，怡然前行，听着流水淙淙，令人心
旷神怡。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "southup":__DIR__"lianhua",
                "northdown":__DIR__"shijie1"
      	]));
	setup();
}

