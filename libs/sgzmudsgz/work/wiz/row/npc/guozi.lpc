// guozi.c 大锅子 by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_INPUT;

int query_status();
void set_islu();
int query_islu();
void do_wave();
int query_clean_up();
void set_isfill();
int query_isfill();
mixed direct_turn_obj();
int turn();
void do_clear();
void clear_it();

string *desc = ({
"一口大锅子，隐隐可以闻到香甜的味道，你看见里面盛了满满一锅和了水\n的%^H_YELLOW%^豆粉%^RESET%^，而且锅下已经点起了小火，似乎万事俱备(wave fan)。\n",
"大锅里的水微微地冒了些小泡泡，泡泡破裂后，释放出了丝丝热气(wave fan)。\n",
"大锅里的水泡越来越多，争先恐后地涌出水面，%^H_YELLOW%^豆粉%^RESET%^也伴随着欢快地翻腾着(wave fan)。\n",
"大锅里的水已经完全沸腾了，一片白白的热气，教人无法看清%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^是\n不是已经完全煮好了(wave fan)。\n",
"一口大锅子，里面满是浅黄色、浓浓香甜的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^，还冒着热气呢(turn cruet)。\n",
"一口大锅子，里面满是浅黄色、浓浓香甜的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^，仔细看，可以发现\n面上飘着一层%^H_CYAN%^卤汁%^RESET%^(turn guozi)。\n",
"一口大锅子，是关夫子用来煮%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^的器具，锅下的灶头里堆着柴火。\n",});
int status; // 0-30
int push;
int isfill; // there is soy powder in
int islu;
string short();

void setup()
{
	set_unit("口");
	set_id("guozi","大锅子");
	set_in_room_desc("一口大锅(guozi)，安在灶头上，可以用来煮些东西。");
	status=0;
	isfill=0;
	islu=0;
}
string long()
{
	if(islu==1)
	return desc[5];
	if(isfill==1&&status==0)
	return desc[0];
	if(isfill==1&&status<10)
	return desc[1];
	if(isfill==1&&status<20)
	return desc[2];
	if(isfill==1&&status<35)
	return desc[3];
	if(isfill==1&&status<40)
	return desc[4];
	return desc[6];
}
int query_status()
{
	return status;
}
void set_islu()
{
	islu=1;
}
int query_islu()
{
	return islu;
}
void do_wave()
{
	status=status+2+random(2);
}
int query_clean_up()
{
	return 1;
}
void set_isfill()
{
	isfill=1;
}
int query_isfill()
{
	return isfill;
}
mixed direct_turn_obj()
{
	return 1;
}
int turn()
{
	object player;
	object room;
	object mutong,guozi;
	int stat;
	player = this_body();
	room = environment( player );
	guozi=present("guozi",room);
	mutong=present("mutong",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N对着锅子直眨巴眼睛，不知道怎么办才好。\n");
	return 1;
	}
	if(!isfill)
	{
	write("锅子里什么都没有，你要做什么？\n");
	return 1;
	}
	if(status<35)
	{
	write("%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^还没有煮好呢。\n");
	return 1;
	}
	if( !mutong = present("mutong", room) )
	{
	write("你要把%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^倒到哪里去？\n");
	return 1;
	}
	stat=mutong->query_isfill();
	if (stat==1)
	{
	write("木桶里已经装满%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^了。\n");
	return 1;
	}
      this_body()->simple_action("$N先把灶头里的火弄熄，然后吃力地抬起大锅子，将香甜的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^一下子全倾入了一旁的大木桶里。\n");
	this_body()->start_busy(5,"你正忙着倒%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^呢。\n");
	status=0;
	isfill=0;
	islu=0;
	mutong->set_isfill();
	mutong->do_cold();
	return 1;
}
void do_clear()
{
	call_out("clear_it",180);
	return;
}
void clear_it()
{
	if(islu==1)
	{
	status=0;
	isfill=0;
	islu=0;
	tell_environment(this_object(),"锅子里点过卤的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^由于放的时间太长，变质了，只能倒掉了。\n");
	return;
	}
	if(isfill==1)
	{
	status=0;
	isfill=0;
	islu=0;
	tell_environment(this_object(),"锅子里的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^由于放的时间太长，错过了点卤的时机，只能倒掉了。\n");
	return;
	}
}
