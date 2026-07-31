// story:shenzhao 凝血神爪

#include <ansi.h>

int give_gift();


mixed *story = ({
        "电母：这...这是啥？",
        "雷公：怎么了你？",
        "电母杏目圆睁：岂有此理！快说，你背地里都瞒着我干些什么？",
        "雷公：变态！",
        "电母：你...",
        "...",
        "嘿...",
        "哎呦...",
        "噼哑！！！！！！！！！！！～～～～～",
        (: give_gift :),

});

void create()
{
        seteuid(getuid());
}



mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
         
        int i;
        object env,ob;
        object *players;
                object gob;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                                
                }
        if(!ob) return 1;
        if (ob->query("gift/lighting") || random(5))
        {
        CHANNEL_D->do_channel(this_object(), "rumor", HIR"只见" +ob->name(1) +
                              "一声惨叫，软软的倒了下去。"NOR);
//                msg = HIR + ob->name(1) + "一声惨叫，软软的倒了下去。" NOR;
                if (ob->query("combat_exp") < 1000000 ||
                    ob->query("qi") < 1000)
                        ob->unconcious();
                else
                {
                        ob->set("qi", 10);
                        ob->set("eff_qi", 10);
                        ob->set("jing", 1);
                        ob->set("eff_jing", 1);
                }
        } else
        {
if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", HIC"霎那间" +ob->name(1) +
                              "浑身火花四射，犹如天神一般，神威凛凛。"NOR);
}
//                msg = HIC "霎那间" + ob->name(1) + "浑身火花四射，犹如天神一般，神威凛凛。" NOR;
                ob->add("con", 1);
                ob->add("gift/lighting", 1);
        }
//        message_vision(msg);
//
//        return msg;

if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "被雷打中了。");
}
        STORY_D->remove_story("new12");
      }
        return 1;
}