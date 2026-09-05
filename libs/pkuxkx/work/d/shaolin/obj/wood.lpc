// wood.c
//未处理的木柴，劈柴任务用到
//seagate@pkuxkx 2010/10/09

inherit ITEM;

mapping prefix=([
 "光滑的" : "smooth",
 "小段的" : "small",
 "大段的" : "large",
 "粗糙的" : "rough",
// "尖锐的" : "sharp",
// "钝的"   : "blunt",
 "弯曲的" : "bending",
 "直的"   : "straight"
 ]);

mapping wood=([
 "树枝"   : "branch",
 "树干"   : "trunk",
 "树根"   : "root",
// "树桩"   : "stump",
// "树节"   : "burl",
 "树杈"   : "crotch"
 	]);

void create()
{
	string name1,name2,*prekey, *woodkey;
  
  prekey=keys(prefix);
  woodkey=keys(wood);
  name1=prekey[random(sizeof(prekey))];
  name2=woodkey[random(sizeof(woodkey))];

	set_name(name1+name2, ({ prefix[name1]+" "+wood[name2] }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根未经处理的木柴。\n");
		set("value", 0);
		set("material", "wood");
	}
	
	set("wood",random(6)+3);
	setup();
}