// gaohehui.c 高和惠

inherit NPC;
inherit F_DEALER;
string ask_me();

int do_mo(string arg); 
int do_fenyao(string arg); 
int do_zhengli(string arg); 
void reward(object me); 

void create()
{
	set_name("高和惠", ({ "gao hehui", "gao" }));
	set("per", 29);
	set("no_get",1);
	set("str", 20);
	set("gender", "女性");
	set("age", 22);
            set("title", "名医");
	set("long", "她是神医世家的长女。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/d/shenlong/obj/xionghuang",
	}));
        set("inquiry", ([
                "工作" : (: ask_me :),
                "job"  : (: ask_me :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_mo", "moyao"); 
        add_action("do_fenyao", "fenyao"); 
        add_action("do_zhengli", "zhengli"); 
}

string ask_me() 
{ 
object me = this_player(); 

if(me->query("family/family_name")!="飞天御剑流")
return "你是谁啊，我不认识你!";

 if (me->query("qi") < 30) 
return "你还是歇会儿吧！ 在做下去我这里又要多了个病人了"; 

if (me->query_temp("smith/mo")) //检查标记
return "不是让你磨药去了吗(moyao)？"; 

if (me->query_temp("smith/fenyao")) 
return "叫分药你分完没有(fenyao)？"; 

if (me->query_temp("smith/zhengli")) 
return "叫整理你整理没有(zhengli)？"; 

switch(random(3))//随机分配三个工作
{ 
case 0: 
me->set_temp("smith/mo", 6+random(11)); 
return "好吧！你帮我磨一下药(moyao)。"; 

case 1: 
me->set_temp("smith/fenyao", 6+random(11)); 
return "这样吧，你帮我分一下药(fenyao)。"; 

case 2:
me->set_temp("smith/zhengli", 6+random(11)); 
return "这里药物太杂乱了，你帮我整理一下(zhengli)。"; 
}
return "快去做事吧!!"; 
}
 
int do_mo(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("你现在正忙。\n"); 

if (! me->query_temp("smith/mo")) 
{ 
message_vision("$n拿起药锄正准备磨药时。" 
"就听见$N对$n大喝道：谁让你在这里乱搞的。\n", 
this_object(), me); 
return 1; 
} 

if ((int)me->query_temp("smith/mo") > 1) 
{
message_vision("$n拿起药材跟工具认真的磨了起来，$N看了点了点头。\n", 
this_object(), me); 
me->start_busy(1);
me->add_temp("smith/mo",-1);
} else reward(me); 
return 1; 
} 

int do_fenyao(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("你现在正忙。\n"); 

if (! me->query_temp("smith/fenyao")) 
{ 
message_vision("$n胡乱的抓了几把药在手中。" 
"只听见$N对$n大喝道：放下，在这里乱搞什么。\n", 
this_object(), me); 
return 1; 
} 

if ((int)me->query_temp("smith/fenyao") > 1) 
{
message_vision("$n仔细看着手中的药材开始分药，" 
"$N“嗯”了一声，看上去有些满意。\n", 
this_object(), me); 
me->add_temp("smith/fenyao",-1);
me->start_busy(1);
}
else reward(me); 
return 1; 
} 

int do_zhengli(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("你现在正忙。\n"); 

if (! me->query_temp("smith/zhengli")) 
{ 
message_vision("$n乘$N不注意拿起药品就打算往柜子里丢，" 
"就听见$N对$n大喝道：你想害死人啊，还不快给我放下。\n", 
this_object(),me);
return 1; 
} 

if ((int)me->query_temp("smith/zhengli") > 1) 
{
message_vision("$N抽开药柜按照药签把药品分类放好。\n", 
me); 
me->start_busy(1);
me->add_temp("smith/zhengli",-1);
} else reward(me);

return 1; 
} 

void reward(object me) //工作结束，分配奖赏，移除标记
{ 
object coin; 
int exp,pot;
exp=15+random(25);
pot=10+random(10);
me->delete_temp("smith/mo"); 
me->delete_temp("smith/fenyao"); 
me->delete_temp("smith/zhengli"); 

coin = new("/clone/money/coin"); 
coin->set_amount(20 + random(50)); 
coin->move(this_player()); 
message_vision("$N对$n道：这是给你的工钱。\n", 
this_object(), me); 
me->add("potential", pot); 
me->add("combat_exp", exp); 
me->receive_damage("qi", me->query("qi")/20); 
me->receive_damage("jing", me->query("jing")/20); 
me->start_busy(1); 
tell_object(me,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
		+chinese_number(pot)+"点潜能\n");
} 