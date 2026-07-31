// migong lev15

#include <ansi.h>

inherit NPC;


void create()

{

   set_name(HIR"千年火龙王"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条巨大的龙，嘴里喷着火，看到了你，向你扑了过来。
它充斥着这整个洞穴，你顿觉空气的压抑，觉得它十分地可怕
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("qi",80000);
	       set("eff_qi",80000);
	       set("max_qi",80000);
set("jing",80000);
  set("eff_jing",800000);
  set("max_jing",800000);
set("neili",109999);
  set("max_neili",109999);
  set("max_sen",109999);
  set("max_mana",109999);

      set("dex",80);
      set("con",80);
      set("int",80);
     set("str" ,80);
       set("no_get",1);
    set("age", 999);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 25000000);
            set_temp("apply/attack", 100);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",100);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("spells",850);
     set_skill("magic-old",800);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "spells.magic1" :),
    (: perform_action, "spells.magic2" :),
    (: perform_action, "spells.magic3" :),
    (: perform_action, "spells.magic4" :),
    (: perform_action, "spells.magic5" :),
    (: perform_action, "spells.magic6" :),
    (: perform_action, "spells.magic7" :),

 }) );

   setup();



}

void init( )

{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        call_out("check",1);
        }
}



/*

void die()
{
        object ob, me, corpse;
object  me,obj;
        int maxpot;
        int exp,pot,score,i;
        string skill;
        object jla , jlb;
        ob = this_object();
     //   me = query_temp("last_damage_from");
             me = this_player();
        //     me=  this_object()->query_last_damage_from();
        if (!me) return;
        
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
       corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        
        
        
if (me->query("migong/lev15"))
{
if( !environment(me)->query("no_fight")&& random(4)==1)
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

if (!me->query("migong/lev15"))
{
me->set("migong/lev15",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第十五层!"NOR"。\n", users());
exp = 500000+random(25000);
pot = exp/2;
score = random(300)+1650;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
}

             message_vision("$N得到一件千年火龙甲。\n",me);
             command("rumor "+me->query("name")+"得到一件"HIR"千年火龙甲"NOR"。\n");
             jla=new("/d/migong/obj/jia3");
             jla->move(me);
             me->add("combat_exp",4000);
              message_vision("$N得到一颗千年火龙丹。\n",me);
             command("rumor "+me->query("name")+"得到一颗"HIR"千年火龙丹"NOR"。\n");
             jlb=new("/d/migong/obj/dan4");
             jlb->move(me);

       
        
        destruct(ob);
        return;
}

*/


void die()
{
        object ob, me, obj,corpse;
int maxpot;
string skill;
        object jla , jlb;
        int exp,pot,score,i;
        ob = this_object();
       
        me=  this_object()->query_last_damage_from();
        if (!me) return;
if (me->query("migong/lev15"))
{
if( !environment(me)->query("no_fight")&& random(4)==1)
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

if (!me->query("migong/lev15"))
{
me->set("migong/lev15",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第十五层!"NOR"。\n", users());
exp = 500000+random(25000);
pot = exp/2;
score = random(300)+1650;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
}

             message_vision("$N得到一件千年火龙甲。\n",me);
             command("rumor "+me->query("name")+"得到一件"HIR"千年火龙甲"NOR"。\n");
             jla=new("/d/migong/obj/jia3");
             jla->move(me);
             me->add("combat_exp",4000);
              message_vision("$N得到一颗千年火龙丹。\n",me);
             command("rumor "+me->query("name")+"得到一颗"HIR"千年火龙丹"NOR"。\n");
             jlb=new("/d/migong/obj/dan4");
             jlb->move(me);

       
        
     
               destruct(ob);
        return;
}



void check()
{
        object ob=this_object();
        object me=this_player();

     if (!ob)
     {
     remove_call_out("check");
     return;
     }

     if (!me)
     {
     remove_call_out("check");
     return;
     }


     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }

if (ob->is_busy() && ob->is_fighting())
{
        message_vision(HIW"$N"HIW"身上圣光一闪，又恢复了行动！\n",ob,me);
        ob->interrupt_me();
        ob->start_busy(2);
        ob->start_busy(2);
}
        remove_call_out("check");
        call_out("check",1+random(3));
}
int hit_ob(object me, object ob, int damage)
{
if (ob=me)
{
if (me->query("qi") < me->query("max_qi"))
{
me->add("qi",me->query("max_qi")/40);
me->add("eff_qi",me->query("max_qi")/40);
}
if (me->query("jing") < me->query("max_jing"))
{
me->add("jing",me->query("max_jing")/40);
me->add("eff_jing",me->query("max_jing")/40);
me->set("neili",me->query("max_neili"));
}
}
if (ob!=me)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
}
}
