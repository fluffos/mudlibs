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
    set("title", HIG"接头人"NOR);
    set("gender", "男性");
    set("age", 20+random(20));
    set("long", "他看上去像是一个猎人，短小精悍，抽着一杆大眼袋，丝毫没有出奇之处。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",200000);

    
	set("inquiry", ([
	
     "jietou": (: ask_tasks :),
     "接头": (: ask_tasks :),
    
	]));

    setup();
   
}

int ask_tasks()
{
    object me=this_player();
    if (me->query_temp("songtasks/shuishi/task")!=1)
    {
        return notify_fail("你是不是想死？这里是太湖水匪聚居之地，快逃吧。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    else
    {
        message_vision("$N道：既有水师大都督之令，我且助你一臂之力。\n",this_object());
        tell_object(me,this_object()->query("name")+"把你引入水贼营寨。\n");
        me->move("/d/suzhou/shuizeiying");
        return 1;
    }
}

