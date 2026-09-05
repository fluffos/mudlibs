// hanbaoju.c
// modified by Zine for NEWBIE job.
#include <ansi.h>;
inherit NPC;
int ask_horse();
int ask_find();
string * loc_1=({"华山","小山村","武当山","少林寺","古墓","长安","洛阳","信阳","杀手帮","泰山","曲阜","麒麟村","荆襄","灵州","星宿","全真",
        "丐帮","扬州","灵鹫","中原","长江北岸","黄河南岸"});
string * loc_2=({"北京","康亲王府","紫禁城","天坛","神龙岛","日月神教","晋阳","张家口","黄河北岸","白驼山","明教","丝绸之路"});
void create()
{
        set_name("韩宝驹", ({ "han baoju", "han" }));
        set("title", "江南七侠");
        set("nickname", HIY"马王神"NOR);
        set("long", "他是个又矮又胖的猥琐汉子，犹如一个大肉团一般。他手短足短，
没有脖子，一个头大的出奇，却又缩在双肩之中。一个酒糟鼻又
大又圆，就如一只红柿子旒在脸上。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
       set("unique", 1);
        set("per", 10);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 3500);
        set("max_jing", 500);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 20);
        set("combat_exp", 1400000);
        set("score", 6000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 160);
        set_skill("qingmang-jian", 160);
        set_skill("strike", 160);
        set_skill("parry", 160);
        set_skill("kunlun-zhang", 160);
        set_skill("whip", 160);
        set_skill("yunlong-bian", 160);

        map_skill("force", "taiji-shengong");
        map_skill("strike", "kunlun-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("whip", "yunlong-bian");
        map_skill("parry", "yunlong-bian");
        prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
         }));


        set("inquiry", ([
                "郭靖" : "靖儿是我们的乖徒儿！\n",
                "江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
                "江南七怪" : "住嘴！！七怪也是你叫的？！\n",
                "丘处机" : "丘道长豪侠仗义，是条汉子！\n",
                "柯镇恶" : "他是我大哥，你别看他眼睛看不见，你是什么样的人他心里很清楚。\n",
                "朱聪"   : "呵呵，小心你的口袋。\n",
                "南希仁"   : "那是我四弟。\n",
                "张阿生"   : "那是我五弟，他那双屠牛的手比你的脸都大。\n",
                "全金发"   : "那是我六弟。\n",
                "韩小莹"   : "那是我七妹,你想不想试试她的越女剑？\n",
                "梅超风"   : "这婆娘，早晚我要杀了她。\n",
                "陈玄风"   : "你能告诉我他在哪吗？\n",
                "送马"   : (:ask_horse:),
                "horse"   : (:ask_horse:),
                "找马"   : (:ask_find:),
                "find"   : (:ask_find:),
        ]));

        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
    add_action("do_tj","taojiao");
}

int ask_find()
{
    object me=this_player();
    object ob=this_object();
    object *all;
    int i;
    object env;
    string env_area;
    if (time()-ob->query("find_horse")<30)
    {
        command("say 我累了，现在不想说话。");
        return 1;
    }
    all=livings();
    all = filter_array(all, (: environment :));
    all = filter_array(all, (: $1->query("horse") :));
    if (!sizeof(all))
    {
        command("say 暂时来说，我也不知道哪里有马。");
        return 1;
    }
    i=random(sizeof(all));
    env=environment(all[i]);
    env_area=TASK_D->place_belong(env);
    if (member_array(env_area,loc_1)==-1&&member_array(env_area,loc_2)==-1)
    {
        command("say 江南倒是有马，不堪大用啊。");
        ob->set("find_horse",time());
        return 1;
    }
    command("say 在"+TASK_D->place_belong(env)+"的"+env->query("short")+"有一匹"+all[i]->query("name")+"，也许你可以把它牵(qian)回来。\n");
    ob->set("find_horse",time());
    return 1;
}

int do_tj(string arg)
{
    object me=this_player();
    string *sk=({"dodge","parry","sword","blade","whip","staff","axe","hammer","halberd","spear","throwing","dagger","force","strike","cuff","finger","claw"});
    int limit=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-5;
    if (!me->query_temp("hbj_taojiao"))
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("combat_exp")>100000)
    {
        message_vision("$N忙道：不敢不敢，你的功夫比我都高了，谈何讨教？",this_object());
        return 1;
    }
    if (me->query("韩宝驹讨教时间")&&(int)me->query("mud_age")-(int)me->query("韩宝驹讨教时间")<3600)
    {
        tell_object(me,"你之前刚向韩宝驹讨教过，还没完全消化呢。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要向韩宝驹讨教哪种功夫？\n");
        return 1;
    }
    if (member_array(arg,sk)==-1)
    {
        tell_object(me,"你只能向韩宝驹讨教基本功夫。\n");
        return 1;
    }
    if ((int)me->query_skill(arg,1)>limit)
    {
        tell_object(me,"你的基本功夫受限于你的实战经验，向韩宝驹讨教也没用。\n");
        return 1;
    }
    message_vision("$N听了韩宝驹的讲解，觉得受益匪浅。\n",me);
    me->set_skill(arg,me->query_skill(arg,1)+1+(int)me->query_temp("hbj_taojiao")*2);
    me->delete_temp("hbj_taojiao");
    me->set("韩宝驹讨教时间",me->query("mud_age"));
    return 1;
}
int ask_horse()
{
    object me=this_player();
    object ob=this_object();
    object env=environment(ob);
    object horse;
    string loc;
    
    if (base_name(env)!="/d/quanzhou/yanyu")
    {
        command("say 我这是到了哪里了？天哪，我迷路了！");
        return 1;
    }
    if (!me->query_temp("pulled_horse"))
    {
        command("say 你没有牵来一匹马呀。");
        return 1;
    }
    
    horse=me->query_temp("pulled_horse");
    if (horse->query("race")!="马类")
    {
        command("say 你牵来的是一匹马吗？");
        return 1;
    }
    if (!present(horse,env))
    {
        command("say 你的马究竟在哪里啊？");
        return 1;
    }
    if (horse->query_leader()!=me)
    {
        command("say 这不是你牵来的马，你怎么能冒领别人的功劳呢。");
        return 1;
    }
    if (!horse->query("pull_loc"))
    {
        command("say 这匹马是牵来的吗？");
        return 1;
    }
    loc=horse->query("pull_loc");
    if (member_array(loc,loc_1)==-1&&member_array(loc,loc_2)==-1)
    {
        command("say 只有西域和河北的马匹可称为神驹，中原地区的马匹或堪一用，其他地方的马就劣了些。");
        return 1;
    }
    else if (member_array(loc,loc_1)!=-1)
    {
        command("say 中原地区的马匹？不错不错。我也不能白让你跑一趟，你可以向我讨教(taojiao)点基本功夫啥的。");
        message_vision("$N顺手牵过了$n的坐骑。\n",ob,me);
        destruct(horse);
        me->set_temp("hbj_taojiao",1);
        return 1;
    }
    else
    {
        command("say 这是神驹啊，我收下了。但我也不能白让你跑一趟，你可以向我讨教(taojiao)点基本功夫啥的。");
        message_vision("$N顺手牵过了$n的坐骑。\n",ob,me);
        destruct(horse);
        me->set_temp("hbj_taojiao",2);
        return 1;
    }
}