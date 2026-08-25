#include <mudlib.h>
#include <ansi.h>
#include <bodyslots.h>

inherit M_GETTABLE;
inherit M_WEARABLE;
inherit M_VALUE;
string *sname=({HIR"红",HIY"黄",HIB"蓝",HIG"绿",HIW"白",HIM"紫",});
string *adjtive=({"华贵的","雍容的","艳丽的","俏丽的","静谧的","含羞的",
"清雅的","轻柔的","妩媚的"});

void setup()
{	
	string name=sname[random(sizeof(sname))]+"牡丹"NOR;
        string adjt=adjtive[random(sizeof(adjtive))];
	set_id("flower", name);
	set_unit("朵");
	set_adj(adjt);
	set_gettable(1);
        set_slot(HEAD);
        set_wearmsg("$N轻轻将$o插在鬓旁，宛然一笑。\n");
        set_removemsg("$N取下鬓旁的$o，轻轻挽起飘散的一绺长发。。\n");
	set_size(1);
	set_attack_ability(0);
 	set_defence_power(0);
        set_defence_ability(0);
        set_rongmao(5);
	return;
}

string long()
{
	return "洛阳牡丹花圃中育出的良种牡丹，美丽华贵。\n";
}
