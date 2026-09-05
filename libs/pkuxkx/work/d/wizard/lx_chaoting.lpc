//北侠名人堂——朝廷
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"朝廷BT纪念馆"NOR);
        set("long", HIY@LONG
这是朝廷的纪念馆，记载着朝廷的传奇：

    三 尺 龙 泉 万 卷 书
    
    上 天 生 我 意 何 如
    
    不 能 治 国 安 天 下
    
    妄 称 男 儿 大 丈 夫

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/pigct_npc": 1,
                __DIR__"laxiang/pigctc_npc": 1,
                __DIR__"laxiang/buzy_npc": 1,
                __DIR__"laxiang/yiguo_npc": 1,
                __DIR__"laxiang/pixyee_npc": 1,
                __DIR__"laxiang/fordfocus_npc": 1,
                __DIR__"laxiang/henryz_npc": 1, 
                __DIR__"laxiang/hawks_npc": 1,  
                __DIR__"laxiang/deifystar_npc": 1,
                __DIR__"laxiang/tyhn_npc":1,
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

