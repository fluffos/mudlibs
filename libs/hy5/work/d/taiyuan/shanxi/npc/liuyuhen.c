 //by xiaolang
// 青衣楼杀手 
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("柳余恨", ({ "liu yuhen" }) );
        set("gender", "男性" );
        set("title",HIG"玉面郎君"NOR);
        set("nickname",WHT"多情自古空余恨，往事如洲不堪提"NOR);
        set("age", 27);
        set("class","swordsuper");
        set("libie/离别钩_尾声",1);
        set("str", 60);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这张脸左面已被人削去了一半，伤口现在已干瘪收缩把他的鼻子
和眼睛都歪歪斜斜的扯了过来，不是一个鼻子，是半个，也不是一
双眼睛，是一只。他的右眼已只剩下了一个又黑又深的洞，额角被
人用刀锋划了个大“十”字，双手也被齐腕砍断了，现在右腕上装着
个寒光闪闪的铁钩。
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 40000000); 
        set("chat_chance", 1);
        set("chat_msg", ({
"柳余恨黯然神伤：“多情自古空余恨，往事如洲不堪提，现在‘玉面郎君’\n早已死了，只可恨柳余恨还活着，十年前柳余恨也就巳想死了，\n无奈偏偏直到现在还活着，我此来但求一死而已。”"
        }) );  
        set("neili",5000);
        set("max_qi",50000);
        set("max_jing",30000);
        set("max_jing",30000);
        set("qi",50000);
        set("jing",30000);
        set("jing",30000);
    set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        setup();
        carry_object(__DIR__"obj/hook")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message("vision",
                HIW + name() + "叹了叹气，一闪身消失的无影无踪。\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}  
void init()
{
    object ob;
    ::init();
    set_temp("libieforce_libie",1);
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
} 
void greeting(object ob)
{   
        string where, location;
        if( !interactive(ob) || environment(ob) != environment() )
                return;
   if (!ob->query_temp("青衣楼/lou1a") ){
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}    
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("青衣楼/lou1a",1);
        ::die();
}  
