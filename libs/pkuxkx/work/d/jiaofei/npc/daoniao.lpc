// jiaofei task npc
// 道鸟禅师
#include <ansi.h>

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("道鸟禅师", ({ "daoniao npc"}));
        set("title", HIY"临安剿匪军需后勤粮草一应物资总管"NOR);
               
        set("shen_type", 1);

        set("str", 30);
        set("gender", "男性");
        set("age", 25);
        set("per",30);
        set("long","出身少林的道鸟禅师，一生刚正不阿，虽然武功平常，却有着一颗拳拳报国之心。
为了剿灭为祸天下的悍匪，毅然承担起了后勤方面的工作。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("inquiry", ([
                "水桶" : "你要买吗？100文一个。\n",
                "水" : "我这里有，拿去救火吧，但是你得有木桶。\n",
                "救火" : "带着装满了水的木桶，对着人倒下去就好了。pour 水量 on id\n",
                "木板": "买点木板吧，用得上。\n",
        ]));
        
        set("chat_chance",10);
        set("chat_msg",({
            "军马未动，粮草先行，朝廷大军所到之处，必须供应充足。\n",
            "听说土匪有一种器械，发动起来，火势凶猛，寻常之水根本无法扑灭。幸好朝廷已有应对之策。\n",
            "铁掌帮有一处很隐秘的仓库，如果能够奇袭成功，必对剿匪大有帮助。但必须经过一片沼泽，十分危险。\n",
        })
        );
        
        set("vendor_goods", ({
                __DIR__"obj/shuitong",
                __DIR__"obj/muban",
        }));

        setup();

}

void init()
{
        object ob;
        
        ::init();

        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_qu_shui", "qushui");
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
    object me = this_player();
    
    if(JIAOFEI_D->istaskstart() != 1 && !wizardp(me))
    {
        command("shake");    
        return 1;
    }    
    if(undefinedp(me->query_temp("jiaofei/code-qushui")))
    {
        write("你在说什么？我不懂。\n");
        return 1;
    }
    
    if(time() - me->query_temp("jiaofei/code-qushui_time") > 30)
    {
        me->delete_temp("jiaofei/code-qushui");
        me->delete_temp("jiaofei/code-qushui_time");
        write("这是朝廷已经作废的密文，你从哪里得来的？\n");
        return 1;
    }
    
    if(me->query_temp("jiaofei/code-qushui") != arg)
    {
        message("vision",this_object()->query("name")+"疑惑的说：你搞错了吧？\r\n",environment(me));        
    }
    else
    {
        object item = present( "shuitong", me );

        if (!objectp(item) )
        {
            return notify_fail("你身上没有水桶，你可以在我这里买一个。\n");
        }
                
        message("vision",this_object()->query("name")+"呵呵一笑，说道：嗯，好，赶快取水去救火吧，火情危急啊。\r\n",environment(me));
        me->delete_temp("jiaofei/code-qushui");
        me->delete_temp("jiaofei/code-qushui_time");
                
        message_vision( name() + "将" + item->name() + "装满清水。\n", me);

        item->set("liquid/type", "jiaofei_water");
        item->set("liquid/name", "清水");
        item->set("liquid/remaining", item->query("max_liquid"));
        item->set("liquid/drink_func", 0);
    }
    return 1;
}

int do_qu_shui( string arg )
{
        object me = this_player();
        string* code = ({});
        
        object item = present( "shuitong", me );

        if (!objectp(item) )
        {
            return notify_fail("你身上没有水桶，你可以在我这里买一个。\n");
        }
        
        if (!undefinedp(me->query_temp("jiaofei/code-qushui")))
        {
            return notify_fail("你还没有回答我的问题，朝廷的密文是什么？\n");
        }
        
        command("look "+me->query("name"));
        command("say 现在奸细横行，而水源紧缺，你还需报上朝廷的密文，我方能把水给你。");
        code = ANTIROBOT_D->generatewebimgcode();
        write(RED"系统提示你：请访问\nhttp://www.pkuxkx.net/antirobot/robot.php?filename="+code[1]+"\n来获取口令！\n"NOR);            
        me->set_temp("jiaofei/code-qushui",code[0]);
        me->set_temp("jiaofei/code-qushui_time",time());        
        //if(wizardp(me))
        {
            write(code[0]+"\n");    
        }         
        return 1;
}

