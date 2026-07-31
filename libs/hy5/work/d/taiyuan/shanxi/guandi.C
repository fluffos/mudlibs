// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
inherit ROOM;
void create()
{
	set("short", "关帝庙");
	set("long", @long
此处北靠盐池，面对中条，内外古柏苍翠，四周桃林繁茂，大有叁
结义的桃园风趣，景色秀丽，百花争艳。庙门前以一块刻上「气肃千秋」
四字的黄石作为屏障。
long );
	set("exits", ([
  
    "north" : __DIR__"huanghe2",
  
	]));
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
		__DIR__"npc/xiucai2" : 1,
	]));
//	set("no_clean_up", 0);
	        set("indoors", "shanxi");
        set("coor/x",-400);
        set("coor/y",-450);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
}
