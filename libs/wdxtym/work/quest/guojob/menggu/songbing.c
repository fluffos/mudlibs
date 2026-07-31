#include <ansi.h>
inherit NPC;
int heal_other();
void create()
{
    set_name("宋军伤兵", ({ "shang bing", "bing" }));
    set("gender", "男性" );//性别与上面对应
        set("long",
"一个刚从前线退下来的宋军的伤兵，看样子他伤的不轻。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIC"大宋官兵"NOR);
  set("qi",300);
  set("jing",300);
  set("max_qi",400+random(590));
  set("max_jing",400+random(590));
        set("per", 25);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 200000+random(300000));
        set("chat_chance", 20);
        set("chat_msg", ({
                "宋军伤兵说道：唉呀呀，好疼啊！！\n",
                "宋军伤兵说道：这次全靠江湖侠士，才能不失襄阳!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 100+random(150));
        set_skill("blade", 100+random(150));
        set_skill("parry", 100+random(150));
        set_skill("dodge", 100+random(150));
	set("inquiry", ([
		"疗伤" : "谢谢大侠你愿意救冶(jiuzhi)我!\n",
	]) );	
        
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();
  carry_object("/clone/misc/cloth")->wear();
}
void init( )
{
	object ob;
	add_action("heal_other","jiuzhi");
        call_out("hunting",180);
}

void hunting()
{
object ob=this_object();
write(HIR"宋军伤兵，由于无人为期冶疗，吐血而亡!\n"NOR);
destruct(ob);
}



int heal_other()

{

        object me=this_player(); 

        object ob=this_object(); 

        if (me->query("gender")=="男性")
   return notify_fail(HIC"这种事不适合大男人来做，你还是去抗敌吧。\n"NOR);

        if ( (int)me->query("jing")<20)

           return notify_fail("你太累了，歇息下吧。\n");

        if (me->query_temp("guo/sanbing")>9)

           return notify_fail("此人已经冶疗好了！\n");

   

  message_vision(HIB"$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....。\n"NOR,me,ob);

      me->add("jing",-me->query("eff_jing")/10);

      me->add_temp("guo/sanbing",1);

  if ( (int)me->query_temp("guo/sanbing")==8)

 {

  message_vision(CYN"$N过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,ob);


      me->delete_temp("guo/sanbing");
   if((int)me->query("combat_exp") < 1000000)   {
  message("vision", me->name() + HIG"由于成功的救冶了宋兵伤兵,增加了200修为和100潜能。\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",100);
        me->add("score",30);
        destruct(ob);
        }
        message("vision", me->name() + HIG"成功的救冶了宋兵伤兵。\n"NOR, me);
        me->add("score",2);
        me->add("shen",10);
        destruct(ob);

      
 }

      return 1;

} 

