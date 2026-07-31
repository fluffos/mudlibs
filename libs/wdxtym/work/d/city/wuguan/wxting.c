//wxting.c 文霞亭 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"文霞亭"NOR);
        set("long", @LONG
这是一个宝蓝色，琉璃顶盖儿的六角小亭。武馆里的内眷若是喜欢，闲着
无事，总喜欢在这里坐坐。亭子周围，花叶扶疏，秀石耸峙，奇花异草，间以
苍松翠柏，布置得甚为幽雅，透过一天星月，更似景致如画。南面有座假山。
LONG);       

	//set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([
            "west" : __DIR__"xiaojing2", 
            "south" : __DIR__"jiashan",              
        ]));       
 
        setup();
}
