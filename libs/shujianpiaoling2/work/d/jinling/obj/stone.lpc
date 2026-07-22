// cai.c

inherit ITEM;

string* titles = ({
	"口磨肥鸡",
	"三鲜鸭子",
	"五绺鸡丝",
	"炖肉",
	"炖肚肺",
	"肉片炖白菜",
	"黄焖牛肉",
	"羊肉炖菠菜豆腐",
	"樱桃肉山药",
	"驴肉炖白菜",
	"羊肉片川小萝卜",
	"鸭条溜海参",
	"鸭丁溜葛仙米",
	"烧茨菇",
	"肉片炖玉兰片",
	"羊肉丝炖跑肚丝",
	"黄韭菜炒肉",
	"熏肘花小肚",
	"熏干丝",
	"烹掐菜",
	"花椒油炒白菜丝",
	"白煮塞勒",
	"烹白肉",
});


void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "cai", "xiaocai" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一盆十分可口的小菜。\n");
		set("unit", "盆");
		set("value", 3000);
		set("remaining", 4);
		set("food_supply", 25);
	}
	setup();
}
void init()
{
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{
	int i = random(sizeof(titles));

    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("你已经吃太饱了，再也吃不下了。\n");

    set("value", 0);
    this_player()->add("food", (int)query("food_supply"));

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") ){
		if ((string)this_player()->query("gender") == "男性")	{
   		 message_vision("$N从盆里夹起了一些菜送入口中，狼吞虎咽地吃起来。\n", this_player());
		} 
		else if ((string)this_player()->query("gender") == "女性") {
		message_vision("$N十分优雅地从盆里夹起了一些菜送入口中。\n", this_player());
		}
	}
	else 	{ 
		if ((string)this_player()->query("gender") == "男性")	{
   		 message_vision("$N将盆里的菜吃了精光，再把盆子添了个干干净净。\n",this_player());
		destruct(this_object());
		}
		else if ((string)this_player()->query("gender") == "女性") {
		 message_vision("$N吃光了盆里的菜，又拿出一方丝帕，轻轻地擦了擦嘴。\n",this_player());
		destruct(this_object());
		}
	}

	return 1;
}

