// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
  string criname,result,ia,ib,ic,id;
object obj;
object *ob;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

//	if( sscanf(target, "%s@%s", target, mud)==2 ) {
//		GTELL->send_gtell(mud, target, me, msg);
//		write("网路讯息已送出，可能要稍候才能得到回应。\n");
//		return 1;
//	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
	if(obj == me) return notify_fail("告诉自己？\n");
	if (!interactive(obj)) return notify_fail("这个人断线了。\n");
	if (!living(obj)) return notify_fail("这个人现在无法听见你的话。\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("正在拱猪的人听不到悄悄话……。\n");

	if (!wizardp(me) && obj->query("env/no_tell")=="all" + NOR)
		return notify_fail("这个人不想听你罗嗦啦。\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL" + NOR)
		return notify_fail("这个人不想听你罗嗦啦。\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id") + NOR)
		return notify_fail("这个人不想听你罗嗦啦。\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("正在拱猪的人听不到悄悄话……。\n");
        if ( ((int)time() - (int)me->query("tell_time")) < 1 )
        return notify_fail("有话好好说哦。\n");
if (me->query("combat_exp") < 100000 && strsrch(msg,"0")>=0 || strsrch(msg,"1")>=0 || strsrch(msg,"2")>=0 || strsrch(msg,"3")>=0
|| strsrch(msg,"4")>=0 || strsrch(msg,"5")>=0 || strsrch(msg,"6")>=0 || strsrch(msg,"7")>=0 
|| strsrch(msg,"8")>=0 || strsrch(msg,"9")>=0 )
{
        if( me->query("combat_exp") < 100000 && sscanf( msg, "%s.%s.%s.%s",ia,ib,ic,id) && strlen(ia)>=1  && strlen(ib)>=1
         && strlen(ic)>=1 && strlen(id)>=1 && strlen(msg)>=10
         && !wizardp(me))
        return notify_fail("做广告不好吧，那是没有道德的事!\n");
}


        write(HIG "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
        tell_object(obj, sprintf( HIG "%s告诉你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
                     me->set("tell_time", time());
//	CHANNEL_D->do_channel( this_object(), "adm", 
//		sprintf("%s告诉%s：%s。",me->name(1),obj->name(1),msg) );
//        ob=users();
        ob = filter_array(children(USER_OB),(: userp($1) && wizardp($1) :));
if (!wizardp(me) && query_ip_name(obj)!=query_ip_name(me))
{
message("channel:snp", HIB"【窃听】"+me->query("name")+"告诉"+obj->query("name")+"："+msg+"\n"NOR, ob);
}
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告诉你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告诉你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
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
