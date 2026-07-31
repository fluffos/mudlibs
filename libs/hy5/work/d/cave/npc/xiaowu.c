#include <ansi.h>
inherit NPC;
int gao();
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
    set_name("小武", ({"xiao wu","wu"}) );
    set("gender", "男性" );
    set("nickname", HIC"随手剑"NOR);
    set("title", "青龙会 刺客");
    set("long", "小武看来仿佛是个很随便、很懒散的人，很喜欢笑，很喜欢酒。没有人能想象
到他杀人时的动作是多么迅速，多么准确。他若要刺瞎你的左眼，他的剑就绝
不会刺在你别的地方。\n");
        set("attitude", "friendly");
        set("age", 25);
        set("cor", 25);
        set("cps", 25);
        set("per", 25);
        set("combat_exp", 3000000);
        set("class","assassin");
        
        set_temp("apply/armor", 100);
        set("force", 2000);
        set("max_neili", 2000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 3);
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",80);
                        break;
                default: set("resistance/kee",30);
        }
                
        set_skill("sword", 200);
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");  
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
           "小武皱了皱眉，喃喃道：该怎生救出高立那鲁莽家伙呢？\n",
        }) );
        set("inquiry", ([
                "gaoli" : (: gao :),
                "gao" : (: gao :),
                "高立" : (: gao :),
                "gao li" : (: gao :),
        ]));
        set("jadebox", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/windsword")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(4)); 
} 
int gao(){
        object me;
   me = this_player();
        if(query("answering")){
                return notify_fail("小武似乎正在忙。\n");
        }
        if(me->query("combat_exp") < 1000000) {
                message_vision("$N打量了$n一番，皱了皱眉道：唉，没等你见到高立，早就一命呜呼了。。\n", 
                                this_object(), me);
        } else if (me->query_temp("marks/underground_gao")) {
                message_vision("$N咦了一声对$n道：我刚刚不是给了你雀翎玉盒吗？难道那个法子不管用？\n",
                                this_object(), me);
        } else {
                message_vision("$N撇了$n一眼，沉思了半晌，双眸突然放出光来：对了，就这样，这样
一定可以救高立和双双，一定可以。\n", this_object(), me);
                set("answering", 1);
                call_out("give_jadebox", 2, me);
        }
        return 1;
} 
void give_jadebox(object me){
        object box;
        if(!interactive(me) || environment(me) != environment(this_object())){
                return;
        }  
        message_vision("$N愉快地笑了笑：好，你就把这个雀翎玉盒交给高立。。嗯，告诉他孔雀翎 
。。就在里面，但孔雀翎存在的真正目的，不是杀人，而是救命，所以。。。 
不到万不得已时，绝不要用它。\n", this_object(), me);    
        me->set_temp("marks/underground_gao", 1);
        box = new(__DIR__"obj/jadebox");
        if(objectp(box)){
                box->move(me);
        }
        delete("answering");
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
   while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else  if (enemy[i]->is_busy()) 
                                        this_object()->smart_attack();
                          else {
                                command("enable sword lefthand-sword");
                                this_object()->perform_action("sword.duxin"); 
                                command("enable sword sharen-sword");
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    
