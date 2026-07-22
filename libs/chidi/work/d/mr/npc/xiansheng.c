// teacher.c ÀΩ€”œ»…˙
// CLEANSWORD 1999/9/7
inherit BHNPC;
#include <ansi.h>
string * degree_desc = ({
       BLU "Œƒ√§" NOR,
       BLU "ÕØ…˙" NOR,
       BLU "–„≤≈" NOR,
       CYN "æŸ»À" NOR,
       CYN "Ω‚‘™" NOR,
       CYN "π± ø" NOR,
       CYN "ª·‘™" NOR,
       GRN "Ω¯ ø" NOR,
       GRN "ÃΩª®" NOR,
       GRN "∞Ò—€" NOR,
       GRN "◊¥‘™" NOR,
       HIY "∫≤¡÷‘∫ ø" NOR,
       HIY "∫≤¡÷À∂ ø" NOR,
       HIY "∫≤¡÷≤© ø" NOR,
       HIY "∫≤¡÷‘∫±‡–ﬁ" NOR,
       HIR " ¸º™ ø" NOR,
       HIR "—ß ø" NOR,
       HIR "ƒ⁄∏Û¥Û—ß ø" NOR,
       HIR "ƒ⁄∏Û ◊∏®" NOR,
       MAG "Œƒ—ß¥Û◊⁄ ¶" NOR,
       HIW " •»À" NOR,
});
int ask_degree();
void create()
{
        set_name("ÀΩ€”œ»…˙", ({ "xiansheng", "teacher" }));
        set("long", "’‚æÕ «ƒΩ»›º“÷ÿΩ¿Ò∆∏¿¥µƒÀΩ€”œ»…˙£¨À˚ «µ±¥˙¥Û»Â÷ÏÏ‰µƒ—ß…˙£¨¨
°°°°°°À˚æ≠π˝¿œ ¶÷ÏÏ‰µƒ–Ìø…£¨ø…“‘Œ™µ±¥˙µƒŒƒ»Àƒ´øÕ ⁄”Ë—ßŒª\n");
        set("gender", "ƒ––‘");
        set("age", 65); 
        set_weight(30000000);
        set_skill("literate", 300);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "—ßŒª" : (:ask_degree:),
            " È"   : "∞¶! ÈµΩ”√ ±∑Ω∫ﬁ…Ÿ°£",
            "ΩË È" : "ΩË£øƒ„≤ªªπŒ“µΩƒƒ¿Ô’“ƒ„£ø∫ﬂ!",
        ]));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "ÀΩ€”œ»…˙Àµµ¿£∫∆’ÃÏ÷Æœ¬£¨ƒ™∑«ÕıÕ¡£ª¬ Õ¡÷Æ±ı£¨ƒ™∑«Õı≥º°£\n",
                "ÀΩ€”œ»…˙Àµµ¿£∫≥ˆº“»À£¨–°π˝À“Ê—…£ªŒﬁÕ˝¥Ûπ˝£¨Œ¥º√œÃ¿ß÷Æ°£\n",
                "ÀΩ€”œ»…˙Àµµ¿£∫¥Û—ß÷Æµ¿£¨‘⁄√˜√˜µ¬°£‘⁄«◊√Ò£¨‘⁄÷π”⁄÷¡…∆°£ \n",
                "ÀΩ€”œ»…˙Àµµ¿£∫∏ÒŒÔ÷¬÷™£¨≥œ“‚’˝–ƒ£¨–ﬁ…Ì∆Îº“£¨÷Œπ˙∆ΩÃÏœ¬°£\n",
        }) );
     this_player()->carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/÷Ï"))
                return 0; 
        ob->add_temp("mark/÷Ï", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/÷Ï"))
                who->set_temp("mark/÷Ï", 0);
        if (ob->query("money_id") && ob->value() >= 5000) {
                message_vision("ÀΩ€”œ»…˙Õ¨“‚÷∏µ„$N“ª–©Œ Ã‚°£\n", who);
                who->add_temp("mark/÷Ï", ob->value() / 250);
                return 1;
        }
        return 0;
}
int ask_degree()
{
        int lv;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 5);
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 3) 
        {
               command("say "+ob->query("name")+"£¨ƒ„ƒ«µ„ƒ´ÀÆ“≤∫√“‚ÀºŒ ? ÀÊ±„∏¯ƒ„∏ˆ—ßŒªæÕÀ„¡À! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        if (lv < 10) 
        {
               command("say "+ob->query("name")+"£¨ﬂ¿£¨≤ª¥Ì£¨”–«∞Õæ£¨∫‹∏ﬂ–À ⁄”Ë—ßŒª∏¯ƒ„£¨ºÃ–¯∫√∫√≈¨¡¶! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        else
        {
               command("say π˚»ª «≥§Ω≠∫Û¿À÷«∞¿À∞°£¨"+ob->query("name")+"£¨Œ“∑«≥£»Ÿ–“ƒ‹”–ª˙ª·Œ™ƒ„ ⁄—ßŒª! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
}

