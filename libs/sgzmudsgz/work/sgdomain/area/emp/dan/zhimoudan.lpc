#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	this_body()->set_zhimou_pure(30);
	
	this_body()->simple_action(
"$N迫不及待地「咕噜」一下服下一枚%^H_MAGENTA%^智谋丹%^RESET%^，顿时感到自己的脑筋变得更聪明灵活了。\n");
}
void setup()
{   set_id("zhimou dan", "%^H_MAGENTA%^智谋丹%^RESET%^");
    set_long("一粒诱人的%^H_MAGENTA%^智谋丹%^RESET%^，听说服了可以使人的智谋天赋变为最大值30。");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("粒");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
