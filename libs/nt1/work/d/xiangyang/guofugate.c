// Room: /d/xiangyang/guofugate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "¹ù¸®´óÃÅ");
	set("long", @LONG
Ò»×ù½¨Öş¹ÅÆÓµÄ´óÕ¬Ôº³öÏÖÔÚÄãµÄÑÛÇ°¡£Ö»¼ûÃÅÂ¥¸ßÌô£¬ÉÏÊéÁ½¸ö´ó
×Ö[1£»33m¹ù¸®[2£»37£»0mÈ«Õæ½ÌµÚ¶ş´úµÜ×ÓÒ®ÂÉÆëºÍ¼¸¸ö¼Ò¶¡Õ¾ÔÚÃÅ
Ç°½Ó´ıÇ°À´±£ÎÀÏåÑôµÄ¸÷·½ÒåÊ¿¡£
LONG );
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"westjie1",
		"north" : __DIR__"guofuyuan",
	]));
	set("objects", ([
		__DIR__"npc/yelvqi" : 1,
		__DIR__"npc/jiading" : 2,
	]));
	setup();
	replace_program(ROOM);
}

