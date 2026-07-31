// Room: /d/fuzhou/wuyishan5.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "¾ÅÇúÏª");
	set("long", @LONG
Ó¯Ó¯Ò»Ë®£¬ÕÛÎª¾ÅÇú¡£Á½°¶Ê÷ÂÌÖñ´ä£¬Ææ·åÍ»Ø££¬ÕæÊÇ¡°Ïª
Á÷¾ÅÇúĞºÔÆÒº£¬É½¹âµ¹½şÇåÁ°äô¡±¡£
LONG );
	set("exits", ([
		"east"      : __DIR__"wuyishan2",
		"northup"   : __DIR__"wuyishan3",
		"northwest" : __DIR__"wuyishan4",
	]));
	set("resource/water", 1);
	set("objects", ([
		"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 

//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

