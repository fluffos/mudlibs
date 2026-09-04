// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"万年寒冰"NOR, ({ "bing" }) );
        set("long",
HIW"大雪山中最上乘的灵丹妙药。\n"NOR);
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
        ob->set_skill("blade",50);
        ob->set_skill("throwing",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("literate",50);
        ob->set_skill("bainiao-jian",50);
        ob->set_skill("bingpo-blade",50);
        ob->set_skill("cuixin-zhang",50);
        ob->set_skill("dengxian-dafa",50);
        ob->set_skill("ningxie-force",50);
        ob->set_skill("xiaoyaoyou",50);
write(HIW+"吃下一颗万年寒冰，只觉得一种神力融入你的体内!顿时你对大雪山的武功有所大悟。\n"NOR);

        message("vision", HIW + ob->name() + 
"吃下一颗万年寒冰，只觉得一种神力融入他的体内!顿时他对大雪山的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
