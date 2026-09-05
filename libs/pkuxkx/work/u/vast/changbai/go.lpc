// go.c

#include <ansi.h>
#include <color.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
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
        "up":           "上",
        "down":         "下",
        "out":          "外",
]);

void create()
{
	seteuid(getuid());
	set("channel_id","GOGOGO");
}

int main(object me, string arg)
{
        string dest, mout, min, dir,ridemsg;
        object env, obj,weapon,armor,ridee;
        mapping exit;
        object *f_obs;
        string str;

        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");

        if( me->query_temp("pk_exp") )
                return notify_fail(RED "你的官司没有打完，不能移动！！\n" NOR);

        if (me->is_fighting()) {
                f_obs = me->query_enemy();
                if (sizeof(f_obs) > 0)
                if (objectp(f_obs[0]))
                if (5 + random((int)me->query("dex")) <=
                        random((int)f_obs[0]->query("dex"))) {

                        me->start_busy(1);
                        return notify_fail("你逃跑失败。\n");
                }
        }

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("这个方向没有出路。\n");
                else
                        return 0;
        }
//        dest = exit[arg];
        if( !env->valid_leave(me, arg) ) return 0;

        if( !stringp(dest = me->query_temp("new_valid_dest")) )
                dest = exit[arg];

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("无法移动。\n");

	me->delete_temp("new_valid_dest");

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;
        if(ridee=me->ride())
                ridemsg = ridee->query("ride_msg")+"着"+ridee->name();
        else
          ridemsg = "";

//        if(ridee)
//           return notify_fail("你的座骑走动不了。\n");
        min = "";
        if( me->is_fighting() ) {
                mout = "$N往" + dir + "落荒而逃了。\n";
                min = "$N跌跌撞撞地跑了过来，模样有些狼狈。\n";
        } else {
        	min+=ridemsg;
                if (objectp( weapon = me->query_temp("secondary_weapon") ))
                {
                        min = min + "左手拿着" + weapon->query("name") + NOR + "，";
                        if (objectp( weapon = me->query_temp("weapon") ))
                                min = min + "右手拿着" + weapon->query("name") + NOR + "，";
                }
                else if (objectp( weapon = me->query_temp("weapon") ))
                        min = min + "手持" + weapon->query("name") + NOR + "，";
                if (objectp( armor = me->query_temp("armor/cloth") ) || objectp( armor = me->query_temp("armor/armor") ) || objectp( armor = me->query_temp("armor/surcoat") ) )
                        min = min + "身穿" + armor->query("name") + NOR;
                else
                {
                	if(userp(me))
                	{
                		CHANNEL_D->do_channel(this_object(),"rumor","听说"+
                		me->name()+"在街上裸奔啊！！！！～～～～\n");
                		if(me->query("gender")=="女性"&&me->query_per()-me->query("age")>10)
               			CHANNEL_D->do_channel(this_object(),"rumor","流鼻血啊～～～～\n");
				me->add("jing",-10);
				me->start_busy(1);
			}
                	min = min + "光着身子" + NOR;
                }
                mout = "$N往" + dir + "离开。\n";
                min = "$N" + min + "走了过来。\n";
        }
        if ((me->query("position") != "zmuduser") && (me->query("env/brief")))
		printf(JSP "parent.look_room(\"%s\", \"%s\", \"%s\")" NSP,
        		"", "如果在行走中仍要看到周围描述，请unset brief\n", "");
        if( me->query("msg_come") ) min = me->query("msg_come");
        if( me->query("msg_leave") ) {
                mout = me->query("msg_leave");
                mout = replace_string(mout, "$E", dir);
        }
        mout = replace_string(mout, "$N", me->name());
        min = replace_string(min, "$N", me->name());

	if(userp(me) || !objectp(me->query_temp("rider")) )
        tell_room( environment(me), mout, ({ me }));
        if( me->move(obj) ) {
                me->remove_all_enemy();
	if(userp(me) || !objectp(me->query_temp("rider")) )
                tell_room( environment(me), min, ({ me }) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
    );
    return 1;
}

