// Room: /d/emei/sroad3.c  

inherit ROOM;

void create()
{
	set("short", "桃源村南");
	set("long", @LONG
你走在一条通往村中心的碎石路上，道路两旁分布着许多房屋，四周一
片寂静，偶而可听的几声犬吠，显的安静祥和。但每至傍晚这里却炊烟四起，
在夕阳的余辉下，务农的村人们竟相归来，一时间平静的小村落打破了别有
的寂静，格外的热闹。
LONG
	);

        set("exits", ([
              "south":__DIR__"sroad2",
              "north":__DIR__"center",
	]));
        set("outdoors", "emei");
	setup();
}
