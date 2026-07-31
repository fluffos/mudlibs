#include <room.h>
inherit ROOM;


void create()
{
        set("short", "澜沧江边");
        set("long", @LONG
你站在一处陡峭的山崖上，西边是个山谷，有上百丈深，谷底一条大江汹涌
地奔腾南去，气势非凡，巨大的声响回荡在山谷中；越过狭窄的山谷，对面山上
的一草一木都可看得清清楚楚，但要想过去就难了。一条山间小路从北面通过来
又向东边山里延伸开去。
LONG
        );
        set("exits", ([
		"southeast" : "/d/dali/wuliang/anbian",
                "north"  : __DIR__"shangu1",
        ]));
        set("item_desc", ([
                "down":  "大江南流的波涛巨响震得脚下的大地都颤动起来。\n",
        ]));
        setup();
        set("outdoors","xinan");
}
void init()
{        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( arg == "down"){
              message_vision("$N忽然纵身一跳，跃下了万丈深谷.\n"
                "奔腾的江水顿时吞没了$N藐小的身躯\n",me);
             me->die();
             command("rumor "+me->query_name()+"在澜沧江边跳江自杀了
\n");
             return 1;
          }
         else{
              write("这种危险的地方你还想跳？找死吗？要死跳下去(down)好了。\n");
             return 0;
          }
}
           
