// door.c
// by augx@sj  3/27/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"石门"NOR, ({ "shi men","men","door" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", HIW"这是一座坚固的石门。\n上面刻着几个篆头大字“帮派重地，擅入者死!”。\n"NOR);
		set("value", 10000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}
	set("open",0);
	set("attack",0);
	set("hp",2000);
	set("max_hp",2000);
	setup();
}

void init()
{
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());
	string * sv;
	int i;

	if( !arg || !id(arg) || env!=me ) return 0;
	env = environment(me);
	if( !me->query("group/id") ) {
		tell_object(me,"你并没有开帮立派，要"+name()+"何用？\n");
		return 1;
	}
	if( !env ) {
		tell_object(me,name()+"不能放在这里！\n");
		return 1;
	}

	if( mapp( env->query("exits") ) ) {
		sv = values( env->query("exits") );
		for(i=0;i<sizeof(sv);i++)
			if( strlen(sv[i])>14 && sv[i][0..14]=="/d/group/entry/" )
				break;
		if( i >= sizeof(sv) ) {
			tell_object(me,name()+"只能放在帮会和外界相连的地方！\n");
			return 1;
		}
	}

	if( present(query("id"),env) ) {
		tell_object(me,"这里不是已经有了一"+query("unit")+name()+"了吗？\n");
		return 1;
	}

	if( !GROUP_D->site_now(me->query("group/id")) ) {
		tell_object(me,GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_object(this_object(),me,env,"$N开始建造"+name()+"……\n","你忙碌了半天，总算把"+name()+"建造好了。\n");
	return 1;
}

void do_name()
{
	set("name",HIW+(query("open")?"敞开":"关闭")+HIW"的石门"NOR);
}

varargs int move(mixed dest, int silently)
{
	int result;
	if( !(result = ::move(dest,silently)) ) return result;
	if( !objectp(dest) || clonep(dest) ) return result;
	if( !dest->query("group2") ) return result;

	do_name();
	return result;
}
