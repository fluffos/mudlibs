// npc: /kungfu/class/btshan/ouyangfeng.c
// Jas 23/1/2003
//欧阳锋

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void heal();
int auto_perform();
int ask_shegu();

void create()
{
        set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
		   +"由于习练「九阴真经」走火入魔，已变得精\n"
		   +"神错乱，整日披头散发。\n");
        set("title", HIG"白驼山"NOR+HIB"庄主"NOR);
        set("nickname",HIR"西毒"NOR);
        set("gender", "男性");
        set("age", 53);

        set("attitude", "peaceful");
        set("shen_type", -1);
        set("shen", -1500000);


        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
        
        
        set("qi", 6000);
        set("max_qi", 6000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("max_jingli", 5000);
        set("jingli", 5000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 200);

        set("reverse", 1);

        set("combat_exp", 12000000);
        set("score", 200000);
        set_skill("force", 350);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("staff", 350);
        set_skill("hand",300);
        set_skill("strike",300);
        set_skill("literate",200);
        set_skill("training", 200);
 	    set_skill("poison", 300);
       
        set_skill("hamagong", 380);
	set_skill("tianshan-xinfa",150);
        set_skill("chanchu-bufa", 300);
        set_skill("lingshe-zhangfa", 380);
        set_skill("shexing-diaoshou", 300);
        set_skill("shentuo-zhang", 300);
        
        map_skill("force","hamagong");
        map_skill("dodge","chanchu-bufa");
        map_skill("staff","lingshe-zhangfa");
        map_skill("hand","shexing-diaoshou");
        map_skill("strike","hamagong");
        map_skill("parry","lingshe-zhangfa");
        
        prepare_skill("strike","hamagong");
       
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
			 (: auto_perform :),            
              }));

         
         create_family("白驼山",1, "开山祖师");
        set("chat_chance",100);
        set("chat_msg",({
	        (: heal :),
        }));
	set("inquiry", ([
		"西毒" : "既有了西毒这个名号，若非在这“毒”字功夫上稍有独得之秘，未免愧对诸贤。",
		"毒" : "既有了西毒这个名号，若非在这“毒”字功夫上稍有独得之秘，未免愧对诸贤。",
		"欧阳克" : "便是舍侄。",
//		"灵蛇" : (: ask_lingshe :),
		"蛇谷": (: ask_shegu :),
//		"化尸粉" : "那是我从前用的小玩意，现在克儿还用，老夫已经不屑一用了。",
	]));

        setup();
        carry_object("/d/baituo/obj/shezhang")->wield();
        carry_object("/d/baituo/obj/baipao")->wear();
         add_money("gold",8);

}
         
 void init()
{
	object ob, me;
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	
}
       
        

      void attempt_apprentice (object ob)
{ 
     int exp;      
     
   if((string)ob->query("family/family_name")!="白驼山")
   {
command("say " + RANK_D->query_respect(ob) + "若想入我白驼山，可先拜钱眼开。\n");  
   return;
    }
   if((int)ob->query("score")<1500)
   {
  command ("say 你自问是否对本门尽力了?");
   return;
   }
   if((int)ob->query("shen")>-100000)
   {
    command("say 你行事不够狠毒，若" + RANK_D->query_respect(ob) + "能多杀几个正派人士给我看看......\n");
   return;
      }
   if((int)ob->query_skill("hamagong",1)<120)
   {
     command("say " + RANK_D->query_respect(ob) + "还应在蛤蟆功上多下些功夫!\n");
    return;
    }
   if((int)ob->query("betrayer")>=2)
   {
   command("say 你多次判师，我怎么能够收你!\n");
   return;
    }
   if((int)ob->query("combat_exp")<100000)
    {
     command("say 你再练几年吧!");
     return;
    }
   
       command("say 好吧，我就收下你吧.\n");
       command("recruit " + ob->query("id"));
       
    
        exp = (int) ob->query("combat_exp");
         if (exp <=500000 && ob->query("age") <= 25) {
			if(ob->query("gender") == "女性")
			ob->set("title",HIG"白驼山"NOR+HIB"小魔女"NOR);
			else
			ob->set("title",HIG"白驼山"NOR+HIB"小毒物"NOR);
		} else {
			if(ob->query("gender") == "女性")
			ob->set("title",HIG"白驼山"NOR+HIB"魔女"NOR);
			else
			ob->set("title",HIG"白驼山"NOR+HIB"老毒物"NOR);
		}

}

