 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "厢房");
        set("long", @LONG
整个庄园，就只有这里还保持着洁净幽雅，只因这里是庄主夫人
的房间。虽然整个庄园的人都有点不太正常，但依然没有人敢造次闯
入此间。房间里的家具并不多，靠墙而立的大衣柜因此特别显眼。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lang2",

   ]));



        set("objects", ([
       
        __DIR__"npc/jifuren" : 1,
                        ]) );

        set("NONPC",1);
        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-395);
        set("coor/z",0);
        set("coor/x",-5);
        setup();
} 


void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/enter") ) return;
        message("vision",
"「吱」得一声，大衣柜门忽然关上。\n",
                this_object() );
                delete("exits/enter");
}  
int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="door" || arg =="大衣柜" || arg=="衣柜门") {
                write("试着拉了拉衣柜的门，");
        if( (int) me->query("neili") >= 120 )
                {
                write("大衣柜里面原来是空的，下面还有条暗道。\n");
                if( !query("exits/west") ) {
                set("exits/enter", __DIR__"gui");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("但费了很大劲也没有拉开。\n");
                return 1;
        }
                write("你要拉开什么？\n");
                return 1;
} 
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "enter" && ob=present("ji furen", this_object()))
        {
        message_vision("$N疯了似的扑向$n：你居然发现了我的秘密？！！\n", ob,me);
        ob->kill_ob(me);
        return notify_fail("不好，这个疯婆子发疯了！\n");
        }
        else
                return 1;
}