// medicine2.h

inherit ITEM;

int init()
{
        add_action("do_eat", "drink");
}
void setup()
{
        ::setup();
}
