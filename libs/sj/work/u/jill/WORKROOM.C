inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", NOR HIM"爱的小屋"YEL);
        set("long",
    "这里是爱你的工作室，平时她就是在这里进行开发的。
东边放着一张"HIW"床(bed)"NOR"，西边放着一个"HIY"佛像(xiang)"NOR"，北边
放着一台电脑。\n
    这里虽然是爱你的工作室，但是它也随时为一些无家
可归的人提供方便。在这些人中 "HIW BLINK"伟弟(Vdi)"NOR" 是最常来的
一个。\n"
);
        set("item_desc", ([
                "bed" : HIC"这是一张摆入很整齐的床!\n"NOR,
                "xiang" : HIY"这尊像看起来很名贵，不仅使人想拜它一拜！\n"NOR,
        ]));

        set("exits", ([
        "out" : "/d/wizard/guest_room",
        ]));
        setup();
}
void init()
{
        add_action("do_use","use");
        add_action("do_koubai","koubai");
}
int do_use(string arg)
{
        object me=this_player();
        object ob;
        if(me->query("id")!="jill")
        return notify_fail("你是谁呀？你要干嘛？？\n");
        
        me->set("title",HIY BLINK"开创星战新纪元"NOR);
        return 1;
}
int do_koubai(string arg)
{
        object me=this_player();
        object ob;
        int jing,jingli,neili,qi,water,food;

        if(!arg  || arg=="")
        return notify_fail("你要做什么呀！\n");
        neili=me->query("max_neili");
        qi=me->query("max_qi");
        water=me->max_water_capacity();
        food=me->max_food_capacity();

        if(arg=="xiang")
        {
        me->set("neili",neili);
        me->set("qi",qi);
        me->set("water",water);
        me->set("food",food);
        message_vision(HIY "$N跪下来向佛像参拜。\n" NOR,this_player());
        message_vision(HIY "这时$N感到全身很舒畅.\n"NOR,this_player());
        return 1;
        }
}
