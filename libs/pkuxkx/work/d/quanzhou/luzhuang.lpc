// /d/jiaxing/luzhang.c 陆家庄
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "陆家庄");
	set("long", @LONG
这是嘉兴一带有名的财庄, 陆家庄。原庄主陆展元因病不治而亡, 其
妻当晚便即自刎殉夫。陆展元、何沅君夫妇的侠名震於江湖，嘉兴陆家庄
的名头在武林中向来是无人胆敢小觑的。现在当家的是陆展元之弟陆立鼎。
LONG
	);

	set("exits", ([
                "enter" : __DIR__"tianjing",
                "north" : __DIR__"shulin",
	]));

        set("outdoors", "嘉兴");
	setup();
	replace_program(ROOM);
}

