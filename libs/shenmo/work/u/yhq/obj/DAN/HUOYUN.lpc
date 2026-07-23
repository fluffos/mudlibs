// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"三味真火丹"NOR, ({ "dan" }) );
        set("long",
HIR"火云洞中最上乘的灵丹妙药。\n"NOR);
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
ob->add("daoxing",100000);
ob->add("combat_exp",100000);
ob->add("potential",10000);
ob->set_skill("force",100);
ob->set_skill("spells",100);
ob->set_skill("parry",100);
ob->set_skill("dodge",100);
ob->set_skill("unarmed",100);
ob->set_skill("huomoforce",100);
ob->set_skill("moshenbu",100);
ob->set_skill("moyun-shou",100);
 ob->set_skill("dali-bang",100);
ob->set_skill("huoyun-qiang",100);
ob->set_skill("pingtian-dafa",100);
ob->set_skill("wuyue-spear",100);
ob->set_skill("spear",100);
ob->set_skill("stick",100);
ob->set_skill("literate",100);
write(HIR+"你吃下一颗三味真火丹，只觉得一种神力融入你的体内!顿时你对火云洞的武功有所大悟。\n"NOR);

        message("vision", HIR + ob->name() + 
"吃下一颗三味真火丹，只觉得一种神力融入他的体内!顿时他对火云洞的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
