// File         : silver.h 门派的例银系统
// Created By   : iszt@pkuxkx, 2007-01-14
// 在NPC文件中include这个文件，inquiry中加上 (: ask_silver :) 即可使用
// mud_age达到一个月之后按月发例银，满足三个条件之一即可
// 门忠增加奖励的例银最多，武功次之，经验最少
// 经验越高，每月例银越多
// 最好进行下面若干参数的定义，以便体现门派特色：
// set("sivler_name") 例银的名称，默认为例银
// set("silver_factor") 例银的数量因子，默认为1
// set("silver_family_skill") 门派武功，提升此武功时可以领取例银，默认为parry
// set("msg_silver_firsttime") 第一次打听例银的时候说的话
// set("msg_silver_record") 作记录时的描述\n
// set("msg_silver_check") 检查记录时的描述\n
// set("msg_silver_mudage") 时间未到不能领取时说的话
// set("msg_silver_paid") 领取成功时说的话
// set("msg_silver_score") 由于提升师门忠诚而领取例银时的描述\n
// set("msg_silver_skill") 由于提升师门武功而领取例银时的描述\n
// set("msg_silver_exp") 由于提升经验而领取例银时的描述\n
// set("msg_silver_none") 领取例银条件均不满足时说的话

void do_record(int mudage, int exp, int score, int skill)
{
        object me = this_player();
        object ob = this_object();
        string msg;

        me->set("silver/last_mud_age", mudage);
        me->set("silver/last_exp", exp);
        me->set("silver/last_score", score);
        me->set("silver/last_family_skill", skill);

        msg = ob->query("msg_silver_record");
        if(!msg)
                msg = "$N取出一本小册子，在上边记下了些什么。\n";
        message_vision(YEL + msg + NOR, ob);
}

void do_givesilver(int salary, int month, string silvername)
{
        object me = this_player();
        object ob = this_object();
        string msg;

        if(!ob->query("silver_factor"))
                ob->set("silver_factor", 1);
        salary *= ob->query("silver_factor");

        msg = "$N交给$n" + chinese_number(month) + "个月的" + silvername;
        msg += MONEY_D->money_str(salary) + "。\n";
        message_vision(WHT + msg + NOR, ob, me);

        MONEY_D->pay_player(me, salary);
        CHANNEL_D->do_channel(this_object(), "sys",
                        sprintf("%s领%s%s。", me->name(), silvername, MONEY_D->money_str(salary)));
}

string ask_silver()
{
        object me = this_player();
        object ob = this_object();
        string msg;

        int mudage = me->query("mud_age");
        int exp = me->query("combat_exp");
        int score = me->query("score");
        string familyskill = ob->query("silver_family_skill");
        int skill;
        int salary;
        int month;

        string silvername = ob->query("silver_name");

        if(!familyskill)
                familyskill = "parry";
        skill = me->query_skill(familyskill, 1);

        if(!silvername)
                silvername = "例银";

        //不允许不停的问
        if(mudage - me->query_temp("last_ask_silver") < 60)
                return "问来问去，你烦不烦啊？";
        me->set_temp("last_ask_silver", mudage);

        //第一次问，没有标记的情况
        if(!me->query("silver"))
        {
                do_record(mudage, exp, score, skill);
                msg = ob->query("msg_silver_firsttime");
                if(!msg)
                        msg = "好，记下了。回头就来领你的" + silvername + "吧。";
                return msg;
        }

        //间隔时间
        salary = mudage - me->query("silver/last_mud_age");
        month = salary / 7200;
        if(month < 1)
        {
                msg = ob->query("msg_silver_check");
                if(!msg)
                        msg = "$N取出一本小册子翻了翻。\n";
                message_vision(CYN + msg + NOR, ob);
                msg = ob->query("msg_silver_mudage");
                if(!msg)
                        msg = "急什么？一月不到，还不是发" + silvername + "的时候。";
                return msg;
        }

        //score有提升
        if(score - me->query("silver/last_score") > salary / 100) //每小时36 score
        {
                msg = ob->query("msg_silver_score");
                if(!msg)
                        msg = "$N轻轻拍了拍$n的肩头道：「不错，最近你为本门出力甚多。」\n";
                message_vision(CYN + msg + NOR, ob, me);

                do_record(mudage, exp, score, skill);

                salary = 1000 * pow((float)me->query("silver/last_exp")*1.0, 1.0/3);
                //50k exp每月350 silver，1M exp每月10 gold，100M exp每月不到50 gold
                salary *= month;

                do_givesilver(salary, month, silvername);

                msg = ob->query("msg_silver_paid");
                if(!msg)
                        msg = "拿去吧，继续为本门努力，绝不会亏待你的。";
                return msg;
        }

        //skill有提升
        if(skill - me->query("silver/last_family_skill") > salary /1800) //每小时2 level
        {
                msg = ob->query("msg_silver_skill");
                if(!msg)
                {
                        msg = "$N轻轻拍了拍$n的肩头道：「不错，你的";
                        msg += CHINESE_D->chinese(familyskill);
                        msg += "又精进了。」\n";
                }
                message_vision(CYN + msg + NOR, ob, me);

                do_record(mudage, exp, score, skill);

                salary = 600 * pow((float)me->query("silver/last_exp")*1.0, 1.0/3);
                //50k exp每月2 gold，1M exp每月6 gold，100M exp每月不到30 gold
                salary *= month;

                do_givesilver(salary, month, silvername);

                msg = ob->query("msg_silver_paid");
                if(!msg)
                        msg = "拿去吧，继续为本门努力，绝不会亏待你的。";
                return msg;
        }

        //exp有提升
        if(exp - me->query("silver/last_exp") > salary * 3) //每小时10.8k exp
        {
                msg = ob->query("msg_silver_exp");
                if(!msg)
                        msg = "$N轻轻拍了拍$n的肩头道：「不错，你的武功又精进了。」\n";
                message_vision(CYN + msg + NOR, ob, me);

                do_record(mudage, exp, score, skill);

                salary = 200 * pow((float)me->query("silver/last_exp")*1.0, 1.0/3);
                //50k exp每月70 silver，1M exp每月2 gold，100M exp每月不到10 gold
                salary *= month;

                do_givesilver(salary, month, silvername);

                msg = ob->query("msg_silver_paid");
                if(!msg)
			msg = "拿去吧，继续为本门努力，师父绝不会亏待你的。";
                return msg;
        }

        do_record(mudage, exp, score, skill);
        msg = ob->query("msg_silver_none");
        if(!msg)
                msg = "你自问这" + chinese_number(month) + "个月做什么去了？罢了，你去吧。";
        return msg;
}
