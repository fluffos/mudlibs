#include <ansi.h>

inherit NPC;

int give_card();

void create()
{
        set_name(HIG "花满楼" NOR, ({"zmud wizard", "zmud", "wizard"}));
        set("gender", "男性" );
        set("long", HIM "男是天涯会员服务中心的管理人员。\n" NOR);
        set("title", HIY "天涯会员服务中心管理员" NOR);
        set("nickname", HIR "天涯客服" NOR); 
        set("age", 20);
        set("str", 99);
        set("con", 99);
        set("int", 99);
        set("dex", 99);
        set("per", 29);
        set("combat_exp", 650000);
        set("attitude", "peaceful");

        set("max_qi", 8400);
        set("max_jing", 8400);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 800);

        set("inquiry", ([
                "天涯会员卡" : (: give_card :),               
        ]));

        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);
        set_temp("apply/armor", 200);
        setup();

  carry_object("/clone/misc/long_cloth")->wear(); 

}

int give_card()
{
        object me, tycard, ob;
        int rmb;

        me = this_player();
        rmb = me->query("rmb");

        // 已经成为会员, 卡片丢失后领取
        if (me->query("is_member"))
        {
              if (ob = present("tianya card", me)) 
              {
                     write(HIG "花满楼说道：“你已经领取了天涯会员卡！请不要在这捣乱！”\n" NOR);
                     return 1;
              }
              // 判断是否在挂失
              if (! me->query("card_lost"))
              {
                     write(HIR "花满楼说道：“如果你卡片丢失，请先联系营业员挂失！”\n" NOR);
                     return 1;
              }

              write(HIW "花满楼说道：“以后小心保管，这张天涯会员卡就交还给你了！\n" NOR);
              tycard = new("/clone/gift/tycard");
              tycard->move(me);
              message_vision(HIC "$N" HIC "从花满楼处领取一张" HIY "天涯会员卡" NOR "。\n" NOR,
                             me);
              me->delete("card_lost");
              return 1;            
        }

        // 非会员
        else
        {
             if (me->query("rmb") < 50)
             {
                      write(HIR "花满楼说道：“对不起，你注入的资金不足，无法申请会员。”\n" NOR);         
                      return 1;
             }

             write(NOR + CYN "花满楼说道：“好吧，从现在开始你就成为天涯会员了！\n" NOR);
             write(NOR + CYN "花满楼说道：“这张会员卡就交给你了，以后请遵守会员条例！\n" NOR);
             message_vision(HIG + me->name() + HIG "从花满楼处领取一张" HIY "天涯会员卡" NOR " 。\n" NOR,
                            me);
             tycard = new("/clone/gift/tycard");
             tycard->move(me);
             me->set("is_member", 1);
             CHANNEL_D->do_channel(this_object(), "chat", me->name() + "正式加入天涯会员！");
             return 1;       
        }
}
void unconcious()
{
        die();
}

