#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "花径");
        set("long",@LONG
这是一片谷底的小路。四周一望无际，全是盛开的鲜花。微风拂过，
蜜蜂到飞舞。香气逼人。往北是一片玫瑰花，往南则是一片紫罗兰。
LONG
        );
       set("exits", ([
     "south" : __DIR__"xiaojin",
     "north" : __DIR__"yihua0",
]));
//	set("objects", ([
//        "" : 1,
//	__DIR__"npc/" : 1,
//   ]) );
    
        set("outdoors","yihua");

        setup();
}
void init()
{       object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/south")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 100 )
        {
        delete("exits/south");
        set("exits/south", __DIR__"yihua_out");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "移花宫")
        {
        delete("exits/south");
        set("exits/south", __DIR__"yihua_out");
	return ;
        }         
	delete("exits/south");
        set("exits/south", __DIR__"yihua0");
}
