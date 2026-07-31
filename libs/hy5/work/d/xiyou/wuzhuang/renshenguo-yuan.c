//Cracked by Roath
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
	set ("short", "人参果园");
	set ("long", @LONG

好大的一遍人参果园！巨大的果树上吊着一枚枚令人垂涎欲滴的
人参果。只是不知道怎样才能弄将下来。据说这人参果娇贵无比，
要是乱摘一气什么都吃不上。
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/drug/renshenguo-fake" : 1,
	]));

	set("outdoors", "xy9");
        set("no_net_dead", 1);
        set("no_get", 1);
	set("alternative_die",1);

	setup();
}

