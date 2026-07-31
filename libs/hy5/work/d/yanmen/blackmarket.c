#pragma save_binary
// ROOM:__DIR__"blackmarket"

inherit ROOM;

void create()
{
	set("short","兵器库");
	set("long",
"在这里你可以看到墙上挂满了各式各样的武器，不难明了这里是存放武器的地方，而墙上写\n"
"了个诺大的「武」字。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"west" : __DIR__"camp8",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/seller" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
