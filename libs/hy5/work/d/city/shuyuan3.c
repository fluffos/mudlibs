//Room: /d/city/shuyuan3.c 
string look_table();

inherit ROOM;

void create()
{
	set("short", "射雕院");
	set("long", @LONG
这是一间轩敞明净的大屋子，正中一张大书桌 (table)，上面摞了
几叠书。这里收藏了武侠大师金庸先生的主要作品，所有惊心动魄、婉
约深情的故事，由大师的生花妙笔娓娓道来。许多成名后的大侠时常来
这里走走、看看，回味自己漫长的江湖岁月中那些弥足珍贵的感受，以
自己坎坷的刀剑生涯印证大师的手笔，并写下自己走上江湖之路。夜深
人静时，如果您仍辗转难眠，不妨翻翻 (fan)这些书。楼下是飞雪堂，
收藏侠客行早期玩家的作品。
LONG);
	set("item_desc", ([
	    "table" : (: look_table :),
	]));
	set("exits", ([
	    "down" : __DIR__"shuyuan2new",
	]));
	set("no_fight", 1);
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 30);
	setup();
}

