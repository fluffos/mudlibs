/*    /lib/fish.c
 *    from the Dead Souls Object Library
 *    fish objects which get caught
 *    created by Descartes of Borg 951009
 */


#include <lib.h>
#include "include/fish.h"

inherit LIB_MEAL;

nosave private int Fight;
nosave private string Food;

protected void create(){
    meal::create();
    Food = 0;
    Fight = 0;
}

int eventCatch(object who){ return 1; }

int SetFight(int x){ return (Fight = x); }

int GetFight(){ return Fight; }

string SetFood(string str){ return (Food = str); }

string GetFood(){ return Food; }
