
#include <ansi.h>
inherit ITEM;
#include "/d/suzhou/npc/lchj.h";

void create()
{
        set_name(HIG"唐诗选辑"NOR, ({ "tangshi xuanji", "book","tangshi", "xuanji"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", HIY"一本很普通的唐诗选辑。只是封面有些破旧。\n"NOR); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
        }
}
void init()
{
        add_action("do_jinpao", "jinpao");
        add_action("do_jinpao", "pour");
        add_action("do_du", "read");
     	add_action("do_fan", "fan");	
     	add_action("do_fan", "find");
	    add_action("do_lingwu", "study");
        add_action("do_lingwu", "lingwu");
}
int do_jinpao(string arg)
{
	string hehe, what;
	object me, ob, obj;
	object *player;
	int i;

	ob = this_object();
	me = this_player();
	player = all_inventory(environment(me));	
	if( !arg ||  sscanf(arg, "%s in %s", hehe, what) != 2 )
		return notify_fail("命令：jinpao <> in <>\n");

	if(hehe!="book" && hehe!="tangshi xuanji" && hehe!="tangshi" && hehe!="xuanji")
		return notify_fail("你要浸泡唐诗选辑不是吗？\n");

	if( me->is_busy() ) 
		return notify_fail("你正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你正在战斗中！\n");
	if(!me->query(QUESTDIR2+"over")) 
		return notify_fail("你似乎什么也发现不了。\n");
        if(me->query_temp(QUESTDIR2+"find_zi")) 
		return notify_fail("你已经发现了其中的秘密。\n");
	if(query("look_zi")) 
		return notify_fail("你已经发现了其中的秘密。\n");

	if( !objectp( obj = present(what, me)))  
		return notify_fail("你身上没有"+what+"，你要放在哪里？\n");

	if( !obj->query("liquid/type"))    
		return notify_fail(obj->name()+"不是器皿！\n");
	if( obj->query("liquid/type")!="water")    
		return notify_fail(obj->name()+"盛的不是水！\n");
	if( !obj->query("liquid/remaining") )    
		return notify_fail(obj->name() + "里面已经一滴不剩了。\n");
	
	for (i = 0; i < sizeof(player); i++) {
				if (living(player[i]) && player[i] != me) 
				{
				   if(me->query("family/master_name")==player[i]->query("family/master_name"))
				       return notify_fail(HIY"这里正巧有一个你的同门弟子"+player[i]->query("name")+HIY"，虽然"+ob->query("name")+HIY"不算什么极品宝物，但还是小心为好。\n"NOR);
				   else if(userp(player[i]) && player[i]->query("shen")<0)
				       return notify_fail(HIY"这里竟然有一个负神的江湖人物，"+HIY"，"+ob->query("name")+HIY"虽然不算什么极品宝物，但还是小心为好。\n"NOR);
           else if(userp(player[i]))
				       return notify_fail(HIY"正巧"+player[i]->query("family/master_name")+HIY"的弟子"+player[i]->query("name")+HIY"竟然也在这里，"+ob->query("name")+HIY"虽然不算什么极品宝物，但还是小心为好。\n"NOR);
		       else return notify_fail(HIY"这里正巧有一个"+player[i]->query("title")+player[i]->query("name")+HIY"，虽然"+ob->query("name")+"不算什么极品宝物，但还是小心为好。\n"NOR);
				}
			}         	  	

	message_vision(YEL"$N仔细地将书浸泡在"+ obj->name() +"里的清水之中。\n"NOR,me);
	call_out("look_zi",5,me);
	me->start_busy(5);
	obj->add("liquid/remaining", -1);
	return 1;
}
void look_zi(object me)
{

	object ob;
	object *player;
	int i;
	ob = this_object();
	if(!me) return;
	if(query("look_zi")) return;
	player = all_inventory(environment(me));	
	for (i = 0; i < sizeof(player); i++) {
				if (living(player[i]) && player[i] != me) 
				{
				   if(me->query("family/master_name")==player[i]->query("family/master_name"))
				       tell_object(me,HIY"这里正巧有一个你的同门弟子"+player[i]->query("name")+HIY"，虽然"+ob->query("name")+HIY"不算什么极品宝物，但还是小心为好。\n"NOR);
				   else if(userp(player[i]) && player[i]->query("shen")<0)
				       tell_object(me,HIY"这里竟然有一个负神的江湖人物，"+HIY"，"+ob->query("name")+HIY"虽然不算什么极品宝物，但还是小心为好。\n"NOR);
           else if(userp(player[i]))
				       tell_object(me,HIY"正巧"+player[i]->query("family/master_name")+HIY"的弟子"+player[i]->query("name")+HIY"竟然也在这里，"+ob->query("name")+HIY"虽然不算什么极品宝物，但还是小心为好。\n"NOR);
		       else tell_object(me,HIY"这里正巧有一个"+player[i]->query("title")+player[i]->query("name")+HIY"，虽然"+ob->query("name")+"不算什么极品宝物，但还是小心为好。\n"NOR);
		       return;
				}
			}         	  	

	message_vision(HIY"\n一会的功夫，唐诗选辑上竟然显示一些数字出来。$N取过一支秃笔，在一张黄纸上写了“江\n"
		             +"陵城南”四个字，口中轻轻念着“一五、一十、十五、十六……第十六个字”，跟着在纸上写\n"
					 +"个“偏”字。$N查一会书，屈指计一会数，便写一个字，一共写了二十六个字，见是：\n\n"
					 +"“"NOR+HIG"       西天宁寺大殿佛像向之虔诚膜拜通灵祝告如来赐福往生极乐"NOR+HIY"       ”\n\n"NOR,me);
	set("look_zi",1);
	me->set_temp(QUESTDIR2+"find_zi",1);
	return;
}
	

int do_du(string arg)
{
	object me = this_player();
	if( me->is_busy()) 
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() ) 
		return notify_fail("你现在正忙着呢。\n");
	tell_object(me,YEL"你研读了一会儿，觉得什么都无法从中学习领悟。\n"NOR);

	return 1;
}

int do_fan(string arg)
{
 	object me = this_player();
	if( me->is_busy()) 
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() ) 
		return notify_fail("你现在正忙着呢。\n");
	tell_object(me,YEL"你翻了一会儿，觉得什么都没有发现。\n"NOR);
	return 1;
}

int do_lingwu(string arg)
{
	object me = this_player();
	if( me->is_busy()) 
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() ) 
		return notify_fail("你现在正忙着呢。\n");
	tell_object(me,YEL"你研读了一会儿，觉得什么都无法从中学习领悟。\n"NOR);
	return 1;
}
