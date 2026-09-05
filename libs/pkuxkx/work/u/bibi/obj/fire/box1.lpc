//firework maker
//written by bibi on 10.15.1998

#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIC"烟花盒"NOR, ({"box"}));
   set_weight(500);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这个是用来放烟花用的，当然放别的也行！\n");
     set("unit", "个");
     set("value", 100000);
     set("material", "steel");
  }
     setup();
}

void init()
{
     add_action("do_firework","firework");
}

int do_firework(string arg)
{
        string file;
	string title;
	string firework;
	mapping fire;
        object ob;
        object *list;
	int i,j;

        if (!arg) return notify_fail("指令格式 : firework [烟花名称]\n");
        file =sprintf("/u/bibi/obj/fire/%s",arg);
        if( file_size(file) < 0 ) return notify_fail("没有指定名称的烟花可以使用！\n");
	fire=file->firework();	
	firework=fire["firework"];
	if(!stringp(firework)) return notify_fail("请查看该烟花文档是否不正确！\n");
	title=fire["title"];
	if(!stringp(title)) title="烟花";
	title=sprintf(HIW"\n请大家欣赏%s为大家献上的<<%s>>\n"NOR,this_player()->query("name"),title);
	list = users();
        j = sizeof(list);
	for(i=0;i<j;i++)
	{
		tell_object(list[i],title);
		tell_object(list[i],firework);
	}
	return 1;
}


	