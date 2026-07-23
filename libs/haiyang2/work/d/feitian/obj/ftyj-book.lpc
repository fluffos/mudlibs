// ftyj-book.c 秘籍
// 青云(diabio)2001.3.4

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"飞天御剑流秘籍下册" NOR, ({ "mi ji","book", }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "本");
             set("long",
        "这是一本写在竹简上面的书，里面一少年手握一把非刀非剑的武器侧身站着。\n",
         );
         set("value", 0);
         set("material", "silk");
         set("skill", ([
                        "name":       "feitian-yujianliu",
                        "exp_required" : 150000,
                        "jing_cost":  35,
                        "difficulty": 25,
                        "max_skill":  101
                ]) );
        }
//        set("no_drop", "武功秘籍可不能随便丢弃！\n");
        set("no_give", "这样东西不能随便给人。\n");
              set("no_put", "你想把他放到哪里去？\n");
}
