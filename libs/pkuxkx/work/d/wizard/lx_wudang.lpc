//北侠名人堂——武当
// by hubo
inherit ROOM;
#include <ansi.h>
int block_cmd();
void create()
{
        set("short", HIY"武当派BT纪念馆"NOR);
        set("long", HIC@LONG
这是武当派的纪念馆，记载着武当派的传奇：
    太和瑞气绕仙踪,灵童玉女影叠重.
    魂借真武倚北宿,意念天尊仗龟龙.
    二十四涧心止水,七十二壑身飞空.
    玄武剑挡妖魔障,修炼不入是非中.
LONG
NOR);
        set("exits", ([
                "out" :"/d/wizard/laxiang",
        ]));
        set("objects", ([
                __DIR__"laxiang/neuton_npc": 1,
                __DIR__"laxiang/swindy_npc": 1,
                __DIR__"laxiang/lkyun_npc": 1,
                __DIR__"laxiang/ark_npc": 1,
                __DIR__"laxiang/henryf_npc": 1,
                __DIR__"laxiang/grla_npc": 1,
                __DIR__"laxiang/wuhun_npc": 1,
                __DIR__"laxiang/xiaofei_npc": 1,        
                __DIR__"laxiang/durer_npc": 1,  
                __DIR__"laxiang/dxf_npc": 1,  
                __DIR__"laxiang/bluecmy_npc": 1,        
                __DIR__"laxiang/sbear_npc": 1,     
                __DIR__"laxiang/hnhd_npc": 1,   
                __DIR__"laxiang/dunyi_npc": 1,
                __DIR__"laxiang/yhzzyahoo_npc": 1, 
                __DIR__"laxiang/laobeng_npc": 1,        
                __DIR__"laxiang/danfeng_npc": 1,   
                __DIR__"laxiang/stevenson_npc": 1,
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

