#include <ansi.h>
inherit ROOM; 
int blinding(object me);
int bbqthem(object me, object obj); 
void create()
{
        set("short", "杂货铺仓房");
        set("long", @LONG
太平杂货铺实在是个标标准准的杂物铺，刷墙的白粉，各色各样的桐油和漆，
冰糖，花生，大米，小米，鸡蛋，鸭蛋，花粉，针线，鞋子，布匹，旱烟，老酒。。
只要你能想得到的东西，这里都有，连你想不到的东西这里都有。一间好大好大的
屋子里，堆满了五花八门，各式各样的东西，甚至还有一大捆已生了锈的刀枪，和
一大堆线装的旧画。
LONG
        );
        set("exits", ([ 
                "east":  __DIR__"mroad3",
                "west": __DIR__"zahuo2",
        ]));
        set("item_desc", ([
        
         ]));
         set("objects", ([
                __DIR__"npc/oldworm" : 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
             
