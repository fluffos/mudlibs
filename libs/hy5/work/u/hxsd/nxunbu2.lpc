// kuangfeng.c 狂风

#include <ansi.h>
inherit NPC;

void catched(object me,object dest);
void greeting(object ob);
int catch_pk(object me,object dest);
int waiting(object me, object dest);
int checking(object me, object dest);
void bu_move(object me);

void create()
{
        set_name(HIR"狂风"NOR, ({ "kuang feng", "feng", "kuangfeng" }));        
        set("title", HIY"四大名捕之首“"HIR"风"HIY"”"NOR);
        set("gender", "男性");
        set("age", 38);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "他，就是闻名天下的四大名捕的老大，面上木无表情，冷若冰霜，"+
        	"\n犹如一具行尸走肉，令人一望而生畏。\n");
        set("combat_exp", 5000000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("finger", 250);
        set_skill("yizhi-chan", 250);
        set_skill("sword", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("hunyuan-yiqi", 250);
        set_skill("wuying-jian", 250);
        set_skill("shaolin-shenfa", 250);
/*
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 60);
*/

        map_skill("force", "hunyuan-yiqi");
        map_skill("finger", "yizhi-chan");
        map_skill("sword", "wuying-jian");
        map_skill("parry", "wuying-jian");


        map_skill("dodge", "shaolin-shenfa");
          
/*
        set("max_qi", 18000);
        set("max_jing", 3000);
        set("neili", 18000); 
*/
        set("max_neili", 5000);
           set("neili",5000);
            set("jiali",150);

        prepare_skill("finger","yizhi-chan");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "finger.jingmo" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "sword.wuying" :),
                (: command("unwield jian") :),
        
        (: command("wield jian") :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
                (: command("unwield jian") :),
                (: command("wield jian") :),
            }) ); 
       
        set("chat_msg",({
     HIR"狂风"HIY"哼了一声，说道：“有四大名捕在，谁也不要杀人...谁要是杀了人给我找麻烦，就让他妈的去坐牢！”\n"NOR,
     HIR"狂风嘿嘿嘿地奸笑了几下，低声对你说：“杀人其实是很好玩的，当杀人狂更加刺激，\n"+
         "如果有一天我下岗了，一定会去当杀人狂，嘿~！嘿~！嘿~！”\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/gangjian")->wield();
}

void init()
{
        object ob;
        ::init();

        if (interactive(ob = this_player()))
        {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }        
}
void greeting(object ob)
{        object me;
        me = this_object();

        if(!ob || environment(ob) != environment()) return;
        if ( ob->query("PKS") > 0 )
        {
                if ( ! is_fighting()) 
                {
                        call_out("catch_pk",0,me,ob);
                        return; 
                }
                else
                {
                        message_vision(HIC "$N对$n说道：听说你个小混蛋杀了人，等我忙完了再来收拾你！"
                                +RANK_D->query_rude(ob)+"，算你命大，再留你多活几天！\n" NOR, me, ob);
                        return;
                }
        }
        else
        {
                command("say 好想抓个杀人犯去领赏钱啊！怎么没人杀人呢？\n");//              init();
        }
        return;
}

int catch_pk(object me,object dest)
{
        if( objectp(dest) && present(dest, environment(me))
                 && !environment(me)->query("no_fight"))
        {
//              if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
                if ( dest->query("qi") <= 40)
//              if ( dest->query("qi") == 0 )
                {
                        catched(me,dest);
                        return 1;
                }

                message_vision(HIY "$N对$n说道：听说你是个杀人狂，整天以杀人为乐，现在碰到了我，"
                                    "\n算你命苦了，乖乖的跟我回去对大家做个交代，否则让你"
                        +RANK_D->query_rude(dest)+"见阎王！\n" NOR, me, dest);
                me->set_leader(dest);
                me->fight_ob(dest);
                
                dest->fight_ob(me);
               
                call_out("checking", 0,  me, dest);
                
        }
        else  
                call_out("waiting", 1, me, dest);
        
        return 1;
}

int waiting(object me, object dest)
{
        if ( objectp(dest) )
        {
                if (dest->is_ghost())
                {
                        dest->apply_condition("killer",0);
                        return 1;
                }
                else if (me->is_fighting() && present(dest, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }
                     else if (!me->is_fighting() && present(dest, environment(me)))
                     {
                              call_out("checking",0,me);
                              return 1;
                     }                  
        }               
        
        remove_call_out("waiting");
        call_out("waiting", 10, me);
    return 1;
}

int checking(object me, object dest)
{
        object ob;

        if (me->query("qi") == 0)
                return 1;

        if (me->is_fighting())
        {
                call_out("checking",0,me);
                return 1;
        }
        else  init();


        if (objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == dest->query("name") )
        {
                dest->apply_condition("killer",0);
                me->set("PKS",0);
                            me->set_leader(0);
                return 1;
        }

//      if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
        if ( dest->query("qi") <= 40 )
//      if ( dest->query("qi") == 0 )
        {
//              command("say 这次是checking()在工作");
                catched(me,dest);
                return 1;
        } 

        call_out("waiting", 0, me, dest);
        return 1;
}

void catched(object me,object dest)
{       
//      command("say "+(string)dest->query("id")+(string)dest->query("qi"));
        
        dest->apply_condition("gvmt_jail", 30);
        dest->unconcious(); // 昏迷
//      command("get "+(string)dest->query("id"));
        command("say 哈哈哈哈，就这么三脚猫的功夫还敢出来当杀人狂！你已经没着了，看绑吧！" );
        message_vision(HIC"只听“哗啦”一声，$N抛出锁链将人犯锁住，押解着"+(string)dest->query("name")+"向嘉峪关方向赶去。\n"NOR,me);

        dest->move("/d/gvmt/jianyu_do");
        me->move("/d/gvmt/jianyu_do");
        

              me->set("startroom", "/d/gvmt/jianyu_do");
          me->set("PKS",0);
       dest->apply_condition("killer",0);
//      command("drop "+(string)dest->query("id"));
        me->set_leader(0);
                
        message_vision(HIC"$N啐了口唾沫，将"+(string)dest->query("name")+"重重的掷在地上，狠狠地踢了一脚，留下一个清晰的鞋印，转身锁上牢门离开。\n"NOR,me);
        bu_move(me);
        return;
}


void bu_move(object me)
{
        switch ( random(6) )
        {
        case 0 :
                me->move("/d/city/kedian"); // 扬州
                break;
        case 1 :
                me->move("/d/city4/center"); // 长安
                break;
        case 2 :
                me->move("/d/city3/kedian"); // 长安
                break;
              case 3 :
                me->move("/d/kunming/kedian"); // 成都
                break;
        case 4 :
                me->move("/d/jyguan/kedian"); // 昆明
                break;
        case 5 :
                me->move("/d/city2/kedian"); // 北京
                break;
        }  
        message_vision("$N走了过来。\n",me);
                
        return;
}


void die()
{
        object ob;
        message_vision("$N倒在地上,挣扎了几下,死了。\n", this_object());
        ob = new("/cao/bukuai");
        destruct(this_object());
}

