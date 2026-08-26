int cmd_roll() {
    string str = "", tmp;

    switch(random(2)) {
    case 0 : tmp = "on"; break;
    case 1 : tmp = "off"; break;
    default : tmp = "*SWITCH ERROR*"; break;
    }

    str += tmp;

    switch(random(3)) {
    case 0 : str += "A"; break;
    case 1 : str += "B"; break;
    case 2 : str += "C"; break;
    default : str += "*TRIANGLE ERROR*"; break;
    }

    str += (string)(random(12) + 1);

    write(str + "\n");

    return 1;
}
