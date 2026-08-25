//**********************************************// write by benben 29/12/97 benben.c 小东西#include <mudlib.h>inherit LIVING;inherit M_ACTIONS;inherit M_TRIGGERS;void setup() {    set_name("ben ben", "小东西");    add_id("ben ben","ben","小东西");    set_gender(2);    set_proper_name("小东西");    set_in_room_desc("厨房里的小东西(Ben ben)");    set_long("小东西正忙的满头大汗，满手油腻地。一抬头看到你：\n"+"“还楞着干嘛！快过来帮忙！都是些好吃懒做得家伙！”\n\n");	add_question("food","food");}void special_answer(object who, string matt){	switch(matt)	{		case "food" :			this_object()->simple_action("小东西兴高采烈地说：“今儿晚上我请客。满汉全席！吃完了咱们唱卡拉OK去。”\n");			return;	}
    set_actions( 2, ({
        "say 又想来骗饭？",
            "say 我可没打算请你。",
            "say 烈火是个大坏蛋！",
            "say ？",
            "say 小东西今天没空上网，她过年去了。",
            "say 三国演义我越看越来气，怎么全是无赖呀？",
            "say 你怎么没穿衣服就来我家？",
            "say 没酱油了，你帮我去买一瓶吧？",
            "say ",
            "heng",
            "grin"
            }) );
     add_pattern("%s突然出现在一阵烟雾中。",function(){
        if ($1=="小东西")
        {
                respond("jump");
        }
        if ($1=="烈火")
        {
                respond("kick fire");
                respond("heng fire");
        }
        else
        {
                respond("smile");
                respond("welcome");
        }
        });

    add_pattern("%s一脚踢到你%s。",function(){ 
	respond("kick $1");
   	respond("chat *slogan $1");
} );
}