inherit ROOM;

void create()
{
        set("short", "松江县");
        set("long", @LONG
这里就是著名的华亭镇边上的松江县，华亭镇的粮仓，也
是富商大贾云集之所，由华亭镇商会控制。
LONG
        );


	set("exits",([
	"east" : __DIR__"lu13",
]));
  	set("objects",([
"quest/skills2/wunon/non/nontian" : 3,
	"/clone/npc/man" : 2,
]));

 
        setup();
}

