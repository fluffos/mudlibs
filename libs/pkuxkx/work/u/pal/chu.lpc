// Made by goodtaste
// pk master

#include <ansi.h>
#include <net/dns.h>
inherit F_DEALER;
inherit NPC;
int ask_pk();
void heal();
int auto_perform();

void create()
{
        seteuid(getuid());
        set_name("楚云飞", ({"chu yunfei" , "chu" ,"master"}));
        set("long",
                "杀手帮开山掌门，江湖人称黑蛟邪客。为人深沉阴险，心狠手辣\n"
               );
        set("title",HIR"纵横不败"NOR);
        set("count",20);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 38);
        set("shen_type", -1);
        set("str", 30);
        set("int", 25);
        set("con", 28);
        set("dex", 25);
        set("qi",4000);
        set("max_qi", 4000);
  		set("jing",4000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("max_jingli", 2500);
        set("jingli", 2500);
        set("jiali", 200);
		set("shaqi",450);
		set("kar",40);

        set("combat_exp", 10000000+random(500000));
        set("chat_chance",10);
        set("chat_msg",({
	        (: heal :),
             "楚云飞说道：无风雨不成江湖，没有我们，嘿嘿\n",
            }));
 
        set_skill("force", 500);
        set_skill("chuforce",500);
        set_skill("dodge", 500);
        set_skill("liuyun",500);//待写
        set_skill("parry", 500);
        set_skill("sword", 500);
        set_skill("guihun-jian", 500);//待写
        map_skill("force", "chuforce");
        map_skill("dodge", "liuyun");
        map_skill("parry", "guihun-jian");
        map_skill("sword", "guihun-jian");
        create_family("杀手帮",1,"掌门");
           set("inquiry",([
              "pk" : ( : ask_pk : ),
              "PK" : ( : ask_pk : ),
              "杀手" : ( : ask_pk : ),
                ]));
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_perform :),
	            }) );
        set("chat_chance",100);

        setup();
        carry_object(__DIR__"obj/guihun_sword")->wield();
        carry_object(__DIR__"obj/pifeng")->wear();
}
void heal()                                             
{                                                       
	object ob=this_player();                        
	                                                
	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{                                               
		command("exert heal");                  
		command("enforce 200");                 
		return;                                 
	}                                               
                                                        
	if (ob->query("qi") < ob->query("eff_qi"))      
	{                                               
		command("exert recover");               
		return;                                 
	}                                               
                                                        
	if (ob->query("jing") < ob->query("eff_jing"))  
	{	
		command("exert regenerate");            
              return;
               }    
       
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if ( !objectp(target) ) return 0;

	if (me->query("eff_qi") < me->query("max_qi"))      
 	command("exert heal"); 
	if (me->query("qi") < me->query("eff_qi"))      
 	command("exert recover"); 
 	if (me->query("jing") < me->query("eff_jing"))  
	command("exert regenerate");    
             

       if ( random(3) == 1)
           {
           	command("perform sword.wuyong " + target->query("id"));
           }

	return 1;
}

int ask_pk()
{ 
  object *death;
  mapping target;
  mixed *targetid;
  int i,j;
  int my_exp,his_exp,sub_exp;
  
  string my_id,his_id;
  object me=this_player();
  object ob=this_object();
  if(me->query_temp("killer")) 
     { 
       say("楚云飞嘿嘿一笑：我正要杀你呢!\n");
       ob->kill_ob(me);
       return 1;
     }
 if(me->query("age")<17) 
     {
        say("楚云飞说道:这位"+ RANK_D->query_respect(me) 
          +"年纪尚小不要过早进这一行\n");
        return 1; 
     }
  if(me->query("pker")==1)
     {
        say("楚云飞把脸一沉：你以为你有多大本事？想同时接几个任务！\n");
        return 1;
     }
  if((me->query_temp("gold_given")!=1||!me->query_temp("wen_pass")||!me->query_temp("wu_pass"))&&!me->query("accomplish2")&&!me->query_temp("right"))
     {
        say("楚云飞大喝一声：你是怎么混进来的！\n");
        ob->kill_ob(me);  
        me->set_temp("killer",1);
        return 1;
     }
  if(me->query("reward")==3)
    {
      write("楚云飞笑道：你已身为紫玉杀手，今后这种小事就不用你去了.\n");
      return 1;
    }
  if ( (int)me->query_condition("bonze_pk" ) > 0)
   {say("楚云飞向你挥挥手：没什么事了下去吧\n"); return 1;}
  if(ob->query("count")<=0)
   {say("楚云飞说道:老夫今天累了,就到这里吧!\n");return 1;}

   say("楚云飞说道：哦，"+RANK_D->query_respect(me) +"有兴趣杀个人玩玩吗？嘿嘿....\n");
   command("say 让我看看有没有合适你的家伙");
   death=users();
   for(i=0;i<sizeof(death);i++)
    {   
 
     his_exp=death[i]->query("combat_exp");
     my_exp=me->query("combat_exp");
     if(my_exp>his_exp) 
        sub_exp=my_exp-his_exp;
     else
        sub_exp=his_exp-my_exp;
     j=0;
 if(sub_exp<=(my_exp/10)&&me->query("id")!=death[i]->query("id")&&!wizardp(death[i])
		 && death[i]->query("mud_age") > 86400)
		{
			printf("编号为%d的id适合\n",i);
			target["id"+sprintf("%d",j++)]=i;
		}
	}
	if( mapp(target) && sizeof(target) )
	{
	targetid=keys(target);
	i=(int)targetid[random(sizeof(targetid))];
      me->set("deathname",death[i]->query("id"));
      me->set("deathexp",death[i]->query("combat_exp"));
      say("楚云飞说道：有了，就是他了,【"+death[i]->query("name")+"】,如何？\n");
      me->set_temp("get_answer",1);
      say("想好了回答(answer)我\n");
      return 1;
	} 
       say("很遗憾，没有合适于你的人\n");
       return 1;
}
    
