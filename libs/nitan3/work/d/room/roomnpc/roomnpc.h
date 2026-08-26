// major function of room's npc

#define GOLDS  10000
#include <ansi.h>

int is_owner(object ob)
{
        if (ob->query("id") == environment()->query("room_owner_id") ||
            ob->query("couple/couple_id") == environment()->query("room_owner_id"))
                return 1;

        return 0;
}

int is_owner_permit(object ob)
{
        string *vip;

        if (ob->query_temp("permit_enter/" + environment()->query("room_owner_id")))
                return 1;

        if (objectp(present(environment()->query("room_owner_id") + " pass", ob)))
                return 1;

        vip = this_object()->query("vip");
        if (vip && sizeof(vip) && member_array(ob->query("id"),vip) != -1)
                return 1;

        return 0;
}

int owner_is_present()
{
        string id;

        if (present(id = environment()->query("room_owner_id")))
                return 1;

        return 0;
}

int do_invite(string arg)
{
        object ob;
        object me;

        me = this_player();

        if (!is_owner(me))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

        if (! arg || ! objectp(ob = present(arg, environment())))
                return notify_fail("你要邀请谁？\n");

        if (! ob->is_character())
                return notify_fail("你向邀请它，可是它不会走路啊！\n");

        if (! ob->query("can_speak"))
                return notify_fail("有意思，不过你最好还是邀请一个“人”。\n");

        if (ob == me)
                return notify_fail("你要邀请你自己？想法不错，可惜没有用。\n");

        if (is_owner(ob))
                return notify_fail("这人也算是这儿的主人，有什么好邀请的？\n");

        if (! userp(ob))
                return notify_fail("这人你还是别邀请了。\n");

        me = this_player();
        message_vision("$N指着" + ob->name() + "对$n道：“这是我请来的"
                       "客人，你可不要怠慢了！”\n$n连忙点头哈腰道：“"
                       "知道了！知道了！这位" + RANK_D->query_respect(ob) +
                       "，小的哪有不周尽管提！”\n", me, this_object());
        ob->set_temp("permit_enter/" + me->query("id"), 1);
        return 1;
}

