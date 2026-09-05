// book0.c

inherit ITEM;
int do_study(string arg);

void create()
{
          set_name("达摩心经", ({"jing"}));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
set("long","这是达摩老祖多年研究佛法的心血,整本书是用梵文写的. \n");
                 set("value", 10000);
 set("material","paper");
	}
setup();
}

void init()
{
add_action("do_study","study");	
}

int do_study(string arg)
    {
        object me;
        string book;
        int times,i;
me = this_player();
	if(!arg || (sscanf(arg, "%s for %d",book,times) < 1 ))
		return notify_fail("指令格式：study jing for [次数]\n");
	if (book != "jing")
		return 0;
if( (int)me->query_skill("fanwen",1)<1)
    {
            write("你不懂梵文,无法领悟上面的东西. \n");
               return 1;
}
	for (i=0;i<times;i++) {
		if ((int)me->query("jing")>35)
		{
			me->add("jing",-35);
			if ((int)me->query_skill("buddhism",1) <150)
			{
				message_vision("$N正专心的研读达摩心经, \n", me);
				 me->improve_skill("buddhism", (int)me->query_skill("fanwen",1)/5+1);
				write("你对达摩心经研读了一会，似乎有所心得. \n");
			}
			else
			{
				write("你对达摩心经研读了一会，发现上面的太过浅薄,对你毫无意义.\n");
				return 1;
			}
		}
		else 
		{
	  	write("你现在有些疲倦，无法专心下来研读新知. \n");
	  	return 1;
		}
	}
 	return 1;
}
