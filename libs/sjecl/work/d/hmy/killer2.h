string *way = ([
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
]);
	
int valid_leave(object me, string dir)
{
	int i;
	
	if(me->query("hostage/dotwo")>0 && me->query("hostage/passed_l")>0){
       		for(i=0;i<sizeof(way);i++){
       			if (dir == way[i] && objectp(present("mojiao shashou", environment(me)))){
        			tell_room(environment(me),"魔教杀手大声对着" + me->name() + "喝道：" + RANK_D->query_rude(ob) + "，你想去黑木崖先得过了我这关。\n");
        			return 1;
        			break;
               		}
               	}
        }
        return ::valid_leave(me, dir);
}
