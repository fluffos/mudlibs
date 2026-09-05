// wdroad6.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。
这里是湖北境界，据说经常有土匪出没，不可久留。
LONG
	);
	set("main_dir", __DIR__"");
	set("exit", ([ /* sizeof() == 1 */
		  "west" : __DIR__"tufeiwo2",
		]));

	set("exits", ([ /* sizeof() == 3 */
		  "southeast" : __DIR__"guandao3",
		  "west" : __DIR__"wdroad7",
		  "north" : __DIR__"vroad1"
		]));
    
	set("outdoors", "wudang");
	setup();
//	replace_program(ROOM);
}
void init()
{
	if( interactive(this_player()))
	if(random(6)==1)
	{	delete("exit/west");
		set("exit/west",__DIR__"tufeiwo2");
	}
}

