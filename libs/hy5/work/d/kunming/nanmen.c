// nanmen  by netkill

inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
这里是昆明的南门，高高的城楼上写着大大的"南门"两个字，
由此南去，就是安南了，出入南门的人很少，只有些渔民不时提
着新鲜的鱼进城来卖。最近南门由于强盗不断，被关闭了。  
LONG
	);

	set("exits", ([
		"south" : "/d/yanping/gudao1",
		"north" : __DIR__"nandajie2",
		"southwest" : "/d/lumaji/lu1",	
		
	]));

	
	setup();
	replace_program(ROOM);
}

