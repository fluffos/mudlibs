// wan.c 气血大补丸

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"气血大补丸"NOR, ({ "wan","dabu wan" }) );
        set("long",
HIG"气血大补丸是采集九九八十一种珍贵药材，费时五百年炼制而成的灵丹。\n"NOR);
        set("unit", "粒");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->add("daoxing",1000);
        ob->add("combat_exp",10000);
        ob->add("potential",2000000);
write(HIY+"你吃下一颗气血大补丸，只觉得一种神力融入你的体内!\n"NOR);

        message("vision", HIY + ob->name() + 
"吃下一颗气血大补丸，只觉得一种神力融入他的体内!\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
