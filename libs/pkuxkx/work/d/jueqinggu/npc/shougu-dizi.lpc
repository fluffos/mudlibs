
#include <ansi.h>
inherit NPC;
int ask_quest();

void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"守谷弟子"+NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 20+random(10));
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("random_npc",1);
	set("inquiry", ([
			"离谷" : (: ask_quest :),
            "out" : (: ask_quest :),
            "leave" : (: ask_quest :),
            "离开" : (: ask_quest :),
       	]) );

	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();

}
int leave_me(object me)
{
    object ob=this_object();
    me->delete_temp("jueqinggu/leave");
    if (me->is_busy())
    {
        tell_object(me,ob->query("name")+"道：既然你还忙着，我也没办法赶人啊。\n");
        return 1;
    }
    else if (base_name(environment(me))!=base_name(environment(this_object())))
    {
        tell_object(me,ob->query("name")+"大喊：人呢？人呢？\n");
        return 1;
    }
    else
    {
        me->move("/d/jueqinggu/xiaolu");
        tell_object(me,ob->query("name")+"送你到谷口，就此别过。\n");
        return 1;
    }
}


int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("jueqinggu/leave"))
    {
        tell_object(me,"你不是刚问过吗？\n");
        return 1;
    }
    message_vision("$N对$n说："+ob->query("name")+"奉家师命，恭送阁下离谷。\n",ob,me);
    me->set_temp("jueqinggu/leave",1);
    me->add_busy(1);
    call_out("leave_me",3,me);
    return 1;
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}