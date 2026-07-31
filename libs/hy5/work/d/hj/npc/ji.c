// Jay 3/17/96
#include <ansi.h>;
inherit NPC;
string ask_ma();
string ask_li();
void create()
{
        set_name("计老人", ({ "ji laoren", "ji"}));
        set("gender", "男性");
        set("age", 83);
        set("long", "满头白发，竟无一根是黑的，身材甚是高大，
只是弓腰曲背，脸上全是皱纹，衰老已极。\n");
        set("attitude", "friendly");

        set("shen", 4800);
      set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 53900);
        set("max_qi", 53900);
        set("jing", 53900);
        set("max_jing", 53900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 9500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 550);

set_skill("huanhe-dao", 580);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 350);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 550);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 580);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 1600);
        set("inquiry", ([
            "马家骏" : (: ask_ma :),
            "李文秀" : (: ask_li :),
            "哈萨克人" : "哈萨克人最爱喝又香又烈的美酒。\n",
            "华辉" : "谁？我不知道这个人。\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/bishou")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
      if (clonep(this_object())) 
        carry_object("/d/hj/obj/rousisuo");
}

string ask_li()
{
    object me, ob, where;
    me=this_player();
    ob = find_living("li wenxiu");
    if (!ob) return "这孩子，不知道又跑哪去了，唉。。。\n";
    where = environment(ob);
       if (!where) return "这孩子，不知道又跑哪去了，唉。。。\n";
    return "哦，这孩子好象跑到"+where->query("short")+"玩去了。";        
}

string ask_ma()
{
	mapping fam; 
    object me, ob, where;
    me=this_player();
	
	if ((int)me->query("jinyong/book6") !=4 )
		return "你说的是谁，我听不明白？";

	me->set_temp("marks/killji", 1);
	this_object()->set("qi",this_object()->query("max_qi"));
	this_object()->set("jing",this_object()->query("max_jing"));
	this_object()->set("neili",this_object()->query("max_neili"));
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return "即然你识破了我，你就去死吧!";
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
if (!me) return;
              //me->add("score",1);        

who=me;        
       if(who->query("jinyong/book6")==4 && who->query_temp("marks/killji")) {
        message_vision(RED"$N喃喃说道，报应,报应.....浑身鲜血直流，倒了下去!\n"NOR,ob,me);
		i = 500+random(3000);
		who->set("jinyong/book6",5);
		who->add("combat_exp",i+20000);
		who->add("potential",i*15);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+20000)+"点经验"+
		           chinese_number(i*15)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了白马啸西风的所有任务!"NOR"\n", users());
		who->save();
        }




              ::die();
        return;
}