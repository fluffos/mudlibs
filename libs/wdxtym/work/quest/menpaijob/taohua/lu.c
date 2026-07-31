// lu.c
#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
int ask_job();
int ask_fail();
void create()
{
        set_name( "陆乘风" ,({ "lu chengfeng", "lu" }));
        set("gender", "男性");
        set("age", 52);
        set("long",
            "陆乘风是黄药师的第四个徒弟。\n"
            "他的鬓角已微见白发，但身材魁梧，双眼有神。\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 50);
        set("int", 58);
        set("con", 50);
        set("dex", 50);
        set("chat_chance", 1);
        set("max_qi",35000);
        set("max_jing",35000);
        set("neili", 65000);
        set("max_neili", 65000);
        set("jiali", 100);
        set("shen_type",1);

        set("combat_exp", 3300000);
        set_skill("force", 220);             // 基本内功
        set_skill("bibo-shengong", 220);     // 碧波神功
        set_skill("unarmed", 220);           // 基本拳脚
        set_skill("xuanfeng-leg", 220);      // 旋风扫叶腿
        set_skill("strike", 220);            // 基本掌法
        set_skill("luoying-zhang", 220);     // 落英神剑掌
        set_skill("dodge", 170);             // 基本躲闪
        set_skill("anying-fuxiang", 270);    // 暗影浮香
        set_skill("parry", 190);             // 基本招架
        set_skill("sword", 190);             // 基本剑法
        set_skill("luoying-shenjian", 190);  // 落英神剑
        set_skill("literate",190);           // 读书识字

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");

        set_temp("jinbing", 30);
        create_family("桃花岛", 2, "弟子 归云庄主");

        set("inquiry", ([
           "桃花岛":   "这儿就是桃花岛，你若不是本派弟子，要过桃花阵。",
           "桃花阵":   "往南就是了。",
           "东邪":     "家师人称东邪！呵呵。",
           "西毒":     "欧阳锋是与家师并世齐名的高手，人称老毒物。",
           "南帝":     "听家师说段王爷现在出家当了和尚，法名一灯。",
           "北丐":     "北丐洪七公是丐帮帮主，现在扬州城外。",
           "黄蓉":     "她是师父的爱女。",
           "黄药师":   "你要拜访家师？",
            "job" : (: ask_job() :),
            "失败" : (: ask_fail() :),
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say 我派武功讲究轻灵巧捷。");
           command("say 这位"+RANK_D->query_respect(ob)+"可能是白来归云庄一趟了。");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say 我派在江湖中立身尚正，"+ RANK_D->query_respect(ob)+"请回吧。");
           return;
        }
        if (ob->query("gender") == "无性")
        {
           command("say 师父最讨厌不男不女的东西了，这位"+RANK_D->query_respect(ob)+"赶快请吧。");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say 师父最爱非僧抑道了，这位"+RANK_D->query_respect(ob)+"还是请回吧。");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "入我门下，需努力不堕。");
        command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
        command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp;
	if (query_temp("jinbing") < 0)
	{
                command("say " + RANK_D->query_respect(who) + "我很累，你回头再来领赏吧。");
		return 0;
	}
//        if(ob->query("userp")) return notify_fail("嘿嘿，想作弊？！\n");
	if (strsrch(ob->query("name"), "完颜康的头颅") < 0 &&
	    strsrch(ob->query("name"), "完颜洪烈的头颅") < 0 &&
	    strsrch(ob->query("name"), "欧阳锋的头颅") < 0 &&
	    strsrch(ob->query("name"), "欧阳克的头颅") < 0 &&
	    strsrch(ob->query("name"), "彭连虎的头颅") < 0 &&
	    strsrch(ob->query("name"), "梁子翁的头颅") < 0 &&
	    strsrch(ob->query("name"), "灵智上人的头颅") < 0 &&
	    strsrch(ob->query("name"), "沙通天的头颅") < 0 &&
	    strsrch(ob->query("name"), "侯通海的头颅") < 0 &&
	    strsrch(ob->query("name"), "沈青刚的头颅") < 0 &&
	    strsrch(ob->query("name"), "吴青烈的头颅") < 0 &&
	    strsrch(ob->query("name"), "马青雄的头颅") < 0 &&
	    strsrch(ob->query("name"), "钱青健的头颅") < 0 &&
	    strsrch(ob->query("name"), "大金兵的头颅") < 0 &&
	    strsrch(ob->query("name"), "段天德的头颅") < 0) 
	{
                command("say 给我这些东西有什么用？\n");
		return 0;
	}
       if(ob->query("userp"))
	{
                command("say 嘿嘿，想作弊？？\n");
		return 0;
	}
	else
	{
                command("say 不错不错，我一直想杀这些金狗，谢你代劳了。");
	}
	exp = 20+random(30);
	this_player()->add("combat_exp",exp);
	add_temp("jinbing", -1);
	tell_object(who,HIW"陆乘风奖励了你"+chinese_number(exp)+"点实战修为\n"NOR);
	return 1;
}

int ask_job()
{

        object me = this_player();
        object ob = this_object();
	  
        if( me->query("family/family_name") != "桃花岛")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
	                      return 1;
            }

//	  if (ob->query_condition("taohuajob"))
//           {
//                      message_vision("$N对着$n说道。等一会再来,本任务十五分钟一次!\n", this_object(), me);
//	                      return 1;
//            }

      if( (int)me->query_skill("bibo-shengong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("陆乘风对着$N摇了摇头说：你等会再来!\n", me);
                      return 1;
            }
        if ((int)me->query_condition("taohuajob"))  
            {
                      message_vision("$N对着$n摇了摇头说：你刚接过任务,等会再来!\n", this_object(), me);
                      return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "你还是练高修为再来吧");
                return 1;
}
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你的潜能太少了!!");
                return 1;
        }

        if (me->query("taohuajob") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "最近有一条官船,要路过此地。");
                command("say " + me->query("id") + "你把官船上的贪官杀了,把金银抢来给穷人分了！\n" NOR);
                me->set("taohuajob", 1);
//	        ob->apply_condition("taohuajob",13);
	        me->apply_condition("taohuajob",16);
                return 1;
               }                              
}


int ask_fail()
{
        object me = this_player();
        
        if (me->query("taohuajob") == 1) {
                command("sigh");
                command("say 你这身手也来抢官船,扣你150点EXP.");
                me->add("combat_exp",-150);
                me->delete("taohuajob");
                me->apply_condition("menpai_busy",12);
//                call_out("delete", 1);
                return 1;
                }
}



int hit_ob(object me, object ob, int damage)
{
if (ob!=me)
{
ob->start_busy(12);
	ob->apply_condition("qx_snake_poison", 220);
	ob->apply_condition("wugong_poison", 140);
        ob->apply_condition("chanchu_poison", 140);
        ob->apply_condition("xiezi_poison", 140);
        ob->apply_condition("snake_poison", 140);
        ob->apply_condition("zhizhu_poison", 140);
        tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
}
}