// fangzhang, the one in jail.
// created by mes, updated 6-21-97 pickle

/************************************************************/
#include <ansi.h>
inherit NPC;

string quest_complete();
int award(object me);
void destroy(object ob);
int annouce_adjust(object me);
string answer();
string check_gift();
int do_add(string arg);
int do_subtract(string arg);
int do_finalized(string arg);

string method="
具体指令如下：

降低天赋：subtract <arg>
增加天赋：add <arg>
检查情况：state
决定接受：finalize

这里的 <arg> 是天赋的缩写：

膂力：str    胆识：cor    悟性：int    灵性：spi
定力：cps    容貌：per    根骨：con    福缘：kar

";
int total = 0;
int credit = 0;
mapping points=([]);
mapping gift=([
	"str"		: "膂力",
	"cor"		: "胆识",
	"int"		: "悟性",
	"spi"		: "灵性",
	"cps"		: "定力",
	"per"		: "容貌",
	"con"		: "根骨",
	"kar"		: "福缘",
]);
string *gift_name=({ "kar", "con", "per", "cps", "spi", "int", "cor", "str", });
/************************************************************/
void create()
{
  set_name("圆清",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","方丈");
  set("gender", "男性");
  set("age", 80);
  set("long","一个削瘦的老和尚，似乎被吓疯了。\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
		   "name"   : "唉！老纳本是灵云寺的圆清长老。",
		   "here"   : "我也不知道怎么回事。那天晚上我正念佛呢，突然就被一阵阴风刮这里来了。",
		   "rumors" : "我连自己的生死都不知，还有什么闲心去打听别的？",
		   "生死"   : "也不知有没有哪位英雄肯来搭救我。唉！",
		   "rescue" : (: quest_complete :),
		   "搭救"   : (: quest_complete :),

		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

/************************************************************/
string quest_complete()
{
  object monk=this_object(), me=this_player();
  string served;

  if (stringp(served=query("serving"))
   && served != me->query("id"))
    if (present(served, environment(monk)))
    {
	return "多谢施主好意，但已有人答应带老衲出去。";
    }
  if (me->query("obstacle/wudidong") == "done")
  {
      tell_object (me,"你已经过了这一关，什么都得不到了！\n");
      return "这．．．";
  }
  if (served==me->query("id"))
	return "阿弥陀佛，施主不是已经答应带老衲出去了么？";
  if (!wizardp(me) || !me->query("env/immortal"))
  if (!me->query_temp("mark/wudidong_opened_door")
    || me->query_temp("mark/wudidong_no_hope_of_knowing_trap"))
  {
      command("say 你、你、你，你是谁？哦，你是来救我的？看你这样子不象啊？");
      command("say 你也是被别人打晕了背进来的吧？我要是跟你出去了，还得给抓回来。");
      return "阿弥陀佛，我佛慈悲！贫僧的这张草铺就让给你吧。";
  }
  me->set_temp("wudidong/can_ask_monk");
  set("serving", me->query("id"));
   call_out("award", 0, me);
  return "这位施主是来搭救于我的？";
}




int award(object me)
{
  object monk=this_object();
        string myid=me->query("id");
        string myname=me->query("name");
  int year, day, hour, reward, mykar=me->query_kar();

  command("thank " + myid);
  command("say 老纳这就起程回寺！");
  command("south");
  call_out ("destroy",2, monk);	

  me->add("obstacle/number",1);
  me->set("obstacle/wudidong","done");
  me->delete_temp("mark/wudidong_opened_door");
  reward=37000+random((mykar-10)*80);
 
  tell_object (me,"你赢得了"+chinese_number(reward)+"点经验 "+chinese_number(reward/2)+"点潜能 十点门派贡献 二点成长上限！！\n");
  command("rumor 听说"+myname+"独闯无底洞，救出了玉鼠精抓去的一个老和尚，也不知是真是假。");
  me->add("combat_exp",reward);
     me->add("potential",reward/2);
   me->add("mpgx",10);me->add("expmax",2);
  me->save();


  return 1;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/
