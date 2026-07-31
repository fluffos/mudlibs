void create()
{
        seteuid(getuid());

}
void buildroom(object me,string s_title,string l_title, string dir,int rec)
{
mapping pairs = ([
        "north":                "south",
        "south":                "north",
        "east":                 "west",
        "west":                 "east",
        "northup":              "southdown",
        "southup":              "northdown",
        "eastup":               "westdown",
        "westup":               "eastdown",
        "northdown":    	"southup",
        "southdown":    	"northup",
        "eastdown":             "westup",
        "westdown":             "eastup",
        "northeast":    	"southwest",
        "northwest":    	"southeast",
        "southeast":    	"northwest",
        "southwest":    	"northeast",
        "up":                   "down",
        "down":                 "up"
]);

	object env;
	string this_file;
	string my_file;
	string name;
	string c_name,o_name;
	name = (string)me->query("id")+sprintf("%d",time());
//ready to build!!!
//Let's read in the .o file istead
	c_name = base_name(environment(me))+".c";
  //      o_name = base_name(environment(me))+".o";
	this_file = read_file(c_name);
	this_file = replace_string(this_file,"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+dir+"\""+" : \"/p/residence/"+name+"\",");	
//do NOT change this write_file
    //    if(!write_file(o_name,this_file,1))
     //   return;
// change this to write_file2
        if(!write_file(c_name,this_file,1))
        return;
	environment(me)->set("exits/"+dir,"/p/residence/"+name);	
	// now the room we are in is done!
	switch(rec) {
	case 1:
	my_file = read_file("/obj/USER_ROOM.o");
	break;
	case 2:
	my_file = read_file("/obj/RESTROOM.o");
	break;
	case 3:
	my_file = read_file("/obj/WEAPONROOM.o");
	break;
        case 4:
	my_file = read_file("/obj/EATROOM.o");
	break;
        case 5:
	my_file = read_file("/obj/FIGHTROOM.o");
	break;
        case 6:
	my_file = read_file("/obj/JOBROOM.o");
	break;	
        case 7:
	my_file = read_file("/obj/JOBTWOROOM.o");
	break;	
	}
	my_file = replace_string(my_file,
"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+pairs[dir]+"\""+" : "+"\""+c_name+"\",");
	my_file= replace_string(my_file,"SHORT_TITLE",s_title);
	 my_file= replace_string(my_file,"LONG_TITLE",l_title);
	if(me->query("family/family_name"))
	my_file= replace_string(my_file,"bigwiz7001",
	me->query("family/family_name"));
        my_file= replace_string(my_file,"bigtie7001",
        me->query("id"));
// now we need to write out this file!
// do NOT change this one!
	write_file("/p/residence/"+name+".o",my_file,1);
	write("³É¹¦£¡£¡\n");
// change this one to write_file2
        write_file("/p/residence/"+name+".c",my_file,1);
	me->add("created_room",1);
	switch(rec) {
	case 1:
	me->add("created_room",1);
	break;
	case 2:
	me->add("rest_room",1);
	break;
	case 3:
	me->add("weapon_room",1);
	break;
        case 4:
	me->add("eat_room",1);
	break;
        case 5:
	me->add("fight_room",1);
	break;
        case 6:
	me->add("job_room",1);
	break;	
        case 7:
	me->add("job2_room",1);
	break;	
	}
me->save();
}

int touch_file(string name)
{
if(write_file(name," ",1))
return 1;
else return 0;
}

