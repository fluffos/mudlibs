#include <ansi.h>
inherit COMBINED_ITEM;

void setup(){}

void create() 
{
	string long;
	set_name("须弥石", ({ "ling shi","shi","stone" }));
        set_weight(50);
        long = "三界灵石，具有将装备封于芥子空间的效果。使用它来绑定(bangding)对应的装备，即可通过zhaohuan命令来召唤存于芥子空间中的装备。\n相关命令：help zhaohuan\n";
        long = sort_string(long,64,0);
        set("long",long);
        set("changed",1);
       	set("unit", "些");
       	set("base_unit","颗");
	set("value", 0);
      	setup();
      	set_amount(1);
}

void init() 
{
	add_action("do_bd","bangding");
}

string short(int v)
{
	string arg,str = ::short(v);
	if( !stringp(arg=query("from"))
	 || strlen(arg)<2 )
	 	return str;
	str+= "("+arg+")";
	return str;
}	

int do_bd(string arg)
{
	mapping my,his;
	string *prop,*ids,name;
	int i,max;
	object obj,target,me = this_player();
	
	if( !present(this_object(),me) )
		return 0;
	if( !arg )
		return err_msg("你要绑定什么？\n");
	target = present(arg,me);
	if( !target )
		return err_msg("你身上没有"+arg+"。\n");
	if( !target->is_armor() && !target->is_weapon() )
		return err_msg("你只能绑定装备。\n");
	if( target->query("equipped") )
		return err_msg("你得先将它卸除。\n");
	if( target->query("owner_id") )
	{
		if( target->query("owner_id")!=me->query("id") )
			return err_msg("这不是你的装备。\n");
	}
	if( query("from") )
	{
		if( !target->query("from") || target->query("from")!=query("from") )
			return err_msg("你只能用它绑定"+query("from")+"的装备。\n");
	}
	else if( target->query("from") )
		return err_msg(target->short()+"是出自于"+target->query("from")+"，你必须用"+target->query("from")+"中得到的芥子石才能绑定她。\n");
		
	if( (me->query("potential")-me->query("learned_points"))<500 )  
		return err_msg("你需要消耗500点潜能。\n");
	if( me->is_busy() )
		return err_msg("你现在正忙着呢。\n");
	
	max = me->query_level()/3+1;
		
	if( wizardp(me) && me->query("env/test") )
		max = 2;
	if( wizardp(me) )
		tell_object(me,"绑定上限为"+max+"。\n");
	if( sizeof(me->query("euqips"))>=max )
		return err_msg("你目前的人物等级，只能绑定 "HIR+max+NOR" 个装备。\n");	
		
	if( target->is_armor() )
	{
		obj = new("/obj/armor");
		obj->set("armor_type",target->query("armor_type"));
	}
	else
	{
		obj = new("/obj/weapon");
		obj->set("skill_type",target->query("skill_type"));
	}
	name = target->query("name");
	ids = target->query_my_id();
	obj->set_name(name,ids);
	obj->set("ids",ids);
	obj->set("names",name);
	my = target->query_entire_dbase();
	his = obj->query_entire_dbase();
	prop = keys(my);
	for(i=0;i<sizeof(prop);i++)
	{
		if( prop[i]=="name" || prop[i]=="id" 
		 || prop[i]=="valid_time" )
			continue;
		obj->set(prop[i],my[prop[i]]);	
	}
	obj->set("owner_id",me->query("id"));
	obj->setup();
	obj->move(me);
	if( !obj->to_save() )
	{
		if( obj )
			destruct(obj);
		return err_msg("绑定失败。\n");
	}
	write(HIY"【系统】绑定成功！你可以通过"HIR" zhaohuan "HIY"命令来获得你绑定的装备。\n"NOR);
	destruct(target);
	destruct(obj);
	if( query_amount()<=1 )
		destruct(this_object());
	else	add_amount(-1);	
	return 1;
}			