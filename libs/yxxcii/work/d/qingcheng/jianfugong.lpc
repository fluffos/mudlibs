//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "建福宫");
	set("long", @LONG
建福宫旧称丈人观，以其座落丈人峰下故也。相传五岳丈人宁封子修
道于此。院内树木假山，相互掩映；周围林木苍翠，浓荫蔽日，炎夏来此
，十分凉爽。这里也是上山的起点。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"xiaoqiao",
		"northwest" : __DIR__"path1",
	]));
	set("objects", ([
		CLASS_D("qingcheng") + "/ji" : 1,
		CLASS_D("qingcheng") + "/shen" : 1,
	]));
	setup();
	replace_program(ROOM);
}

