//翰林学士 Zine 

#include <ansi.h>
inherit NPC;
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int askforhelp();

void create()
{
    set_name("官员", ({"guan yuan", "guan","officer"}));
    set("title", HIW"大明 通政司"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他是朝廷的通政司的官员。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",5);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
    set("chat_chance", 5);
        set("chat_msg", ({
                
                (:askforhelp:),
        }) );
    set("mingpin",5);
	

    setup();
    carry_object("/d/yingtianfu/neicheng/obj/guanyin2");
}

int askforhelp()
{
    if (random(100)>95)
    {
        command("daming 请今岁没有领俸禄的官员赶紧来通政司领取俸禄，过期不补。\n");
    }
    if (random(100)>95)
    {
        command("daming 任何弊政/BUG请在通政司递送奏折，上达天听。\n");
    } 
    if (random(100)>75)
    {
        command("daming 岁考(suikao)在通政司进行，无岁考记录无法使用大明任何福利，间隔超过五年不参加岁考或连续三年岁考为差将被降级乃至逐出官场。\n");
    }  
}
void init()
{
	add_action("do_compensate","compensate");
}
int do_compensate()
{
	object me=this_player();
	string *ids=({"yhzzyahoo","zine","ruoyu"}),id=me->query("id");
	int *compens=({2443,2,418}),compen;
	if (member_array(id,ids)==-1)
	{
		return notify_fail("你的名字暂时不在补偿列表上，请联系Zine.\n");
	}
	compen=compens[member_array(id,ids)];
	if (me->query("ming/credit")>=compen)
	{
		return notify_fail("你的功勋已大于之前的损失。\n");
	}
	me->set("ming/credit",compen);
	tell_object(me,"你的大明功勋被恢复为"+chinese_number(compen)+"点。\n");
	if (me->query("ming/credit")/25>=1)
	{
		me->add("ming/credit",me->query("ming/credit")/25);
		tell_object(me,"你的大明功勋被额外补偿"+chinese_number(me->query("ming/credit")/25)+"点。\n");
	}
	return 1;
}
