//北侠名人堂——明教
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"明教BT蜡像馆"NOR);
        set("long", HIR@LONG
这里是明教的蜡像馆，在这里记载着明教的传奇：

熊熊圣火,焚我残躯。生亦何哀，死亦何苦？

为善除恶，惟光明故，喜乐悲愁，皆归尘土。

怜我世人，忧患实多！怜我世人，忧患实多！
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
        ]));
        setup();
}
void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{        
       string verb = query_verb();  
       if (verb=="say") return 0; //allow say     
       if (verb=="chat") return 0;                
       if (verb=="quit") return 0;                                                         
       if (verb=="look") return 0;                
       if (verb=="out") return 0; 
       return 1;                                  
}                                  
