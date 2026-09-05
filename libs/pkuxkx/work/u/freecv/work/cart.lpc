// cart

#include <ansi.h>
inherit ITEM;

void to_rob(object me);
int robit(object ppl);

mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);
void create()
{
        seteuid(getuid());
        set_name(YEL"囚车"NOR, ({ "qiu che", "che"}) );
        set_weight(300000);
        set("no_get", 1);

	set("location",1);
	set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "辆");
        set("long", "一辆官府的囚车，里面关着一位囚犯。\n你可以drive(gan) che to <方向> 来推动它前进\n");
        set("closed", 1);
        set("value", 2000);
        setup();
    	remove_call_out("destroy2");
    	call_out("destroy2",random(300) + 600,this_object());
}

void init()
{
    add_action("do_open","jie");
    add_action("do_gan","gan");
    add_action("do_gan","drive");
//    add_action("do_touxiang","touxiang");
}

int do_open(string arg)
{
        object me, ob,master,player;
        string mname,mid;
        int rewardr;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();

        if(arg != "qiu che" && arg != "che")
          return notify_fail("你要劫什么？\n");
        if(me->query("jianzhan/in_dart"))
          return notify_fail("你想监守自盗？\n");
        if (ob->query("be_robbed"))
            return notify_fail("什么？\n");
        if(player = present(mid,environment()))
          if (living(player))
          return notify_fail("监斩的还在旁边，先把他做掉吧。\n");

        message_vision("$N将$n推走了。\n", me, this_object());
        message("channel:rumor",HIM"【谣言】"+mname
         +"护送的囚车被"+me->query("name")+"劫去了！\n"NOR,users());
         rewardr=random(50)+30;
         message("vision",HIW"你得到了"+chinese_number(rewardr)+"点江湖声望的奖励！\n"NOR,me);
         message("vision",HIW"你的经验增加了！\n"NOR, me);
         me->add("repute",rewardr);
         me->add("combat_exp",300+random(700));
         ob->set("be_robbed",1);
	remove_call_out("destroy1");
        call_out("destroy1",1,ob);
        return 1;
}

int do_gan(string arg)
{
        object me,ob, env, obj;
        object* inv;
        int i;
        string item, dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("你要赶什么？\n");

        if( me->query("id")!=ob->query("masterid")) return 0;

        if( sscanf(arg, "%s to %s", item, dir) != 2 ||
                item != "cart" && item != "che")
                return command(query_verb()+" "+arg);

        if( me->is_busy() )
                return notify_fail("你现在正忙着哩。\n");
        if(!me->query("jianzhan/can_go"))
        	return notify_fail("囚车还没有跟上来呢,走慢点.\n");

                inv = all_inventory(environment(me));
                for(i=0; i<sizeof(inv); i++) {
                    if (inv[i]->query("uni_target") == me)
                        return notify_fail(HIR"劫匪伸手一拦道：“想跑？没那么容易！”\n"NOR);
                }


        if ( this_player()->is_fighting())
                return notify_fail("你还是先把对手解决了再说吧！\n");

        env = environment(me);
        if(!env) return notify_fail("你要去那里？\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) {
                if( query_verb()=="gan")
                        return notify_fail("这个方向过不去。\n");
                else
                        return 0;
        }

        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("没法赶。\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");


       if (objectp(present("qiu che", obj)))
         return notify_fail("对面已经有一辆囚车了，你还是绕道走吧。\n");
        if(me->follow_path(dir))
	{
        	message("vision", HIG "\n" + me->name() + "赶着囚车往" + target + "驶去。\n" NOR, env);
        	message("vision", HIG "囚车隆隆向"+ target + "驶去。\n" NOR, env);
		ob->move(obj);
        	message_vision(HIG "$N赶着囚车驶了过来。\n" NOR, me);
        	message_vision(HIG "囚车隆隆驶了过来。\n" NOR,me);
        	me->start_busy(1+random(2));
        	me->set("jianzhan/can_go",0);
	}
	else
	{
        	return notify_fail("这个方向过不去。\n");
	}
        //到地方了就不出劫匪了
          call_out("check1",1,ob,me);
        if (base_name(environment()) == "/d/beijing/caishikou" )
        return 1;
        remove_call_out("robit");
    	call_out("robit",1,this_player());

        if (random(10) > 5){
		remove_call_out("to_rob");
		call_out("to_rob",1,me);
	}
        return 1;
}
int check1(object ob, object me)
{
	object *obj;
	int i;
        if ( base_name(environment()) == "/d/beijing/caishikou" )
           {
              message_vision(HIY"$N终于把囚车运到了菜市口。\n\n"NOR,me);
              message_vision(HIY"早已守候多时的刽子手，将囚犯押上了断头台。\n"NOR, me);
              write(HIY"只见刽子手大刀一挥... ...\n"NOR);
              tell_object(me,"你的任务完成了，赶快回去覆命吧。\n");

  	obj = all_inventory(environment(me));
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query_leader() == me && obj[i]->query("id") == "guan bing")
		destruct(obj[i]);
	}
              me->set("jianzhan/over_dart",1);
	      remove_call_out("destroy1");
              call_out("destroy1",1,ob);
              return 1;
            }
        me->set("jianzhan/can_go",1);

}
void destroy1(object me)
{
        destruct(me);
        return;
}

