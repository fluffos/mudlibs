// chanfang-3
// by zqb

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是诵经的禅房。房中有一座小香炉，淡淡的清烟从中散出，弥漫在
整间房内。阳光透过窗格照在青石地上，在青烟中形成根根耀眼的光柱。屋
中的地上散放着几个蒲团，几个年青的僧人正闭目打坐于其上。
LONG
	);
	set("exits", ([
		"north" : __DIR__"chanfang-1",
//              "south" : __DIR__"chanfang-1",
//              "east" : __DIR__"zdyuan",
	]));
//	set("objects", ([
//		"/d/village/obj/zhujian" : 1]));
set("objects",([
__DIR__"obj/fojing2"+random(2) : 1
]));
	set("no_fight", 1);
	
	set("coor/x",20);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}
