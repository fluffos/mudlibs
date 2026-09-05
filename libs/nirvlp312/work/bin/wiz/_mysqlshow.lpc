cmd_mysqlshow(string str)
{
    mixed *all;
    string tmp, *rs;
    int x, a, my_size;

if(this_player()->query_level() < 1000) return 0;
    if(!str)
    {
        write("+----------------------+\n"+
          "|     Valid Tables     |\n"+
          "+----------------------+\n");
        all = db_get_rs("show tables");
        for(x = 0; x < sizeof(all); x++)
        {
            rs = all[x];
            printf("| %-20s |\n",rs[0]);
        }
        write("+----------------------+\n"+
          sizeof(all) + " rows in set (0.00 sec)\n");
        return 1;
    }

    all = db_get_rs("describe " + str);

    if(!sizeof(all))
    {
        write("No such table.\n");
        return 1;
    }

write("+---------------+----------------------+------+-----+---------+----------------+\n"+
      "| Field         | Type                 | Null | Key | Default | Extra          |\n"+
      "+---------------+----------------------+------+-----+---------+----------------+\n");

    for(x = 0; x < sizeof(all); x++)
    {
        rs = all[x];
        for(a = 0; a < sizeof(rs); a++)
        {
            tmp = "";
            if(a == 0) my_size = 14;
            if(a == 1) my_size = 21;
            if(a == 2) my_size = 5;
            if(a == 3) my_size = 4;
            if(a == 4) my_size = 8;
            if(a == 5) my_size = 14;
            if(rs[a]) tmp = rs[a];
            if(tmp == "" && a ==4) tmp = "NULL";
            printf("| %-" + my_size + "s",tmp);
        }
        write(" |\n");
    }
    write("+---------------+----------------------+------+-----+---------+----------------+\n"+
      sizeof(all) + " rows in set (0.00 sec)\n");
    return 1;

}
