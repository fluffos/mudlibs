//Cracked by Kafei
// Kane,
// Qianj 11/2001

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("黄药师", ({ "huang yaoshi", "huang" }));
        set("title", "桃花岛主");
        set("nickname", "东邪");
        set("long",
"他就是名震天下的桃花岛主「东邪」黄药师，但见他形相清癯，\n"
"丰资秀爽，湛然若神。一袭青袍，领后插着一支玉箫，神色之间\n"
"大有一股落拓山林的逸气。\n");
        set("gender", "男性");
        set("age", 55);
        set("attitude", "friendly");
        set("shen_type", 0);

        set_skill("qimen-dunjia", 400);
        set_skill("bitao-xuangong", 400);
        set_skill("music", 400);

        setup();
}
