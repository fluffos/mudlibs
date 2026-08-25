inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	int sw;
	string p_id;
	p_id=this_body()->query_primary_id();
	sw=CHAR_D->get_char(p_id,"reputation");		//获取声望值
	sw+=10000;
	CHAR_D->set_char(p_id,"reputation",sw);
	
	this_body()->simple_action(
"$N服下了一枚%^H_MAGENTA%^声望丹%^RESET%^，效果立竿见影，声望马上变大了一万点。\n");
}
void setup()
{   set_id("shengwang dan", "%^H_MAGENTA%^声望丹%^RESET%^");
    set_long("一粒紫色的%^H_MAGENTA%^声望丹%^RESET%^，听说吃了可以加一万点声望。");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("粒");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
