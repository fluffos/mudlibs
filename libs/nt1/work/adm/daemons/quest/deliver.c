// Íæ¼ÒÈÎÎñÊØ»¤½ø³Ì£ºdeliver.c

#include <ansi.h>

string *ob_list = ({
        "/clone/questob/rice",
        "/clone/questob/cloth",
        "/clone/questob/spice",
        "/clone/questob/bait",
        "/clone/questob/wood",
        "/clone/questob/metal",
        "/clone/questob/farm",
        "/clone/questob/silver",
        "/clone/questob/gold",
});

void startup();

// ÈÎÎñ¶ÔÏó´´½¨
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
        object qob;     // ÈÎÎñÎï¼ş
        string name;    // ÒªËÍµÄ»õÎï
        int amount;     // ËÍ»õµÄÊıÁ¿

        if (sizeof(children("/clone/quest/deliver")) > 30)
                // ÏµÍ³ÖĞ×î¶68¸öËÍ»õµÄÈÎÎñ
                return;

        name = ob_list[random(sizeof(ob_list))];
        amount = 5 + random(6);

        qob = new("/clone/quest/deliver");
        qob->init_quest(name, amount);

        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "½ø³Ì(DELIVER)ÀûÓÃ" + 
                              get_object(name)->name() +
                              HIR "´´½¨ÁËÒ»¸öÈÎÎñ¡£");
}

private void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // Èç¹û¿ÉÒÔ£¬Ã¿´ÎĞÄÌø²úÉúÒ»¸öQUEST
        start_quest();
}

// ÈÎÎñÊØ»¤½ø³Ì»½ĞÑÕâ¸ö½ø³Ì
void startup()
{
        // Æô¶¯
        if (! find_object(QUEST_D))
                return;

        if (! query_heart_beat())
                CHANNEL_D->do_channel(find_object(QUEST_D),
                                      "sys", "½ø³Ì(DELIVER)Æô¶¯ÁË¡£");

        // Æ½¾ùÃ¿ËÄ·ÖÖÓ²úÉúÒ»¸öÈÎÎñ
        set_heart_beat(110 + random(20));
}

// Í£Ö¹Õâ¸öÈÎÎñ½ø³Ì
void stop()
{
        set_heart_beat(0);
}

