//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *inv, ob;
        string s1, s2;
        int i, j, total, t1, t2, t3, t4, temp;

        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
        }

        if( !ob ) ob = me;

        inv = all_inventory(ob);

        if( !(total = sizeof(inv) ) ) {
                write((ob == me)? "目前你身上没有任何东西。\n"
                        : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }

        printf(HIC"\n%s拥有下列%s样东西：\n"NOR,
                (ob == me)? "你": ob->name(), CHINESE_D->chinese_number(total) );
        printf("───────────────────────────────────────\n");
        
        for( i = 0; i < total; i++ ) {
			printf("  %s = %O (base_name: %s)\n"NOR, inv[i]->short(), inv[i], base_name(inv[i]));
		}
        printf("───────────────────────────────────────\n");

        return 1;
}


int help (object me)
{
        write(@HELP
指令格式：inv
          inv [人物]      （巫师专用）
 
列出目前身上所携带的所有物品。
 
相关讯息：get, drop
HELP
        );
        
        return 1;
}



