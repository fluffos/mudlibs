//渔
//by icer
#include <ansi.h>


inherit NPC;

int ask_fish();
int ask_goldfish();


void create()
{
        set_name("渔隐", ({ "yuyin" }));
        set("long", "他约莫四十来岁年纪，一张黑漆漆的锅底脸，正自垂钓。这瀑布水势湍急异常，一泻如注，水中哪里有鱼？纵然有鱼，又哪有余暇吞饵？\n");
        set("gender", "男性");
        set("rank_info/respect", "大叔");
        set("age", 46);
        set("attitude","heroism");
        set("str", 20);
        set("dex", 35);
        set("con", 20);
        set("int", 30);
        set("shen_type", 5000);

        set_skill("finger", 100);
	set_skill("yiyangzhi",100);
        set_skill("force", 100);
	set_skill("parry",100);
        set_skill("dodge", 100);
	set_skill("xiantian-gong",80);
        map_skill("force", "xiantian-gong");
	map_skill("parry","yiyangzhi");
	map_skill("finger","yiyangzhi");
        set("jiali",50);

        set("combat_exp", 150000);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);

        set("inquiry", ([
	    "怪鱼" : (: ask_fish :),
	    "金娃娃" : (: ask_goldfish :),	
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("seeing");
                call_out("seeing", 1, ob);
        }
	add_action("do_jump","jump");
}

void seeing(object ob)
{
        switch( random(3) ) {
                case 0:
                       break;
                case 1:
                       break;
                case 2:
	               if( ob->query_temp("marks/瑛4") && (!ob->query_temp("marks/渔1")) )

        	       {
           say("
			忽见水中金光闪了一闪，那渔人脸现喜色，猛然间钓竿直弯下去，\n
			只见水底下一条尺来长的东西咬着钓丝，那物非鱼非蛇，全身金色，\n
			模样甚是奇特。你大感诧异，不禁失声叫道“咦？这是什么怪鱼？”\n
			那鱼受了惊吓，转眼之间，钻进了水潭（pool)底的岩石之下，再也不出来了。\n");
			command("l "+ ob->query("id"));
			command("heng "+ ob->query("id"));
			command("say 你是什么人？！老子辛辛苦苦地等了半天，偏生叫你这个小贼来惊走了！");
			ob->set_temp("marks/渔1",1);
		       }
                       break;
        }
}

int ask_fish()
{
	if ((int)this_player()->query_temp("marks/渔1")) {
	say("那渔夫怒道：看清楚了！什么怪鱼！那是金娃娃！\n");
	this_player()->set_temp("marks/渔2", 1);
	}
	else
	{
		say("渔夫摇摇头，没听说过。\n");
	}
	return 1;
}

int do_jump(string arg)	
{
	if (((int)this_player()->query_temp("marks/渔3")) && ( arg = "pool" ))
	{
		this_player()->move("/d/dali/yideng/pool",1);
		this_player()->add("neili",-100);	 
		message_vision("$N一纵身跳下了水潭。\n" , this_player());
         return 1;
	}
		
	return notify_fail("你要往哪儿跳？\n");
	
	
}	
int ask_goldfish()
{
	if ((int)this_player()->query_temp("marks/渔2")) {
	say("渔夫说道：我师叔好不容易捉住了这两只金娃娃，想带回去喂养。可是它们趁我一不小心逃入这水潭之中。\n
终于快要再次捉住的时候却又被你吓跑了，哼！你说怎么办吧！\n");
	this_player()->set_temp("marks/渔3", 1);
	}
	else
	{
		say("渔夫摇摇头，没听说过。\n");
	}
	return 1;
}

int accept_object(object me, object ob)
{
	object boat;
        if (ob->query("id")=="jin wawa")
     {
	        if (!me->query_temp("marks/渔4") ) {
			command("yi");
			command("say 这金娃娃是谁给你的？");
			return 1;}
		else {
			command("thank "+me->query("id"));
			command("say 那边有只小船，你可以划到上面去。");
			write("渔夫匆匆忙忙地跑进小屋，把金娃娃放好。");
			boat=new("/d/dali/yideng/obj/boat");
			boat->move(environment(me));
		        return 1;}
	command("say 我不要这个。");
	return 1;	}
}
	
