 
#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(RED "南海仙芝嫩芽" NOR, ({"xian zhi","xian","zhi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗紫红色的小草。\n");
		set("value", 0);
		set("drug_type", "补品");
  	}
  
	set("is_monitored",1);
	setup();
}
void init()
{
    set("no_get", "你拿不起来这样东西。试试挖挖(dig)。\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");

    add_action("do_dig", "dig");
    add_action("do_eat", "eat");
}

int do_dig(string arg)
{
   object baihe, who, me, where;
   who=this_player();
   me=this_object();
   where=environment(me);

   if( me->query("can_eat"))
     return notify_fail("什么？\n");

   if( !arg || (arg!="xian zhi" && arg!="zhi"))
     return notify_fail("你要挖什么？\n");

   if(who->is_fighting() && who->is_busy())
     return notify_fail("你很忙，没时间挖草。\n");

   if( baihe=present("bai he")){
     message_vision("白鹤长鸣一声，对$N发起了攻击。\n", who);
     baihe->kill_ob(who);
     who->fight_ob(baihe);
     return 1;
   }

     message_vision("$N轻轻将$n挖了起来。\n", who, me);
     me->set("can_eat", 1);
     me->move(who);
     remove_call_out("yiyexianzhi");
     remove_call_out("eryexianzhi");
     remove_call_out("sanyexianzhi");
     remove_call_out("siyexianzhi");
     remove_call_out("wuyexianzhi");
     remove_call_out("liuyexianzhi");
     remove_call_out("qiyexianzhi");
     where->delete("qiyexianzhirass");

   if( !baihe && me->query("eatable")){
     seteuid(getuid());
     baihe=new(__DIR__"npc/baihe");
     baihe->move(environment(who));
     tell_room(environment(who), "忽听一声鹤鸣，半空中冲下一只白鹤来。\n");
     baihe->kill_ob(who);
     who->fight_ob(baihe);
   }
   return 1;
}

int do_eat(string arg)
{
   object me=this_object();
   object who=this_player();
   int force_add, mana_add, howold;
   
   if (!id(arg))
        return notify_fail("你要吃什么？\n");
   if( !me->query("can_eat"))
        return notify_fail("你要吃什么？\n");


   howold = (int)who->query("mud_age") ;
   who->set("food", (int)who->max_food_capacity());
   who->set("water", (int)who->max_water_capacity());

   if( !me->query("eatable")){
     message_vision("$N狼吞虎咽般地将一颗$n吃了下去。\n", who, me);
     destruct(me);
     return 1;
   }
   
   message_vision("$N将一颗$n轻轻嚼着咽下了肚，脸上泛起阵红晕。\n", who, me);
   tell_object(who, "你觉得一阵热气直通七窍，浑身上下好象有使不完的力气。\n");

   who->set("eff_jing", (int)who->query("max_sen"));
   who->set("jing", (int)who->query("max_sen"));
   who->set("eff_qi", (int)who->query("max_gin"));
   who->set("qi", (int)who->query("max_gin"));
   
   if( (int)who->query("max_neili")< 10*(int)who->query_skill("force")){
         who->set("max_nei", 10 * (int)who->query_skill("force") );
   }
   //if( howold > 500000 ) {
   //      who->add("mud_age", -200000);
   //}
   destruct(me);
   return 1;
}



void invocation()
{
   object me=this_object();
   int i=200+random(200);
   call_out("yiyexianzhi", i, me);
}

int yiyexianzhi(object me)
{
   int i=400+random(400);
   tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
   set_name(RED "一叶仙芝" NOR, ({"xian zhi","zhi"}));
   call_out("eryexianzhi", i, me);
   return 1;
}

int eryexianzhi(object me)
{
        int i=600+random(600);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "二叶仙芝" NOR, ({"xian zhi","zhi"}));
        call_out("sanyexianzhi", i, me);
        return 1;
}

int sanyexianzhi(object me)
{
        int i=800+random(800);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "三叶仙芝" NOR, ({"xian zhi","zhi"}));
        call_out("siyexianzhi", i, me);  
        return 1;
}

int siyexianzhi(object me)
{
        int i=1000+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "四叶仙芝" NOR, ({"xian zhi","zhi"}));
        call_out("wuyexianzhi", i, me);  
        return 1;
}

int wuyexianzhi(object me)
{
        int i=1200+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "五叶仙芝" NOR, ({"xian zhi","zhi"}));
        call_out("liuyexianzhi", i, me);  
        return 1;
}

int liuyexianzhi(object me)
{
        int i=1500+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "六叶仙芝" NOR, ({"xian zhi","zhi"}));
        call_out("qiyexianzhi", i, me);  
        return 1;
}

int qiyexianzhi(object me)
{
        int i=2000+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        tell_room(environment(me), me->name()+"周围渐渐笼起一股红光。\n", ({me, me}));
        set_name(RED "七叶仙芝草" NOR, ({"xian zhi","zhi"}));
        set("eatable",1);
        return 1;
}

