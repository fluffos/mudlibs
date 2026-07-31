#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name(HIB "四天明王轮" NOR ,({ "mingwang lun","lun" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",HIB"
四天明王轮本为军荼利明王、爱染明王、降三世明王和不动明王用自
己的黄金之血打造，后借给大孔雀王诛杀六道众中的青面金刚。事后
遗失于中国黄山，被山民拾得，辗转后世，最终下落不明。现在的四
天明王轮是以真四天明王轮的图谱打造，虽保留了锋利，却已经神力
不在。\n"NOR);
                set("value", 100000);
                set("material", "gold");
                set("wield_msg", HIB"$N将手一招，一道光华从半空降临，霎时间雷声大作，仿佛诸魔都在为四天明王轮降临人间而祝福。\n"NOR);
                set("unwield_msg","$N随手一晃，$n已化作蓝光而去。\n");
        }
        init_hammer(300);
        setup();
}
