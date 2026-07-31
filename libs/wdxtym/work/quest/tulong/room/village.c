inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "精灵村落");
        set("long",HIG @LONG 
眼前是几处极为普通的村舍，几个精灵族的小孩子正在屋外追
逐打闹，几只肥肥的大白鹅，看见你来，伸长了脖子嘎嘎的叫，似
乎奇怪你居然找到了这里。这里每当夕阳西下的时候，厚厚的茅草
毡成的屋顶便会被淡淡的炊烟罩住，整个村里弥漫着一股诱人的米
饭的香味。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "south" : "/quest/tulong/room/lake",
   "west" : "/quest/tulong/room/spirit10",
   "east" : "/quest/tulong/room/zhanglao",
//  "northeast" : "/quest/tulong/room/liechang",
   ]));

        setup();
        replace_program(ROOM);

}

