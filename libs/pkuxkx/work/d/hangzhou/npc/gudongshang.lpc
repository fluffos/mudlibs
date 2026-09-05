// 游方和尚 By Zine
               
#include <ansi.h> 
inherit NPC; 
int adv();
int ask_jianding();
void create()
{
	set_name("古董店掌柜", ({ "gudong zhanggui","zhanggui",}));
        
	set("long",
	"他是一位古董商请来的掌柜，想从他那里赚到便宜十分不易。\n"
         );
	set("gender", "男性");
	
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
    set("uni_target",1);
    set("no_get",1);
	set("max_qi", 1000);
    set("qi", 1000);
    set("max_jing", 1000);
    set("jing", 1000);
    set("max_jingli", 1000);
    set("jingli", 1000);
    set("neili", 900);
	set("max_neili", 900);
	set("jiali", 5);
    set_skill("hand", 50);
	set_skill("parry",50);
	set_skill("dodge", 50);
	set_skill("force",50);
	set_skill("literate",100);
    set_skill("identification",1000);
    set_skill("anti-disguise",1000);
	set("combat_exp", 1+random(10000));
    set("inquiry", ([
			"鉴定" : (: ask_jianding :),
            "jianding" : (: ask_jianding :),
     
       	]) );    
        setup();
        carry_object("/d/changan/npc/obj/jin-cloth")->wear();
        
	

}

int ask_jianding()
{
    object me=this_player();
    object *inv=all_inventory(me);
    object item;
    int i,count=0;
    if (me->is_busy()||me->is_fighting())
    {
        command("say 看你手忙脚乱的。");
        command("smile");
        return 1;
    }
    if (me->query_temp("允许鉴定"))
    {
        command("say 那就快把你的宝贝拿给我吧。");
        return 1;
    }
    for(i=sizeof(inv)-1; i>=0; i--)
    {
        if(!inv[i]->query("is_guwanzihua"))
        continue;
        item = inv[i];
    }
    if (!item)
    {
        command("say 你身上什么都没有，鉴定什么呀？");
        return 1;
    }
    else
    {
        command("say 你是要我鉴定"+item->query("name")+"吗？那就快拿过来吧？");
        command("say 每次鉴定要收取古董实际价值的两成作为我的酬劳，假如你身上没钱，我就用两成价格把这古董买下了，如果同意，就把货给我吧。");
        me->set_temp("允许鉴定",1);
        return 1;
    }
            
}

int receive(object ob,object me)
{
    int amount;
    string moneygiven;
    message_vision("$N小心地捧着$n上上下下仔仔细细的打量了一遍。\n",this_object(),ob);
    ob->rename();
    amount=(int)ob->query("value")/5;
    moneygiven=MONEY_D->money_str(amount);
    message_vision("$N颤声道：“这竟是"+ob->query("name")+"”。\n",this_object());
    if (MONEY_D->player_pay(me,amount))
    {
        message_vision("$N赶紧按照之前约定，塞给了"+this_object()->query("name")+moneygiven+"，一把抢过$n，抱在怀里。\n",me,ob);
        me->delete_temp("允许鉴定");
        ob->move(me);
        this_object()->delete("jianding");
        return 1;
    }
    else
    {
        message_vision("$N露出了老狐狸般的笑容，既然你没钱，按之前的约定，我就用"+moneygiven+"的价格收购了。\n",this_object());
        destruct(ob);
        me->delete_temp("允许鉴定");
		this_object()->set("profit",1);
        this_object()->delete("jianding");
        MONEY_D->pay_player(me,amount);
        tell_object(me,this_object()->query("name")+"付给你"+moneygiven+"。\n");
        command("heihei");
        return 1;
    }
}

int accept_object(object me,object ob)
{
    if (!me->query_temp("允许鉴定"))
    {
        return notify_fail("你得同意我的条件，我才能帮你鉴定。\n");
    }
    if (!ob->query("is_guwanzihua"))
    {
        return notify_fail("你这破烂是给赝品，我看就不用鉴定了。\n");
    }
    if (this_object()->query("jianding"))
    {
        return notify_fail("没看我正忙着吗？\n");
    }
    call_out("receive",3,ob,me);
    this_object()->set("jianding",1);
    return 1;
}


void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}