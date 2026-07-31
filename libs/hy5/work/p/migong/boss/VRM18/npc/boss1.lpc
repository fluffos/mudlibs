#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""YEL"", ""HIW"", ""YEL"",""YEL"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"葛羅姆"NOR, ({ "gnome"}));
if (random(2)==0)
	set("magicgift",3);
else 	set("magicgift",4);
	set("magicset",1);
       set("title",YEL"大地之力量使"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的大地之力量使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",39000000+random(8000000));
        set_skill("force",1150+random(300));
	set_skill("unarmed",1150+random(300));
	set_skill("sword",1150+random(300));
	set_skill("club",1150+random(300));
	set_skill("whip",1150+random(300));
	set_skill("throwing",1150+random(300));
	set_skill("parry",1150+random(300));
set_skill("spells",1100+random(300));
      set_skill("magic-unarmed", 1100+random(300));
      set_skill("magic-sword", 1100+random(200));
      set_skill("magic-earth", 1160+random(200));
      set_skill("magic-water", 1100+random(300));
      set_skill("magic-ice", 1100+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-earth");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
	set_skill("force",1150+random(300));
	set_skill("force",1150+random(300));
	set_skill("huntian-qigong",1150+random(300));
	map_skill("force", "huntian-qigong");	
b=3898000+random(968000);
a=3898000+random(968000);
d=98+random(60);
set("str",d);
set("dex",80+d);
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

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",5600);
	set_temp("apply/damage",5600);


        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.stab" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.Attach" :),
               (: perform_action, "spells.missile" :),
               (: perform_action, "spells.quake" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.Dintfield" :),                                                            
                (: big_blowing :),
        }) );
        
        set("bonus", random(100000)+9000);
	set("killer_reward", ([
                "/clone/magic/obj/sword13"   :   1500,
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&5"   :   8000,
                "BL&5"   :  8000,
                "RI&60"   :   5000,
                "GE&6"   :  5000,
                "JD&7"   :  5000,
                "YC&4"   :  5000,
                "WG&4"   :  5000,
                "KS&7"   :  2500,
                "BL&8"   :  2500,
                "YW&5"   :  2500,
                "YA&5"   :  2500,
                "TW&480"   :  2000,
                "TA&480"   :  2000,
"TZ&0"   :  1500,
	]));        
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
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
        }
}




int big_blowing()
{
        message_vision(YEL "$N" YEL "从大地中召唤了土地的力量，附近的大地冒出了各种毒气，"
                       "整个大地充满了毒气！！\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", 3);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIY "$N" HIY "打出一道惨绿的毒焰．．．．．．昏天黑地！！！\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 20000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 10;
                        //inv[i]->start_busy(2);
                        inv[i]->apply_condition("tmzhuihun_poison", 60);
                        inv[i]->apply_condition("chanchu_poison", 60);
                        inv[i]->apply_condition("xiezi_poison", 60);
                        inv[i]->apply_condition("wugong_poison", 60);
                        inv[i]->apply_condition("snake_poison", 60);
                        inv[i]->apply_condition("zhizhu_poison", 60);
                        inv[i]->apply_condition("tmpili_poison", 60);
                        inv[i]->apply_condition("zm_poison", 60);
                        inv[i]->apply_condition("tmqidu_poison", 1);
                        inv[i]->receive_wound("qi", dam/2);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}
