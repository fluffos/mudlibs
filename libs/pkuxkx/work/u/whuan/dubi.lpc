// dubi.c 独臂神尼

#include <ansi.h>

inherit NPC;

inherit F_MASTER;

int ask_princess();
int ask_bxj();
int ask_guren();
int ask_ycz();
void create()
{
	set_name("独臂神尼", ({ "dubi shenni", "dubi", "shenni", "ni" }));
	set("gender", "女性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("per", 25 + random(10));
	set("long", "这是一位白衣女尼，手握拂尘，目视前方。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住她迷人的风采。\n");
	set("combat_exp", 200000);
	set("score", 10000);
        set("book_count",1);
	set("shen_type", 1);
	set("attitude", "peaceful");
         set("no_get",1);

	set_skill("whip", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("qiufeng-chenfa", 150);
	set_skill("shenxing-baibian", 150);
	map_skill("whip", "qiufeng-chenfa");
	map_skill("parry", "qiufeng-chenfa");
	map_skill("dodge", "shenxing-baibian");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
        set("inquiry", ([
                "阿珂" :  "神尼叹了一口气，说道：她是我的得意弟子，\n人长得挺美，唉，只可惜被韦小宝骗去了。\n",
                "公主" :  (:ask_princess:),
                "碧血剑" : (:ask_bxj:),
                "故人" : (:ask_guren:),
                "袁承志" : (:ask_ycz:),
                "大明公主" :  (:ask_princess:),
        ]) );
	setup();
        carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	add_money("gold", 2);
}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player() );
}


void greeting(object ob)
{
	int i;
	object man,*obj;

	man=this_object();
	if( !ob || environment(ob) != environment()) return;
	message_vision(HIC "白衣女尼对$N微微一笑。\n" NOR,ob);
if((int)ob->query_temp("hastrystab")>=6)
{
message_vision(HIC "$N踏进屋来，只见地上尸体横陈，一个女尼喘息不止。\n" NOR,ob);
ob->delete_temp("hastrystab");
ob->set_temp("savesheni",1);
ob->delete_temp("warned2");
message_vision("\n白衣女尼对$N说道：“多谢这位"+RANK_D->query_respect(ob)+
"拔刀相助，贫尼感激不尽，无以为报。”\n",ob);
ob->set("marks/savesheni",1);

//        message_vision(HIC "白衣女尼对$N微微一笑。\n" NOR,ob);
	return;
}

obj = all_inventory(environment(ob));
for(i=0; i<sizeof(obj); i++)
{
	if( !living(obj[i]) || userp(obj[i]) || obj[i]==man ) continue;
	if( !userp(obj[i]) ) {
		man->set_leader(obj[i]);
		man->kill_ob(obj[i]);
		obj[i]->fight_ob(man);
		}
	}
return ;
}
int ask_princess()
{
        object ob;
        ob=this_player();
        if ((int)ob->query("marks/savesheni")!=1)  return 0;

        if( (int)ob->query("repute")<=10000 )
        {
        command("pat "+ob->query("id"));
        message_vision("独臂神尼说道：等你在江湖混出点名堂我就告诉你这件事！\n",ob);
        return 1;
        }

         command("look "+ob->query("id")); 
         command("hmm "+ob->query("id")); 
         message_vision("独臂神尼说道：不错，我的确是大明的公主，我一定要刺杀掉鞑子皇帝。\n",ob);
         command("sigh "+ob->query("id")); 
         command("say 但是如果能找到四十二章经..."); 
         return 1;

}

int accept_object(object me, object ob)        
{
        string men;
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;

       if (me->query("mark/savesheni")==1 &&  ob->query("id") != "sishierzhang jing")
        {
        message_vision("独臂神尼说道：辛苦了！但这不是我要的东西！\n",me);
        return 0;
        }
        if (me->query_skill("shenxing-baibian")>=1)
        {
        message_vision("独臂神尼说道：辛苦了！但是我没有什么可以给你的！\n",me);
        command("smile");
        return 1;        
        }
        if ( ob->query("id") == "sishierzhang jing")
        {
        tell_object(me, "我这就教你一套神行百变的入门功夫。\n");
        me->set_skill("shenxing-baibian",10);
        tell_object(me, "你以后勤加练习，可保你性命无忧！\n");        
        tell_object(me, HIC"你学会了「神行百变」！\n"NOR);    
        message("channel:rumor",HIM"【谣言】听说"+me->query("name")+HIM"学会了「神行百变」！\n"NOR,users());
        return 1;
        }
        
        return 0;
}

int ask_bxj()
{
        object me,book;
        me=this_player();
        command("say 《碧血剑》是我一位故人留下的，他说只能送给有缘人！");
        if (me->query("mark/savesheni")<1) return 0;
        if (me->query_temp("bxj/can_give")>=1 && query("book_count")>0)
        {
           command("say 今日我看你我有缘，我就将《碧血剑》赠与你！");
           book=new("/d/reborn/jinyong/obj/bxj");
           book->move(me);
           add("book_count",-1);
           message_vision("独臂神尼送给你一本《碧血剑》！\n",me); 
        }
        return 1; 
}
int ask_guren()
{
        command("hmm");
        return 1; 
}
int ask_ycz()
{
        object me;
        me=this_player();
        command("yi");
        command("look "+me->query("id"));
        command("say 你怎么知道的？我也好多年没有他的消息了。");
        command("sigh");
        if (me->query("mark/savesheni")<1) return 0;
        if (me->query_skill("jinshe-jian")>=1 || me->query_skill("jinshe-zhui")>=1 ||me->query_skill("jinshe-zhang")>=1)
        {
            message_vision("独臂神尼说道：我看你身怀绝技，似乎和他的功夫同出一门，也许就是他的有缘人！\n",me);
            me->set_temp("bxj/can_give",1);
            return 1;
         }
        return 1;
}
