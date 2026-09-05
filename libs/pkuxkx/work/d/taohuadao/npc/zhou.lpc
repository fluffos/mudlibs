// zhou.c 周伯通
#include <ansi.h>
inherit NPC;
string ask_zhou();
string ask_huang();
string ask_zhenjing();
string ask_story();
string ask_houlai();
string ask_xueyi();
string ask_zyhb();
int do_answer(string arg);
int do_hua(string arg);

void heal();
int auto_perform();

void create()
{
    set_name("周伯通",({"zhou botong","zhou"}));
    set("nickname",RED"老顽童"NOR);
    set("long","他看起来笑嘻嘻的，活像一个白发顽童."
            "他看起来五十多岁.\n");
    set("no_get", 1);
    set("zyhb", 1);
    set("zuoyou-hubo", 1);
    set("str",29);
    set("con",28);
    set("int",14);
    set("dex",29);
    set("gender","男性");
    set("shen_type",1);
    set("attitute","frieldly");
    set("age",56);
    set("max_qi",8500);
    set("qi",8500);
    set("max_neili",7500);
    set("neili",7500);
    set("max_jing",2000);
    set("jing",2000);
    set("max_jingli",2000);
    set("jingli",2000);
    set("jiali",150);
    set("combat_exp",20000000);
    set("score",500000);
    set_skill("force",350);
    set_skill("xiantian-gong",350);
    set_skill("dodge",350);
    set_skill("jinyan-gong",400);
    set_skill("parry",450);
    set_skill("cuff",400);
    set_skill("kongming-quan",400);
    set_skill("literate",150);
    map_skill("force","xiantian-gong");
    map_skill("dodge","jinyan-gong");
    map_skill("parry","kongming-quan");
    map_skill("cuff","kongming-quan");
    prepare_skill("cuff","kongming-quan");
    set("inquiry", ([
                "周伯通" : (:ask_zhou : ),
                "黄药师" : (:ask_huang : ),
                "九阴真经" : (:ask_zhenjing : ),
                "故事" : (:ask_story : ),
                "后来怎样" : (:ask_houlai : ),
                "后来" : (:ask_houlai : ),
                "功夫" : (:ask_xueyi : ),
                "左手和右手打架的功夫" : (:ask_xueyi : ),
                "左右互搏" : (: ask_zyhb : ),
                "双手互搏" : (: ask_zyhb : ),
                ]) );
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
                (: auto_perform :),
                }) );
    set("chat_chance",100);
    set("chat_msg",({
                (: heal :),
                }));    
    setup();
    carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
    object me;
    me = this_player();
    tell_object(me,"周伯通一见有人进来，便问道：「你猜我是谁？」\n");
    add_action("do_answer", "answer");
    add_action("do_hua", "hua");
    return;
}
void heal()                                             
{                                                       
    object ob=this_player();                        

    if (ob->query("eff_qi") < ob->query("max_qi"))  
    {                                               
        command("exert heal");                  
        command("enforce 200");                 
        return;                                 
    }                                               

    if (ob->query("qi") < ob->query("eff_qi"))      
    {                                               
        command("exert recover");               
        return;                                 
    }                                               

    if (ob->query("jing") < ob->query("eff_jing"))  
    {       command("exert regenerate");            

        return;
    }    

}

int auto_perform()
{
    object me = this_object();
    object target = me->select_opponent();

    command("exert powerup");

    if ( !objectp(target) ) return 0;

    if (me->query("qi") < me->query("eff_qi"))      
        command("exert recover"); 
    if (me->query("jing") < me->query("eff_jing"))  
        command("exert regenerate");    

    if (me->query_busy() > 4 || me->query("qi") < 1000) command("hubo");
    switch( random(3) )
    {
        case 0:
            command("perform cuff.hubo " + target->query("id"));
            break;
        case 1:
            command("hubo " + target->query("id"));
            break;
        case 2:
            command("perform cuff.hubo " + target->query("id"));
            break;
    }

    return 1;
}

