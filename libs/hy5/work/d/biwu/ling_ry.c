// gangzhang.c 钢杖
#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name(HIR"日月神令"NOR, ({ "ryling" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块日月教的令牌。你可以战斗中召唤(zhao)护卫。恢复(huifu)自己或他人。\n");
		set("no_put",1);
		set("armor_prop/intelligence",5);
		set("armor_prop/strength",5);
		set("armor_prop/karey",5);
		set("armor_prop/percao",5);
		set("armor_prop/dexerity",5);
		set("armor_prop/constitution",5);set("armor_prop/armor", 200); set("armor_prop/damage",200);
		set("no_get",1);
		set("no_drop",1);
		set("rigidity",100);
		set("material", "steel");
		set("no_put",1);
		set("no_get",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_steal",1);	
	}
	setup();
}
int query_autoload() { return 1; }void init()
{
string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion_ry.o");
	if (!info) call_out("destroying", 0); 
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) call_out("destroying", 0); 
}	
	
	add_action("do_zhao","zhao");
	add_action("do_zhao2","huifu");	
}


int do_zhao2(string str)
{
object dizi,me,me2;
int exp;
    int i;
    object obj;
string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion_ry.o");
	if (!info) call_out("destroying", 0); 
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) call_out("destroying", 0); 
}
me = this_player();
me2= this_player();


   if (me->query("jing")<100) 
	return notify_fail("你精不够。\n");

        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚用过这个信物.\n");
    
    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("对象错误: 找不到"+str+"\n");

me=obj;

if( !userp(me) && !wizardp(me2)) 
	return notify_fail("只能对玩家使用这个信物！\n");
if( (string)me->query("family/family_name") != (string)me2->query("family/family_name") ) 
	return notify_fail("只能对本派人员使用这个信物！\n");

if ( me2->is_busy() )
        return notify_fail("现在正忙得不得了？\n");
        
if ( me->is_busy() )
        return notify_fail("现在正忙得不得了？\n");

	me->set("jing",me->query("max_jing"));me->set("eff_jing",me->query("max_jing"));
	me->set("qi",me->query("max_qi"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("neili",me->query("max_neili"));

	me2->apply_condition("zdizi_busy",3);
	message_vision(GRN "\n$N的气血和精力，顺间得到了恢复！\n" NOR, me);	

	return 1;
}
void destroying(){destruct(this_object());   }int do_zhao()
{
object dizi,me;
int exp;
string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion_ry.o");
	if (!info) call_out("destroying", 0); 
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) call_out("destroying", 0); 
}
me = this_player();
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚招过随身弟子.\n");
   if( (int)me-> query_temp("number") > 0 )
     return notify_fail("你最多只能召唤一名随身弟子。\n");
   if (me->query("jing")<100) 
	return notify_fail("你精不够。\n");
 if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
if ( me->is_busy() )
        return notify_fail("你现在正忙得不得了，还有心思召唤你的弟子？\n");
	exp = (int)me->query("combat_exp");
	me->receive_damage("jing",100);
	dizi = load_object("/d/biwu/dizi.c");
	dizi->move(environment(me));
        dizi->invocation(me, (exp));
        dizi->set("possessed", me);
	 dizi->set_name(this_player()->query("name")+"的随身弟子",({"dizi"}));
        me->add_temp("number",1);
//        me->remove_all_killer();
	message_vision(CYN "\n$N发出号令，召唤身边的弟子来保护自己！\n" NOR, me);	
	message_vision(CYN "\n$N的弟子随着号令声而来！\n" NOR, me);
	return 1;
}
