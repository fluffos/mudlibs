// file:      qc_room.h
// attrib:    headfile of qingcheng rooms
// write:     xli
// date:      1998.10
//   Last Modified:xli 1999.9


string *caiyuan_things = ({
    "一包白菜籽","一包萝卜籽","一包青菜籽","一包西瓜籽","一包苹果籽","一袋桃子核",
    "一把锄头","一个菜篮","一把铲子","一架梯子","一把砍刀","一根草绳",
});
string *mofang_things = ({
    "一袋面粉","一袋高粱","一袋玉米","一袋小麦","一袋大麦",
    "一把扫帚","一个篮子","一根鞭子","一根绳子","一块黑布",
});
string *chufang_things = ({
    "一袋面粉","一袋小米","一袋大米",
    "一袋白菜","一袋青菜","一块豆腐",
    "一把扫帚","一个篮子","一把菜刀",
});
string *things_where = ({
    "前殿","后殿","半山亭","厢房","松风观","武器房","练武厅"
});

void init()
{
    add_action("do_souxun", ({"search","souxun","sou"}));
    call_out("greeting", 1, this_player());
}

int greeting(object me)
{
    if ( random(2) == 0 && objectp(me) && environment(me) == this_object() )
    {
        tell_object(me, "一位年轻的青城弟子匆匆走过。\n");
    }

    return 1;
}

int do_souxun(string arg)
{
    object me;
    object thing;
    int place;
    int renwu_where;
    int thing_num;
    int i,times;
    int now_gin;

    me = this_player();

    renwu_where = me->query("xli_marks/renwu_where");
    // 1:厨房 2:磨房 3:菜园
    place = me->query("xli_marks/things_place");
    thing_num = me->query("xli_marks/now_thing");

    if ( (!renwu_where)
        ||  (!place) 
        ||  (!thing_num) 
        ||  (this_object()->query("short") != things_where[place-1])
        )
    {
        return 0;
    }

    if ( renwu_where == 3 ) // 在菜园
    {
        tell_object(me,"你在"+things_where[place-1]+"里所有可能找到"
                        +caiyuan_things[thing_num-1]+"的地方开始搜寻...\n");
    }

    if ( renwu_where == 2 ) // 在磨房
    {
        tell_object(me,"你在"+things_where[place-1]+"里所有可能找到"
                        +mofang_things[thing_num-1]+"的地方开始搜寻...\n");
    }

    if ( renwu_where == 1 ) // 在厨房
    {
        tell_object(me,"你在"+things_where[place-1]+"里所有可能找到"
                        +chufang_things[thing_num-1]+"的地方开始搜寻...\n");
    }

    times = random(5) + 1;
    for ( i = 0; i < times; i++ )
    {
        now_gin = me->query("gin");
        tell_object(me, "你不停地找着......\n");
        me->set("gin", (int)now_gin * 8 / 10);
    }

    if ( renwu_where == 3 )
    {
        tell_object(me, "果然发现了"+caiyuan_things[thing_num-1]+"!\n");
    }

    if ( renwu_where == 2 )
    {
        tell_object(me,"果然发现了"+mofang_things[thing_num-1]+"!\n");
    }

    if ( renwu_where == 1 )
    {
        tell_object(me,"果然发现了"+chufang_things[thing_num-1]+"!\n");
    }

    thing = new("/d/menpai/qingcheng/obj/item");

    if ( renwu_where == 3 )
    {
        thing->set_name(caiyuan_things[thing_num-1],({"item"}));
        thing->set("long",caiyuan_things[thing_num-1]);
    }

    if ( renwu_where == 2 )
    {
        thing->set_name(mofang_things[thing_num-1],({"item"}));
        thing->set("long",mofang_things[thing_num-1]);
    }

    if ( renwu_where == 1 )
    {
        thing->set_name(chufang_things[thing_num-1],({"item"}));
        thing->set("long",chufang_things[thing_num-1]);
    }

    me->set("xli_marks/find", 1);
    //me->delete("xli_marks/now_thing");
    me->delete("xli_marks/things_place");
    thing->move(me);

    return 1;
}

