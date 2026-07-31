// npc: shidao.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;
int rate=0;
string materialname="";
void create()
{
        set_name("侍甲", ({ "shi jia","jia",}) );
	set("nickname", HIY "甲" NOR );
	set("gender", "男性" );
	set("age", 40);
	set("long", 	
		"他头上包着红布头巾，一袭蓝缎袍，没有一丝褶皱。\n");
	set("str", 25);
	set("dex", 20);
        set("no_get",1);
	set("con", 17);
	set("int", 30);
        set_temp("no_kill",1);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage",150);

	set("combat_exp", 2500000);
	set("score",0);
	
	set("attitude", "peaceful");
        
	set("inquiry", ([
		"铸甲"  : "你要做一件自己的甲衣吗？\n",
		"原料"  : "铸甲可用寒丝羽竹，海底金母，千年神木。但效果各不一样。\n",
	]) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{   

    who->delete_temp("jia");
    who->set_temp("m_jia",1);
    if (!ob->query("rate")) {
                message_vision(CYN "$N对$n皱眉道：这种东西根本无法用来锻造甲衣，你还是好好再去找找材料吧！\n" NOR, this_object(), who);
		return 0;
		}
		rate = ob->query("rate");
		materialname = ob->query("name");
		
    message("vision","侍甲低头检视了一下手中的"+(string)ob->query("name")+
            "点了点头说：\n", who);
    message("vision","。。。好我们现在就开始甲衣！\n", who);
    write("请这位"+RANK_D->query_respect(who)+"给甲衣起名字吧！(zhu 甲衣的中文名字(使用颜色请参考help nick))\n");
    return 1;
}

int do_zhu(string arg)
{
	string o_name,id,w_name;
	object jia,make_time;   //生成的武器句柄
	object me;
	me = this_player();
	if(!(me->query_temp("m_jia")) )
        return notify_fail("什么?\n");
    if((me->query("jia/make")) ){
        say("侍甲一脸茫然：您已经有一把自造的衣服了，还来干什么？难到不可手么？\n");
        return 1;
    }
	if( !arg )
		return notify_fail("侍甲认真的说：想好甲衣的名称及代号后在对我说。\n");

    sscanf(arg ,"%s" ,w_name);
    id="jia";
    if(!w_name)
        return notify_fail("什么?(使用zhu 剑的中文名字\n)");
            me->delete_temp("m_jia");
    me->delete_temp("get_orc");
    me->delete_temp("or");
   	o_name=materialname;
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"沉吟了一会，对侍甲悄声说了几句话。侍甲点了点头。说：好吧！\n",me );
	message_vision("\n侍甲回过身，转向身后的一个巨大的火炉，鼓动真气燃起了熊熊的大火。说：开始！\n",me );
	message_vision(BLU "$N双手握住一个巨大的铁锤，猛的向炉中渐渐红热起来的"+o_name+"挥去！\n" NOR,me);
	message_vision(RED "只听得棚的一声巨响，锤头和"+o_name+"粘在了一起。\n" NOR,me );
	message_vision(YEL "$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！\n" NOR,me);
	message_vision(HIM "一身精血胶合着汩汩的内气，源源不断的向炉中的"+o_name+"涌去！\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "突然$N觉得气血一阵翻涌，一口真气接不上来。。。。 \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "只听咯的一声轻响，一件甲衣从炉中倏然跃起。化作一道青电猛的向$N的前胸飞来！！\n" NOR,me );

	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

        w_name = replace_string(w_name, "$BLK$", BLK);
        w_name = replace_string(w_name, "$RED$", RED);
        w_name = replace_string(w_name, "$GRN$", GRN);
        w_name = replace_string(w_name, "$YEL$", YEL);
        w_name = replace_string(w_name, "$BLU$", BLU);
        w_name = replace_string(w_name, "$MAG$", MAG);
        w_name = replace_string(w_name, "$CYN$", CYN);
        w_name = replace_string(w_name, "$WHT$", WHT);
        w_name = replace_string(w_name, "$HIR$", HIR);
        w_name = replace_string(w_name, "$HIG$", HIG);
        w_name = replace_string(w_name, "$HIY$", HIY);
        w_name = replace_string(w_name, "$HIB$", HIB);
        w_name = replace_string(w_name, "$HIM$", HIM);
        w_name = replace_string(w_name, "$HIC$", HIC);
        w_name = replace_string(w_name, "$HIW$", HIW);
        w_name = replace_string(w_name, "$NOR$", NOR);

	me->set("jia/make",1);		//武器制造后防止再造的标志		
	me->set("jia/name",w_name +NOR);	//武器的名称
	me->set("jia/id",id);		//武器的代号
	me->set("jia/lv",1);    	//武器等级
	me->set("jia/or",o_name);	//记录制造原料
	me->set("jia/value",0);	      	//记录武器升级已有的点数	
	me->set("jia/rate",rate); //武器材料的等级 
	me->set("jia/time",make_time);
	me->set("jia/type","甲");

	jia=new(__DIR__"jia",1);	//生成新甲
	jia->move(this_player());
	message_vision("侍甲摸起地上，带着斑斑血迹还有些烫手的巨甲，说：\n甲。。已。。成。。，侍甲的任务。。。也就完成了。。。。\n",me );
	say("侍甲艰难的说：甲。。您。。收好，我该走了。。。\n");
	message_vision("侍甲说完。倏的便不见了。\n",me);
	this_object()->die();
	return 1;
}

