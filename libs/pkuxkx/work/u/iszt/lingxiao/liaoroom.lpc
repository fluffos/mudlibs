// File		: liaoroom.c
// Created By	: iszt@pkuxkx, 2007-02-16

inherit ROOM;

void create()
{
	set("short", "廖自励居所");
	set("long", @LONG
这是廖自励的居所。同辈弟子中，以他最为生性多智，传言说若不是当年先
师仙去时，他不在凌霄城内，而等他回来之时，大局已定，那这掌门之位必为他
囊中之物。这房间内摆满了书，从《孙子兵法》到《史记》，尽皆是权谋争斗之
书。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"stonee4",
	]));

	setup();
	replace_program(ROOM);
}