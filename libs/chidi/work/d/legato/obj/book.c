inherit ITEM;

void create()
{
        set_name("《刀》",({"dao","book"}));
        set_weight(100);
        set("unit", "本");
        set("long",
                "一本记载刀法的武学书籍。\n"
             );
        set("value",3000);
        set("skill", ([
        "name": "blade",
        "exp_required":10000,
        "max_skill":80,
        "sen_cost":20,
        ]) );
}

