
 
inherit ITEM;

void create()
{
   set_name("请柬", ({"qing jian","jian"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一封请柬。\n");
                set("unit", "封");
				set("li_songxin_job",1);
                
        }
}

