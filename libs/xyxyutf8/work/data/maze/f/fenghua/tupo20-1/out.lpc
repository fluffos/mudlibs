inherit ROOM; 
#include <ansi.h>

string random_msg();

mapping color = ([
	"jin" : "白", 
	"mu"  : "青", 
	"shui": "黑",
	"huo" : "红",
	"tu"  : "黄",
]);

void create() 
{ 
        set("short", "山谷"); 
        set("long", @LONG
这里是山中的一个隐秘山谷。四周是高可及天的山峰，云深林密，一径小溪潺潺流过，溅入坡下塘中。
一条小径随地势陡然变高，延伸至高山深处。
    一边路旁，立着一块石碑(bei)。
LONG
); 
	set("no_magic",1);
        set("no_fight",1);
        set("exits", ([ 
                "south" :__DIR__"maze/exit",
        ]));
	set("channel_id","引气入体");
	set("item_desc", ([
                "bei": (:random_msg:),
	]));                
        setup();
}

string random_msg()
{
	mapping need,ns;
	string name,t1,t2,*types,str,msg;
	object me = this_player();
	if( !stringp(str=me->query_temp("maze/1_msg")) )
	{
		ns = NAME_D->random_name2(0, 1, 0, 0, 0);
		name = ns["name"];
		name = replace_string(name,sprintf("%s",name[0..0]),"");
		types = ({"jin","mu","shui","huo","tu",});
		t1 = types[random(sizeof(types))];
		types-= ({t1});
		t2 = types[random(sizeof(types))];
		need = ([
			t1 : 1+random(5),
			t2 : 1+random(5),
		]);
		me->set_temp("maze/1jiguan",need);
		me->set("mark/20_name",name);
		msg = color[t1]+color[t2]+"之色";
		str = "一座古旧的石碑，上面依稀刻着「"+name+"山人之"+chinese_number(me->query_temp("maze/1jiguan/"+t1))+chinese_number(me->query_temp("maze/1jiguan/"+t2))+"洞府」。\n";
		str+= "碑石的底座刻着一个未名奇兽，两个空洞眼睛闪着"+msg+"。\n";
		str+= "看来需要可以将什么镶嵌(qian)在上面。\n";
		me->set_temp("maze/1_msg",str);
		me->set_temp("maze/temp_msg",chinese_number(me->query_temp("maze/1jiguan/"+t1))+chinese_number(me->query_temp("maze/1jiguan/"+t2)));
		return str;
	}
	return str;
}

void init()
{
	add_action("do_qian","qian");
}

void succ_maze(object who)
{
	object xin;
	string str,npc_name;
	if( !who || !living(who) 
	 || (who->query_level()!=19&&!wizardp(who))
	 || !present(who,this_object()) )
		return;
	npc_name = who->query("mark/20_name");
	if( !npc_name )
		return;
	str = who->query_temp("maze/temp_msg");
	if( !str )
		return;
	who->delete_temp("maze");
	message_vision(HIY"\n石兽上霞光一闪，顿时灵气翻腾，隐约中霞光中渐现一曼妙身影。\n"NOR,who);
	message_vision("那人影在霞光中渐隐渐现，装束古朴，似道非道，似佛非佛，隐约有清冷女声传出。\n",who);
	message_vision("那女子说道：吾乃"+npc_name+"山人，此处为吾八十一处洞府中"+str+"之处。修仙之路漫漫，吾等孤身摸索，个中艰辛皆需品尝。吾昔日曾得一丹方，能省修行百日之功。今留神识于此，希遇有缘人，赠吾丹方，结个善缘，望日后仙界能有缘再见。\n",who);
	xin = new("/d/maze/tupo20-1/obj/xin");
	if( xin->init_owner(who) )
	{	
		message_vision("道罢，人影随着霞光都渐渐淡出，半空中飘下一页信笺。\n",who);
		if( xin->move(who) )
		{
			who->stop_busy();
			if( MAZE_D->enter_maze(who, "tupo20-2") )
			{
				message_vision("\n霞光一闪，你已身在洞中。\n\n",who);
				who->set_temp("maze/tupo20-2",1);
				return;
			}
			else	message_vision(HIR"【系统】副本激活出错，请联系巫师！\n"NOR,who);
		}
		else
		{
			message_vision("一阵怪风吹过，将信笺刮得无影无踪！\n\n",who);
			if( xin )
				destruct(xin);
		}
	}
	message_vision(YEL"无由的一阵怪风吹过，将霞光与人影顿时吹散！\n\n"NOR,who);
}	

int do_qian(string arg)
{
	int i,succ;
	mapping tmp;
	string type,*need;
	object shi,me = this_player();
	if( !me->query_temp("maze/1_msg") )
		return 0;
	if( me->query_level()!=19 && !wizardp(me) )
		return 0;
	if( !me->query_temp("maze/tupo20-1") )	
		return 0;
	tmp = me->query_temp("maze/1jiguan");
	if( !tmp || !mapp(tmp) || sizeof(tmp)<1 )
		return 0;
	if( me->query("kee")<100 )
		return err_msg("你现在身负重伤，还是小心点好。\n");	
	if( !arg )
		return err_msg("你要嵌什么？\n");
	shi = present(arg,me);
	if( !shi || userp(shi) )
		return err_msg("你身上没有"+arg+"。\n");
	if( me->is_busy() )
		return err_msg("你现在正忙着呢。\n");	
	message_vision("$N小心翼翼的将$n镶嵌在石兽眼中。\n",me,shi);	
	me->start_busy(1);
	if( !stringp(type=shi->query("type")) )
	{
		message_vision(HIR"‘轰’的一声，石碑虽然纹丝不动，"+shi->name()+"却是炸了个粉碎！\n"NOR,me);
		me->receive_wound("kee",50+random(50));
		COMBAT_D->report_status(me,1);
		destruct(shi);
		return 1;
	}
	need = keys(tmp);
	if( member_array(type,need)==-1 )
	{
		message_vision(HIR"‘轰’的一声，石碑虽然纹丝不动，"+shi->name()+"却是炸了个粉碎！\n"NOR,me);
		me->receive_wound("kee",30+random(30));
		COMBAT_D->report_status(me,1);
		destruct(shi);
		return 1;
	}		
	me->add_temp("maze/1jiguan2/"+type,1);
	if( me->query_temp("maze/1jiguan/"+type)<=me->query_temp("maze/1jiguan2/"+type) )
		message_vision("石兽眼中"+color[type]+"光一闪，灵气攒动，宛如活物。\n",me);
	else	message_vision("石兽眼中"+color[type]+"光闪了几闪，表情看似变得生动起来。\n"NOR,me);
	succ = 1;
	for(i=0;i<sizeof(need);i++)
	{
		if( me->query_temp("maze/1jiguan2/"+need[i])>=me->query_temp("maze/1jiguan/"+need[i]) )
			continue;
		message_vision("石兽眼中的"+color[need[i]]+"色流转得好似变得艰涩了一些。\n",me);	
		succ++;
	}	
	if( succ==1 )
		succ_maze(me);
	return 1;
}