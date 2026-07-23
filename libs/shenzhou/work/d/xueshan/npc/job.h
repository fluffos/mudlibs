#include <ansi.h>
string ask_me()
{

        object asker,me;
        asker = this_player();
        me = this_object();
        if ( asker->query_skill("lamaism") < 51 )
                                        return RANK_D->query_respect(asker) + "不懂佛法，请勿误人子弟。"; 
        if ( me->query("assigned_asker") )
                                        return RANK_D->query_respect(asker) + 
        "现在已有人在施法渡人，你过一段时间再来吧。";
        say("\n拉章活佛说道：大师佛法渊深，又肯于渡人，真乃武林之福啊。\n");
                me->set("assigned_asker", asker->query("id"));            
                message_vision("\n拉章活佛长袖一拂，一道青焰闪过，现出一个四方莲台。\n\n", asker);
                                        return "老衲已准备好了，请将奸徒交与老衲。\n";
}

int accept_object(object ob, object obj)
{
        mapping fam;
        object me = this_object();
        int obj_exp,my_exp,got_pot,shen;
        shen = obj->query("shen");
        if (ob->query("id")!=me->query("assigned_asker"))
                                return notify_fail("你是哪里跳出来的，想骗本座？\n");
        if (shen <=1)
                        {
                        say("你是什么意思？活得不耐烦了？\n");    
        me->delete("assigned_asker");    
        me->kill_ob(ob);
                                return 1;
                        }
        if (userp(obj)==1)
                        {
                                me->delete("assigned_asker");       
                    return notify_fail("你让玩家串通作弊，以为本座是傻瓜？\n");
            }
        obj_exp=(int)obj->query("combat_exp",1);
        my_exp=(int)ob->query("combat_exp",1);
        if (my_exp>obj_exp*2)
                        {
                    me->delete("assigned_asker");       
                    return notify_fail("你找个小东西来劝导，未免太失身份。\n");
                    }
         message("vision", HIY"\n拉章活佛双手一挥，已将"+obj->query("name")+"送上莲台，四周风雷大作。\n"NOR,  environment(ob),ob);
         write (HIY"拉章活佛双手一挥，已将"+obj->query("name")+"送上莲台，四周风雷大作。\n"NOR); 
         message(HIR "vision", ob->name()+HIR"用力摇动法杵，九环齐飞，风雷顿息。\n",environment(ob),ob);
         write("你用力摇动法杵，九环齐飞，风雷顿息。\n"NOR);
         message("vision", ob->name()+"大声念诵大乘般若经文，一片红光笼罩着法台。\n",environment(ob),ob);
         write ("你大声念诵大乘般若经文，一片红光笼罩着法台。\n");
         message("vision",ob->name()+"一声断喝，云淡风清，四处踪迹不见。\n"NOR,environment(ob),ob);
         write ("你一声断喝，云淡风清，四处踪迹不见。\n");
         got_pot=(obj_exp/my_exp)*100+random((int)ob->query_skill("lamaism",1));
         ob->add("combat_exp",got_pot*2+random(40));
                 log_file("/job/xs-duren", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")在雪山度人" + got_pot*2 + "经验和\n" ); 
         ob->add("potential",got_pot);
		 if (ob->query("potential")>ob->query("max_potential")) ob->set("potential",ob->query("max_potential"));
         ob->add("neili",-got_pot*2+80-random(160)); 
         ob->start_busy(5);
         if ((int)ob->query("neili",1)<0)
                         {
                                ob->set("neili",0);
                                ob->unconcious();  
             }
         say("拉章活佛合什礼拜道：大师以无边佛法渡化俗人，使其破去心魔真乃功德无量。\n");
        destruct(obj);
         call_out("destroying", 20+random(20) , obj);
                                return 1;
                 }

void destroying(object obj)
{
		this_player()->delete("assigned_asker");
        return;
}
