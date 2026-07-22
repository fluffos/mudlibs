#include <ansi.h>
inherit NPC;

string *list=({"yg-jjf","yg-jjf2","yg-jjf3","yg-hyd",
                "yg-fangcun","yg-hell","yg-jjf4","yg-dragon1",
                "yg-dragon2","yg-moon","yg-xueshan1","yg-dragon3","yg-pansi",
                "yg-putuo","yg-shushan","yg-wdd",
	});
void create()
{
    set_name(HIW "元始天尊" NOR, ({"yuanshi tianzun", "tianzun", "yuanshi"}));
    set("title", HIC "阐教掌教" NOR);
    set("long", "一位苍颜鹤发道人,身上霞光万道，瑞彩千条，光婵灿烂，映目射眼\n");
    
    set("gender", "男性");
    set("age", 13500);
    set("str", 40);
    set("per", 40);
    set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 10000);
    set("eff_sen", 10000);
    set("max_kee", 10000);
    set("max_sen", 10000);
    set("sen", 10000);
    set("kee", 10000);
    set("max_force", 10000);
    set("max_mana", 10000);
    set("mana", 10000);
    set("force", 20000);
    set("force_factor",  500);
    set("mana_factor", 500);
    set_skill("dao", 321 );
    set_skill("zhenyuan-force", 301);
    set_skill("spells", 321);
    set_skill("force", 301);
    set_skill("moonshentong", 301);
    set_skill("whip", 301);
    set_skill("staff", 301);
    set_skill("blade", 301);
    set_skill("spear", 301);
    set_skill("hammer", 301);
    set_skill("buddhism", 301);
    set_skill("taiyi", 301);
    set_skill("lotusforce", 301);
    set_skill("wuxiangforce", 301);
    set_skill("moonforce", 301);
    set_skill("stick", 301);
    set_skill("dodge", 301);
    set_skill("unarmed", 301);
    set_skill("parry", 301);
    set_skill("sword", 251);
    map_skill("force", "wuxiangforce");
    map_skill("spells", "dao");
    create_family("方寸山三星洞", 1, "祖师");
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "dingshen" :),
        (: cast_spell, "fenshen" :),
(: exert_function, "jldl" :)
}));
      setup();
 carry_object("/d/quest/obj/pao")->wear();  
}

int accept_fight(object me)
{
        write("休得无礼？\n");
        return 0;
}

int recognize_apprentice(object me)
{
      object ob = this_player();
      
        if (!(int)ob->query_temp("mark/仙"))
             return notify_fail( HIR "看起来" HIW "元始天尊" HIR "想杀死你！\n"NOR);
        if( ( ob->query("family/family_name") != "方寸山三星洞"
            && ob->query("family/family_name") != "南海普陀山"
            && ob->query("family/family_name") != "月宫"
            && ob->query("family/family_name") != "将军府"
            && me->query("family/family_name") != "东海龙宫" 
            && ob->query("family/family_name") != "盘丝洞"
            && ob->query("family/family_name") != "蜀山剑派"
            && ob->query("family/family_name") != "五庄观")
            || ob->query("combat_exp")  < 2000000 ) 
             return notify_fail( HIR "看起来" HIW "元始天尊" HIR "想杀死你！\n"NOR);

             ob->add_temp("mark/仙", -1);
               return 1;
}

void init ()
{
  add_action("do_task", "task");
  add_action("do_cancel", "cancel");
}

