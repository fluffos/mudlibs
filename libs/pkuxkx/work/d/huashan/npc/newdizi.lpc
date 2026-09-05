// 弟子by Zine newbie job HS
inherit NPC;
#include <ansi.h>
int bugen(object me);
int ask_gen();
int check_me()
{
	string user;
	object pl,ob=this_object();
	if (!user=ob->query("owner"))
	{
		message_vision("$N见无人理睬，径自走开了。\n",ob);
		destruct(ob);
		return 1;
	}
	if (!pl=find_player(user))
	{
		message_vision("$N见无人理睬，径自走开了。\n",ob);
		destruct(ob);
		return 1;
	}
	if (!pl->query_temp("hsnewbiejob/xunlian_target"))
	{
		message_vision("$N见无人理睬，径自走开了。\n",ob);
		destruct(ob);
		return 1;
	}
	if (pl->query_temp("hsnewbiejob/xunlian_target")!=ob)
	{
		message_vision("$N见无人理睬，径自走开了。\n",ob);
		destruct(ob);
		return 1;
	}
	remove_call_out("check_me");
	call_out("check_me",60);
	return 1;
}
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	    string color1=color[random(sizeof(color))];
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("long",
"华山派新弟子\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 2000);
        set("score", 100);
        set("random_npc",1);
        set_skill("force", 20);
        set_skill("huashan-neigong", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("sword", 20);
//      set_skill("huashan-jianfa", 60);
        map_skill("force", "huashan-neigong");
//      map_skill("parry", "huashan-jianfa");
//      map_skill("sword", "huashan-jianfa");
        create_family("华山派", 22, "弟子");
         set("inquiry", ([
        "gen":   (: ask_gen() :),
        "跟随":   (: ask_gen() :),
        "指点":   (: ask_gen() :),
		"指教" : (: ask_gen() :),
      ]));
        setup();
        carry_object("/clone/weapon/changjian")->wield();
		call_out("chck_me",60);
}

void init()
{
    add_action("do_zhidian","zhidian");
}


int do_zhidian(string arg)
{
    object ob=this_object();
    object me=this_player();
    int n=1+random(5);
	if (!arg) 
	{
		tell_object(me,"你要指点谁啊？\n");
		return 1;
	}
	if (member_array(arg,ob->parse_command_id_list())==-1) return 0;
    if (!me->query_temp("hsnewbiejob/xunlian"))
    return 0;
    if (me->query("id")!=ob->query("owner"))
    {
        tell_object(me,ob->query("name")+"转过了头去，根本不理睬你。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (base_name(environment(me))!="/d/huashan/liangong")
    {
        tell_object(me,"这里人多嘈杂，不是个合适的练功场所。\n");
        return 1;
    }
    if (me->query_temp("hsnewbiejob/xunlian/degree")>50)
    {
        tell_object(me,ob->query("name")+"一招一式有板有眼，你可以回去和宁中则复命了。\n");
        message_vision("$N对$n挥了挥手，$n转身离去了。\n",me,ob);
        destruct(ob);
        return 1;
    }
    message_vision(HIM"$N开始指点$n华山派的武学。\n"NOR,me,ob);
    me->add_busy(1+random(2));
    me->add_temp("hsnewbiejob/xunlian/degree",2+random(2));
    if (random(5))
    {
        tell_object(me,"在指点弟子练功中，你印证心中所学，经验增加了"+chinese_number(n)+"点。\n");
        me->add("combat_exp",n);
        me->add("exp/hsnewbiejob", n);
    }
    if (random(100)>83&&(int)me->query_temp("hsnewbiejob/xunlian/bugen")<3)
    {
        me->add_temp("hsnewbiejob/xunlian/bugen",1);
        bugen(me);
    }
    return 1;
}

int gen(object me)
{
    command("follow "+me->query("id"));
    return 1;
}

int ask_gen()
{
    object ob=this_object();
    object me=this_player();
    if (!me->query_temp("hsnewbiejob/xunlian"))
    {
        return 0;
    }
    if (me->query("id")!=ob->query("owner"))
    {
        tell_object(me,ob->query("name")+"转过了头去，根本不理睬你。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢\n");
        return 1;
    }
    if (random(100)<55)
    {
        message_vision("$N道：休息一会行不行啊？\n",this_object());
        return 1;
    }
    message_vision("$N道：好吧，好吧，我回去还不行吗？\n",this_object());
    me->add_busy(random(2));
    gen(me);
    return 1;
}
int bugen(object me)
{
    object ob=this_object();
    object where;
    while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
          where->query("no_hsnewbiejob"))
        {where=TASK_D->random_room("/d/huashan/");}
    command("follow none");
    message_vision("$N趁$n不注意，一溜烟不知道跑到哪里去了。\n",ob,me);
    ob->move(where);
    if (wizardp(me))
    {
        tell_object(me,where->query("short"));
    }
    return 1;
}