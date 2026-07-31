#include <ansi.h>
inherit NPC;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
void pay_him(object who, int amount);
void clear_stat();
void create()
{
        set_name( "雷九指", ({ "lei jiuzhi","lei" }) );
        set("long", "这是这里的职业赌手，骰子上的功夫出神入化。\n");
        set("attitude", "friendly");
        set("title", HIW "大千手" NOR);
        set("jiali", 30);
        set("max_jing", 3000);
        set("max_qi", 3000);
        set("max_jing", 300);
        set("jing", 300);
        set("max_neili", 3000);
        set("meili", 3000);
        set("age", 33);
        set_temp("apply/damage",600);
        set("gender", "男性" );
        set("str", 35);
        set("con", 30);
        set("cps", 25);
        set("per",5);
        set("lower_limit",1);
        set("too_late",0);
        set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
        set("max_force",400000);
        set_skill("throwing",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set("combat_exp", 50000000);
        setup();
        carry_object(__DIR__+"obj/cloth")->wear();
        carry_object(__DIR__"obj/guzi")->wield();
}
void init()
{
        object ob;
        ::init();
        if (base_name(environment())!=query("startroom")) return;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
        add_action("do_bet", "bet");
        
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "雷九指笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来赌两手，开开心吧。\n");
                        break;
                case 1:
                        say( "雷九指晃了晃手中的骰子，叫道：这位" + RANK_D->query_respect(ob)
                                + "，小赌可以养家糊口，大赌可以定国安邦。来吧！\n");
                        break;
                case 2:
                        say( "雷九指说道：这位" + RANK_D->query_respect(ob)
                                + "，进来！进来！ 输了算我的！\n");
                        break;
        }
        return;
}
 
