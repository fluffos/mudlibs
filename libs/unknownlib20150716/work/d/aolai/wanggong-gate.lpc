inherit ROOM;

void create ()
{
	set ("short", "王宫大门");
  	set ("long", @LONG
王宫大门庄严肃穆，金壁辉煌，宫墙里面殿阁高大雄伟，层
层叠叠，琉璃瓦白玉掾富丽堂皇。此刻宫门紧闭，门前守卫
着几位金甲武士。
LONG);
	set("objects", ([
  		__DIR__"npc/weishi" : 3,
	]));
  	set("outdoors","aolai");
  	set("exits", ([ 
  		//"south" : __DIR__"chaoyangmen",
  		"north" : __DIR__"south3",
	]));
	setup();
}