void init()
{
        
        add_action("get_answer","answer");
        add_action("get_request","request");
        add_action("get_bai","apprentice");
        add_action("get_bai","bai");
        add_action("get_name","select");
        add_action("re_fail","fail");
        add_action("get_kill","kill");
}
 

int get_answer(string arg)
{
  object me;
  me=this_player();
  if(!arg||(arg!="yes"&&arg!="no"))
  {
        say("楚云飞说道：我可没空陪你玩！给我滚！\n");
        remove_call_out("kicking");
        call_out("kicking", 1, me);
        return 1;
   }
  if(!me->query_temp("get_answer"))
  { 
    say("你说的关我什么事\n");
    return 1;
  }
  if(arg=="yes")
{
  say("楚云飞哈哈大笑几声，这位"+RANK_D->query_respect(me) +
      "果然有魄力，好！\n");   
  me->set("pker",1);
  say("你可以选择(select)一个名字作为今后行走的代号\n");
     me->delete("get_answer");
     me->set("begin_time",me->query("mud_age"));
  me->set_temp("get_name",1);
    return 1;
}
  else
   {
     command("heng");
     say("没有胆量就不要来我这里！\n");
     me->delete("get_answer");
     me->delete("deathname");
     me->delete("deathexp");
     return 1;  
    }
}


