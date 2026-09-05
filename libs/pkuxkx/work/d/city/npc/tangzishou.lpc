// 趟子手 zine Oct 24 2010保护玩家不被get all

inherit NPC;
#include <ansi.h>
int dest();
int ask_keepfollow();
void create()
{
    string* name=({"妲己","褒姒","夏姬","毛嫱","西施","王昭君","貂蝉","杨玉环","妺喜","郑旦","赵飞燕","骊姬","赵姬","陈圆圆","萧皇后","李师师","柳如是","香妃",});
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	set_name(color[random(sizeof(color))]+name[random(sizeof(name))]+NOR, ({ "tangzi shou", "shou", "beauty" }));
	set("age", 20);
    set("per", 50);
	set("gender", "女性");
	set("long", "趟子手的主要职责不是与劫匪战斗，而是保护镖师。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 200000);
        set("shen_type",1);

	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("blade", 120);
	set_skill("force", 120);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
    set("inquiry", ([
                
                "跟随" : (: ask_keepfollow:),    
                "保护" : (: ask_keepfollow:),
        ]) );

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"items/cloth1")->wear();
    call_out("dest",480);
    call_out("checksta",1);
}

int checksta()
{
    object lord;
    if (this_object()->query("lord"))
    {
        lord=find_player(this_object()->query("lord"));
        if (lord && lord->query("in_dart"))
        {
            call_out("checksta",40);
            return 1;
        }
        else
        {
            dest();
            return 1;
        }
    }
    else
    {
        dest();
        return 1;
    }
}

int dest()
{
    if (environment(this_object()))
    {
    tell_room(environment(this_object()),this_object()->query("name")+"见没什么其他事可做，自己先回福威镖局了。\n");
    }
    destruct(this_object());
}

void init()
{
	add_action("do_get",({"get"}));
}

int ask_keepfollow()
{
    if (this_player()->query("id")==this_object()->query("lord"))
    {
    command("follow "+this_player()->query("id"));
    command("say 好吧，本小姐且保护你一程。");
    return 1;
    }
}

int busyme(object me)
{
    me->add_busy(random(4)+6);
}
int do_get(string arg)
{
    string things,target;
    object me=this_player();
    if (arg==this_object()->query("lord"))
        {
            tell_object(me,this_object()->query("name")+"见你光天化日之下竟敢直接抢人，对你大喝了一声，你愣了一下。\n");
            remove_call_out("busyme");
            call_out("busyme",1,me);
            return 1;
        }
	if(sscanf(arg, "%s from %s", things, target)==2)
    {
        if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
        
        
        if (things=="all" && target==this_object()->query("lord"))
        {
            tell_object(me,this_object()->query("name")+"见你光天化日之下竟敢抢东西，对你大喝了一声，你愣了一下。\n");
            remove_call_out("busyme");
            call_out("busyme",1,me);
            return 1;
        }
        
    }
    
}
