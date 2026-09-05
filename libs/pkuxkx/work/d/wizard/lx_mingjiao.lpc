//北侠名人堂——明教
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"明教BT纪念馆"NOR);
        set("long", HIR@LONG
这是明教的纪念馆，记载着明教的传奇：

    熊熊圣火，焚我残躯。生亦何哀，死亦何苦？

    为善除恶，惟光明故，喜乐悲愁，皆归尘土。

    怜我世人，忧患实多！怜我世人，忧患实多！
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/scarlet_npc": 1,
                __DIR__"laxiang/saviola_npc": 1,
                __DIR__"laxiang/tangguo_npc": 1,
                __DIR__"laxiang/tant_npc": 1,
                __DIR__"laxiang/univursal_npc": 1,
                __DIR__"laxiang/nrcc_npc": 1,
                __DIR__"laxiang/cid_npc": 1,
                __DIR__"laxiang/safeguard_npc": 1,
                __DIR__"laxiang/mosquito_npc": 1,
                __DIR__"laxiang/cxj_npc": 1, 
                __DIR__"laxiang/pkuhao_npc": 1, 
                __DIR__"laxiang/yadianna_npc": 1, 
                __DIR__"laxiang/ylei_npc": 1,
                __DIR__"laxiang/van_npc": 1,
        ]));
        set("room_location", "/d/changan/");
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

