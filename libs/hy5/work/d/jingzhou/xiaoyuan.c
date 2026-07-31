// Room: huiyuan
// Date: Haa 96/03/22

inherit ROOM;

int do_say(string arg);

void create()
{
	set("short", "卉园");
	set("long", @LONG
这里是一处幽静的环境所在，偶尔听到外面竹林中传来几声清脆的鸟
叫，园子里种着各式各样的花。有绿菊（lvju），兰花（lanhua)，牡丹
（mudan）。。。。。。。
LONG 
	);
	set("exits", ([
		"out" : "/d/jingzhou/zizhulin7"
	]));


	set("objects",([
		"/d/jingzhou/obj/lvju" : 3,
	]));

	setup();
}

