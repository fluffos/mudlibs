string format_table( string *col1, string *col2 ) {
    return sprintf(
        "%-=10s %-=30s",
        implode(col1, "\n"),
        implode(col2, "\n")
    );
}

int cmd_test() {
    string *col1, *col2;

    col1    = ({ "one",     "two",      "three"     });
    col2    = ({ "line1 ",  "line2 ",   "line3"     });

    write( "hello \e[1;32mworld\e[0m [" + 10 + "]\n" );
    write( format_table(col1, col2) + "\n" );

    // limit_tune_on();

    call_out("foo", 3);

    return 1;
}

void foo() {
    write( "hello \e[1;32mworld\e[0m [" + 20 + "]\n" );
    // limit_tune_off();
}

int main(object me) {
    cmd_test();
    return 1;
}
