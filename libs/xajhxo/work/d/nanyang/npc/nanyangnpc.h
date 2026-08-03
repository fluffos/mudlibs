//nanyangnpc.h

void create()
{
        set("talk_msg",({
            "这里是南阳城",
            "这里是诸葛亮的故乡",
            "柯府老爷为民除害，大家都感恩待德呀！",
            "南阳城北接中原，南渡汉水，客官想去哪里呀？",
        }));
}
>cat caiyao.c
//caiyao.c
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
void create()
{
    set_name("采药人", ({ "cai yao ren","ren" }) );
    set("gender", "男性" );
    set("age", 35);
    set("max_kee",800);
    set("max_sen",700);
    set_xiuwei_by_type("unarmed",250);
    set_xiuwei_by_type("dodge",250);
    set("attitude","friendly");
    set("combat_exp", 1500);
    set("vendor_goods",([
        "甘草"  : __DIR__"obj/gancao",
        "败耳草" : __DIR__"obj/baier",
        "党参" : __DIR__"obj/dangshen",
        "乌梅" : __DIR__"obj/wumei",
    ]));
    setup();
    carry_object(__DIR__"obj/cloth1")->wear();
    carry_object(__DIR__"obj/dangshen");
    carry_object(__DIR__"obj/gancao");
    carry_object(__DIR__"obj/baier");
}
void init()
{
    ::init();
    add_action("do_vendor_list","list");
}