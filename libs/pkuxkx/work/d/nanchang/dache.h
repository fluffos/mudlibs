

void init()
{
    add_action("do_qu", ({"qu"}));
    add_action("do_drink", ({"drink","he"}));
    add_action("do_na",({"na",}));
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 450);
                tell_object(me,"你端起桌上冰镇好的竹叶青，一口喝了下去。\n");
        }
        else tell_object(me,"你已经喝饱了，一滴也喝不下去了。\n");

        return 1;
}

int do_na()
{
    string* obj = ({
       
	   "/d/city/npc/obj/yyfood2",
	   "/d/city/npc/obj/yyfood3",
	   "/d/city/npc/obj/kmfood1",
       "/d/city/npc/obj/kmfood2",
       "/d/city/npc/obj/kmfood3",
       "/d/city/npc/obj/ncfood1",
       "/d/city/npc/obj/ncfood2",
       "/d/city/npc/obj/jzfood1",
       "/d/city/npc/obj/jzfood2",
       "/d/city/npc/obj/jzfood3",
       "/d/city/npc/obj/zjfood1",
       "/d/city/npc/obj/zjfood2",
       "/d/city/npc/obj/zjfood3",
   });
   object me=this_player();
   object food;
   if (me->query_temp("guche/food"))
   {
       tell_object(me,"你再想拿发现桌上的食物都被拿光了。\n");
       return 1;
   }
   else
    {
       food = new( obj[random(sizeof(obj))] );
       if (food)
       {
            tell_object(me,"你拿起了桌上的一份"+food->query("name")+"。\n");
            food->move(me);
            me->set_temp("guche/food",1);
            return 1;
       }
       else
        {
           tell_object(me,"你再想拿发现桌上的食物都被拿光了。\n");
           return 1;
        }
    }
}