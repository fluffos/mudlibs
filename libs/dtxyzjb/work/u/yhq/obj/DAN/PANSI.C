// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"紫霞丹"NOR, ({ "dan" }) );
        set("long",
HIM"盘丝洞中流传的最上乘的灵丹妙药。\n"NOR);
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
        ob->set_skill("force",80);
        ob->set_skill("parry",80);
        ob->set_skill("dodge",80);
        ob->set_skill("sword",80);
        ob->set_skill("unarmed",80);
        ob->set_skill("literate",80);
        ob->set_skill("jiuyin-xinjing",50);
        ob->set_skill("spells",50);
        ob->set_skill("lanhua-shou",50);
        ob->set_skill("chixin-jian",50);
        ob->set_skill("pansi-dafa",50);
        ob->set_skill("yueying-wubu",50);
write(HIM+"吃下一颗紫霞丹，只觉得一种神力融入你的体内!顿时你对盘丝洞的武功有所大悟。\n"NOR);

        message("vision", HIM + ob->name() + 
"吃下一颗紫霞丹，只觉得一种神力融入他的体内!顿时他对盘丝洞的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
