inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	int rm;
	rm=this_body()->query_shouming();
	rm+=random(5)+2;
	rm=bmin(100,rm);
	this_body()->set_shouming(rm);
	if(this_body()->query_gender()==1) {
		this_body()->simple_action(
"$N囫囵吞下了一枚%^H_YELLOW%^长生不老丹%^RESET%^，双目微闭，长长地嘘了一口气，只觉得浑身舒畅。\n");
	}
	else {
		this_body()->simple_action(
"$N服下一枚%^H_YELLOW%^长生不老丹%^RESET%^，正开心不已，忽然想到容颜将老，不由得「唉」地轻叹了一声。\n");
	}
}
void setup()
{   set_id("changsheng dan", "%^H_YELLOW%^长生不老丹%^RESET%^");
    set_long("一粒金黄色的%^H_YELLOW%^长生不老丹%^RESET%^，听说吃了可以延年益寿。");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("粒");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
