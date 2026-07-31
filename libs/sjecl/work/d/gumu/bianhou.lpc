// Room: bianhou.c
// By River 98/08
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"匾后"NOR);
        set("long", @LONG
这里就是古墓中堂匾额之后，黑漆漆的什么都看不清楚。
LONG
    );
      
        set("objects",([
             __DIR__"obj/silkey" : 1,   
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump","jump");
        add_action("do_search", "search");
}

int do_jump(string arg)
{
        object me,room;
        me=this_player();  
        if (arg!="down") return 0;
        message("vision",me->name()+"一纵身，跳了下去。\n",this_object());
        if(room=find_object(__DIR__"gmzt"))
        message("vision",me->name()+"从匾额上跳了过来。\n",room);
        me->move(__DIR__"gmzt");
        return 1;
}

int do_search(string arg)
{
	object me,key;
	me = this_player();
	if(arg) return 0;
	key = unew(__DIR__"obj/silkey");
        if(!clonep(key)) return notify_fail("你来晚了，发现匾后什么东西也没有找到。\n");
        if(clonep(key) && key->violate_unique()){
           destruct(key);
           return notify_fail("你来晚了，发现匾后什么东西也没有找到。\n");
        }
        message_vision(HIB"$N当下仔细搜索，于匾后黑暗处发现了$n。\n"NOR, me, key);
        key->move(me);
	return 1;
}

void reset()
{
        object *ob;
        int i;
        ob = all_inventory(this_object());
        for(i=0; i < sizeof(ob); i++){
                if( userp(ob[i]) ) continue;
                ob[i]->reincarnate();
                if( !ob[i]->return_home() ) destruct(ob[i]);
        }
}
