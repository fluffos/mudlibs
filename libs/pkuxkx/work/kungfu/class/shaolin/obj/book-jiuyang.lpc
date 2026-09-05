inherit ITEM;
void create()
{
        set_name("九阳神功", ({ "jiuyang shengong", "book" }));
        set_weight(600); 

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张羊皮纸，一面有毛，一面光滑，上面写着“九阳神功心法”。\n");
                set("value", 1000);
                set("material", "cloth");
                set("skill", ([
                        "name": "jiuyang-shengong",
             "exp_required": 50000,
                        "jing_cost":    40,
                        "difficulty":   30,
                        "max_skill":    100
                ]) );
        }
  }
