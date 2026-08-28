/**
**      Example item by Dazzt
*/

inherit ITEM;

init()
{
    add_action("do_dig", "dig");
}

create_item()
{
    set_name("shovel");
    set_short("A sturdy shovel");
    set_long("This sturdy shovel is made from oak. It has been polished\n" +
      "and it looks quite new, like it hasn't been ever used.\n");

    set_smell("The smell of sturdy shovel reminds you of that grocery store\n" +
      "you used to visit when you were a child.\n");
    set_taste("The polish used in shovel sticks into your teeth. yuck!\n");

    set_dimensions(3, 3, 130);      /* 130 cm long, 3cm thick */
    set_weight(1500);               /* 1.5kg */
    set_hp(10);
    set_max_hp(10);
    set_material("oak");
}

do_dig()
{
    message("standard", "You start digging the ground.\n", THIS);
    message("standard", capitalize(THIS->query_name()) + " starts digging the ground.\n",
      environment(THIS), THIS);
    return 1;
}