int do_show(string arg)
{
        object ob;
        object me;
        string msg;

        if (! arg)
                return notify_fail("你要亮出什么东西？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)))
                return notify_fail("你身上没有这种东西。\n");
 
        msg = "$N亮出一" + ob->query("unit") + ob->name() + "\n";
        if (! ob->id(environment()->query("room_owner_id") + " pass"))
                msg += "不过$n理都没有理$n。\n";
        else
                if (is_owner_permit(me))
                        msg += "$n满脸堆笑，对$N道：“失敬！失敬！”\n";
                else
                {
                        msg += "$n一看，满脸堆笑，对$N道：“原来是" +
                               environment()->query("room_owner") +
                               "的朋友，失敬！失敬！”\n";
                        me->set_temp("permit_enter/" +
                                     environment()->query("room_ownerid"), 1);
                }
        message_vision(msg, me, this_object());
        return 1;
}

int list_vip()
{
        object ob;
        int i;
        string msg,*vip;

        if (!is_owner(this_player()))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

        ob = this_object();

        vip = ob->query("vip");
        if (!vip || sizeof(vip) < 1)
        {
                msg = "您并没有定义任何的贵宾。\n";
                msg += "您可以通过vip <id>来添加贵宾，通过vip <id> -c来清除贵宾。\n";
                return notify_fail(msg);
        }
        msg = HIY "您所定义的贵宾有如下玩家：\n" NOR;
        msg += "------------------------------\n";
        for (i = 0;i < sizeof(vip);i++)
        {
                msg += sprintf(HIY"%s\n"NOR, vip[i]);
        }
        msg += "------------------------------\n";

        msg += HIY "总共" + sizeof(vip) + "个贵宾。\n" NOR;
        msg += HIY "您可以通过vip <id>来添加贵宾，通过vip <id> -c来清除贵宾。\n" NOR;
        write(msg);
        return 1;
}

int do_vip(string arg)
{
        string *vip;
        object ob,me;
       // int num;
        
        ob = this_object();
        me = this_player();

        if (!is_owner(me))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

        if (!arg)
                return notify_fail("您可以通过vip <id>来添加贵宾，通过vip <id> -c来清除贵宾。\n");

        vip = ob->query("vip");
        if (!vip) vip = ({});

        if (sscanf(arg,"%s -c",arg) == 1)
        {
                if (member_array(arg,vip) == -1)
                        return notify_fail(ob->name(1) + "赔着笑脸说：" + arg + "本来就不是您的贵宾啊！\n");
                vip -= ({arg});
                ob->set("vip",vip);
                ob->save();
                write(ob->name(1) + "点头哈腰对你说：收到！收到！！以后" + arg + "不是您的贵宾了。\n");
                return 1;
        }

        if (sizeof(vip) >= ob->query("max_vip"))
                return notify_fail(ob->name(1) + "苦着脸说：您定的贵宾太多了，老奴我实在是记不住啊！\n");

        if (arg == me->query("id"))
                return notify_fail(ob->name(1) + "一个哆嗦，战战兢兢的说：您是主人啊，老奴不敢当您是客人！\n");

        if (member_array(arg,vip) != -1)
                return notify_fail(ob->name(1) + "赔着笑脸说：" + arg + "本来就已经是您的贵宾啦！\n");

        vip += ({ arg });
        ob->set("vip",vip);
        ob->save();
        write(ob->name(1) + "满脸堆笑，点头哈腰到：" + arg + "既然是您贵宾，以后一定放行！\n");
        return 1;
}

int add_force()
{
        object ob, me;

        ob = this_object();
        me = this_player();

        if (!is_owner(me))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

        if (ob->query("max_jing") >= 1000000 || ob->query("max_qi") >= 1000000
            || ob->query("max_neili") >= 1000000)
                return notify_fail("老仆的精、气、内力已经不能再升了。\n");

#ifdef LONELY_IMPROVED 
        if (count_lt(me->query("balance"), 100000000))
#else
        if (me->query("balance") < 100000000)
#endif
                return notify_fail("你的存款不足。\n");

        me->add("balance", - 10000 * GOLDS);
        ob->add("max_qi", 2000);
        ob->add("max_jing", 2000);
        ob->add("max_jingli", 2000);
        ob->add("max_neili", 2000);
        ob->add("qi", 2000);
        ob->add("jing", 2000);
        ob->add("jingli", 2000);
        ob->add("neili", 2000);

        ob->save();
        message_vision("只见$N脸上红光忽隐忽现，" +
                "瞬间又恢复平静。\n", ob);
        tell_object(me, "老仆的精、气、内力升级成功！\n");
        return 1;
}

int add_skill()
{
        object ob, me;
        int oldlvl;

        ob = this_object();
        me = this_player();

        if (!is_owner(me))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

        oldlvl = ob->query_skill("force", 1);

#ifdef LONELY_IMPROVED
        if (count_lt(me->query("balance"), count_mul(oldlvl, 200000)))
#else
        if (me->query("balance") < oldlvl * 200000)
#endif
                return notify_fail("你的存款不足。\n");

        me->add("balance", - oldlvl * 20 * GOLDS);
        ob->set_skill("force", oldlvl + 100);
        ob->set_skill("parry", oldlvl + 100);
        ob->set_skill("dodge", oldlvl + 100);
        ob->set_skill("strike", oldlvl + 100);
        ob->set_skill("claw", oldlvl + 100);
        ob->set_skill("jiuyang-shengong", oldlvl + 100);
        ob->set_skill("lingbo-weibu", oldlvl + 100);
        ob->set_skill("qiankun-danuoyi", oldlvl + 100);
        ob->set_skill("jiuyin-baiguzhao", oldlvl + 100);
        ob->set_skill("cuixin-zhang", oldlvl + 100);
        ob->set_skill("martial-cognize", oldlvl + 100);
        ob->set_skill("count", oldlvl + 100);

        ob->save();
        message_vision("忽然间听到$N全身的骨骼“哗啦啦”一阵暴响，" +
                "瞬间又恢复平静。\n", ob);
        tell_object(me, "老仆的武功升级成功！\n");
        return 1;
}

int buy_vip()
{
        object ob, me;

        ob = this_object();
        me = this_player();

        if (!is_owner(me))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

#ifdef LONELY_IMPROVED 
        if (count_lt(me->query("balance"), 2000 * GOLDS))
#else
        if (me->query("balance") < 2000 * GOLDS)
#endif
                return notify_fail("你的存款不足。\n");

        me->add("balance", - 2000 * GOLDS);
        ob->add("max_vip", 1);

        ob->save();
        tell_object(me, "成功增加一个VIP名额！\n");
        tell_object(me, sprintf("现共有 %d 个VIP名额。\n", ob->query("max_vip")));
        return 1;
}

int add_hujiu()
{
        object ob, me;

        ob = this_object();
        me = this_player();

        if (!is_owner(me))
                return notify_fail("老仆奇怪的问：你是谁？凭什么对我指手画脚的？\n");

        if (ob->query("can_hujiu"))
                return notify_fail("主人已经吩咐过了，老奴不敢忘记。\n");

#ifdef LONELY_IMPROVED 
        if (count_lt(me->query("balance"), 3000 * GOLDS))
#else
        if (me->query("balance") < 30000 * GOLDS)
#endif
                return notify_fail("你的存款不足。\n");

        me->add("balance", - 30000 * GOLDS);
        ob->set("can_hujiu", 1);

        ob->save();
        tell_object(me, "主人放心，老奴记住了！\n");
        return 1;
}

