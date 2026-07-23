#include <ansi.h>
inherit NPC;
//inherit F_UNIQUE;
int ask_go();
int ask_kiss();
int ask_home();
int ask_sm();
int ask_eat();

void create()
{
        set_name("小龙女", ({ "long er", "long","longer"}));
	set("nickname", HIM "风动梨花" NOR);
	set("long", HIC "\n她长得极美，尤其是那双眼睛，清纯得像一潭碧水。\n"+
	"其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
	"回眸嫣然一笑，雅如仙子下凡。眼波流转之间，\n"+
	"便把你的心灵，推向梦中极美的境界。\n" NOR);
        set("marry","caobin");
        set("gender", "女性");
 	set("age", 18);
        set("str", 50);
        set("cor", 50);
        set("baohu","caobin");
        set("cps", 50);
        set("int", 50);
        set("per", 100);
        set("agi",55);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dugulianjian" :),
                (: perform_action, "sword.yiji" :),
                (: perform_action, "sword.san" :),
//   	  (: command, "full" :),
        }) );

        set("combat_exp", 80000+random(800000));
        set("score", 9000);
        set("shen", 9000);

        set("max_qi",800+random(1190));
        set("max_jing",800+random(1190));
        set("max_sen",800+random(1190));
        set("max_neili",800+random(1190));
        set("neili",800+random(1190));
        set("max_mana",800+random(1190));
        set_skill("dodge",900);
        set_skill("parry", 100);
        set_skill("dodge", 900);
        set_skill("force", 88);
        set_skill("literate", 88);
	  set_skill("sword", 100);
        set_skill("unarmed",88);
         set_skill("hubo", 120); 
        set_skill("meinv-quan", 160);    
        set_skill("dugu-steps",400);
        set_skill("dugu-force",200);
        set_skill("dugu-jian",150);
        set_skill("dugu-steps",400);
        map_skill("dodge", "dugu-steps");
	map_skill("sword", "dugu-jian");
	map_skill("force", "dugu-force");
	map_skill("parry", "dugu-jian");
	map_skill("unarmed", "meinv-quan");
        set("chat_chance", 20);
        set("chat_msg", ({
		(: command, "follcao master cao" :),
        }) );
        set("force",18888);
        set("max_force",18888);
        set("force_factor",30);
	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
       set("inquiry", ([
            "你愿不愿意跟我走" : (: ask_go :),
            "亲热" :  (: ask_kiss :),
            "回家" :  (: ask_home :),
            "惩罚" :  (: ask_sm :),
            "吃饭" :  (: ask_eat :),
	]));
	setup();
        carry_object("/cao/long/baiyi");
        carry_object("/cao/obj/roommaker");
        carry_object("/cao/long/sword")->wield();
        carry_object("/cao/long/cloth")->wear();
        carry_object("/cao/long/jindai")->wear();
        add_money("gold", 50);

}

int init()
{
 object ob;
ob = this_player();
::init();
if (userp(ob))
if(random(10)>5)
      add_action("do_att","att");
       add_action("do_ting","ting");
       add_action("do_send","sendto");
       add_action("do_sha","sha");
       add_action("do_sex","sex");
remove_call_out("greeting");
call_out("greeting", 1, ob);
}

void smiling (object who)
{
  if (random(2))
    command("smile");
  else
    command("smile "+who->query("id"));
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
message_vision(	"$N对$n嫣然一笑.\n\n",this_object(),ob );
if(ob->query("id")=="caobin")
{
	  command("say噢，"+ob->query("name")+"主人回来了。");
}
else
{
command("say 这位" + RANK_D->query_respect(ob)
+ "，你是从哪来的?你好吗？\n");
if (ob->query("gender") == "男性"||ob->query("gender") == "无性")
{
       message_vision(
	HIM "$N一见到小龙女，不由得心中砰的一跳，胸口宛如被一个\n"+
	"无形的铁锤重重击了一下，霎那间唇干舌燥，目瞪口呆，\n"+
	"心道：我死了，我死了！世间那来这样的美女?\n"+
	"倘若她再对我笑一笑，我就算死了也心甘啊!...\n" NOR,ob,this_object());
 	command("xixi");
 	command("follow caobin");
}
else
{
       message_vision(
	HIM "$N一见小龙女，不由得心中砰的一跳，胸口宛如被一个\n"+
	"无形的铁锤重重击了一下，霎那间唇干舌燥，目瞪口呆，\n"+
	"心道：我死了，我死了！世间那来这样的美女?\n"+
	"倘若我也是男子，她要我为她去死，我也决不皱一皱眉...\n" NOR,ob,this_object());
	command("say 总是有男子来惹我恼我，不想今日却来了一位" + RANK_D->query_respect(ob)+"\n");
 	command("follow caobin");
}
}
}

