// mumen.c 墓门
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "墓门");
        set("long", @LONG
你走过了草地，眼前突然了一片开阔地，突兀地耸立着一座大墓，
墓上砌的石头已经班驳了，看的出来这是座古墓。墓前没有立碑，也
没有任何的标记，不知道这是前朝哪位王公大臣的墓穴。墓门口被一
块黑黝黝的大石头(shi)封闭得丝毫不透。
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "north" : __DIR__"caodi",
                "west"  : __DIR__"huangshalin",
        ]));

        set("objects", ([
           __DIR__"npc/gumudizi" : 2,
                __DIR__"npc/yufeng" : 1+random(3),
        ]));

        set("item_desc", ([
        "shi": "这是块巨石，怕不有万斤上下，好象锩着‘"+YEL"降龙石"NOR+"’几个字。\n"
        ]) );

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_move", "move");
}


int do_move(string arg)
{
        object me=this_player();

        if( !arg || arg != "shi" ) {
                return notify_fail("你要移动什么？\n");
        }

        if((int)me->query_str()>33) //膂力大于33
                {
                message_vision("$N站在石前，双掌发力推动巨石，只听得巨石吱吱连声，\n",this_player());
                message_vision("缓缓向后移去，现出一道门户来。\n", this_player());
                set("exits/south", __DIR__"qianting");
                remove_call_out("close");
                call_out("close", 5, this_object());
                }
        else
                message_vision("$N试着推了推巨石，巨石纹丝不动，只得罢了。\n", this_player());
        return 1;
}

void close(object room)
{
        message("vision","只见巨石又吱吱地回到原地。\n", room);
        room->delete("exits/south");
}
