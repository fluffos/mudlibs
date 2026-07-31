// gangzhang.c 钢杖

#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
	set_name(HIY"神杖"NOR, ({ "shenstaff" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根象征正义的神杖，上面刻着“自古今来，邪不胜正”。你可以战斗中召唤(zhao)护卫。恢复(huifu)自己或他人。\n");
		set("no_put",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_steal",1);
//		set("value", 1500);
		set("rigidity",100);
		set("armor_prop/intelligence",15);
		set("armor_prop/strength",15);
		set("armor_prop/dexterity",15);
		set("armor_prop/constitution",15);set("armor_prop/armor", 600); set("armor_prop/damage",600);
		set("armor_prop/karay",15);
		set("armor_prop/percao",15);
		set("material", "steel");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  
	setup();
}

int query_autoload() { return 1; }

void init()
{
	string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion.o");
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
me = this_player();
me2= this_player();

	info = read_file("/data/npc/champion.o");
	if (!info) {call_out("destroying", 0);return 0;}
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) {call_out("destroying", 0);return 0;} 
}
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

if( (int)me->query("shen",1) <=0 ) 
	return notify_fail("只有正派才能承受这个信物！\n");
	
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


int do_zhao()
{
object dizi,dizi1,dizi2,me;
int exp;
 string info,name,id,file,infoa,infob;
me = this_player();

	info = read_file("/data/npc/champion.o");
	if (!info) {call_out("destroying", 0);return 0;}
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) {call_out("destroying", 0);return 0;} 
}

        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚招过随身弟子!!\n");


//   if( (int)me-> query_temp("number") > 0 )
//     return notify_fail("你最多只能召唤一名随身弟子。\n");
   if (me->query("jing")<100) 
	return notify_fail("你精不够。\n");
 if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
if ( me->is_busy() )
        return notify_fail("你现在正忙得不得了，还有心思召唤你的弟子？\n");
	exp = (int)me->query("combat_exp");
	me->receive_damage("jing",100);
	dizi = new("/d/biwu/dizi.c");
	dizi->move(environment(me));
        dizi->invocation(me, (exp));
        dizi->set("possessed", me);
	 dizi->set_name(this_player()->query("name")+"的随身弟子",({"dizi"}));


	dizi1 = new("/d/biwu/dizi.c");
	dizi1->move(environment(me));
        dizi1->invocation(me, (exp));
        dizi1->set("possessed", me);
	 dizi1->set_name(this_player()->query("name")+"的护法弟子",({"dizi"}));


	dizi2 = new("/d/biwu/dizi.c");
	dizi2->move(environment(me));
        dizi2->invocation(me, (exp));
        dizi2->set("possessed", me);
	 dizi2->set_name(this_player()->query("name")+"的掌刑弟子",({"dizi"}));

          me->add_temp("number",1);      

        me->apply_condition("zdizi_busy",12);
                
//        me->remove_all_killer();
	message_vision(CYN "\n$N发出号令，召唤身边的弟子来保护自己！\n" NOR, me);	
	message_vision(CYN "\n$N的弟子随着号令声而来！\n" NOR, me);
	return 1;
}
void destroying(){destruct(this_object());   }