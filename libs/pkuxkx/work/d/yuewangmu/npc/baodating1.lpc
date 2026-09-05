//包打听
// by male
// Modified by iszt@pkuxkx, 2007-02-28

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int do_ask();

void create()
{
        set_name("包打听", ({ "bao dating", "bao" }));
        set("title", HIG"水果小贩"NOR);
        set("shen_type", -1);

        set("str", 60);
        set("gender", "男性");
        set("age", 55);
        set("long",
                "钱眼开的堂兄，爱财如命，整天以卖水果为名，到处招摇撞骗。\n"
                "不过他倒是知道岳王墓的不少秘密。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("inquiry", ([
                "岳飞" : "传说岳王可是黄药师的师兄，他们当年都曾拜过周侗为师，只是岳王出师以后，黄药师才被周侗救了一命，做了他的关门弟子。",
                "岳家枪" : "岳家枪可是当年让人闻风丧胆的一套枪法，还有岳飞当年的那一杆夺魄枪更是...",
                "夺魄枪" : "你...你...问这个干什么？这支枪可不是好玩的！",
                "武穆遗书" : "你问我，我问谁去？那个不想要那本书？我都想要！",
                "盗墓" : (: do_ask :),
        ]));

        set("vendor_goods", ({
                "/d/quanzhou/obj/lizhi",
                "/d/quanzhou/obj/longyan",
                "/d/quanzhou/obj/nai",
        }));

        setup();
}

void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int do_ask()
{
        object me=this_player();
        if(me->query("asked包"))
        {
                CHANNEL_D->do_channel(this_object(), "bd", "papaya "+me->query("id"), 1);
                write(HIY"ft，我不是告诉过你么？<dig 岳王墓>！到墓后空地去！\n"
                        "不过别怪我没提醒你哦，盗墓可是很需要很需要铁锹的。\n"
                        "你进不进去得了和拿的到什么，那就看你自己的造化了，嘿嘿！\n"
                        "还有，岳王墓里千万不要呆得太久哦，会缺氧的，听说。\n"NOR);
                return 1;
        }
        else
        {
                message_vision("包打听听到后脸色大变，连忙对$N说：「你...你...打听这干什么？」\n",me);
        }
        if(me->query("shen")>-1)
        {
                message_vision(HIY"包打听把头一扭，根本不理$N。\n"NOR,me);
                return 1;
        }
        else
        {
                write(HIY"过了一会，包打听又朝你神秘一笑：「你算是问对人了，嘿嘿，不过你总得给我点好处吧？」\n"
                        "包打听在你面前把手搓来搓去，眼睛直盯着你的钱袋。\n"NOR);
                CHANNEL_D->do_channel(this_object(), "bd", "beg "+me->query("id"), 1);
                me->set_temp("ask包",1);
                return 1;
        }
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if(ob->query("money_id")&&ob->value()<1)
                return notify_fail("包打听显然觉得钱太少了，生气的噘了噘嘴。\n");
        if(ob->query("money_id")&&ob->value()>=1000000 && who->query_temp("ask包"))
        {
                write(HIY"包打听神秘的压低声音在你耳边说道：\n"
                        "「到墓后空地上去挖<dig 岳王墓>，保证你会有所收获，嘿嘿！」\n"NOR);
                CHANNEL_D->do_channel(this_object(), "bd", "addoil "+me->query("id"), 1);
                who->set("asked包",1);
                who->delete_temp("ask包");
                return 1;
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "bd", "hehe "+me->query("id"), 1);
                message_vision(HIW"包打听笑道：「既然你这么热心，我就告诉你一个天大的秘密！听说岳家枪法还在世间哦！」\n"NOR,who);
                tell_object(who, HIR"你差点被包打听气晕过去，这算什么秘密？\n"
                        "也许你应该考虑其他方式或多给点钱从他口里掏出点东西来。\n"NOR);
                CHANNEL_D->do_channel(me, "bd", "faint bao dating", 1);
                return 1;
        }
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("包打听的眼光到处乱转，一定又在想什么坏主意了。\n");
                break;
        case 1 :
                say("包打听叹道: 「又没钱了，只要谁有钱，我保证告诉他一个大秘密！嘿嘿！」\n");
                break;
        }
}
