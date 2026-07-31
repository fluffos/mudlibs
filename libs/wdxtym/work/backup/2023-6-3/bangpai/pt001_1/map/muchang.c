inherit ROOM;
#define FARM "/d/bangpai/farm/farm"
string look_paizi();

void create()
{
	set("short", "牧场");
	set("long", @LONG
牧场。
LONG);
	
	set("exits", ([
	    "west" : __DIR__"caiyuan",
	]));
	
	set("item_desc", ([
	    "牌子" : (: look_paizi :),
	]));
	
	set("no_fight", 1);
	
	set("objects", ([
	    "/d/bangpai/farm/laonong" : 1,
	]));
	setup();
}

void init()
{
    add_action("do_look", "look");
    add_action("do_slaughter_animal", "slaughter_animal");
    add_action("do_sell_animal", "sell_animal");
}

string look_paizi()
{
    return "牧场为单人场景。\n出售动物将返回购买所花的70%的金子。\n目前你的农场可以养殖" + FARM_D->get_animal_amount(this_player()) + "只动物。\n";
}
int do_slaughter_animal(string arg)
{
    object who = this_player();
    
    FARM->slaughter_animal(who, arg);
    
    return 1;
}

int do_sell_animal(string arg)
{
    object who = this_player();
    
    FARM->sell_animal(who, arg);
    
    return 1;
}

int do_look(string arg)
{
    object who = this_player();
    object ob;
    
    if (!arg || arg == "")
        return 0;

    if (!objectp(ob = present(arg, environment(who))))
        return 0;
    
    if (!ob->query("is_animal"))
        return 0;
    
    FARM->look(who, ob);
    return 1;
}

int valid_leave(object me, string dir)
{
	string fb_id;
	object room;
	
	if (userp(me) && dir == "south")
	{
	    FARM_D->sort_farmd(me);
	    me->move((this_object()->query("exits"))["south"]);
	    destruct(this_object());
	    return 1;
	}
	
	return ::valid_leave(me, dir);
}