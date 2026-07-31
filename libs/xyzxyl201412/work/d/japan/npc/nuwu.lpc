inherit NPC;
#include <ansi.h>;
int ask_con();
int ask_kar();
int ask_spi();
int ask_int();
void create()
{
      set_name("铃木加代", ({ "lingmu jiadai","lingmu","jiadai"}) );
         set("gender", "女性" );
         set("title", "神户占卜屋" );
set("per", 30 );
         set("age", 25 );
         set("nickname", HIY"大巫师"NOR );
        set("long",
   "一位长发披肩,正坐在白色光晕中冥思的女子.\n");
        set("inquiry",  ([
                "悟性" : (: ask_int :),
                "福缘" : (: ask_kar :),
                "根骨" : (: ask_con :),
      "推算" : "你要推算悟性?福缘?根骨?灵性?",
                "灵性" : (: ask_spi :),
        ]) );
        set("combat_exp", 500);
        set("attitude", "friendly");
     set("chat_chance", 3);
        set("chat_msg", ({
                   name()+"默默地冥思。。。\n",
                   "只见"+name()+"抬手轻轻地抚摩着水晶球。。。\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me,object obj)
{
       if(this_object()->is_busy())
       {
       command("say 请稍候,我正忙着呢!");
       return 0;
       }
       if(query(me->query("id")))
       {
       command("say 已经收过你的钱了,你要推算 悟性 福缘 根骨 灵性 中的哪一项?");
       return 0;
       }
       if(!(string)obj->query("money_id")||(string)obj->query("money_id")!="gold")
       {
          command("say 请用金子支付!");
       return 0;
       }
       if((int)obj->value() < 20000 )
       {
       say(CYN+name()+"轻蔑地说道: 您也太小器了吧!\n"NOR);
       return 0;
       }
       command("nod "+me->query("id"));
       command("say 好,金子我收下了,你要推算哪一项啊?");
       set(me->query("id"),1);
       return 1;
}

int ask_int()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say 请稍候,我正忙着呢!");
       return 1;
       }
      if(!query(me->query("id")))
        {
       command("say 推算一次费神费力的您是否能付些劳务费呢!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
       say("\n"+HIG+name()+"双手在水晶球上一阵轻抚,忽然一道"+HIW+" 白光 "+HIG+"注入水晶球内 ... \n\n"NOR);
        if (me->query("int") >= 30)
        {
        command("say 你的悟性很高嘛！");
        return 1;
        }
        if (me->query("int") >= 20 && me->query("int") < 30)
        {
        command("say 你的悟性还不错。");
        return 1;
        }
        if (me->query("int") > 10 && me->query("int") < 20)
        {
        command("say 你的悟性一般。");
        return 1;
        }
        if (me->query("int") <= 10 )
        {
        command("say 我没见过你这么笨的人！");
        return 1;
        }
        return 1;
}
int ask_kar()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say 请稍候,我正忙着呢!");
       return 1;
       }
      if(!query(me->query("id")))
        {
       command("say 推算一次费神费力的您是否能付些劳务费呢!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
       say("\n"+HIG+name()+"双手在水晶球上一阵轻抚,忽然一道"+HIW+" 白光 "+HIG+"注入水晶球内 ... \n\n"NOR);
        if (me->query("kar") >= 30)
        {
        command("say 你的福缘很高嘛！");
        return 1;
        }
        if (me->query("kar") >= 20 && me->query("kar") < 30)
        {
        command("say 你的福缘还不错。");
        return 1;
        }
        if (me->query("kar") > 10 && me->query("kar") < 20)
        {
        command("say 你的福缘一般。");
        return 1;
        }
        if (me->query("kar") <= 10 )
        {
          command("say 你比刘备还背！！");
        return 1;
        }
        return 1;
}
int ask_spi()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say 请稍候,我正忙着呢!");
       return 1;
       }
      if(!query(me->query("id")))
        {
       command("say 推算一次费神费力的您是否能付些劳务费呢!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
       say("\n"+HIG+name()+"双手在水晶球上一阵轻抚,忽然一道"+HIW+" 白光 "+HIG+"注入水晶球内 ... \n\n"NOR);
        if (me->query("spi") >= 30)
        {
        command("say 你的灵性很高嘛！");
        return 1;
        }
        if (me->query("spi") >= 20 && me->query("spi") < 30)
        {
        command("say 你的灵性还不错。");
        return 1;
        }
        if (me->query("spi") > 10 && me->query("spi") < 20)
        {
        command("say 你的灵性一般。");
        return 1;
        }
        if (me->query("spi") <= 10 )
        {
        command("say 我要是告诉你1+1=2，你能知道1+2=?吗？");
        return 1;
        }
        return 1;
}
int ask_con()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say 请稍候,我正忙着呢!");
       return 1;
       }
      if(!query(me->query("id")))
        {
       command("say 推算一次费神费力的您是否能付些劳务费呢!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
       say("\n"+HIG+name()+"双手在水晶球上一阵轻抚,忽然一道"+HIW+" 白光 "+HIG+"注入水晶球内 ... \n\n"NOR);
        if (me->query("con") >= 30)
        {
        command("say 你的根骨很高嘛！");
        return 1;
        }
        if (me->query("con") >= 20 && me->query("spi") < 30)
        {
        command("say 你的根骨还不错。");
        return 1;
        }
        if (me->query("con") > 10 && me->query("spi") < 20)
        {
        command("say 你的根骨一般。");
        return 1;
        }
        if (me->query("con") <= 10 )
        {
        command("say 你体弱多病，我看你活不长了。。");
        return 1;
        }
        return 1;
}

int accept_fight(object me)
{
        command("say 你什么人啊！一个算命的老头你也欺负！！");
        return 0;
}

