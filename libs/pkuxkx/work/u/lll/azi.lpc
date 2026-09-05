// azi.c 阿紫
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/new_quest/qxingxiu.h"
#include "/new_quest/quest.h"
string ask_me();
string ask_zhen();
void consider();
void do_answer(string);

void create()
{
        set_name("阿紫", ({ "a zi","azi" }));
        set("nickname", "星宿派小师妹");
        set("title",HIR "星宿派" NOR + GRN +"妖女" NOR);
        set("long",
                "她就是丁春秋弟子阿紫。\n"
                "她容颜俏丽，可眼神中总是透出一股邪气。\n");
        set("zhen_count",5);
        set("gender", "女性");
        set("age", 15);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 25);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("combat_exp", 50000);
        set("score", 10000);
	set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "name"   : "我就是阿紫呀！！",
        	"quest":   (: ask_quest() :),
        	"碧磷针":  (: ask_zhen() :),
        ]) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
        set_skill("force", 50);
        set_skill("huagong-dafa", 50);
        set_skill("dodge", 50);
        set_skill("zhaixinggong", 50);
        set_skill("strike", 50);
        set_skill("xingxiu-duzhang", 50);
        set_skill("hand", 50);
        set_skill("zhaixing-shou", 50);
        set_skill("parry", 50);
        set_skill("staff", 50);
	set_skill("tianshan-zhang", 50);
        set_skill("literate", 80);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "xingxiu-duzhang");
 	map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
        create_family("星宿派", 2, "弟子");
        setup();
        carry_object("/d/xingxiu/obj/xxqingxin-san");
        carry_object("/d/xingxiu/obj/xxqingxin-san");
}
void init()
{
	add_action("do_answer","answer");
add_action("do_qifu","kick");
add_action("do_qifu","hit");
add_action("do_qifu","kill");
add_action("do_qifu","fight");
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}

void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say 好吧，我就收下你了。");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
	}
return;
}



void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("exert qisuck " + target->query("id"));
}

string ask_me()

{
	mapping fam;
  	if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	if ( this_player()->query_temp("marks/阿") )
    		return "“怎么，我不是刚刚告诉你了吗?”\n";
	if (this_player()->query_temp("marks/丁") )
	{
		write("阿紫悄悄对你说道：你都知道了，冰魄杖是我给老怪藏了起来了,\n"
			"你到逍遥洞找找，找到了，你就拿着吧，我要着也没用。\n");
  		this_player()->set_temp("marks/阿", 1);
		return "这可不能让外人听到啊！";
 	}
	else
	{
		write(HIY"你发现阿紫的脸有点红.\n"NOR);
		return("我...我不知道。。\n");
	}	
}

string ask_zhen()
{
	object zhen;
	mapping fam;

  	if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                	"与本派素无来往，为何窥觑本派宝物？";
	if (this_player()->query("score") < 200)
		return "这位" + RANK_D->query_respect(this_player()) +
			"对本门忠心不够，没有资格获得本门宝物。";
	if (query("zhen_count") == 0)
		return "你来晚了，碧磷针我已经给光了。";
        add("zhen_count",-1);
	zhen = new("/d/xingxiu/npc/obj/bilinzhen");
	zhen->move(this_player());
        message_vision("阿紫从腰间捏出一根绿幽幽的" + HIG + "碧磷针"+ NOR + "交给$N。\n",this_player());
	return "碧磷针炼制不易，一定要仔细使用啊。";
}
void die()
{
(this_object()->query_temp("last_damage_from"))->unconcious();
set("qi",10000);
set("max_qi",10000);
set("eff_qi",10000);
}
int do_qifu(string target)
{
object me;
{me=this_player();;}
                   message("vision",
   HIB "啦啦啦冲你邪恶的一笑：不许欺负阿紫哦！哼哼\n"
   NOR, environment(), this_object() );
{me->unconcious();}
return 1;
}
