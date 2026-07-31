#include <ansi.h>
inherit ROOM;

void create()
{
set("short","开来");
set("item_desc",([ 
        "up" : "上方雾气缭绕，你什么也看不清。\n", 
]));
set("long",@LONG
你征战了半天，走到此处，不由浑身一松，感觉如释重负。
回想刚才种种，不禁感慨万千。
    迎面是一座石碑，上面龙飞凤舞的题着：
                開來題記
             求仙我欲到昆侖
             三重離火傷我身
             今生忘卻菩提樹
             素裹凝香自沈呤
             朝天彌勒肚無量
             人間獎懲不關心
             功名自在唯淨土
             往昔崢嶸複還真

LONG);
set("exits",([
        //"up"  : __DIR__"top",
]));
set("objects",([
        __DIR__"npc/learn" : 1,
]));
setup();
}       

void init()
{
object *inv;
int i,k,flag=0;
inv = all_inventory();
for(i=0;i<sizeof(inv);i++)
        {
        if ( userp(inv[i]) 
          && !inv[i]->query_temp("kailai_no_learn") ) 
                flag++;
        }
if ( flag>=10 )
        {
        k = 0;  
        inv = all_inventory();
        for(i=0;i<sizeof(inv);i++)
                {
                if ( !userp(inv[i]) )
                        continue;
                k++;
                if ( k>10 )
                        {
                        tell_object(inv[i],"半空传来一阵声音：开来业已人满为患，多余人等还是请回吧！\n");
                        inv[i]->set_temp("kailai_no_learn",1);
                        }
                }
        }
}               