int get_request()
{
     int pkscore,reward,pksc;
object me,ob;
me=this_player();

if(!me->query("pker"))
{ say("楚云飞说道：这位"+RANK_D->query_respect(me)+"不知从何说起啊?\n");
  return 1;
}
if(!me->query("accomplish2"))
{
 say("楚云飞喝道:任务没有完成，你居然敢回来见我！\n");
 remove_call_out("kicking");
 call_out("kicking",0,me);
 return 1;
}
 say("楚云飞哈哈大笑几声：好，我没有看走眼，果然是个人物！\n");
   say("现在改为每次pk增加pkscore 100点了！\n");
 me->delete("accomplish2");
 me->set_temp("right",1);
  pksc = 20000/(me->query("mud_age")-me->query("begin_time"));
   if (pksc < 10) pksc = 10;
   me->add("pkscore", 100);
 command("smile");
 me->add("combat_exp",me->query("deathexp")/50);
 message_vision(HIY "你被奖励了\n" NOR,me);
 me->delete("pker");
 me->delete("deathname");
 me->delete("deathexp");
 me->delete("pk_level");
 me->set("name",me->query("oldname"));
 me->apply_condition("bonze_pk", 500);
 
 pkscore=me->query("pkscore");
 reward=me->query("reward");
 if(me->query("pkscore")>12000&&me->query("reward")==2)

{
   say("这位"+RANK_D->query_respect(me)+"真是武林中百年难得一见的好手，
我这里有一把归魂剑，乃是我当年行走江湖时所用之物，现在就送给你吧！\n");
    me->set("family/pk_master","楚 云 飞");
    ob = new (__DIR__"obj/guihun_sword");
    ob->move(this_player());
    me->set("name",me->query("oldname"));
    me->set("title",HIR "紫玉杀手" NOR);
    me->add("reward",1);
    return 1;
}
  if(pkscore>2000&&reward==0)
{
   say("这位"+RANK_D->query_respect(me)+"身手非凡,连本帮主也不能不敬佩于你，
应该重重的奖励你！呆会你去梁总管那里去领赏，就说我要给你颗玄气丹\n");
   me->set("title",HIR "青玉杀手" NOR);
   me->set_temp("get_dan",1);
   me->add("reward",1);
   return 1;
}
  if(pkscore>5000 && reward==1)
{
   say("这位"+RANK_D->query_respect(me)+"你已经成为本帮开创以来第一杀手，完全有能力
继承我的大业，我现在就把这本归魂剑秘籍交给你，希望你好好钻研，光大我杀手帮一派!\n");
    ob = new (__DIR__"obj/guihun_miji");
    ob->move(this_player());
   me->set("title",HIR "黑玉杀手" NOR); 
   me->add("reward",1);
}
    say("楚云飞笑着说：好了，没什么事了，你下去吧\n");
    me->delete("pker");
    return 1;
}

 
int get_bai()
{
  say("楚云飞说道:我杀手帮不收门徒，只在江湖之中招募高手充当杀手\n");	
  return 1;
}   

int kicking(object me)
{
        if (!me || environment(me) != environment()) return 1;

	me->move("/d/pker/shanmen");
	message("vision","楚云飞大袖一拂" +  me->query("name") +
		"一个踉跄就从纵横神府跌了出来\n", environment(me), me);
        return 1;
}
 
int re_fail()
{
   object me,ob,feilong,jujing,menzhu;
   string name1,name2,name3,name;
   ob=this_object();
   me=this_player();
   feilong=load_object("/clone/npc/feilong");
   name1=feilong->query("winner");
   jujing=load_object("/clone/npc/jujing");
   name2=jujing->query("winner");
   menzhu=load_object("/clone/npc/meng-zhu");
   name2=menzhu->query("winner");
   name=me->query("id");
   
   if(me->query("pker")!=1)
   {
        say("楚云飞迷惑的望着你：这位大侠不知从何说起?\n");
        return 1;
   }
   if(name==name1||name==name2||name==name3)
   {
   	say("楚云飞冷笑一声:你还有帮主之位,就想承认失败?\n");
   	return 1;
   }	

   
   say("楚云飞大怒：想不到你是个这样的懦夫！算老夫看走了眼！给我滚！\n");
   say("现在fail改为每次降pkscore 100点，不再降经验值了！\n");
   me->delete("pker");
//     me->add("combat_exp",-(me->query("deathexp")/50));
   me->set("name",me->query("oldname"));
   me->add("pkscore", -100);
   me->set("pker/be_pked","pker");
   me->delete("deathname");
   me->delete("deathexp");
   me->delete("spyname");
   ob->add("count",1);
   remove_call_out("kicking");
   call_out("kicking", 0, me);
   return 1;
}
  


int get_name(string name)
{
  object me=this_player();
  object ob=this_object();
  string spyname;
  string *spys = ({"华山王前","全真李余","少林扫地僧","丐帮小糊涂","武当何立","天龙孙拳","襄阳郭没"});
if(!me->query_temp("get_name"))
{
    say("楚云飞瞟了你一眼，显然把你当神经病了\n");
  return 1;
}
  if(!name||name==""||name==(string)me->query("name"))
  {
    say("楚云飞说道：难道你打算用真名去杀人吗？倒是有点胆气。好吧\n");
    name=(string)me->query("name");
  }
  me->set("oldname",(string)me->query("name"));
  me->set("name",name);
  spyname=spys[random(7)];
  say("今后你就以这个名字行走吧！\n");
  message("vision",RED "楚云飞附到你耳边说：任务完成以前你与"NOR+spyname+RED"单线联系，不得前来见我!\n" NOR,me);
  me->set("pk_level",2);
  me->set("spyname",spyname);
  command("chat 杀手帮杀手开始行走江湖！");
  ob->add("count",-1);
  me->delete_temp("wen_pass");
  me->delete_temp("wu_pass");
  me->delete_temp("gold_given");
  return 1;
} 


int get_kill(string arg)
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if(me->query("reward")!=0&&(arg=="chu"||arg=="chu yunfei"||arg=="master"))
   {
      write("楚云飞大怒：想不到我一力栽培于你，今日你居然要杀我，好！我今天就给你点颜色瞧瞧!\n");
      me->delete("reward");
      me->set("title",HIR"杀手帮弃徒"NOR);
	  me->delete("pkscore");
      ob->kill_ob(me);
      return 1;
   }
return 0;
}

void die()
{
        object mask,me,player,sword;
        me = this_object();

        if( objectp(player = me->query_temp("last_damage_from"))) 
        {
//                  if (base_name(environment(me)) == "/d/pker/zonghengfu")
//                {
//                        mask = new("/clone/misc/mask2");

//                         mask->move(player);
//                }
	        message("vision",HIW"楚云飞一声长叹：想不到我楚云飞纵横一世，最后死在"+player->name()+"手里。。\n"NOR,users());
        }
      	  
        if(objectp(sword=present("guihun sword",me)))
        	message("vision",WHT"楚云飞掌中归魂剑顿时黯然"+
        	"失色，竟然化作片片铁锈，消逝在风中。。\n"NOR,environment(me));
        message("vision",HIB"正是：恩恩怨怨本难了，是是非非待来生。江湖儿女称雄霸，逝去红颜空啼痕。\n"+
        "这人世的纷争，江湖的杀戮，到头来，都是如此下场，英雄一世，也难免一死。\n"NOR,environment(me));
        destruct(me);
}

void unconcious()
{
die();
}






