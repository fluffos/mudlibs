// ouxuepu.c 呕血谱
inherit ITEM;
void create()
{
        set_name("《呕血谱》", ({ "ouxue pu", "book", "pu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本小册子，封面上写着「呕血谱」三个字，是一本围棋的棋谱。传说国手刘仲甫在
骊山之麓给一个乡下老媪杀得大败，登时呕血数升，这局棋谱便称为《呕血谱》。\n");
                set("value", 10000);
                set("material", "paper");
               }
}
