// jiao_zhong1.c
//write by dfbb@hero
//
#include <ansi.h>
inherit NPC;

#include <random_name.h>


void kailiu();

void create()
{
        string name,id,nick;

	name = get_rndname();
	id = get_rndid();
	nick = get_rndnick();
	
        set_name(name, ({ id, "jiaozhong" }) );
	set("gender", "男性");
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + YEL "黄衣" NOR + "教众");
        set("nickname", nick);

	set("age", 20);
	set("long",
		"这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 15000+random(15000));
        set("shen_type", -1);
	set("attitude", "heroism");
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(HIY "圣教主千秋万载，一统江湖!\n" NOR),
		(HIG "文成武德、泽被苍生圣教主万岁万万岁!\n" NOR),
        }) );


	set_skill("strike", 65);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("mo-shan-jue",70);
        map_skill("dodge","mo-shan-jue");   

        create_family("日月神教", 16, "教众");


	setup();
        
	if(strsrch(nick,"剑")!=-1)
	 {
          carry_object("/d/heimuya/obj/sword")->wield();
	  set_skill("sword",70);
	  set_skill("mo-jian-jue",70);
	  map_skill("sword","mo-jian-jue");
	  map_skill("parry","mo-jian-jue");   
	  
	 }	
        else if(strsrch(nick,"刀")!=-1)
	 {
          carry_object("/d/heimuya/obj/blade")->wield();
	  set_skill("blade",60);
          set_skill("mo-dao-jue",60);
          map_skill("blade","mo-dao-jue");
	  map_skill("parry","mo-dao-jue");
	 }
        else if(strsrch(nick,"钩")!=-1)
	 {
	  carry_object("/d/heimuya/obj/gou")->wield();
	set_skill("hook", 70);
          set_skill("mo-gou-jue",70);
	map_skill("hook", "mo-gou-jue");
	  map_skill("parry","mo-gou-jue");
         }
        else if(strsrch(nick,"戟")!=-1)
	 {
	  carry_object("/d/heimuya/obj/ji")->wield();
	set_skill("halberd", 70);
          set_skill("mo-ji-jue",70);
	map_skill("halberd", "mo-ji-jue");
	  map_skill("parry","mo-ji-jue");
         }
        else if(strsrch(nick,"锤")!=-1)
	 {
	 carry_object("/d/heimuya/obj/hammer")->wield();
	 set_skill("hammer",70);
         set_skill("mo-chui-jue",70);   
         map_skill("hammer","mo-chui-jue");
	 map_skill("parry","mo-chui-jue");
         }

        else if(strsrch(nick,"斧")!=-1)
	 {
	  carry_object("/d/heimuya/obj/axe")->wield();
          set_skill("axe",70);
          set_skill("mo-fu-jue",70);
          map_skill("axe","mo-fu-jue");
	  map_skill("parry","mo-fu-jue");
         }
        else if(strsrch(nick,"叉")!=-1)
	 {
         carry_object("/d/heimuya/obj/fork")->wield();
         set_skill("fork",70);
         set_skill("mo-cha-jue",70);   
         map_skill("fork","mo-cha-jue");
	 map_skill("parry","mo-cha-jue");
         }

        else if(strsrch(nick,"枪")!=-1)
	 {
	carry_object("/d/heimuya/obj/qiang")->wield();
	set_skill("spear", 70);
	set_skill("mo-qiang-jue", 70);
	map_skill("spear", "mo-qiang-jue");
	map_skill("parry", "mo-qiang-jue");
         }
        else if(strsrch(nick,"鞭")!=-1)
	 {
          carry_object("/d/heimuya/obj/whip")->wield();
	  set_skill("whip",70);
          set_skill("mo-bian-jue",70);
          map_skill("whip","mo-bian-jue");
	  map_skill("parry","mo-bian-jue");
         }
	else 
	 {
  	  set_skill("mo-zhang-jue",80);
	map_skill("strike", "mo-zhang-jue");
	prepare_skill("strike", "mo-zhang-jue");
	 }

        carry_object("/obj/cloth")->wear();
	add_money("silver", 10);
}

int accept_fight(object me)
{
        command("say 好小子, 居然敢同我们日月神教作对, 看招!");
        command("grin");
        kill_ob(me);
        return 1;
}

int accept_kill(object killer)
{
 	int i;
	object *ob,me;
	me=this_object();
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="日月神教") continue;
		if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
		write(ob[i]->query("name")+ "吼道:"+HIY 
                "好小子, 居然敢杀我们日月神教的人,死去吧你!\n" NOR);
        }
        return 1;
}