void heal()                                             
{                                                       
	object ob=this_player();                        
	                                                
	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{                                               
		command("exert heal");                  
		command("enforce 200");                 
	}                                               
                                                        
	if (ob->query("qi") < ob->query("eff_qi"))      
 	command("exert recover");               
   
	if (ob->query("jing") < ob->query("eff_jing"))  
	command("exert regenerate");            

	return;       
}


int ask_shegu()
{
	object me, staff;
	int lv;
	me = this_player();

	if( me->query("family/family_name") != "白驼山" && me->query("combat_exp") > 100000) {
		command("sneer "+me->query("id"));
		command("say 白驼山蛇谷的秘密，岂能透露给外人知晓？"+RANK_D->query_rude(me)+"，你太多嘴了！");
		return 1;
	}

	if( me->query("baituo/shegu_permit") ) {
		command("say 蛇谷中的蛇儿，你可以随意捕捉。好好修炼毒技，莫要堕了西毒的威名！");
		return 1;
	}

	lv = (int)me->query_skill("poison", 1);

	if( lv < 80 ) {
		command("say 凭你这点使毒本事，想进蛇谷还早得很。乖乖的在庄里修炼！");
		return 1;
	}
	
	if( lv < 100 ) {
		command("pat "+me->query("id"));
		command("say 你的毒技是有点火候了，不过想进蛇谷，还得多下点功夫琢磨。");
		return 1;
	}

	command("nod "+me->query("id"));
	command("say 你用毒的能耐，似乎是进步多了。好，老夫就许你进蛇谷练练本领。");
	me->set("baituo/shegu_permit", 1);

	staff = new("/d/baituo/obj/shezhang");
	staff->move(me);

	message_vision("$N将一根"+staff->name()+"交给$n。\n",this_object(), me);
	command("say 从今以後，你可以自由进出蛇谷。用心从中钻研，你的毒技还可以更上层楼。");

	return 1;
}

void greeting(object me)
{
		if (me->query("enter_shegu")) {
		if ( environment(me) != environment(this_object())) return;

		me->delete("enter_shegu");

		if (me->query("family/family_name") != "白驼山") {
			command("hehe "+me->query("id"));
			command("say "+me->name()+RANK_D->query_rude(me)+"，竟敢擅闯蛇谷，我若不将你折磨得死不成活不了，岂不枉称“西毒”名号？");
			command("perform shoot "+me->query("id")); //for weapon
			kill_ob(me);
		}
		else if (me->query("family/family_name") == "白驼山" 
		&& !me->query("baituo/shegu_permit") ) {
			command("slap "+me->query("id"));
			command("say 谁叫你擅入蛇谷的？");
			message_vision(HIR"欧阳锋在$N的肩头重重按了一掌，蛤蟆功劲力直透腑脏，登时震得$N面如白纸，汗如雨下。\n"NOR, me);
			me->set("neili", 0);
			me->set("jingli", me->query("jingli")/10);
			me->set("qi", me->query("qi")/10);
			me->start_busy(3);
			command("say 这点惩罚，算是便宜你了。不许再有下次！");
		}
	}
	return;
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if( !me->query_temp("hmg_dzjm") )
		command("exert reverse");

	if ( !objectp(target) ) return 0;

	if (me->query("qi") < me->query("eff_qi"))      
 	command("exert recover"); 
 	if (me->query("jing") < me->query("eff_jing"))  
	command("exert regenerate");    

         switch( random(4) )
        {
            case 0:
            command("wield zhang");
            command("perform staff.saoluoye " + target->query("id"));
             break;
            case 1:
            command("unwield zhang");
            command("perform strike.puji " + target->query("id"));
            command("wield zhang");
            break;
            case 2:
            command("wield zhang");
            command("perform staff.shoot " +target->query("id"));
             break;
            case 3:
            command("unwield zhang");
            command("perform strike.puji " +target->query("id"));
            command("wield zhang");
             break;            
	 }

	return 1;
}
