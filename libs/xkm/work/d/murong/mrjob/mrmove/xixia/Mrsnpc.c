/************************
File:   Mrsnpc.c
Create: Play
Time:   4/25/2002
************************/
inherit "/d/murong/mrjob/mrnpc/mr_inherit/snoop_npc.c";

void create()
{
        seteuid(getuid());
	set_name("隐士",({ "yin shi", "man" }) );
        set("gender", "男性" );
        set("title", "灵州逍遥居士" );
        set("age", 50);
        set("long", "一位洒脱的隐士，鹤发童颜，观赏着街景。\n");
        set("per", 28);
        set("str", 34);
        set("dex", 25);
        set("con", 26);
        set("int", 25);
        set("env/wimpy", 40);
        //设此为必免探访人物出生地出错误
        set("move_room", "/d/lingzhou/beidajie");
        //这里必须写上此npc所在的区域代码,详查help map 城市部分
        set("area", "灵州");
        set("attitude", "friendly");

        setup();
        carry_object("/clone/armor/cloth")->wear();
}
