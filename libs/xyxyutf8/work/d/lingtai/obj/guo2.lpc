// songguo.c
inherit ITEM;
inherit F_FOOD;

mapping Guo = ([
	"黑" : ({"hei songguo","一个黑色的松果。",60,}),
	"白" : ({"bai songguo","一个白色的松果，散发着清香。",80,}),
	"金" : ({"jin songguo","一个金色的松果，香气宜人。",120,}),
]);

void create()
{
	string name,*names = keys(Guo);
	name = names[random(sizeof(names))];
	set_name(name+"松果",({Guo[name][0],"song guo","guo"}));
	set("long", Guo[name][1]);
	set("unit", "个");
        set("food_remaining", 1);
        set("food_supply", Guo[name][2]);
	setup();
}

