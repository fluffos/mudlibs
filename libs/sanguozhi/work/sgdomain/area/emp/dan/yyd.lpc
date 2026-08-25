// candy.c 大白兔奶糖 by fire on Jan 7, 1998
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	int rm;
	mixed gift;
	string p_id;
	/*rm=this_body()->query_sg_rongmao();
	rm+=random(3)+1;
	rm=bmin(30,rm);*/
	this_body()->set_sg_rongmao(30);
	p_id=this_body()->query_primary_id();
	gift=CHAR_D->get_char(p_id,"gift");
	if(mapp(gift)) {
		gift["rongmao"]=30;
		CHAR_D->set_char(p_id,"gift",gift);
	}
	if(this_body()->query_gender()==1) {
		this_body()->simple_action(
"$N迫不及待地「咕噜」一下服下一枚%^H_MAGENTA%^养颜丹%^RESET%^，一边不可置信地摸了模自己的面孔。\n");
	}
	else {
		this_body()->simple_action(
"$N拈起一枚%^H_MAGENTA%^养颜丹%^RESET%^，轻轻地放入口中，咽了下去。\n$N连忙找到一面铜镜，照了又照，发觉自己变得更加美丽动人了。\n");
	}
}
void setup()
{   set_id("yangyan dan", "%^H_MAGENTA%^养颜丹%^RESET%^");
    set_long("一粒诱人的%^H_MAGENTA%^养颜丹%^RESET%^，听说服了可以使人变得更漂亮。");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("粒");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
