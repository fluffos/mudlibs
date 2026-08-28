/*  /adm/simul_efun/capitalization.c
 *  Made for DarkeMUD
 *  Created by Geldron 030296
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

int capp(string str) {
    if(strlen(str) != 1) error("Bad argument 1 in capp().\n");
    if(member_array(str, ({ "A", "B", "C", "D", "E", "F", "G", "H",
	"I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
	"V", "W", "X", "Y", "Z" })) != -1) return 1;
    return 0;
}

int allcapp(string str) {
    string *tmp;
    int i, count;

    tmp = explode(str, " ");
    if(sizeof(tmp) > 1) error("Bad argument 1 in allcapp().\n");
    tmp = explode(str, "");
    for(i = 0; i < sizeof(tmp); i++)
	if(capp(tmp[i])) count++;
    if(count == strlen(str)) return 1;
    return 0;
}