int ask_kiss()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
	   if(random(10)>1)	          
           {
	   say(query("name")+"满脸羞得通红,垂下头来,缓缓的点了点头.\n");
           command("lovelook "+ me->query("id") );
           command("cat "+ me->query("id") );
           command("kiss "+ me->query("id") );
           write(CYN"你对小龙女微微一笑，流露出无限的喜爱之情。\n"NOR);
           write(CYN"小龙女回眸嫣然一笑，雅如仙子下凡。其容色晶莹如玉。\n"NOR);
           me->add("force",10000);
           me->add("qi",10000);
           me->add("jing",10000);
           me->add("sen",10000);
           me->add("combat_exp",2000);
           }		
           else 
	   say(query("name")+"啊的一声,一下子跳将开去,说:不嘛,不要.\n");
	   return 1;
           }
	}
say(query("name")+"说道:呸,我不干.");
return 1;
}

int ask_go()
{
  object me;
  string new_name,new_id,host_id;
   me=this_player();
	   if(query("id")!="long er")
        {
		 sscanf(query("id"),"%s's long er",host_id);
		 if(query("id")==host_id)
           {say(query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说:当然愿意啦,我都听你的。\n");
            return 1;
           }
	 if(me->query("id")!=host_id)
           {say(query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说:不行的,我得听我主人的。\n");
			return 1;
           }
	 }
      	if((int) me->query_skill("dugu-jian",1) > 300)
      //  if ((int)this_player()->query_skill("dugu-jian")>300)
	   {
           write( HIY "小龙女道:主人待我恩重如山,主人对我家又有大恩。\n" NOR);
           write( HIY "要我服侍主人,我一定尽心。\n" NOR);
	   command("nod");
           set_leader(me);
       new_name = me->query("name")+"的丫环小龙女";
       new_id=me->query("id")+"'s long er";
       set("name",new_name);
       set("id",new_id);
	   write( "可用指令:\aatt sb 攻击某人.\nsha sb 杀死某人.\nting 停止战斗.\nsendto sb.--把小龙女送给sb.\n");
                  set("long","这是"+new_name+"。\n"
       "她长得极美，尤其是那双眼睛，清纯得像一潭碧水。\n"
	"其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"
	"回眸嫣然一笑，雅如仙子下凡。眼波流转之间，\n"
	"便把你的心灵，推向梦中极美的境界。\n"
	"小龙女笑靥如花,正笑嘻嘻地看着你。\n");
       }
	   else say(query("name")+"睁大眼睛看着"+
				me->query("name")+"，说:不行的,主人没有同意。\n");
return 1;
}

int ask_home()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
	   if(random(10)>3)	          
           {
	message("vision",
		 name() + "说道：主人如再要我服待，请发哨为警！我等你啊！\n\n"
		+ name() + "闪了闪就消失不见了。\n" , environment(),
		this_object() );
//        if(objectp(owner=this_object()->query("possessed")))
		me->add_temp("max_guard",-1);
	destruct(this_object());
           }		
           else 
	   say(query("name")+"啊的一声,轻声细语的说:求求"+me->query("name")+"主人,不要.我不要回家\n");
	   return 1;
           }
	}
