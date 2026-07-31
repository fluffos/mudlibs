#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
//	npc=data[random(sizeof(data))];
   set_name(order[random(13)]+"星  月"NOR, ({ "lywin"}));
set("magicgift",1+random(6));
       set("title",HIW"光之创造神"NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
	set("magicset",1);
       set("long",
"这个世界的创造神之一。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",185000000+random(8000000));
        set_skill("force",1690+random(300));
	set_skill("unarmed",1690+random(300));
	set_skill("sword",1690+random(300));
	set_skill("club",1690+random(300));
	set_skill("force",1690+random(300));
	set_skill("whip",1690+random(300));
	set_skill("throwing",1690+random(300));
	set_skill("parry",1690+random(300));
      set_skill("magic-dark", 690+random(300));
      set_skill("magic-light", 690+random(300));
      set_skill("magic-earth", 690+random(300));
      set_skill("magic-ice", 690+random(300));
      set_skill("magic-water", 690+random(300));
      set_skill("magic-fire", 690+random(300));
      set_skill("magic-unarmedboss", 690+random(300));
      set_skill("magic-swordboss", 690+random(300));
      map_skill("sword", "magic-swordboss");
      map_skill("unarmed", "magic-unarmedboss");
      map_skill("parry", "magic-unarmedboss");
      set_skill("jiuyin-zhengong", 1680+random(300));
      set_skill("jiuyin-shenfa", 1680+random(200));
      set_skill("dafumo-quan", 1680+random(300));
      set_skill("jiuyin-shenzhang", 1680+random(300));
      set_skill("jiuyin-shenzhua", 1680+random(300));
      set_skill("xuanyin-jian", 1680+random(300));
      set_skill("yinlong-bian", 1680+random(300));
      set_skill("xuanyin-jian", 1680+random(300));
      map_skill("dodge", "jiuyin-shenfa");
      map_skill("force", "jiuyin-zhengong");
      map_skill("strike", "cuixin-zhang");
      map_skill("claw", "jiuyin-shenzhua");
        set("no_get",1);
b=800900+random(186000);
a=800900+random(185000);
d=200+random(60);
set("str",d);
set("dex",130+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

set("shen",-100000);
        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",1600);
if (random(2)==0)
{
     map_skill("spells", "magic-light");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
               (: perform_action, "spells.cure lightangel" :),
               (: perform_action, "spells.delete" :),
               (: perform_action, "spells.holyword" :),
               (: perform_action, "spells.moonlight lightangel" :),
               (: perform_action, "spells.sunbolt" :),
               (: perform_action, "spells.sunfield" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.sunarrow" :),                                                            
	(: command("use huoqiang") :),
        }) );
}
else 
{
     map_skill("spells", "magic-ice");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
               (: perform_action, "spells.invisibility" :),
               (: perform_action, "spells.lightningball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.implosion" :),
               (: perform_action, "spells.lightningbolt" :),
               (: perform_action, "spells.stun" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.holylightning" :),                                                            
	(: command("use huoqiang") :),
        }) );
        }
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/box/new2/36");	
	carry_object("/clone/box/new2/35");		
	carry_object("/clone/box/new2/34");		
	carry_object("/clone/box/new2/36");	
	carry_object("/clone/box/new2/35");		
	carry_object("/clone/box/new2/34");		
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
        call_out("hunting",0);
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
        call_out("check",0);
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
me->set("title",HIW"光之守护神"NOR);
              me->add("score",1000);
        message_vision(HIB"$N,化为了无数的光芒，消失在空中。\n"NOR,ob,me);
message("vision", me->name() + HIG"在最终任务中!!打败了"+ob->query("title")+HIG":"+ob->query("name")+HIG"("+ob->query("id")+HIG")。\n"NOR, users());
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
        ob->start_busy(1);
        ob->start_busy(0);
ob->set_temp("apply/intelligence", 200);
ob->set_temp("apply/strength",200);
ob->set_temp("apply/dexerity",200);
ob->set_temp("apply/constitution",200);
ob->set_temp("apply/karey", 200);
ob->set_temp("apply/percao", 200);	
ob->set_temp("apply/armor", 1000);
ob->set_temp("apply/defense", 200);
ob->set_temp("apply/attack", 200);
ob->set_temp("apply/damage", 1000);     
	if((int)ob->query("qi") < (int)ob->query("max_qi")/10)
        {
        ob->add("qi",ob->query("max_qi")/12);
        ob->add("eff_qi",ob->query("max_qi")/12);
        }
ob->clear_condition();
}

        remove_call_out("check");
        call_out("check",1+random(3));
}