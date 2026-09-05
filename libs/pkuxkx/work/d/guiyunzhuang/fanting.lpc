// guiyunzhuang/fanting 饭厅

inherit ROOM;
string* names=({
	"/d/shaolin/obj/mala-doufu",
	"/d/shaolin/obj/bocai-fentiao",
	"/d/shaolin/obj/shanhu-baicai",
	"/d/shaolin/obj/liuli-qiezi",
        }); 

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这是归云庄的饭厅，供庄上的男女老少及外客们饮用。
LONG);
        set("exits", ([ /* sizeof() == 2*/
        "west" : __DIR__"zoulang5",
 "south":__DIR__"zoulang2",      ]));
	set("objects",([
		__DIR__"obj/dianxin":1,
		"/d/shaolin/obj/qingshui-hulu":2,
		names[random(sizeof(names))]:1,
		names[random(sizeof(names))]:1,
		]));
	setup();
	replace_program(ROOM);
}
