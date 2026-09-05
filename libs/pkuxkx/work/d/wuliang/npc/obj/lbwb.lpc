// lbwb_book.c 
// by paladin

inherit ITEM;

void create()
{
        set_name("凌波微步图谱", ({ "lingbo-weibu", "tu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "
帛卷上源源皆是裸女画像，或立或卧，或现前胸，或见后背，人像的面容都是一般，\n
但或喜或愁，或含情凝眸，或轻嗔薄怒，神情各异。一共有三十六幅图像，\n
每幅像上均有颜色细线，注明穴道部位及练功法诀. 无数足印，注明“妇妹”“无妄”\n
等等字样，足印密密麻麻，不知有几千百个，自一个足印至\n
另一个足印均有绿线贯串，线上绘有箭头，料是一套繁复的步法。写着一行字\n
道：“猝遇强敌，以此保身，更积内力，再取敌命。”\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "lingbo-weibu",     // name of the skill
                         "exp_required": 0,      // minimum combat experience required

                          "jing_cost":    50,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
        "max_skill":    100 
                ]) );
        }
}
