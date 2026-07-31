// test.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i;
        object ob;
        function g;

        if (! arg)
                return 0;

        ob = present(arg, environment(me));
        if (! ob)
                return 0;

        seteuid(getuid());
        ob->start_call_out(bind((: call_out, __FILE__, "test" :), ob), 10);
        destruct(ob);
        write("Ok.\n");

	return 1;
}

int help()
{
	write(@TEXT
÷∏¡Ó∏Ò Ω£∫t2

	return 1;
TEXT );
}
