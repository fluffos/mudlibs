// by row on 12/1999 cruet.c
#include <ansi.h>
#include <mudlib.h>
inherit M_INPUT;
inherit OBJ;
inherit M_GETTABLE;

void setup() {
	set_adj("发出咸味的");
	set_long("这是一瓶用独家配方调出来的%^H_CYAN%^卤汁%^RESET%^。\n");
	set_id("cruet", "%^H_CYAN%^卤汁瓶%^RESET%^");
	set_unit("个");
	set_in_room_desc("一个小瓶子，里面装着%^H_CYAN%^卤汁%^RESET%^(cruet)。\n");
	set_can_give(0);
	set_is_keeping(1);
	set_can_drop(0);
	set_can_drop("把这个瓶子丢了就做不成豆腐了。\n");
	set_size(VERY_SMALL);
	call_out("dest",600);
}
mixed direct_turn_obj()
{
	return 1;
}
int turn()
{
	object player;
	object room;
	object guozi,cruet;
	int stat,isfill,status;
	player = this_body();
	room = environment( player );
	cruet=present("cruet",player);
	guozi=present("guozi",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N一不小心，瓶子脱手而出，掉在地上摔破了，顿时香味四溢。\n");
	destruct(cruet);
	return 1;
	}
	if( !guozi = present("guozi", room) )
	{
	write("你想把%^H_CYAN%^卤汁%^RESET%^倒在什么地方？\n");
	return 1;
	}
	isfill=guozi->query_isfill();
	if(!isfill)
	{
	write("锅子里什么也没有，别浪费这么好的%^H_CYAN%^卤汁%^RESET%^。\n");
	return 1;
	}
	stat=guozi->query_islu();
	if(stat==1)
	{
	write("锅子里的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^已经点过%^H_CYAN%^卤%^RESET%^了。\n");
	return 1;
	}
	status=guozi->query_status();
	if(status<35)
	{
	write("锅子里的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^还没有煮好，不能点%^H_CYAN%^卤%^RESET%^(wave fan)。\n");
	return 1;
	}
      this_body()->simple_action("$N拿出小瓶子，将%^H_CYAN%^卤汁%^RESET%^小心翼翼地倒入了大锅子中的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^里，点卤完成了！\n");
	guozi->set_islu();
	destruct(cruet);
	return 1;
}
void dest()
{
	string p_id;
	p_id=this_body()->query_primary_id();
	tell_user(p_id,"由于长时间不使用，%^H_CYAN%^卤汁%^RESET%^变质，只能倒掉了。\n");
	destruct(this_object());
}