#define EXTRA_INIT 
#define TP 		this_player()
#define TPS		TP->query_spell_points()
#define ADDSP(X)	TP->restore_spell_points(X)
#define COST_TO_MOVE	10

init() {
int i;

  ::init();
  EXTRA_INIT
  for(i=0;i<sizeof(dest_dir);i++) add_action(dest_dir[i][1],dest_dir[i][1]);
}

forward() {
  if(TPS>=COST_TO_MOVE) {
    ADDSP(-COST_TO_MOVE);
    ::move();
  } else {
    write("You are too low on energy to drift "+query_verb()+".\n");
  }
  return 1;
}

backward() {
  if(TPS>=COST_TO_MOVE) {
    ADDSP(-COST_TO_MOVE);
    ::move();
  } else {
    write("You are too low on energy to drift "+query_verb()+".\n");
  }
  return 1;
}

left() {
  if(TPS>=COST_TO_MOVE) {
    ADDSP(-COST_TO_MOVE);
    ::move();
  } else {
    write("You are too low on energy to drift "+query_verb()+".\n");
  }
  return 1;
}

right() {
  if(TPS>=COST_TO_MOVE) {
    ADDSP(-COST_TO_MOVE);
    ::move();
  } else {
    write("You are too low on energy to drift "+query_verb()+".\n");
  }
  return 1;
}

up() {
  if(TPS>=COST_TO_MOVE) {
    ADDSP(-COST_TO_MOVE);
    ::move();
  } else {
    write("You are too low on energy to drift "+query_verb()+".\n");
  }
  return 1;
}

down() {
  if(TPS>=COST_TO_MOVE) {
    ADDSP(-COST_TO_MOVE);
    ::move();
  } else {
    write("You are too low on energy to drift "+query_verb()+".\n");
  }
  return 1;
}

