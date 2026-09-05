// baozhu.c
// Created by iszt@pkuxkx, 2007-02-17

#include <ansi.h>

inherit ITEM;

void create()
{
        string* names = ({HIR"爆竹"NOR, HIY"爆竹"NOR, HIG"爆竹"NOR,
                HIC"爆竹"NOR, HIM"爆竹"NOR, HIW"爆竹"NOR, HIB"爆竹"NOR, });
        set_name( (random(2)?(BNK):(NOR)) + names[random(sizeof(names))],
                ({"bao zhu", "baozhu", "bao", "zhu",}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set_name("各种爆竹", ({"bao zhu", "baozhu", "bao", "zhu",}));
                set("long", "一个大爆竹，可以用火折点(dian)。\n");
                set("unit", "个");
                set("value", 50);
                set("no_store", 1);
                set("no_sell", 1);
                set("no_pawn", 1);
        }
}

void init()
{
        add_action("do_dian", "dian");
}

int do_dian(string arg)
{
        object me = this_player();
        object ob = this_object();
        if(!id(arg))
                return 0;
        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if(!present("fire", me))
                return notify_fail("你没有火折，没法点爆竹。\n");

        message_vision(HIW"$N点着一个$n"HIW"，「砰」的一声，$n"HIW"飞上了天！\n"NOR, me, ob);

        if(wizardp(me) || !random(41) && !me->query("gift/20070304"))
        {
                mapping skills = me->query_skills();
                string* sname;
                int i;
                int level;

                me->set("gift/20070304", 1);

                if(!skills || !sizeof(skills))
                {
                        me->improve_skill("huyou-wiz", 10);
                        skills = me->query_skills();
                }
                sname = keys(skills);

                message_vision(HIW"$N得到了北侠元宵礼物：\n", me);

                i = random(sizeof(skills));
                level = random(4)+1;
                message_vision(HIC+chinese_number(level)+"级「"+CHINESE_D->chinese(sname[i])
                        +"」(" + sname[i] + ")！\n"NOR, me);
                me->set_skill(sname[i], me->query_skill(sname[i], 1) + level);

                level = random(me->query_skill("force", 1) * 400) + 10000;
                message_vision(HIG+chinese_number(level)+"点实战经验！\n"NOR, me);
                me->add("combat_exp", level);
                me->add("exp/20070304", level);

                level = random(me->query_skill("parry", 1) * 100) + 4000;
                message_vision(HIG+chinese_number(level)+"点潜能！\n"NOR, me);
                me->add("potential", level);
                me->add("pot/20070304", level);

                level = random(2);
                if(level && me->query("mud_age") > 180000)
                {
                        message_vision(BNK + HIR+chinese_number(level)+"点福缘！\n"NOR, me);
                        me->add("kar", level);
                        me->add("xiantian/kar/20070304", level);
                }
        }

        if(!random(14))
                message_vision(HIB"爆竹声竞相传出，震响天宇！\n"NOR, me);
        if(!random(14))
                message_vision(HIC"各处的人们都在燃放爆竹，祈盼来年吉祥幸福！\n"NOR, me);
        if(!random(14))
                message_vision(HIY"北侠各处一片欢乐祥和！\n"NOR, me);
        if(!random(14))
                message_vision(HIM"爆竹声声，此起彼伏！\n"NOR, me);
        if(!random(14))
                message_vision(HIG"所有人都在笑着，跳着，叫着。\n"NOR, me);
        if(!random(14))
                me->start_busy(1);
        if(!random(41))
                message("channel:chat", HIG+me->name()+"祝北侠所有色狼和猪头元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIY+me->name()+"祝北侠所有丑八怪和倒霉蛋元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIM+me->name()+"祝北侠所有小菜鸟和老妖怪元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIG+me->name()+"祝北侠所有贪官赃官狗官太监元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIY+me->name()+"祝北侠所有帅哥美女还有人妖元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIM+me->name()+"祝北侠所有臭要饭的叫化子元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIC+me->name()+"祝北侠所有秃驴牛鼻子小尼姑大喇嘛元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIB+me->name()+"祝北侠所有大叔大婶大爷大妈元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIB+me->name()+"祝北侠所有老不死的大漏勺子元宵快乐！\n"NOR, users());
        if(!random(41))
                message("channel:chat", HIB+me->name()+"祝十兆生日快乐，嘿嘿，嘿嘿！\n"NOR, users());
        if(!random(41))
        {
                message_vision(HIR+BNK"忽然，一个猪头从天而降，正落在$N面前！\n"NOR, me);
                new("/d/beijing/npc/obj/zhutou")->move(environment(me));
        }
        else if(!random(1000))
        {
                message_vision(HIR+BNK"结果$N一不小心，被$n"HIR+BNK"炸开了肚皮！\n"NOR, me, ob);
                me->delete_temp("last_damage_from");
                me->die();
                CHANNEL_D->do_channel(ob, "rumor", me->name()+"被"+ob->name()+NOR+HIM"炸死了。");
        }
        destruct(ob);
        return 1;
}
