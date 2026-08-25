#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_LIGHTABLE;
inherit M_VALUE;
int fun;
int lighten;
string *sname=({HIR"仙童报喜"NOR,HIY"金龙吉祥"NOR,HIB"鸳鸯双飞"NOR,
HIG"火树银花"NOR,HIW"子孙满堂"NOR,HIM"紫气东来"NOR,});
string *chaois=({
   HIY"一串焰火互相追逐着冲上天空，又互相追逐着在空中绽开，组成了一张灿烂的笑脸。\n"NOR,
  HIY"金色的光焰在天空盘桓不去，有如一条金色飞龙，预报着吉祥。\n"NOR,
HIR"“砰砰砰砰”，无数烟花划破宁静的夜空，顿时漫天都是花的海洋。\n"NOR,
HIW"一颗小小光球飞上天际，炸开时却聚而不散，宛如一道闪烁的银河，从天上一直铺到地上。\n"NOR,
HIR"两股焰火交叉而起，再同时炸开，交织成相依相伴的两色花朵。\n"NOR,
HIR"“砰”的一声，焰火在高空分了开来，四散的火花打出了浪漫的“我爱你”三个红字。\n"NOR,
HIY"一道金色的火焰冲上蓝色的夜空，再迸裂开来，散做千千万万朵小小的金花。\n"NOR,
	});
void delay();

void setup()
{	
	string name=sname[random(sizeof(sname))];
	set_id("firework", name);
	set_unit("只");
	set_gettable(0);
	set_size(1);
	fun = random(10);
	lighten =0;
return;
}

string long()
{
	return "匠人精心制作的焰火，放放看就知道了。(light firework)\n";
}

int light()
{
	string who;
	int i;
	if(lighten)
	{write("正在点呢。\n");
	return 0;
	}
	lighten = 1;
	who = this_body()->query_name();
	DELAY_D->delay_simple_action(this_body(),"$N小心翼翼的靠近烟火，探出手去想点燃它。\n",2);

	while(random(5)<2)
	{  DELAY_D->delay_simple_action(this_body(),"$N手颤抖得厉害，怎么也点不着焰引。\n",5);
		
	}
	
	DELAY_D->delay_simple_action(this_body(),"$N鼓足勇气，闭上眼睛，拼命一点！着了！\n",5);
	DELAY_D->delay_simple_action(this_body(),"$N一个后空翻，翻出了三丈之外。\n",6);
	
	DELAY_D->delay_simple_action(this_body(),"$N紧张的看着燃烧中的烟火。\n",8);
	write("\n");

	call_out("delay",12);
	return 1;
}


void delay()
{	string msg;

	remove_call_out("delay");
	switch(fun)
	{
	case 0:
	case 1:
	write(HIB"焰引烧到尽头，一阵青烟冒起，却什么也没发生。原来是个哑炮。\n");
	break;
	case 2:
	write(HIR"焰引烧到尽处，红光一闪，“砰”的一声巨响，炸了个满堂春。\n");
	break;
	default:

write(HIR"焰引烧到尽处，“嗖”的一声，美丽的烟火在众人的喝彩中冲天而起。\n");
	msg = chaois[random(sizeof(chaois))];
	tell(users(),"%^H_RED%^【庆典】"+msg);
	break;
	}
	destruct(this_object());
}

		
