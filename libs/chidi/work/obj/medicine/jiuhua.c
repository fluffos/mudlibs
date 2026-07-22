// jiuhua.c 九花玉露丸
// 97.9.6  by Aug

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"九花玉露丸"NOR, ({ "jiuhua","wan" }) );
        set("long",
HIM"九花玉露丸是以「东邪」黄药师的秘方，采集九种珍贵药材，费时三年
炼制而成的灵药。能大量的恢复精、气、神。\n"NOR);
        set("unit", "粒");
        set("weight", 50);
        set("value", 10000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

        ob=this_player();
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("atman", (int)ob->query("max_atman")*2);
        ob->set("force", (int)ob->query("max_force")*2);
        ob->set("mana", (int)ob->query("max_mana")*2);

        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);

        write(HIM+"你拿出一粒九花玉露丸，放入口中，吞了下去，顿时有一种飘飘欲仙
的感觉，身上病痛、疲劳似乎一下子都消失了。\n"NOR);

        message("vision", HIM + ob->name() + 
"拿出一粒九花玉露丸，放入口中，吞了下去，顿时有一种飘飘欲仙
的感觉，身上病痛、疲劳似乎一下子都消失了。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
