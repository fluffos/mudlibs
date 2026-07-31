//liangongfang.c 练功房
//edit by snow
inherit ROOM;
#include <ansi.h>
void create()
{
           set("short",YEL"练功房"NOR);
           set("long",@LONG
这里是练功房，地上放着几张蒲团，几名绝情谷弟子在这里吐纳练功，练
功房的四个角上各放着一只香炉，房内弥漫着一股淡淡的香气。
LONG
);          
           set("exits",([
               "north": __DIR__"lang2",
           ]));

           setup();
           replace_program(ROOM);
}
