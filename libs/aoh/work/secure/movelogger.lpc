// an object to log the cost of moving

// elem 0 : number of moves
// elem 1 : accumulated eval_cost   - unit is ticks of the LPC machine
// elem 2 : accumulated user time   - unit seems to be milliseconds
// elem 3 : accumulated system time - might indicate swap effort. same unit

//#define DEBUG

int *interactives;
int *livings;
int *others;

void create() {
	if (object_name(this_object()) != "/secure/movelogger") {
		destruct(this_object());
		return;
	}
	seteuid(getuid());
	interactives = ({ 0, 0, 0, 0});
	livings = ({ 0, 0, 0, 0});
	others = ({ 0, 0, 0, 0});
	call_out("save", 15*60);
	write_file("/log/MOVECOST", "* loaded at "+ctime(time())+"\n");
}

void save() {
	if (find_call_out("save") < 0) call_out("save", 15*60);
	write_file("/log/MOVECOST",
		   "interactives "+interactives[0]+" "+interactives[1]
		   +" "+interactives[2]+" "+interactives[3]+"\n");
	write_file("/log/MOVECOST",
		   "livings "+livings[0]+" "+livings[1]
		   +" "+livings[2]+" "+livings[3]+"\n");
	write_file("/log/MOVECOST",
		   "others "+others[0]+" "+others[1]
		   +" "+others[2]+" "+others[3]+"\n");
	interactives = ({ 0, 0, 0, 0});
	livings = ({ 0, 0, 0, 0});
	others = ({ 0, 0, 0, 0});
}

void log(int cost, int utime, int stime) {
	if (!intp(cost) || cost < 0 || !intp(utime) || utime < 0
	    || !intp(stime) || stime < 0) {
		string s;
	s = 	sprintf("* %s %d %d %d\n", object_name(previous_object()),
			cost, utime, stime);
		write_file("/log/MOVECOST", s);
		return;
	}
	if (interactive(previous_object())) {
		interactives[0]++;
		interactives[1] += cost;
		interactives[2] += utime;
		interactives[3] += stime;
		return;
	}
	if (living(previous_object())) {
		livings[0]++;
		livings[1] += cost;
		livings[2] += utime;
		livings[3] += stime;
		return;
	}
	others[0]++;
	others[1] += cost;
	others[2] += utime;
	others[3] += stime;
}

int remove() { save(); destruct(this_object()); return 1; }

void prof() {
  string *lines;
  string what;
  int n, cost, utime, stime;
  int i;
  int *is;
  int *ls;
  int *os;
  int *sis;
  int *sls;
  int *sos;

  is = ({ 0,0,0,0}); ls = ({ 0,0,0,0}); os = ({ 0,0,0,0});
  sis = ({ 0,0,0,0}); sls = ({ 0,0,0,0}); sos = ({ 0,0,0,0});
  lines = explode(read_file("/log/MOVECOST"), "\n");
  for (i = 0; i < sizeof(lines); i++) {
    sscanf(lines[i], "%s %d %d %d %d", what, n, cost, utime, stime);
    switch (what) {
      case "--":
        sis[0] += is[0]; sis[1] += is[1]; sis[2] += is[2]; sis[3] += is[3];
        sls[0] += ls[0]; sls[1] += ls[1]; sls[2] += ls[2]; sls[3] += ls[3];
        sos[0] += os[0]; sos[1] += os[1]; sos[2] += os[2]; sos[3] += os[3];
	break;
      case "interactives":
	is[0] = n; is[1] = cost; is[2] = utime; is[3] = stime;
	break;
      case "livings":
	ls[0] = n; ls[1] = cost; ls[2] = utime; ls[3] = stime;
	break;
      case "others":
	os[0] = n; os[1] = cost; os[2] = utime; os[3] = stime;
	break;
    }
  }
  lines = what = 0; 
  write("profile for move_object() at "+ctime(time())
	+", GD now version " __VERSION__ "\n");
#ifdef DEBUG
  printf("sis %@10d\n", sis);
#endif
  printf("%12s: eval_cost %9.4f user %9.4f system %9.4f, %8d samples\n",
	 "interactives", to_float(sis[1])/sis[0], to_float(sis[2])/sis[0],
	 to_float(sis[3])/sis[0], sis[0]);
#ifdef DEBUG
  printf("sls %@10d\n", sls);
#endif
  printf("%12s: eval_cost %9.4f user %9.4f system %9.4f, %8d samples\n",
	 "livings", to_float(sls[1])/sls[0], to_float(sls[2])/sls[0],
	 to_float(sls[3])/sls[0], sls[0]);
#ifdef DEBUG
  printf("sos %@10d\n", sos);
#endif
  printf("%12s: eval_cost %9.4f user %9.4f system %9.4f, %8d samples\n",
	 "others", to_float(sos[1])/sos[0], to_float(sos[2])/sos[0],
	 to_float(sos[3])/sos[0], sos[0]);
  n = sis[0] + sls[0] + sos[0];
  cost = sis[1] + sls[1] + sos[1];
  utime = sis[2] + sls[2] + sos[2];
  stime = sis[3] + sls[3] + sos[3];
#ifdef DEBUG
  printf("sis %@10d\n", ({ n, cost, utime, stime}) );
#endif
  printf("%12s: eval_cost %9.4f user %9.4f system %9.4f, %8d samples\n",
	 "total", to_float(cost)/n, to_float(utime)/n, to_float(stime)/n, n);
}
