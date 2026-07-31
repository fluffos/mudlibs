#include <ansi.h>
inherit BOSS;
string *first_name = ({ "木", "树"});
string *first_id = ({ "mu", "shu"});
string *name_words = ({ "精灵", "怪"});
string *id_words = ({ "jingling", "guai"});
int combatpower();

void create()
{
        string name;
        int i,j,k,a,b,c,d,e,f,temp;
        
        i = random(sizeof(first_name));
        name = first_name[i];
        j = random(sizeof(name_words));
        name += name_words[j];

        set_name(name, ({ first_id[i]+" "+id_words[j] }) );
        // random_name_color(this_object());
        
        set("age", 20);
        set("vrm_guard", 1);
        set("attitude", "aggressive");

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);
        
        set("combat_exp", 35000000);
        set("level", 35);
        set("qi", 40000);
        set("max_qi", 40000);
        set("jing", 35000);
        set("max_jing", 35000);
        set("neili", 140000);
        set("max_neili", 140000);
        set("jiali", 1000);

        set_skill("unarmed", 3500); 
        set_skill("dodge", 3500); 
        set_skill("parry", 3500); 
        set_skill("force", 3500); 
	
set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
	
	if (random(18)==0)
{
set("nickname",HIY"武功高超"NOR);
        set_skill("spells",1000+random(1000));
        set_skill("force",1000+random(1000));
	set_skill("unarmed",1000+random(1000));
	set_skill("sword",1000+random(1000));
	set_skill("club",1000+random(1000));
	set_skill("whip",1000+random(1000));
	set_skill("throwing",1000+random(1000));
	set_skill("parry",1000+random(1000));
}
else
if (random(18)==0)
{
set("nickname",MAG"魔法强大"NOR);
      set_skill("magic-unarmed", 850+random(1300));
      set_skill("magic-sword", 850+random(1300));
      set_skill("magic-ice", 850+random(1200));
      set_skill("magic-water", 850+random(1200));
      set_skill("magic-fire", 850+random(1200));
      set_skill("magic-earth", 850+random(1200));
      set_skill("magic-light", 850+random(1200));
      set_skill("magic-dark", 850+random(1200));
}
else
if (random(18)==0)
{
set("nickname",HIB"经验丰富"NOR);
set("combat_exp",150000000+random(58000000));
}
else
if (random(18)==0)
{
set("nickname",HIR"强大不死"NOR);
set("dex",300);
        set("jing",900000);
        set("max_jing",900000);
        set("eff_jing",900000);
        set("qi",900000);
        set("max_qi",900000);
        set("eff_qi",900000);
        set("neili",900000);
        set("max_neili",900000);
}
else
if (random(18)==0)
{
set("nickname",HIC"超级加强"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(18)==0)
{
set("dex",300);
        set("jing",800000);
        set("max_jing",800000);
        set("eff_jing",800000);
        set("qi",800000);
        set("max_qi",800000);
        set("eff_qi",800000);
        set("neili",800000);
        set("max_neili",800000);
      set_skill("magic-unarmed", 850+random(800));
      set_skill("magic-sword", 850+random(800));
      set_skill("magic-ice", 850+random(800));
      set_skill("magic-water", 850+random(800));
      set_skill("magic-fire", 850+random(800));
      set_skill("magic-earth", 850+random(800));
      set_skill("magic-light", 850+random(800));
      set_skill("magic-dark", 850+random(800));
        set_skill("spells",850+random(800));
        set_skill("force",850+random(800));
	set_skill("unarmed",850+random(800));
	set_skill("sword",850+random(800));
	set_skill("club",850+random(800));
	set_skill("whip",850+random(800));
	set_skill("throwing",850+random(800));
	set_skill("parry",850+random(800));
set("nickname",HIC"完美无敌"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
	
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",100);  
		set("bonus", 600);
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   500,
                "TW&480"   :  380,
                "TA&480"   :  380,
        ]));

	set_weight(500000);
       setup();
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
}

void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
        
mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        
        damage = 700 + random(700);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIC "$N" HIC "“呼”的一声地上冒出许多木刺，登时令$n"
               HIC "浑身鲜血狂流。\n" NOR;
}



