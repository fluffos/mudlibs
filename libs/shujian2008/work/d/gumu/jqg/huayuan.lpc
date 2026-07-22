//huayuan.c 花园
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIM"花园"NOR);
        set("long",@LONG
这里是花园，种满了情花树(hua），西北方是一个小池塘，眼下正值六月，
池塘内荷花都绽开了花朵，几只青蛙趴在荷叶上“呱呱”地叫个不停。西南方
一座假山，南面是一条长廊。
LONG
    );
        set("item_desc",([
           "hua": "树枝叶上生满小刺，情花花瓣的颜色娇艳无比，诱得你忍不住去摘下来。\n",
           "hill": "这是一座假山，一块巨石挡在山前，看上去这块巨石似乎有些奇怪，\n"+
                   "巨石后面似乎有些不同寻常，二名绿衣弟子守在假山前。\n",
        ]));

        set("outdoors","绝情谷");
        set("exits",([
              "south": __DIR__"lang1",
        ]));  

        set("objects",([
                 __DIR__"npc/dizi1" : 2,
        ]));

        setup();
}

void init()
{
        add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{    
        object ob, *inv, me = this_player();
        int i;
        
        me = this_player();
        inv = deep_inventory(me);
        i = sizeof(inv);

        if (!arg || (arg != "hua"))
              return notify_fail("你要摘什么啊？\n");

        if (me->is_busy() || me->is_fighting())
	      return notify_fail("你正忙着哪！\n");

        if (present("qing hua", this_player()))
	      return notify_fail("你身上不是有么，还想要，太贪心了。\n");

        while (i--)
        if( inv[i]->query("drug"))
              return notify_fail("你刚想去摘花，忽然发现枝上小刺，不由犹豫地放下手来。\n");

        ob = new(MEDICINE_D("neili/flower"));
        message_vision(HIY"$N避开枝上尖刺，伸手去摘"HIM"情花"HIY"，落手甚是小心。\n"NOR, this_player());

        ob->set("owner", me->query("id"));
        ob->move(me);

        me->add_busy(random(2));

        if(random(me->query("kar")) < 10 ){
		message_vision(HIY"岂知花朵背後隐藏著小刺，将$N的手指给刺破了。\n"NOR, this_player());
		me->apply_condition("qinghua_poison", me->query_condition("qinghua_poison")+100);
		log_file("quest/neili",sprintf("%-18s得到%s，中情花毒。\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
		return 1;
        }
	else {
		log_file("quest/neili",sprintf("%-18s得到%s，没有中情花毒。\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
		message_vision(HIY"$N绕开花朵背后的小刺，伸手将"HIM"情花"HIY"摘了下来。\n"NOR, this_player());
		return 1;
	}
}
