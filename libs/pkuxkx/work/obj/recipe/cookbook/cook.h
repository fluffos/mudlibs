//菜谱头文件 by Vast@pkuxkx 2009.04.05

void init()
{
	      add_action("do_recite", "recite");
}

int do_recite(string arg)
{
	object me = this_player();
	int sk = me->query_skill(skill, 1);
	string *all;
	mapping skl;
	
	if (!arg || (arg != "cook book" && arg != "menu" && arg != "pu" && arg != "book") )
		return notify_fail("你要背什么？\n");
	if(!sk)
		return notify_fail("你连" + to_chinese(skill) + "都不会，如何学习？\n");
	if(sk < level)
		return notify_fail("你技艺尚不精通，无法深入学习。\n");

	skl = me->query_profs();
	
	if(!mapp(skl))
		{
			skl = ([ ]);
			me->set_prof(skill, prof_id);
		}
	else if(sizeof(skl) == 0)
		me->set_prof(skill, prof_id);
	else 
		{
				if(arrayp(skl[skill]) && member_array(prof_id, skl[skill]) != -1)
					return notify_fail("你已经会做" + to_chinese(prof_id) + "了。\n");
				else
					me->set_prof(skill, prof_id);
		}
		
	message_vision("$N仔细的看了几遍" + this_object()->query("name") + "心中默默记住内容，然后一把撕了个稀巴烂。\n", this_player());
	destruct(this_object());
	return 1;
}
                
void create()
{
        set_name(short_desc, ({"cook book", "book", "pu", "menu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", long_desc + "你想你也许可以背(recite)下来。\n");
                set("unit", "本");
                set("value", 1000);
                set("material", "paper");
        }
        setup();
}