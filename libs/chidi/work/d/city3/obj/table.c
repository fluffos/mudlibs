
inherit ITEM;

void create()
{
        set_name( "四方桌",({"table" }));
        set_weight(30000);
        set_max_encumbrance(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "wood");
                set("value", 2000);
                set("long", "这是一张红木四方桌，上面摆着几双筷子。\n" );
                set("no_sell", "这样东西不能随便买卖。");
                set("no_get","红木四方桌是酒楼的财产,任何人都不能拿走!");
                set("no_get_from","吃不了，也不能兜着走耶。");
        }        
        setup();
}
int is_container() { return 1; }


void init()
{
        add_action("do_look","look");
        add_action("do_eat","eat");
}
int do_look(string arg)
{
        string str1,str2;
        object ob;

        if (!arg)       return 0;
        if (sscanf(arg,"%s %s",str1,str2)!=2)
                return 0;
        if (!id(str1)) return 0;
        ob=present(str2,this_object());
        if (!ob)        return 0;
        write(ob->long());
        return 1;
}
int do_eat(string arg)
{
    object food;
    if (!arg)   return 0;
    food=present(arg,this_object());
    if (!food || !inherits(F_FOOD,food))   return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if( !food->query("food_remaining") )
        return notify_fail( food->name() + "已经被吃光了，只剩下个空"+food->query("unit")+"。\n");
    if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() ){
        write("你已经吃太饱了，再也塞不下任何东西了。\n");
                return 1;
    }
    this_player()->add("food", food->query("food_supply"));
    if( this_player()->is_fighting() ) this_player()->start_busy(2);
    // This allows customization of drinking effect.
    if( food->query("eat_func") ) return 1;
    food->set("value", 0);
    food->add("food_remaining", -1);
    if( !food->query("food_remaining") ){
        message_vision("$N将剩下的$n吃得干干净净。\n",this_player(),food );
        remove_call_out("dest_food");
        call_out("dest_food",20);
    }else{
        if (stringp(food->query("eat_msg")))
        message_vision(food->query("eat_msg"),this_player(),food );
        else
        message_vision("$N拿起筷子，夹起$n咬了一口。\n",this_player(),food );
    }
    return 1;
}
void dest_food()
{
        foreach (object food in all_inventory()){
                if (food && inherits(F_FOOD,food) && !food->query("food_remaining"))
                        destruct(food);
        }
        message("vision","一个老伙计走了上来，十分麻利地把空碟子收了起来。转身走了下楼。\n",environment(this_object()));
}

