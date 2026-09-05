// girl.c 兑奖小姐

#include <ansi.h>
inherit NPC;

void create()
{
          set_name("兑奖小姐", ({ "girl" }) );
         set("gender", "女性" );
        set("age", 19);
        set("long",
                 "这是专门负责兑奖的小姐，你可以在她这里兑奖(duijiang)。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 3); 
        set("chat_msg", ({
"小姐说道：「来！看看你是不是中奖了！」\n",
"小姐笑嘻嘻地说道：「昨天刚刚有个人中了头奖呢！」\n",
        }));
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy","duijiang");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                          say( "小姐招呼道：「这位" + RANK_D->query_respect(ob)
                                  + "是来兑奖的吗？」\n");
                        break;
                case 1:
                          say( "小姐微笑着说：「" + RANK_D->query_respect(ob)
                                 + "，是不是想看看自己中奖了没有？」\n");
                        break;
        }
}

int do_buy(string arg)
{
        object me;
        string file,number,level;
        string* dj_number;
        object* inv;
        int i,j;
        me = this_player();
        inv = all_inventory(me);
        
        this_object()->start_busy(10);
        if ( !(file = read_file("/d/gift/icer/jingli_number")) )
        {
                write("读文件出错。\n");
                return 1;
        }
        dj_number = explode(file,"\n"); 
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
        {
                if ((inv[i]->query("name") == HIR"精力彩票"NOR)&&(inv[i]->query("id") == "cai piao"))
                {
                        for (j = 0; j < sizeof(dj_number); j++)
                        {
                                sscanf(dj_number[j],"%s %s",number,level);
                                if (inv[i]->query("long") == "这是一张精力彩票，票号是" + number + "号。\n")
                                {
                                        if (level == "0")
                                        {
                                                write(HIR"恭喜你！中了精力彩票特等奖！你的最大精力上升1000点！\n"NOR);
                                                shout(HIR + me->query("name") + "中了精力彩票特等奖！\n");
                                                me->add("max_jingli",1000);
                                        }
                                        if (level == "1")
                                        {

                                                write(HIR"恭喜你！中了精力彩票一等奖！你的最大精力上升500点！\n"NOR);
                                                shout(HIG + me->query("name") + "中了精力彩票一等奖！\n");
                                                me->add("max_jingli",500);
                                        
                                        }
                                        if (level == "2")
                                        {
                                                write(HIR"恭喜你！中了精力彩票二等奖！你的最大精力上升300点！\n"NOR);
                                                shout(HIW + me->query("name") + "中了精力彩票二等奖！\n");
                                                me->add("max_jingli",300);
                                        }
                                        if (level == "3")
                                        {
                                                write(HIR"恭喜你！中了精力彩票三等奖！你的最大精力上升100点！\n"NOR);
                                                shout(HIM + me->query("name") + "中了精力彩票三等奖！\n");
                                                me->add("max_jingli",100);
                                        }
                                }
                        }
                        destruct(inv[i]);
                }
        }
        if ( !(file = read_file("/d/gift/icer/neili_number")) )
        {
                write("读文件出错。\n");
                return 1;
        }
        dj_number = explode(file,"\n"); 
        inv = all_inventory(me);
        if (sizeof(inv) != 0)
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if ((inv[i]->query("name") == HIR"内力彩票"NOR)&&(inv[i]->query("id") == "cai piao"))
                {
                        for (j = 0; j < sizeof(dj_number); j++)
                        {
                                sscanf(dj_number[j],"%s %s",number,level);
                                if (inv[i]->query("long") == "这是一张内力彩票，票号是" + number + "号。\n")
                                {
                                        if (level == "0")
                                        {
                                                write(HIR"恭喜你！中了内力彩票特等奖！你的最大内力上升1000点！\n"NOR);
                                                shout(HIR + me->query("name") + "中了内力彩票特等奖！\n");
                                                me->add("max_neili",1000);
                                        }
                                        if (level == "1")
                                        {
                                                write(HIR"恭喜你！中了内力彩票一等奖！你的最大内力上升500点！\n"NOR);
                                                shout(HIG + me->query("name") + "中了内力彩票一等奖！\n");
                                                me->add("max_neili",500);
                                        }
                                        if (level == "2")
                                        {
                                                write(HIR"恭喜你！中了内力彩票二等奖！你的最大内力上升300点！\n"NOR);
                                                shout(HIW + me->query("name") + "中了内力彩票二等奖！\n");
                                                me->add("max_neili",300);
                                        }
                                        if (level == "3")
                                        {
                                                write(HIR"恭喜你！中了内力彩票三等奖！你的最大内力上升100点！\n"NOR);
                                                shout(HIM + me->query("name") + "中了内力彩票三等奖！\n");
                                                me->add("max_neili",100);
                                        }
                                }
                        }
                        destruct(inv[i]);
                }
        }
        if ( !(file = read_file("/d/gift/icer/rongmao_number")) )
        {
                write("读文件出错。\n");
                return 1;
        }
        dj_number = explode(file,"\n"); 
        inv = all_inventory(me);
        if (sizeof(inv) != 0)
        for(i=sizeof(inv)-1; i>=0; i--)
        {
                if( (inv[i]->query("name") == HIR"容貌彩票"NOR)&&(inv[i]->query("id") == "cai piao"))
                {
                        for (j = 0; j < sizeof(dj_number); j++)
                        {
                                sscanf(dj_number[j],"%s %s",number,level);
                                if (inv[i]->query("long") == "这是一张容貌彩票，票号是" + number + "号。\n")

                                {
                                        if (level == "0")
                                        {
                                                write(HIR"恭喜你！中了容貌彩票特等奖！你的容貌上升100点！\n"NOR);
                                                shout(HIR + me->query("name") + "中了容貌彩票特等奖！\n");
                                                me->add("per",100);
                                        }
                                        if (level == "1")
                                        {
                                                write(HIR"恭喜你！中了容貌彩票一等奖！你的容貌上升50点！\n"NOR);
                                                shout(HIG + me->query("name") + "中了容貌彩票一等奖！\n");
                                                me->add("per",50);
                                        }
                                        if (level == "2")
                                        {
                                                write(HIR"恭喜你！中了容貌彩票二等奖！你的容貌上升30点！\n"NOR);
                                                shout(HIW + me->query("name") + "中了容貌彩票二等奖！\n");
                                                me->add("per",30);
                                        }
                                        if (level == "3")
                                        {
                                                write(HIR"恭喜你！中了容貌彩票三等奖！你的容貌上升10点！\n"NOR);
                                                shout(HIM + me->query("name") + "中了容貌彩票三等奖！\n");
                                                me->add("per",10);
                                        }
                                }
                        }
                        destruct(inv[i]);
                }
        }
        write(HIG"兑奖完毕，谢谢您惠顾！\n"NOR);
        return 1;
}
int choujiang(int max_number,int level,string type)
{
        int i,number,j;
        string strshout;
        i = max_number;
        if (level == 0)
        {
                number = random(i);
                shout(HIW + "【兑奖小姐】：" + HIR + type + "彩票特等奖号码是：" + sprintf("%d",number) + "\n" + NOR);
                return 1;
        }
        strshout = "";
        if (level == 1)
        {
                for (j = 0;j < 5;j++)
                        strshout = strshout + sprintf("%d",random(i)) + " ";
                shout(HIW + "【兑奖小姐】：" + HIG + type + "彩票一等奖号码是： " + strshout + "\n" + NOR);
                return 1;
        }
        if (level == 2)
        {
                for (j =0;j < 10;j++)
                        strshout = strshout + sprintf("%d",random(i)) + " ";
                shout(HIW + "【兑奖小姐】：" + HIM + type + "彩票二等奖号码是： " + strshout + "\n" + NOR);
                return 1;
        }
        if (level == 3)
        {
                for (j = 0;j < 20;j++)
                        strshout = strshout + sprintf("%d",random(i)) + " ";
                shout(HIW + "【兑奖小姐】：" + HIY + type + "彩票三等奖号码是： " + strshout + "\n" + NOR);
                return 1;
        }
        return 1;
}

