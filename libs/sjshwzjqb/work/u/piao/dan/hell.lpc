// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"阴气还阳丹"NOR, ({ "dan"}) );
        set("long",
HIB"阎罗地府中最上乘的灵丹妙药。\n"NOR);
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
        ob->set_skill("force",50);
        ob->set_skill("spells",50);
        ob->set_skill("sword",50);
        ob->set_skill("parry",50);
        ob->set_skill("dodge",50);
        ob->set_skill("spear",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("whip",50);
        ob->set_skill("literate",50);
        ob->set_skill("ghost-steps",50);
        ob->set_skill("gouhunshu",50);
        ob->set_skill("hellfire-whip",50);
        ob->set_skill("stick",50);
        ob->set_skill("kusang-bang",50);
        ob->set_skill("tonsillit",50);
        ob->set_skill("zhuihun-sword",50);
write(HIB+"你吃下一颗阴气还阳丹，只觉得一种神力融入你的体内!顿时你对阎罗地府的武功有所大悟。\n"NOR);

        message("vision", HIB + ob->name() + 
"吃下一颗阴气还阳丹，只觉得一种神力融入他的体内!顿时他对阎罗地府的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
