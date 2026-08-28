/*  /cmds/system/_dos2lpc.c

 *  Made for DarkeMUD

 *  Created by Geldron 053196

 *  Copyright (c) 1996

 *  Do not remove this header

 */





inherit DAEMON;



int cmd_dos2lpc(string arg) {

    if(!find_object("/cmds/system/_replace")) new("/cmds/system/_replace");

    find_object("/cmds/system/_replace")->cmd_replace("-d #^M# # " + arg);

    return 1;

}

