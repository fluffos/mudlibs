// Room: fatang.c

inherit ROOM;

void create()
{
	set("short", "萨迦法堂");
	set("long", @LONG
这座法堂重檐盔顶，纯木结构，四面环以明廊，腰檐设有平座，建筑精湛，
精巧别致。廊下环栽着长青松柏，庭中更有一株几抱粗的百年梅花树，树干黝
黑似铁，苍劲挺拔。
LONG
	);

	set("exits", ([
		"up" : __DIR__"fatang2",
		"south" : __DIR__"fanyinge",
	]));
        set("objects", ([__DIR__"npc/zayilama" : 1,]));
	setup();
}
int valid_leave(object me, string dir)
{
        if ((string)me->query("family/family_name") != "大轮寺" 
           && dir == "up"  
           && present("zayi lama", environment(me)))
	return notify_fail(
"杂役喇嘛拦住了你，小心翼翼地道：“施主留步，本寺方丈正在清修，不许打搅，施主\n
是否改天再来拜见？\n");

	return ::valid_leave(me, dir);
}
