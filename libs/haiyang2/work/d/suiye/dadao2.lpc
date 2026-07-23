// "suiye"/dadao2.c
// Room in 碎叶
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "大草原");
	set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还
真不好走，看来买匹马来代步到是的好主意。
LONG
        );
set("outdoors", "suiye");
set("exits", ([
                "north":__DIR__"dadao1",  
                "south":"/d/mayi/beimen",  	
                "northeast":__DIR__"caoyuan",  
                 "southwest":"/d/xingxiu/shamo3",    
	]));
 set("objects",(["/clone/npc/man":2,]));
       setup();
	replace_program(ROOM);
}
