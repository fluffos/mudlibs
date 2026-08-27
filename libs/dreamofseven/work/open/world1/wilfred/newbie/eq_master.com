#include <ansi.h>
inherit NPC;

void create()
{
  set_name("打鐵老師博", ({ "EQ master","master" }) );
  set("gender", "男性" );
  set("long",@LONG
謎般的老師博，任何壞掉的武器或裝備，交到他手
裡都能在短時間內修理好 [需要一點代價]。
LONG
);
  set("title",HIC"修理大師"NOR);
  set("age",74);
  set("level",80);
  set("race","human");

  set_skill("hammer",100);
  set_skill("dodge",40);
  set_skill("parry",50);
  set("chat_chance", 20);
  set("chat_msg", ({
"老師博將一塊燒紅的鐵塊「嗤」地一聲浸入一旁的水箱中。\n",
(: command("sweat") :),
(: command("hmm") :),
}));

  set("talk_reply","想要修理武器或是裝備嗎？ 把東西交給俺就行了！ (give master <物品 id>)\n");
  setup();
  carry_object(__DIR__"hammer")->wield();
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    command("thank");
    return 1;
  }

  message_vision(NOR"$N"NOR"拿出"+ob->query("name")+NOR"("+ob->query("id")+")給$n。\n"NOR,who,this_object());

  if( !ob->query("skill_type") && !ob->query("armor_type") )
  {
    command("say 俺不會修理這種東西，您另請高明吧。");
    return notify_fail("");
  }

  if(this_object()->is_busy())
  {
    command("say 俺還在忙，請您等一下。");
    return notify_fail("");
  }

  command("say 請稍等，俺馬上修理。");
  this_object()->start_busy(2);
  call_out("fixing",2,ob,who);

  return 1;
}

void fixing(object ob, object who)
{
  int price, level;

  if(!who || environment(who) != environment(this_object()))
  {
    command("drop all");
    return;
  }

  level = 100 - ob->query_durable();
  if(ob->query("value") == 1) price = level * ob->query("init_value") / 100;
    else price = level * ob->query("value") / 100;

  message_vision(NOR+YEL"\n打鐵老師博說﹕"NOR"$n"NOR+YEL"的修理費是"HIC+chinese_number(price)+NOR+YEL"枚古幣。\n\n"NOR,this_object(),ob);
  if(who->query("bank/past") < price)
  {
    command("say 等你存款夠了再來找我吧。");
    command("give "+who->query("id")+" "+ob->query("id"));
    return;
  }

  if(level > 90) command("say 這玩意兒幾乎快壞了嘛，沒關係，看俺的手段。");
    else if(level > 60) command("say 壞得滿嚴重的，不過不難修。");
           else if(level > 30) command("say 這東西還不算壞得很嚴重嘛，趁早修理也是好的。");
                  else command("say 這玩意兒倒是沒什麼損壞，你要修俺便給您照辦。");

  ob->set_durable(100);
  who->add("bank/past",-price);
  command("say 行了，修好了，謝謝惠顧。");
  command("give "+who->query("id")+" "+ob->query("id"));
  return;
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   message("world:world1:vision",
HIR"\n【鐵匠公會】鐵匠老師博被可惡的"+ob->name(1)+"殺死了。\n\n"NOR,users());

   tell_object(ob,HIC"[因為你的作惡多端，你得到了額外的 1 點聲望!!]\n"NOR);
   ob->add("popularity",1);
   ::die();
   return;
}

