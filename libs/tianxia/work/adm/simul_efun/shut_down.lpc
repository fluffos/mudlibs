// shutdown.c
// by Find.

nomask void shutdown(int count)
{
        object obj = find_object("/cmds/arch/shutdown");

        if( obj && (previous_object() == obj) )
	{
		object db = find_object(DATABASE_D);

		if(objectp(db))
			destruct(db);
                efun::shutdown(count);
	}

        else return;
}
