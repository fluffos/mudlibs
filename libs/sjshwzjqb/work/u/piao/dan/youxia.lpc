// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"大活络丹"NOR, ({ "dan" }) );
        set("long",
HIW"江湖中流传的最上乘的灵丹妙药。\n"NOR);
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
ob->set("combat_exp",100000);
        ob->set_skill("force",80);
        ob->set_skill("parry",80);
        ob->set_skill("dodge",80);
        ob->set_skill("sword",80);
        ob->set_skill("unarmed",80);
        ob->set_skill("literate",80);
        ob->set_skill("tianjijue",50);
        ob->set_skill("spells",50);
        ob->set_skill("lingxiyizhi",50);
        ob->set_skill("baiyun-sword",50);
        ob->set_skill("wuji-force",50);
        ob->set_skill("piaoxiang",50);
write(HIC+"吃下一颗大活络丹，只觉得一种神力融入你的体内!顿时你对游侠的武功有所大悟。\n"NOR);

        message("vision", HIW + ob->name() + 
"吃下一颗大活络丹，只觉得一种神力融入他的体内!顿时他对游侠的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
