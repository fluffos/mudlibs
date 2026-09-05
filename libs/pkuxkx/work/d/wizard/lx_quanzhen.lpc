//北侠名人堂——全真
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"全真派BT纪念馆"NOR);
        set("long", HIG@LONG
这是全真派的纪念馆，记载着全真派的传奇：

    一住行窝几十年   蓬头长日走如颠 

    海棠亭下重阳子   莲叶舟中太乙仙

    无物可离虚壳外   有人能悟未生前

    出门一笑无拘碍   云在西湖月在天

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/abda_npc": 1,
                __DIR__"laxiang/cfa_npc": 1,
                __DIR__"laxiang/titan_npc": 1,
                __DIR__"laxiang/yxfyg_npc": 1,
                __DIR__"laxiang/erty_npc": 1,
                __DIR__"laxiang/xiaoyuxue_npc": 1,
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

