// Room: fenghuo.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","气寒轩");
        set("long",@LONG
这里是凌霄城大弟子白万剑及其家人的住所。墙上挂着一副
中堂，上书“气寒西北”，笔法粗犷，显是名家手迹。桌上放着
一壶参阳玉酒，酒香四溢，一位面貌英俊的男子坐在桌旁，正悠
闲自得地修剪桌上的一盆梅花。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"houyuan2", 
        ]));
        
set("roomif","$botten#护卫任务|扫雪任务|完成扫雪|取消护卫:ask bai about huweijob|ask bai about job|ask bai about finish|ask bai about huweifail$#");	  
        
        set("objects", ([  
               "quest/menpaijob/lingxiao/bai-wanjian" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

