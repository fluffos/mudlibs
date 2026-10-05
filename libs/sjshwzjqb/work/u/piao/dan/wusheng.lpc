// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"武圣降龙丹"NOR, ({ "dan" }) );
        set("long",
HIY"武圣门中最上乘的灵丹妙药。\n"NOR);
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
        ob->set_skill("literate",50);
        ob->set_skill("feisheng",50);
        ob->set_skill("fumobashi",50);
  ob->set_skill("mizongbu",50);
     ob->set_skill("spells",80);
        ob->set_skill("wuying",50);
        ob->set_skill("xiantian",50);
write(HIY+"你吃下一颗武升降龙丹，只觉得一种神力融入你的体内!顿时你对武圣门的武功有所大悟。\n"NOR);

        message("vision", HIY + ob->name() + 
"吃下一颗武升降龙丹，只觉得一种神力融入他的体内!顿时他对武圣门的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
