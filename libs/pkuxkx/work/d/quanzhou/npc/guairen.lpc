// oyf.c 欧阳锋

#include <ansi.h>

inherit NPC;
void heal();
int auto_perform();

void create()
{
       set_name("怪人", ({ "guai ren", "ren", "man" }) );
       set("gender", "男性" );
       set("shen_type", -1);
       set("age", 70);
       set("str", 35);
       set("con", 30);
       set("int", 30);
       set("dex", 30);

       set("no_clean_up",1);

       set("long",
"一位用头支在地上，双脚并拢，撑向天空的怪人。
看上去疯疯癫癫的。但见他高鼻深目，满脸雪白短
须，根根似铁，又听他喃喃自语，说著叽哩咕噜的
怪话，极是难听。也许可以求他解除身上的寒毒。\n" );

       set("combat_exp", 18000000);
       set("attitude", "heroism");

       set("max_qi", 5000);
       set("max_jing", 4000);
       set("neili", 10000);
       set("max_neili", 5500);
       set("max_jingli", 4000);
       set("jingli", 4000);
       set("jiali", 150);
       set("reverse", 1);

       set_skill("force", 350); 
       set_skill("hamagong", 380); 
       set_skill("literate", 200);
       set_skill("poison", 300);
       set_skill("dodge", 300);
       set_skill("parry", 300);
       set_skill("hand", 300);
       set_skill("training", 300);
       set_skill("strike", 300);
       set_skill("chanchu-bufa", 300);
       set_skill("staff", 350);
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
                (: auto_perform :)
              }));

        set("chat_chance",100);
        set("chat_msg",({
	        (: heal :),
	}));

       set("inquiry", ([
                "欧阳锋" : "欧阳锋、欧阳锋，听起来这名字挺熟的。。。\n",
                "洪七公" : "洪七公，这名字也熟。\n",
                "蛤蟆功" : "蛤蟆、蛤蟆、蛤蟆。。。\n",
                  "救命" : "你给我磕头我才会救你。\n",
                  "驱毒" : "你给我磕头我才会救你。\n",
                  "解毒" : "你给我磕头我才会救你。\n",
                  "name" : "我…我是谁？我知道我是谁就好啦。\n",

       ]));

       setup();       
       
       carry_object("/clone/weapon/gangzhang");
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 10);
}


void init()
{
        object me = this_player();
        ::init();        
        
      if(me->query_temp("oyf_see")){
          command("look " + me->query("id"));
          command("hehe");
          command("say 你越是东奔西跑，身上的毒越是发作得快。");
          me->delete_temp("oyf_see");
          me->set_temp("oyf_see1", 1);
          call_out("do_wait", 360, me);
        }     
         add_action("do_kneel","kneel");
         add_action("do_kneel","ketou");
         add_action("do_turn","turn");
         add_action("do_jiao","jiao");
}

