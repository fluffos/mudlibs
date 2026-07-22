//stoneroad1.c

inherit ROOM;

void create()
{
	set("short", "石板路");
        set("long",@LONG
一条整齐四通八达的石板路。这里是全寺的正中央，亦是寺中交通最繁
忙的地方，由此向南可达大雄宝殿。向北是大悲殿。向东向西辗转可达龙树
院戒律院等寺中要地。
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
	"west" : __DIR__ "huaishu4",
        "north" : __DIR__"dabeidia",
        "south" : __DIR__ "daxiong",
        "east" : __DIR__ "songshu2",
          ]));
        set("objects",([
          CLASS_D("shaolin") + "/hui-ru" : 1,
          __DIR__"npc/seng-bing3" : 2,
         
      ]));
	set("coor/x",50);
  set("coor/y",310);
   set("coor/z",120);
   setup();
}



