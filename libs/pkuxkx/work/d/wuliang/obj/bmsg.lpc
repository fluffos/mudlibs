// beiming-shengong.c
// by paladin

inherit ITEM;
void create()
{
        set_name("北冥神功图谱", ({ "beiming shengong", "book" }));
        set_weight(600);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", " 
这是个卷成一卷的帛卷. 帛卷上赫然画一个横卧的裸女画像，全身一丝不挂.
只见有一条绿色细线起自左肩，横至颈下，斜行而至右乳. 绿线通至腋下，
延至右臂，经手腕至右手大拇指而止。另一条绿线却是至颈口向下延伸，
经肚腹不住向下，至离肚脐数分处而止。线旁以细字注满了“云门”、
“中府”、“天府”、“侠白”、“尺泽”、“孔最”、“列缺”、“经渠”、
“大渊”、“鱼际”等字样，至拇指的“少商”而止. 北冥大水，非由自生。
语云：百川汇海，大海之水以容百川而得. 汪洋巨浸，端在积聚.\n");
                set("value", 1000);
                set("material", "silk");
                set("skill", ([
                        "name": "beiming-shengong",

               "exp_required": 100000,
                        "jing_cost":    50,
                        "difficulty":   30,
   "max_skill": 120

                ]) );
        }
  }

