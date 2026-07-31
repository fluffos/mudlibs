string *way = ({
	"up",
	"down",
	"west",
	"east",
	"south",
	"north",
	"southeast",
	"southwest",
	"northeast",
	"northwest",
	"southup",
	"southdown",
	"northup",
	"northdown",
	"eastup",
	"eastdown",
	"westup",
	"westdown",
});
	
int valid_leave(object me, string dir)
{
	object ob;
	int i;
	
	if(me->query("hostage/doone")>0 && !me->query("hostage/passed_x") && me->query_temp("midao/killed") < 5)
       	{
       		ob = new(__DIR__"npc/killer1");
       		ob->set_temp("target",me->query("id"));
       		ob->move(environment(me));
       		for(i=0;i<sizeof(way);i++)
       		{
       			if (dir == way[i] && objectp(present("mojiao shashou", environment(me))))
        		{
                    tell_room(environment(me),"魔教杀手大声对着" + me->name() + "喝道：" + RANK_D->query_rude(ob) + "，你想找长老，先得过了我这关。\n");
                    return 0;
        			break;
               		}
               	}
        }
        
        return ::valid_leave(me, dir);
}
