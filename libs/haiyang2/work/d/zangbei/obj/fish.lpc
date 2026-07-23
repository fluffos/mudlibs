 inherit ITEM;
inherit F_FOOD; 
void create()
{
        int i;
        string *names = ({ "草鱼", "银鱼", "柳条鱼" });
        i = random(3);
        set_name(names[i], ({ "fish" }) );
        set_weight(500);
        if( clonep() )
            set_default_object(__FILE__);
        else {
                set("long", "这是一条刚刚钓上来的鲜鱼。\n");
                set("unit", "条");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 10);
                set("marks/catfood", 1);
        }
        
} 
