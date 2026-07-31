// cheng.c 程药发

#include <ansi.h>
inherit NPC;

string do_zhuibu();
int get_reward(object me, object obj);
int potential_lv(int exp);

void create()
{
        set_name("程药发", ({ "cheng yaofa", "cheng" }));
        set("title", "扬州知府");
        set("gender", "男性");
        set("age", 43);
        set("str", 40);
        set("dex", 20);
        set("long", "他就是程药发，扬州现任知府。\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 250);

        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);

        set("inquiry", ([
                "工作" : (: do_zhuibu :),
                "job" : (: do_zhuibu :),
        ]));

        setup();
        carry_object("/d/city/npc/obj/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

string do_zhuibu()
{

string *quest = ({
        //"汉水南岸",
        "/d/shaolin/hanshui1",
        //"南阳城",
        "/d/shaolin/nanyang",
        //"汝州城",
        "/d/shaolin/ruzhou",
        //"少室山石阶",
        "/d/shaolin/shijie2",
        //"西长安街",
        "/d/beijing/xichang1",
        //"京城西门",
        "/d/beijing/ximen",
        //"华山村东村口",
        "/d/village/eexit",
        //"华山村碎石路",
        "/d/village/eroad2",
        //"泉州海港口",
        "/d/quanzhou/haigang",
        //"泉州北门",
        "/d/quanzhou/beimen",
        //"武夷山路",
        "/d/quanzhou/qzroad5",
        //"嘉兴南门",
        "/d/quanzhou/jxnanmen",
        //"扬州南大街",
        "/d/city/nandajie1",
        //"岱宗坊",
        "/d/taishan/daizong",
        //"泰山一天门",
        "/d/taishan/yitian",
        //"泰山石经峪",
        "/d/taishan/shijin",
        //"京城海港",
        "/d/tanggu/haigang",
        //"星宿六盘山",
        "/d/xingxiu/xxroad3",
        //"丝绸之路",
        "/d/xingxiu/silk1",
        //"武当黄土路",
        "/d/wudang/wdroad7",
        //"武当山脚下",
        "/d/wudang/wdroad8",
        //"天山脚下",
        "/d/xingxiu/shanjiao",
        //"北疆小镇",
        "/d/xingxiu/beijiang",
        //"赛马场",
        "/d/xingxiu/saimachang",
        //"华山玉女峰",
        "/d/huashan/yunu",
        //"华山镇岳宫",
        "/d/huashan/zhenyue",
        //"华山猢狲愁",
        "/d/huashan/husun",
        //"华山青柯坪",
        "/d/huashan/qingke",
        //"华山脚下",
        "/d/huashan/path1"
        //"大理城北"
        "/d/dali/dalinorth"
});

        object obj, ob = this_player();
        int exp = ob->query("combat_exp");

        if ( environment(this_object())->query("short")!="衙门正厅" )
                return "这里不是衙门，你有事回衙门再说吧？";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";

        if ( ob->query_condition("in_zhuibu") )
                return "你不是己经在追捕了吗？ 如果你不想干，就放弃吧。\n";

        if ( ob->query_condition("after_zhuibu") )
                return "你已经很辛苦了，还是先休息一会再来吧！\n";

        if (exp < 500000)
        {
                if (exp < 10000) {
                        command("pat " + ob->query("id"));
                        return ("程药发说道：你年纪还小，大人的事怎么能做呢？\n");
                }
                else if (exp < 100000) {
                        obj = new(__DIR__"quest2/thief");
                        obj->move(quest[random(28)]);
                        ob->set_temp("抓/" + obj->query("id"), 1);
                }
                else if (exp < 200000) {
                        obj = new(__DIR__"quest2/zei");
                        obj->move(quest[random(28)]);
                        ob->set_temp("抓/" + obj->query("id"), 1);
                }
                else if (exp < 300000) {
                        obj = new(__DIR__"quest2/dadao");
                        obj->move(quest[random(28)]);
                        ob->set_temp("抓/" + obj->query("id"), 1);
                }
                else if (exp < 400000) {
                        obj = new(__DIR__"quest2/qinfan");
                        obj->move(quest[random(28)]);
                        ob->set_temp("抓/" + obj->query("id"), 1);
                }
                else if (exp < 500000) {
                        obj = new(__DIR__"quest2/dawang");
                        obj->move(quest[random(28)]);
                        ob->set_temp("抓/" + obj->query("id"), 1);
                }
                ob->start_busy(1);

                ob->set("oldtitle",ob->query("title"));
                ob->set("title",HIW"衙门捕头"NOR);
                ob->apply_condition("in_zhuibu", 20);
                message_vision(YEL"$N已被委任为衙门捕头。\n"NOR,ob);
                remove_call_out("destrory");
                call_out("destrory",1000,obj);
//                return "快去把" + obj->query("name") + "给我抓来，据说他在"+environment(obj)->query("outdoors")+"一带！\n";
                return "快去把" + obj->query("name") + "给我抓来，据说他在"+environment(obj)->query("short")+"一带！\n";
        }
        else {
                return("程药发说道：这种小事怎敢劳您大驾？\n");
        }
}

int accept_object(object me, object obj)
{
        if ( !me || environment(me) != environment() ) return 0;

        if ( !objectp(obj) ) return 0;

        if ( !present(obj, me) ) {say("你没有这件东西。\n"); return 0;}

        if ( me->query_condition("in_zhuibu") ) {
                if ( me->query_temp("抓/" + obj->query("id")) )
                {
                        command("nod");
                        command("say 很好很好，这是你的奖赏。\n");
                        call_out("get_reward", 0, me, obj);
                        me->apply_condition("after_zhuibu", 7);
                        me->apply_condition("in_zhuibu", 0);
                        me->delete_temp("抓/" + obj->query("id"));
                        me->set("title",me->query("oldtitle"));
                        me->delete("oldtitle");
                        return 1;
                }
                else {
                        command("heng");
                        command("say 想滥竽充数，来人啦，给我打！\n");
                        message_vision("四周衙役凶神恶刹般拥过来，围住你一顿痛打......\n", me);
                        me->apply_condition("after_zhuibu", 7);
                        me->apply_condition("in_zhuibu", 0);
                        me->set("title",me->query("oldtitle"));
                        me->delete("oldtitle");
                        me->unconcious();
                        return 0;
                }
        }
        else {
                command("say 你好象还没什么任务吧，\n");
                return 0;
        }
}

int get_reward(object me, object obj)
{
        int exp, pot, bonus;
        int rand = random(3);
        if ( rand == 0 )
                rand = 1;

        exp = obj->query("score") * 20 * rand;
        pot = exp / 10 * 3 / 2;

                        remove_call_out("destrory");
                        call_out("destrory",1,obj);

        me->add("combat_exp", exp);
        bonus = (int)me->query("potential");
        bonus = bonus - (int)me->query("learned_points");
        bonus = bonus + pot;
//       if ( bonus > potential_lv((int)me->query("combat_exp")) )
//        bonus = potential_lv((int)me->query("combat_exp"));
        bonus += (int)me->query("learned_points");
        me->set("potential", bonus );
        tell_object(me, sprintf("你得到了%s点潜能，%s点修为。\n",chinese_number(pot),chinese_number(exp)));
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;;
        return grade;
}

void destrory(object ob)
{
        destruct(ob);
        return;
}


