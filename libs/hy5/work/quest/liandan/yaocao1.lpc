// yaocao.c 药草  
// 星星lywin 2000/6/15

#include <ansi.h>
inherit ITEM;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create() 
{
string file;
string *roomlines;
string location;
file = read_file("/clone/medicine/yaocainame");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        //set_name(HIG "珍贵药草" NOR,({"yao cao", "yao"}));
set_name(order[random(13)]+"普通的"+location+NOR,({"yao cao", "yao"}));
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "株");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_put",1);
		set("yaocao",1);
		set("lev",1);
                set("long", "这是一株生长在密林中的无名草药，一般人都会误认成杂草。\n");
             }
        setup();
}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}



int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	me->add("food",20);
	me->add("water",20);
	write("你三口两口把"+this_object()->query("name")+"吃了下去。\n");
	destruct(this_object());
	return 1;
}
