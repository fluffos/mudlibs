//北侠名人堂——古墓
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"古墓派BT纪念馆"NOR);
        set("long", HIB@LONG
这是古墓派的纪念馆，记载着古墓派的传奇：

    终           活           神            绝
 
    南           死           雕            迹

    山           人           侠            江
    
    下           墓           侣            湖
 
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/terry_npc": 1,
                __DIR__"laxiang/baobei_npc": 1,
                __DIR__"laxiang/huangdaopo_npc": 1,
                __DIR__"laxiang/iceblade_npc": 1,
                __DIR__"laxiang/qianxue_npc": 1,	
                __DIR__"laxiang/luochunlan_npc": 1,	      
             		__DIR__"laxiang/yimei_npc": 1,	 
           			__DIR__"laxiang/lace_npc": 1,	    
         				__DIR__"laxiang/henryr_npc": 1,	  
                __DIR__"laxiang/qimengs_npc": 1, 	
                __DIR__"laxiang/yxy_npc": 1, 
                 __DIR__"laxiang/xmw_npc": 1, 
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

