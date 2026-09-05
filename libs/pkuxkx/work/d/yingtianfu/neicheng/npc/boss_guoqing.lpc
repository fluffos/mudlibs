//boss1 ,zine

#include <ansi.h>
inherit NPC;
void create()
{ 
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	    string color1=color[random(sizeof(color))];
        string* title=({"汉奸","国贼","奸党"});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",color1+title[random(sizeof(title))]+NOR);
        set("gender", "男性" );
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1); 
       	set("max_qi", 1000000);
        set("eff_qi", 1000000);
        set("qi", 1000000);
        set("max_jing", 6000000);
        set("jing", 6000000);
        set("neili", 1);
        set("max_neili", 1);
        set("jingli",500000);
        set("max_jingli",250000);
        set("jiali", random(2));
        set("combat_exp", 1000000);
        set("id_no",random(10000));
        set_skill("force", 500);             // 基本内功
       
        
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("moving",1);
        call_out("dest",3600);
}

int moving()
{
    string place;
    random_move();
    place=environment(this_object())->query("short");
    if ((!this_object()->is_fighting()||!random(10))&&place)
    {
        message( "channel:" + "chat",MAG + "【国庆活动】有人看见"+this_object()->query("title") +MAG+ this_object()->query("name")+MAG+"在"+place+"附近出没，大家快去干掉他吧。\n"NOR,users());
    }
    remove_call_out("moving");
    call_out("moving",15+random(10));
    return 1;
}

void init()
{
    add_action("do_perform","perform");
}

int do_perform(string arg)
{
    object me=this_player();
    string martial,action,target;
    if( sscanf(arg, "%s.%s", martial, arg)!=2 ) 
        return notify_fail("指令格式 perform martial.action [target]\n");
    if( sscanf(arg, "%s %s", action, target)==2 )
    {
        if (action=="feilong"||action=="feihua"||action=="cixue"||action=="leiting"||action=="yizhi")
        {
            return notify_fail("你无法对"+this_object()->query("name")+"使用一招晕。\n");
        }
    }
    else
    {
        if (arg=="feilong"||arg=="feihua"||arg=="cixue"||arg=="leiting"||arg=="yizhi")
        {
            return notify_fail("你无法对"+this_object()->query("name")+"使用一招晕。\n");
        }
    }
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
    }
    return 1;
}

int start_busy()
{
    return 1;
}

int add_busy()
{
    return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
    int id_no=this_object()->query("id_no"), ret=0;
    object killer;

    if (damage>5000)
    {
        damage=5000;
    }

    ret=::receive_damage(type, damage, who);
    killer=get_damage_origin_object();

	if(objectp(killer) && userp(killer))
    {
	    killer->add_temp("guoqing_credit_1", damage);				
	}
	return ret;
}

void die()
{
    object *all_player;
    int index,i,exp,pot,id_no=this_object()->query("id_no");
    all_player = filter_array(children(USER_OB), (: userp :));
    all_player = filter_array(all_player, (: environment :));
    all_player = filter_array(all_player, (: $1->query_temp("guoqing_credit_1") :) );
    if (sizeof(all_player)<=10)
    {
        index=1;
    }
    else if (sizeof(all_player)<=30)
    {
        index=2;
    }
    else if (sizeof(all_player)<=50)
    {
        index=3;
    }
    else
    {
        index=4;
    }
    for (i=0;i<sizeof(all_player);i++)
    {
        exp=all_player[i]->query_temp("guoqing_credit_1")*index;
        pot=exp/2;
        all_player[i]->add("combat_exp",exp);
        all_player[i]->add("potential",pot);
        tell_object(all_player[i],MAG+"『国庆活动』打败"+this_object()->query("name")+"后，你获得了"+chinese_number(exp)+"点经验。\n"+NOR);
        tell_object(all_player[i],MAG+"『国庆活动』打败"+this_object()->query("name")+"后，你获得了"+chinese_number(pot)+"点潜能。\n"+NOR);
        all_player[i]->delete_temp("guoqing_credit_1");
    }
    destruct(this_object());
    return;
}