// xiang.c 向问天

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("向问天", ({ "xiang wentian", "xiang", "wentian"}));
        set("long", "只见他容貌清瘦，身形高大，颏下疏疏朗朗一丛花白长须，垂在胸前，\n"+
		"背上负着一个包袱，再看他腰间时，却无弯刀。\n");
        set("title",HIY"日月神教 "HIW"光明左使"NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 4000);
        set("max_jing", 2200);
        set("eff_jingli", 2500);
        set("jiali", 100);
        set("combat_exp", 2000000);

        set_skill("finger", 220);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("force", 220);
        set_skill("literate", 160);

        set_skill("yiyang-zhi",220);
        set_skill("ding-dodge",220);
        set_skill("huntian-qigong",220);

        map_skill("force", "huntian-qigong");
        map_skill("parry", "yiyang-zhi");
        map_skill("dodge", "ding-dodge");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger", "yiyang-zhi");
        
        set("chat_chance", 3);
        set("chat_msg", ({
		"向问天拿起酒壶，灌了一大口，道：“好酒！”\n",
        }));
        setup();

        carry_object(MISC_D("cloth"))->wear();        
}
