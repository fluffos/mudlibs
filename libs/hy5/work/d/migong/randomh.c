string *default_dirs=({
"north",
"south",
"east",
"west",
"northup",
"southup",
"eastup",
"westup",
"northdown",
"southdown",
"eastdown",
"westdown",
"northeast",
"northwest",
"southeast",
"southwest",
"north",
"south",
"east",
"west",
"northeast",
"northwest",
"southeast",
"southwest",
});


void initlvl()
 { 
object env,envt;
mapping exit;
object ob,corpse,obj,me;
int maxpot,i,j,h,k;
	mapping exits;
string *directions;
env = this_object();
	exits = env->query("exits");
j=random(20);
k=random(2);
if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
//	me=this_player();

h=sizeof(exits);
env->delete("exits");
if (k==1 && j <=4 ) j=4;
if (k==0 && j >=18 ) j=18;	

		for(i=0; i<h; i++)
{
//	tell_object(me, "存在出口:"+directions[i]+"...\n");	
//tell_object(me, "存在出口:"+exits[directions[i]]+"...\n");	
env->set("exits/"+default_dirs[j],exits[directions[i]]);
if (k==0) 
{
	j=j+1;
}
else
{
	j=j-1;	
}		

	
}	


if( !env->query("magicroom"))
{
if (j <=20 && random(3)==0)
env->set("exits/"+default_dirs[j+1],__DIR__"dong"+(random(50)+10));

if (j <=20 && random(5)==1)
env->set("exits/"+default_dirs[j+1],__DIR__"dong"+(random(30)+30));
}

}