// girl.c

inherit NPC;
#include <ansi.h>
void init();
int do_anmo();
void create()
{
        set_name(HIY"和服女子"NOR, ({"hefu nvzi", "sun","girl",}));
        set("long","一位身着和服的女子，说话细声细气，看起来很有礼貌哦。\n");
        set("gender", "女性");
        set("attitude", "friendly");        
        set("age", 15);
        set("str", 21);
        set("int", 25);      
        set("con", 20);
        set("no_get", 1);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("cuff", 100);
        set_skill("parry", 100);
	 set("inquiry", ([ 
	      "name" : "嗯。。呃。。我。。叫。凉子。",
	      "here" : "这里。。丝。。按摩番。。你。。需要服务嘛？",
	      "anmo" : "本点。。星开业。。免汇。。为达家。。服务(anmo)。",
        "按摩" : "本点。。星开业。。免汇。。为达家。。服务(anmo)。",   
        ]));

        set("shen_type",1);set("score",200);setup();
        carry_object("/clone/misc/hefu")->wear();
}

void init()
{
   add_action("do_anmo","anmo");
}                               


int do_anmo()
{
 object ob = this_object();
 object me = this_player();
 object obj;
 if(me->is_busy()) return notify_fail("你正忙着呢！\n");
if (me->query_condition("anmo"))
return notify_fail("哇，你怎么又来按摩了，腐败啊腐败啊。。\n");
tell_object(me,"你在塌塌米上躺了下来。\n");
tell_object(me,HIY"一位身穿和服的女子走了过来，深鞠一躬，跪坐在你身边，开始给你按摩。\n"NOR);
tell_object(me,HIW"温柔的小手轻轻的揉捏着你身上的每一块肌肉，你身上的疲劳顿消，舒服的直想唤娘。\n"NOR);
tell_object(me,HIR"幽香的空气，清雅的古筝，温柔的抚摸。。。你渐渐进入梦乡。\n"NOR);
me->set_temp("block_msg/all", 1);
me->disable_player("<爽歪歪中	>");
me->start_busy(10);
me->apply_condition("anmo",60);
call_out("wakeup", 10, me);
  return 1;
}
void wakeup(object me)
{
	me->delete("disable_type");
	me->start_busy(0);
	me->delete_temp("block_msg/all");
	me->set("eff_qi",(int)me->query("max_qi"));
  me->set("qi",(int)me->query("max_qi"));
  me->set("eff_jing",(int)me->query("max_jing"));
  me->set("jing",(int)me->query("max_jing"));
        tell_object(me,WHT"你从睡梦中醒了过来。觉得全身疲劳尽去，神清气爽。\n"NOR);
}
