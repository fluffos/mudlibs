 inherit ITEM;
void create()
{
        set_name("暗香浮影", ({ "book", "anxiang steps", "anxiang" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "本");
            set("long",
                    "书本首页用寥寥数笔勾画出一棵雪中盛开的寒梅。\n");
            set("value", 0);
            set("no_give", 1);
            set("no_drop", 1);
            set("no_sell",1);
            set("material", "paper");
/*          set("skill", ([
                    "name": "anxiang-steps",
                    "exp_required": 5000,
                    "sen_cost": 60,
                    "difficulty": 35,
                    "max_skill": 135,
            })); */
        }
}     
