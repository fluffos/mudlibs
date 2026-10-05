#include <ansi.h>
inherit ROOM;

void init();
int do_knock(string);
int do_say(string);
void reset();
void close(object);

void create()
{
        set("short", "小屋");
        set("long",
"这是一个普普通通的小屋，墙角一盆"HIR"盆景"NOR"(penjing)长
得很是旺盛。外面凄冷的月光从窗户射进来，映在盆景上，你才
发现盆景有些异样。\n");
        set("exits", ([
            "south": __DIR__"houyuan",
        ]));

        set("item_desc", ([
            "penjing" : "这盆景似乎很平常，独有其边沿特别光滑。敲一敲试试？\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_knock","knock");
        add_action("do_say","say");
}
int do_knock(string arg)
{
        object me;
        me=this_player();

        if (!arg || (arg!="penjing" ) )
           return  notify_fail("你要敲什么？\n");

        set_temp("marks/pen",1);
        message_vision("$N突然在盆景上敲了几下，$N干吗呀。\n",me);
        tell_object(me,"你好象听见下面有声音，可是下面什么都没有啊？！这何从说起呢？\n");
        return 1;
}
int do_say(string arg)
{
        object me;
        me = this_player();

        if (!query_temp("marks/pen")) return 0;
        if( !arg || arg=="" ) return 0;

        if (arg == "踏雪御风笑看江湖，覆雨翻云雄霸天下")
        {
                tell_object(me,"你既然知道暗号，就进来吧。\n");
                message("vision", "盆景边上的一堵墙渐渐移开，露出道木门。\n", this_player());
                set("exits/down", __DIR__"mishi");
                remove_call_out("close");
                call_out("close", 3, this_object());
                return 1;
        }
}

void close(object room)
{
        message("vision","忽然一道人影闪过，将木门关上了。\n", room);
        room->delete("exits/down");
}
void reset()
{
        ::reset();
        delete_temp("marks/pen");
}

