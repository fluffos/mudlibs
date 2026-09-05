//城门
// By Zine 23 Nov 2010

inherit NPC;
#include <ansi.h>
int ask_tasks();
void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title", HIG"绿林豪侠"NOR);
    set("gender", "男性");
    set("age", 20+random(20));
    set("long", "这是一个相貌狰狞的绿林豪侠，脸上好长的一道刀疤，正双目警惕地看着你。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",3);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",2000000);
	set("dasong_bing",0);
    
	set("inquiry", ([
	
     "caolian": (: ask_tasks :),
     "操练": (: ask_tasks :),
    
	]));
	set("no_get",query("name")+"实在吃得太胖了，你扛不起来。\n");
    setup();
	carry_object("clone/cloth/cloth")->wear();
}
int DASONG_BING()
{
	return query("dasong_bing");
}
int ask_tasks()
{
    object me=this_player();
    if (me->query_temp("songtasks/longwei/task")!=1)
    {
        return notify_fail("小皮猴子，操练我？大爷我先操练操练你。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("songtasks/longwei/lcaolian_degree")>50)
    {
        tell_object(me,"不是练完了吗？俺等着拿军饷呢。\n");
        return 1;
    }
    else
    {
        tell_object(me,"不必多说，要操练(caolian)快来。\n");
        return 1;
    }
}

void init()
{
    object ob=this_object();
    object me;
    add_action("do_caolian","caolian");
    if (ob->query("owner"))
    {
        me=find_player(ob->query("owner"));
    }
    if (!me)
    {
        destruct(ob);
        return;
    }
    if (me->query_temp("songtasks/longwei/task")!=1)
    {
        destruct(ob);
        return;
    }
    if (base_name(environment(ob))=="/d/hangzhou/xiongwu"
        &&me->query_temp("songtasks/longwei/lcaolian_degree")>50)
    {
        message_vision("$N向$n抱拳道：青山不改，绿水长流，我们后会有期！\n",ob,me);
        message_vision("$N转身走进了军营。\n",ob);
        me->set_temp("songtasks/longwei/1/finish",1);
        destruct(ob);
        return;
    }
}

int gen(object me)
{
    object ob=this_object();
    message_vision(HIC"$N穿戴好盔甲，骑上战马，列队跟上"+me->query("name")+"。\n"NOR,ob);
    command("follow " + me->query("id"));
    tell_object(me,"新军即成，你把他们带到雄武营去吧。\n");
	set("long", "这是一个新近被收编的大宋官兵。\n");
	set("dasong_bing",1);
    return 1;
}

int do_caolian()
{
    object me=this_player();
    object ob=this_object();
    int n=1+random(5);
    if (ob->query("owner")!=me->query("id"))
    {
        return notify_fail("小皮猴子，操练我？大爷我先操练操练你。\n");
    }
    if (me->query_temp("songtasks/longwei/task")!=1)
    {
        return notify_fail("小皮猴子，操练我？大爷我先操练操练你。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    
    message_vision("$N开始指挥这群乌合之众演练阵型。\n",me);
    if (me->query_temp("songtasks/longwei/lcaolian_degree")>50)
    {
        
        message_vision(HIR"$N穿上盔甲，跨上战马，长枪一指，群雄齐头并进，气势汹汹，喊杀震天，好不威武！\n"NOR,me);
        gen(me);
        return 1;
    }
    me->add_busy(3);
    me->add_temp("songtasks/longwei/lcaolian_degree",n);
    message_vision("$N穿上盔甲，跨上战马，长枪一指，群雄面面相觑，紧接着哄堂大笑，将江湖散勇的泼赖作风发挥到了极致。\n",me);
    return 1;
}