// by snowcat oct 15 1997
inherit ITEM;

string *names = ({
  "野参果","yesen guo", "人参","ren shen",
  "雪莲","xue lian", "枸杞","gou qi",
  "灵芝","ling zhi", "铜皮石斛","shi hu",
  "佛手","fo shou","肉豆蔻","dou kou",
  "连翘","lian qiao","荆芥","jing jie",
  "茯苓","fu ling",
});

void create()
{
	string name,id;
	int i;
	i = random(sizeof(names))/2*2;
	name = names[i];
	id = names[i+1];
	set_name(name,({id,"yao cao",}));
	set_weight(1);
  	if (clonep())
    		set_default_object(__FILE__);
  	else 
  	{
    		set("long", "名贵药草，在深山之中已生长多年。\n");
    		set("unit", "株");
    		set("value", 0);
	}
}