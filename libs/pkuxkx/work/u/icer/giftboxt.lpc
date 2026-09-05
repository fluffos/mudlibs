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

int do_gift()
{
return 1;
}

int do_giftall(string arg)
{
    call_out("sagift",1,arg);
        return 1;
}
void sagift(string arg)
{
        object *usr;
        object gift;

        usr=users();
        gift = new(arg);
        shout(HIR"\n发礼物啦发礼物啦！光棍节每人发一个老婆！\n祝大家都找到一个如花似玉、冰雪聪明的好老婆～～～\n");
        for(int i=0;i<sizeof(usr);i++)
       {  
       	  gift = new(arg);
          gift->move(environment(usr[i]));
          gift->set("name",HIR + usr[i]->name() + "的老婆");
          gift->set("id",usr[i]->id() + "'s wife");
          gift->set_leader(usr[i]);
       }
}

