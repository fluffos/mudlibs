
int do_zhao(string arg)
{
	object yaocai;
	object me;
	string name;

	me = this_player();
	name = me->query_temp("caiyao_name");

	if (me->is_busy())
		return notify_fail ("你现在很忙！\n");

	if (me->is_fighting())
		return notify_fail ("你还是专心战斗吧。！\n");

	if (!( present("yao chu", me)))
		return notify_fail("你正在找寻药材，突然发现忘带药锄，不禁暗暗懊恼！！\n");

	if ( !arg || arg != "yaocai" )
		return notify_fail("你要找什么？\n");

	if (! me->query_temp("caiyao_room"))
		return notify_fail("现下这些药材可是紧缺异常，你就不要糟蹋了吧！？\n");

	if ( me->query("jingli") < 200)
		return notify_fail ("你已十分疲惫，需要好好休息了！\n");

	me->add("jingli",-(60+random(20)));
	message_vision("$N眼光似电，迅速的在丛林中搜寻着。\n", me);

	if( this_object()->query("caiyao_room") < 1 || random(10) < 8 )
		return notify_fail("你举目四顾，哪有半分药材的影子，还是到其他地方看看吧！\n");

	me->delete_temp("caiyao_room");
	me->set_temp("caiyao_ok",1);
	me->add("jingli", -30);
	this_object()->add("caiyao_room", -1);
	message_vision("$N拨开草丛，突然发现一株"YEL+name+NOR",欣喜如狂，赶忙轮起药锄挖了起来，放入怀中。\n",me);
	switch(name) {
		case "生地":	yaocai= new(MEDICINE_D("wudang/shengdi"));	break;
		case "茯苓":	yaocai=new(MEDICINE_D("wudang/fuling"));	break;
		case "红花":	yaocai=new(MEDICINE_D("wudang/honghua"));	break;
		case "灵仙":	yaocai=new(MEDICINE_D("wudang/lingxian"));	break;
		case "桃仙":	yaocai=new(MEDICINE_D("wudang/taoxian"));	break;
		case "没药":	yaocai=new(MEDICINE_D("wudang/meiyao"));	break;
		case "五灵脂":	yaocai=new(MEDICINE_D("wudang/wulingzhi"));	break;
		case "千金子":	yaocai=new(MEDICINE_D("wudang/qianjinzi"));	break;
		case "当归":	yaocai=new(MEDICINE_D("wudang/danggui"));	break;
		case "远志":	yaocai=new(MEDICINE_D("wudang/yuanzhi"));	break;
		case "独活":	yaocai=new(MEDICINE_D("wudang/duhuo"));		break;
		case "防风":	yaocai=new(MEDICINE_D("wudang/fangfeng"));	break;
	}
	yaocai->move(me);
	return 1;
}
