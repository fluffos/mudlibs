//国书
//create by zine 29/3/2011
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(YEL"国信"NOR, ({ "guo xin","xin", "letter"}));
	set_weight(50);
	set("long", "这是一封国信。\n");
	set("material", "paper");
	set("unit", "封");
	set("value", 0);
	setup();
}
int set_long(object me)
{
	string *countries=({"蒙古国","大理国","西夏国"});
	int n=random(sizeof(countries)),length,*lengths=({5,7,9,11}),i=1;
	string new_cont="▓▓▓▓國書▓▓▓▓\n",cont,contents=countries[n]+"皇帝谨致书于大宋皇帝阙下如此如此这般这般不知所云";
	length=lengths[random(sizeof(lengths))];
	while (strwidth(contents)>=length)
	{
		length=lengths[random(sizeof(lengths))];
		cont=contents[0..length];
		me->set_temp("songtasks/guoxin/line"+i,cont);
		i+=1;
		contents=replace_string(contents,cont,"");
		new_cont+=sprintf("%-4s%-13s%4s\n","▓",cont,"▓");
	}
	if (contents!="")
	{
		new_cont+=sprintf("%-4s%-13s%4s\n","▓",contents,"▓");
		me->set_temp("songtasks/guoxin/line"+i,contents);
		me->set_temp("songtasks/guoxin/total_line",i);
	}
	else
	me->set_temp("songtasks/guoxin/total_line",i-1);
	new_cont+="▓▓▓▓▓▓▓▓▓▓\n";
	new_cont=replace_string(new_cont,"▓",HIY+"▓"+NOR);
	new_cont=replace_string(new_cont,"國書",HIY+"國書"+NOR);
	set("long", "这是一封"+countries[n]+"送来的的国信。\n");
	set("contents",HIY+new_cont+NOR);
	return 1;
}

int do_read()
{
	object me=this_player();
	message_vision("$N展开国书开始读了起来……\n",me);
	tell_object(me,this_object()->query("contents"));
	message_vision("$N读完，把国书放了回去。\n",me);
	destruct(this_object());
	return 1;
}

void init()
{
	add_action("do_read","read");
}