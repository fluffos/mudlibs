//To prevent abuse

mapping uses;

void reset(int arg) {
        if(arg) return;
        uses = ([]);
}

int query_use(string str) {
        return uses[str];
}

int add_use(string str) {
        if(!uses[str]) {
                uses += ([ str: 1]);
                return 1;
        } else {
                uses[str]++;
        }
        return 1;
}
