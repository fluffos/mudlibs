#include <ansi.h>
inherit NPC;

string ask_liwu();

void create()
{
        set_name(HIG"金庸"NOR, ({ "jin yong","jing" }) );
  set("title", HIM "武林至尊" NOR);
	set("gender", "男性" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "他就是大侠金庸。你可以向他要礼物\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 150);
	set_skill("blade", 150);
	set_skill("parry", 40);
	set_skill("dodge", 150);
set("chat_chance",10);
        	 set("chat_msg", ({
		"金庸念道：问世间 情为何物 直教生死相许\n",
		"金庸念道：天南地北双飞客 老翅几回寒暑\n",
		"金庸念道：欢乐趣 离别苦 就中更有痴儿女\n",
		"金庸念道：君应有语 渺万里层云\n"
		"金庸念道：问世间 情为何物 直教生死相许\n",
		"金庸念道：天南地北双飞客 老翅几回寒暑\n",
		"金庸念道：欢乐趣 离别苦 就中更有痴儿女\n",
		"金庸念道：君应有语 渺万里层云\n"
		"金庸念道：赵客缦胡缨，吴钩霜雪明。银鞍照白马，飒沓如流星。\n",
		"金庸念道：十步杀一人，千里不留行，事了拂衣去，深藏身与名。\n",
		"金庸念道：闲过信陵饮，脱剑膝前横。将炙啖朱亥，持觞劝侯嬴。\n",
		"金庸念道：三杯吐然诺，五岳倒为轻。眼花耳热后，意气素霓生。\n",		
		"金庸念道：救赵挥金锤，邯郸先震惊，千秋二壮士，煊赫大梁城。\n",
                "金庸念道：纵死侠骨香，不惭世上英，谁能书阁下，白首太玄经。\n",
	}) );
	set("inquiry" , ([
             "gift" : (: ask_liwu :),
             "礼物" : (: ask_liwu :),
             "liwu" : (: ask_liwu :),
	]));
	setup();
}

string ask_liwu()
{
  object me=this_player();
  int exp_bound,qn_bound,neili;

  if(me->query("liwu_bound")>0)
  {
   return "已经给过你新手礼物了额!";
  }
  exp_bound=random(8000)+8000;
  qn_bound=random(8000)+2000;
  neili=random(200)+180;

  //command("chat "HIR+me->query("name")+HIC"得到我的奖励基本武功各20级!");
  command("say "HIR+me->query("name")+HIC" 欢迎你来到侠客行一百 海洋II的武侠世界!");
//command("say "HIR+me->query("name")+HIC" 欢迎你来到侠客行一百 海洋II的武侠世界!");
//command("say "HIR+me->query("id")+HIC" 如果你是新手，请用help -old看一下帮助!");
//command("say "HIR+me->query("id")+HIC" help aboutquest是任务说明!");
//command("say "HIR+me->query("id")+HIC" help wlmm是常见说明!");
//command("say "HIR+me->query("id")+HIC" help maps是常见区域地图!");
//command("say "HIR+me->query("id")+HIC" help menpai是门派说明!");
//command("say "HIR+me->query("id")+HIC" help shuoming4是路径介绍!");
  //command("say "HIR+me->query("name")+HIC"只有经验大于5000才能保留这20级武功!");
  //command("chat "HIR+me->query("name")+HIC"得到我的奖励潜能:"HIR+qn_bound+HIC"!");
  //command("es "HIG+me->query("name")+HIC"来到了海洋II上海总站"HIR+"IP 202.101.10.187 PORT 5555"+HIC"并得到了奖励!");
        tell_object(me,HIW"你被奖励了：\n" + 
        chinese_number(exp_bound) + "点实战经验\n" +
        chinese_number(qn_bound) + "点潜能\n"+
        chinese_number(neili) + "点内力\n"+
        NOR);
  me->add("combat_exp",exp_bound);
  me->add("potential",qn_bound);
me->add("max_neili", neili);



if (me->query_skill("unarmed")<30)
{
  me->set_skill("unarmed",30);
}
if (me->query_skill("parry")<30)
{
  me->set_skill("parry",30);
}
if (me->query_skill("dodge")<30)
{
  me->set_skill("dodge",30);
}
if (me->query_skill("force")<30)
{
  me->set_skill("force",30);
}

if (me->query_skill("literate")<30)
{
  me->set_skill("literate",30);
}
  me->set("liwu_bound",1);
  return "欢迎光临海洋II！";
}
