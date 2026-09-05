inherit ITEM;

#include <ansi.h>

string* name = ({"避孕套","跳蛋","按摩棒","皮鞭","手铐","蜡烛","印度神油","金刚丸","金枪不倒丹","如狼似虎膏","干菜烈火露","郎情妾意蜜","春光乍泄衣"});
string* id = ({"tao","tiao dan","bang","bian","shou kao","la zhu","shen you","wan","dan","gao","lu","mi","yi"});
string* color = ({RED,HIR,BLU,HIB,WHT,HIW,YEL,HIY,GRN,HIG,CYN,HIC,MAG,HIM});

void create()
{
    int i = random(sizeof(name));
    int j = random(sizeof(color));

        set_name(color[j]+name[i]+NOR, ({id[i]}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 1000000);
        }
}
