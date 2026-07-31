// /d/taiyuan/nroad1.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "崛围山");
	set("long", @LONG
崛围山是太原的一处风景胜地。这里山势陡峻，松柏遍野，春日山花竞放，
秋来红叶满山。 “崛围红叶”是太原著名胜景之一。崛山寺前的东南山峰顶
处，建有多福寺和宋代七级舍利塔，寺内藏有寺观壁画。站在塔前，可俯瞰
太原全景。	
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "westdown":__DIR__"sroad3", 
                "northeast":__DIR__"sroad5", 
                
	]));
       setup();
	replace_program(ROOM);
}
