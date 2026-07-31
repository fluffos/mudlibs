// /d/taiyuan/nroad1.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "山道");
	set("long", @LONG
你顺着大驿道向前走，渐渐的走进了山里，道路也开始颠簸不平起
来，道路顺着山的走势向前延伸，两边多是茂密的树林，偶尔还可以听
到林中鸟儿叫。	
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "southwest":__DIR__"sroad4", 
///                "northup":"/d/hengshan/daziling", 
                
	]));
       setup();
	replace_program(ROOM);
}
