// xiangji.c 香积厨
// by llin

inherit ROOM;

void create()
{
	set("short", "香积厨");
	set("long", 
"这儿是厨事之处，一阵阵烟火熏人，一个粗壮的道人正用\n"
"吹火筒猛吹一气，憋的满脸通红。另一个道士手执一只铁铲，\n"
"在在粥锅中用力搅着。不时停下来歇口气，直直腰。一边放着\n"
"几盘菜，还没有端上去。\n"
	);
	set("exits", ([
		"west"  : __DIR__"shanfang",
	]));
	set("kitchen", 1);
	set("objects",([
		__DIR__"npc/shaohuo" : 1,
		__DIR__"npc/shaofan" : 1
		]));
	setup();
	replace_program(ROOM);
}

