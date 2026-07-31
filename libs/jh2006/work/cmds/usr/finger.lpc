// finger.c
// by xiaoyao@Sj
// 加入好友名单
// Modify by snowman@SJ 09/01/2000
// Added busy time, by snowman@SJ 26/08/2000

#include <ansi.h>
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
	object obj;
	string *friend_user, list;
	
	friend_user = me->query("friend_user");

	if( !stringp(arg)) {
		if (!sizeof(friend_user))
			return notify_fail("你目前没有设定好友。\n");

		friend_user = sort_array(friend_user, 0);
		list = "\n你目前的好友名单如下：\n";	 
		for( i = 0 ; i < sizeof(friend_user); i++) {
			if( (obj = LOGIN_D->find_body(friend_user[i]) )){
				if( me->visible(obj) ) list += sprintf("  [%2d] %s\n", i+1, obj->short(1));
				else list += sprintf("  [%2d] %-9s目前不在线上。\n", i+1, capitalize(friend_user[i]));
			} else if( file_size(DATA_DIR+"login/"+ friend_user[i][0..0] +"/"+ friend_user[i] +__SAVE_EXTENSION__) > 0 )
				list += sprintf("  [%2d] %-9s目前不在线上。\n", i+1, capitalize(friend_user[i]));
			else {
				list += sprintf("  [%2d] %-9s"HIR"已经", (i+1), capitalize(friend_user[i]));
				if (file_size(DATA_DIR+"login/"+ friend_user[i][0..0] +"/"+ friend_user[i] + ".ppp") > 0)
					list += "被删除";
				else list += "自杀";
				list += "了。\n"NOR;
			}
		} 
		write(list);
		return 1;       
	} else {
		if( arg == "-all" ){
			if( !wizardp(me) )
				return notify_fail("-all 为巫师专用。\n");
			else me->start_more( FINGER_D->finger_all() );
			return 1;
		}
		
		if( sizeof(friend_user) && sscanf(arg,"-d %s", arg) ) {
			if( friend_user -= ({ arg }) )
				if( me->set("friend_user", friend_user) )
					return notify_fail("你将 "+capitalize(arg)+" 从好友名单移除了。\n");
			else return notify_fail("你的好友名单中并没有 "+capitalize(arg)+" 这个人。\n");
		}
		
		else if( sscanf(arg, "-a %s", arg) ) {
			if( arg==me->query("id") )
				return notify_fail("你脑袋有问题吗？xixi\n");
				
			if (!sizeof(friend_user)) {
				if (me->set("friend_user", ({arg})))
					return notify_fail("你成功的将 "+capitalize(arg)+" 加入好友名单里面。\n");
			}

			if (member_array(arg, friend_user) != -1)
				return notify_fail("好友名单中已经有此人了。\n");

			if (sizeof(friend_user) > 9)
				return notify_fail("好友名单最多为十位，请先确定人数。\n");
				
			if( file_size(DATA_DIR+"login/"+arg[0..0]+"/"+ arg +__SAVE_EXTENSION__) < 0 )
				return notify_fail("没有这位使用者。\n");
				
			friend_user = sort_array(friend_user + ({ arg }), 0);

			if (me->set("friend_user", friend_user))
				return notify_fail("你成功的将 "+capitalize(arg)+" 加入好友名单里面。\n");

			return notify_fail("将 "+capitalize(arg)+" 加入好友名单失败！请通知巫师。\n");
		} else {
			if( !wizardp(me) ) {
				if( me->is_busy() ) return notify_fail("你正忙着呢。\n");
				if( (int)me->query("jing") < 50 ) return notify_fail("你的精神无法集中。\n");
				me->receive_damage("jing", 50);
				me->start_busy(1+random(2));
			}
			write( FINGER_D->finger_user(arg) );
		}
	}
	
	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
指令格式：finger [-a|-d|-all] 
	  finger <id>
	  finger
--------------------------------------------------
 finger [使用者姓名]   : 获取此人的资料
 finger -a [加入好友]  : 将此人加入好友名单
 finger -d [移除好友]  : 将此人从好友名单中删除
 finger		: 显示好友名单
 finger -all	   : 全部玩家详细资料(巫师专用)
--------------------------------------------------

HELP
    );
    return 1;
}