string *dice = ({
HIW"
         ┏━━━┓
         ┃      ┃
         ┃  "+HIR+"⊙"+HIW+"  ┃
         ┃      ┃
         ┗━━━┛
"NOR,
HIW"
         ┏━━━┓
         ┃"+HIY+"⊙"+HIW+"    ┃
         ┃      ┃
         ┃    "+HIY+"⊙"+HIW+"┃
         ┗━━━┛
"NOR,
HIW"
         ┏━━━┓
         ┃"+HIY+"⊙"+HIW+"    ┃
         ┃  "+HIY+"⊙"+HIW+"  ┃
         ┃    "+HIY+"⊙"+HIW+"┃
         ┗━━━┛
"NOR,
HIW"
         ┏━━━┓
         ┃"+HIR+"⊙"+HIW+"  "+HIR+"⊙"+HIW+"┃
         ┃      ┃
         ┃"+HIR+"⊙"+HIW+"  "+HIR+"⊙"+HIW+"┃
         ┗━━━┛
"NOR,
HIW"
         ┏━━━┓
         ┃"+HIY+"⊙"+HIW+"  "+HIY+"⊙"+HIW+"┃
         ┃  "+HIY+"⊙"+HIW+"  ┃
         ┃"+HIY+"⊙"+HIW+"  "+HIY+"⊙"+HIW+"┃
         ┗━━━┛
"NOR,
HIW"
         ┏━━━┓
         ┃"+HIY+"⊙"+HIW+"  "+HIY+"⊙"+HIW+"┃
         ┃"+HIY+"⊙"+HIW+"  "+HIY+"⊙"+HIW+"┃
         ┃"+HIY+"⊙"+HIW+"  "+HIY+"⊙"+HIW+"┃
         ┗━━━┛
"NOR});



int do_bet(string arg)
{
        int i,bet_amt,amount;
        int bet_type;
        object me, money_ob;
        string message,money;
        if(!arg || !sscanf(arg, "%d %d %s",bet_type,amount,money))
                return notify_fail("bet <种类> <数量> <货币名称>\n");
        if(bet_type>18 || bet_type < 0)
                return notify_fail("种类只可从零到十八\n");
        me = this_player();
        if(me->is_busy())
                return notify_fail("你上个动作还没完成。\n");
                money_ob = present(money + "_money", me);
        if(!money_ob) return notify_fail("你身上没有这种钱。\n");
                if (amount<0)   return notify_fail("你至少要下一个子。\n");
        if((int) money_ob->query_amount() < amount)
                return notify_fail("你身上没有那麽多"+money_ob->query("name")+"。\n"); 
        if((int) this_object()->query("too_late") )
                return notify_fail("这铺来不及了，等下手吧．\n");
                bet_amt=amount * money_ob->query("base_value");
                if (me->query_temp("gamble/amount")+bet_amt<0
                || me->query_temp("gamble/amount")+bet_amt>1000000000)
                        return notify_fail("压这么多钱，小的怕赔不起。\n");
                money=money_ob->query("base_unit")+money_ob->query("name");
                i=money_ob->value()-bet_amt;
                destruct(money_ob);
                if (i>0)
                        pay_him(me,i);
                else
                if (i<0)
                        say(BOLD "财神从桌子底下伸了只手出来："+me->name(1)+"，你身上的钱太多了，还是我帮你保管吧。\n" NOR);
        if((int) me->query_temp("gamble/amount")) { 
                if(bet_type != (int) me->query_temp("gamble/type"))
                        return notify_fail("你不可在一铺中下不同的注．\n");
                if(bet_type == 0)
                        message = sprintf(RED"小"NOR);
                if(bet_type == 1)
                        message = sprintf(RED"大"NOR);
                if(bet_type == 2)
                        message = sprintf(RED"围骰"NOR);
                if(bet_type >=3)
                        message = sprintf(RED"%s"NOR,chinese_number(bet_type));
                    message_vision(sprintf("$N又从身上拿出%s%s，加压在%s上．\n",
                                chinese_number(amount), money,message), me);
                bet_amt += (int) me->query_temp("gamble/amount");
            me->set_temp("gamble/amount",bet_amt);
        }
        else
        {
                if(bet_type == 0)       
                        message = sprintf(RED"小"NOR);
                if(bet_type == 1)
                        message = sprintf(RED"大"NOR);
                if(bet_type == 2)
                        message = sprintf(RED"围骰"NOR);
                if(bet_type >=3)
                        message = sprintf(RED"%s"NOR,chinese_number(bet_type));
                message_vision(sprintf("$N从身上拿出%s%s，压在%s上．\n",
                                        chinese_number(amount),money, message), me);
                me->set_temp("gamble/type",bet_type);
                me->set_temp("gamble/amount",bet_amt);
        }
        stat[bet_type] += bet_amt;
        if( find_call_out("rolldice") == -1)
                call_out("rolldice",30);
        if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
                call_out("advertise",random(5)+1);
        return 1;
}

void advertise()
{
        if (is_fighting()) return;
        switch( random(3) ) {
                case 0: message_vision("$N向你笑道：快下注！这注你一定会赢！\n",this_object());
                        break;
                case 1: message_vision("$N说道：再不下注就来不及了！\n",this_object());
                        break;
                case 2: message_vision("$N满面红光，耸恿着大家：加！再加大你的赌注！一定赢！\n",this_object());
                        break;
        }
        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
        return;
}

void rolldice()
{
        if (is_fighting()) return;
        this_object()->set("too_late",1);
        message_vision("$N大声叫道：下定注！说罢，将手中的三粒骰子撒向碗里．\n",this_object());
        message_vision("\n．．．三粒骰子在碗里蹦跳着，发出悦耳的声音．．．\n",this_object());
        call_out("first_dice",3);
        return;
}

void first_dice()
{
        int first;
        this_object()->set("first_dice",(random(1000)%18)/3);
        switch( random(3) ) {
                case 0:
        message_vision("\n一粒骰子弹了几下，停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n一粒骰子＂叮叮叮＂的跳动了几下，缓缓的停了下来：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n三粒骰子相互一撞，一颗直落碗底：\n\n",this_object());
                        break;
        }
        first = (int) this_object()->query("first_dice");
        message_vision(dice[first], this_object());
        this_object()->set("first_dice",first+1);
        call_out("second_dice",4);
        return;
}

void second_dice()
{
        int second;
        this_object()->set("second_dice",(random(1000)%18)/3);
        if (this_object()->query("first_dice")+1 ==this_object()->query("second_dice") )
                this_object()->set("second_dice",(random(1000)%18)/3);
        switch( random(3) ) {
                case 0: message_vision("\n又一粒骰子缓缓的停了下来：\n\n",this_object());
                        break;
                case 1: message_vision("\n第二粒骰子在碗边旋转不停．．忽地翻了个身：\n\n",this_object());
                        break;
                case 2: message_vision("\n二粒骰子相互一撞，其中一颗跳了一跳：\n\n",this_object());
                        break;
        }
        second= (int) this_object()->query("second_dice");
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
        call_out("third_dice",5);
        return;
}
void third_dice()
{
        int third;
        this_object()->set("third_dice",(random(1000)%18)/3);
        if (this_object()->query("third_dice")+1 ==this_object()->query("second_dice") )
                this_object()->set("third_dice",(random(1000)%18)/3);
        if (this_object()->query("third_dice")+1 ==this_object()->query("first_dice") )
                this_object()->set("third_dice",(random(1000)%18)/3);
        switch( random(3) ) {
                case 0:
       message_vision("\n最后一粒骰子在碗里滑了两下，终于停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n还有最后一粒骰子嘀遛遛的转个不停．．终于：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n最后一粒骰子也终于停稳了：\n\n",this_object());
                        break;
        }
        third= (int) this_object()->query("third_dice");
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",2);
        return;
}
void end_the_round()
{
        int tot,reward,i,first, second, third,j;
        object *inv;
        first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");
// announce results:
        message_vision(sprintf("\n$N高声叫道：%s，%s，%s，",
                chinese_number(first),chinese_number(second),chinese_number(third)),
                this_object());
// see who is the winner!
        if (!first || !second || !third){
                tot = first+second+third;
                message_vision(sprintf("%s....点，啊?！骰子摔烂了，不好意思，大小通吃!\n",chinese_number(tot)),this_object());
                inv = deep_inventory(environment(this_object()));
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i] && userp(inv[i]) && (int) inv[i]->query_temp("gamble/amount") )
                        {
                                inv[i]->set_temp("gamble/amount",0);
                        }
                }
        }else
        if( second == first && third == first)
        {
        message_vision("大小通吃！！\n",this_object());
        inv = deep_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i] && userp(inv[i]) && (int) inv[i]->query_temp("gamble/amount") )
                {
                        if((int) inv[i]->query_temp("gamble/type") == 2)
                        {
                                message_vision("赢家－$N，一赔三十六！！\n",inv[i]);
                                reward = (int) inv[i]->query_temp("gamble/amount");
                                for (j=0; j<=36;j++)
                                        pay_him( inv[i],reward);
                        }
                        inv[i]->set_temp("gamble/amount",0);
                }
        }
        }else{
                tot = first+second+third;
                message_vision(sprintf("%s点，",chinese_number(tot)),this_object());
                if( tot>10 )
                        message_vision("赔大吃小！\n",this_object());
                else
                        message_vision("赔小吃大！\n",this_object());
        inv = deep_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        if( inv[i] && userp(inv[i]) && (int) inv[i]->query_temp("gamble/amount") )
        {
                if((int) inv[i]->query_temp("gamble/type") == tot)
                {
                message_vision("赢家－$N，一赔四！\n",inv[i]);
                                reward = (int) inv[i]->query_temp("gamble/amount");
                                for (j=0; j<=4;j++)
                      pay_him( inv[i],reward);
                inv[i]->set_temp("gamble/amount",0);
                }
                else 
                if(((int) inv[i]->query_temp("gamble/type") == 0 && tot <=10 ) ||
                        ((int) inv[i]->query_temp("gamble/type") == 1 && tot > 10 ))
                {
                message_vision("赢家－$N，一赔一！\n",inv[i]);
                                reward = (int) inv[i]->query_temp("gamble/amount");
                                for (j=0; j<=1;j++)
                      pay_him( inv[i],reward);
                inv[i]->set_temp("gamble/amount",0);
                }
                else
                {
// here are the losers
                reward = (int) inv[i]->query_temp("gamble/amount");
                // inv[i]->decrease_skill("betting", reward, 1);
                inv[i]->set_temp("gamble/amount",0);
                }
        }
        }
        }
        this_object()->set("too_late",0);
        this_object()->set("first_dice",0);
        this_object()->set("second_dice",0);
        this_object()->set("third_dice",0);
        clear_stat();
        return;
}
void pay_him(object who, int amount)
{
        object ob;
        if( amount < 0 ){
            say(BOLD "财神从桌子底下伸了只手出来："+who->name(1)+"，你身上的钱太多了，还是我帮你保管吧。\n" NOR);
            return;
        }
                if (environment(who)!=environment(this_object()))     return;
        if( amount/10000000 ) {
               ob = new(THGOLD_OB);
               ob->set_amount(amount/10000000);
               if ( !ob->move(who) )
                     ob->move(environment(who));
                amount %= 10000000;
        }
        if( amount/100000 ) {
               ob = new(THCASH_OB);
               ob->set_amount(amount/100000);
               if ( !ob->move(who) )
                     ob->move(environment(who));
                amount %= 100000;
        }
        if( amount/10000 ) {
               ob = new(GOLD_OB);
               ob->set_amount(amount/10000);
               if ( !ob->move(who) )
                     ob->move(environment(who));
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                if (!ob->move(who))
                     ob->move(environment(who));
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                if (!ob->move(who))
                     ob->move(environment(who));
        }
}
int accept_object(object who, object ob)
{
        int bet_type;
        string message;
        
                if( ob->value() >= 100) {
                        say("雷九指呵呵的笑道：谢赏...\n");
        message_vision("$N在$n耳边嘀咕了几句．．\n",this_object(),who);
        bet_type = random(1000)%19;
        if(bet_type == 0)
                message = sprintf(RED"小"NOR);
        if(bet_type == 1)
                message = sprintf(RED"大"NOR);
        if(bet_type == 2)
                message = sprintf(RED"围骰"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
        tell_object(who,"雷九指悄悄告诉你：下手儿压"+message+"，一定赢！\n");
        message_vision("$N会心的微笑起来．．\n",who);
        
                        return 1;
                } else {
                    say("雷九指说道：这点钱你还是自己用吧！\n");
                        return 0;
                }
        return 0;
}
void clear_stat()
{
        int i;
        for(i=0;i<=18;i++)
                stat[i]=0;
}
void die()
{
 foreach (object user in deep_inventory(environment(this_object()))){
        if( user && userp(user))
        {
          user->delete_temp("gamble");
        }
 }
 ::die();
}