int do_task()
{
	object me = this_player();
        object guai,obj;
        int level,i,t,lv;
        
        string kind,where,msg;
        
       
         if( ( me->query("family/family_name") != "方寸山三星洞"
            && me->query("family/family_name") != "南海普陀山"
            && me->query("family/family_name") != "将军府"
            && me->query("family/family_name") != "月宫"
             && me->query("family/family_name") != "盘丝洞"
            && me->query("family/family_name") != "东海龙宫" 
            && me->query("family/family_name") != "蜀山剑派"
            && me->query("family/family_name") != "五庄观"))
             
       {
          message_vision(CYN"\n元始天尊道：你不是我阐教门人,速速离开。\n"NOR,me);
	  return 1;
	}
        

        me->command("say 敢问掌教，招弟子前来何事？");
        
        if(me->query("combat_exp")  < 3000000 )
         {message_vision(CYN"\n元始天尊叹了口气说：你虽有心，但修炼不够，去也枉然。\n"NOR,me);
              return 1;
             }
        if ((int)me->query("obstacle/number")<34)
             {message_vision(CYN"\n元始天尊道：你尚未历经劫难，得成正果，还是先下山修炼去吧。\n"NOR,me);
              return 1;
             }
        if( me->query("xian/get") )
             {message_vision(CYN"\n元始天尊说道：我不是已经给了任务你吗，快快起程。\n"NOR,me);
              return 1;
             }
        
        t=(int)me->query("xian/start_time");  

        if( me->query("xian/fail"))
        { 
           
           if(objectp(obj = me->query("xian/guai"))) destruct (obj);
          
           if(t<=time() && time()<t+360) {
		message_vision(CYN"$N沉思片刻说:"+
			"：这位"+RANK_D->query_respect(me)
			+"你自身修行不够,还是不妨先去自行修炼。\n"NOR,
			this_object(), me);
		        return 1;
	    }
	    me->delete("xian/fail");
	 }else{
	   if(t<=time() && time()<t+120) {
	   message_vision(CYN"$N用赞许的目光看着你，说"+
			"：这位"+RANK_D->query_respect(me)
			+",妖魔已除尽,不妨先去歇息。\n"NOR,
			this_object(), me);
		return 1;
	    }
	 }
	   
          
       
             
        //确定任务等级
       lv = random(10);
       
       if(lv<=6) level = 3 ;  
       if(lv<=4) level = 2 ; 
       if(lv<=2) level = 1 ;
       if(lv ==7) level = 4 ;
       if(lv ==8) level = 4 ;
       if(lv ==9) level = 5 ;
       
        //确定任务种类
        i = random(4);
        if (i==0) kind="杀";
        else if (i==1) kind="擒";
        else if (i==2) kind="降";
        else kind="劝";
        
        me->set("xian/get",1);
        me->set("xian/level",level);
        me->set("xian/kind",kind);
        guai = new("/d/quest/guai/"+list[random(sizeof(list))]);
        where=guai->invocation(me, level);
        guai->set("escape_time",uptime());
        switch (kind)
          {
          	case "杀": {message_vision(CYN"\n元始天尊说道：现有一精怪"+where+"附近为害，此怪
已经残杀了不少无辜，恶贯满盈了，你这就去把它除掉吧。\n"NOR,me); break;}
          	case "擒": {message_vision(CYN"\n元始天尊说道：现有一妖怪"+where+"附近出没，此怪尚未为大恶
，但极难点化，你这就去把它生擒回来，以免堕入魔道。\n"NOR,me); break;}
          	case "降": {message_vision(CYN"\n元始天尊说道：现有一截教门徒"+where+"附近出没，好勇斗狠，
看在通天师弟面上,你只需狠狠教训它一回，使它不敢为恶了即可。\n"NOR,me); break;}
		case "劝": message_vision(CYN"\n元始天尊说道：现有一个"+where+"附近出没，此
怪本性不坏，只是未能冲破迷津，你这就去点化它吧。\n"NOR,me);
          }
        me->set("xian/guai",guai);
        me->set("xian/where",where);
        me->set("xian/start_time",time());
        msg = me->name()+"接到一个难度"+chinese_number(level)+"的"+kind+"妖任务。";
        MONITOR_D->report_system_msg (msg);
        return 1;
}        


int do_cancel()
{
	object me = this_player();
       object obj;
	if (!me->query("xian/get"))
	     {tell_object(me,"你没有任务在身。\n"); return 1;}
	    
	me->command("say 这个任务弟子恐怕无能为力。");
	message_vision(CYN"\n元始天尊说道：你让我失望了，我亲自下山一趟，你好好修行去吧。\n"NOR,me);
	me->set("xian/fail",1);
        me->delete("xian/get",1);
    if(objectp(obj = me->query("xian/guai"))) destruct (obj);
	return 1;
}	
