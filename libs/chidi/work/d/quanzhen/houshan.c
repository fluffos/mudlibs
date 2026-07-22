//houshan.c 后山 

#include <room.h>
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "后山");
        set("long", @LONG
这里是全真教的后山，两边是全真第子自己开发的农田，种着各种蔬菜。
往西有一条深沟，东面是一片青松林，林前立着一块牌子(paizi)。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
              "east" : __DIR__"qingsonglin1",
             "southdown": __DIR__"xiaolu2" 
        ]));

         set("item_desc",([
                "paizi"        :       "\n\t\t\t  \n\n\n" 
                                          HIR"\t\t∷∷∷∷∷∷∷∷∷\n"
                                          "\t\t∷　后     擅   ∷\n"
                                          "\t\t∷　            ∷\n"
                                          "\t\t∷　山     入   ∷\n"
                                          "\t\t∷　            ∷\n"
                                          "\t\t∷　禁     者   ∷\n"
                                          "\t\t∷　            ∷\n"
                                   "\t\t∷　地     死   ∷\n"
                                 " \t\t∷∷∷∷∷∷∷∷∷\n\n\n"NOR,
                                                        
                ]));



        
        setup();
        replace_program(ROOM);
}