int do_kneel(string arg)
{
     object me, oyf;
     int number;
     me = this_player();
     oyf = this_object();         
     number = me->query_temp("oyf_kneel");


      if(!me->query_temp("oyf_see1")) return 0;
      if( !arg ) return notify_fail ("你要向谁磕头？\n");
      if(arg == "guai ren" || 
         arg == "ren" || 
         arg == "man") 
      { 
        if(me->query("oyf_son")) return notify_fail("儿啊，你的蛤蟆功近来练得如何？\n");
        if(!number) {
             me->set_temp("oyf_kneel", 1);   
             message_vision(CYN"\n$n猛然福至心灵，向$N双膝跪倒，叫道：「求老公公救我性命。」\n"NOR,oyf,me);  
             me->set_temp("oyf_kneel", 1);   
/*
             if ((string)me->query("gender") == "女性") { 
                command("hmm " + me->query("id"));
                command("say 好吧，我就帮你解了这毒。");
                message_vision("只见$N翻过身来，捏住$n手臂推拿几下，已经将$n中的冰魄神针毒解了。\n",oyf,me);
                me->apply_condition("bing_poison", 0);
                me->delete_temp("oyf_see1"); 
                call_out("do_back", 1, me);
                return 1;
                }
*/
//              else {
                message_vision("怪人摇了摇头道：「难救，难救！」\n",me);          
                return 1;
//                }
           }
        if (number == 1) {
                message_vision(CYN"\n$n跪在地上对$N道：「你本事这麽大，定能救我。」\n"NOR,oyf,me);  
                message_vision("$N甚是高兴，微微一笑，道：「你怎知我本事大？」\n",oyf); 
                me->add_temp("oyf_kneel", 1);                
                return 1;
           }
        if (number > 1) {
                message_vision(CYN"\n$n忙对$N道：「你倒转了身子还跑得这麽快，天下再没第二个及得上你。」\n"NOR,oyf,me);  
                message_vision("$N哈哈大笑，声震林梢，叫道：「娃娃倒(turn)过身来，让我瞧瞧。」\n",oyf); 
                me->delete_temp("oyf_kneel");
                me->delete_temp("oyf_see1");  
                me->set_temp("oyf_see2", 1);             
                return 1;
           }
      }
}
int do_turn()
{
      object me, oyf;
      me = this_player();
      oyf = this_object();         
     
      if(!me->query_temp("oyf_see2")) return 0;

      tell_object(me, HIC "你心想不错，自己直立而他倒竖，确是瞧不清楚，
他即不愿顺立，只有自己倒立了。\n" NOR );      
      message_vision("$n当下倒转身子，将头顶在地下，用右手牢牢的在旁撑住。
向$N求道：「好公公，你救救我。」\n",oyf,me);     
      me->delete_temp("oyf_see2");  
      me->set_temp("oyf_see3", 1);  
      if( me->query("age") <= 18 ){
         me->set_temp("oyf_see3", 1);  
         call_out("oyf_ask", 4, me);                 
         return 1;
         }
      else {      
      call_out("oyf_cure", 4, me);   
      return 1;
      }
      return 1; 
}

void oyf_ask()
{
      object me, oyf;
      me = this_player();
      oyf = this_object();    

        message_vision("$N斜眼瞧向$n，脸有喜色，显得极是满意。\n",oyf,me);
        command("say 好，救你不难，但你须得答应我一件事。");
        command("say 我要收你为义儿。不许叫我公公，要叫(jiao)爸爸。");
        call_out("do_wait", 320, me);       
}

void do_wait()
{
        object me = this_player();
        if(!me->query_temp("oyf_son") && present(me)){
        command("hmm");
        call_out("do_back", 0, me);       
        }
}

int do_jiao(string arg)
{      
       object me, oyf;
       me = this_player();
       oyf = this_object();    

       if(!me->query_temp("oyf_see3")) return 0;
       if(me->query_temp("oyf_see3")){
          if( !arg ) return 0;
          me->set_temp("oyf_say", 1); 
          if(me->query_temp("oyf_say") >=3 ){
             me->delete_temp("oyf_say");
             me->delete_temp("oyf_see3");    
             call_out("do_wait", 0, me);   
             return 1;
             }    
          if(arg == "爸爸"){ 
             message_vision(HIC"$N心中一动，真情流露，一声“爸爸，爸爸”冲口而出！\n"NOR, me );
             remove_call_out("do_wait");
             me->set_temp("oyf_say", 1);
             me->set("oyf_son", 1);
             remove_call_out("do_cure");
             call_out("do_cure", 4, me);   
             return 1;              
             }
          else {             
             command("hmm");
             command("say 快叫爸爸。");
             me->add_temp("oyf_say", 1);       
             return 1;
             }
           return 1;
       }
}

void do_cure()
{
      object me, oyf;
      me = this_player();
      oyf = this_object();    
      if(environment(me)){
       
        command("haha");
        command("say 乖儿子，来，我给你除去身上的毒气。");
        message_vision(CYN"\n只见$N翻过身来，捏住$n手臂推拿几下，已经将$n中的冰魄银针毒解了。\n"NOR,oyf,me);
        me->apply_condition("bing_poison", 0);

	 if (me->query("family/family_name") == "白驼山")
        {
        command("say 好啦！毒已经解了，为父再把生平最得意的武功《蛤蟆功》也传给你。");
        tell_object(me, HIC "\n怪人开始给你讲解蛤蟆功的入门功夫。。。\n" NOR );      
        me->delete_temp("oyf_see3");   
        call_out("do_teach", 5, oyf);
        return;
        }
        me->delete_temp("oyf_see3");   
        call_out("do_back", 5, oyf);   
        return;
        
      }      
}

void do_teach()
{
      object me, oyf;
      int i,lvl=1;
	mapping skills;
	string *sk;
      me = this_player();
      oyf = this_object();    

	if (me->query("oyfquest/teach"))
		return;
	me->set("oyfquest/teach",1);      
      if(me->query("con") < 20){
        command("say 本可以传你为父的得意武功《蛤蟆功》，怎奈你不是个练武的材料。");
        command("sigh");
        command("say 只有帮你提高提高你现有的武功了。"); 
        skills = me->query_skills();
        if (sizeof(skills)>0)
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]]+=lvl;
	    }
//	me->add("combat_exp",me->query("combat_exp")/(50-lvl)+lvl);
//	me->add("shen", me->query("shen")/(10-lvl));
//     me->set("potential", i);

      tell_object(me, "你的功夫提高了！\n");             
      call_out("do_back", 15, me);           
        return;
        }     
      else{ 
        tell_object(me, HIC "\n怪人开始给你讲解蛤蟆功的经脉逆转。。。\n" NOR );              
        me->set("reverse", 1);  
        me->add("con",1);
        me->set_skill("hamagong", 9+me->query_skill("hamagong",1));        
        skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]]+=lvl;
	    }
