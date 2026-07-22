// /d/wudang/xuanyuemen.c 玄岳门
// By River@SJ

#include <ansi.h>
#include <wanted.h>

inherit ROOM;

void create()
{
        set("short", HIY"玄岳门"NOR);
        set("long", "你的面前就是天下闻名的武当山，它是一座林木繁茂的高山，几座山峰被
云雾笼罩，难见全貌。一条石阶盘延向上，隐约可见几个进香客。一座古牌石
坊(fang)面山而立。武当山又名太和山，为七十二福地之一，有二十七峰、三
十六岩、二十四涧、五台、五井、三潭、三天门、三洞天和一福地，百里内密
树森罗，蔽日参天，景物幽绝。而这玄岳门是武当派迎接来客的第一站。
"HIG"\n\t\t\t  武  当  山\n\n"NOR
        );

        set("exits", ([
                "east" : __DIR__"wdroad8",
                "southup" :__DIR__"shijie1",
        ]));
        set("outdoors","武当");
        set("item_desc", ([
                "fang" : HIG"\n
                    　※※※※※※※※
                　    ※※※※※※※※   
                      ※※        ※※  
                      ※※   武   ※※　 
                      ※※        ※※　 
                      ※※        ※※　                         
                      ※※   当   ※※  
                      ※※        ※※　                          
                      ※※        ※※　　　　　　　　　　　　　 
                      ※※   山   ※※
                      ※※        ※※ 
                      ※※※※※※※※
                      ※※※※※※※※\n\n"NOR,
        ]));
        
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "southup" && is_wanted(me)) return 0;
        return ::valid_leave(me, dir);
}
