//  礼品分发器

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("属性查看器", ({"gift box","box"}) );
        setup();
}
void init()
{
        add_action("do_giftall","kanall");
}

int do_giftall(object me)
{
        object *usr;
        string str="";
        usr=users();

        for(int i=0;i<sizeof(usr);i++)
	{
                if (usr[i]->query("zuiquanpf")>0)
		{
                str+="   "+usr[i]->query("name")+"       "+usr[i]->query("zuiquanpf");
		str+="\n"; 
		}
        }
        write(str); 
        return 1;
}
