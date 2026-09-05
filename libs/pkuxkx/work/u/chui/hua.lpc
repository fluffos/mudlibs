// 恢复死前武功用。
#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("无名花", ({"hua", "wuming"}));
        set("unit", "朵");
                set("value", 30);
        set("long", "这是一朵无名小花,花蕊虽小,却十分美丽，看起来好象很可口（eat）。\n");
        setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!id(arg))  return notify_fail("你要吃什么？\n");
    if(arg=="hua") 
    {
       string *sname;    //恢复的功夫名称
       int *svalue;
       mapping skill_status;    //灵鹫宫返老还童用

                skill_status=me->query_skills("");
                sname=keys(skill_status);
                svalue=values(skill_status);

                for(int i=0; i<sizeof(skill_status); i++)                                      
               me->set_skill(sname[i],svalue[i]+1);
     me->set("channels", ({ "chat", "rumor", "new", "tt", "hslj", "baowei","sys"}) );
 me->set("str", 100);
 me->save();

     destruct(this_object());
}
return 1;
}
