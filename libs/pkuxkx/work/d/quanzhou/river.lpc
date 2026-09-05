#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", GRN "河岸" NOR);
        set("long", @LONG
江南水乡之地到处河泊纵横，前面是小河拦路，无法再行。后面是一
片绿柳林，传出阵阵花香鸟鸣。左边一架小桥，从桥下几叶小舟，隐隐可
以听见少女们正唱着那宛转动人的江南小调。
LONG);
 
        set("no_sleep_room", 1);

        set("couldfish",1);
        set("exits", ([
              "east" : __DIR__"xiaojing",
			  "northwest" : __DIR__"matou",
        ]));

        set("outdoors", "嘉兴");

        setup(); 

}

void init()
{   object me = this_player();
    int luck = me->query_temp("oyf_meet");
        if (userp(me))
      me->add("jingli", -10);
      if(!me->query("oyf_son") ) {
       if(random((int)me->query("kar")) <= 2 
          || random((int)me->query("kar")) >= 20 
          || me->query("oyf_fail") >= 10){
        if(!luck &&
          me->query_condition("bing_poison") > 30 &&          
          me->query("age") < 19){
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n");
          me->set_temp("oyf_meet", 1);
          }   
        if (luck >= 1) {
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n"); 
          me->add_temp("oyf_meet", 1); 
          }
        if (luck >= 10 && userp(me)) {
          write("忽听背後一人说道：「小娃娃，知道厉害了罢？」这声音铿锵刺耳，似从地底下钻出来一般。\n");
          message_vision("\n$N好象被什么东西一惊，回头便发足狂奔。\n",me);         
          me->delete_temp("oyf_meet");
          me->set_temp("oyf_meet1", 1); 
          call_out("wait", 10, me);         
          }
        }    
     }                         
}

void wait()
{
        object me;
        int total, try;
        me = this_player();
        if (objectp(me)&&!living(me)) return;
        total = me->query("kar")+me->query("per")+me->query("con");
        try = me->query("oyf_fail");
         if(random(total) >= 55 || random(total) <= 5 || me->query("oyf_fail") >= 10){
        message_vision("$N只觉手臂麻木，早已不听使唤，只急得大汗淋漓，
不知如何是好，慌乱中跑进了柳树林子。\n",me);
        me->set_temp("oyf_see", 1); 
        me->delete_temp("oyf_meet1");
        me->move(__DIR__"river1");
        return;
        }
        else {
          if(!try) {
                me->set("oyf_fail", 1);    
                message_vision(HIR"$N脚下突然一软，骨碌碌地滚出了数十丈！\n"NOR,me);
                me->delete_temp("oyf_meet1");     
                me->move(__DIR__"shulin");
                me->receive_wound("qi", 100, "脚发软滚出数十丈摔");
                tell_room(environment(me), HIR + me->name()+"骨碌碌地滚了过来，躺在地上半天爬不起来！\n" NOR,
                ({ me }));    
                return;
                }
           else {
                me->add("oyf_fail", 1);    
                message_vision(HIR"$N脚下突然一软，骨碌碌地滚出了数十丈！\n"NOR,me);
                me->delete_temp("oyf_meet1");     
                me->move(__DIR__"shulin");
                me->receive_wound("qi", 100, "脚发软滚出数十丈摔");
                tell_room(environment(me), HIR + me->name()+"骨碌碌地滚了过来，躺在地上半天爬不起来！\n" NOR,
                ({ me }));        
                return;
                }     
        }
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("oyf_meet1") &&
            dir == "east")
                return notify_fail("忽听呼的一声响，一个人影从你头顶跃过，落在你身前。\n");
        return ::valid_leave(me, dir);
}
