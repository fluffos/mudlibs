// migong lev10  du

#include <ansi.h>

inherit NPC;


void create()
{

      set_name(MAG"盲婆婆"NOR,({ "mang popo" , "popo" }));

       set("gender", "女性" );
 set("long",
"百毒神君的师姐,武功极高，因被百毒神君暗算毒瞎了
双眼，所以躲藏于次。\n");
        	  set("force_factor",100+random(200));
  set("max_qi",39000+random(4200));
  set("max_jing",39000+random(4200));
  set("max_sen",39000+random(4200));
  set("max_neili",19000+random(4000));
  set("max_mana",19000+random(4000));
  set("eff_neili",12500+random(4000));
  set("neili",19000+random(4000));
set("attitude", "aggressive");
        set("per", 1);
        set("age", 52);
set("no_get",1);
       set("jiali" , 200);
        set("shen", -10000);
               set("combat_exp", 8000000+random(2000000));
                 set_skill("claw", 400+random(60));

set_skill("unarmed", 400+random(60));

        set_skill("force", 300);
        set_skill("wudu-shengong", 300);
        set_skill("dodge", 290);
        set_skill("wudu-yanluobu", 250);
        set_skill("unarmed", 260);
        set_skill("qianzhu-wandushou", 260);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 280);
        set_skill("poison", 260);
        set_skill("literate", 280);
        set_skill("finger",260);
        set_skill("shedu-qiqiao",260);
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "finger.sandu" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "finger.sandu" :),
                (: perform_action, "dodge.snake" :),
        }) );


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");

        create_family("五毒教", 11, "长老");
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 550);

          set_temp("apply/armor", 350);
        set_temp("apply/damage", 350);


   set("inquiry", ([
"百毒神君" : "他是我师弟，这个狼心狗废的东西，我的眼睛就是他毒瞎的。",
"百毒尊者" : "百毒尊者也是我师弟，他也不是个好东西，和他师兄狼狈为奸。",
"眼睛" : "我的眼睛是被断肠草毒瞎的，只有七心海棠能治。",
"七心海棠" : "听说七心海棠就只有眠龙洞里有，但我找了许久就是没找到。"
]) );

        setup();

    //    carry_object("d/wudujiao/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
//        carry_object("d/wudujiao/npc/obj/wuxing");
   carry_object("/d/migong/obj/zhang")->wield();



}

int accept_object(object who, object ob)
{
	   if ((string)ob->query("id")=="qixin haitang") {
            say(MAG"盲婆婆"NOR"激动的叫道：“真是天不绝我,我总算能报仇了！”
说完就匆匆忙忙离开了。
\n");
           move("/d/migong/lev8/dong101");
            }
		return 1;
}

int hit_ob(object me, object ob, int damage)
{
if (ob)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
}
}

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
   int exp,pot,score,i;
int maxpot;
        ob = this_object();
       // me = query_temp("last_damage_from");
        me=  this_object()->query_last_damage_from();
        if (!me) return;
             me->add("score",1000);
        me->add("shen",1000);

        message_vision(WHT"$N被打烂了!!。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev10"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct");
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：让你见识是一下武术的真髓! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}

}
if (!me->query("migong/lev10"))
{
me->set("migong/lev10",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第十层!"NOR"。\n", users());
exp = 380000+random(25000);
pot = exp/2;
score = random(300)+550;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

}
        if((int)me->query("combat_exp") < 700000)   {
        message("vision", me->name() + "为江湖除害,增加了4000修为和2000潜能。\n", me);
        me->add("combat_exp",4000);
        me->add("potential",2000);
        destruct(ob);
        }
        destruct(ob);
        return;
}
