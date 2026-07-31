// cart

#include <ansi.h>
inherit ITEM;

void to_rob();

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
        set_name(HIW"镖车"NOR, ({ "biao che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
		set("biaoche", 1);
set("location",1);
set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "辆");
        set("long", "一辆黑漆漆的镖车，上面插着镖旗。\n"ZJURL("cmds:help lj")+ZJSIZE(20)+"赶车"NOR"或"ZJURL("cmds:jie biao che")+ZJSIZE(20)+"劫镖\n"NOR);
        set("closed", 1);
        set("value", 2000);

}

void init()
{
    add_action("do_open","jie");
    if( this_player()->query_temp("in_dart"))
    {
         add_action("do_gan","gan");
         add_action("do_gan","drive");
    }
    call_out("destroy2",random(800)+3000,this_object());
}

int do_open(string arg)
{
        object me, ob;
        string mname,mid;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();

        if(arg != "biao che")
          return notify_fail("你要打开什么？\n");
        if(me->query_temp("in_dart"))
          return notify_fail("你想监守自盗？\n");
        if(present(mid,environment()))
          return notify_fail("护镖的还在旁边，先把他做掉吧。\n");

        message_vision("$N将$n推走了。\n", me, this_object());
        message("channel:rumor",HIM"【谣言】"+mname
         +"护的镖被"+me->query("name")+"劫去了！\n"NOR,users());
        call_out("destroy1",0,ob);
        return 1;
}

int do_gan(string arg)
{
        object me,ob, env, obj;
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

        if ( present("robber",environment()))
                return notify_fail(HIR"劫匪伸手一拦道：“想跑？没那么容易！”\n"NOR);

        if ( this_player()->is_fighting())
                return notify_fail("你还是先把对手解决了再说吧！\n");

        env = environment(me);
        if(!env) return notify_fail("你要去那里？\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) {
            if( query_verb()=="gan")
			{
				write(ZJFORCECMD("help lj"));
				return 1;
			}
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

        message_vision(HIG "\n$N赶着镖车往" + target + "驶去。\n" NOR,
                me);
        message_vision(HIG "镖车隆隆向"+ target + "驶去。\n" NOR,me);

        if( ob->move(obj) && me->move(obj)) {
          all_inventory(env)->follow_me(me, dir);
          message_vision(HIG "$N赶着镖车驶了过来。\n" NOR, me);
          message_vision(HIG "镖车隆隆驶了过来。\n" NOR,me);
		  write(ZJFORCECMD("help lj"));
          me->start_busy(random(2));
        }
        call_out("check1",0,ob,me);
        if (base_name(environment())!=(string)me->query_temp("dart_area"))
{
        if (random(10)==8){ call_out("to_rob",1,me);}
}
        return 1;
}
int check1(object ob, object me)
{
        if (base_name(environment())==(string)me->query_temp("dart_area")
             && present(me->query_temp("dart_id"), environment()) )
           {
              message_vision(HIY"$N累了个半死，终于把镖运到了地头。\n\n"NOR,me);
              message_vision(HIY+me->query_temp("dart_name")+
                "拍拍$N的头说道：“"+RANK_D->query_respect(this_player())
                +"辛苦了！”\n\n"NOR,me);
              write(HIY"里间出来几个人将镖车拉了进去。\n"NOR);
              me->set_temp("over_dart",1);
              me->apply_condition("dart_limit", 0);
              call_out("destroy1",1,ob);
              return 1;
            }
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

void to_rob()
{
  object *ob;
  object robber,room;
  int i;
if (!this_player()) return;
  room = environment(this_player());
if (base_name(environment())==(string)this_player()->query_temp("dart_area")) return;

  if( environment(this_player())->query("no_fight") ) return;
  message_vision(HIR"劫匪突然从暗处跳了出来，阴笑道：“红货和人命都留下来吧！。”\n" NOR,
        this_player());
	ob = all_inventory(environment(this_player()));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i])) continue;
				ob[i]->set_leader(0);
		}
  this_player()->start_busy(2);
  if (random(4)==0)
  {
  robber=new(__DIR__"npc/robber0");
  }
  else if (random(4)==1)
  {
  robber=new(__DIR__"npc/robber1");
  }
  else if (random(4)==2)
  {
  robber=new(__DIR__"npc/robber3");
  }
  else if (random(4)==3)
  {
  robber=new(__DIR__"npc/robber4");
  }
  else
  {
  robber=new(__DIR__"npc/robber1");
  }
  robber->do_change(this_player());
  robber->move(room);
  robber->kill_ob(this_player());
  robber->checking(robber,this_player());
  robber->set_leader(this_player());
  robber->command("rob");
}


