// chou.c 
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("仇松年", ({ "chou songnian", "chou",}));
        set("nickname", "长发头陀");        
        set("long", "这头陀长发垂肩，头上戴着一个闪闪发光的铜箍，束着长发。\n");
        set("title",HIY"日月神教  "RED"朱雀堂旗主"NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 32);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 2700);
        set("max_jing", 1800);
	set("eff_jingli", 1800);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", 5000);

	set_skill("blade", 180);
        set_skill("dodge",180);
        set_skill("finger", 180);

        set_skill("xuedao-daofa",180);
        set_skill("yizhi-chan", 180);
        set_skill("literate", 120);
	set_skill("ding-dodge", 180);
	set_skill("force", 180);
	set_skill("tianmogong", 180);

        map_skill("blade", "xuedao-daofa");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
	map_skill("parry", "yizhi-chan");
	map_skill("finger", "yizhi-chan");
	prepare_skill("finger", "yizhi-chan");
	
        setup();
 
	carry_object(BINGQI_D("jiedao"))->wield();
	carry_object(MISC_D("cloth"))->wear();        
}
