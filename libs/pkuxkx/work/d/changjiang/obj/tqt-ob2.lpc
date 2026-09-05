// Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit F_SAVE;
inherit ITEM;

#define SELF_CHANNEL "/data/business/self_channel"
string query_save_file()
{
        return SELF_CHANNEL;
}


void init()
{
	add_action("do_use", "use");
}

void create()
{
	set_name(WHT"银雀"NOR, ({ "yin que"}));
	set_weight(500);
    set("value",100000);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一支做工精巧的银色的孔雀，使用(use)它使你的声音被江湖中更多的人听到。\n");
			set("unit", "支");
		}
}

int do_use(string arg)
{
   
    object me=this_player();
    object ob=this_object();
    string color,ch_name;
    string *co_list,*ch_list,*creater_list,*user_list=({}),*allowed_color=({"HIR","RED","HIW","WHT","HIY","YEL","HIG","GRN","HIB","BLU","HIM","MAG","HIC","CYN"});
    int index;
    if (me->query("safari_newchannel"))
    {
        tell_object(me,"你已经开通了千里传音功能，不要暴殓天物了。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你需要指定一个千里传音的频道名，比如use HIR 天魔宗。\n");
        tell_object(me,"创建千里传音频道名之后，你可以最多邀请(mes_invite)不超过10个玩家以及你自己使用(mes)这个特殊频道。\n");
        tell_object(me,"正确创建千里传音频道后，使用效果如下：\n");
        tell_object(me,HIR+"【天魔宗】我踏月色而来(Zine):你好！\n"+NOR);
        tell_object(me,BLINK+"频道名不得包含任何政治、色情信息，否则除被删除频道外，将面临巫师组追加其他惩罚。\n"+NOR);
        return 1;
    }
    if (sscanf(arg, "%s %s", color,ch_name)!=2)
    {
        tell_object(me,"你需要指定一个千里传音的频道名，比如use HIR 天魔宗。\n");
        tell_object(me,"创建千里传音频道名之后，你可以最多邀请(mes_invite)不超过10个玩家以及你自己使用(mes)这个特殊频道。\n");
        tell_object(me,"正确创建千里传音频道后，使用效果如下：\n");
        tell_object(me,HIR+"【天魔宗】我踏月色而来(Zine):你好！\n"+NOR);
        tell_object(me,BLINK+"频道名不得包含任何政治、色情信息，否则除被删除频道外，将面临巫师组追加其他惩罚。\n"+NOR);
        return 1;
    }
    if (member_array(color,allowed_color)==-1)
    {
        tell_object(me,"你可以使用的颜色，只包含HIR,RED,HIW,WHT,HIY,YEL,HIG,GRN,HIB,BLU,HIM,MAG,HIC,CYN这14种颜色。\n");
        return 1;
    }
    ob->restore();
    co_list=ob->query("co_list");
    if (!co_list)
    {
        co_list=({});
    }
    ch_list=ob->query("ch_list");
    if (!ch_list)
    {
        ch_list=({});
    }
    creater_list=ob->query("creater_list");
    if (!creater_list)
    {
        creater_list=({});
    }
    if (member_array(ch_name,ch_list)!=-1)
    {
        index=member_array(ch_name,ch_list);
        tell_object(me,ch_name+"已经被 "+HIW+creater_list[index]+NOR+" 所创建，你必须换一个千里传音频道名。\n");
        return 1;
    }
    co_list+=({color});
    ch_list+=({ch_name});
    creater_list+=({me->query("id")});
    user_list+=({me->query("id")});
    ob->set("co_list",co_list);
    ob->set("ch_list",ch_list);
    ob->set("creater_list",creater_list);
    ob->set(ch_name,user_list);
    ob->save();
    me->set("safari_newchannel",color+ch_name);
    message_vision("$N凭空消失了。\n",this_object());
    destruct(this_object());
    return 1;		
}