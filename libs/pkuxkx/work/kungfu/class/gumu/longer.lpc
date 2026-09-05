// longer.c 小龙女
#include <ansi.h>
#include <title.h>
#include "/d/gumu/bonus.h"
inherit NPC;
inherit F_AQUESTMASTER;
string ask_me();
string ask_exchange();
string ask3();
string ask2();
int ask_job();
string ask_qufeng();
void consider();
void heal();
int adv();
string ask_for_leave();

void create()
{
         set_name("小龙女", ({ "xiao longnu","xiao","long","longnu","longer"}));
        set("title",HIR "古墓派" NOR + MAG "传人" NOR);
        set("long",
                "她就是古墓派第三代传人小龙女，容颜极美，只是脸上稍带白色。\n"
                "她是神雕大侠杨过的妻子。\n");
        set("gender", "女性");
        set("age", 29);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 38);
        set("int", 42);
        set("con", 30);
        set("dex", 50);
        set("per", 50);
        set("hubo", 1);
        set("suxin", 1);
        set("max_qi", 14000);
        set("max_jing", 14000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 300);
        set("combat_exp", 12000000);
        set("score", 100000);
	      set("book_count", 1);
	      set("ping_count",3);
        set("chat_chance", 100);
        set("chat_msg", ({
	          (: heal :),
	      }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
   
	      set_skill("force", 280);
        set_skill("yunu-xinfa", 280);
	      set_skill("cuff", 280);
	      set_skill("meinu-quan", 280);
        set_skill("dodge", 300);
        set_skill("xianyun", 300);
        set_skill("parry", 280);
        set_skill("whip", 280);
        set_skill("changhen-bian", 300);
	      set_skill("throwing",280);
	      set_skill("qianmie-shou",280);
        set_skill("literate", 150);
        set_skill("qufengshu", 180);
	      set_skill("yunu-jianfa",280);
        set_skill("sword",300);

        map_skill("force", "yunu-xinfa");
	      map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
	      map_skill("sword","yunu-jianfa");
        map_skill("parry", "changhen-bian");
        map_skill("whip", "changhen-bian");
	      map_skill("throwing","qianmie-shou");

        prepare_skill("cuff", "meinu-quan");
		set_temp("apply/armor", 300);
		set_temp("apply/damage", 350);
	
        set("chat_chance", 100);
	      set("inquiry", ([
               "淑女剑" : (: ask_me :),
		           "机关"   : (: ask3 :),
		           "左右互搏": (: ask2 :),
		           "驱蜂术":(:ask_qufeng:),
                           "内功转换":(:ask_exchange:),
              "job"   : (: ask_job :),
              "任务" : (: ask_job :),
              "脱离门派" : (: ask_for_leave :), 
        ]) );
      
        create_family("古墓派" , 3, "传人");
        setup();
        carry_object("/d/gumu/npc/obj/lingsuo");
        carry_object("/clone/weapon/changjian");
        carry_object("/d/gumu/npc/obj/white")->wear();
        call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
	if (!environment()||base_name(environment())!="/d/gumu/dating")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="古墓派"&&ob[i]->query("combat_exp")<100000&&time()-ob[i]->query_temp("gm广告")>600)
        {
            ob[i]->set_temp("gm广告",time());
            command("tell "+ob[i]->query("id")+" 古墓新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}

int ask_job()
{
    object me=this_player();
    string * task=({"养蜂","捉麻雀","捉野兔"});
    int n,exp,pot,rep;
    string * skill=({"force","yunu-xinfa","cuff","meinu-quan","dodge","xianyun","parry","whip","changhen-bian","throwing","qianmie-shou","literate","qufengshu","yunu-jianfa","sword"});
    string sk;
    object duandi;
    if (me->query("family/family_name")!="古墓派")
    {
        command("say 阁下与我古墓素无渊源，何出此言呢？");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    
    if (me->query("combat_exp")<10000)
    {
        command("say 你且去寒玉床上睡睡吧，对内功修为有着一些好处。");
        return 1;
    }
    if (me->query("combat_exp")>120000)
    {
        command("say 剩下的古墓武功要以自行修炼为主了。");
        return 1;
    }
    if (me->query("gm_require_skill")&& ((int)me->query_skill("yunu-xinfa", 1) < 20||(int)me->query_skill("xianyun", 1) < 20))
    {
        command("say 我不是叫你去练练本门功夫吗？");
        return 1;
    }
    if (me->query_temp("gmnewbiejob/yetucount"))
    {
        exp=(int)me->query_temp("gmnewbiejob/yetucount")*((int)me->query("combat_exp")+30000)/3000;
        pot=10+random(exp);
        rep=1+random(pot);
		bonus(me,6,exp,pot,rep,"");
        me->delete_temp("gmnewbiejob/yetucount");
        me->delete_temp("gmnewbiejob/yetu");
        return 1;
    }
    if (me->query_temp("gmnewbiejob_yangfeng_finish"))
    {
        sk=skill[random(sizeof(skill))];
        command("say 玉蜂的蜂蜜已经采集好了？办得不错。");
        me->delete_temp("gmnewbiejob_yangfeng_finish");
        me->delete_temp("gmnewbiejob");
        me->set_skill(sk,me->query_skill(sk,1)+1);
        tell_object(me,HIC"小龙女指点了你一些武功上的难关。\n"NOR);
        return 1;
    }

    if (time()-me->query("gmnewbiejob/last_time")<180)
    {
        command("say 我略感不适，你稍后再来吧。");
        return 1;
    }
    me->set("gmnewbiejob/last_time",time());
    n=random(sizeof(task));
    if (n==0)
    {
        command("say 断龙石前的草地，特别适合养蜂，你去养蜂酿蜜吧。");
        tell_object(me,"到了那里，你先清理(qingli)出适合蜜蜂的一片所在，之后可以用吹(blow)短笛，引来蜜蜂，时机成熟后，可以提取(tiqu)蜂蜜完成任务。\n");
        me->set_temp("gmnewbiejob/yangfeng",1);
        me->set_temp("gmnewbiejob/yangfengtime",time());
        me->delete_temp("gmnewbiejob/yetu");
        if (!me->query("gm_qufengshu"))
        {
            duandi=new("/d/gumu/obj/duandi2");
            duandi->move(me);
            tell_object(me,"小龙女给你一只短笛。\n");
            me->set("gm_qufengshu",1);
            tell_object(me,this_object()->query("name")+"传授了你驱蜂之术。\n");
        }
        if (!present("duan di",me))
        {
            duandi=new("/d/gumu/obj/duandi");
            duandi->move(me);
            tell_object(me,"小龙女给你一只短笛。\n");
        }
        return 1;
    }
    if (n==1)
    {
        if ( (int)me->query_skill("yunu-xinfa", 1) < 20)
        {
            command("say 我派玉女心法，你学得那么差劲，还不快去补补？");
            me->set("gm_require_skill",1);
            return 1;
        }
        if ( (int)me->query_skill("xianyun", 1) < 20)
        {
            command("say 我派纤云步，你学得那么差劲，还不快去补补？");
            me->set("gm_require_skill",1);
            return 1;
        }
        command("say 我派武功以轻灵为主，你去墓外的草坪把麻雀都捉来(wang)给我，可不许弄伤了羽毛脚爪。");
        me->set_temp("gmnewbiejob/maque",1);
        me->set_temp("gmnewbiejob/maquetime",time());
        me->delete_temp("gmnewbiejob/yetu");
        return 1;
    }
    if (n==2)
    {
        command("say 我虽然不吃腥荤，但古墓派并不禁止门下弟子吃些肉食，这些日子你也苦了，断龙石前的草地有许多野兔。");
        command("say 一来你可以打打牙祭，而来捉(zhuo)它也可以练练轻功，不要轻易捕杀了。");
        me->set_temp("gmnewbiejob/yetu",1);
        me->set_temp("gmnewbiejob/yetutime",time());
        me->delete_temp("gmnewbiejob/yetuappear");
        me->delete_temp("gmnewbiejob/yetucount");
        return 1;
    }
}
void init()
{
        add_action("give_wsquest","quest");
	      add_action("do_leave",  "leave");
}

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("family/family_name") != "古墓派")
		return "你非我古墓派弟子，脱离门派的事情我作不得主。";

	me->set_temp("pending/leave_gumu", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我古墓派而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_gumu") != 1)
		return 0;
	message_vision("$N对$n说道：「从此你就不再是我古墓派门下了，请好自为之！」\n",this_object(), me );
	tell_object(me,HIR "你决定叛出古墓派门下！\n" NOR);
	me->delete_temp("pending/leave_gumu");
  me->expell_family("古墓派");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}	

void attempt_apprentice(object ob)
{
      	if((string)ob->query("family/family_name")!="古墓派")
      		{
      		 command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜小虹小玲。"); 
                      return;
              	}
         if((int)ob->query("betrayer")>0)
         {
         command("say 学武之人最忌背信弃义，你是判师之人，我怎么能够收你!\n");
         return;
          }
              if((int)ob->query("score")<1000)
      {
         command("say 你对我派的贡献还不够，我暂时不能够收你!\n");
         return;
      }
      	 if ((int)ob->query_skill("yunu-xinfa",1) < 50)
      		 {
      		 command("say " + RANK_D->query_respect(ob) + "玉女心法太低，再回去好好努力吧。"); 
                      return;
              	}
      	if (((int)ob->query("dex")+(int)ob->query_skill("dodge",1)/10)<20)
      		{
      		command("say" + "我古墓派的功夫以轻灵为主，" + RANK_D->query_respect(ob) + "似乎对轻功不太重视吧。");
              	return;
      		}
      	else
                {
              command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
              command("recruit "+ob->query("id"));
                 }
             
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	      { 
	      	if(ob->query("gender")=="女性")
		       	ob->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
        	else
        		ob->set("title",GRN "古墓派" NOR + MAG +"圣使" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
          return;
        }

}
void re_rank(object student)
{
	if(student->query("gender")=="女性")
   	student->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
  else
    student->set("title",GRN "古墓派" NOR + MAG +"圣使" NOR);
//title系统记录玩家title by seagate@pkuxkx
	student->set_title(TITLE_RANK, student->query("title"));	
  return;
}
string ask_qufeng()
{
	      object me=this_player();
	      object ob;
	      mapping fam;
      if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	      if (me->query("score")<1500)
	      	return "驱蜂术是本派秘籍，以你对本派的忠诚情况来看，目前还不能传给你。\n";
	      if((int)me->query_temp("qufengping")==1)
	        return "你已经拿了一瓶了，留点给别人吧。\n";
        if((int)me->query_skill("qufengshu",1)<80)
          return "你的驱蜂术太低了，要了也没法驱蜂啊。";
        if (query("ping_count") < 1)
                return "真是不巧，最后一瓶也给出去了。\n";
        add("ping_count", -1);
        ob = new("/d/gumu/obj/yufengping");
        ob->move(me);
	      me->set_temp("qufengping",1);
	      command("say 好吧，这个玉蜂瓶拿去用吧。\n");
	      command("whisper "+me->query("id")+" 使用的命令是：qufeng <sb.>。\n");
        return "好好利用，切记不可胡作非为，不然小心过儿惩罚你哦。\n";                
}
string ask_exchange()
{
        object me = this_player();
        object ob;
        mapping fam;
        int level = me->query_skill("jiuyin-shengong", 1);
        int level1 = me->query_skill("yunu-xinfa", 1);
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
                return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        if((int)me->query("gumu/exchange") == 1)
                return "你的内功已经转换过了。\n";
        if (me->query_skill("jiuyin-shengong", 1) < 200)
                return "你的九阴神功等级太低，没必要转换。\n";
       if (level < level1)
                return "你的玉女心法比九阴神功都高，要亏的。\n";
                
        me->set_skill("yunu-xinfa", level);
        me->set_skill("jiuyin-shengong", level1);
        me->set("gumu/exchange",1);
        command("say 好吧，我就帮你转换内功吧。\n");
        return "虽然男性使用略微差点，但是也是武林奇功。好好努力，扬我古墓之威风。\n";
}
string ask_me()
{
        mapping fam;
        object ob;
	      object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	      if((int)me->query_temp("sword1")==1)
	      return "你已经拿了一把宝剑了，还想要第二把呀";
        if((int)me->query_skill("yunu-jianfa",1)<80)
        return "你的玉女剑法太低，要了淑女剑也发挥不出它的威力。";
        if (query("book_count") < 1)
                return "你来晚了，本派的淑女剑不在此处。";
        add("book_count", -1);
        ob = new("/d/gumu/obj/sword1");
        ob->move(this_player());
	      me->set_temp("sword1",1);
        return "好吧，这把淑女剑你拿回去好好保管。";
}

string ask3()
{	
	      mapping fam;
	      object me=this_player();
	      if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                      return RANK_D->query_respect(this_player()) +
                      "与本派素无来往，不知此话从何谈起？";
	      if (me->query("score")<500)
	      	return "墓洞可是我古墓派的重地，不是一般人能进去的。\n";
	      else 
	      	{me->set("jiguan",1);
                      command("whisper "+me->query("id")+" 墓洞是我古墓派的重地，你可千万不要告诉别人啊。\n" );
                      command("whisper "+me->query("id")+" 从小石洞进去之后，路径是东西南南西，然后一只向东就到了。\n" );
                      command("look "+me->query("id"));
                      command("whisper "+me->query("id")+" 第5口棺材下面有个密道。" );
                      return "好吧，我已经把机关的秘密告诉你了，你好自为之。\n";
	      }
}
string ask2()
{
	      mapping fam;
	      object me=this_player();
	      if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                      return RANK_D->query_respect(this_player()) +
                      "与本派素无来往，不知此话从何谈起？";
	      else
	      {
	      message_vision("小龙女说道：“好吧，我就教你双手互搏吧。”\n",me);
	      if (me->query_skill("yunu-xinfa",1)<80)               
	      { message_vision("$N练了半天，还是没练会。”\n",me);
                     
	      return "也许是你玉女心法不够，静不下心来练吧。\n";}
        if (me->query("combat_exp")>500000)
	      {message_vision("$N练了半天，还是没练会。”\n",me);
	      return "也许是你经验太高，不习惯于左右互搏吧。\n";}
	      message_vision("$N练了半天，学会了左右互搏之技。\n",me);
	      me->set("hubo",1);
	      me->set("suxin",1);
	      return "记住，不要用我教你的来作恶，不然我决不轻饶。\n";
	      }
}	
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield jian");
            command("perform sword.suxin " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("wield lingsuo");
            command("perform whip.chan " +target->query("id"));
            command("unwield lingsuo");
             break;
        }
}
void heal()
{
        object ob=this_object();
        
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
        	command("exert heal");
        	command("enforce 100");
        	return;
        }
        
        if (ob->query("qi") < ob->query("eff_qi"))
        {
        	command("exert recover");
        	return;
        }
        
        if (ob->query("jing") < ob->query("eff_jing"))
        	command("exert regenerate");
        
        return;
}
	
#include "/kungfu/class/masterdie.h"