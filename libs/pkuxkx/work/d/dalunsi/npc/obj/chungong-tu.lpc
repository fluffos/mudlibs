#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_look","read");
        add_action("do_look","open");
        add_action("do_look","look");
        add_action("do_look","l");
}
void create()
{   
        set_name(HIM"春宫图"NOR, ({"chungong tu", "tu"}));
    if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long", 
                        HIY"这是一本以图解方式流传的春宫图，听说还有压邪避灾的作用。\n"NOR);
                set("value", 0);
        }
        setup();
}

int do_look(string arg)
{
        object me;
        if(arg!="chungong tu"&&arg!="tu")
                return 0;
        me=this_player();
        if (me->query("age")<18)
                return notify_fail("你年纪还小，看了这个恐怕还把持不住！");
        tell_object(me,HIY"你慢慢打开春宫图，欣赏了起来。\n\n"NOR);
        tell_object(me,HIY"你翻开春宫图专注的看着，不一会只觉呼吸急促，浑身躁热起来。\n"NOR);
//      tell_object(me,HIR+"
//                  蒙古今率数万之众，兴无名之师，阀我大宋，\n
//              现已兵临襄阳城下，然朝廷无能，迟不见援兵来\n
//              襄阳拒敌。当此国难之际，凡大宋子民当舍生取\n
//              义，共拒强敌．危难之际，多说无益，望火速赶\n
//              赴襄阳，共聚大义！\n
//              　　　　　　　　来援为盼!\n
//                                         　　　  郭靖字\n\n"NOR);
        switch(random(3)) {
          case 0:            
                message("vision", me->name() + "躲在角落里，偷偷摸摸在看什么东西。\n", environment(me), me);
          case 1:            
                message("vision", me->name() + "面色潮红，眼角含春，不知道是不是中邪了。\n", environment(me), me);
          case 0:            
                message("vision", me->name() + "呼呼的只喘粗气，两只眼睛色迷迷的偷偷的打量周围的人。\n", environment(me), me);
          }
        return 1;
}




