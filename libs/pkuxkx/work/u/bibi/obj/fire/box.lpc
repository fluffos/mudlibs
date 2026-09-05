// 烟花盒ver 3.00
//firework maker 
// /u/bibi/obj/fire/box.c
//written by bibi on 10.15.1998
//rewrittem by bibi on 10.16.1998

#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIC"烟花盒"NOR, ({"box"}));
   set_weight(500);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", 
	"    这是用来放烟花用的盒子，当然放别的也行！只见盒子盖上面贴着一张字条：\n"
	"“天干物燥，小心火烛！”，在盒子盖的一个角上，歪歪扭扭的刻着一行小字：  \n"
     GRN"           “柳残阳制于公元一九九八年十月十六日”\n\n"NOR			
	"    用法: firework [烟花名称的英文.c] [-w|-r|-s|-a]，用法说明如下：\n"
	"其中-w:巫师看得到；-r本房间玩家看得到;-s自己能看得到；-a全部玩家看得到\n"
	"如果玩家不使用-这个开关的话，默认的开关将是-s，即只有自己能看到，\n"
	"如果不想看到别人或自己放的烟花，可以"GRN"set refurse_firework\n"NOR
	);
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

	string swit;

	if (!arg) return notify_fail("指令格式 : firework [烟花名称]([-s|-w|-r|-a])\n");
	if( sscanf(arg, "%s %s", arg, swit)==2 )
	{		
	        file =sprintf("/u/bibi/obj/fire/%s",arg);
	        if( file_size(file) < 0 ) return notify_fail("没有指定名称的烟花可以使用！\n");
        	fire=file->firework();
	        firework=fire["firework"];
        	if(!stringp(firework)) return notify_fail("请查看该烟花文档是否不正确！\n");
	        title=fire["title"];
        	if(!stringp(title)) title="烟花";
	        title=sprintf(HIW"\n请大家欣赏%s为大家献上的<<%s>>\n"NOR,this_player()->query("name"),title);

		if(swit=="-s")
		{
			if( !this_player()->query("env/refuse_firework") )
			{
                		tell_object(this_player(),"只有你自己能看到：\n");
				tell_object(this_player(),title);
        		        tell_object(this_player(),firework);			
			}
			return 1;
		}
		
		if(swit=="-w")
		{		
			list=users();
		        j = sizeof(list);			
			tell_object(this_player(),"只有巫师能够看到：\n");
			for(i=0;i<j;i++)
			{
				if( wizardp(list[i]) && !list[i]->query("env/refuse_firework") )
				{
					tell_object(list[i],title);
					tell_object(list[i],firework);
				}
			}
			return 1;
		}

		if(swit=="-r")
		{
		        list = all_inventory(environment(this_player()));
			j=sizeof(list);
			tell_object(this_player(),"只有本房间的人能够看到：\n");
		        for(i=0;i<j; i++)
			{
				if( userp( list[i] ) && !list[i]->query("env/refuse_firework") )
				{
					tell_object(list[i],title);
					tell_object(list[i],firework);
				}
			}
			return 1;
		}

		if(swit=="-a")
		{
			list = users();
		        j = sizeof(list);
			tell_object(this_player(),"全部玩家都可以看到：\n");
			for(i=0;i<j;i++)
			{
				if( !list[i]->query("env/refuse_firework") )
				{
					tell_object(list[i],title);
					tell_object(list[i],firework);
				}
			}
		}	return 1;
	}

//没有设定开关时默认是-s

        file =sprintf("/u/bibi/obj/fire/%s",arg);
        if( file_size(file) < 0 ) return notify_fail("没有指定名称的烟花可以使用！\n");
	fire=file->firework();	
	firework=fire["firework"];
	if(!stringp(firework)) return notify_fail("请查看该烟花文档是否不正确！\n");
	title=fire["title"];
	if(!stringp(title)) title="烟花";
	title=sprintf(HIW"\n请大家欣赏%s为大家献上的<<%s>>\n"NOR,this_player()->query("name"),title);

	if( !this_player()->query("env/refuse_firework") )
	{
		tell_object(this_player(),"只有你自己能看到：\n");
		tell_object(this_player(),title);
		tell_object(this_player(),firework);
	}
	return 1;
}


	
