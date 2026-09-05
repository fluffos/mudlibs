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
    set("title", HIW"太湖水匪"NOR);
    set("gender", "男性");
    set("age", 20+random(20));
    set("long", "这是一个相貌狰狞的太湖水匪，脸上好长的一道刀疤，正双目警惕地看着你。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",2000000);

    
	set("inquiry", ([
	
     "caolian": (: ask_tasks :),
     "操练": (: ask_tasks :),
    
	]));

    setup();
   
}

int ask_tasks()
{
    object me=this_player();
    if (me->query_temp("songtasks/shuishi/task")!=1)
    {
        return notify_fail("小皮猴子，操练我？大爷我先操练操练你。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("songtasks/shuishi/scaolian_degree")>50)
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
   
    add_action("do_caolian","caolian");
    
}

int gen(object me)
{
    object ob=this_object();
    tell_object(me,"水军已成，你和众水军踏上战船，准备回师临安府。\n");
    me->set_temp("songtasks/shuishi/warship",1);
    me->move("/d/suzhou/warship");
    
    destruct(ob);
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
    if (me->query_temp("songtasks/shuishi/task")!=1)
    {
        return notify_fail("小皮猴子，操练我？大爷我先操练操练你。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    message_vision("$N舞起旌旗，做着各种手势。\n",me);
    if (me->query_temp("songtasks/shuishi/scaolian_degree")>50)
    {
        
        message_vision(HIR"群雄在$N的指挥下，船头齐进，乘风破浪，喊杀震天，$N站在船头，威风凛凛，感慨万端。\n"NOR,me);
        remove_call_out("gen");
        call_out("gen",2,me);
        return 1;
    }
    me->add_busy(3);
    me->add_temp("songtasks/shuishi/scaolian_degree",n);
    message_vision("群雄在$N的指挥下，却各自胡乱开船，如苍蝇乱撞般碰在一起，纷纷落水。\n",me);
    return 1;
}