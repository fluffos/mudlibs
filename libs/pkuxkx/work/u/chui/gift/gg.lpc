//  礼品分发器

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("礼品分发器", ({"gift box","box"}) );
        setup();
}
void init()
{
        add_action("do_giftall","giftall");
//      add_action("do_gift",gift);
}
int do_giftall()
{
        object *usr;
        string name;
        usr=users();
	 for(int i=0;i<sizeof(usr);i++)
               {   tell_object(usr[i],HIM"\n你终于可以动了，不禁欣喜若狂！\n"NOR);
		      write(usr[i]->query("name")+"已经可以了。\n");
                   usr[i]->revive();
                    usr[i]->start_busy(0);
               }
        return 1;
}
