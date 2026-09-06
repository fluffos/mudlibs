
/******************************************
 NAME: duel_list.c

 PURPOSE: show gladiator rankings.

 AUTHOR:  Tron
 ******************************************/
#include <areas.h>

#define	SAVE	AREA_TRISTEZA "duel/duel_list"

#define RANK	0
#define KILLS	1
#define VICTORY 2
#define DUELS	3

#define LIST_SIZE	15
#define LIST_MAX	50

string  *names;
mixed   *datas;

void
dueld_list_create() {
    int n, s;

    names = ({});
    datas = ({});

    restore_object(SAVE);

    if((n = sizeof(names)) > LIST_MAX) {
	s = LIST_MAX-1;
	n--;
	for(; s < n; s++) {
	    names[s] = 0;
	    datas[s] = 0;
	}
	names -= ({0});
	datas -= ({0});
	save_object(SAVE);
    } 

}

void
dueld_save() { 
    save_object(SAVE);
}

private int
_getSortBy(int by, status order) {

    if(!order) {
	switch(by) {
	case RANK: return -1;
	case KILLS: return VICTORY;
	case VICTORY: return DUELS;
	case DUELS: return RANK;
	default: return -1;
	}
    }
    else {
	switch(by) {
	case RANK: return DUELS;
	case DUELS: return VICTORY;
	case VICTORY: return KILLS;
	case KILLS: return -1;
	default: return -1;
	}
    }
}

void
dueld_sort(string name, mixed data, int sort_by) {
    mapping tmp;
    mixed  dt;
    int i;

    if(!name || !data || sort_by > DUELS || sort_by < RANK) return;

    i = member(names, name);
    if(i == -1) return; //No name in the list !?!

    if(!i) return; //We are the best already.
    while(i--) {
	if(data[sort_by] > datas[i][sort_by]) {
	    datas[i+1] = datas[i];
	    datas[i] = data;
	    names[i+1] = names[i];
	    names[i] = name;
	    sort_by = KILLS; // let's presume the list is not yet
	    // in full order by sort factors.
	    // So, check all factors every time.
	}
	else if(data[sort_by] == datas[i][sort_by]) {
	    sort_by = _getSortBy(sort_by, 0);
	    if(sort_by == -1) break;
	    i++;
	}
	else break;
    }
    return;    
}


void
dueld_sort_all(int sort_by) {
    int i;

    i = sizeof(names);

    if(i)
	while(i--) {
	    dueld_sort(names[i], datas[i], sort_by);
	}
}

void
dueld_show_list(int from) {
    int i, siz;

    if(from < 0) from = 0;

    if(!names || !(siz = sizeof(names))) {
	write("There are no Gladiators on the list yet, sorry.\n");
	return;
    }
    write("The Official Top "+siz+" Gladiator list\n");
    write("K = Kills, V = Victories, D = Duels, Sc = Score, V% = Victory %\n");
    write("Avg_lvl = Average level of killed gladiators.\n");
    write("Read list <number>, read list from certain number.\n\n");
    printf("%-3s) %-12s %-5s %-5s %-5s %-5s %-5s %-5s\n", "#", "Name", "K", 
      "V", "D", "Sc", "V%", "Avg_lvl");
    write("-----------------------------------------------------------\n");

    siz--;

    if(from >= siz) {
	from = siz;
	siz = 1;
    }
    else if((siz - from) > LIST_SIZE)
	siz = LIST_SIZE-1;
    else siz -= from;

    for(i = from, siz += (from+1); i<siz; i++) {

	printf("%-3d) %-12s %-5d %-5d %-5d %-5d %-5d %-5d\n", 
	  i+1,
	  capitalize(names[i]), 
	  datas[i][KILLS],
	  datas[i][VICTORY], 
	  datas[i][DUELS],
	  datas[i][RANK], 
	  (datas[i][DUELS]?datas[i][VICTORY]*100/datas[i][DUELS] : 0 ),
	  (datas[i][KILLS]?datas[i][RANK]/datas[i][KILLS] : 0));
    }
}                      

void
add_dueld_kill(string name, int lvl) {
    int i;

    if(!name) return;

    i = member(names, name);
    if(i == -1) return;

    datas[i][RANK] += lvl;
    datas[i][KILLS] += 1;

    dueld_sort(name, datas[i], KILLS);

    return;
}

void
add_dueld_victory(string name) {
    int i;

    if(!name) return;

    if((i = member(names, name)) == -1) return;

    datas[i][VICTORY]++;
    dueld_sort(name, datas[i], KILLS);
    dueld_save();
}

void
add_dueld_duels(string name) {
    int i;

    if(!name) return;

    i = member(names, name);

    if(i == -1) {
	names += ({name});
	datas += ({({0, 0, 0, 1})});
	i = member(names, name);
    }
    else datas[i][DUELS]++;
    dueld_sort(name, datas[i], KILLS);

}
