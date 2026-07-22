#include <ansi.h>;

inherit ITEM;

string wanted();
int do_arrest(string);

void create()
{
        set_name(HIY"官府文书"NOR, ({ "guanfu wenshu", "wenshu", }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("value", 0);
                set("no_drop", 1);
                set("material", "paper");
        }
        set("long", wanted());
        setup();
}

void init()
{
        add_action("do_arrest","arrest");
        add_action("do_arrest","jubu");
}

int sort_killer(object obj)
{
	if ( SECURITY_D->get_status(obj) != "(player)" ) return 0;
        if ( (int)obj->query("PKS") < 50 ) return 0;
        if ( obj->query("combat_exp") / obj->query("PKS") > 350000 ) return 0;
        if ( base_name(environment(obj)) == "/d/city/dalao") return 0;
	return 1;
}

int sort_pks(object ob, object obj)
{
	if ( ob->query("PKS") < obj->query("PKS") ) return 0;
        return 1;
}

string wanted()
{
        int i, age;
        string msg;
        object *ob = users();

        msg = "";
        ob  = filter_array( users(), (: sort_killer :) );
        ob  = sort_array(ob, (: sort_pks :));
        
        for (i = 0; i < sizeof(ob); i++){
        	msg += "\n「"+chinese_number(i+1)+"」"+ob[i]->short(1)+"\n";
                msg += HIR"\t该逃犯";
                age = ob[i]->query("age");
                if (ob[i]->query_skill("beauty") > 30) age -= (ob[i]->query_skill("beauty")-30)/5;
                if (age < 10)
                	msg += "看起来不到十岁，";
                else	msg += "看起来约"+chinese_number(age / 10 * 10)+"多岁，";
                msg += "共犯下"+chinese_number(ob[i]->query("PKS"))+"桩命案。\n"NOR;
		msg += "\t该逃犯武艺看上去似乎"+"/cmds/std/look"->gettof(ob[i], age)+"，要小心在意！\n";
                msg += "──────────────────────────────\n";
        }
        if (msg == "")
                return "近日本府治安良好，无可疑人物出入。\n";
        else
                return HIY"现在本府正在悬赏缉拿(arrest)以下要犯：\n"NOR + msg;
}

int do_arrest(string arg)
{
        object me=this_player(), victim;

        if (!me->query_temp("mark/巡捕"))
        	return notify_fail("小小草民也想拘捕别人？\n");

        if (!arg)
        	return notify_fail("你要拘捕谁？\n");

        victim = present(arg,environment(me));

        if (!victim)
        	return notify_fail("这里并无此人！\n");

        if (victim == me) 
                return notify_fail("想抓自己？何必多此一举？\n");

        if (!living(victim))
                return notify_fail("你眼睛瞎了？那可不是活物！\n");

        if (!(userp(victim)
                && victim->query("PKS")>50
                && victim->query("combat_exp")/victim->query("PKS") < 350000))
                return notify_fail("此人不是凶犯！\n");

        message_vision(HIC"$N对$n高喊一声："+RANK_D->query_rude(victim)+"作恶多端，我奉朝廷之命缉拿你！还不束手就擒？！\n"NOR, me, victim);

        if (victim->is_fighting()) 
                victim->remove_all_killer();

        victim->kill_ob(me);
        me->fight_ob(victim);
        return 1;
}
