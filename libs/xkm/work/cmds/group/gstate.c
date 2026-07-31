// by tiantian(www.wangcf.com) 2001.4
// 查看本帮详细信息

#include <ansi.h>
#include <group.h>

int main(object me)
{
	string str;
	object home, ob;

	seteuid(getuid());

	if( !me->query( "group" ) )
		return notify_fail( "你并没有加入任何帮派。\n" );

	home = load_object( GROUP_D->query_home( me ) );

	str = sprintf(""HIR"帮派名称\t"+to_chinese( me->query("group/group") )
		+"(" +me->query("group/group")+")\n");

	str += sprintf(""HIY"目前人口\t"+home->query("people")+" 人\n");

	str += sprintf(""HIW"帮派资金\t"+home->query("gold")+" 两黄金\n");

	ob = new( LOGIN_OB );
	ob->set( "id", home->query("master") );
	ob->restore();

	str += sprintf(""HIG"现任帮主\t" + ob->query("name")
		+ "(" + ob->query( "id" ) + ")\n" NOR);

	str += sprintf( "共 " + home->query( "room" ) + " 间房间\t" );
	str += sprintf( "可建额度 " + home->query("room_max") + " 间\n" );
	
	str += sprintf( "共 " + home->query("npc") + " 个NPC\t" );
	str += sprintf( "可建额度 " + home->query("npc_max") + " 个\n" );
	
	str += sprintf( "共 " + home->query("item") + " 个物品\t" );
	str += sprintf( "可建额度 " + home->query("item_max") + " 个\n\n" );

	write(str);
	return 1;
}

int help(object me)
{
        write(@HELP
----------------------------------------
指令格式：gstate

显示所在帮派的详细信息。

相关命令：group

----------------------------------------
HELP
        );
        return 1;
}

