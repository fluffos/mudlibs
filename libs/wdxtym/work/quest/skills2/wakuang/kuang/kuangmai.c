// ying-kuang.c 矿脉
// 星星lywin 2000/8/27

#include <ansi.h>
inherit ITEM;

string *kuang1=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang"});
string *kuang2=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang"});
string *kuang3=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang"});
string *kuang4=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang","/quest/skills2/wakuang/kuang/xuantie-kuang"});
string *kuang5=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang","/quest/skills2/wakuang/kuang/xuantie-kuang","/quest/skills2/wakuang/kuang/hantie-kuang1"});
string *kuang6=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang","/quest/skills2/wakuang/kuang/xuantie-kuang","/quest/skills2/wakuang/kuang/hantie-kuang1","/quest/skills2/wakuang/kuang/hantie-kuang2"});

void init()
{
	add_action("do_wakuang", "wakuang");
}


void create()
{
        set_name("矿脉",({"kuang mai", "mai"}));
        set_weight(500000000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_put",1);
		set("no_get",1);
                set("long", "这是一条很好的矿脉，你可以用("ZJURL("cmds:wakuang")ZJSIZE(15)""HIY"挖矿"NOR")来试试你的运气如何。\n");
             }
        setup();
}

int do_wakuang()
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("你现在很忙！不能挖！\n");
        if ((me->query("combat_exp") < 100000))
        {
          tell_object(me,"你的修为不足！\n");
          return 1;
        }
        if ((me->query("jing") < 30))
        {
          tell_object(me,"你的精力不能集中，不可以挖矿石！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"你的身体状态太差，不能挖矿石！\n");
          return 1;
        }
        else
        if ((int)me->query_condition("skill2_busy"))
            {
         tell_object(me,"你刚刚才干过活,要休息一会了！\n");
                      return 1;
            }

        message_vision(HIC"$N挥动铁镐开始在地上挖了起来。\n"NOR,me);
        me->add("jing",-20);
        me->add("qi",-30);
        if (me->query("combat_exp")<1000000)
        {
        me->add("combat_exp",1000+random(100));
        me->add("potential",1000+random(100));
        }
        else
        {
        me->add("combat_exp",500+random(19));
        me->add("potential",500+random(50));
        }
        me->apply_condition("skill2_busy",1+random(3));
        me->start_busy(10);
       	call_out("wakuang",5,me);
       	me->stop_busy();
       	return 1;
}

int wakuang(object me)
{
      object ob;
      object ob1;
	  int mykar = me->query("kar");
      if (random(7)<1)
      {
          message_vision(CYN"一阵挖掘之后，$N什么也没挖到。\n"NOR,me);
//          this_player()->add("work/wakuang",1);
          return 1;
      }
      else
      if ((int)me->query("work/wakuang") > 307200 )
        {
           message_vision(HIR"$N熟练的在矿脉中找来查去，不一会儿就找出一块好矿石。\n"NOR,me);
           me->add("work/wakuang",1);
           ob=new(kuang6[random(7)]);
           ob->move(me);
		   if(random(mykar)>=30 && random(200)==1)
		   {
			    message("channel:chat", HIY"【空穴来风】"HIW + "听说《"+me->query("name")+"》在某一处矿脉挖到了一颗昆仑石！\n"NOR,users() );
				ob=new("clone/zhifen/stone");
				ob->move(me);
		   }
          destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 76800 )
        {
           message_vision(HIY"$N熟练的在矿脉中找来查去，不一会儿就找出一块好矿石。\n"NOR,me);
           me->add("work/wakuang",1);
           ob=new(kuang5[random(6)]);
           ob->move(me);
		   if(random(mykar)>=30 && random(300)==1)
		   {
			    message("channel:chat", HIY"【空穴来风】"HIW + "听说《"+me->query("name")+"》在某一处矿脉挖到了一颗昆仑石！\n"NOR,users() );
				ob=new("clone/zhifen/stone");
				ob->move(me);
		   }
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 19200 )
        {
           message_vision(HIY"$N熟练的在矿脉中找来查去，不一会儿就找出一块好矿石。\n"NOR,me);
           me->add("work/wakuang",1);
           ob=new(kuang4[random(5)]);
           ob->move(me);
		   if(random(mykar)>=40 && random(400)==1)
		   {
			    message("channel:chat", HIY"【空穴来风】"HIW + "听说《"+me->query("name")+"》在某一处矿脉挖到了一颗昆仑石！\n"NOR,users() );
				ob=new("clone/zhifen/stone");
				ob->move(me);
		   }
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 4800 )
        {
           message_vision(HIY"$N在矿脉中翻来覆去，找出一块好矿石。\n"NOR,me);
           me->add("work/wakuang",1);
           ob=new(kuang3[random(4)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 1600 )
        {
           message_vision(HIY"$N在矿脉中找来查去，好久才找出一块矿石。\n"NOR,me);
           me->add("work/wakuang",1);
           ob=new(kuang2[random(3)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 800 )
        {
           message_vision(HIY"$N在矿脉中摸来摸去，好不容易找出一块矿石。\n"NOR,me);
           me->add("work/wakuang",1);
           ob=new(kuang1[random(2)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
      else
      {
        message_vision(HIG"$N找了半天，终于发现其中一块石头是矿石。\n"NOR,me);
        me->add("work/wakuang",1);
        ob1 = new( __DIR__ "tong-kuang");
        ob1->move(me);
        destruct(this_object());
      }
      return 1;
}
