// by fire on Jan 9 1998 barrel.c
#include <ansi.h>
#include <mudlib.h>
inherit M_INPUT;
inherit OBJ;
inherit M_GETTABLE;

void setup() {
	set_adj("颗粒饱满的");
	set_long("这是一袋上选的%^H_YELLOW%^黄豆%^RESET%^，用来做豆腐是最好不过的了。\n");
	set_id("soy bean", "%^H_YELLOW%^黄豆%^RESET%^","soybean");
	set_unit("袋");
	set_in_room_desc("一袋颗粒饱满的%^H_YELLOW%^黄豆%^RESET%^(soy bean)。\n");
	set_can_give(0);
	set_is_keeping(1);
	set_can_drop(0);
	set_can_drop("把黄豆丢了就拿不到工钱了。\n");
	set_size(SMALL);
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
	object shimo,soy;
	int stat;
	player = this_body();
	room = environment( player );
	soy=present("soy bean",player);
	shimo=present("shimo",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N一阵手忙脚乱，将%^H_YELLOW%^黄豆%^RESET%^洒了一地。\n");
	destruct(soy);
	return 1;
	}
	if( !shimo = present("shimo", room) )
	{
	write("你想把%^H_YELLOW%^黄豆%^RESET%^倒到什么地方？\n");
	return 1;
	}
	stat=shimo->query_isfill();
	if(stat==1) {
	write("石磨里已经装满%^H_YELLOW%^黄豆%^RESET%^了。\n");
	return 1;
	}
      this_body()->simple_action("$N提起袋底，将满满一口袋%^H_YELLOW%^黄豆%^RESET%^全倒入了石磨里。\n");
	shimo->set_isfill();
	destruct(soy);
	return 1;
}
void dest()
{
	string p_id;
	p_id=this_body()->query_primary_id();
	tell_user(p_id,"由于长时间不用，口袋被磨了一个洞，%^H_YELLOW%^黄豆%^RESET%^全漏光了。\n");
	destruct(this_object());
}