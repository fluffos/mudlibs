// /d/yazhang/shanghuang.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "商行");
	set("long", @LONG
你信步走进商行，只见正对门的招牌上写着“万有商行”几个商人
正在屋里付价还价，西南的小门好象是通向后院的帐房。
LONG
	);
set("exits", ([
                 "east" : __DIR__"nandajie2",  
                  "southwest" : __DIR__"zhangfang",    
	]));
 set("objects",([ __DIR__"npc/shangren":1,]));
       setup();
	replace_program(ROOM);
}	
