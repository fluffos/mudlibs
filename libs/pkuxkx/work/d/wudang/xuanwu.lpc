// xuanwu.c 玄武门
// by Xiang
// by arnzh 97.1.24 

inherit ROOM;

void create()
{
	set("short", "玄武门");
	set("long", 
"在你的面前是一座高大的石坊，上面写着“玄武门”三个\n"
"镏金大字，由于年代久远，久经日晒雨淋，已经显得有些黯淡。\n"
"再往上就是武当山的灵霄宫了。往下则是一条石阶路一直通到\n"
"山下。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
		"westdown" : __DIR__"shijie15",
 		"northup" : __DIR__"zixiao",  
	]));
	setup();
	replace_program(ROOM);
}