void destroy2(object me)
{
	object *ob;
	int i;
	if (!me)
		return;
    if (!environment(me)) return;
  	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( ob[i]->query_leader() == (me->query("owner")) && ob[i]->query("id") == "guan bing")
		destruct(ob[i]);
	}
     message_vision(HIR"突然骡子大叫一声发疯似拖着囚车跑了。\n"NOR,me);
     destruct(me);
     return;
}

void to_rob(object me)
{
  object *ob;
  object robber,room;
  int i, j, exp;
  room = environment(me);

  if( environment(me)->query("no_fight") ) return;
  message_vision(HIR"劫匪突然从暗处跳了出来，阴笑道：“囚车和人命都留下来吧！。”\n" NOR, me);
  ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i])) continue;
		if (userp(ob[i])) ob[i]->set_leader(0);
	}
  me->start_busy(2);
	exp = me->query("combat_exp");
	j = 1 + random(3);
	for (i = 0; i < j; i++)
	{
	robber = new("/d/beijing/npc/robber");

	if (exp < 500000)
	{
		robber->Set_Npcattrib(20, 10,
		   			500, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			100000, 200000 );
		if (random(2) == 0)
		robber->skills_setup_none(50, 50, "random_menpai");
		else
		robber->skills_setup_weapon(50, 50, "random_menpai");
	}
	else if (exp < 1000000)
	{
		robber->Set_Npcattrib(20, 10,
		   			1000, 1500,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			100000, 500000 );
		if (random(2) == 0)
		robber->skills_setup_none(50, 100, "random_menpai");
		else
		robber->skills_setup_weapon(50, 100, "random_menpai");
	}
	else
	{
		robber->Set_Npcattrib(20, 10,
		   			1500, 2000,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			300000, 1000000 );
		if (random(2) == 0)
		robber->skills_setup_none(100, 100, "random_menpai");
		else
		robber->skills_setup_weapon(100, 100, "random_menpai");
	}
  		robber->set("uni_target",me);
  		robber->apply_condition("bjkiller", 100);
  		robber->move(room);
  		robber->kill_ob(me);
  		robber->checking(robber,me);
  		robber->command("rob");
	}
}

int robit(object ppl)
{
	object *inv;
	int i;
	inv = all_inventory(environment(ppl));
	for(i=0;i<sizeof(inv);i++)
	{
		if(!userp(inv[i]) && living(inv[i]) && inv[i]->query("family/family_name") == "天地会")
		{
			message_vision("斜刺里冲出来$N，猛地对$n痛下杀手！\n",inv[i],ppl);
			message_vision("官兵大呼：有人劫囚车啊！\n",ppl);
			ppl->start_busy(2);
                        inv[i]->kill_ob(ppl);
		}
	}
	return 1;
}