string ask_zhou()
{
    object me;
    me = this_player();

    if( me->query_temp("zyhb/zhou"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( me->query_temp("zyhb/zbt") && me->query_temp("zyhb/bhcs"))
    {
        command("point " + this_object()->query("id"));
        me->set_temp("zyhb/zhou", 1);
        return "「不错，不错，我正是周伯通。」";
    }
    tell_object(me, "周伯通两只手正打得热火朝天，显然不会听你说话。\n");
    return "我现在正忙着呢！";
}
string ask_huang()
{
    object me;
    me = this_player();

    if( me->query_temp("zyhb/huang"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( me->query_temp("zyhb/zhou"))
    {
        me->delete_temp("zyhb/zhou");
        me->set_temp("zyhb/huang", 1);
        return "「黄老邪想要我的九阴真经，把我关了十五年啦。」";
    }
    tell_object(me, "周伯通两只手正打得热火朝天，显然不会听你说话。\n");
    return "我现在正忙着呢！";
}
string ask_zhenjing()
{
    object me;
    me = this_player();

    if( me->query_temp("zyhb/zhenjing"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( me->query_temp("zyhb/huang"))
    {
        command("say 「九阴真经？那个本来是我师哥的，可是给黄老邪跟他老婆骗了去。」");
        command("say 「听她老婆告诉他的上卷残缺不全，下卷又被他自己徒弟偷了，这个就叫报应。」");
        command("laugh " + this_object()->query("id"));
        tell_object(me, "周伯通拉着你说道：「乖乖的听我说故事吧。」\n");
        command("grin");
        me->delete_temp("zyhb/huang");
        me->set_temp("zyhb/zhenjing", 1);
        return "「来来来，难得有个人找我，你别想跑了。」";
    }
    tell_object(me, "周伯通两只手正打得热火朝天，显然不会听你说话。\n");
    return "我现在正忙着呢！";
}
string ask_story()
{
    object me;
    me = this_player();

    if( me->query_temp("zyhb/story"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( me->query_temp("zyhb/zhenjing"))
    {
        tell_object(me, "周伯通听到你要他讲故事，登时兴高采烈。\n");
        say("周伯通开始讲起九阴真经和黄裳的故事。\n");
        tell_object(me, "你听得入神，没有说话，周伯通看你不问后来怎样，便赌气不说了。\n");
        me->delete_temp("zyhb/zhenjing");
        me->set_temp("zyhb/story", 1);
        return "哼，你不问我就不说了！";
    }
    tell_object(me, "周伯通两只手正打得热火朝天，显然不会听你说话。\n");
    return "我现在正忙着呢！";
}
string ask_houlai()
{
    object me;
    me = this_player();

    if( me->query_temp("zyhb/houlai"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( me->query_temp("zyhb/story"))
    {
        tell_object(me, "周伯通一听你问他后来怎样，又口沫横飞的说起来。\n");
        command("say 「后来啊，九阴真经落到了我师兄王重阳的手中。」");
        say("周伯通把从九阴真经从王重阳手里转到自己手里，以至后来下册被毁，黄药师逼他交出上册的事一一道来。\n");
        command("say 「我打不过黄老邪，被困在这里十五年。」");
        me->delete_temp("zyhb/story");
        me->set_temp("zyhb/houlai", 1);
        return "「但是这十五年的时光我也没有白费，我冥思苦想，创出一套左手和右手打架的功夫。」";
    }
    tell_object(me, "周伯通两只手正打得热火朝天，显然不会听你说话。\n");
    return "我现在正忙着呢！";
}
string ask_xueyi()
{
    object me;
    me = this_player();

    if( me->query_temp("zyhb/xueyi"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( me->query_temp("zyhb/houlai"))
    {
        command("say 「这套功夫是我自己的创作，可厉害的很啊。」");
        command("say 「我在桃花岛这么多年独居，无聊之极，今天有你陪我说话解闷，我很高兴。不妨你我结为兄弟如何？」");
        me->delete_temp("zyhb/houlai");
        me->set_temp("zyhb/xueyi", 1);
        return "「结义之后我自当传你这套“双手互搏”的功夫。(answer yes or no)」";
    }
    tell_object(me, "周伯通两只手正打得热火朝天，显然不会听你说话。\n");
    return "我现在正忙着呢！";
}
int do_answer(string arg)
{
    object me, ob;

    me = this_player();
    ob = this_object();

    if(!me->query_temp("zyhb/xueyi")) return 0;
    if(arg != "yes" && arg != "no")
    {
        tell_object(me,"周伯通着急道：「你到底愿不愿意啊？」\n");
        return 1;
    }
    if(arg == "yes")
    {
        message_vision("$N笑道：「兄长既然有此美意，小弟如何不遵？咱俩就在此撮土为香，义结兄弟便是。」\n", me);
    }
    if(arg == "no")
    {
        message_vision("$N说道：「晚辈与前辈辈分差距太大，若是依了前辈之言，必定被人笑骂。」\n", me);
        message_vision("$N说道：「偏你就有着许多顾虑。你不肯和我结拜，定是嫌我太老，呜呜呜……」\n", ob);
        say("周伯通嚎啕大哭起来。\n");
        message_vision("$N看周伯通大哭，慌了手脚，忙道：「弟子依前辈吩咐就是。」\n", me);
    }
    say("周伯通「哈哈」大笑几声。\n");
    say("周伯通大叫：「好兄弟，我们这就来行结拜之礼。」\n");
    message_vision("周伯通与$N并肩而跪，朗声说道：「老顽童周伯通，今日与" + me->name() + "义结金兰，日后有福同享，有难共当。\n若是违此盟誓，叫我武功全失，连小狗小猫都打不过。」\n", me);
    message_vision("$N依式念了一遍，两人以酒沥地，义结金兰。\n", me);
    me->delete_temp("zyhb/xueyi");
    me->set_temp("zyhb/zyhb", 1);
    return 1;
}
string ask_zyhb()
{
    object me;
    me = this_player();

    if( me->query("zyhb"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「我不是已经教会你了么了么？」";
    }

    if( me->query_temp("zyhb/fangyuan"))
    {
        tell_object(me, "周伯通白了你一眼。\n");
        return "「你烦不烦啊，不是刚问过了么？」";
    }

    if( !me->query_temp("zyhb/zyhb"))
    {
        tell_object(me, "周伯通看了你一眼，似乎有些不太信任你。\n");
        return "「这门功夫我只传授给我兄弟」";
    }

    if( me->query_temp("zyhb/zyhb"))
    {
        command("say 「我一个人在这里的时候，假装右手是黄老邪，左右是老顽童。右手一掌打过去，左手拆开之后还了一拳，就这样打了起来。」");
        say("周伯通说着当真双手出招，左攻右守的打得甚是激烈。\n");
        message_vision("$N起初觉得十分好笑，但开了数招，只觉得他双手掌法诡异奥妙，匪夷所思，不仅怔怔得出了神。\n", me);
        command("say 「我这双手互搏之术要人分心二用，研习之法要从“左手画方，右手画圆”做起。」");
        me->delete_temp("zyhb/zyhb");
        me->set_temp("zyhb/fangyuan", 1);
        return "「你就来练练这“画方圆”(hua fangyuan)之术吧。(用halt命令停止)」";
    }
}
int do_hua(string arg)
{
    object me, ob;

    me = this_player();
    ob = this_object();

    if(!me->query_temp("zyhb/fangyuan")) return 0;
    if(!arg || arg != "fangyuan") return notify_fail("你要画什么？\n");
    if (me->query_temp("pending/draw")||me->query_temp("pending/exercise")||me->query_temp("pending/respirate")) return notify_fail("你正忙着呢！\n");
    me->set_temp("drawing");
    me->set_temp("draw");
    me->set_temp("pending/draw", 30);
    me->start_busy("do_draw", "halt_draw");
    return 1;
}
int do_draw(object me)
{
    int kar, wis;
    string msg;
    kar = me->query("kar");
    wis = me->query("int");

    if(!stringp(msg))  msg = "$N屏息凝神，一神守内，一神游外，意图双手各成方圆，却总是很难成功。";
    msg = HIG + "" + msg + "\n" + NOR;

    if ((wis - kar / 4) * 480 > 9999 )
        tell_object(me,HIW"你天生太聪明！福缘也不够高，不适合学习「双手互搏」！\n"NOR);
    if(me->query("neili") < 20
            || me->query("jing") < 20
            || me->query_temp("pending/draw") < 2)
    {
        msg = HIG"\n$N累得满头大汗, 暂停了画方圆。\n"NOR;
        message_vision(msg, me);
        me->delete_temp("drawing");
        me->delete_temp("draw");
        me->delete_temp("pending/draw");
        return 0;
    }
    if (random(100000 + (kar / 4 - wis) * 480) > 90000)
    {
        me->add("hubo_practice", 1);
        if(me->query("hubo_practice") > 1000)
        {
            tell_object(me, HIR"成功了，你领悟了「双手互搏」之术！！\n"NOR);
            message_vision(HIR"$N突然兴奋得跳了起来，看来是有所顿悟！\n"NOR, me);
            tell_object(me, HIY"你觉得学会了「双手互搏」后，思维似乎变得迟钝了一些！\n"NOR);
message( "channel:" + "chat",HIW + "【江湖谣传】"+HIY"据说" + me->query("name") +HIY "经过多年苦练，已经掌握了左右互搏绝技！\n"NOR,users());
            me->add("int", -3);//先天悟性减3
            me->add("xiantian/int/zyhb", -3);
            me->set("zyhb", 1);//学会双手互搏
            me->delete("hubo_practice");
            me->delete_temp("drawing");
            me->delete_temp("draw");
            me->delete_temp("pending/draw");
            me->delete_temp("zyhb/zbt");
            me->delete_temp("zyhb/bhcs");
            me->delete_temp("zyhb/fangyuan");
            return 0;
        }
        if(me->query("hubo_practice") > 900 && !random(30))
            tell_object(me, HIY"你对双手互搏的要领已经很熟练了！成功就在眼前！\n"NOR);
        else if(me->query("hubo_practice") > 700 && !random(30))
            tell_object(me, HIY"你对双手互搏要领大部分都掌握了，加油啊！\n"NOR);
        else if(me->query("hubo_practice") > 500 && !random(30))
            tell_object(me, HIY"你对双手互搏的要领有了一些理解！\n"NOR);
        else if(me->query("hubo_practice") > 300 && !random(30))
            tell_object(me, HIY"你对双手互搏加深了一些理解。\n"NOR);
        else if(me->query("hubo_practice") > 50 && !random(30))
            tell_object(me, HIY"你对双手互搏多了一点认识。\n"NOR);
    }
    else message_vision(msg, me);

    me->receive_damage("jing", 15);
    me->add("neili", -5);
    me->add_temp("pending/draw", -1);
    return 1;
}
int halt_draw(object me)
{
    me->delete_temp("drawing");
    me->delete_temp("pending/draw");
    me->delete_temp("draw");
    if ((int)me->query("jing")< 100)
    {
        me->set("jing", 0);
        message_vision("$N猛地停了下来，突然觉得头昏眼花，一下晕了过去。\n", me);
        me->unconcious();
    }
    else
        me->add("jing", -100);
    return 1;
}
