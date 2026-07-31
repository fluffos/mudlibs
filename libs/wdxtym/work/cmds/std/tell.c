#include <ansi.h>
#include <net/dns.h>
inherit F_CLEAN_UP;
#define DEBUG "snowsot"
#ifdef DEBUG
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
    int i;
    object *str;
    str=users();
    for (i=0;i<sizeof(str);i++)
	if (str[i]->query("id")==target){
	      if (!environment(str[i])) return 0;
	      else
	    return str[i];
	 }
    return 0;
}
int help(object me);
void create() {seteuid(getuid());}
int main(object me, string arg)
{
    string target, msg, mud;
    object obj;
    if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
    if( userp(me) && !wizardp(me)) {
	if (me->query("chblk_tell")+300>time())
	    return notify_fail("你现在喉咙嘶哑,半句话也说不出了。\n");
       me->add_temp("tell_msg_cnt", 1);
       if (me->query_temp("tell_msg_cnt")>5)
	    if (time()-me->query_temp("tell_time")<2)
		me->set("chblk_tell",time());
	    else
		me->delete_temp("tell_msg_cnt");
    }

    if( sscanf(target, "%s@%s", target, mud)==2 ) {
	GTELL->send_gtell(mud, target, me, msg);
	write(BOLD "网路讯息已送出，可能要稍候才能得到回应。"NOR"\n");
	return 1;
    }
    obj = find_player(target);
    if (obj && !userp(me)){
	tell_object(obj, sprintf(BOLD "%s千里传音你：%s"NOR"\n",
	me->name(1)+"("+me->query("id")+")", msg));
	return  1;
    }
    if (!obj) return notify_fail("没有这个人....。\n");
    if (!me->visible(obj)) return notify_fail("没有这个人....。\n");
    if (!interactive(obj)) return notify_fail("没有这个人....。\n");
    if (obj==me) return notify_fail(PTEXT("你在自言自语的不知道在说什么...\n"));
    debug(sprintf( YEL "%s(%s)告诉%s(%s)：%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), msg));
    if ( member_array("tell", me->query("channels"))==-1)
			me->set("channels", me->query("channels") + ({ "tell" }) );
    write(BOLD+HIG "你千里传音" + obj->name(1) + "：" + msg + ""NOR"\n");
    if ( (pointerp(obj->query("channels")) && member_array("tell", obj->query("channels"))==-1) && !wizardp(me))
	return notify_fail("但"+obj->name(1)+"已经把tell频道关掉了....。\n");
    if (me->id(obj->query("env/no_tell")) )
	return notify_fail("很显然，"+obj->name(1)+"在生你的闷气，不想和你说话....。\n");
    tell_object(obj, sprintf(BOLD+HIG "%s千里传音你：%s"NOR"\n",
	me->name(1)+"("+me->query("id")+")", msg));
    if (query_idle(obj)>120) write(YEL+"但是"+obj->name(1)+"已经发呆"+query_idle(obj)/8640000+"分钟，看来不会马上回答你哟！\n"+NOR);
   if (in_edit(obj)) return notify_fail("但是，对方好像正在编辑档案！\n");
    obj->set_temp("reply", me->query("id"));
    return 1;
}
string remote_tell(string cname, string from, string mud, string to, string msg)
{
    object ob;
    if( ob = find_player(to) ) {
	if( cname )
	    tell_object(ob, sprintf(PTEXT(BOLD "%s(%s@%s)千里传音你：%s"NOR"\n"),
		cname, capitalize(from), mud, msg ));
	else
	    tell_object(ob, sprintf(PTEXT(BOLD "%s@%s 千里传音你：%s"NOR"\n"),
		capitalize(from), mud, msg ));
	ob->set_temp("reply", from + "@" + mud);
	return ob->name(1);
    } else
	return 0;
}
int help(object me)
{
    write(@HELP
指令格式：tell <某人> <讯息>
你可以用这个指令和其他地方的使用者说话。
其他相关指令：reply
HELP
    );
    return 1;
}

