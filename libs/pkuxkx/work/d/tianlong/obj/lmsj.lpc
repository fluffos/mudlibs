// jianpu.c
// by paladin


inherit ITEM;

void create()
{
        set_name("六脉神剑剑谱", ({ "liumai-shenjian jianpu", "jianpu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"六脉神剑剑谱由六幅图形组成, 每幅图上都是纵横交叉的直线、圆圈和弧形.\n
顺着经脉图上的工线一路看去，自也最而至大渊，随即跳过来回到尺泽，\n
再向下而至鱼际，虽然盘旋往复\n");
                set("value", 10000);
                set("material", "paper");
                set("skill", ([
       "name":                 "finger",        // name of the skill
       "exp_required": 2000,         // minimum combat experience required
                                                                               
// to learn this skill.
      "jing_cost":            20,       // jing cost every time study this
      "difficulty":   20,               // the base int to learn this skill
                                                                               
// modify is jing_cost's (difficulty - int)*5%
"max_skill": 150 //max skill
                                                                               
// from this object.
                ]) );
        }
}
