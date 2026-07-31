#include <ansi.h>
#include <net/dns.h>
inherit F_CLEAN_UP;
#define DEBUG "snowsot"
#ifdef DEBUG
//修复发送信息臭虫
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
   // write(arg+"\n");
    if(!arg||sscanf(arg, "%s %s", target, msg)!=2){
     target=arg;
     msg="...";
    // arg+="...";
   //  write(arg+"\n");
     //write(target+"\n");
    }
  // write(target+"\n");

    if( sscanf(target, "%s@%s", target, mud)==2 ) {
	GTELL->send_gtell(mud, target, me, msg);
	write(BOLD "网路讯息已送出，可能要稍候才能得到回应。"NOR"\n");
	return 1;
    }
    obj = find_player(target);
    if (obj && !userp(me)){
	 write(HIY+ me->name(1) + HIG"对你说：" + msg + ""NOR"\n");
	return  1;
    }
    if (!obj) return notify_fail("没有这个玩家。\n");
    if (!me->visible(obj)) return notify_fail("没有这个玩家。\n");
    if (!interactive(obj)) return notify_fail("没有这个玩家。\n");
 
    debug(sprintf( YEL "%s(%s)告诉%s(%s)：%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), msg));
    if ( member_array("tell", me->query("channels"))==-1)
		me->set("channels", me->query("channels") + ({ "tell" }) );
    write(HIG "你对" HIY+ obj->name(1) + HIG"说：" + msg + ""NOR"\n");
     
    if (me->id(obj->query("env/no_tell")) )
	return notify_fail("很显然，"+obj->name(1)+"在生你的闷气，不想和你说话....。\n");
	
	 tell_object(obj,HIY+ me->name(1) + HIG"对你说：" + msg + ""NOR"\n");
    if (me->query("env/no_tan"))	 
	 tell_object(obj,INPUTTXT(HIY+me->name(1)+HIG"对你说道："+ msg +"", "bei1 "+me->query("id")+" $txt#")+"\n");	    	    
    if (query_idle(obj)>120) write(YEL+"但是"+obj->name(1)+"已经发呆"+query_idle(obj)/8640000+"分钟，看来不会马上回答你哟！\n"+NOR);
   if (in_edit(obj)) return notify_fail("但是，对方好像正在编辑档案！\n");
    obj->set_temp("reply", me->query("id"));
    return 1;
}