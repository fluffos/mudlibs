// ÖÜÔ±Íâå /d/city/chuzhou/npc/zhou_yuanwai.c
// by lala, 1997-12-14

inherit NPC;

void create()
{
    set_name( "ÖÜÔ±Íâ", ({ "zhou yuanwai", "zhou", "yuanwai" }) );
    set( "gender", "ÄÐÐÔ" );
    set( "age", 58 );
    set( "title", "±¾µØÏçÉð" );
    set( "long", @LONG
ÖÜÔ±ÍâÊÇ±¾µØÓÐÃûµÄÏçÉð£¬Ëû¼Ò×æÉÏËÆºõ×ö¹ý²»Ð¡µÄ¹Ù£¬µ«ÊÇÖÜÔ±Íâ±¾ÈË²¢Ã»ÓÐ
×öÌ«¾ÃµÄ¹Ù£¬Ò²Ã»ÓÐ×öµ½¶à¸ßµÄ¹Ù£¬Ö»×ö¹ýÒ»Á½ÈÎÖªÖÝ¡¢Í¨ÅÐÒ»ÀàµÄ¹ÙÖ°¡£µ«ÊÇ
ÓÉÓÚËûÒ»Ïò±È½Ï·½Õý£¬ËùÒÔÔÚ±¾µØÆÄÓÐºÃÃû¡£
LONG
    );

    set("combat_exp", 10000);
    set("social_exp", 20000);
    set("positive_score", 5000);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    carry_object( __DIR__"obj/riben_zheshan")->wield();
}          

