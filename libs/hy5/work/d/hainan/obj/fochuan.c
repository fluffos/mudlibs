inherit ITEM;

void create()
{
  set_name("檀木佛串", ({ "fo chuan", "chuan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
    set("long", "一百单八颗檀木珠子串成的佛串,上面微刻着一些文字
仔细看去,其文大致为:老僧大悲,一生杀人无数,晚年遁入空门,本不应再生嗔念,
唯老衲平生所学,不忍就此失传.刻于佛串,传之有缘. 
......  ......
。\n");
        set("material", "wood");
        set("skill", ([
                        "name": "blade",
                        "exp_required": 300,
			"sen_cost":20+random(11),
			"max_skill":200,
]) );
        }
}

