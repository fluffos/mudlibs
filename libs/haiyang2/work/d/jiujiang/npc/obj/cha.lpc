
 
inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
   set_name("满春茶", ({"cha"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是九江春在楼的满春茶。\n");
                set("unit", "壶");
                set("value",300);
                set("no_decay",1);
                set("food_remaining",80);
                set("food_supply",80);
        }
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   object ob;
   ob=this_player();
   if(!arg||arg!="cha")
   return notify_fail("你要吃什么？\n");
   if(environment(this_object())!=ob)
   return notify_fail("你身上没有这个东西。\n");
   ob->add("food",80);
   ob->add("water",80);
   message_vision("$N吃了一口"+query("name")+"，觉得舒服极了。\n",ob);
   destruct(this_object());
   return 1;
}