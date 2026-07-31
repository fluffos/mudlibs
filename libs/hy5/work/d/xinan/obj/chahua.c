// chahua.c

inherit ITEM;

string *flower_name = ({
    "「十八学士」",
    "「羽衣霓裳」",
    "「步步生莲」",
    "「美人抓破脸」",
    "「紫袍」",
    "「恨天高」",
});



void create()
{
	set_name(flower_name[random(sizeof(flower_name))], ({ "cha hua", "flower" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盆名贵的「十八学士」。\n");
		set("unit", "盆");
		set("value", 2000);
        set("cant_sell","活计尴尬地笑了笑：“小的不会养花，白赔了这几两银子，客官见笑了。。”\n");
		set("material", "plant");
	}
	setup();
}

