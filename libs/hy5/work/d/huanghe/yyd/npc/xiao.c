// xiao.c 萧半和
// zly 99.6.11

#include <ansi.h>

inherit NPC;
int ask_me();
void create()
{
        set_name("萧半和", ({"xiao banhe", "banhe", "xiao"}));
        set("gender", "男性");
        set("title", HIY"晋阳大侠"NOR);
        set("shen_type", 1);
        set("age", 50);
        set("long", 
"这便是天下知名的晋阳大侠萧半和，他躯体雄伟，满腮虬须，长袍
马褂，极是威武。\n"
        );
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

       set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        set("chat_chance", 3);
        set("chat_msg", ({
            "萧半和冷哼一声，说道：“你们这些狗腿子别想拿到鸳鸯刀。”\n",
            "萧半和叹了一口气，说道：“我这个女儿呀，真是调皮，不知道这一次能不能改改。”\n", 
        }) );

        set("inquiry", ([
        "鸳鸯刀" : (: ask_me :),
        "萧中慧" : "那是我的乖女儿。她现在正在练功呢，说完，呵呵地笑了起来。\n",
        "袁冠男" : "那是我的乖女婿。说完，露出慈祥的笑容。\n",
        "太岳四侠" : "他们现在帮忙守着后山呢，你有什么事情吗？\n",
        ]));

        setup();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",2);
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  if(((int)who->query("jinyong/book14")!=4))
	{
		message_vision("$N对$n说道： 鸳鸯刀藏着天大的秘密！\n",this_object(),who);
		return 1;	
	}
	  	if(!who->query_temp("book145"))
	{
		message_vision("$N对$n说道： 你先去找袁冠男吧！\n",this_object(),who);
		return 1;	
	}

	if ( !objectp(present("yuanyang dao", who)) )
{
		message_vision("$N对$n说道： 你有鸳鸯宝刀吗！\n",this_object(),who);
		return 1;

}	

	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 鸳鸯刀的秘密就是仁者无敌。\n",this_object(),who);

	
	i = 500+random(2800);
	who->set("jinyong/book14",5);
	who->add("combat_exp",i+16880);
	who->add("potential",i*28);
	who->add("mpgx",20);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+16880)+"点经验"+
	           chinese_number(i*28)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");
message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了鸳鸯刀的所有任务!"NOR"\n", users());

	who->save();
	call_out("destroying", 0);                       
	return 1;
}