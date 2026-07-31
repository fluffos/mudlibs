

#include <ansi.h>

inherit NPC;

static int ask_zhou();
static int ask_back();
static int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence);
int distribute_skill(object ob,int skill_level);

mapping *skill_map = ({
([//逍遥
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//逍遥
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//逍遥
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//逍遥
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),

});

string* msg = ({
"1,一等古月殇,杏眼九州行,小怪",
"2,一等古月殇,杏眼九州行,小怪",
"3,一等古月殇,杏眼九州行,小怪",
"4,一等古月殇,杏眼九州行,小怪",
"5,一等古月殇,杏眼九州行,小怪",
"6,一等古月殇,杏眼九州行,小怪",
"7,一等古月殇,杏眼九州行,小怪",
"8,一等古月殇,杏眼九州行,小怪",
"9,一等古月殇,杏眼九州行,小怪",

});

void create()
{

	set_name("小怪", ({ "xiaoguaiu", "xiaoguai" }));
	set("title", HIY "憨憨" NOR);
	set("gender", "无性");
	set("age", 20);
	set("long","这是个看起来三十来岁的汉子，面眉全黑，脸傍消瘦，着一袭战袍，昂然挺立。\n");


	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 50);
	set("combat_exp", 10000000);

    set("sequence",4);//设置任务人数数量
    set("lvl",100);//设置任务人物成长值
	 set_temp("apply/reduce_busy", 100);//化解忙乱
	set_temp("apply/attack", 150);//命中
	set_temp("apply/defense", 150);//闪避
	set_temp("apply/damage", 150);//武器伤害
	set_temp("apply/unarmed_damage", 150);//空手伤害

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


void die()
{
        object me = this_object()->query_last_damage_from();
        object newob,ob,jl,jl2,jl1,objwp;
		string *manmsg;
        int newsequence,manskills,pot,jilv;
		int exp;
        ob = this_object();
		newsequence = ob->query("sequence")-1;
		manmsg = explode(msg[newsequence],",");

	  if (newsequence <= 1)
	  {
		  me->move("/d/xiaobaiben/fangjian");
		  ::die();
	
	  }
	  else
	  if (newsequence >= 1)
	  {
		pot=10000;
		exp=10000;
	  me->add("potential",pot);
	  me->add("combat_expl",exp);
	  tell_object(me,HIR"你击杀了"+ob->query("name")+exp+"点修为。\n""获得了以及"+pot+"点潜能。\n"NOR);
	  newob = new("/d/xiaobaiben/npc/npcshuxing");
		}
  
   /*	jilv= random(10);
	  if (jilv == 1)
	  {
	  objwp =new("clone/vip/book_wuliang");
	  objwp->move(environment(me));
	 message("channel:chat",HBRED"副本挑战"HIR"："+ob->query("name")+"完成任务 掉落\n"NOR,users());
	  }
	  else
	  if (jilv == 2)
	  {
	  objwp =new("/d/automap4/npc/guai1");
	  objwp->move(environment(me));
	  message("channel:chat",HBRED"副本挑战"HIR"："+ob->query("name")+"完成任务 掉落\n"NOR,users());

	  }
	  else
	    if (jilv == 0)
	  {
	  objwp =new("/clone/fbqhs");
	  objwp->move(environment(me));
	    message("channel:chat",HBRED"副本挑战"HIR"："+ob->query("name")+"完成任务 掉落\n"NOR,users());
	  }*/

	  if (objectp(newob)&&objectp(ob)&&sizeof(manmsg)&&newsequence)
	  {
	  inheritman(newob,ob,manskills,manmsg,newsequence);
	  environment(ob)->set("short",manmsg[1]);
	  newob->move(environment(ob));
	 tell_object(me,ZJFORCECMD("look"));//执行look指令，以便玩家看到当地环境名称的变化!
	 }
	  ::die();
}
//需要注意，调用此函数需要保证两个物件同时存在。
int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence)
{
object me = this_object()->query_last_damage_from();
 distribute_skill(newob,me->query_temp("zhuangtai")+50);

    newob->set("qi", ob->query("lvl")*50);
	newob->set("max_qi",ob->query("max_qi")*50);
	newob->set("eff_qi",ob->query("max_qi")*50 );
	newob->set("jing", ob->query("max_jing")*50);
	newob->set("max_jing", ob->query("max_jing")*50);
	newob->set("neili", ob->query("max_neili")*50);
	newob->set("max_neili", ob->query("max_neili")*50);
	newob->set("sequence",newsequence);
	
	 newob->set("name",manmsg[3]);
	 newob->set("title",manmsg[2]);
	newob->set("lvl",ob->query("lvl")+120);
	newob->set_temp("apply/jiali", ob->query("lvl"));
	newob->set_temp("apply/attack", ob->query("lvl"));
	newob->set_temp("apply/defense", ob->query("lvl"));
	newob->set_temp("apply/damage", ob->query("lvl")*3/2);
	newob->set_temp("apply/unarmed_damage", ob->query("lvl")*3/2);
	return 1;
}

int distribute_skill(object ob,int skill_level)
{
int ran,size,i;
string *skills;
	ran = random(sizeof(skill_map));
	size = sizeof(skill_map[ran]);
	skills = keys(skill_map[ran]);

	for(i = 0; i < size; i++)
	{
		if (!skill_map[ran][skills[i]])
		{
			ob->set_skill(skills[i], skill_level);
		}
		else
		{
			ob->set_skill(skills[i], skill_level);
			ob->set_skill(skill_map[ran][skills[i]], skill_level);
			ob->map_skill(skill_map[ran][skills[i]], skills[i]);
		}
	}
	return 1;
}