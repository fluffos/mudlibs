#include <ansi.h>

void startup();

// ÈÎÎñ¶ÔÏó´´½¨
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
        object qob;
        string qob_name;
        string *ob_names;

        if (sizeof(children("/clone/quest/capture")) > 30)
                // ÏµÍ³ÖĞ×î¶7¸ö×·É±µÄÈÎÎñ
                return;

        qob = new("/clone/quest/capture");
        qob->init_quest();
        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "½ø³Ì(CAPTURE)"
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
                                      "sys", "½ø³Ì(CAPTURE)Æô¶¯ÁË¡£");

        // Æ½¾ùÃ¿ËÄ·ÖÖÓ²úÉúÒ»¸öÈÎÎñ
        set_heart_beat(50 + random(10));
}

// Í£Ö¹Õâ¸öÈÎÎñ½ø³Ì
void stop()
{
        set_heart_beat(0);
}
