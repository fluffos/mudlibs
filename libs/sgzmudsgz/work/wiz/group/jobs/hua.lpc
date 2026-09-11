#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_GETTABLE;
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
	return;
}

string long()
{
	return "洛阳牡丹花圃中育出的良种牡丹，美丽华贵。\n";
}
