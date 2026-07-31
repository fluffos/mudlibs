// ¿àÁ¦å /d/city/chuzhou/npc/kuli.c
// by lala, 1997-12-14

inherit NPC;

void create()
{
    set_name( "¿àÁ¦", ({ "ku li", "coolie", }) );
    set( "gender", "ÄÐÐÔ" );
    set( "age", random(18) + 18 );
    set( "long", @LONG
ÕâÊÇ¸öÂúÍ·´óº¹µØÔÚÂëÍ·ÉÏ°áÔË¶«Î÷µÄ¿àÁ¦¡£
LONG
    );
    set( "chat_chance", 5 );
    set( "chat_msg",({
        "¿àÁ¦¿¸×ÅÂé´üÒ»²½Ò»²½µÄÑØ×ÅÌø°åÐ¡ÐÄµÄ×ßÉÏ´¬¡£\n",
        "¿àÁ¦´­ÁË¿ÚÆø£¬ÓÖ°áÆðÒ»¸ö´óÄ¾Ïä¡£\n",
        "¿àÁ¦¸ÕÏëÍµÍµÐÝÏ¢Ò»ÏÂ£¬¾Í±»Ê¿±ø·¢ÏÖÁË£¬Ê¿±ø¿ªÊ¼Ð×ºÝµÄÖäÂîÆðÀ´¡£\n",
    }));
    set("combat_exp", 1000);
    set("social_exp", 2000);
    set("positive_score", 50);
    set("negative_score", 10);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "coin", 1 + random(5) );
}          

