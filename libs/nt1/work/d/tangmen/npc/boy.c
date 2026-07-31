//boy.c

inherit NPC;

void create()
{
        int i,amun;
        string *order = ({"ÕÅ", "Íõ", "Àî", "ÕÔ", "Ëï", "Ğì", "Ö£", "ÖÜ", "Îâ",
                "½¯", "Éò", "Ñî", "Ãç", "Òü", "½ğ", "Îº", "ÌÕ", "Óá", "Áø", "Öì"});
        string *orderr = ({"°ü°ü", "±¦±¦", "¹Ô¹Ô", "Ğ¡Ğ¡", "ÀÚÀÚ",
                "¼¦¼¦", "Ñ»Ñ»", "¹·¹·", "Ã¨Ã¨"});
        set_name( order[random(20)] + orderr[random(8)], ({ "boy", "kid" }) );
        set("title", "ÎŞÖªÄĞº¢");
        set("gender", "ÄĞĞÔ" );
        set("age", random(5)+4);
        set("long",
                "ËûºÜĞ¡, ºÜºÃÆÛ·ş.\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("attitude", "peaceful");
        set("combat_exp", random(1000));
        set("max_qi", 100);
        set("qi", 100);
        set("max_jingli", 100);
        set("jingli", 100);
        set_skill("cuff", 1+random(10));
        setup();
        carry_object("clone/misc/cloth")->wear();
}

