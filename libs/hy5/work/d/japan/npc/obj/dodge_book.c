// dodge_book.c

inherit ITEM;

void create()
{
        set_name("身法入门", ({ "shenfa rumen", "shu", "book", "rumen" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
            set("long", "这是一本讲身法入门的书。\n");
                 set("value",2000);
                set("material", "paper");
                set("skill", ([
                 "name": "dodge",
                  "exp_required": 3000,
                        "sen_cost":20+random(10),
                 "max_skill": 20,
                ]) );
        }
}
