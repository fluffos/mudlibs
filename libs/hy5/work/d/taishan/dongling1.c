// Room: /d/taishan/dongling1.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "东灵后殿");
	set("long", @LONG
这里是泰山派的根本重地。殿内布置肃穆，正中神案上泰山派开派
祖师东灵道长的牌位和画像。神案上香炉里插着三柱清香，香烟袅袅上
升，散发着一股檀香味。
    后殿现在是泰山派弟子练功的休息间。
LONG );

	set("sleep_room", 1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("exits", ([
		"south"    : __DIR__"dongling",	
	]));
        set("objects", ([
               "/kungfu/class/taishan/dongling" : 1,
       ]) );
	
	set("coor/x", 390);
	set("coor/y", 780);
	set("coor/z", 190);
  set("door_name","殿门");
	set("door_dir","south");
	set("force_name","迟百城");
  set("outroom",__DIR__"dongling");
	setup();
}