say(query("name")+"说道:你是谁？我又不认识你，就不听你的！");
return 1;
}
int ask_sm()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
	   if(random(30)>2)	          
           {
           command("shiver");
           say(query("name")+"啊的一声,颤抖的说:求求你,"+me->query("name")+"主人你打我，骂我都可以，但不要那样！\n");
 	   return 1;
           }		
           else 
       write( CYN "你邪恶地笑了笑，然后从怀中拿出一条绳子和一此其它很XX的东西..... \n"NOR);
       command("shiver");
       write( CYN "你粗暴地脱下了小龙女的衣裙。把她绑了起来"+"\n" NOR);
       write( CYN "你拿出鞭子和一此其它的东西。然后与小龙女...XXX了起来。"+"\n" NOR);       
       write( CYN "............................."+"\n" NOR);
       write( CYN "......................."+"\n" NOR);
       write( CYN "...................."+"\n" NOR);
       write( CYN "................."+"\n" NOR);
       write( CYN ".............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN ".........."+"\n" NOR);
       write( CYN "........"+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "你一觉醒来。只见小龙女两眼发呆的望着天空，一声也不坑。"+"\n" NOR);
     	   if(random(10)>3)	          
           {
command("say 我的命真苦。。。\n");
command("say "+me->query("name")+"主人以后我不能继续再服待你了。。。\n");
command("say 大家珍重。。。\n");
command("say 珍重。。。\n");
message_vision("$N说罢，拿起剑自刎而死，她缓缓的到在地上。。。\n",this_object());
	set("long", HIC "\n她长得极美，尤其是那双眼睛，清纯得像一潭碧水。\n"+
	"其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
	"她因自刎而死,不过她死了还是那么的美。\n" NOR);
this_object()->die();
           return 1;
           }		
             write( CYN "小龙女很可怜对你说：“求求你，放开我吧。” \n"NOR);
        set("name","被绑起来的小龙女");
             return 1;
           }
	}
say(query("name")+"大声喊道:来人哪！这有个变态！！");
command("kill "+ me->query("id") );
kill_ob(me);
me->fight(this_object());
return 1;
}

int ask_eat() 
{
object me;
object wo;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
me = this_player();
message_vision("$N拿出了一些做饭材料，升起了火，为主人$n做起饭来．．．\n",this_object(),me);
       write( CYN ".................."+"\n" NOR);
       write( CYN "..............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN "........."+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "."+"\n" NOR);
       write( CYN "小龙女把做完的饭装在几个盘子里给了你"+"\n" NOR);
       write( CYN "小龙女从怀中拿出几个冷馒头，站在你旁边吃了起来。"+"\n" NOR);
            set ("food",170);
            set ("water",170);
            switch( random(22) ) {
		case 0:
	wo = new(__DIR__"obj/s0");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
		case 1:
	wo = new(__DIR__"obj/s1");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
		case 2:
	wo = new(__DIR__"obj/s2");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
		case 3:
	wo = new(__DIR__"obj/s3");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 4:
	wo = new(__DIR__"obj/s4");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 5:
	wo = new(__DIR__"obj/s5");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 6:
	wo = new(__DIR__"obj/s6");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 7:
	wo = new(__DIR__"obj/s7");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 8:
	wo = new(__DIR__"obj/s8");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 9:
	wo = new(__DIR__"obj/s9");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 10:
	wo = new(__DIR__"obj/s10");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 11:
	wo = new(__DIR__"obj/s11");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 12:
	wo = new(__DIR__"obj/s12");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 13:
	wo = new(__DIR__"obj/s13");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 14:
	wo = new(__DIR__"obj/s14");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 15:
	wo = new(__DIR__"obj/s15");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 16:
	wo = new(__DIR__"obj/s16");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 17:
	wo = new(__DIR__"obj/s17");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 18:
	wo = new(__DIR__"obj/s18");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 19:
	wo = new(__DIR__"obj/s19");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 20:
	wo = new(__DIR__"obj/s20");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 21:
	wo = new(__DIR__"obj/s21");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
}
           }
	}
say(query("name")+"我恁什么为你做饭，你又不是我主人！！");
command("kick "+ me->query("id") );
return 1;
}

