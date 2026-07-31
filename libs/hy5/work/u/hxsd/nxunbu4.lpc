// baoyu.c 暴雨

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
        set_name( BLU "暴雨"NOR, ({ "bao yu", "baoyu", "yu" }));        
        set("title", HIY"四大名捕之二“"BLU"雨"HIY"”"NOR);
        set("gender", "男性");
        set("age", 32);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "他，就是闻名天下的四大名捕的老二，虽然武功在四人中是最低的，
但是处事稳重，心细如发，能力一点都不比其他三人逊色。\n");
        set("combat_exp", 2000000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("cuff", 200);
        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("strike", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("zixia-shengong", 200);
	   set_skill("lonely-sword", 200);
        set_skill("poyu-quan", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("qiankundanuoyi", 200);
/*
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);
*/

        map_skill("force", "zixia-shengong");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "lonely-sword");
        map_skill("parry", "qiankundanuoyi");
        map_skill("dodge", "qiankundanuoyi");
          
/*
        set("max_qi", 12000);
        set("max_jing", 2500);
*/
        set("neili", 4000); 
        set("max_neili", 4000); 
           set("jiali",100);

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.pojian" :),
                (: perform_action, "sword.podao" :),
                (: perform_action, "sword.poqi" :),
                (: perform_action, "sword.poanqi" :),
                (: perform_action, "sword.pobian" :),
                (: perform_action, "sword.pozhang" :),
                (: perform_action, "cuff.leidong" :),
                (: perform_action, "strike.wuji" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     BLU"暴雨"HIY"哼了一声，说道：“有四大名捕在，谁也不要杀人...谁要是杀了人给我找麻烦，就让他妈的去坐牢！”\n"NOR,
     BLU"暴雨露出迷惑的表情，百思不解的摇摇头说：“咦！你们办事怎么这么水？如此容易就被PK了，
         怪不得要出动我们四大名捕啦。”\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/gangjian")->wield();
//        carry_object("/clone/weapon/gangjian")->wield();
//        carry_object("/d/city/obj/tiejia")->wear()
;
}

void init()
{
        object ob;
        ::init();

        if (interactive(ob = this_player()))
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }        

void greeting(object ob)
{
        object me;
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
                command("say 他妈的，亚洲金融风暴害得我都快要破产了，没办法，只好重操旧业，出来捉杀人狂回去赚钱。");    
//              init();
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

                message_vision(HIY "$N对$n说道：听说你是个杀人狂，整天以杀人为乐，现在碰到了我，
                                    算你命苦了，乖乖的跟我回去对大家做个交代，否则让你"
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
                me->set_leader(0);
                            me->set("PKS",0);
                return 1;
        }

//      if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
        if ( dest->query("qi") <= 40 )
        {
//      if ( dest->query("qi") == 0 )
//              command("say 这次是checking()在工作");
				catched(me,dest);
                return 1;
        } 
        else if (dest->query("qi") > 0) init();

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