//	me->add("combat_exp",me->query("combat_exp")/(50-lvl)+lvl);
//	me->add("shen", me->query("shen")/(10-lvl));
       tell_object(me, "你学会了蛤蟆功的经脉逆转!\n");     	

       tell_object(me, "你的功夫提高了！\n你的根骨增加了!你的经验增加了2000点！\n");  
      me->add("combat_exp", 2000);
       call_out("do_back", 15, me);    
        }
               
}

void oyf_cure()
{
      object me, oyf;
      me = this_player();
      oyf = this_object();    
      if(environment(me)){
       
        command("hmm");
        command("say 看起来你这娃娃还不赖，我就帮你解了毒吧。");
        message_vision(CYN"\n只见$N翻过身来，捏住$n手臂推拿几下，已经将$n中的冰魄银针毒解了。\n"NOR,oyf,me);
        me->apply_condition("bing_poison", 0);
        me->set("oyf_son", 1);
        
        command("say 好啦！毒已经解了。");        
       
        call_out("do_back", 5, oyf);       
        return;
        
      }      
}

void do_back()
{     
      object me;
      me = this_player();    
      message_vision(HIY"\n 空中忽然几声雕唳，两头大雕在半空飞掠而过。\n\n"NOR,me);
      call_out("do_leave", 5, me);             
}

void do_leave()
{
      object me, oyf;
      me = this_player();
      oyf = this_object();    
      if(environment(me)){   
      	if (me->query("oyfquest/leave"))
      		return;
      	me->set("oyfquest/leave",1);
      message_vision("$N两眼呆望，以手击额，皱眉苦苦思索，突然间似乎想起了甚麽，登时脸色大变。\n",oyf);
      command("whisper " + me->query("id") + " 我好象记得一个叫“白驼山”的地方，但、但。。。");
      if(me->query("oyf_son"))
         command("whisper " + me->query("id") + " 好象是个大戈壁，往西五百里骑白骆驼过去。");     
      command("pat " + me->query("id"));
      message_vision("接着$N一步跨了出去。这一步迈得好大，待得第二步跨出，人已在
丈许之外，连跨得十来步，身子早在桑树林後没了。\n",oyf);   
      tell_object(me, "你被奖励了一万点经验点！\n");
       me->add("combat_exp", 10000); 
      me->add("max_neili", 100);  
      tell_object(me, "你的内力增加了！\n");  
      me->delete("oyf_fail");       
      destruct(oyf);      
      }
}

void heal()                                             
{                                                       
	object ob=this_player();                        
	                                                
	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{                                               
		command("exert heal");                  
		command("enforce 150");                 
		return;                                 
	}                                               
                                                        
	if (ob->query("qi") < ob->query("eff_qi"))      
	{                                               
		command("exert recover");               
		return;                                 
	}                                               
                                                        
	if (ob->query("jing") < ob->query("eff_jing"))  
	{	command("exert regenerate");            
                                                        
               return;
               }    
       
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if( !me->query_temp("hmg_dzjm") )
		command("exert reverse");

	if ( !objectp(target) ) return 0;

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "staff" && random(3) == 1)
			return perform_action("staff.saoluoye");
		else return perform_action("staff.shoot");

	}
	if (random(2) == 1 ) 
       return perform_action("strike.puji");
}
