// 延至馆
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
void create()
{
	set("short", HIY"延至馆"NOR);
	set("long", @LONG
这里是一片竹楼，正是星宿老仙考究门下弟子武功进境的地方。一口古井(well)
竖立在楼前。
LONG
	);
    set("normaldesc", @LONG
这里是一片竹楼，正是星宿老仙考究门下弟子武功进境的地方。一口古井(well)
竖立在楼前。
LONG
	);
    set("resource/water", 1);
	set("exits", ([ 
		"north" : __DIR__"tianxiugong",
        "west" : __DIR__"suishilu2",
     
        
		
    ]));
    set("item_desc", ([ 
        "well" : "井水清凉，你可以喝(drink)个痛快。跳(jump)下去似乎别有洞天。\n",  
   
   ])); 
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
        add_action("do_drink", "drink");
        add_action("do_jump", "jump");
}

int do_jump()
{
    object room,me=this_player();
    int i;
    object *all=deep_inventory(me);
	
    for (i=0;i<sizeof(all);i++)
        {
            if (userp(all[i])&&all[i]->query("family/family_name")=="星宿派"&&all[i]->query("combat_exp")<100000)
            {
                tell_object(me,"把星宿年轻弟子背出去？亏你想的出来！\n");
                return 1;
            }
        }
    if (me->query("family/family_name")!="星宿派")
    {
        tell_object(me,"你要跳井自杀吗？\n");
        return 1;
    }
    if (me->query("combat_exp")<100000)
        {
            tell_object(me,"你这么菜就准备去闯荡江湖了？\n");
            return 1;
        }
    else
    {
        room=load_object(__DIR__"midao1");
        if (room)
        {
            me->move(room);
            tell_room(this_object(),me->query("name")+"纵身跳下井去。\n",me);
            tell_object(me,"你飘身下井，来到了一处秘道。\n");
        }
        return 1;
    }
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
                message("vision", me->name()+"拿起水桶，舀出一桶水一阵豪饮。\n",
                        environment(me), ({me}) );
                write("你拿起水桶，痛快地喝着井水。\n");
        }
        else write("你已经不渴了。\n");

        return 1;
}
