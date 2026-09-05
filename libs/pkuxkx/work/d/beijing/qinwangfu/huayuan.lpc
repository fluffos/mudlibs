#include "verify.h"
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这里是一处花园，可惜缺人打理，杂草丛生。
LONG
	);

	set("exits", ([
		
        "west" : __DIR__"houyuan",
       
	]));
    set("max_contain_items",5);
	setup();
}

void init()
{
    add_action("do_modify","modify");
}

int do_modify( string arg)
{
    object me=this_player();
	if (!arg) 
	{
		write("要把花园修饰成什么样子呢？\n");
		return 1;
	}
	if (verify(me))
	{	
		arg = replace_string(arg, "$BNK$", BNK);
		arg = replace_string(arg, "$BLK$", BLK);
		arg = replace_string(arg, "$RED$", RED);
		arg = replace_string(arg, "$GRN$", GRN);
		arg = replace_string(arg, "$YEL$", YEL);
		arg = replace_string(arg, "$BLU$", BLU);
		arg = replace_string(arg, "$MAG$", MAG);
		arg = replace_string(arg, "$CYN$", CYN);
		arg = replace_string(arg, "$WHT$", WHT);
		arg = replace_string(arg, "$HIR$", HIR);
		arg = replace_string(arg, "$HIG$", HIG);
		arg = replace_string(arg, "$HIY$", HIY);
		arg = replace_string(arg, "$HIB$", HIB);
		arg = replace_string(arg, "$HIM$", HIM);
		arg = replace_string(arg, "$HIC$", HIC);
		arg = replace_string(arg, "$HIW$", HIW);
		arg = replace_string(arg, "$NOR$", NOR);
		this_object()->set("long","\n"+arg+NOR+"\n");  
		this_player()->set("qinwangfu/myhuayuan/long","\n"+arg+NOR+"\n");
		write("完成!\n");
	}
	else 
	{
		write("你是来做客还是来搞破坏的？\n");
	}
	return 1;
}