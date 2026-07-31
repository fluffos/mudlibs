// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_ti(string arg);
int do_an(string arg);
void create()
{
        set("short", "井底");
        set("long", @LONG
这是在一口水井中。光线极暗，什么也看不清, 
你模模糊糊的感觉到旁边都是井壁,井水冰寒刺骨,
使你感到受骗的感觉,生出踢(ti)人的感觉!

LONG
        );
        set("exits", ([
                "up" : __DIR__"yuanzi",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_ti", "ti");
        add_action("do_an", "an");
}
int do_ti(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要踢什么东西!\n");
            if( arg=="wall" ) {
             write(
           "你踢了一脚,感觉好象踢中了什么东西,你可以试试按进去看看!\n");
             this_player()->set_temp("tiwall", 1);
             return 1;
       }
}
int do_an(string arg)
{
        object me;
        object room; 
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要按什么东西!\n");
  if( arg=="wall" ) {
        if (me->query_temp("tiwall") ) {
            message("vision", me->name() + "向半尺见方的石块用力按去,
发出了「轧轧」声响，在井底的窄长空间份外触耳。\n",
                    environment(me), ({me}) ); 
 message("vision","井璧缓缓凹陷下去，露出仅可容一人通过的入
口。 \n",
                    environment(me), ({me}) );
           if(!( room = find_object(__DIR__"jindi")) )
                  room = load_object(__DIR__"jindi"); 
        if(objectp(room)) 
            { 
  me->move(__DIR__"tongdao1");
message("channel:chat", HBRED"【海洋】"+me->query("name")+"成功进入杨公宝库!\n"NOR,users());
}
                            this_player()->delete_temp("tiwall");
            return 1;
        }
}
        else {
            write("你想按什么东西?!\n");
     return 1;
        }
}


