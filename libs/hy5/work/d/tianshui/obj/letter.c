// letter.c
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("密信", ({ "letter"  }) );
    set("unit", "封");
    set("long","兄长大人台鉴：
    小弟今得到一奇物，为一柄宝剑，多请高手，
均不能将宝剑从剑鞘中拔出，鞘上遍书梵文，也无
一人能识，似乎有重大的秘密。弟想中原多能人，
将此物托日月镖局送与兄长，多请能人，望能揭开
此秘密为盼。
		弟 百万 敬上\n");
    set_weight(50);
    setup();
}