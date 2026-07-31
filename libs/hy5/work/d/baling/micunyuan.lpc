// baling/nandajie3
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "觅春院");
	set("long", @LONG
厅不大，但很是热闹，好多公子少爷都在这里，龟公在伺候着。墙
上挂着纣王寻欢图，阵阵娇笑之声从楼上传来，不时还加杂着一两声令
你无比兴奋的呻吟。你不由自主的加快了步伐。
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"westdown":__DIR__"nandajie2",
                "up":__DIR__"xunhuange",
	]));
	setup();
	
}

int valid_leave(object ob,string dir)
{
  if(ob->query("age")<18&&dir=="up"&&!wizardp(ob))
  return notify_fail("小孩子还是不要到那种地方去！\n");
  return ::valid_leave(ob,dir);
}
