// shijie3.c 石阶3
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你现在正走一条用坚实石板铺成的宽大石阶，两边建有石栏，凭栏观赏，
遥遥可望见峨嵋绝顶。循石阶而上，再苍松翠柏的掩映中，西边的太阳泛出
淡淡的余辉，有令人说不出的赏心悦目。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "southup" : __DIR__"baizhangyan",
                "northdown":__DIR__"lianhua"
      	]));
	setup();
}

