// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "三生石" NOR, ({ "sansheng shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的三生石，据说吃了可以转世为生。\n");
                set("value", 0);
                set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
obj=this_player();
        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

if ( !obj->query("zhuanshen"))
{
  obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
                obj->set("combat_exp",300000);
            obj->set("potential",obj->query("learned_points")+100000);
// 1
        if ( obj->query("per")+10 > 50)
        {
	obj->set("per",50);
        }
        else obj->set("per",obj->query("per")+10);

//2
        if ( obj->query("str")+10 > 50)
        {
	obj->set("str",50);
        }
        else obj->set("str",obj->query("str")+10);

//3
        if ( obj->query("dex")+10 > 50)
        {
	obj->set("dex",50);
        }
        else obj->set("dex",obj->query("dex")+10);

//4
        if ( obj->query("int")+10 > 50)
         {
	obj->set("int",50);
        }
        else obj->set("int",obj->query("int")+10);

//5
        if ( obj->query("con")+10 > 50)
        {
	obj->set("con",50);
        }
        else obj->set("con",obj->query("con")+10);


//6
        if ( obj->query("kar")+10 > 50)
        {
	obj->set("kar",50);
        }
        else obj->set("kar",obj->query("kar")+10);

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("blade_get");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
        obj->save();
obj->set("tforceok",2);
    write(HIR"一转成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"转生成功,请重新登陆!\n"NOR);
	log_file("static/ZS",
		sprintf("%s 一转，时间: %s\n", geteuid(obj), ctime(time())) );
"/cmds/usr/quit"->main(obj);
destruct(this_object());

return 1;
}

    if ( obj->query("zhuanshen") && !obj->query("guard/flag"))
{
  obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
        if ( obj->query("per") < 60)
        {
	obj->set("per",obj->query("per")+10);
        }
        if ( obj->query("str") < 60)
        {
	obj->set("str",obj->query("str")+10);
        }
        if ( obj->query("dex")< 60)
        {
	obj->set("dex",obj->query("dex")+10);
        }
        if ( obj->query("int")< 60)
        {
	obj->set("int",obj->query("int")+10);
        }
        if ( obj->query("con")< 60)
        {
	obj->set("con",obj->query("con")+10);
        }
        if ( obj->query("kar")< 60)
        {
	obj->set("kar",obj->query("kar")+10);
        }

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));

obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
//obj->delete("jiuyin");
//obj->delete("szj");
//obj->delete("zhou");
obj->set("guard/flag",1);
obj->set("tforceok",2);
        obj->save();
    write(HIR"二转成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"转生成功,请重新登陆!\n"NOR);
	log_file("static/ZS",
		sprintf("%s 二转，时间: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"二转了。");
	"/cmds/usr/quit"->main(obj);
        destruct(this_object());

	return 1;
}

    if ( !obj->query("zhuanbest") && obj->query("guard/flag"))
{
obj->delete("last_alert");
   obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
        if ( obj->query("per") < 60)
        {
	obj->set("per",obj->query("per")+10);
        }
        if ( obj->query("str") < 60)
        {
	obj->set("str",obj->query("str")+10);
        }
        if ( obj->query("dex")< 60)
        {
	obj->set("dex",obj->query("dex")+10);
        }
        if ( obj->query("int")< 60)
        {
	obj->set("int",obj->query("int")+10);
        }
        if ( obj->query("con")< 60)
        {
	obj->set("con",obj->query("con")+10);
        }
        if ( obj->query("kar")< 60)
        {
	obj->set("kar",obj->query("kar")+10);
        }

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));

obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
//obj->delete("jiuyin");
//obj->delete("szj");
//obj->delete("zhou");
obj->set("guard/flag",1);
obj->set("tforceok",2);
        obj->save();
    write(HIR"三转成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"转生成功,请重新登陆!\n"NOR);
if (obj->query("zhuanbest"))
{
	log_file("static/ZS",
		sprintf("%s 三转，时间: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"三转了。");
}
	"/cmds/usr/quit"->main(obj);
        destruct(this_object());

	return 1;
}
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        destruct(this_object());
	return 1;

}
