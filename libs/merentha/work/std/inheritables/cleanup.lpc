// Petrarch
// Merentha Lib 1.0
// cleanup.c

int no_clean;

void create() {}
void init() {}
void reset() {}

void set_no_clean(int i) { no_clean=i; }

int clean_up(int i) {
    if(i || no_clean) return 0;
    return 1;
}

void remove() {
    object env;
    if(this_object()) {
        env=environment();
        if(env) all_inventory(this_object())->move(env);
        destruct(this_object());
    }
}

