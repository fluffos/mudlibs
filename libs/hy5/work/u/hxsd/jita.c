// aaarose.c

#include <ansi.h>;
#include <command.h>;
inherit ITEM;

void create()
{
	set_name("电吉他", ({"dian jita", "jita"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
这是一把蓝色的，很COOL的电吉他，上面系着几根弦，弹（tan）
起来发出一阵美妙的韵律。
LONG
);
	set("value", 0);
	set_weight(10);
	}
	setup();
}
void init()
{
	add_action("do_tan", "tan");
}
int do_tan(string arg)
{
	object me = this_player();
	if( !arg || arg=="") return notify_fail("你要弹什么？\n");
	
	if( me->query("qi") < 100 )
		return notify_fail("别再唱了，会没命的！\n");
	if( arg == "jita"  || arg == "吉他"){
	   	message_vision("$N很COOL的拿起一把电吉他，激昂的音乐声震撼着每一个少女的心怀。\n",me);
	   	me->add("qi",-100);
	   	me->set("title",HIR +"风"+ HIY +"总是"+ HIW +"吹过"NOR);
	switch( random(22) ) {
                case 0:
           	message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"Don~t Break My Heart，再次温柔，喜悦总是出现在我梦中～～\n"NOR,users());
		break;
                case 1:
                message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"我的热情，好象一把火，燃烧了整个沙漠，太阳见了我，也会躲着我～～\n"NOR,users());
		break;
                case 2:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"我承认都是月亮惹的祸，那样的夜色太美你太温柔～～\n"NOR,users());
		break;
        	case 4:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"都是你的错，轻易爱上我，让我不知不觉满足被爱的虚荣～～\n"NOR,users());
		break;
		case 5:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"今夜的寒风将我心撕碎，怅慌的脚步我不醉不归，朦胧的细雨有朦胧的美～～\n"NOR,users());
		break;
	 	case 6:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"我怎么哭得如此狼狈，是否我对你还有所依恋～～\n"NOR,users());
		break;
	   	case 7:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"一杯酒，二角银，三句告心嘛来凑阵～～\n"NOR,users());
		break;
	   	case 8:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"冷冷的冰雨在脸上胡乱的拍，冷冷的眼泪跟雨水混成一块～～\n"NOR,users());
		break;
	   	case 9:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"我想哭但是哭不出来，跟着～～\n"NOR,users());
		break;
		case 10:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"说了是无心，做了更无情，都说做无情人有何必再写信～～\n"NOR,users());
		break;
		case 11:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"情花开，开灿烂，快乐永无限～～\n"NOR,users());
		break;
		case 12:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"当年相恋意中人，大家性情近，空有爱丝万千丈，早经消散化烟云～～\n"NOR,users());
		break;
		case 13:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"来吧我什么都应承，来吧我什么都听命～～\n"NOR,users());
		break;
		case 14:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"冷雨夜我不想归家，盼望你背影，可苦笑望雨点，虽知要说清楚，可惜我没胆试～～\n"NOR,users());
		break;
		case 15:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"我会搽去我不小心滴下的泪水，还会装做一切都无所谓～～\n"NOR,users());
		break;
		case 16:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"让我将你心儿摘下，试着让它漫漫融化，看我在你心中是否仍完美無瑕～～\n"NOR,users());
		break;
		case 17:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"当他对你说一往情深，你千万不要信以为真，不要轻易的付出你的吻～～\n"NOR,users());
		break;
		case 18:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"哦相思无用，哦相思无用，对我是一种太昂贵的痛～～\n"NOR,users());
		break;
		case 19:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"Every Sha La La La，Every How How，Sunshine～～\n"NOR,users());
		break;
		case 20:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"我的爱如潮水，爱如潮水将我向你推，紧紧跟随，爱如潮水它将你我包围～～\n"NOR,users());
		break;
		case 21:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"今天晚上的星星很少，不知道它们到哪里了～～\n"NOR,users());
		break;
		case 22:
		message("channel:chat",HIY"〖"+me->query("name")+"九九汕头演唱会〗："HIC"哎哟向着天空拜拜呀勇敢站起来，老天爱笨小孩。\n"NOR,users());
		break;
		}
	return 1;
	}
}
