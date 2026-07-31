// chuzi.c 厨子

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(WHT"小圆子"NOR, ({"chu zi","chuzi"}));
        set("title", HIC"小厨子"NOR);
        set("gender", "男性" );
        set("age", 16);
        set("long", "一个吃的胖胖的小道士，正在烧火．\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();

}
void init()
{
::init();
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$N向厨子问道：兄弟，开饭了吗？\n", this_player());

        if((int)this_player()->query("food") >=(int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("厨子笑道：没那，等开饭时再来吧！\n");

        if((present("bao zi", this_player())))
        return notify_fail("厨子笑道：不要拿着手里的，还看着锅里的！￥？\n");
	
	if ( present("bao zi", environment()) )
                return notify_fail("厨子笑道：那不是有一块呢嘛，吃完再说！\n");

        m=new("/d/xiyou/sanjie/obj/gourou");
        mm=new("/d/xiyou/sanjie/obj/gourou");


        m->move(this_player());
        mm->move(this_player());

        message_vision("厨子对$N笑道：饿了吧，慢点吃。\n", this_player());
return 1;
}

