//随机动物

inherit NPC;

mixed* info_list = ({
	({"野兔","ye tu","这是一只普通的野兔。灰色的皮毛，长长的耳朵。一边吃草，一边警觉的观察着周围的一切。\n",({"野兔跳了起来。\n","野兔低头啃着青草。\n"}),({ "头部", "身体", "前腿", "后腿" }),({ "hoof", "bite", "claw" })}),
	({"梅花鹿","meihua lu","这是一只罕见的梅花鹿。身上的斑点恰如梅花般美丽，生长在它优雅的身躯上。\n",({"梅花鹿扭过头，眼神迷离，仿佛在眺望着什么。\n","梅花鹿突然高高跃起，奔跑起来。\n"}),({ "鹿角", "身体", "前腿", "后腿" }),({ "hoof", "poke", "claw" })}),
	({"蝴蝶","hu die","这是一只粉色的蝴蝶，大大的翅膀上有两个眼睛一样的斑点。\n",({"蝴蝶在空中飞来飞去。\n","蝴蝶落在了一朵花的花瓣上。\n"}),({ "头部" }),({ "bite" })}),
});
void create()
{
	mixed* info = info_list[random(sizeof(info_list))];
	set_name(info[0], ({ info[1] }));
	set("race", "野兽");
	set("long",
		info[2]);
	set("chat_chance",10);
	set("chat_msg",info[3]);
    set("limbs",info[4]);
    set("verbs",info[5]);
	setup();
}