//room: /d/emei/sroad2.c

inherit ROOM;

void create()
{
	set("short", "桃源村南");
	set("long", @LONG
你走在一条通往村中心的碎石路上，道路两旁是两排长长的竹篱笆，在
后面是一间间房屋，可以看到许多大门向外敞开着。因为民风淳朴、村民关
系溶洽，时已到了路不拾遗、夜不闭户的程度。桃花村多年来与世隔绝，大
都自耕自养过着无忧无虑的生活。
LONG
	);

        set("exits", ([
              "south":__DIR__"sroad1",
              "north":__DIR__"sroad3",
             "west":"/d/emei/user-room/sunrise/home",
	]));
        set("outdoors", "emei");
	setup();
}
