//jiguan.c 机关人
inherit NPC;
void create()
{
        set_name("机关人", ({"jiguan ren", "ren"}));
        set("gender", "男性");
        set("age", 100);
        set("long","这些机关人都是黄药师亲手设计的，专门为方便弟子练功用。\n");
        set("attitude", "peaceful");
        set("str", 10);
        set("int", 10);
        set("con", 10);
        set("dex", 10);
        set("qi", 100000);
    set("no_suck",1);           // 不能吸jing,neili
        set("max_qi", 100000);
        set("jing", 100000);
        set("max_jing", 100000);
        set("combat_exp", 2000);
        setup();
}
