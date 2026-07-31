// by tiantian(www.wangcf.com) 2001.4
// 向帮派捐赠黄金

#include <ansi.h>
#include <group.h>

int main(object me, string arg)
{
	int money;
    object gold;

    seteuid(getuid(me));
        
    if( !me->query("group")) 
        return notify_fail("你不属于某个帮派，想捐钱给谁？\n");            
                
    if( strlen( arg ) > 10 )
	    return notify_fail("想作弊赚钱呀!小心被杀挡哦!!\n"); 

    if( !arg || !sscanf(arg, "%d", money) )
	    return notify_fail("指令格式：gdonate <数目>\n");

    if( money < 1 )
	    return notify_fail("想作弊赚钱呀!小心被杀挡哦!!\n"); 

    if (!objectp(gold = present("gold", me)))
        return notify_fail("你是穷人，先把自己喂饱吧！\n");

    if ( (int)gold->query_amount() < money )
        return notify_fail("你身上现在没有那么多钱\n");

    write("你捐了"+money+"两黄金给自己的帮派！\n");
	gold -> add_amount( -money );
	load_object( GROUP_D->query_home( me ) )->add("gold",money);
    GROUP_D->save_group( me );
    return 1;
}

int help(object me)
{
  write(@HELP
----------------------------------------
指令格式 : gdenote <数目>

向自己所属的帮派捐赠黄金。

----------------------------------------
HELP
    );
    return 1;
}
