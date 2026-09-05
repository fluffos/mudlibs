// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_app, pre_master;
        mapping family, skills, menpai, my_menpai;
        int i, t;
        string *skname, st;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( !arg ) 
                return notify_fail("指令格式：apprentice | bai [cancel]|<对象>\n");
// add by aiai
        if ( (me->query("menpai/gen")== 1) && ( ! ( arg == "long" || arg == "long yifan" ) ) )
                return notify_fail("你想要拜别人为师，，还是先把你自己创建的门派解散吧。\n");
                
        if( arg=="cancel" ) {
                old_app = me->query_temp("pending/apprentice");
                if( !objectp(old_app) )
                        return notify_fail("你现在并没有拜任何人为师的意思。\n");
                write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                me->delete_temp("pending/apprentice");
                return 1;
        }

        if( !(ob = present(arg, environment(me)))
        ||      !ob->is_character() )
                return notify_fail("你想拜谁为师？\n");

        if( !living(ob) ) 
                return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

        if( ob==me ) 
                return notify_fail("拜自己为师？好主意....不过没有用。\n");
// by aiai        
        if ( ( me->query("menpai/gen" ) > 1 ) )
                return notify_fail("你已经拜了"RED+me->query("menpai/master_name")+NOR"哪好再一声不响地拜了别人呢？如果你真的不想干了，还是让你的师傅把你开除算了。\n");
                        
        if( userp(ob))
// modify by aiai for selfcreate class plan
//              return notify_fail("对不起，现在不能拜玩家为师了！\n");
                if ( ob->query("menpai/gen") == 1 )
                {
                        if ( me->query("combat_exp") <= 200000 )
                                return notify_fail("只有这点功夫就想要拜别人为师，不太好意思吧。\n");
                        if ( ( t = sizeof( ob->query("menpai/tudi") ) ) == 3)
                                return notify_fail(ob->query("name")+"已经收了足够多的徒弟了，你还是令投他人吧。\n");
                } 
                else    return notify_fail("你拜的这位英雄还没有创建自己的门派，你还是另投名师吧。\n");


        if( me->is_apprentice_of(ob) || me->query("menpai/master_id") == ob->query("id") ) {
                message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);
                if (! userp(ob) )
                        ob->re_rank(me);
                return 1;
        }
// aiai
        if( !mapp( ob->query("family") ) &&  ob->query("menpai/gen")!=1 )
                return notify_fail(ob->name() + "既不属於任何门派，也没有开山立派，不能拜师。\n");

        // If the target is willing to recruit us already, we do it.

        if( (object)ob->query_temp("pending/recruit") == me ) {

                if( me->query("family") ) 
                {
                        message_vision(
                                "$N决定背叛师门，改投入$n门下！！\n\n"
                                "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",
                                me, ob);
                        me->set("score", 0);
                         if ( me->query("combat_exp") >= 1000 ) me->add("betrayer", 1);
                        
                } else
                        message_vision(
                                "$N决定拜$n为师。\n\n"
                                "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",
                                me, ob);
                if ( !userp(ob))
                {
                        ob->recruit_apprentice(me);
                        ob->delete_temp("pending/recruit");

                        tell_object(ob, "恭喜你新收了一名弟子！\n");
                        family = me->query("family");
                        printf("恭喜您成为%s的第%s代弟子。\n", 
                        me->query("family/family_name"),
                        chinese_number( me->query("family/generation")));
                        return 1;
                }
                else{
                        my_menpai = ob->query("menpai");
                        menpai = allocate_mapping(sizeof(my_menpai)+1);
                        menpai["name"] = my_menpai["name"];
                        menpai["place"] = my_menpai["place"];
                        menpai["gen"] = 2;
                        menpai["master_id"] = ob->query("id");
                        menpai["master_name"] = ob->query("name");
                        me->set("menpai",menpai); 
                        ob->delete_temp("pending/recruit");
                        if (me->query("family") )
                        {
                                me->set("old_family",me->query("family") );
                                me->delete("family");
                        }
                        st = sprintf("tudi%d",t+1);
                        ob->set("menpai/tudi",ob->query("menpai/tudi")+([st:me->query("id")]) );
                        tell_object(ob, "恭喜你新收了一名弟子！\n");
                        printf("恭喜您成为%s的第%s代弟子。\n", 
                        menpai["name"],
                        chinese_number(2) );
                        return 1;
                }
        
        } else {
                old_app = me->query_temp("pending/apprentice");
                if( ob==old_app )
                        return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
                else if( objectp(old_app) ) {
                        write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                        tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                }

                message_vision("$N想要拜$n为师。\n", me, ob);
                me->set_temp("pending/apprentice", ob );
                if( userp(ob) ) {
                        tell_object(ob, YEL "如果你愿意收" + me->name() + "为弟子，用 recruit 指令。\n" NOR);
                } else 
                        ob->attempt_apprentice(me);
                return 1;
        }
}


int help(object me)
{
        write(@HELP
指令格式 : apprentice|bai [cancel]|<对象>
 
这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。

请注意你已经有了师父，又背叛师门投入别人门下，所有技能会减半，并且
评价会降到零。

如果对你的师父使用这个指令，会变成向师父请安。
 
请参考相关指令 expell、recruit
HELP
        );
        return 1;
}


