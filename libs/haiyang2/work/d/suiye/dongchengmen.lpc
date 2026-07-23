// "suiye"/dongchengmen
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "东城门");
	set("long", @LONG
这里是碎叶的东城门。西面就到了城中，远望人头攒动，人还是很
多的东面通向中华内陆，城门下有一些执勤的武士。时下虽已天下太平，但
一干武士还是英姿勃勃，警惕的盯着往来人士。
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east"  : __DIR__"caoyuan1",
               
	]));
 set("objects",([ __DIR__"npc/guanbing":2,]));
       setup();
	replace_program(ROOM);
}	
