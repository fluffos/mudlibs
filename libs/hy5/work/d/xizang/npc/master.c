 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 

int leave(); 
void create()
{
        set_name("桑结", ({ "sang jie", "master","sangjie" }) );
        set("gender", "男性" );
        set("class","lama");
        set("age", 99);
        set("int", 30);
        set("agi",25);
        set("int",30);
        set("fle",50);
        set("apprentice_available", 20);
        create_family("大昭寺", 20, "主持");
    set("rank_nogen",1);
    set("ranks",({"弟子","罗汉","高僧","大师","圣僧",YEL"法王"NOR,YEL"活佛"NOR,HIY"主持"NOR}));
        set("long",
                "桑结高僧已在大昭寺主持多年。男女弟子遍布关外。\n"
                );
        set("inquiry", ([
                "舍利子": "嗯....舍利子.....在舍利塔里。\n",
                "普松": "普松在大昭寺的木屋里。",

        ]) );
        set("combat_exp", 3000000+random(1500000));
        set("score", random(90000));
        set("reward_npc", 1);
        set("difficulty", 30);
        set("qi",80000);
        set("max_qi",80000); 
        set("max_neili",86000);
        set("neili",86000);
        set("max_jing",66000);
        set("max_neili",66000);

        set("force_factor",30); 
        set_skill("unarmed", 600);
        set_skill("dodge", 600);
		set_skill("move", 600);
        set_skill("staff", 600);
        set_skill("force", 680);
        set_skill("parry", 650);
        set_skill("literate", 640);
        set_skill("iron-cloth", 630);
        set_skill("bloodystrike", 650);
        set_skill("lamaism", 600);
        set_skill("jin-gang", 600);
        set_skill("spells",600);

        
        
        map_skill("unarmed", "bloodystrike");
        map_skill("iron-cloth", "jin-gang");
        
        set_temp("apply/iron-cloth",200); 
/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.fefawubian" :),
                (: cast_spell, "an" :),
        }) ); */
        
	set_skill("iron-cloth", 650);
set_skill("longxiang", 580);
	set_skill("bloodystrike", 600);
	set_skill("cloudstaff", 600);
	set_skill("bolomiduo", 600);
	set_skill("buddhism", 600);
        set_skill("jin-gang", 650);
        set_skill("yujiamu-quan", 580);
        set_skill("dashou-yin", 580);
        set_skill("magic", 580);
        set_skill("kwan-yin-spells", 580);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
	map_skill("unarmed", "bloodystrike");
         map_skill("force", "longxiang");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");        
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),     
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 5500);
        set_temp("apply/damage", 5600);                
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}  


void unconcious()
{
    die();
}
void die()
{
                int i;
        object ob, me, corpse,who;
        
        ob = this_object();

        me = query_temp("last_damage_from");
who=me;
if (!me) return;
              //me->add("score",1);        
message_vision(RED"$N一声怒吼，我的天下一统大业，浑身鲜血直流，倒了下去!\n"NOR,ob,me);

if (!me->query_temp("book772"))
message_vision(RED"$N说道，罗莎大军会帮我报仇的!\n"NOR,ob,me);        

if (!me->query_temp("book771"))
message_vision(RED"$N说道，罗莎大军会帮我报仇的!\n"NOR,ob,me);        

if(who->query("jinyong/book7")==6 && who->query_temp("book772") && who->query_temp("book771")) 
{
        message_vision(RED"$N喃喃说道，佛祖啊 报应,报应.....浑身鲜血直流，倒了下去!\n"NOR,ob,me);
		i = 500+random(3000);
		who->set("jinyong/book7",7);
		who->add("combat_exp",i+20000);
		who->add("potential",i*25);
		who->add("mpgx",20);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+20000)+"点经验"+
		           chinese_number(i*25)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");

		who->save();
        }
        me->set_temp("killsx5",1);


               ::die();
        return;
}