//Cracked by Roath
inherit ROOM;
int block_cmd(string); 

void create ()
{
	set ("short", "乘云阁");
	set ("long", @LONG

乘云阁居观中的最高处，阁上画栋雕梁，丹楹刻柱，显是下了很
大的功夫、周围朱栏曲槛，凭栏四望，远处景致俱在眼前。山下
村房楼舍，山上奇石怪松历历在目。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"down": __DIR__"yanzhen",
//    "master": "/d/wailijie/room/wzgmaster.c",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhenyuan" : 1,
	]));


	set("outdoors", "xy9");
        set("no_fight", 1);   
        set("no_magic", 1);   

	setup();
}

void init() 
{
  add_action("block_cmd", "", 1); 
}

int block_cmd(string args) 
{
  string verb; 
  verb = query_verb(); 
  
  if (verb == "bian") return 1;
  if (verb == "cast") return 1;
  return 0; 
}
