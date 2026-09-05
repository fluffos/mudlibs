//北侠名人堂——天龙寺
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"天龙寺BT纪念馆"NOR);
        set("long", HIW@LONG
这是天龙寺的纪念馆，记载着天龙寺的传奇：

    有           双           南            非
    
    常           树           北            假

    无           枯           西            非
    
    常           荣           东            空
 
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/benseqq_npc": 1,
                __DIR__"laxiang/nichqe_npc": 1,
                __DIR__"laxiang/reverse_npc": 1,
                __DIR__"laxiang/yuyi_npc": 1,
        	__DIR__"laxiang/batchelor_npc": 1,
                __DIR__"laxiang/qqaa_npc": 1,
                __DIR__"laxiang/thu_npc": 1,
                __DIR__"laxiang/trying_npc": 1,
                __DIR__"laxiang/afaccc_npc": 1,
                __DIR__"laxiang/slapu_npc": 1,
                __DIR__"laxiang/wzxb_npc": 1,
                __DIR__"laxiang/huyan_npc": 1,
		__DIR__"laxiang/passionx_npc": 1,
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

