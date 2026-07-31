// Modify By River 98/12
inherit ITEM;
void create()
{
       set_name("掌法诀要", ({ "zhangfa jueyao", "book", "jueyao" }));
       set_weight(250);
       if( clonep() )
	   set_default_object(__FILE__);
       else {
	   set("unit", "本");
	   set("long", "这是一本很破旧的小册子，只剩下前几页，画着一些练掌法的姿势。\n");
	   set("value", 500);
	   set("material", "paper");
           set("unique", 1);
           set("treasure", 1);
	   set("skill", ([
		"name":	"strike",	 
		"exp_required":	300, 
                "jing_cost":    25,   
		"difficulty":	20, 
		"max_skill":	30 
	   ]));
	}
}
