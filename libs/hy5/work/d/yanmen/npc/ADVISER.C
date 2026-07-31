#pragma save_binary
// shiao.c

inherit NPC;

void create()
{
	set_name("赫造基", ({ "adviser" }));
	set("title","军师");
	set("gender", "男性");
	set("age", 44);
	set("long",
        	"道光满面，智不言而现，气象万千，显然是茅山术高手中的高\n"
        	"手，经纶羽扇，和大将军正是绝配。\n");

	set("attitude", "peaceful");

	set("str", 20);
	set("int", 30);

	set("combat_exp", 1300000);
        
        set("inquiry", ([
        	"兵器库" : "先看看你的诚意再说罗。\n",
        ]) );
        
      
	
	set("neili", 22600);
	set("max_neili", 22600);
	set("force_factor", 5);
        
        set("atman", 600);
        set("max_atman", 600);
        
        set("mana", 2000);
        set("max_mana", 1200);
	set("mana_factor", 5);
	set("max_qi",10000);
	set("max_jing",10000);
        set_skill("literate", 160);
        set_skill("magic", 160);
        set_skill("force", 325);
        set_skill("spells", 180);
        set_skill("unarmed", 230);
        set_skill("sword", 240);
        set_skill("parry", 235);
        set_skill("dodge", 240);
        
        set_skill("taoism", 260);
        set_skill("necromancy", 270);

        
        map_skill("magic", "taoism");
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        
        set_temp("apply/dodge",115);
        set_temp("apply/armor",115);
         
	setup();

	carry_object(__DIR__"obj/fan_sword")->wield();
	carry_object(__DIR__"obj/hat")->wear();
}

int accept_object(object who,object ob)
{
        if ( !ob->value() ) {
        	command("say 谢了!!");
                command("grin");
              //  call_out( (: destruct :), 1, ob);
                return 1;
	}
                                                                                                                                                                
	if( !who->query_temp("军营/swear") ) {
		if( ob->value() >= 800 ) {
            	   command("say 好极了，我就告诉你一项秘密吧。");
            	   command("say 在那片光滑的山壁前发誓(swear) 我爱.....。");
                   command("say 或许\你可以发现奇特的事喔。");
                   who->set_temp("军营/swear", 1);
		   return 1;
		} else {
		   command("say 钱太少了吧！没收。");
		   return 1;
		}
	} else 
		command("say 即然你那么有心，那我就勉强收起来了。");
	
	return 1;
}
