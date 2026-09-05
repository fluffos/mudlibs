// room: /d/xingxiu/tianroad3.c
// Jay 3/18/96

inherit ROOM;

void init();
int do_jump(string);
int do_home(string);

void create()
{
        set("short", "黄河平原");
        set("long", @LONG
这里是靠近黄河源头的一片广袤的平原，黄河之水行进至此因地势平缓，
河面骤然展宽，流速也变缓，四处流淌的河水，使这里形成大片沼泽和众多的
湖泊。一条深涧(valley)横亘眼前。西北方向有一条大河拦住了你的去路。
LONG
        );
        set("exits", ([



          "northwest" : "/d/huanghe/hhn19",
            "eastdown" : __DIR__"tianroad1",
]));
        set("item_desc", ([
                "valley" : "深涧有三丈多宽，不知道能不能跳(jump)过去。\n"
        ]) );


        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_jump", "jump");
}


int do_home(string arg)
{
object me;
me=this_player();
          if( !arg || arg=="" ) return 0;
         if( arg=="xgz" ) {
                          me->move("/u/bing/workroom");
return 1;
}
}

int do_jump(string arg)
{
        object me,ma;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="valley" ) {
                if (present("yili ma", environment(me)))  { 
                    ma=present("yili ma",environment(me));
                    if (ma->query_temp("rider")==me)
                    {
                    
                        message("vision", me->name() + 
                          "猛地一提缰绳，胯下的伊犁马一声长嘶越过了深涧。\n",
                           environment(me), ({me}) );
                        write("你猛地一提缰绳，胯下的伊犁马一声长嘶越过了深涧。\n");
                        me->move("/d/xingxiu/tianroad4");
                        message("vision", "只听得唏溜溜一声马嘶，" + 
 me->name() +  "从深涧的那端纵马跳了过来，好似当年马跳\n檀溪的玄德公。\n",
                        environment(me), ({me}) );
                        write("只听得唏溜溜一声马嘶，你从深涧的那端纵马跳了过来，"
                              "真是酷呆了。\n你乐得从马背上滚了下来。\n");
                        me->set_temp("marks/骑", 0);
                        return 1;
                    }
                    else
                    {
                        write("你试了试，发现深涧的那边比这边高，非是人力可以跳上去的。\n");
                        return 1;
                    }
                }
                else {
            write("你试了试，发现深涧的那边比这边高，非是人力可以跳上去的。\n");
                        return 1;
                }
        }
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}