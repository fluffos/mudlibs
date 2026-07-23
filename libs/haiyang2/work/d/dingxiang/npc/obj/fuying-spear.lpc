//Edit By Subzero
#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
        set_name(CYN"伏鹰枪"NOR,({ "fuying qiang", "qiang", "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 15000);
                set("material", "steel");
                set("rumor", 1);
                set("no_sell", 1);
                set("super", 6);
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -5);
                set("wield_neili", 300);
                set("wield_maxforce", 800);
                set("wield_str", 23);
                set("long", CYN"伏鹰枪相传为波斯巧匠所作的短杆马枪，并带有血槽，枪身上还装有被雕琢成飞鹰形状的枪档，
更增加其伤敌能力。此枪为突厥可汗突利所用，伏鹰枪再配合突利可汗的龙卷枪法更添威势，每
每枪招一出，对手非死即伤。
\n"NOR);
                set("wield_msg", CYN"$N"+CYN+"把短杆的$n"+CYN+"重重在地面顿了一下，生出仿若能摇撼整闲食肆震摄人心的响音。\n"NOR);
                set("unwield_msg", WHT "$N"+WHT+"随手舞出一片枪花，枪花散尽，$n"+WHT+"已被你收在身后。\n" NOR);                
        }
   init_club(380);
        setup();
}
