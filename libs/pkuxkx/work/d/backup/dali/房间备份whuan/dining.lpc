// /d/dali/dining.c

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
这里是招待客人的饭厅，桌子上有一些素菜，要是饿了就坐下来吃点吧？
LONG);
        set("exits", ([ /* sizeof() == 2*/
"west" : __DIR__"yuan",
]) );
	set("objects",([
"/d/pker/npc/sunquan":1,
		"/d/shaolin/obj/qingshui-hulu":2,
		names[random(sizeof(names))]:1,
		names[random(sizeof(names))]:1,
		]));
	setup();
	replace_program(ROOM);
}
