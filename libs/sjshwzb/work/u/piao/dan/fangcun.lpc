// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"灵台仙丹"NOR, ({ "dan" }) );
        set("long",
HIC"方寸山中最上乘的灵丹妙药。\n"NOR);
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
ob->set_skill("literate",100);
ob->set_skill("dodge",100);
ob->set_skill("sword",100);
ob->set_skill("liangyi-sword",100);
ob->set_skill("force",100);
ob->set_skill("spells",100);
ob->set_skill("stick",100);
ob->set_skill("unarmed",100);
ob->set_skill("dao",100);
ob->set_skill("jindouyun",100);
ob->set_skill("puti-zhi",100);
ob->set_skill("qianjun-bang",100);
ob->set_skill("wuxiangforce",100);
ob->set_skill("parry",100);
write(HIW+"你吃下一颗灵台仙丹，只觉得一种神力融入你的体内!顿时你对方寸山的武功有所大悟。\n"NOR);

        message("vision", HIW + ob->name() + 
"吃下一颗灵台仙丹，只觉得一种神力融入他的体内!顿时他对方寸山的武功有所大悟。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
