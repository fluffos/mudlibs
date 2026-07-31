// 杀手任务
// derondog@ZLZY

object  target;
#include <copy_player.h>

string ask_job()
{
        string *yz = ({
                "/d/city/guangchang",
                "/d/city/wumiao",
                "/d/city/zuixianlou",
                "/d/city/yaopu",
                "/d/city/datiepu",
                "/d/city/lichunyuan",
                "/d/city/chaguan",
                "/d/city/caizhu",
                "/d/city/wuguan",
                });

        object me = this_player();
        string str;
        int life_time = 200 + random(200);

        if ( me->query("quest/type")=="杀人" )
                return "我不是给了你任务了吗？\n";

        if ( me->query("quest") )
                return "你还有其他的任务吧？”\n";

        if ( me->query("fail_time") && me->query("fail_time") + 300 > time() )
                return "你上一次任务失败了，你还是回去好好反省吧！”\n";

        me->set("quest/type", "杀人");
        me->set("quest/task_time", time() + life_time);
        target = new(__DIR__"quest_npc");
        target->set("born", time());
        target->set("life", life_time);
        copy_player(me, target, 1);
        switch(random(3)) {
                case 0:
                        str = CYN "来得正好，我最近生意比较忙，你就去扬州帮我杀一个叫"+target->name(1)+"的人吧！不要让我失望哦。\n" NOR;
                        target->move("/d/city/guangchang");
                        target->set("num", 0);
                        me->set("quest/num", 0);
                        break;
                case 1:
                        str = CYN "来得正好，我最近生意比较忙，你就去扬州帮我杀一个叫"+target->name(1)+"的人吧！不要让我失望哦。\n" NOR;
                        target->move(yz[random(sizeof(yz))]);
                        target->set("num", 1);
                        me->set("quest/num", 1);
                        break;
                case 2:
                        str = CYN "来得正好，我最近生意比较忙，你就去扬州帮我杀一个叫"+target->name(1)+"的人吧！不要让我失望哦。\n" NOR;
                        target->move("/d/city/guangchang");
                        target->set("num", 2);
                        me->set("quest/num", 2);
                        break;
                }
        return str;
}

string ask_fail()
{
        object me = this_player();
        
        if ( me->query("quest/type")!="杀人" || !me->query("quest") )
                return "你脑袋有包啊？我什么时候叫你帮我杀人了？";

        if ( objectp(target) ) {
                message_vision("你似乎看到一个人影冲了过来，对着$N出了一剑……。", target);
                target->die();
                }

        me->delete("quest");
        me->set("fail_time", time());
         message_vision("$N急急忙忙地离开了。\n$N走了过来。\n", this_object());
        return "他妈的，又要老子亲自出马。";
}

