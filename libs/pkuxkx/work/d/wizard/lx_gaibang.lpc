//北侠名人堂——丐帮
// by hubo

inherit ROOM;
#include <ansi.h>

int block_cmd();
void create()
{
        set("short", HIY"丐帮BT纪念馆"NOR);
        set("long", HIW@LONG
这是丐帮的纪念馆，记载着丐帮的传奇：

    打 狗 棒 子 神 又 神
    
    上 打 天 子 下 打 臣
    
    扫 尽 天 下 不 平 事
    
    也 打 丐 帮 变 心 人

LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/hapi_npc": 1,
                __DIR__"laxiang/mengzhu_npc": 1,
                __DIR__"laxiang/yuge_npc": 1,
                __DIR__"laxiang/coolname_npc": 1,
                	__DIR__"laxiang/ppeng_npc": 1,
                	__DIR__"laxiang/arnold_npc": 1,
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