int do_att(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
  if(query("id")=="long er")
   {say("你无权使用此命令。\n");
    return 0;}
  sscanf(query("id"),"%s's long er",host_id);
  if(me->query("id")!=host_id)
  return notify_fail("小龙女连理都不理你！\n");
  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("小龙女傻傻地望着你，不明白你的意思。\n");
  if(!living(ob)) 
	 return notify_fail("小龙女说:"
              +ob->query("name")+"已经这样啦你还要...??!!\n");
  message_vision("小龙女对主人$N点头道: 嗯,好的.\n",me);
  fight_ob(ob);
  return 1;
}

int do_ting()
{
   string host_id;
  object me=this_player();
  if(query("id")=="long er")
   return notify_fail("你无权使用此命令。\n");
  sscanf(query("id"),"%s's long er",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("小龙女连理都不理你！\n");
 if(!is_fighting())
	 return notify_fail("小龙女现在没和人打斗.\n");
 message_vision("小龙女对主人$N微微一笑，跳出了战圈。\n",me);
 command("halong");
 return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
  if(query("id")=="long er")
   return notify_fail("你无权使用此命令。\n");
  sscanf(query("id"),"%s's long er",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("小龙女连理都不理你！\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要把小龙女送给谁？\n");
  if(!living(ob)) 
	 return notify_fail("你只能把小龙女给活人!\n");
 message_vision("小龙女眼泪汪汪地望着主人$N，说:\n主人待我好,是我命好;主人待我不好,是我命苦罢了.\n",me);
 set_leader(ob);
 new_name = ob->query("name")+"的丫环小龙女";
	   set("long","这是"+new_name+"。\n"
		"她是一个清纯绝俗的少女,大约十八,九岁年纪;\n"
	            "她长得极美，尤其是那双眼睛，清纯得像一潭碧水。\n"+
	            "其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
		"一张雪白的脸庞,眉弯嘴小,却象是刚受人欺负,眼泪汪汪地看着你。\n");
 new_id=ob->query("id")+"'s long er";
 set("name",new_name);
 set("id",new_id);
 write( HIY "小龙女对新主人"+ob->query("name")+"楚楚可怜地盈盈一拜。\n" NOR);
 message_vision("可用指令:\att sb 攻击某人.\nsha sb 杀死某人.\nting 停止战斗.\nsendto sb.--把小龙女送给sb.\n",me);
 return 1;
}

int do_sha(string arg)
{
        int i ;
	object me,ob;
	object* obj;
	me = this_object();
        if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要小龙女杀谁？\n");
	if(!environment(ob)->query("no_fight"))
	{
        message_vision("小龙女对$N点头说道: 嗯,好的.\n",me);
	command("say 哼,主人要我杀了你!");
	remove_call_out("kill_ob");
  	call_out("kill_ob", 1, ob); 
	}
	return 1;
}       

int do_sex(string arg)
{
       string host_id;
       object me=this_player();
       if(query("id")=="long er")
       return notify_fail("你无权使用此命令。\n");
       sscanf(query("id"),"%s's long er",host_id);
           if(me->query("id")!=host_id)
          return notify_fail("小龙女想要杀死你这个流氓！\n");
       command("shiver");
       command("say 已经这样啦"+me->query("name")+"主人你还要...??!!");
       command("remove cloth");
       write( CYN "小龙女缓缓地一件件地脱下了衣服..... \n"NOR);
       write( CYN "小龙女脸上露出悲哀的脸色。"+"\n" NOR);
       write( CYN "小龙女慢慢的抱住了你。然后与你...XXX了起来。"+"\n" NOR);       
       write( CYN "......................."+"\n" NOR);
       write( CYN "...................."+"\n" NOR);
       write( CYN "................."+"\n" NOR);
       write( CYN ".............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN ".........."+"\n" NOR);
       write( CYN "........"+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "你一觉醒来。只见小龙女眼泪汪汪地望着你。一声也不坑。"+"\n" NOR);
       write( CYN "小龙女缓缓地穿上了衣服。但见她脸上泪痕依旧。 \n"NOR);
       command("wake");
       command("wear cloth");
       me->add("force",10000);
       me->add("qi",10000);
       me->add("jing",10000);
       me->add("sen",10000);
       return 1;
}
