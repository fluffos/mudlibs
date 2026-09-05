destroy(num)
{
    int n;
    object ob;

    if (sscanf(num, "%d", n) != 1)
        return 0;
    ob = first_inventory(this_player());
    while(n>0 && ob) {
        n -= 1;
        ob = next_inventory(ob);
    }
    if (ob == this_player()) {
        write("That is your self !\n");
        return 1;
    }
    write("Destroying: " + call_other(ob, "short") + ".\n");
    destruct(ob);
    return 1;
}