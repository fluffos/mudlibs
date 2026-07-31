
// bag.c
// By L.G.

#include <ansi.h>

inherit ITEM; 			// /std/item
inherit F_SAVE;                 // /feature/save.c
inherit F_AUTOLOAD;             // /feature/autolaod.c

void delete_waste();
void restore_waste();
int do_save(string);
int do_load(string);
int save();

void create()
{
        restore_waste();
        if( clonep() )
                {
                set("master_id",this_player()->query("id"));
                set_default_object(__FILE__);
                }
        set("no_get",1);
        set("no_drop",1);
        seteuid(getuid());
}

void init()
{
        if( !environment()->is_character())
        {
                destruct(this_object());
                return;
        }
        if (environment()->query("id")!=query("master_id"))
        {
                destruct(this_object());
                return;
        }
	else
	{
                add_action("do_save", "putin");
                add_action("do_load", "putout");
                add_action("do_info", "checkbag");
    }
}

string query_save_file()
{
  return DATA_DIR+"bag/"+query("master_id")[0..0]+"/"+query("master_id");
}

string query_autoload()	{ return query("master_id"); }

void autoload(string name)
{
        set("master_id",name);
        restore();
}


int do_save(string arg)
{
        object me,*ob,card;
		int s;
		int flag;
		mapping *notes;
		mapping note;
		string str;
        int amount,rich,sub;

        if (!arg) return 0;

        me=this_player();
		if(environment(me)->query("short")!="丰登当铺")
			return notify_fail("你只能在丰登当铺存物品。\n");

		ob=all_inventory(me);
		flag=0;
		s=sizeof(ob);
		while(s--)
		{
			if (!stringp(ob[s]->query("id"))) continue;
			if (ob[s]->query("id")==arg)
			{
				flag=1;
				break;
			}

		}
		if(!flag)
			return notify_fail("你身上没有这种物品。\n");
		
		if(ob[s]->query("no_get") || ob[s]->query("no_drop"))
			return notify_fail("你不能把这样物品放入袋中。\n");

		if(ob[s]->query("money_id"))
			return notify_fail("你不能把钱放入袋中。\n");

                amount=ob[s]->query("value");
		if(amount>49999)
			return notify_fail("你不能把贵重物品放入袋中。\n");

		notes = query("notes");
		if( sizeof(notes) >=10)
			  return notify_fail("你的乾坤袋已经装满了。\n");
       
		card = present("account card", this_player());
		if(!card)
			return notify_fail("你身上没有金龙卡。\n");

		rich=card->query("rich");
		sub=(int)(amount/10);
		if(rich<sub)
			return notify_fail("当铺老板说道：你帐号上的钱不够交税了。\n");
		sub=-1*sub;
		card->add("rich",sub);
		card->save();
        write("当铺老板说道：在乾坤袋中存东西需收税十分之一！客官用不着您费心, 我自己从您兜里拿就成了。\n");

        str=sprintf("%d",ob[s]->query_amount());
		note = allocate_mapping(4);
		note["title"] = ob[s]->query("name");
		note["msg"] = base_name(ob[s]);
		note["amount"]=str;

		destruct(ob[s]);
		if( !pointerp(notes) || !sizeof(notes) )
			notes = ({ note });
		else
			notes += ({ note });

		set("notes", notes);

	    save();
        write("OK.\n");
        return 1;
}


int do_load(string arg)
{

	mapping *notes;
	int num,amount;
	object me,obj;

    if (!arg) return 0;
    me=this_player();

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
	{
		write("没有任何存放在乾坤袋中!\n");
		return 1;
	}

	if( !sscanf(arg, "%d", num) )
		return notify_fail("你要取出第几样物品？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("物品序号不对。\n");
	
//	printf("obj is %s\n",notes[num-1]["msg"]);

    if (file_size(notes[num-1]["msg"]+".c")<0)
        return notify_fail("没有这种东西!\n");

	sscanf(notes[num-1]["amount"],"%d",amount);

	obj=new(notes[num-1]["msg"]+".c");

    if(amount)
		obj->set_amount(amount);
	obj->move(me);
	
	notes = notes[0..num-2] + notes[num..sizeof(notes)-1];
	set("notes", notes);
	save();
    write("OK.\n");
    return 1;
}


int do_info(string arg)
{

	
	mapping *notes;
	int i,count;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
	{
		write("没有任何存放在乾坤袋中!\n");
		return 1;
	}

	count=sizeof(notes) ;
	printf("你的乾坤袋中装著(%d)样东西\n",count);
	for(i=0;i<count;i++)
	{
		printf("[ %d ]         %s\n",i+1,notes[i]["title"]);
	}
	return 1;

}


void delete_waste()
{
	delete("name");
	delete("unit");
	delete("id");
	delete("long");
}

int save()
{
	int i;
	delete_waste();
	i=::save();
	restore_waste();
	return i;
}

void restore_waste()
{
     set_name( GRN "乾坤袋" NOR, ({ "qiankun bag","bag" }) );
     set("unit", "只");
     set("long",@LONG
这是东方故事世界中通用的乾坤袋，里面装着需随身所带的
物品。望妥善保管，遗失后果自负。
     putin      物品全名             把物品放入袋中
     putout     在袋中物品的序号     把物品从袋中取出
     checkbag                        查看袋中的物品
LONG
        );
}

void owner_is_killed() { destruct(this_object()); }
