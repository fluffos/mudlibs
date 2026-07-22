// /d/fuzhou/bridge.c 南门吊桥
// by xiaoyao
// Lklv modify 2001.9.10
inherit ROOM;

void quarter_pass();

void create()
{
        set("short","南门吊桥");
        set("long",@LONG
这是福州城南面的一座吊桥，从傍着晋江而建的城楼大门上以两个滑轮维
系。日出放下吊，日落绞起。过了桥向西南走可达岭南广东。
LONG);
	set("outdoors", "福州");
	set("exits",([
		"south"  : "/d/foshan/road14",
		"north"  : __DIR__"nanmen",
	]));
	set("no_clean_up", 0);
	setup();
        quarter_pass();
}

void quarter_pass()
{
	string local;
	local = NATURE_D->query_daytime();

	switch(local){
		case "event_night":
		case "event_midnight":
		set("long", @LONG
这里是福州的南门，往西南方向可以通往佛山镇，可惜近日劫匪四起，民
不聊生，故现在福州城外的吊桥已经放下，来往的过路人只能等到次日才能进
入城池。
LONG);
		delete("exits/north");
		break;
		default: set("long", @LONG
这是福州南面的一座吊桥，从傍着晋江而建的城楼大门上以两个滑轮维系。
日出放下吊，日落绞起。过了桥向西南走可达岭南广东。现在行人还多，来来
往往异常繁忙。
LONG);
		set("exits/north", __DIR__"nanmen");
		break;
	}
	call_out("quarter_pass", 60);
}
