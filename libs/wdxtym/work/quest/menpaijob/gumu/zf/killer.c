#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"黑衣"
});

    
string *nm2_jp =({
"女子",
});

void create()
{
       object me;
   int i = random(sizeof(nm1_jp));
      me=this_player();
set_name(HIB "黑衣女子" NOR, ({ me->query("id")+"-heiyi"}));
    set("gender", "女性" );//性别与上面对应
        set("long",
"一个道姑装扮的女子。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
set("dex",100);
  set("max_qi",500+random(1890));
  set("max_jing",500+random(1890));
  set("max_sen",500+random(1890));
  set("max_neili",500+random(1890));
  set("max_mana",500+random(1890));
  set("eff_neili",500+random(2000));
  set("neili",500+random(2000));
        set("per", random(26)+10);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(900000));
	set("bellicosity", 10000);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
                (: perform_action, "whip.sanwu" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
(: random_move :),
	}) );


        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        
        set_skill("xue-dao", 150+random(180));
        set_skill("unarmed",150+random(180));
        set_skill("xianglong-zhang",150+random(180));
        set_skill("dodge", 150+random(180));
        set_skill("blade", 150+random(180));
        set_skill("parry", 150+random(180));
        set_skill("dashou-yin", 150+random(180));
        set_skill("shenkong-xing", 150+random(180));
        set_skill("longxiang", 150+random(180));
        set_skill("huntian-qigong", 150+random(180));
        set_skill("whip", 150+random(180));
        set_skill("chilian-shenzhang", 150+random(180));
        set_skill("jueqing-bian", 150+random(180));
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("unarmed","xianglong-zhang");
        map_skill("strike","chilian-shenzhang");
        map_skill("whip","jueqing-bian");
        prepare_skill("strike", "chilian-shenzhang");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 100);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

        carry_object("clone/misc/cloth")->wear();
        carry_object("clone/weapon/changbian")->wield();
}
void init( )
{
        call_out("hunting",300);
}

void hunting()
{
object ob=this_object();
command("say 地形已经查看完了，可以向师父交待了!");
destruct(ob);
}


void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (!me) return;
        message_vision(WHT"$N惨叫一声，倒地而亡！。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if(me->query("family/family_name") == "古墓派" )   {
        message("vision", me->name() + HIG"由于成功的保卫了古墓派,增加了200修为和130潜能。\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",130);
        me->delete_temp("gumukill");
        }

        destruct(ob);
        return;
}
