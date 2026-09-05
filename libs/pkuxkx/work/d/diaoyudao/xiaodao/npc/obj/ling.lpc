// cart 

#include <ansi.h>
inherit ITEM;

void to_rob(object me);
int robit(object ppl);


void create()
{       
        seteuid(getuid());
        set_name(HIW"镖车"NOR, ({ "biao che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
 
    set("location",1);
    set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "辆");
        set("long", "一辆黑漆漆的镖车，上面插着镖旗。\n你可以drive(gan) che to exit来推动它前进\n");
        set("closed", 1);
        set("value", 2000);
        call_out("destroy3",900 + random(300),this_object());
}

void init()
{
    add_action("do_open","jie");
    add_action("do_gan","gan"); 
    add_action("do_gan","drive");
    add_action("do_touxiang","touxiang");
    remove_call_out("destroy2");
    call_out("destroy2",random(400)+600,this_object());
}

int do_open(string arg)
{
        object me, ob,master,player;
        string mname,mid;
        int rewardr;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();
    
        if(arg != "biao che")
          return notify_fail("你要打开什么？\n");
        if(me->query("in_dart"))
          return notify_fail("你想监守自盗？\n"); 
        if (ob->query("be_robbed"))
            return notify_fail("什么？\n");
        if(player = present(mid,environment()))
          if (living(player))
          return notify_fail("护镖的还在旁边，先把他做掉吧。\n");

        message_vision("$N将$n推走了。\n", me, this_object());
        CHANNEL_D->do_channel(this_object(), "rumor", mname+"护的镖被"+me->query("name")+"劫去了！", -1);
         rewardr=random(50)+30;
         message("vision",HIW"你得到了"+chinese_number(rewardr)+"点江湖声望的奖励！\n"NOR,me);
         message("vision",HIW"江湖上谈起你，纷纷摇头变色，你的道德下降了！\n"NOR,me);
         message("vision",HIW"你的经验增加了！\n"NOR,me);
         me->add("repute",rewardr);
         me->add("shen",-random(1000));
         me->add("combat_exp",30+random(100));
        ob->set("be_robbed",1);
    remove_call_out("destroy1");
        call_out("destroy1",1,ob);
        return 1;
}
int do_touxiang()
{
       object me, ob,master,player;
        string mname,mid;
        int rewardr;
        object *inv;
        int i;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();

    if (this_object()->query("masterid") != me->query("id"))
        return notify_fail("这不是你的镖车！\n");
                inv = all_inventory(environment(me));
                for(i=sizeof(inv)-1; i>=0; i--) {
                    if (inv[i]->query("uni_target") == me)
                        destruct(inv[i]);
                   }
        message_vision("$N抛下武器向劫匪投降，劫匪嘿嘿一笑：算你聪明！\n",me,this_object());    
        message_vision("劫匪将$n推走了。\n", me, this_object());
        CHANNEL_D->do_channel(this_object(), "rumor", mname+"护的镖被劫匪劫去了！", -1);
        ob->set("be_robbed",1);
    remove_call_out("destroy1");
        call_out("destroy1",1,ob);
        return 1;
}

int robit(object ppl)
{
    object *inv;
    int i;
    inv=all_inventory(environment(ppl));
    for(i=0;i<sizeof(inv);i++)
    {
                 if(!userp(inv[i])&&living(inv[i])&&inv[i]->query("shen")<0 && (inv[i]->query("id") != "cart robber"))
        if(random(2) > 0)
        {
            message_vision("斜刺里冲出来$N,猛地对$n痛下杀手！\n",inv[i],ppl);
            message_vision("趟子手大呼：有人劫镖阿，快护镖，快快！\n",ppl);
            ppl->start_busy(5);
                         inv[i]->fight_ob(ppl);
        }
    }
    return 1;
}
