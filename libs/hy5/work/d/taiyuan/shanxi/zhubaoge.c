#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", HIY"珠"+HIR"光"+HIM"宝"+HIG"气"+HIC"阁"NOR); 
        set("long", @long
酒筵摆在水阁中，四面荷塘一碧如洗，九回桥栏却是鲜红的。金阁的
面阔三间，宽敝高爽，厅名取朱熹：“一水方涵碧，千林以变红”之诗意。
厅前宽广的平台依临荷池，为夏日赏荷纳凉胜处，故称“荷花金阁”。阁后
有花台庭院，叠石种树，自成一景。
long); 
       // set("type","waterbody");
        set("exits",([
                
                "north":__DIR__"qiao",
        ]) );
        set("objects",([
                __DIR__"npc/sushaoying":1,
                __DIR__"npc/maxingkong":1,
        ]) ); 

       set("indoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-360);
        set("coor/z",100);
        setup();
} 