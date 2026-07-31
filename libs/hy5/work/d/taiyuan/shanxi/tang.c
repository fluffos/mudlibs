#include <room.h>
inherit ROOM;
void close_path();
void create()
{
        set("short", "灵堂");
        set("long", @long
一片松柏造景映入眼帘，简单典雅，没有繁复花俏的设计。灵堂中间是一
副上好的柳州棺木，後方挂了块白布挂帘，前方放了一尊琉璃观音，右侧是长
青的松柏，左侧则是在寒冷中坚忍不拔的梅竹，两行题字「示甘露道使清凉，
随众生心而化诱」，概念来自金刚经，象徵极乐世界。
long
        );
        set("exits", ([
               // "down" : __DIR__"fyge",
                "south" : __DIR__"hyuan",
        ]));
        set("objects", ([
                __DIR__"npc/tianqing": 1,
        ]) );
        set("item_desc", ([
                "curtain": "这个白布挂帘似乎可打开(open)。\n",
                "挂帘" : "这个白布挂帘似乎可打开(open)。\n",
                "白布挂帘" : "这个白布挂帘似乎可打开(open)。\n"
        ]) );
        //set("NONPC",1);
set("coor/x",-500);
        set("coor/y",-320);
        set("coor/z",100);
        setup();
//        create_door("east", "    ", "west", DOOR_CLOSED); 
} 
void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/north") ) return;

        message("vision",
               "白布挂帘轻轻落了来，挡在门前。\n",
                this_object() );
                delete("exits/north");
}  
int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="curtain" || arg =="白布挂帘" || arg=="挂帘") {
                write("你掀开白布挂帘，");
        if( (int) me->query("neili") >= 1000 )
                {
                write("轻轻推开了木门。\n");
                if( !query("exits/west") ) {
                set("exits/north", __DIR__"tolou1");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("推了推门，但门纹丝不动。\n");
                return 1;
        }
                write("你要打开啥？\n");
                return 1;
} 
/*int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "north" && ob=present("huo tianqing", this_object()))
        {
        message_vision("$N对$n喝道：  麽  □      摸摸想进  ，    ！！\n", ob,me);
        ob->kill_ob(me);
        //return notify_fail("快  ！\n");
        }
        else
                return 1;

} */  
