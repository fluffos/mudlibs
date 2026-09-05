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
        set_name(HIR"镖车"NOR, ({ "biao che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
 
	set("location",1);
	set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "辆");
        set("long", "一辆黑漆漆的镖车，上面插着镖旗。\n你可以drive(gan) che to exit来推动它前进\n");
        set("closed", 1);
        set("value", 2000);
        call_out("destroy3",900 + random(300),this_object());
}

void init()
{
    add_action("do_open","jie");
    add_action("do_gan","gan"); 
    add_action("do_gan","drive");
    add_action("do_touxiang","touxiang");
    remove_call_out("destroy2");
    call_out("destroy2",random(200)+1000,this_object());
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
	
        if(arg != "biao che")
          return notify_fail("你要打开什么？\n");
        if(me->query("in_dart"))
          return notify_fail("你想监守自盗？\n"); 
        if (ob->query("be_robbed"))
            return notify_fail("什么？\n");
		if (userp(me) && me->query("combat_exp")<3000000)          //picewolf添加，主要为了限制0 exp玩家捣乱所设
			return notify_fail("你武功这么面，劫个毛，不怕被人剁死么？\n");
        if(player = present(mid,environment()))
          if (living(player))
          return notify_fail("护镖的还在旁边，先把他做掉吧。\n");

        message_vision("$N将$n推走了。\n", me, this_object());
        CHANNEL_D->do_channel(this_object(), "rumor", mname+"护的镖被"+me->query("name")+HIM+"劫去了！", -1);
         rewardr=random(50)+30;
         message("vision",HIW"你得到了"+chinese_number(rewardr)+"点江湖声望的奖励！\n"NOR,me);
         message("vision",HIW"江湖上谈起你，纷纷摇头变色，你的道德下降了！\n"NOR,me);
         message("vision",HIW"你的经验增加了！\n"NOR,me);
         me->add("repute",rewardr);
         me->add("shen",-random(1000));
         me->add("combat_exp",30+random(100));
        ob->set("be_robbed",1);
	remove_call_out("destroy1");
        call_out("destroy1",1,ob);
        return 1;
}
int do_touxiang()
{
       object me, ob,master,player;
        string mname,mid;
        int rewardr;
        object *inv;
        int i;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();

	if (this_object()->query("masterid") != me->query("id"))
		return notify_fail("这不是你的镖车！\n");
                inv = all_inventory(environment(me));
                for(i=sizeof(inv)-1; i>=0; i--) {
                    if (inv[i]->query("uni_target") == me)
                    	destruct(inv[i]);
                   }
        message_vision("$N抛下武器向劫匪投降，劫匪嘿嘿一笑：算你聪明！\n",me,this_object());	
        message_vision("劫匪将$n推走了。\n", me, this_object());
        CHANNEL_D->do_channel(this_object(), "rumor", mname+"护的镖被劫匪劫去了！", -1);
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
        if(!me->query_temp("yunbiao/can_go"))
        	return notify_fail("镖车还没有跟上来呢,走慢点.\n");

                inv = all_inventory(environment(me));
                for(i=0; i<sizeof(inv); i++) {
                    if ( (inv[i]->query("uni_target") == me) && (inv[i]->query("id") == (me->query("id")+"'s robber")) )
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

/*
        message_vision(HIG "\n$N赶着镖车往" + target + "驶去。\n" NOR,
                me);
        message_vision(HIG "镖车隆隆向"+ target + "驶去。\n" NOR,me);  

        if( ob->move(obj) && me->move(obj)) {
          all_inventory(env)->follow_me(me, dir);
          message_vision(HIG "$N赶着镖车驶了过来。\n" NOR,
                        me);
          message_vision(HIG "镖车隆隆驶了过来。\n" NOR,me); 
          me->start_busy(1+random(2));
          me->set_temp("yunbiao/can_go",0);
        }
*/
//       if (objectp(present("biao che", obj)))
//         return notify_fail("对面有人运镖，还是打个招呼绕道走吧。\n");
        if(me->follow_path(dir)) 
{
        message("vision", HIG "\n" + me->name() + "赶着镖车往" + target + "驶去。\n" NOR, env);
        message("vision", HIG "镖车隆隆向"+ target + "驶去。\n" NOR, env);  
                ob->move(environment(me));
        message_vision(HIG "$N赶着镖车驶了过来。\n" NOR, me);
        message_vision(HIG "镖车隆隆驶了过来。\n" NOR,me); 
        me->set_temp("yunbiao/can_go",0);
		}
		else
		{
            return notify_fail("这个方向过不去。\n");
		}
        //到地方了就不出劫匪了
          call_out("check1",1,ob,me);
        if (base_name(environment())==(string)me->query_temp("dart_area") 
             && present(me->query_temp("dart_id"), environment()) )
            return 1;
        remove_call_out("robit");
    	call_out("robit",1,this_player());
        if (random(30)<10){ 
		remove_call_out("to_rob");
		call_out("to_rob",1,me);
	}
	else
	        me->start_busy(1+random(2));
        return 1;
}
int check1(object ob, object me)
{
	object target;
        if (!objectp(me->query_temp("dart_target")))
        {
                write(HIR"接应你的伙计已经不在了，你运的镖已经没有用处了。\n"NOR);
                 write(HIW"镖车呼啦一声散了架。\n"NOR);
                call_out("destroy1",1,ob);
                return 1;
        }
        if ( objectp(target = present(me->query_temp("dart_target"),environment())))
           {  
              message_vision(HIY"$N累了个半死，终于把镖运到了地头。\n\n"NOR,me);
              message_vision(HIY+target->name()+
                "对$N说道：“终于到了！"+RANK_D->query_respect(this_player())
                +"辛苦了！”\n\n"NOR,me);
              write(HIY"围上来几个伙计将镖车拉了进去。\n"NOR);
              me->set_temp("over_dart",1);
              me->set_temp("finish_lin",1);
              me->apply_condition("dart_limit", 0);
              destruct(target);
	      remove_call_out("destroy1");
              call_out("destroy1",1,ob);
              return 1;
            }  
        me->set_temp("yunbiao/can_go",1);
        
}
void destroy1(object me)
{
        destruct(me);
        return;
}

void destroy2(object me)
{
     message_vision(HIR"突然骡子大叫一声发疯似拖着镖车跑了。\n"NOR,me);
     destruct(me);
     return;
}
void destroy3(object me)
{
        if(!objectp(me)) return; //iszt@pkuxkx, 2007-02-03, 这里me应该是this_object()啊，怎么会没有呢……
     message_vision(HIR"$N磨损太大，哗啦一声散了架。\n"NOR,me);
     destruct(me);
     return;
}
void to_moveaway(object me)
{
	mapping exits;
	string *dirs;
	object dest;
	string dir;
	object *inv;
	int i;

	if(!environment()) return 0;
	if(sizeof(environment()->query("exits")) == 0) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	if (!me) return 0;
	if (!me->is_fighting()) return 0;
	inv = all_inventory(environment(me));
	dirs = keys(exits);
	dir = dirs[random(sizeof(dirs))];
	dest = exits[dir];
	message_vision("劫匪趁$N不注意，推着镖车就跑，$N赶紧追了上去。\n",me);
	for (i=sizeof(inv)-1;i>=0;i--)
	{
		if ((inv[i]->query("id") == (me->query("id")+"'s robber")) && inv[i]->query("uni_target")==me)
			inv[i]->move(dest);
		if (userp(inv[i]) && inv[i]->query_leader()==me)
			{			
				inv[i]->move(dest);
				tell_object(inv[i],"你看到劫匪推着"+me->query("name")+"的镖车跑了，赶忙也跟了上去。\n");
			}
	}
	tell_room(dest,"一群劫匪匆匆忙忙赶着一辆镖车跑了过来，后面" + me->query("name") + "穷追不舍。\n");
	this_object()->move(dest);
	me->move(dest);
	if(!random(20))
	{
		remove_call_out("to_moveaway");
		call_out("to_moveaway",5,me);
	}	
	return;
}

void to_rob(object me)
{
  object *ob;
  object robber,room;
  int i;
  room = environment(me);
  
  if( environment(me)->query("no_fight") ) return;
  message_vision(HIR"劫匪突然从暗处跳了出来，阴笑道：“红货和人命都留下来吧！。”\n" NOR,
        me); 
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i])) continue;
		//if( ob[i]->query("id")=="dashi") continue;	/*whuan 防止husong的follow效果消失*/
		//if( ob[i]->query("shaolin/on_husong")) continue; 	/*whuan 防止husong的follow效果消失*/
		if(ob[i]->query_leader() == me)//这个判断可靠,dashi的id是xuan* dashi
	    {
		        ob[i]->set_leader(0);
       	}
	}
  
  switch(random(7))
  {
  	case 0:
  robber=new("/d/luoyang/npc/robber0");
  break;
  	case 1:
  robber=new("/d/luoyang/npc/robber1");
  break;
  	case 2:
  robber=new("/d/luoyang/npc/robber2");
  break;
  	case 3:
  robber=new("/d/luoyang/npc/robber3");
  break;
  	case 4:
  robber=new("/d/luoyang/npc/robber4");
  break;
  	case 5:
  robber=new("/d/luoyang/npc/robber5");
  break;
  case 6:
  robber=new("/d/luoyang/npc/robber6");
  break;
  }
    robber->set("uni_target",me);
    robber->set("title", "拦路抢劫"+me->query("name")+"的");
    robber->set_name(robber->query("name"), ({me->query("id")+"'s robber",me->query("id")+" robber","robber"}));
  robber->do_change(me);
  robber->move(room);
   robber->fight_ob(me);
  robber->checking(robber,me);
  robber->command("rob");
  if ((random(me->query("kar")+5)<10) 
  	&& !room->query("no_movecart")
  	&& (me->query_temp("yunbiao/high_value")) && !me->query_temp("yb_addi"))
  { 
		remove_call_out("to_moveaway");
		call_out("to_moveaway",random(30),me);
	}
  
}

int robit(object ppl)
{
	object *inv;
	int i;
	inv=all_inventory(environment(ppl));
	for(i=0;i<sizeof(inv);i++)
	{
                 if(!userp(inv[i])&&living(inv[i])&&inv[i]->query("shen")<0 && (inv[i]->query("id") != "cart robber"))
		if(random(2) > 0)
		{
			message_vision("斜刺里冲出来$N,猛地对$n痛下杀手！\n",inv[i],ppl);
			message_vision("趟子手大呼：有人劫镖阿，快护镖，快快！\n",ppl);
			if(ppl->query("yidaizhenlong"))
			{
			    message_vision("$N看到$n气势如神，肝胆俱裂，双膝跪地，磕头如捣蒜，不知"+HIY+"一代真龙"NOR+"驾到，罪该万死！\n",inv[i],ppl);
			    continue;
			}
			ppl->start_busy(5);
            inv[i]->fight_ob(ppl);
		}
	}
	return 1;
}
